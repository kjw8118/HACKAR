#include "ES582.h"
#include <cstring>
#include <iostream>
#include <windows.h>


void ES582::FrameCallback(void* userData, struct OCI_CANMessage* msg)
{
	//(void)userData;
	OCI_QueueHandle txQ = *(OCI_QueueHandle*)userData;
	OCI_ErrorCode ec = 0;
	switch (msg->type)
	{
	case OCI_CAN_RX_MESSAGE:
		OCI_CANMessage txmsg[1];
		txmsg[0].type						= OCI_CAN_TX_MESSAGE;
		txmsg[0].reserved					= 0;
		txmsg[0].data.txMessage.frameID	= msg->data.rxMessage.frameID;
		txmsg[0].data.txMessage.flags		= msg->data.rxMessage.flags;
		txmsg[0].data.txMessage.res		= msg->data.rxMessage.res;
		txmsg[0].data.txMessage.dlc		= msg->data.rxMessage.dlc;
		for(int i=0; i<msg->data.rxMessage.dlc; i++)
		{
			txmsg[0].data.txMessage.data[i] = msg->data.rxMessage.data[i];
		}

		ec = OCI_WriteCANData(txQ, OCI_NO_TIME, txmsg, 1, NULL);
		if(OCI_FAILED(ec))
		{
			std::cout << "Reflection failed" << std::endl;
			printf( "Message type: OCI_CAN_RX_MESSAGE\n" );
            printf( "Message Frame ID: 0x%x\n", msg->data.rxMessage.frameID );
            printf( "Message Time Stamp: %lld\n", msg->data.rxMessage.timeStamp );
            printf( "Message Data Length: %u\n", msg->data.rxMessage.dlc );
            printf( "Message Tag: 0x%x\n", msg->data.rxMessage.tag );
			printf( "Message Reserved: %d\n", msg->reserved);
			//printf( "Message Reserved: %d\n", msg->data);
            printf( "Message Data: " );

            for (int i = 0; i < msg->data.rxMessage.dlc; ++i )
            {
                printf( "%c ", msg->data.rxMessage.data[i] );
            }

            printf( "\n" );
		}
		else
		{
			//std::cout << msg->data.rxMessage.timeStamp << " " << txmsg->data.rxMessage.timeStamp << std::endl;
		}
		/*std::cout << "Frame Callback >> OCI_CAN_RX_MESSAGE";
		std::cout << std::dec << " TimeStamp: " << msg->data.rxMessage.timeStamp;
		std::cout << std::hex << " FrameID: " << (unsigned)msg->data.rxMessage.frameID;
		std::cout << " DLC: " << msg->data.rxMessage.dlc;
		std::cout << " Data:";
		for(int i=0; i<msg->data.rxMessage.dlc; i++)
		{
			std::cout << " " << (unsigned)msg->data.rxMessage.data[i];
		}
		std::cout << std::endl;*/
		
		break;

	case OCI_CAN_BUS_EVENT:
		std::cout << "Frame Callback >> OCI_CAN_BUS_EVENT" << std::endl;
		break;

	case OCI_CAN_ERROR_FRAME:
		std::cout << "Frame Callback >> OCI_CAN_ERROR_FRAME" << std::endl;
		break;

	case OCI_CAN_INTERNAL_ERROR_EVENT:
		std::cout << "Frame Callback >> OCI_CAN_INTERNAL_ERROR_EVENT" << std::endl;
		break;

	case OCI_CAN_TIMER_EVENT:
		std::cout << "Frame Callback >> OCI_CAN_TIMER_EVENT" << std::endl;
		break;

	case OCI_CAN_QUEUE_EVENT:
		std::cout << "Frame Callback >> OCI_CAN_QUEUE_EVENT" << std::endl;
		break;

	case OCI_CAN_TX_MESSAGE:
		std::cout << "Frame Callback >> OCI_CAN_TX_MESSAGE" << std::endl;
		break;

	default:
		std::cout << "Frame Callback >> DEFAULT" << std::endl;
		break;
	}
}

void ES582::EventCallback(void* userData, struct OCI_CANMessage* msg)
{
	(void)userData;
	switch (msg->type)
	{
	case OCI_CAN_RX_MESSAGE:
		std::cout << "Event Callback >> OCI_CAN_RX_MESSAGE" << std::endl;
		break;

	case OCI_CAN_BUS_EVENT:
		std::cout << "Event Callback >> OCI_CAN_BUS_EVENT" << std::endl;
		break;

	case OCI_CAN_ERROR_FRAME:
		std::cout << "Event Callback >> OCI_CAN_ERROR_FRAME" << std::endl;
		break;

	case OCI_CAN_INTERNAL_ERROR_EVENT:
		std::cout << "Event Callback >> OCI_CAN_INTERNAL_ERROR_EVENT" << std::endl;
		break;

	case OCI_CAN_TIMER_EVENT:
		std::cout << "Event Callback >> OCI_CAN_TIMER_EVENT" << std::endl;
		break;

	case OCI_CAN_QUEUE_EVENT:
		std::cout << "Event Callback >> OCI_CAN_QUEUE_EVENT" << std::endl;
		break;

	case OCI_CAN_TX_MESSAGE:
		std::cout << "Event Callback >> OCI_CAN_TX_MESSAGE" << std::endl;
		break;

	default:
		std::cout << "Event Callback >> DEFAULT" << std::endl;
		break;
	}
}
int ES582::SelectCANController(uint32_t nFound)
{
	int idx = -1;
	while (idx < 0 || idx >= nFound)
	{
		std::cout << "CAN 컨트롤러 번호를 입력하세요: ";
		std::cin >> idx;
		if (std::cin.fail())
		{
			std::cout << "올바른 숫자를 입력하세요." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			idx = -1;
		}
	}
	return idx;
}
int ES582::FindCANController(bool single)
{
	
	uint32_t nFound;
	int RxUriIdx = -1, TxUriIdx = -1;
	if (!OCI_FAILED(OCI_FindCANController(this->uriNames, 16, &nFound)))
	{
		std::cout << "검색 된 CAN 컨트롤러 목록:" << std::endl;
		for (uint32_t i = 0; i < nFound; i++)
		{
			std::cout << i << " >> " << this->uriNames[i] << std::endl;
		}
		RxUriIdx = this->SelectCANController(nFound);
		if(!single)
		{
			TxUriIdx = this->SelectCANController(nFound);
		}
	}
	else
	{
		return -1;
	}
	if(!OCI_FAILED(OCI_CreateCANControllerVersion(this->uriNames[RxUriIdx], &(this->version[RXCANIDX]), &(this->handle[RXCANIDX]))))	
	{
		std::cout << "선택된 CAN 컨트롤러: " << this->uriNames[RxUriIdx] << std::endl;
	}
	else
	{
		return -1;
	}
	if(!single)
	{
		if(!OCI_FAILED(OCI_CreateCANControllerVersion(this->uriNames[TxUriIdx], &(this->version[TXCANIDX]), &(this->handle[TXCANIDX]))))
		{
			std::cout << "선택된 CAN 컨트롤러: " << this->uriNames[TxUriIdx] << std::endl;
		}
		else
		{
			return -1;
		}
	}
	return 0;
		

}

void ES582::OpenCANController()
{
	bool single = false;
	this->FindCANController(single);
	for(int i=0; i<1+!single; i++)
	{
		memset(&(this->conf[i]), 0, sizeof(this->conf[i]));
	

		this->conf[i].baudrate = 500000;
		this->conf[i].samplePoint = 80;
		this->conf[i].samplesPerBit = OCI_CAN_THREE_SAMPLES_PER_BIT;
		this->conf[i].BTL_Cycles = 10;
		this->conf[i].SJW = 1;
		this->conf[i].syncEdge = OCI_CAN_SINGLE_SYNC_EDGE;
		this->conf[i].physicalMedia = OCI_CAN_MEDIA_HIGH_SPEED;

		this->conf[i].selfReceptionMode = OCI_SELF_RECEPTION_OFF;

		this->prop[i].mode = OCI_CONTROLLER_MODE_RUNNING;
		this->ec = OCI_OpenCANController(this->handle[i], &(this->conf[i]), &(this->prop[i]));
	}

	//this->ec = OCI_OpenCANController(this->handle, &(this->conf), &(this->prop));
		
	if (OCI_FAILED(this->ec))
	{

	}
	else
	{
		std::cout << "CAN 컨트롤러 버스 Open" << std::endl;				
	}
}

void ES582::listening()
{
	this->txQConf.reserved = 0;

	this->ec = OCI_CreateCANTxQueue(this->handle[0], &(this->txQConf), &(this->queue[0]));
	if(OCI_FAILED(this->ec))
	{
		std::cout << "Tx Queue 생성 실패" << std::endl;
		return;
	}

	this->rxQConf.onFrame.function = (OCI_CANRxCallbackFunctionSingleMsg)(this->FrameCallback);
	this->rxQConf.onFrame.userData = &(this->queue[0]);
	this->rxQConf.onEvent.function = (OCI_CANRxCallbackFunctionSingleMsg)(this->EventCallback);
	this->rxQConf.onEvent.userData = NULL;
	this->rxQConf.selfReceptionMode = OCI_SELF_RECEPTION_OFF;


	this->ec = OCI_CreateCANRxQueue(this->handle[0], &(this->rxQConf), &(this->queue[0]));
	if(OCI_FAILED(this->ec))
	{
		std::cout << "Rx Queue 생성 실패" << std::endl;
	}
	else
	{
		this->rxFilter[0].frameIDMask = 0;
		this->rxFilter[0].frameIDValue = 0;
		this->rxFilter[0].tag = 0;

		this->ec = OCI_AddCANFrameFilter(this->queue[0], this->rxFilter, 1);
		
		if(OCI_FAILED(this->ec))
		{
			std::cout << "Rx Filter 적용 실패" << std::endl;
		}
		else
		{
			std::cout << "Rx 수신 시작" << std::endl;
			while(true)
			{
				/*OCI_CANMessage msg[1];
				msg[0].type						= OCI_CAN_TX_MESSAGE;
				msg[0].reserved					= 0;
				msg[0].data.txMessage.frameID	= 0x0100 + 1;
				msg[0].data.txMessage.flags		= 0;
				msg[0].data.txMessage.res		= 0;
				msg[0].data.txMessage.dlc		= 8;
				for(int i=0; i<8; i++)
				{
					msg[0].data.txMessage.data[i] = i;
				}
				
				this->ec = OCI_WriteCANData(this->txQueue, OCI_NO_TIME, msg, 1, NULL);
				if(OCI_FAILED(this->ec))
				{
					std::cout << "Tx failed" << std::endl;
				}*/
				//::Sleep(500);

			}
		}
	}
}