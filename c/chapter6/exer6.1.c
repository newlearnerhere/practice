//written by surekha
/*Exercise 6-1. Our version of getword does not properly handle underscores, string constants, 
comments, or preprocessor control lines. Write a better version.*/
//including header files
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 100
struct key
{
	char *word;
	int count;
}keytab[]={"signed",0,
	   "unsigned",0,
	   "int",0,
	   "char",0,
	   "float",0,
	   "double",0,
	   "if",0,
	   "else",0,
	   "for",0,
	   "while",0,
	   "do",0,
	   "switch",0,
	   "auto",0,
	   "register",0,
	   "static",0,
	   "extern",0,
	   "case",0,
	   "default",0,
	   "long",0,
	   "short",0,
	   "break",0,
	   "continue",0,
	   "struct",0,
	   "union",0,
	   "typedef",0,
	   "enum",0,
	   "goto",0,
	   "return",0,
	   "void",0,
	   "const",0,
	   "sizeof",0,
	   "volatile",0};
#define NKEYS sizeof(keytab)/sizeof(struct key)
int getword(char *);
int search_word(char *);
int main()
{
	char word[MAXSIZE];
	int n;
	while(getword(word)!=EOF)
		if((n=search_word(word))>=0)
			keytab[n].count++;
	for(n=0;n<NKEYS;n++)
		printf("%s %d\n",keytab[n].word,keytab[n].count);
}
/*getting word from input buffer*/
int getword(char *word)
{
	char ch;
	int i=0;
	while(isspace(ch=getchar()));
	if(ch==EOF)
		return ch;
	do
	{
		word[i++]=ch;
		ch=getchar();
	}while((ch!='\n')&&(i<(MAXSIZE-1)));
	word[i]='\0';
	return i;
}
/*search weather the word present in the structure or not*/
int search_word(char *word)
{
	int i;
	for(i=0;i<NKEYS;i++)
	{
		if((strcmp(keytab[i].word,word))==0)
			break;
	}
	if(i==NKEYS)
		return -1;
	return i;
}


