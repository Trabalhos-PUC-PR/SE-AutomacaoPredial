//
// Created by kovalski on 18/09/23.
//

#include "sm3.h"
#include "hal.h"

chrono c3;

STATE(sm3_init){
    v2(0);
    NEXT_STATE(sm3_v2_ligada);
}

STATE(sm3_v2_ligada){
    v2(1);
    if(s32()){
        start_chronometer(&c3, valvePause());
        NEXT_STATE(sm3_v2_desligada);
    }
}

STATE(sm3_v2_desligada){
    v2(0);
    if(is_finished_chronometer(&c3) && !s32() &&s21()){
        NEXT_STATE(sm3_v2_ligada);
    }
}
