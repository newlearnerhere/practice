//written by surekha
/*.Exercise 4-2. Extend atof to handle scientific notation of the form 
 123.45e-6 
where a floating-point number may be followed by e or E and an optionally signed exponent. */
//including heaer files
#include<stdio.h>
#include <ctype.h> 
#include<math.h>
double atof(char s[]);
//double poww(int b,int ipow);
//int isspace(char );
//int isdigit(char );
 /* atof: convert string s to double */ 
 double atof(char s[]) 
 { 
 double val, power; 
 int i, sign,ipow; 
 for (i = 0; isspace(s[i]); i++) /* skip white space */ 
 ; 
 sign = (s[i] == '-') ? -1 : 1; 
 if (s[i] == '+' || s[i] == '-') 
 i++; 
 for (val = 0.0; isdigit(s[i]); i++) 
 val = 10.0 * val + (s[i] - '0'); 
 if (s[i] == '.') 
 i++; 
 for (power = 1.0; isdigit(s[i]); i++) { 
 val = 10.0 * val + (s[i] - '0'); 
 power *= 10; 
 } 
 val= sign * val / power;
if(s[i]=='e' || s[i]=='E')
{
       i++;
       sign = (s[i] == '-') ? -1 : 1;
       i++;
       for (ipow=0; isdigit(s[i]); i++)
       {
	      printf("%c\n",s[i]); 
		ipow = 10 * ipow + (s[i] - '0');
       }
       printf("p=%d\n",ipow);
       val=val*pow(10.0,sign*ipow);
 }
return val;
}
/*double poww(int b,int ipow)
{
	double val=1.0;
	if(ipow<0)
	{
		ipow=-ipow;
		for(int i=0;i<ipow;i++)
		{
			val/=10;
		}
	}
	else
	{
		for(int i=0;i<ipow;i++)
                {
                        val*=10;
                }
	}
	return val;
}
int isspace(char c)
{
	if(c==' ')
		return 1;
	else
		return 0;
}
int isdigit(char c)
{
	if(c>='0' && c<='9')
		return 1;
	else
		retuen 0;
}*/
int main()
{
	char s[100];
	printf("Enter: ");
	fgets(s,100,stdin);
	printf("%g",atof(s));
	return 0;
}

