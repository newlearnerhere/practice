//written by surekha
/*Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned.*/
#include<stdio.h>
#include<limits.h>
int main()
{
	printf("unsigned char range: 0 to %d\n",UCHAR_MAX);
	printf("signed char range: %d to %d\n",SCHAR_MIN,SCHAR_MAX);
	printf("unsigned short int range: 0 to %hu\n",USHRT_MAX);
        printf("signed short int range: %hd to %hd\n",SHRT_MIN,SHRT_MAX);
	printf("unsigned int range: 0 to %u\n",UINT_MAX);
	printf("signed int range: %d to %d\n",INT_MIN,INT_MAX);
	printf("unsigned long int range: 0 to %lu\n",ULONG_MAX);
        printf("signed long int range: %ld to %ld\n",LONG_MIN,LONG_MAX);
	return 0;
}

