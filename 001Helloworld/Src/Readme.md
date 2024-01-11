
# Using printf outputs on ARM Cortex M3/M4/M7 based MCUs.
-> this discussion is only applicable to MCUs based on ARM
cortex m3/m4/m7 or higher processors.
-> printf works over SWO pin (Serial wire output) of SWD
interface.

-> If you use a board based on Cortex m0 processor,
thnen use openOCD based semi hosting technique to use printf.

Inside ARM CORTEX M4 Processor
(ITM Unit) Instrumentation Trace Macrocell unit.
The ITM is an optional application driven trace source that supports printf style debugging to
trace operating system and application events, and generates diagnostic system information.
______________
Serial Wire Debud (SWD) is a Two - wire protocol for accessing the ARM debug interface.
SWD 
2 pin (debug) + 1 (trace)
___________________
=> SWD
1. Serial wire debug is 2 wire protocol for accessing the ARM debug interface
2. It is part of the ARM Debug interface specification v5 and is an alternative to JTAG.
3. The physical layer of SWD consists of 2lines.
-> SWDIO: a bidirectional data line
-> SWCLK : a clock driven by the host
4.By using SWD interface should be able to program MCUs internal flash, you can access memory regions,
add breakpoints , stop/run cpu.
5. The other good thing about SWD is you can use the serial wire viewer for your printf statements for
debugging.











### Memory Map of the MCU
### - -------------------------
ARM Cortex M4
Width of the system bus is 32 bits
the processor can product 2^32 of different addresses (4-Gigabyte)
range is :
0x0000_0000 to 0xffff_ffff
the manufacture put different peripherals into this range.

=> When the proessor produces 
0x4002 0000 on the system bus, it is actually referring to
the GPIOA registers.
these are manufacture dependent.

1. What is the base address of AHB1 BUS Peripherals ?

AHB1_PERI_START_ADDRESS:  0x4004 0000
AHB1_PERI_END_ADDRESS  :  0x4007 FFFF
 

2. What is the base address of GPIO-A registers ?
ans :
0x4002 0000
3. What is the base address of RCC engine registers of MCU ?
ans : 0x4002 3800
4. What is the base address of APB1 peripherals registers ?
ans : 0x4000 0000
5. What is the base address of FLASH memory ?
ans : 
6. what is the base address of SRAM ?
SRAM starts from :

size of SRAM1 = X bytes
base address of SRAM2 

7. What is the base address of ADC1 Registers ?
ans : 