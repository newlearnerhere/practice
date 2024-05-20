//EE6 (7/5/2024) by surekha
//this program reads the name of the person and print  the details of the person in the file if that person present
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
typedef struct 
{
	char  name[100];
	int age;
	int salary;
}person;
person search(char*);
int main()
{
	char name[100];
	person per;
	printf("Enter the name of the person: ");
	fgets(name,100,stdin);
	per=search(name);//if person present then it returns structureof that person
	if(strcmp(per.name,"\0"))
	{
		printf("age=%d\nsalary=%d\n",per.age,per.salary);
	}
	else
		printf("person not present\n");

	return 0;
}
person search(char * name)
{
	FILE *fp;
	person temp={0,0,0};
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	fgets(temp.name,100,fp);
	while(!feof(fp))//check until the end of the file
	{
		fscanf(fp,"%d %d",&temp.age,&temp.salary);
		if(strcmp(temp.name,name)==0)
			return temp;//return stucture
		fgets(temp.name,100,fp);
	}
	strcpy(temp.name,"\0");
	return temp;
	fclose(fp);
}



