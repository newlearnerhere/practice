//written by surekha
/*Exercise 3-6.Write a version of itoa that accepts three arguments instead of two. The third 
argument is a minimum field width; the converted number must be padded with blanks on the 
left if necessary to make it wide enough.*/
//including header files
#include<stdio.h>
#include<string.h>
#define MAX 100
void inttoa(int n , char s[],int width);
void reverseof(char *s)
{
	int len,i=0,j,n;
	char temp;
	j=strlen(s)-1;
	//printf("j-%d\n",j);
	len=strlen(s);
	//printf("%d",len);
	n=len/2;
	//printf("n=%d",n);
	while(n)
	{
	//	printf("n=%d",n);
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		i++;
		j--;
		n--;
	}
	s[len]='\0';
	//printf("%s",s);
}


int main()
{
	char s[MAX];
	int num,width;
	printf("enter a number:");
	scanf("%d",&num);
	printf("enter the width of the string:");
	scanf("%d",&width);
	//reverseof(s);
	inttoa(num,s,width);
	printf("%s",s);
	return 0;
}
void inttoa(int num,char s[],int width)
{
	int i=0,len,sign,n;
	sign=num<0?-1:1;
	num=num<0?-num:num;
	do
	{
		s[i++]=num%10+'0';
	}while((num/=10)>0);
	if(sign==-1)
		s[i++]='-';
	s[i]='\0';
	//printf("%d %s",strlen(s),s);
	reverseof(s);
//	printf("%s",s);
	if(width<strlen(s))
		return;

	len=strlen(s)+1;
	n=width-len+1;
	while(n)
	{
		memmove(s+1,s,strlen(s)+1);
		s[0]='a';
		n--;
	}

}




