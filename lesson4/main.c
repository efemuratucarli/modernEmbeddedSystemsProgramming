int main() {
    *((unsigned int *) (0x400FE608U)) = 0X20U; //clock gating to GPIOF
    *((unsigned int *) (0x40025400U)) = 0X0EU; //Direction Register
    *((unsigned int *) (0x4002551CU)) = 0X0EU; // Digital Enable Register
    
    while(1){
    //blink effect
    *((unsigned int *) (0x400253FCU)) = 0X02U; // turn on LED (DATA REGISTER)
    int counter = 0;
    while (counter < 1000000)
    {
      counter++;
    }
    *((unsigned int *) (0x400253FCU)) = 0X00U; // turn off LED
    counter = 0;
    while (counter < 1000000)
    {
      counter++;
    }
    }
    return 0;
}
