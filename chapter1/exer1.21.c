//written by surekha
/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */
//replacing the blanks with tabs and blanks
//header files
#include<stdio.h>
#include<string.h>
#include <stdio_ext.h>
#define MAX 100
int main()
{
	char str[MAX];
	int n,scount=1,index,rem=0,tabc=0,temp,count=0;
	printf("enter tabstops: ");
	scanf("%d",&n);
	__fpurge(stdin);
	printf("enter string: ");
	fgets(str,MAX,stdin);
	if(n==1)
	{
		 printf("str=%s",str);
                 return 0;
	}
	for(index=0;index<=strlen(str);index++)
	{
		if(str[index]== ' ' && str[index+1]==' ')
		{
			scount++;
			continue;
		}
		//printf("c%d n%d %d\n",scount,n,strlen(str));
		count=scount;
		scount=1;
		if(count>=n)
		{
			if(n==count)
			{
				str[index-count+1]='#';
				memmove(str+(index-count+2),str+index+1,strlen(str+index+1)+1);
				count=0;
			}
			else
			{
				tabc=count/n;
				rem=count%n;
				memmove(str+(index-(count-rem-tabc-1)),str+index+1,strlen(str+index+1)+1);
				temp=index-count+1;
				while(tabc)
				{
					printf("t=%d\n",temp);
					str[temp++]='#';
					tabc--;
				}
			}
			//printf("%d %s\n",strlen(str+index+1),str);
			index--;
		}
	}
	printf("str=%s",str);
	return 0;
}
