//written by surekha
/*Exercise 3-4.. In a two's complement number representation, our version of itoa does not 
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why 
not. Modify it to print that value correctly, regardless of the machine on which it runs.*/
//including header files
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) 
{
    char buffer[20];
    int n;
    printf("enter n value:\n");
    scanf("%d",&n);
    itoa(n,buffer);
    printf("Buffer : %s\n",buffer);

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ( n /= 10 );
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) 
{
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


