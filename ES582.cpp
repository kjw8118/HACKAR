#include "ES582.h"
#include <cstring>
#include <iostream>
#include <windows.h>

void ES582::FrameCallback_1(void *ptxQueue1, struct OCI_CANMessage *msg1)
{
	OCI_QueueHandle txQ1 = *(OCI_QueueHandle *)ptxQueue1;
	OCI_ErrorCode ec = 0;
	switch (msg1->type)
	{
	case OCI_CAN_RX_MESSAGE:
		OCI_CANMessage txMsg1[1];
		txMsg1[0].type = OCI_CAN_TX_MESSAGE;
		txMsg1[0].reserved = 0;
		txMsg1[0].data.txMessage.frameID = msg1->data.rxMessage.frameID;
		txMsg1[0].data.txMessage.flags = msg1->data.rxMessage.flags;
		txMsg1[0].data.txMessage.res = msg1->data.rxMessage.res;
		txMsg1[0].data.txMessage.dlc = msg1->data.rxMessage.dlc;
		for (int i = 0; i < msg1->data.rxMessage.dlc; i++)
		{
			txMsg1[0].data.txMessage.data[i] = msg1->data.rxMessage.data[i];
		}

		ec = OCI_WriteCANData(txQ1, OCI_NO_TIME, txMsg1, 1, NULL);
		if (OCI_FAILED(ec))
		{
			std::cout << "CAN 1 Tx 에러 발생" << std::endl;
			system("pause");
		}
		else
		{
			//std::cout << "Receive frame id: " << std::hex << msg1->data.rxMessage.frameID << " " << std::dec << msg1->data.rxMessage.timeStamp << std::endl;
		}
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

void ES582::FrameCallback_2(void *ptxQueue2, struct OCI_CANMessage *msg2)
{
	OCI_QueueHandle txQ2 = *(OCI_QueueHandle *)ptxQueue2;
	OCI_ErrorCode ec = 0;
	switch (msg2->type)
	{
	case OCI_CAN_RX_MESSAGE:
		OCI_CANMessage txMsg2[1];
		txMsg2[0].type = OCI_CAN_TX_MESSAGE;
		txMsg2[0].reserved = 0;
		txMsg2[0].data.txMessage.frameID = msg2->data.rxMessage.frameID;
		txMsg2[0].data.txMessage.flags = msg2->data.rxMessage.flags;
		txMsg2[0].data.txMessage.res = msg2->data.rxMessage.res;
		txMsg2[0].data.txMessage.dlc = msg2->data.rxMessage.dlc;
		for (int i = 0; i < msg2->data.rxMessage.dlc; i++)
		{
			txMsg2[0].data.txMessage.data[i] = msg2->data.rxMessage.data[i];
		}

		ec = OCI_WriteCANData(txQ2, OCI_NO_TIME, txMsg2, 1, NULL);
		if (OCI_FAILED(ec))
		{
			std::cout << "CAN 2 Tx 에러 발생" << std::endl;
			system("pause");
		}
		else
		{
			//std::cout << "Receive frame id: " << std::hex << msg2->data.rxMessage.frameID << " " << std::dec << msg2->data.rxMessage.timeStamp << std::endl;
		}
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

void ES582::EventCallback_1(void *userData, struct OCI_CANMessage *msg)
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
void ES582::EventCallback_2(void *userData, struct OCI_CANMessage *msg)
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
int ES582::FindCANController()
{

	uint32_t nFound;

	if (OCI_FAILED(OCI_FindCANController(this->uriNames, 16, &nFound)))
	{
		std::cout << "CAN 컨트롤러 검색 실패" << std::endl;
		return -1;
	}
	std::cout << "검색 된 CAN 컨트롤러 목록:" << std::endl;
	for (uint32_t i = 0; i < nFound; i++)
	{
		std::cout << i << " >> " << this->uriNames[i] << std::endl;
	}

	int RxUriIdx = -1;
	while (RxUriIdx < 0 || RxUriIdx >= nFound)
	{
		std::cout << "RX CAN 컨트롤러 번호를 입력하세요: ";
		std::cin >> RxUriIdx;
		if (std::cin.fail())
		{
			std::cout << "올바른 숫자를 입력하세요." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			RxUriIdx = -1;
		}
	}
	if (OCI_FAILED(OCI_CreateCANControllerVersion(this->uriNames[RxUriIdx], &(this->version[RXCANIDX]), &(this->handle[RXCANIDX]))))
	{
		std::cout << "Rx CAN 컨트롤러 생성 실패" << std::endl;
		return -1;
	}
	std::cout << "선택된 RX CAN 컨트롤러: " << this->uriNames[RxUriIdx] << std::endl;

	int TxUriIdx = -1;
	while (TxUriIdx < 0 || TxUriIdx >= nFound)
	{
		std::cout << "TX CAN 컨트롤러 번호를 입력하세요: ";
		std::cin >> TxUriIdx;
		if (std::cin.fail())
		{
			std::cout << "올바른 숫자를 입력하세요." << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			TxUriIdx = -1;
		}
	}
	if (RxUriIdx == TxUriIdx)
	{
		this->can_num = SINGLE_CAN;
	}
	else
	{
		if (OCI_FAILED(OCI_CreateCANControllerVersion(this->uriNames[TxUriIdx], &(this->version[this->can_num]), &(this->handle[this->can_num]))))
		{
			std::cout << "Tx CAN 컨트롤러 생성 실패" << std::endl;
			return -1;
		}
	}
	std::cout << "선택된 TX CAN 컨트롤러: " << this->uriNames[TxUriIdx] << std::endl;

	return 0;
}

void ES582::OpenCANController()
{
	this->FindCANController();

	for (int i = 0; i < 1 + (this->can_num); i++)
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
		if (OCI_FAILED(this->ec))
		{
			std::cout << i << " CAN 컨트롤러 버스 Open failed" << std::endl;
			return;
		}
		std::cout << i << " CAN 컨트롤러 버스 Open" << std::endl;

		this->txQConf[i].reserved = 0;
		this->ec = OCI_CreateCANTxQueue(this->handle[i], &(this->txQConf[i]), &(this->txQueue[i]));
		if (OCI_FAILED(this->ec))
		{
			std::cout << i << " Tx Queue 생성 실패" << std::endl;
			return;
		}
		std::cout << i << " CAN Tx Queue 생성" << std::endl;
	}
}

void ES582::listening()
{
	OCI_CANRxCallbackFunctionSingleMsg ffp[2];
	OCI_CANRxCallbackFunctionSingleMsg efp[2];
	
	ffp[0] = (OCI_CANRxCallbackFunctionSingleMsg)(this->FrameCallback_1);
	ffp[1] = (OCI_CANRxCallbackFunctionSingleMsg)(this->FrameCallback_2);

	efp[0] = (OCI_CANRxCallbackFunctionSingleMsg)(this->EventCallback_1);
	efp[1] = (OCI_CANRxCallbackFunctionSingleMsg)(this->EventCallback_2);

	for (int i = 0; i < 1 + (this->can_num); i++)
	{
		this->rxQConf[i].onFrame.function = ffp[i];
		this->rxQConf[i].onFrame.userData = &(this->txQueue[this->can_num - i]);
		this->rxQConf[i].onEvent.function = efp[i];
		this->rxQConf[i].onEvent.userData = NULL;
		this->rxQConf[i].selfReceptionMode = OCI_SELF_RECEPTION_OFF;

		this->ec = OCI_CreateCANRxQueue(this->handle[i], &(this->rxQConf[i]), &(this->rxQueue[i]));
		if (OCI_FAILED(this->ec))
		{
			std::cout << "Rx Queue 생성 실패" << std::endl;
			return;
		}

		this->rxFilter[i].frameIDMask = 0;
		this->rxFilter[i].frameIDValue = 0;
		this->rxFilter[i].tag = 0;

		this->ec = OCI_AddCANFrameFilter(this->rxQueue[i], this->rxFilter, 1);

		if (OCI_FAILED(this->ec))
		{
			std::cout << "Rx Filter 적용 실패" << std::endl;
			return;
		}
		std::cout << i << " Rx 준비 완료" << std::endl;
	}
	//::Sleep(5000);
	std::cout << "수신 시작" << std::endl;
	while (true)
	{
		
	}
	
}