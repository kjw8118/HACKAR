#include "can.h"
//#include "mcp_can.h"
#include "gpio_interface.h"
#include <iostream>


CANHS can1;
CANHS can2;
#define target_in 0
#define target_out 1

double aReq = 0;
double dist = 0;

void routing()
{
    uint8_t buf[8] = {0,};
    uint8_t len = 0;
    can1.readMsgBuf(len, buf);
    uint32_t id = can1.getCanId();
    switch(id)
    {
        case target_in: // get data
            dist = buf[0];
            break;
        case target_out: // put data
            buf[0] = aReq;
            break;
        default:
            break;
    }
    can2.sendMsgBuf(id, 0, len, buf);

    

}

void algo()
{
    while(true)
    {
        if(dist == 0)
            aReq = 0;
        else
            aReq = 1;
    }
}

int main()
{
    GPIO::init_gpio();
    can1.begin();
    can2.begin();
    GPIO::attachInterrupt(2, routing, GPIO::FALLING);
    //MCP_CAN CAN0(8);
    //CAN0.begin(CAN_500KBPS, MCP_8MHz);
    /*while(true)
    {
        uint8_t buf[8] = {0,};
        uint8_t len = 0;
        //CAN0.readMsgBuf(&len, buf);
        can1.readMsgBuf(len, buf);
        uint32_t id = can1.getCanId();
        std::cout << std::hex << (unsigned)id << " >> ";
        for(int i=0; i<len; i++)
        {
            std::cout << (unsigned)buf[i] << " ";
        }
        std::cout << std::endl;
    }*/
    
    
}