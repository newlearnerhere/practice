//written by surekha
/*Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that 
 tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the 
input or the value of n. Write the program so it makes the best use of available storage; lines 
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of 
fixed size. */
//including  header files
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define MAXLINES 100
int read_lines(char *linesptr[]);
char *my_getline();
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("ERROR..invalid argument formate\n");
		return 0;
	}
	char *linesptr[MAXLINES];
	int nlines,n,i;
	n=atoi(argv[1]);
	nlines=read_lines(linesptr);
	if(n>nlines)
		i=0;
	else
		i=nlines-n;
	while(i<nlines)
		printf("%s\n",linesptr[i++]);

}
int read_lines(char *linesptr[])
{
	int line_cnt=0;
	char *p;
	while((p=my_getline())!=NULL)
	{
		linesptr[line_cnt++]=p;
		if(line_cnt>=MAXLINES)
		{
			printf("reaches max line count\n");
			break;
		}
	}
	return line_cnt;
}
char *my_getline()
{
	char *p=NULL;
	int i=0;
	__fpurge(stdin);
	do
	{
		p=realloc(p,i+1);
		p[i++]=getchar();
		if(p[0]==EOF)
		{
			free(p);
			p=NULL;
			break;
		}
	}while(p[i-1]!='\n');
	if(p)
	p[i-1]='\0';
	return p;
}


