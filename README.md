# embedded_security

This was a workshop as well as a competition for implementing predesigned lightweight security algorithms which are suitable for 8 bit, 16 bit , 32 bit platforms.

cryprology
    |
    |
cryptography --------------- cryptanalysis    
    |
    |
symmetric------------- assymetric
    |
    |
block cypher ---------- stream cypher

Block cyphers(block length 64 bits):
1. Friestal Network:
  64 bit plane text is divided into 2 32 bit left and right blocks.
2. SP:
  substitution and permutation blocks 
3. GFS

Basic Building blocks of cipher designing :
1. S block.
2. bit permutation.
3. Block permutation.
4. circular shift.
see basic_blocks.c and generalised_basic_blocks.c for details

following cypher designs are implemented on FPGA and ARM Cortex M3 based LPC1768 microcontroller:
