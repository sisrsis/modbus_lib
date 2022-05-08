#ifndef MODBUSLIB_H_INCLUDED
#define MODBUSLIB_H_INCLUDED
#include <stdint.h>
#include <stdio.h>
#include "modbuslib.c"

void modbus(uint8_t modbus_id,uint8_t * modbus_data,uint8_t modbus_data_len,uint16_t * ragiser,uint8_t *ragiser_trasmit,uint8_t * ragiser_trasmit_lan);
#endif