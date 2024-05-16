/*. Exercise 2-9.In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount.*/
#include<stdio.h>
int bitcount(int);
int main()
{
	int x;
	printf("enter x value:");
	scanf("%d",&x);
	printf("%d\n",bitcount(x));
	return 0;
}
int bitcount(int x)
{
	int bit_cnt;
	for(bit_cnt=0 ; x ; x&=(x-1))
		bit_cnt++;
	return bit_cnt;
}


