#include "../../common/hal.h"
#include <time.h>

uint8_t pin_s11;
uint8_t pin_s12;
uint8_t pin_v1;
uint8_t pin_s21;
uint8_t pin_s22;
uint8_t pin_pump;

uint8_t pin_v2;
uint8_t pin_s31;
uint8_t pin_s32;

uint8_t pin_b1;
uint8_t pin_sb11;
uint8_t pin_sb12;

double temp;
double tanque1;
double tanque2;
double tanque3;


void InitHAL(){
    tanque1 = 0;
    tanque2 = 0;
    tanque3 = 0;
    pin_v1 = 0;
    pin_s11 = 0;
    pin_s12 = 0;
    pin_s21 = 0;
    pin_s22 = 0;
    pin_pump = 0;

    temp = 0;
    pin_b1 = 0;
    pin_sb11 = 0;
    pin_sb12 = 0;
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

uint8_t s31(){
    return pin_s31;
}

uint8_t s32(){
    return pin_s32;
}

void v2(uint8_t signal){
    pin_v2 = signal;
}

uint64_t now(){
    return clock()/1000;
}

uint16_t valvePause(){
    return 5000;
}

uint8_t sb11(){
    return pin_sb11;
}

uint8_t sb12(){
    return pin_sb12;
}

void boiler(uint8_t signal){
    pin_b1 = signal;
}