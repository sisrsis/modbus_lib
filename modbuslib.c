#include <stdint.h>

#include <stdio.h>
#include "mod_crc.h"
void modbus(uint8_t modbus_id, uint8_t *modbus_data, uint8_t modbus_data_len, uint16_t *Register, uint8_t *data_transmit, uint8_t *data_transmit_lan)
{

    void CRC(uint8_t * modbus_data_crc, uint8_t modbus_data_len_crc, uint8_t * data_low, uint8_t * data_high)
    {
        uint16_t crc = CRC16(modbus_data_crc,modbus_data_len_crc);
        uint8_t crc_low = crc >> 8;
        uint8_t crc_high = crc;
        *data_low = crc_low;
        *data_high = crc_high;
    }
    void transmit(uint8_t mode, uint8_t * data, uint8_t len)
    {
        
        switch (mode)
        {
        case 0x03:
            data_transmit[0] = modbus_id;
            data_transmit[1] = mode;
            data_transmit[2] = (modbus_data[4] * 256) + (modbus_data[5]) * 2;
            int y = 3;
            for (int x = 0; x < len; x++,y++)
            {
                data_transmit[y] = data[x]; 
            }
            CRC(data_transmit, y, &data_transmit[y + 1], &data_transmit[y ]);
            *data_transmit_lan = y+2;
            break;

        default:
            break;
        }
    }
    void Read_Holding_Register()
    {
        uint16_t start_addreas_ragister = modbus_data[2] << 8 | modbus_data[3];
        uint16_t Quantity_addres_ragister = modbus_data[4] << 8 | modbus_data[5];
        if(Quantity_addres_ragister>125){}
        else
        {

        uint8_t data_read[125];
        int y = 0;
       // printf(":%d:",start_addreas_ragister);
        //for (int x=0;x < Quantity_addres_ragister ;x++)printf("%d ",ragiser[x]);
        for (int x = start_addreas_ragister; x < (start_addreas_ragister + Quantity_addres_ragister);x++,y++)
        {   
                       
            data_read[y] = Register[x]>>8;
            data_read[++y] = Register[x]&0xFF; 


        }
        transmit(0x03, data_read, y);
        }
    }

    if (modbus_id == modbus_data[0])
    {
        if(CRC16(modbus_data,modbus_data_len)==0)
        {
                switch (modbus_data[1])
                {
                case 0x03:
                    Read_Holding_Register();
                    break;
                case 0x06:
                    break;
                default:
                    break;
                }
        }
            
    }
}

