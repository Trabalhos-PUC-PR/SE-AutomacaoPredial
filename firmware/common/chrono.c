#include "chrono.h"
#include "time.h"
#include "hal.h"

void start_chronometer(chrono* c, uint32_t deltaT){
    *c = now()+deltaT;
}

uint8_t is_finished_chronometer(chrono* c){
    return (now() >= *c);
}
