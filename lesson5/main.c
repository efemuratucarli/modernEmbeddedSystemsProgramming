#include "tm4c.h"

//my own definition of registers
/*#define RCGCGPIO (*((unsigned int *) (0x400FE608U))) //clock gating control

#define GPIOF_BASE 0X40025000U
#define GPIOF_DIR (*((unsigned int *) (GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int *) (GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int *) (GPIOF_BASE + 0x3FCU)))*/

int main() {
    SYSCTL_RCGCGPIO_R = 0X20U; //enable clock for GPIOF
    GPIO_PORTF_DIR_R = 0X0EU; //set pins 1,2, and 3 as outputs
    GPIO_PORTF_DEN_R = 0X0EU; // Digital Enable Register
    
    while(1){
        //blink effect
        GPIO_PORTF_DATA_R  = 0X02U; // turn on LED (DATA REGISTER)
        int volatile counter = 0; //delay in any level of optimization
        while (counter < 1000000)
        {
          counter++;
        }
        GPIO_PORTF_DATA_R  = 0X00U; // turn off LED
        counter = 0;
        while (counter < 1000000)
        {
          counter++;
        }
    }
    return 0;
}
