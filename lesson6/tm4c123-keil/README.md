## Program Overview

This code is written for the TM4C123GH6PM microcontroller (Tiva C Series). It demonstrates a simple LED blinking effect using direct register manipulation with GPIOF.

- The **blue LED** is always **ON**.
- The **red LED** **blinks continuously** (turns on and off with a delay loop).
- The **green LED** is not used in this example.
- The initial commented-out section showcases various **bitwise operations** (AND, OR, XOR, NOT, shift operations) for demonstration purposes.

The blinking effect is achieved by setting and clearing the red LED bit in the `GPIO_PORTF_DATA_R` register, along with a software delay using a volatile counter.


## LiveDemo
Check out the live demo of this lesson

https://github.com/user-attachments/assets/9f855011-b2e7-402e-9b9c-9082bada56fc

