# Problem 2
Generate the map file (in my case, vector_table.map) for your program and provide details on:

**Question A**: How much total ROM your program is occupying?

**Answer:** 482 Bytes - 402 bytes of code; 80 bytes of data


**Question B**: How much total RAM your program is using?   

**Answer:** 8196 bytes


**Question C**: What part of your program is using the most ROM?

**Answer:** main.o, using 200 bytes of ROM.


**Question D**: What part of your program is using the most RAM?  

**Answer:** The stack, occupying 8192 bytes of RAM. This was created by the Linker, using the CSTACK value.
