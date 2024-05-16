//written by surekha
/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert 
an integer into a string by calling a recursive routine. */
//including header files
#include<stdio.h>
void my_itoa(char s[],int);
int i=0;
int main()
{
	char s[100];
	int n;
	printf("enter the number:");
	scanf("%d",&n);
	my_itoa(s,n);
	s[i]='\0';
	printf("%s\n",s);
	return 0;
}
void my_itoa(char s[],int n)
{
	if(n<0)
	{
		s[i++]='-';
		n=-n;
	}
	if(n/10)
		my_itoa(s,n/10);
	s[i++]=(n%10)+'0';
}


