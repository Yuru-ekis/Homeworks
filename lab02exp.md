# Explanation

## Task 3

> Explain the hexadecimal representations of the printed "val"    

val's data type is integer, which means that its size is $4$ bytes.

"0x" means that it is a hexadecimal numeral. Just like "0" stands for octal numeral.       
"96" is positive, we can convert it to hex without special treatment.     
"-1" is negative, below are the converting steps.     

1. The positive value of "-1" is "1".
2. Convert the positive value in decimal to a 4 bytes binary value. the result is "0000 0000 0000 0000 0000 0000 0000 0001".
3. Negate every bit of the binary, the result is "1111 1111 1111 1111 1111 1111 1111 1110".
4. Add 1 to "1111 1111 1111 1111 1111 1111 1111 1110", the result is "1111 1111 1111 1111 1111 1111 1111 1111".
5. Convert the binary value to hex. The conversation was done as below:     
   $1111\space1111\space1111\space1111\space1111\space1111\space 1111\space 1111 =$      
   $1×2^3+1×2^2+1×2^1+1×2^0 | 1×2^3+1×2^2+1×2^1+1×2^0|$     
   $1×2^3+1×2^2+1×2^1+1×2^0|1×2^3+1×2^2+1×2^1+1×2^0|$     
   $1×2^3+1×2^2+1×2^1+1×2^0|1×2^3+1×2^2+1×2^1+1×2^0$     
   $1×2^3+1×2^2+1×2^1+1×2^0|1×2^3+1×2^2+1×2^1+1×2^0|$     
   $=15|15|15|15|15|15|15|15$         
   In hex, 10=A, 11=B,  12=C, 13=D, 14=E, 15=F. So the result is $\texttt{0xFFFFFFFF}$.

"-128" is negative, too. We can convert it to hex using the method above.

## Task 4

> Add function calls to test overflow for the following additions and explain the output results.
> 1)  uchar 125+150
> 2)  char 64+63
> 3)  char 64+64
> 4)  char (-64)+(-64)
> 5)  char (-64)+(-65)

The output results is:    

```
Test overflow for unsigned and signed char

    uchar addition 5 + 6 is in bound
    char addition -3 + 9 is in bound
    uchar addition 125 + 150 overflow
    char addition 64 + 63 is in bound
    char addition 64 + 64 overflow
    char addition -64 + -64 is in bound
    char addition -64 + -65 underflow
```

The size of unsigned char and char in C programming language is 8 bits.       
The range of unsigned char in decimal is 0 to 255.       
The range of signed char in decimal is -128 to 127.       

- $125 + 150 = 275$, which is more than $255$. Overflow.
- $64 + 63=127$, which equals to $127$. In bound.     
- $64+64=128 > 127$, overflow.
- $-64 + -64=-128$, in bound.
- $-64+-65=-129$, underflow.     
