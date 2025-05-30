#include "tm4c.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

int main() {
    
		SYSCTL_RCGCGPIO_R |= (1U << 5); //enable clock for GPIOF
	  SYSCTL_GPIOHBCTL_R |= (1U << 5);
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN); //set pins 1,2, and 3 as outputs
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN); // Digital Enable Register
    
		GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
    while(1){
        //blink effect
				//*((unsigned long volatile *) (0X40025000 + (LED_RED << 2))) = LED_RED;
				//*(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;
				GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        int volatile counter[2] = {0,0}; //delay in any level of optimization
        while (counter[0] < 1000000)
        {
          ++counter[0];
        }
				GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        while (*(counter+1) < 1000000)
        {
          ++counter[1];
        }
    }
    return 0;
}
