#include "behavior.h"

#include "hal.h"
#include "sm1.h"

StateMachine sm1;

void behavior(){
    InitHAL();
    INIT(sm1, sm1_init);
    while(1){
        EXEC(sm1);
    }
}
