//written by surekha
/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to 
handle quoted strings and character constants properly. C comments don't nest.*/
#include<stdio.h>
int main()
{
	int slc=0;	//flag variable for checking single line commants
        int mlc=0;      //flag variable for checking multi line commants
	int d_quote=0;  //flag variable for checking double quotes open or not
	char ch;        //for read charecter from buffer
	while((ch=getchar())!=EOF)
	{
		if((mlc==0)&&(slc==0)&&(d_quote==0)&&(ch=='"'))
		{
			putchar(ch);
			d_quote=1;
		}
		else if((d_quote==0)&&(mlc==0)&&(slc==0)&&(ch=='/'))
		{
			ch=getchar();
			if(ch=='/')
				slc=1;
			else if(ch=='*')
				mlc=1;
			else
			{
				putchar('/');
				if(ch==EOF)
					break;
				putchar(ch);
			}
		}
		else if((d_quote==0)&&(mlc==0)&&(ch=='\n')&&(slc==1))
		{
			slc=0;
		}
		else if((d_quote==0)&&(mlc==1)&&(ch=='*'))
		{
			ch=getchar();
			if(ch=='/')
				mlc=0;
			else
			{
				putchar('*');
				putchar(ch);
			}
		}
		else if((d_quote==1)&&(ch=='"'))
		{
			putchar('"');
			d_quote=0;
		}
		else if((mlc==0)&&(slc==0))
			putchar(ch);
	}
}
			






