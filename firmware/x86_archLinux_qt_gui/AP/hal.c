#include "../../common/hal.h"
#include <time.h>

uint8_t pin_s11;
uint8_t pin_s12;
uint8_t pin_v1;
uint8_t pin_s21;
uint8_t pin_s22;
uint8_t pin_pump;

void InitHAL(){
    pin_v1 = 0;
    pin_s11 = 0;
    pin_s12 = 0;
    pin_s21 = 0;
    pin_s22 = 0;
    pin_pump = 0;
}

uint32_t Now(){
    return clock();
}

uint8_t s11(){
    return pin_s11;
}

uint8_t s12(){
    return pin_s12;
}

void v1(uint8_t signal){
    pin_v1 = signal;
}

uint8_t s21(){
    return pin_s21;
}

uint8_t s22(){
    return pin_s22;
}

void pump(uint8_t signal){
    pin_pump = signal;
}
