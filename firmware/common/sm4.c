//
// Created by kovalski on 22/09/23.
//

#include "sm4.h"
#include "hal.h"

chrono c4;

STATE(sm4_init){
    boiler(1);
    NEXT_STATE(sm4_b1_ligado);
}

STATE(sm4_b1_ligado){
    boiler(1);
    if(sb12()){
        start_chronometer(&c4, 3500);
        NEXT_STATE(sm4_b1_desligado);
    }
    if(!sb11() && sb12()){
        NEXT_STATE(sm4_b1_erro);
    }
}

STATE(sm4_b1_desligado){
    boiler(0);
    if(!sb11() || is_finished_chronometer(&c4)){
        NEXT_STATE(sm4_b1_ligado);
    }
    if(!sb11() && sb12()){
        NEXT_STATE(sm4_b1_erro);
    }
}

STATE(sm4_b1_erro){
    boiler(0);
}