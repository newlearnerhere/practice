//EE6 (7/5/2024) by surekha
//this program reads the info of 3 persons and print it on the file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 3
typedef struct Person
{
	char  name[100];
	int age;
	int salary;
}person_arr;
void readPerson(struct Person*,int );//read from stdin and print it in data.txt file
int main()
{
	int i;
	char *hometown,*per_name;
	hometown=calloc(1,100);
	per_name=calloc(1,100);
	printf("enter number of persons: ");
	scanf("%d",&i);
	person_arr list[i];
	readPerson(list,i);
	return 0;
}
void readPerson(person_arr *list,int n)
{
	FILE *fp;
	fp=fopen("data.txt","w");
	for(int i=0;i<n;i++)
	{
		__fpurge(stdin);
	printf("Enter name of person%d: ",i+1);
	fgets(list[i].name,100,stdin);
	printf("Enter age of person%d: ",i+1);
	scanf("%d",&list[i].age);
	printf("Enter salary of person%d: ",i+1);
	scanf("%d",&list[i].salary);
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	fputs(list[i].name,fp);
	fprintf(fp,"%d\n",list[i].age);
	fprintf(fp,"%d\n",list[i].salary);
	}
	fclose(fp);
}



