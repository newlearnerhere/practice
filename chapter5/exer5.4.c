//written by surekha
/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the 
end of the string s, and zero otherwise. */
//including header files
#include<stdio.h>
#include<string.h>
int my_strend(char *,char *);
int main()
{
	char s[]="mahesh is very good boy employee";
	char t[]="employee";
	printf("%d\n",my_strend(s,t));
}
int my_strend(char *s,char *t)
{
	s=s+strlen(s)-strlen(t);
	while(*s)
	{
		if(*s!=*t)
			break;
		s++;
		t++;
	}
	if(*s)
		return 0;
	else
		return 1;
}



