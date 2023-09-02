#include "sm1.h"
#include "hal.h"

STATE(sm1_init){
    v1(0);
    if(s12()) {
        NEXT_STATE(sm1_v1_desligada);
    }else{
        NEXT_STATE(sm1_v1_ligada);
    }
}

STATE(sm1_v1_ligada){
    v1(1);
    if(s12()){
        NEXT_STATE(sm1_v1_desligada);
    }
}

STATE(sm1_v1_desligada){
    v1(0);
    if(!s12()) {
        NEXT_STATE(sm1_v1_ligada);
    }
    if(!s11()) {
        NEXT_STATE(sm1_v1_erro);
    }
}

STATE(sm1_v1_erro){
    v1(-1);
}