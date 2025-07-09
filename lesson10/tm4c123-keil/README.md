## Program Overview

This code is written for the TM4C123GH6PM microcontroller (Tiva C Series). It demonstrates a simple LED blinking effect using the GPIO peripheral in direct register access mode.

- The **blue LED** is always **ON**.
- The **red LED blinks in a pattern** based on a variable delay:
  - First, it turns **ON for a long duration** (1,000,000 cycles) and **OFF for a short duration** (500,000 cycles).
  - Then, it turns **OFF for a long duration** (1,000,000 cycles) and **ON for a short duration** (500,000 cycles).
  - This alternating blinking pattern continues indefinitely.
- The **green LED** is not used in this example.

The blinking effect is created by toggling the red LED pin and introducing software delay loops using volatile counters. The variable delay behavior is controlled through a `swap()` function that exchanges the ON and OFF durations every cycle.

## LiveDemo

Check out the live demo of this lesson