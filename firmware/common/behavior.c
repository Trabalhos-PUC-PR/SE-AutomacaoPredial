#include "behavior.h"

#include "hal.h"
#include "sm1.h"
#include "sm2.h"

StateMachine sm1;
StateMachine sm2;

void behavior(){
    InitHAL();
    INIT(sm1, sm1_init);
    INIT(sm2, sm2_init);
    while(1){
        EXEC(sm1);
        EXEC(sm2);
    }
}
