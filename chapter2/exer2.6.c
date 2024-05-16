//written by surekha
/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged.*/
//including header files
#include<stdio.h>
int setbits(int x ,int p,int n,int y);
int main()
{
	int x,p,n,y;
	printf("Enter a number :");
	scanf("%d",&x);
	printf("Enter bit position:");
	scanf("%d",&p);
	printf("Enter number of bits: ");
	scanf("%d",&n);
	if(p+1<n)
	{
		printf("number of bits are more compared to number of bits from given position\n");
		return 0;
	}
	printf("Enter another number:");
	scanf("%d",&y);
	x=setbits(x,p,n,y);
	printf("%d\n",x);
	return 0;
}
int setbits(int x ,int p,int n,int y)
{
	x=x & (~(~(~0<<n))<<(p-n+1));
	return	(x|((y& ~(~0<<n))<<(p-n+1)));
}
