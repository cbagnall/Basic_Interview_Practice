#include <stdio.h>
#include <math.h>
#include <unistd.h> //for timing which is faster
#include <time.h>

#define INT_BITS 32

void bitshift(int val)
{
    printf("The binary value of %d is ", val);
    struct timespec start, stop; 
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = INT_BITS - 1; i >= 0; --i){
	printf("%d", (val & (1 << i)) ? 1 : 0);
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);
    printf("\nTime using Bit Shifting: %ld ms\n", (stop.tv_nsec - start.tv_nsec)/1000);
}

void mod(int val)
{
    printf("The binary value of %d is ", val);
    int temp = 0;
    struct timespec start, stop; 
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = INT_BITS-1; i >= 0; i--){
	temp = val;
	val %= (int)pow(2,i);
	printf("%d", (temp == val ? 0 : 1));
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);
    printf("\nTime using Modulo opperator: %ld ms\n", (stop.tv_nsec - start.tv_nsec)/1000);
}

int main()
{
    int value=0, temp=0;
    printf("Please enter an integer value: ");
    scanf("%d", &value);
    bitshift(value);
    mod(value);
    return 0;
}
