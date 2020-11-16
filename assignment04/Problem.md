# Problem 1
**Question A**: What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?  
**Answer** The compliler produces the 'STR' instruction which tells the CPU to store the value in *R0* (our clock enable toggle) immediately into the address at *R1* (the Bit-Band Alias address for RCC_AHB2ENR)

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment04/project_bit_band/debug_bit_band.JPG">
</p>

**Question B**: What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?  

**Answer** TODO

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment04/project_bit_band/debug_register_manipulation.JPG">
</p>

