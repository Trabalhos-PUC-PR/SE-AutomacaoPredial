//
// Created by kovalski on 03/09/23.
//

#include "sm2.h"
#include "hal.h"

chrono c2;

STATE(sm2_init){
    pump(0);
    NEXT_STATE(sm2_pump_desligada);
}

STATE(sm2_pump_ligada){
    pump(1);
    if(s22() || !s11()){
        start_chronometer(&c2, valvePause());
        NEXT_STATE(sm2_pump_desligada);
    }
}

STATE(sm2_pump_desligada){
    pump(0);
    if(is_finished_chronometer(&c2) && s11() && !s22()){
        NEXT_STATE(sm2_pump_ligada);
    }
    if(s22() && !s21()){
        NEXT_STATE(sm2_pump_erro);
    }
}

STATE(sm2_pump_erro){
    pump(0);
}