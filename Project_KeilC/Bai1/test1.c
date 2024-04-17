#include <stdint.h>

void delay (void){
    uint32_t i;
    for(i=0; i<5000000; i++){}
}

int count = 0;

void funCount (void) {
    count++;
    delay();
}