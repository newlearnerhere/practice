//written by surekha
/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.*/
//including header files
#include<stdio.h>
#define swap(t,x,y) { t temp;\
	            temp=x;\
		    x=y;\
		    y=temp; }
int main()
{
	int x=10,y=20;
	char a='A',b='B';
	printf("before swapping x=%d,y=%d\n",x,y);
	swap(int,x,y);
	printf("after swapping x=%d,y=%d\n",x,y);
	printf("before swapping a=%c,b=%c\n",a,b);
	swap(char,a,b);
	printf("after swapping a=%c,b=%c\n",a,b);
}

