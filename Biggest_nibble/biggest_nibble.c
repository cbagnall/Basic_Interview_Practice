#include <stdio.h>

#define NIBBLES_PER_UNSIGNED 8
#define SIZEOF_NIBBLE 4
#define NIBBLE 0xF //(4 bits / byte) 00001111 in Bin -> OXF in hex 

unsigned biggest_nibble(unsigned a, unsigned b)
{
    unsigned a_nib;
    unsigned b_nib;
    unsigned mask = NIBBLE;
    unsigned final = 0;
    
    for(int i = 0; i < NIBBLES_PER_UNSIGNED; i++){        
        a_nib = a & mask;
        b_nib = b & mask;
        
        if(a_nib >= b_nib){
            final |= a_nib;
        }
        else{
            final |= b_nib;
        }
        mask = mask << SIZEOF_NIBBLE;
    }
    return final;
}

int main()
{
    unsigned a = 0x12346789;
    unsigned b = 0x2568BCF1;
    
    unsigned c = biggest_nibble(a, b);
    printf("0x%x\n", c);  
}

