//written by surekha
/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. */
//including headerfiles
#include<stdio.h>
 int invert(int x,int p,int n);
int main()
{
        int x,p,n;
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
        x=invert(x,p,n);
        printf("%d\n",x);
        return 0;
}
int invert(int x,int p,int n)
{
        return  (x^((~(~0<<n))<<(p-n+1)));
}
