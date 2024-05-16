//written by surekha 
/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.Should n be a variable or a symbolic parameter?*/
//replacing the tabs with spaces
//header files
#include<stdio.h>

int main()
{
	char c;
	int n,count=0;
	printf("enter tabstops: ");
	scanf("%d",&n);
	while((c=getchar()) !=EOF)//read the charector until end of the file(-1)
	{
		if(c=='\t')
		{
			c='#';
			for(int i=0;i<n;i++)
				putchar('#');

		}
		else if(c=='#')
		{
			count=0;
			while((c=getchar())=='#')
				count++;
	//		printf("%d %d\n",count,n-1);
			if(count==n-1)
				printf("#");
			else
			{
				count++;
				while(count--)
					putchar('#');
			}
			putchar(c);
		}		
		else 
			putchar(c);
	}


	return 0;
}
