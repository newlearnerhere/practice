//written by surekha
/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which 
operate on at most the first n characters of their argument strings. For example, 
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.*/
//including header files
#include<stdio.h>
#include<string.h>
//void my_strncpy(char *,char *,int);
//int my_strncmp(char *,char *,int);
void my_strncat(char *,char *,int);
int main()
{
	char s[100]="mahesh";
	char t[100]="akhil";
	//my_strncpy(s,t,5);
	//printf("%s\n",s);
	//printf("%d\n",my_strncmp(s,t,3));
	my_strncat(s,t,3);
	printf("%s\n",s);
}
void my_strncpy(char *s,char *t,int n)
{
	int i;
	for(i=0;(i<n) && t[i] ;i++)
		s[i]=t[i];
	s[i]='\0';
}
void my_strncat(char *s,char *t,int n)
{
	int i;
	s=s+strlen(s);
	for(i=0;(i<n) && t[i] ;i++)
	{
		*s=t[i];
		s++;
	}
	*s='\0';
}
int my_strncmp(char *s,char *t,int n)
{
	int i;
	for(i=0;(i<n) && s[i] ; i++)
	{
		if(s[i]!=t[i])
			break;
	}
	if(i==n)
		return 0;
	return s[i]-t[i];
}

