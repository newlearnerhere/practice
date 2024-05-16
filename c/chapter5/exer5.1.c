//written by surekha
/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid 
representation of zero. Fix it to push such a character back on the input. */
//including header files
#include<stdio.h>
#include<ctype.h>
#define SIZE 100
int getint(int *);
int main()
{
	int num;
	if(getint(&num)==1)
		printf("Invalid Entry..\n");
	else
	printf("%d\n",num);
}
int getint(int *np)
{
	int c,sign=0;
	while(isspace(c=getchar()));
	if((c=='+')||(c=='-'))
	{
		sign=c;
		c=getchar();
	}
	for(*np=0;isdigit(c);*np=(*np * 10)+(c - '0'),c=getchar());
	if(sign=='-')
		(*np)*=-1;
	if((*np==0)&&((sign=='-')||(sign=='+')||(isalpha(c))))
		return 1;
	return 0;
}


