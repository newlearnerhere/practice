//written by surekha
/*Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does 
getfloat return as its function value? */
//including header files
#include<stdio.h>
#include<ctype.h>
#define SIZE 100
int getfloat(float *);
void print(float *,int);
int power(int,int);
int main()
{
        float array[SIZE];
        int n;
        for(n=0;(n<SIZE) && (getfloat(&array[n]))!=EOF ; n++);
        print(array,n);
}
int getfloat(float *np)
{
        int c,sign=1,dp_flag=0,dp_cnt=0;
        while(isspace(c=getchar()));
        if((c=='+')||(c=='-'))
        {
                sign=(c=='-')?-1:1;
                c=getchar();
        }
        for(*np=0;isdigit(c); )
	{
		*np=(*np * 10)+(c - '0');
		c=getchar();
		if((dp_flag==0)&&(c=='.'))
		{
			dp_flag=1;
			c=getchar();
		}
		else if(dp_flag==1)
			dp_cnt++;
	}
        *np *= sign;
	if(dp_flag==1)
	{
		*np/=power(10,dp_cnt);
	}
        return c;
}
int power(int pow,int n)
{
	int result=1;
	while(n--)
		result*=10;
	return result;
}

void print(float *p,int n)
{
        for(int i=0;i<n;i++)
                printf("%f ",p[i]);
        printf("\n");
}

