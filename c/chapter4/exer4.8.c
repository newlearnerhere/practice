//written by surekha
/*Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify 
getch and ungetch accordingly.*/
//including header files
#include <stdio.h>

char buf = 0;

/* getch: get a (possibly) pushed back character */
char getch(void)
{
    char c;

    if(buf != 0)
        c = buf;
    else
        c = getchar();

    buf = 0;
    return c;
}

/* ungetch: push a character back into input */
void ungetch(int c)
{
	if(buf==0)
		buf=c;
}

int main(void)
{
    int c;

    while((c=getchar()) != EOF)
    {
	    if(c=='\n')
	    {
		    putchar(getch());
		    putchar('\n');
	    }
	    else
		    ungetch(c);
    }

    return 0;
}



