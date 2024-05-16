//written by surekha
/*Exercise 4-1.Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.*/
//including header files
#include <stdio.h> 
 #define MAXLINE 1000 /* maximum input line length */ 
 int getlinee(char line[], int max); 
 int strindexx(char source[], char searchfor[]); 
 char pattern[] = "ould"; /* pattern to search for */ 
 /* find all lines matching pattern */ 
 int main() 
 { 
 char line[MAXLINE]; 
 int found = 0; 
 while (getlinee(line, MAXLINE) > 0) 
 if (found=strindexx(line, pattern)) {
	printf("%d\n",found); 
 } 
 return 0; 
 } 
 /* getline: get line into s, return length */ 
 int getlinee(char s[], int lim) 
 { 
 int c, i; 
 i = 0; 
 while (--lim > 0 && (c=getchar()) != EOF && c != '\n') 
 s[i++] = c; 
 if (c == '\n') 
 s[i++] = c; 
 s[i] = '\0'; 
 return i; 
 } 
 /* strindex: return index of t in s, -1 if none */ 
 int strindexx(char s[], char t[]) 
 { 
 int i=0, j, k,n,flag=0; 
for (i ; s[i] != '\0'; i++) { 
//	printf("%d\n",i);
for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
if (k > 0 && t[k] == '\0') 
{
	flag=1;
	n=i;
//	printf("n-%d\n",n);
}
}

if(flag==1)
	return n;
else
return -1; 
 } 

