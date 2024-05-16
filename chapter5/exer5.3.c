//written by surekha
/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: 
strcat(s,t) copies the string t to the end of s. */
//including header files
#include<stdio.h>
#include<string.h>
void my_strcat(char *,char *);
int main()
{
	char s[100]="mahesh ";
	char t[]="einfochips employee";
	my_strcat(s,t);
	printf("%s\n",s);
}
void my_strcat(char *s,char *t)
{
	int i;
	s=s+strlen(s);
	while(*t)
		*s++=*t++;
	*s='\0';
}



