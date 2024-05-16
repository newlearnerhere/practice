//written by surekha
/*.Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, 
with a conditional expression instead of if-else. */
#include<stdio.h>
 /* lower: convert c to lower case; ASCII only */
 /*int lower(int c)
 {
 if (c >= 'A' && c <= 'Z')
 return c + 'a' - 'A';
 else
 return c;
 }*/
 int lower(int c)
 {
 return (c >= 'A' && c <= 'Z')? c ^ 32 :c;
 }
int main()
{
	char c;
	scanf("%c",&c);
	c=lower(c);
	printf("%c",c);
	return 0;
}

