//written by surekha
/*Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2. */
//including header files
#include<stdio.h>
#include<string.h>
void squeeze(char *s1,char *s2); 
int main()
{
	char s1[100],s2[100],*s;
	printf("Enter a string:");
	fgets(s1,100,stdin);
	printf("Enter another string:");
	fgets(s2,100,stdin);
	squeeze(s1,s2);
	printf("s1=%s,s2=%s\n",s1,s2);
	return 0;
}
void squeeze(char *s1,char *s2)
{
	char s[100];
	int i=0,j;
//	if(strcmp(s1,s2))
	{
	while(*s1)
	{
		for(j=0;s2[j];j++)
		{
			if(*s1==s2[j])
				break;
		}
		if(j==strlen(s2))
			s1++;
		else
			memmove(s1,s1+1,strlen(s1+1)+1);
	}
	}
}



