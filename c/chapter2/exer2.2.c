/*Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. */
/*i changed for loop */ 
#include<stdio.h>
#define MAXLINE 1000 /* maximum input line size */
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int getlin(void);
void copy(void);
int main()
{ 
	int len; 
	extern int max; 
	extern char longest[]; 
	max = 0; 
	while ((len = getlin()) > 0) 
		if (len > max) { 
			max = len; 
			copy(); 
		} 
	if (max > 0) /* there was a line */ 
		printf("%s", longest); 
	return 0; 
}  
/* getline: specialized version */ 
int getlin(void) 
{ 
	int c, i; 
	extern char line[]; 
	for (i = 0; i < MAXLINE - 1 ; ++i)
	{
		c=getchar();
		if(c==EOF)
			break;
		else if(c=='\n')
			break;
		else
			line[i] = c;
	}	
	if (c == '\n') { 
		line[i] = c; 
		++i; 
	}
	line[i] = '\0'; 
	return i; 
} 
/* copy: specialized version */ 
void copy(void) 
{ 
	int i; 
	extern char line[], longest[]; 
	i = 0; 
	while ((longest[i] = line[i]) != '\0') 
		++i; 
}

