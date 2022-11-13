#pragma once
#include <iostream>

#include <stdlib.h>

#include <OCI/oci.h>


#include "SearchForHw.h"

#define RXCANIDX 0
#define TXCANIDX 1

class ES582
{
private:
	OCI_ControllerHandle				handle[2];
	OCI_CANConfiguration                conf[2];
	OCI_CANControllerProperties         prop[2];
	BOA_Version							version[2] = {{ 1,0,0,0 }, {1,0,0,0}};
	OCI_ErrorCode						ec = 0;
	OCI_URIName							uriNames[16];	
	
	OCI_QueueHandle                 	rxQueue[2];
    OCI_CANRxQueueConfiguration     	rxQConf[2];
    OCI_CANRxFilter                 	rxFilter[2];
    OCI_QueueHandle                     txQueue[2];
    OCI_CANTxQueueConfiguration         txQConf[2];
    
	int can_num = 0;

	static void FrameCallback_1(void* qtxQueue1, struct OCI_CANMessage* msg1);
	static void FrameCallback_2(void* qtxQueue2, struct OCI_CANMessage* msg2);

	static void EventCallback_1(void* userData, struct OCI_CANMessage* msg);
	static void EventCallback_2(void* userData, struct OCI_CANMessage* msg);

	int FindCANController();
	
	

public:
	ES582()
	{
		ES582(DOUBLE_CAN);
	}
	ES582(int can_num): can_num(can_num) {};
	~ES582() {};
	
	void OpenCANController();
	void listening();

	enum
	{
		SINGLE_CAN = 0,
		DOUBLE_CAN = 1,
	};
	

};

