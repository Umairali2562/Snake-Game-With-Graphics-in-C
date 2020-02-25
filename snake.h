#include <windows.h>
#include <conio.h>
#include <stdio.h>

char ce=178;
int score;
bool gameOver; //bolean variable 
const int width = 20;  // Wall's Width
const int height = 10; // Wall's Height
int x, y; //head position
int fruiteX;
int FruiteY; //variables for our fruite possition ..
enum eDirection {stop=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int tailx[100];
int taily[100];
int ntail;
//Function for printing board
void setup(void);
//Function for taking input
void input(void);
//function for drawing snake
void draw(void);
//Function for processing our input ...
void logic(void);
//to set high scores (filing)
int setscore();

int snake()
{
	setup();
     //condition , run the while loop till we get 0 (as game over)...
	while (!gameOver)
	{
		//calling the draw function to print the border and snake..
		draw();
		
		input();
		
		logic();
		
		Sleep(300); //delay ...

	}

//conditions for high scores ..
if(gameOver==1){
setscore();

}

return 0;
}

void setup()
{
	gameOver = false;
	dir = stop;
	x = width/2; // this is the position of head , width divided by 2 so it will be in the middle ..
	y = height/2; // same goes for this , so the snake will be at the center of the map since the value is going to be of 20/2=10 likewise for x
	fruiteX = rand()%width; //so this will create a random Number would always be less than the width i.e Obivously 20..
	FruiteY = rand() %height; // same goes for this ...
	score = 0; 
}

//in this function we will draw the map ..
void draw()
{
	int j;
	//clear screen ..
	system("cls"); 
	
	//to display the top boarder of our map with for loop..
	for (int top = 0; top < width+2;top++)
		printf("%c",ce); //char for the top wall ..

	printf("\n");
	
	for (int i = 0; i < height; i++)
	{
		
		//to print the left side of the boarder :
		for (j = 0; j < width; j++)
		{
			if (j == 0)
				printf("%c",ce);

			
			//for snake to be in the center of the start
			if (i == y&&j == x)
				printf("0");
				
			else if (i == FruiteY && j == fruiteX){
				printf("F");
			}
				// to print the space ..
			else
			{
				bool print = false;
				for(int k=0; k < ntail; k++)
				{
					if(tailx[k] == j && taily[k] == i)
					{
						printf("o");
						print = true;
					}
				}
				if(!print)
					printf(" ");
			}
//to print the right side of the boarder..
			if (j == width-1)
				printf("%c",ce);
		}
		printf("\n");
	}
	
	//char for the bottom wall ..
	for (int bottom = 0; bottom < width+2; bottom++)
	{
		printf("%c",ce); 

}

	printf("\n");
	printf("Scores: %d\n",score);
    printf("Generating fruite in X-axies=%d\n",fruiteX);
    printf("Generating fruite in Y-axies=%d\n",FruiteY);
}

void input()
{
	if (kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;	
		}
	}
		if(x>width||x==0||y>height||y<0)
		gameOver=true;
		
			}
			

void logic(){

int prevx = tailx[0];
int prevy = taily[0];
int prev2x, prev2y;

for(int i=1; i<=ntail; i++)
{
prev2x = tailx[i];
prev2y = taily[i];
tailx[i] = prevx;
taily[i] = prevy;
prevx = prev2x;
prevy = prev2y;
tailx[0] = x;
taily[0] = y;
}


switch(dir){

	case LEFT:
	x--;
	
	break;
	case RIGHT:
	x++;

	break;
	case UP:
	y--;

	break;
	case DOWN:
	y++;

	break;	
	}
	printf("Snake Moving at X=%d",x);
	printf("\nSnake Moving at Y=%d",y);
	
	for(int i =0; i<ntail; i++)
{
if(tailx[i] == x && taily[i] == y)
{
printf("\n\n  GAME OVER  ");
Sleep(1000);	
gameOver = true;
}
}
	//snake eating frutie ..
	if(x== fruiteX && y== FruiteY)
	{
	    
		score+=10;
		fruiteX= rand() %width;
		FruiteY= rand() %height;
        ntail++;
	}
	if(x==width||x<0||y==width||y<0||y==10)
		gameOver=true;

}

setscore(){
FILE *fp;
char high;
printf("\nYour Scores are %d",score);
fp=fopen("Records.txt","w");

while(1){
high=putc(score,fp);
if(high==EOF){
break;
}

}

fclose(fp);

}
