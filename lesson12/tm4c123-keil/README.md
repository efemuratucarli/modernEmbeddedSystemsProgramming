## Program Overview

This project targets the TM4C123GH6PM (Tiva C Series) microcontroller and demonstrates GPIO control using the CMSIS device header (TM4C123GH6PM.h). 
The code configures Port F pins and creates a simple LED behavior using direct register access through CMSIS structs.

- **Blue LED (PF2)** is turned ON once at startup and stays **ON** continuously.
- **Red LED (PF1)** blinks forever:
  - **ON** for 500000 delay cycles
  - **OFF** for 500000 delay cycles
  - This blinking pattern continues indefinitely.
- The **green LED** is not used in this example.

The blinking is created by writing to the bit-specific addressing array GPIOF_AHB->DATA_Bits[...], which allows changing a single pin(or combinatons of them (totally 256 combinations)) without touching other bit/s.

## Key Concepts Demonstrated

### 1) CMSIS-Based Register Access

Instead of using raw register(macro based) addresses, this project uses **CMSIS-style peripheral structures** provided by `TM4C123GH6PM.h`. This approach improves readability and portability while still allowing low-level hardware control.

The following CMSIS registers are used:

- `SYSCTL->RCGCGPIO`  
  Enables clock gating for GPIO peripherals

- `SYSCTL->GPIOHBCTL`  
  Selects the **AHB bus interface** for GPIO Port F (faster than older way of APB bus)

- `GPIOF_AHB->DIR` / `GPIOF_AHB->DEN`  
  Configures GPIO direction and enables digital functionality

- `GPIOF_AHB->DATA_Bits[mask]`  
  Provides **bit-specific access** to GPIO pins without affecting other bits

---

### 2) Clock Gating and AHB Selection

Before GPIO Port F can be accessed, its clock must be enabled and the correct bus interface must be selected.

- `SYSCTL->RCGCGPIO |= (1U << 5);`  
  Enables the clock for **GPIO Port F**

- `SYSCTL->GPIOHBCTL |= (1U << 5);`  
  Switches GPIO Port F from the APB interface to the **AHB interface**

Once enabled, all GPIO operations are performed using the `GPIOF_AHB` register set.

---

### 3) GPIO Direction and Digital Enable

The onboard LEDs are connected to pins **PF1, PF2, and PF3**, which are configured as digital outputs.

- `DIR` register  
  Selects the pin direction (output)

- `DEN` register  
  Enables the digital function for the selected GPIO pins

This configuration allows direct control of the LEDs through GPIO data registers.

---

### 4) Delay Loop (Software Delay)

The `delay()` function implements a **busy-wait software delay** using a simple loop.

## LiveDemo

Check out the live demo of this lesson

https://github.com/user-attachments/assets/5c2e6b02-3bd0-48bb-8766-d7a515df2710
