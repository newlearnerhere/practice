//written by surekha
/*Exercise 3-3.Write a function expand(s1,s2) that expands shorthand notations like a-z in 
  the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either 
  case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange 
  that a leading or trailing - is taken literally. */
//including header files
#include<stdio.h>
void expand(char*s1,char*s2);
int main()
{
	char s1[100],s2[100];
	printf("enter a short hand notation\n");
	fgets(s1,100,stdin);
	expand(s1,s2);
	printf("%s%s",s1,s2);
	return 0;
}
void expand(char * s1, char * s2)
{
	char c1,c2;
	int dcnt=0,i=0,j=0,k=0;
	while(s1[i]==' ')
	i++;
	if(s1[i]=='-')
		i++;
	if((s1[i]>='a' && s1[i]<='z')||(s1[i]>='A' && s1[i]<='Z'))
	{
		c1=s1[i];
		//printf("%c\n",c1);
		i++;
		while(s1[i]==' ')
			i++;
		if(s1[i]=='-')
		{
		/*	dcnt++;
		if(dcnt==2)
		{
			printf("invalid notation\n");
			return;
		}*/
		i++;
		while(s1[i]==' ')
		i++;
		if((c1>='a' && c1<='z'))
		{
			if(s1[i]>c1 && s1[i]<='z')
			{
				c2=s1[i];
				i++;
				 while(s1[i]==' ')
                                        i++;
                                if(s1[i]!='\n')
                                {
                                        printf("wrong notation\n");
                                        return;
                                }
			}
			else 
			{
				printf("wrong notation\n");
                                return;
			}
			//printf("%c\n",c2);
		}
		else if(c1>='A' && c1<='Z')
		{
			if(s1[i]>c1 && s1[i]<='Z')
			{
				c2=s1[i];
				i++;
		//		printf("%c",c2);
				 while(s1[i]==' ')
                                        i++;
		//		 printf("%c",s1[i]);
                                if(s1[i]!='\n')
                                {
                                        printf("wrong notation a\n");
                                        return;
                                }
			}
			else 
			{
				printf("wrong notation b\n");
				return;
			}		
			//printf("%c\n",c2);
		}
		}
		else
		{
			printf("wrong notation c\n");
			return;
		}
				//printf("hii");
	}
	else if(s1[i]>='0' && s1[i]<='9')
	{
		c1=s1[i];
		i++;
		while(s1[i]==' ')
			i++;
		if(s1[i]=='-')
		{
			/*dcnt++;
                        if(dcnt==2)
			{
				printf("invalid notation\n");
                                return;
                        }*/
                        i++;
                        while(s1[i]==' ')
				i++;
			if(s1[i]>c1 && s1[i]<='9')
			{
				c2=s1[i];
				i++;
				while(s1[i]==' ')
					i++;
				if(s1[i]!='\n')
				{
					printf("wrong notation d\n");
					return;
				}
			}
			else
			{
				printf("wrong notation e\n");
				return;
			}
		}
		else
                {
                        printf("wrong notation f\n");
                        return;
                }
	}
	else if(s1[i]!='\n') 
	{
		printf("wrong notation g\n");
		return;
        }
	for(i=0;c1+i<=c2;i++)
		s2[i]=c1+i;
	s2[i]='\0';
}


