//EE6 (7/5/2024) by surekha
//this program reads the info of 3 persons from file and print it in stdin
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 3
typedef struct 
{
	char  name[100];
	int age;
	int salary;
}person;
void Print(void);//read from file and print it in display
int main()
{
	Print();
	return 0;
}
void Print(void)
{
	FILE *fp;
	char data[100];
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	fgets(data,100,fp);
	while(!feof(fp))
	{
		//fgets(data,100,fp);
		printf("name: %s",data);

		fgets(data,100,fp);
		printf("age: %s",data);
		fgets(data,100,fp);
		printf("salary: %s",data);
	        fgets(data,100,fp);
	}



	fclose(fp);
}



