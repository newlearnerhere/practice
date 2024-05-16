//written by surekha
/*Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */
//including header files
#include<stdio.h>
#define MAX 20
int flagh=0;
int htoi(char *);
int main()
{
	char hex[MAX];
	int i;
	printf("Enter headecimal value:");
	scanf("%s",hex);
	i=htoi(hex);
	if(i==0 && flagh==1)
		printf("invalid hexadecimal value\n");
	else
		printf("integer value of %s is %d\n",hex,i);
}
int htoi(char * hex)//hexadecimal to integer
{
	int i,num,val=0;
	if(hex[0]=='0' &&( hex[1]=='x' || hex[1]=='X'))
		i=2;
	else
		i=0;
	for(i;hex[i];i++)
	{
		if(hex[i]>='0' && hex[i]<='9')
			num=hex[i]-'0';
		else if (hex[i]>='a' && hex[i]<='f')
			num=hex[i]-'a'+10;
		else if (hex[i]>='A' && hex[i]<='F')
			num=hex[i]-'A'+10;
		else
		{
			flagh=1;
			return 0;
		}
		val=val<<4|(num & 0Xf);
	}
	return val;
}




