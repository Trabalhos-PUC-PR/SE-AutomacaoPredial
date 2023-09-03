//
// Created by kovalski on 03/09/23.
//

#include "sm2.h"
#include "hal.h"

STATE(sm2_init){
    pump(0);
    NEXT_STATE(sm2_pump_desligada);
}

STATE(sm2_pump_ligada){
    pump(1);
    if(s22() || !s11()){
        NEXT_STATE(sm2_pump_desligada);
    }
}

STATE(sm2_pump_desligada){
    pump(0);
    if(s11() && !s22()){
        NEXT_STATE(sm2_pump_ligada);
    }
    if(s22() && !s21()){
        NEXT_STATE(sm2_pump_erro);
    }
}

STATE(sm2_pump_erro){
    pump(0);
}