//
// Created by kovalski on 01/09/23.
//

#ifndef INC_20230901_HAL_H
#define INC_20230901_HAL_H

#include <stdint.h>

void InitHAL();
uint32_t Now();
uint8_t s11();
uint8_t s12();
void v1(uint8_t signal);

uint8_t s21();
uint8_t s22();
void pump(uint8_t signal);

uint8_t s31();
uint8_t s32();
void v2(uint8_t signal);

#endif //INC_20230901_HAL_H
