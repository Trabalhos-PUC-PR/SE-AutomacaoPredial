#ifndef CHRONO_H
#define CHRONO_H

#include <stdint.h>

typedef uint32_t chrono;
/**
 * @param c chrono
 * @param deltaT in ms
 */
void start_chronometer(chrono* c, uint32_t deltaT);
uint8_t is_finished_chronometer(chrono* c);

#endif // CHRONO_H
