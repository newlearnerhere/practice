//printing the lines that are greater than 80 charectors
#include<stdio.h>
#define MAX 1000
int getlinee(char str[], int limit);
//int getline(char str[],int limit);
int main()
{
	int ilen;
	char arrline[MAX];
	while((ilen=getlinee(arrline,MAX))>0)
	{
		if(ilen>80)
		{
			printf("%s \n",arrline);
		}
	}
}
int getlinee(char str[],int limit)
{
	char c;
	int index;
	for(index=0;index<limit && (c=getchar()) != EOF && c != '\n' ;index++)
			str[index]=c;
	if(c == '\n')
	{
		str[index]='\n';
		index++;
	}
	str[index]='\0';
	return index;
}

	

