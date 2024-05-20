//EE6 (7/5/2024) by surekha
//this program reads the info of 3 persons and print the home town of given person
#include<stdio.h>
#include<stdlib.h>//for calloc()
#include<string.h>//for strcmp()
#define MAX 3
struct Person
{
	char  name[100];
	char  home_town[100];
}person_arr[MAX];
void readPerson(struct Person*);//read the person info from file
char * searchTown(struct Person*,char * per_name);//search the name of person and give details
int main()
{
	int i;
	char *hometown,*per_name;
	hometown=calloc(1,100);
	per_name=calloc(1,100);
	readPerson(person_arr);
	printf("Enter name of the person: ");
	fgets(per_name,100,stdin);
	if(hometown=searchTown(person_arr,per_name))//if person found return hometown  else return NULL
	{
		printf("%s\n",hometown);
	}
	else
		printf("person not present");
	return 0;
}
void readPerson(struct Person * person_arr)//read input from file to structure
{
	for(int i=0;i<MAX;i++)
	{
	printf("Enter name of person%d: ",i+1);
	fgets(person_arr[i].name,100,stdin);
	printf("Enter home town of person%d: ",i+1);
	fgets(person_arr[i].home_town,100,stdin);
	}
}
char * searchTown(struct Person *person_arr,char * per_name)	
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(strcmp(person_arr[i].name,per_name)==0)//comparing input with structure members
		{
			return person_arr[i].home_town;
		}
	}
	return NULL;
}



