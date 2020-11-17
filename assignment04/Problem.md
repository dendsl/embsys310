# Problem 1
**Question A**: What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?  

**Answer** The compliler produces the 'STR' instruction which tells the CPU to store the value in *R0* (our clock enable toggle) immediately into the address at *R1* (the Bit-Band Alias address for RCC_AHB2ENR)

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment04/project_bit_band/debug_bit_band.JPG">
</p>

**Question B**: What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?  

**Answer** Unlike in Bit-Banding, the compliler generates three instructions to write to RCC_AHB2ENR. First, it must load the value stored at the address of RCC_AHB2ENR (represented by the *LDR* instruction). Second, it performs a logical or operation (denoted by the *ORRS.W* instruction) on the value of the RCC_AHB2ENR register, and our clock enable toggle and stores that operation back into Register *R1*. Finally, it stores the value of Register *R1* back into the address of RCC_AHB2ENR.

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment04/project_bit_band/debug_register_manipulation.JPG">
</p>

