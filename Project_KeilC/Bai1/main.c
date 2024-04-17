#include "stm32f10x.h"

extern int count;
extern void delay (void);

int main (){		
	
	while(1){
		count++;
		delay();
	}	
}