#include <stdio.h>

void reverse_string(char* s)
{

    if(!s) {
        return;
    }

    char* end_ptr = s;
    char* begin_ptr = s;
    char swap;    
    int str_len = 0;
    
    while(*end_ptr !=  '\0') { 
        end_ptr++;
        str_len++;
    }
    end_ptr--; //end_ptr now points to '\0' character so we have to shift it back one space..
    
    for(int i = 0; i < str_len / 2; i++) {
        swap = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = swap;
        end_ptr--;
        begin_ptr++;
    }
}

int main()
{
  char str[] = "ABCDEFGHIJ";
  printf("Original String is: %s\n", str);
  reverse_string(str);
  printf("Reversed String is: %s\n", str);
  
}

