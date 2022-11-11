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
	//OCI_ControllerHandle				CAN1Handle;
	//OCI_ControllerHandle				CAN2Handle;
	OCI_CANConfiguration                conf[2];
	OCI_CANControllerProperties         prop[2];
	BOA_Version							version[2] = {{ 1,0,0,0 }, {1,0,0,0}};
	//BOA_Version						rxVersion = { 1,0,0,0 };
	//BOA_Version						txVersion = { 1,0,0,0 };
	OCI_ErrorCode						ec = 0;
	OCI_URIName							uriNames[16];	
	
	OCI_QueueHandle						queue[2];
	//OCI_QueueHandle                 	rxQueue;
    OCI_CANRxQueueConfiguration     	rxQConf;
    OCI_CANRxFilter                 	rxFilter[1];
    //OCI_QueueHandle                     txQueue;                // Transmit Queue handle
    OCI_CANTxQueueConfiguration         txQConf;                // Transmit Queue configurations
    

	static void FrameCallback(void* userData, struct OCI_CANMessage* msg);

	static void EventCallback(void* userData, struct OCI_CANMessage* msg);

	int SelectCANController(uint32_t nFound);
	int FindCANController(bool single);
public:

	ES582() {};
	~ES582() {};
	
	void OpenCANController();
	void listening();
	

};

