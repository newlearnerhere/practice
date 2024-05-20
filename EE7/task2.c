//written by surekha
//EE7  task2 8/5/2024
//this file calculate the age of persons in a file and find the biggest among them and the largest name among them
#include<stdio.h>
#include<string.h>//malloc() or calloc()
#include<stdlib.h>
struct DATE 
{
	int day,month,year;
};
typedef struct
{
	char name[100];
	struct DATE dob;
}Person;
struct DATE age[10];
int i,len,j,indexx;
char longname[100];
void read_person(Person *per,char *s);
void calculate(Person pers,struct DATE cdate);
int days_in_month(int month, int year);
int main(int argc,char * argv[])
{
	Person per[10];
	struct DATE cdate;
	FILE *fp;
	
	if(argc!=5)
	{
		printf("./a.out current_date(dat month year) filename");
		return 0;
	}
	cdate.day=atoi(argv[1]);
	cdate.month=atoi(argv[2]);
	cdate.year=atoi(argv[3]);
	read_person(per,argv[4]);
	for(j=0;j<i;j++)
	{
		//printf("%d %d %d\n",age[j].day,age[j].month,age[j].year);
	        calculate(per[j],cdate);
		//printf("%d %d %d\n",age[j].day,age[j].month,age[j].year);
		printf("%s is %d years old\n",per[j].name,age[j].year);
	}
		printf("%s is bigger\n",per[indexx].name);
		printf("%s is the longest name\n",longname);

}
//read the data in the file into structure called Person
void read_person(Person *per,char *s)
{
	FILE *fp;
	fp=fopen(s,"r");
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	fscanf(fp,"%s",per[i].name);
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d",&per[i].dob.day,&per[i].dob.month,&per[i].dob.year);
		//printf("%s %d %d %d\n",per[i].name,per[i].dob.day,per[i].dob.month,per[i].dob.year);
		i++;
	        fscanf(fp,"%s",per[i].name);
	}
}
int days_in_month(int month, int year) {
    int days[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}
void calculate(Person pers,struct DATE cdate)
{
		int temp;
	if (cdate.day < pers.dob.day) 
	{
	    	cdate.day += days_in_month((cdate).month, (cdate).year);
            cdate.month -= 1;
    }
    if (cdate.month < (pers.dob).month) {
        cdate.month += 12;
        cdate.year -= 1;
    }
    //coping age to stuct DATE age[j]
    age[j].day = cdate.day - (pers.dob).day;
    age[j].month = cdate.month - (pers.dob).month;
    age[j].year = cdate.year - (pers.dob).year;
    //printf("%d %d %d\n", age[j].day, age[j].month, age[j].year);
    //comparing string length of names to find the largest name 
    temp=strlen(pers.name);
    if(temp>len)
    {
	    len=temp;
            strcpy(longname,pers.name);
    }
    //comaparing the ages to find the oldest person
    indexx=((age[j-1].year>age[j].year)?j-1:((age[j-1].year==age[j].year)?((age[j-1].month>age[j].month)?j-1:((age[j-1].month==age[j].month)?((age[j-1].day>age[j].day)?j-1:((age[j-1].day==age[j].day)?-1:j)):j)):j));
  
}








		

