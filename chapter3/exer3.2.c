//written by surekha
/*Exercise 3-2.Write a function escape(s,t) that converts characters like newline and tab 
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write 
a function for the other direction as well, converting escape sequences into the real characters.*/
//including header files
#include<stdio.h>
void escape(char* s,char* t);
int main()
{
	char  str[100],t[200];
	printf("Enter a string: ");
	fgets(str,100,stdin);
	escape(str,t);
	printf("%s\n%s\n",str,t);
	return 0;
}
void escape(char *s,char *t)
{
	int i=0;
	while(*s)
	{
		switch(*s)
		{
			case '\n':t[i++]='\\';
				  t[i++]='n';
				  break;
			case '\t':t[i++]='\\';
                                  t[i++]='t'; 
                                  break;
			case '\\':s++;
				  if(*(s)=='n')
					  t[i++]='\n';
				  else if(*(s)=='t')
					  t[i++]='\t';
				  else
					  t[i++]=*s;
				  break;
			default:t[i++]=*s;
				break;
		}
		s++;
	}
	t[i]='\0';
}



