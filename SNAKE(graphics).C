#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

#define MOVE 15
#define DIFF 5

void snake_head();
void snake();
void border();
void input();
void control();
void snake_body(int i);
void setup();
void food();

typedef enum {STOP=0, UP, DOWN, LEFT, RIGHT} edirection;
enum edirection dir=STOP;

int gameover=0;
int x=320,y=240;
int len=0;
int foodx=550, foody=350;
int x_body[100], y_body[100];

main()
{
	int grd=DETECT, grm;
	initgraph(&grd, &grm, "C:\\TURBOC3\\BGI\\");
	while(!gameover)
	{
		delay(200);
		cleardevice();
		setup();
		snake();
		printf("x= %d, y= %d\n" ,x,y);
		printf("foodx= %d, foody= %d", foodx, foody);
	}
	getch();
	closegraph();
	return 0;
}

void setup()
{
	border();
	food();
}

void border()
{
	bar(0,5,20,470);
	bar(610,5,630,470);
	bar(0,5,630,25);
	bar(0,450,630,470);
}

void snake()
{
	bar(x,y,x+15,y+15);
	if((x == (foodx+DIFF) && y == foody) || (x == foodx && y == (foody+DIFF)) ||
	   (x == (foodx-DIFF) && y == foody) || (x == foodx && y == (foody-DIFF)) ||
	   (x == (foodx+DIFF) && y == (foody+DIFF)) ||
	   (x == (foodx-DIFF) && y == (foody-DIFF)) ||
	   (x == foodx && y == foody) )
	{
		for(;;)
		{
			foodx= rand()%600;
			foody= rand()%400;
			if((foodx%15==0 && foody%15==0) &&
			  (foodx>15 && foodx<600) &&
			  (foody>15 && foody<400))
				break;
		}
		food();
		len++;
	}
	if(len>0)
		snake_body(len-1);
	input();
	control();
}

void snake_body(int i)
{
	switch(dir)
	{
		case UP:
			y_body[i]=y+15+(10*i);
			x_body[i]=x;
			break;
		case DOWN:
			y_body[i]=y-15-(10*i);
			x_body[i]=x;
			break;
		case RIGHT:
			x_body[i]=x-15-(10*i);
			y_body[i]=y;
			break;
		case LEFT:
			x_body[i]=x+15+(10*i);
			y_body[i]=y;
			break;
	}
	if(i>0)
	{
		bar(x_body[i], y_body[i], x_body[i]+15, y_body[i]+15);
		snake_body(i-1);
	}
}


void control()
{
   switch (dir)
   {
	case UP:
		y=y-MOVE;
		break;
	case DOWN:
		y=y+MOVE;
		break;
	case LEFT:
		x=x-MOVE;
		break;
	case RIGHT:
		x=x+MOVE;
		break;
   }
}

void input()
{

	if(kbhit())
	{
		switch (getch())
		{
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
		}
	}
}

void food()
{
	circle(foodx, foody, 10);
}