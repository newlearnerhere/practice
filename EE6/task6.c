//EE6 (7/5/2024) by surekha
//this program reads the info of 3 persons and add it on the file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define MAX 3
void add_details(void);//add the details to the persons
int main()
{
	add_details();
	return 0;
}
void add_details(void)
{
	FILE *fp,*cp;
	char data[100],name[100];
	fp=fopen("cpdata.txt","r");
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	cp=fopen("fullinfo.txt","w");
	if(cp==NULL)
	{
		perror("cp");
		exit(0);
	}
	fgets(name,100,fp);
	while(!feof(fp))
	{
		printf("%s",name);
		fprintf(cp,"%s",name);
	        fgets(data,100,fp);
		fprintf(cp,"%s",data);
		fgets(data,100,fp);
		fprintf(cp,"%s",data);
		fgets(data,100,fp);
		fprintf(cp,"%s",data);
		printf("Enter the street name: ");
		fgets(data,100,stdin);
		fprintf(cp,"streetname:%s",data);
		printf("Enter the house number: ");
		fgets(data,100,stdin);
		fprintf(cp,"house number:%s",data);
		printf("Enter the postel code: ");
		fgets(data,100,stdin);
		fprintf(cp,"postal code:%s",data);
		printf("Enter the state: ");
		fgets(data,100,stdin);
		fprintf(cp,"state:%s",data);
	        fgets(name,100,fp);
	}
	fclose(cp);
	fclose(fp);
}



