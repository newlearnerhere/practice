//written by surekha
//EE7  task1 on 8/5/2024
//this program read the lines from 2 different files and return the difference between the lines
#include<stdio.h>
#include<string.h>//for strcmp
int main(int argc,char *argv[])
{
	FILE *f1p,*f2p,*f3p;
	char arr1[100],arr2[100];
	int line_n=0;
	if(argc!=3)
	{
		printf("./a.out filename1 filename2\n");
		return 0;
	}
	if(!strcmp(argv[1],argv[2]))//both are same then exit
	{
		printf("both files having same name\n");
		return 0;
	}
	f1p=fopen(argv[1],"r");
	f2p=fopen(argv[2],"r");
	f3p=fopen("output1","w");
	if(f1p==NULL)
	{
		perror("f1p");
		return 0;
	}
	if(f2p==NULL)
	{
		perror("f2p");
		return 0;
	}
	if(f3p==NULL)
	{
		perror("f3p");
		return 0;
	}
	//printf("%d\n%s %s",line_n,arr1,arr2);
	fgets(arr1,100,f1p);
	fgets(arr2,100,f2p);
	//printf("%d\n%s %s",line_n,arr1,arr2);
	while(!feof(f1p) && !feof(f2p) && line_n!=10)//reading up to end of files or up to 10 lines
	{
		++line_n;
		int i=0;
		if(strcmp(arr1,arr2))
		{
			//printf("%d ",i);
			fprintf(f3p,"%d\n%s%s",line_n,arr1,arr2);
			//printf("%d\n%s %s",line_n,arr1,arr2);
		}
		fgets(arr1,100,f1p);
		fgets(arr2,100,f2p);
	}
}





