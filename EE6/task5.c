//EE6 (7/5/2024) by surekha
//this program reads the surname info of 3 persons from the file and add it on to the file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 3
void add_sur(void);//add the surname to the details and print it to the file
int main()
{
	add_sur();
	return 0;
}
void add_sur(void)
{
	FILE *fp,*cp;
	char data[100];
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	cp=fopen("cpdata.txt","w");
	if(cp==NULL)
	{
		perror("cp");
		exit(0);
	}
	fgets(data,100,fp);
	while(!feof(fp))
	{
		fprintf(cp,"name:%s",data);
		printf("Enter the surname %s: ",data);
		fgets(data,100,stdin);
		fprintf(cp,"surname:%s",data);
		fgets(data,100,fp);
		fprintf(cp,"age:%s",data);
		fgets(data,100,fp);
		fprintf(cp,"salary:%s",data);
	        fgets(data,100,fp);
	}
	fclose(cp);
	fclose(fp);
}



