#include "tictacto.h"
#include "snake.h"
#include <windows.h>
#include <ctype.h>
char play;


void load();

main()
{
	char x;
	char y;
	
	puts("Welcome");
	puts("Which game do you want to play ?");
	puts("Press");
	do{
	
	printf("1- Tic Tac To\t2- Snake");
	x= getch();
	switch(x)
	{
		case '1':
			load();
			tic();
			break;
		case '2':
			//load();
			snake();
			break;
		default:
			puts("Error\n");
			break;
	}//switch ends here
	puts("Want to play again ?(y/n)");
	scanf("%c",&play);
	if(play=='y'||play=='Y'){
		snake();
	}
	else if(play=='N'||play=='n'){
		break;
	}
}
		while(1);
	} //main ends here ..
     



void load(){
    int r;
    system("cls");
    
    puts("loading...");
    for(r=1;r<=20;r++){
    Sleep(300);
    printf("%c",177);}
}
