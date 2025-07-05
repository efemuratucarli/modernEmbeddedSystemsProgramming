## Program Overview

This code is written for the TM4C123GH6PM microcontroller (Tiva C Series). It demonstrates a basic LED blinking pattern using direct register manipulation and a separate delay function.

- The **blue LED** is always **ON**.
- The **red LED** continuously **blinks** with different on and off durations (on for longer, off for shorter).
- The **green LED** is not used in this example.

The delay is implemented using a simple software loop in the `delay()` function to ensure compatibility with any compiler optimization level.

Key register features:
- `GPIO_PORTF_AHB_DATA_BITS_R[]` is used for direct bit-specific GPIO data access.
- `SYSCTL_GPIOHBCTL_R` enables the AHB bus for GPIOF, allowing faster GPIO access.

## LiveDemo
Check out the live demo of this lesson


https://github.com/user-attachments/assets/5a65f0dc-0af0-4cd2-826d-f0ab7c940b2d

