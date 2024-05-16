//written by header files
/*Exercise 2-8.Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n positions.*/
//including header files
#include<stdio.h>
 int rightrot(int x,int n);
void binary(int x)
{
	for(int i=31;i>=0;i--)
	{
		printf("%d",(x>>i)&1);
	}
}
int main()
{
        int x,n;
        printf("Enter a number :");
        scanf("%d",&x);
        printf("Enter number of bits: ");
        scanf("%d",&n);
	binary(x);
	printf("\n");
        x=rightrot(x,n);
        printf("%d\n",x);
	binary(x);
        return 0;
}
int rightrot(int x,int n)
{
    return ((x >> n) & ~(~0<< (32 - n)))| (x << (32 - n));
}
