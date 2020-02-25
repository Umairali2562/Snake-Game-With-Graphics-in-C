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
int temp1, temp2, temp3, temp4;

main()
{
	int grd=DETECT, grm;
	initgraph(&grd, &grm, "C:\\TURBOC3\\BGI\\");
	srand(time(NULL));
	while(!gameover)
	{
		delay(200);
		cleardevice();
		setup();
		snake();
		if(x<20 || y<30 || x>600 || y>435)
			gameover = 1;
	}
	delay(500);
	cleardevice();
	settextstyle(0,0,3);
	outtextxy(240,240,"GAME OVER");
	delay(700);
	cleardevice();
	outtextxy(180,240,"Press any key");
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
	int i;
	setfillstyle(7, GREEN);
	bar(x,y,x+15,y+15);
	rectangle(x,y,x+15,y+15);
	if((x == (foodx+DIFF) && y == foody) || (x == foodx && y == (foody+DIFF)) ||
	   (x == (foodx-DIFF) && y == foody) || (x == foodx && y == (foody-DIFF)) ||
	   (x == (foodx+DIFF) && y == (foody+DIFF)) ||
	   (x == (foodx-DIFF) && y == (foody-DIFF)) ||
	   (x == foodx && y == foody) ||
	   ((x+15) == (foodx+DIFF) && (y+15) == foody) || ((x+15) == foodx && (y+15) == (foody+DIFF)) ||
	   ((x+15) == (foodx-DIFF) && (y+15) == foody) || ((x+15) == foodx && (y+15) == (foody-DIFF)) ||
	   ((x+15) == (foodx+DIFF) && (y+15) == (foody+DIFF)) ||
	   ((x+15) == (foodx-DIFF) && (y+15) == (foody-DIFF)) ||
	   ((x+15) == foodx && (y+15) == foody))
	{
		for(i=0;;i++)
		{
			foodx= rand()%600;
			foody= rand()%400;
			if((foodx%15==0 && foody%15==0) &&
			  (foodx>15 && foodx<600) &&
			  (foody>15 && foody<400) &&
			  (foodx != x_body[i]) &&
			  (foodx != y_body[i]) &&
			  (foodx != x_body[i]+15) &&
			  (foodx != y_body[i]+15)
			  )
				break;
		}
		food();
		len = len + 2;
	}
	if(len>0)
		snake_body(len);
	input();
	control();
}

void snake_body(int i)
{
	int count;
	x_body[0] = x;
	y_body[0] = y;
	temp1 = x_body[i-1];
	temp2 = y_body[i-1];
	if((i-1) > 0)
	{
		count = i;
		x_body[i-1] = temp3;
		y_body[i-1] = temp4;
	}
	x_body[i] = temp1;
	y_body[i] = temp2;
	temp3 = x_body[i];
	temp4 = y_body[i];

	for(;count>0;count--)
		if(x == x_body[count] && y == y_body[count])
			gameover = 1;

	rectangle(x_body[i], y_body[i], x_body[i]+15, y_body[i]+15);
	if((i-1) > 0)
		snake_body(i-1);

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
	circle(foodx, foody, 6);
}
