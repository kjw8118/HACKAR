#ifndef __CAN_TOOLS_H__
#define __CAN_TOOLS_H__

namespace CAN_TOOLS
{
    template<typename T>
    T decoding(uint8_t *msg, int start_bit, int length_bit, double factor, T offset)
    {
        uint64_t buffer = 0;

        int current_bit = start_bit;

        while(length_bit > 0)
        {
            buffer = (buffer<<1) | ((msg[current_bit/8] & (1<<(current_bit%8))) != 0);
            
            current_bit++;
            length_bit--;
        }

        T decoded_value = (T)(buffer * factor) + offset;

        return decoded_value;
    };

    /*template<typename T>
    void encoding(T decoded_value, uint8_t *msg, int start_bit, int length_bit, double factor, T offset)
    {
        uint64_t buffer = (uint64_t)((decoded_value - offset)/factor);
        
        int current_bit = start_bit;
        while(length_bit > 0)
        {
            msg[current_bit/8] |= ((buffer ))) != 0);
            
            current_bit++;
            length_bit--;
        }

    };*/


};



#endif