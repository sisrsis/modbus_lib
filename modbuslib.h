#ifndef MODBUSLIB_H_INCLUDED
#define MODBUSLIB_H_INCLUDED
#include <stdint.h>
#include <stdio.h>
#include "modbuslib.c"

void modbus(uint8_t modbus_id, uint8_t *modbus_data, uint8_t modbus_data_len, uint16_t *Register, uint8_t *data_transmit, uint8_t *data_transmit_lan);
#endif