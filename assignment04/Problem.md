# Problem 1  
Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bitband region to enable the clock to Port A, then answer the following:  

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


# Problem 2 
Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:  

    void func1(int param1, int param2, int param3, int param4, int param5)
    {
        int temp1 = param1;
        int temp2 = param2;
        int temp3 = param3;
        int temp4 = param4;
        int temp5 = param5;
        
        return;
    }
     
    void func2(void)
    {
        func1(1,2,3,4,5);
        
        return;
    }

**Question A**: How does the **calling** function “func2” pass the values to the **called** function “func1”?

**Answer** TODO

**Question B**: What extra code did the compiler generate before calling the function “func1” with the multiple arguments?

**Answer** TODO

**Question C**: What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?

**Answer** TODO

**Question D**: Any other observations?

**Answer** TODO
