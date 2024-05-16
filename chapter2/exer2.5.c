//written by surekha
/*Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
(The standard library function strpbrk does the same job but returns a pointer to the 
location.)*/
//including header files
#include<stdio.h>
int any(char *s1,char*s2);
int main()
{
	char s1[100],s2[100],*s;
	int ad;
	printf("Enter a string: ");
	fgets(s1,100,stdin);
	printf("Enter another string: ");
	fgets(s2,100,stdin);
	//printf("%s,%s\n",s1,s2);
	ad=any(s1,s2);
	if(ad==-1)
	{
		printf("no charector of s2 is present in s1\n");
	}
	else
	{
	//	s=ad;
		printf(" %d \n ",ad);
	}
}
int any(char *s1,char* s2)
{
	while(*s2)
	{
		if(*s2==' ' || *s2=='\n')
		{
			s2++;
			continue;
		}
		for(int i=0;s1[i];i++)
		{
	//		printf("%ld\n",s1[i]);
			if(*s2==s1[i])
				return i;
		}
		s2++;
	}
	return -1;
}



