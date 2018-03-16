#include <stdio.h>

int main(int argc, char* argv[])
{
	unsigned short val = 0x0000;

	unsigned short arr[8];
	arr[0] = 0x4500;
	arr[1] = 0x003c;
	arr[2] = 0x1c46;
	arr[3] = 0x4000;
	arr[4] = 0x4006;
	arr[5] = 0xb1e6;
	arr[6] = 0xac10;
	arr[7] = 0x0a63;
	
	for(int i = 0; i < 6; i++)
	{
		val += arr[i];
	}
	printf("%x\n", val); 
}
