//written by surekha
/*Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like 
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and 
double, escape sequences, and comments. (This program is hard if you do it in full 
generality.) 
*/
//including header files
#include<stdio.h>
int main()
{
	int braces_cnt=0;    //variable for counting braces { }
	int bracket_cnt=0;   //variable for bracket count like [ ]
	int parentheses_cnt=0;   //variable for parantheses count like ( )
	int d_quote=0;   //flag variable for double quotes
	char ch;    //charecter variable for read charecter from buffer
	while((ch=getchar())!=EOF)
	{
		if((ch=='{')||(ch=='}'))
		{
			if(ch=='{')
				braces_cnt++;
			else
				braces_cnt--;
		}
		else if((ch=='[')||(ch==']'))
		{
			if(ch=='[')
				bracket_cnt++;
			else
				bracket_cnt--;
		}
		else if((ch=='(')||(ch==')'))
		{
			if(ch=='(')
				parentheses_cnt++;
			else
				parentheses_cnt--;
		}
		else if(ch=='"')
		{
			d_quote^=1;
		}
	}
	if((braces_cnt!=0)||(bracket_cnt!=0)||(parentheses_cnt!=0)||(d_quote!=0))
		printf("SYNTAX ERROR\n");
}


