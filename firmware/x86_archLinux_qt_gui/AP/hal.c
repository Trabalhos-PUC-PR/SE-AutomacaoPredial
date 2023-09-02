#include "../../common/hal.h"
#include <time.h>

uint8_t pin_s11=0;
uint8_t pin_s12=0;
uint8_t pin_v1=0;

void InitHAL(){
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

void v1(uint8_t s){
    pin_v1 = s;
}
