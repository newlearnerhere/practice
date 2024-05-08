#define CC cc
#define  CFlag -c
my_prog:1.o app.o helper.o
	gcc 1.o app.o  helper.o -Iheader.h -o my_prog

1.o:1.c
	CC CFlag 1.c  
my_app:app.c
	cc -c app.c
helper.o:helper.c
	cc -c helper.c

