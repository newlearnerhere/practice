//written by surekha
/*Exercise 3-5.Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a 
hexadecimal integer in s.*/
//including header files
#include<stdio.h>
#include<string.h>
void itob(int,char s[],int);//integer to binary
void reverse(char s[]);//reverse the string
int main()
{
	int n,b;
	char s[50];
	printf("enter the number:");
	scanf("%d",&n);
	printf("enter the base value:");
	scanf("%d",&b);
	if(b<0)
		printf("enter valid base value\n");
	else
	{
		itob(n,s,b);
		printf("%s\n",s);
	}
	return 0;
}
void itob(int n,char s[],int b)
{
	int i=0,rem;
	while(n)
	{
		rem=n%b;
		if(b==16)
			rem=(rem<10)?(rem+'0'):(rem-10+'A');
		else
			rem=rem+'0';
		s[i++]=rem;
		n/=b;
	}
	s[i]='\0';
	reverse(s);
}
void reverse(char s[])
{
	int i,j;
	char temp;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}


