//writen by surekha
/*Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the 
string s in place.*/
//including header files
#include<stdio.h>
void my_reverse(char s[]);
int main()
{
	char s[1000];
	printf("enter the string:\n");
	scanf("%[^\n]s",s);
	my_reverse(s);
	printf("\n");
	return 0;
}
void my_reverse(char s[])
{
	if(*(s+1))
		my_reverse(s+1);
	printf("%c",*s);
}


