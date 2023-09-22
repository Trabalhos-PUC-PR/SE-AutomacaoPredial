//
// Created by kovalski on 18/09/23.
//

#include "sm3.h"
#include "hal.h"

chrono c3;

STATE(sm3_init){
    v2(0);
    NEXT_STATE(sm3_v2_desligada);
}

STATE(sm3_v2_ligada){
    v2(1);
    if(s32() && s22()){
        start_chronometer(&c3, valvePause());
        NEXT_STATE(sm3_v2_desligada);
    }
}

STATE(sm3_v2_desligada){
    v2(0);
    if(!s22() || !s32() && s21() && is_finished_chronometer(&c3)){
        NEXT_STATE(sm3_v2_ligada);
    }
    if((s22() && !s21()) || (s32() && !s31())){
        NEXT_STATE(sm3_v2_erro);
    }
}

STATE(sm3_v2_erro){
    v2(0);
}