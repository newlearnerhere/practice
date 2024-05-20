//written by surekha
//EE7  task2 8/5/2024
//this file calculate the age of persons in a file and find the biggest among them
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
struct DATE age[100];
int i,len,j,indexx;
char longname[100];
int main(int argc,char * argv[])
{
	Person per[10];
	struct DATE cdate;
	FILE *fp;
	int j=0;
	if(argc!=5)
	{
		printf("./a.out current_date(dat month year) filename");
		return 0;
	}
	cdate.day=atoi(argv[1]);
	cdate.month=atoi(argv[2]);
	cdate.year=atoi(argv[3]);
	read_person(per,argv[4]);
	age=calloc(i,sizeof(struct DATE));
	for(j=0;j<i;j++)
	{
	    	//days_in_month(2,2024);
		calculate(per[j],cdate,age[j]);
		printf("%s is %d years old\n",per[j].name,age[j].year);
	}

}
void read_person(Person **per,char *s)
{
	FILE *fp;
	//printf("%s\n",s);
	fp=fopen(s,"r");
	if(fp==NULL)
	{
		perror("fp");
		exit(0);
	}
	per[i]=calloc(1,sizeof(Person));
//	fgets(per[i]->name,100,fp);
	fscanf(fp,"%s",per[i]->name);
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %d",&per[i]->dob.day,&per[i]->dob.month,&per[i]->dob.year);
		printf("%s %d %d %d\n",per[i]->name,per[i]->dob.day,per[i]->dob.month,per[i]->dob.year);
		i++;
	        per[i]=calloc(1,sizeof(Person));
		//fgets(per[i]->name,100,fp);
	        fscanf(fp,"%s",per[i]->name);
	}
}
int days_in_month(int month, int year) {
    int days[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("%d\n",days[month-1]);
    return days[month - 1];
}
void calculate(Person *pers,struct DATE cdate,struct DATE *per_age)
{
		int temp;
	if (cdate.day < (pers->dob).day) 
	{
//	    	cdate->day += 
	    	//days_in_month((*cdate).month, (*cdate).year);
	    	days_in_month(2,2024);
  //              cdate->month -= 1;
    }
    /*if (cdate->month < (pers->dob).month) {
        cdate->month += 12;
        cdate->year -= 1;
    }
    per_age=calloc(1,sizeof(struct DATE));
    per_age->day = cdate->day - (pers->dob).day;
    per_age->month = cdate->month - (pers->dob).month;
    per_age->year = cdate->year - (pers->dob).year;
    temp=strlen(pers->name);
    if(temp>len)
	    len=temp;
    strcpy(longname,pers->name);
    indexx=((age[j-1].year>per_age->year)?j-1:((age[j-1].year==per_age->year)?((age[j-1].month>per_age->month)?j-1:((age[j-1].month==per_age->month)?((age[j-1].day>per_age->day)?j-1:((age[j-1].day==per_age->day)?-1:j)):j)):j));
   */
}








		

