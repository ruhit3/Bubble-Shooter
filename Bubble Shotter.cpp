#include <iostream>
#include <string>
#include "graphics.h"

#define WINX 1000
#define WINY 600

int bubble[26][11];

int end=0;
int grow=0;
int time=0;
int y_ind;
int ind_y;

int score=0;

#define ARROW_SIZE 7
#define BALLOON_SIZE 3

int col=3;  //initial moving bubble color
void draw_ball(int x, int y,int rad)
{
	setcolor(col);
	setfillstyle(SOLID_FILL,col);
	fillellipse(x,y,rad,rad);


}

void draw_vertix_ball(int x,int y,int rad, int color)
{
	setcolor(color);
	setfillstyle(SOLID_FILL,color);
	fillellipse(x,y,rad,rad);

}

void erase_ball(int x,int y,int rad)
{
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	fillellipse(x,y,rad,rad);


}


void move_ball(int x,int y, int rad)
{
	int xx=x,yy=y;

	int ind_x=xx/(2*rad);
	int ind_y;
	int i;
	int bol=0;
	for( i=1;i<=10;i++)
	{

		if(bubble[ind_x][i]==1 )
		{


			bol=1;
			ind_y=i+1;

			y_ind=i+1;        //for check in function

			printf("index y: %d\n",ind_y);

			if(i==10)
			{
				end=1;

			}

		}


	}
	if(bol==0)
	{
		ind_y=1;

		y_ind=1;
	}
	bubble[ind_x][ind_y]=1;
	char out[60];
	while(1)
	{
		draw_ball(x,y,rad);
		draw_ball(xx,yy,rad);

		if(ind_y*rad*2 == y )
			break;

		//delay(1);
		grow+=2;
		erase_ball(x,y,rad);
		y--;
		/*setcolor(col);
		sprintf(out,"Time: %d unit",time);
		outtextxy(WINX+20,150,out);*/

	}


}

void check_in(int ind_bx,int ind_by,int rad)
{

	printf(" col: %d %d\n",ind_bx,ind_by);
	if(getpixel(ind_bx,(ind_by-1)*rad*2)==col && getpixel(ind_bx,(ind_by-2)*rad*2)==col)  //for up
	{
		erase_ball(ind_bx,(ind_by)*rad*2,rad);
		delay(100);
		grow+=100;
		erase_ball(ind_bx,(ind_by-1)*rad*2,rad);
		delay(100);
		grow+=100;
		erase_ball(ind_bx,(ind_by-2)*rad*2,rad);
		delay(100);
		grow+=100;

		score+=3;

		bubble[ind_bx/(2*rad)][ind_by]=0;
		bubble[ind_bx/(2*rad)][ind_by-1]=0;
		bubble[ind_bx/(2*rad)][ind_by-2]=0;

	}

	int defi_x=ind_bx/(2*rad);

	//for all verticle position

	if(getpixel((defi_x+1)*rad*2,(ind_by)*rad*2)==col && getpixel((defi_x-1)*rad*2,(ind_by)*rad*2)==col || getpixel((defi_x+1)*rad*2,(ind_by)*rad*2)==col && getpixel((defi_x+2)*rad*2,(ind_by)*rad*2)==col || getpixel((defi_x-1)*rad*2,(ind_by)*rad*2)==col && getpixel((defi_x-2)*rad*2,(ind_by)*rad*2)==col)
	{

		//for left+middle+right
		if(getpixel((defi_x+1)*rad*2,(ind_by)*rad*2)==col && getpixel((defi_x-1)*rad*2,(ind_by)*rad*2)==col)
		{
			erase_ball((defi_x+1)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;
			erase_ball((defi_x)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;
			erase_ball((defi_x-1)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;

			score+=3;

			bubble[(ind_bx)/(2*rad) + 1][ind_by]=0;
			bubble[(ind_bx)/(2*rad)][ind_by]=0;
			bubble[(ind_bx)/(2*rad) - 1][ind_by]=0;

			if(getpixel((defi_x+2)*rad*2,(ind_by)*rad*2)==col)
			{
				erase_ball((defi_x+2)*rad*2 +rad,(ind_by)*rad*2,rad);
				delay(100);
				grow+=100;
				score++;
				bubble[(ind_bx)/(2*rad) + 2][ind_by]=0;
			}
			if(getpixel((defi_x-2)*rad*2,(ind_by)*rad*2)==col)
			{
				erase_ball((defi_x-2)*rad*2 +rad,(ind_by)*rad*2,rad);
				delay(100);
				grow+=100;
				score++;
				bubble[(ind_bx)/(2*rad) - 2][ind_by]=0;
			}

		}
		//for middle+right+rightmost
		else if(getpixel((defi_x+1)*rad*2,(ind_by)*rad*2)==col && getpixel((defi_x+2)*rad*2,(ind_by)*rad*2)==col)
		{
			erase_ball((defi_x)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;
			erase_ball((defi_x+1)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;
			erase_ball((defi_x+2)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;

			score+=3;

			bubble[(ind_bx)/(2*rad)][ind_by]=0;
			bubble[(ind_bx)/(2*rad) + 1][ind_by]=0;
			bubble[(ind_bx)/(2*rad) + 2][ind_by]=0;

			if(getpixel((defi_x+3)*rad*2,(ind_by)*rad*2)==col)
			{
				erase_ball((defi_x+3)*rad*2 +rad,(ind_by)*rad*2,rad);
				delay(100);
				grow+=100;
				score++;
				bubble[(ind_bx)/(2*rad) + 3][ind_by]=0;
			}
		}
		//for middle+left+leftmost
		else if(getpixel((defi_x-1)*rad*2,(ind_by)*rad*2)==col && getpixel((defi_x-2)*rad*2,(ind_by)*rad*2)==col)
		{
			erase_ball((defi_x)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;
			erase_ball((defi_x-1)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;
			erase_ball((defi_x-2)*rad*2 +rad,(ind_by)*rad*2,rad);
			delay(100);
			grow+=100;

			score+=3;
			bubble[(ind_bx)/(2*rad)][ind_by]=0;
			bubble[(ind_bx)/(2*rad) - 1][ind_by]=0;
			bubble[(ind_bx)/(2*rad) - 2][ind_by]=0;

			if(getpixel((defi_x-3)*rad*2,(ind_by)*rad*2)==col)
			{
				erase_ball((defi_x-3)*rad*2 +rad,(ind_by)*rad*2,rad);
				delay(100);
				score++;
				grow+=100;
				bubble[(ind_bx)/(2*rad) - 3][ind_by]=0;
			}

		}

	}

}

void initial_bubble(int rad)
{
	int i;

	int colo;     //initial still bubble color

	for(int j=1;j<=6;j++)
	{
		if(j%2==0)
		{
			i=1;
		}
		else
		{
			i=2;
		}
		for(;i<=23;i+=2)
		{

			colo=rand()%5 +1;
			draw_vertix_ball(i*rad*2 + rad, j*rad*2,rad,colo);
			bubble[i][j]=1;
		}
	}
}

void initial_game_window()
{

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,1300,WINY);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(WINX+2,0,WINX+4,WINY);
}

int main()
{
	initwindow(1300,WINY,"dance with bubble is now Shoot The Bubble v.26.32.00 :P");

	//goto statement for restart game
	restart:





	end=0;

	//initial_game_window();

	/*initwindow(1300,WINY,"dance with bubble :P");
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,1300,WINY);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(WINX+2,0,WINX+4,WINY);*/


	//int colo;

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,1300,WINY);

	//beginning warning
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(LIGHTMAGENTA);
	char sen[100];
	sprintf(sen,"Shoot The Bubble v.26.32.00 :p ");
	outtextxy(WINX/2-120,40,sen);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	setcolor(LIGHTCYAN);
	sprintf(sen,"___DISCLAIMER___ ");
	outtextxy(WINX/2+30,100,sen);
	sprintf(sen,"__You Have To Shoot at least 50 Bubbles to win this ULTIMATE bubble WAR within 50 units:p__");
	outtextxy(WINX/2-300,130,sen);
	sprintf(sen,"___Good Luck___ :) ");
	outtextxy(WINX/2+30,170,sen);
	sprintf(sen,"press Any Key to Continue");
	outtextxy(WINX/2-20,WINY/2+10,sen);
	(char)getch();

	initial_game_window();
	//timing
	time=0;
	int excact_time=50;
	int excact_score=50;

	for(int i=1;i<26;i++)
	{
		for(int j=1;j<11;j++)
		{
			bubble[i][j]=0;
		}
	}
	int i;
	int rad=20;  //define radious
	//j= Y axis, i=X axis
	/*for(int j=1;j<=3;j++)
	{
		if(j%2==0)
		{
			i=1;
		}
		else
		{
			i=2;
		}
		for(;i<=23;i+=2)
		{

			colo=rand()%5 +1;
			draw_vertix_ball(i*rad*2 + rad, j*rad*2,rad,colo);
			bubble[i][j]=1;
		}
	}*/
	initial_bubble(rad);



	int cx,cy;

	int x_fix=rad, y_fix=WINY-rad;
	cx=cy=rad;

	int cxx=4,cyy=3;

	int x=60,y=60;

	char s[100];
	score=0;


	//for score
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	//setcolor(YELLOW);
	char sc[100];
	//for time
	grow=0;

	for( ; ; )      //main loop (game ARC) :p.......................................................
	{
		grow++;
		if(grow>=500)
		{
			grow=0;
			time++;
		}
		if(time<=excact_time && score>=excact_score)
		{
			setcolor(MAGENTA);
			sprintf(sen,"OWO... YOU WIN THIS BATTLE __");
			outtextxy(WINX/2-20,WINY/2+10,sen);
			sprintf(sen,"^_^ CONGRATES ^_^");
			outtextxy(WINX/2,WINY/2+40,sen);
			sprintf(sen,"press q to quit or r to play the battle again :p ");
			outtextxy(WINX/2-200,WINY/2+80,sen);


			again1:
			char chch=(char)getch();

			if(chch=='q')
			{
				break;
			}
			else if(chch=='r')
			{
				goto restart;
			}
			else
			{
				goto again1;
			}

		}
		else if(time==(excact_time+1) && score<excact_score)
		{
			setcolor(MAGENTA);
			sprintf(sen,"Oh no ..Times Up.. You lose Yourself :( ");
			outtextxy(WINX/2-30,WINY/2+10,sen);
			//sprintf(sen,"^_^ CONGRATES ^_^");
			//outtextxy(WINX/2,WINY/2+40,sen);
			sprintf(sen,"press q to quit or r to play the battle again :p ");
			outtextxy(WINX/2-200,WINY/2+80,sen);

			again2:
			char chch=(char)getch();

			if(chch=='q')
			{
				break;
			}
			else if(chch=='r')
			{
				goto restart;
			}
			else
			{
				goto again2;
			}
		}


		draw_ball(x_fix,y_fix,rad);

		if(kbhit())
		{
			char c=(char)getch();
			if(c==KEY_UP)                                   // shoot bubble
			{
				move_ball(x_fix,y_fix,rad);

				delay(100);
				grow+=100;
				check_in(x_fix,y_ind,rad);  //check whether any bubble to shoot



				col=rand()%5 + 1;

				if(end==1)
				{
					settextstyle(BOLD_FONT, HORIZ_DIR, 1);
					setcolor(YELLOW);
					sprintf(s,"Oh nooo... :( you have been finished *_*    press q to quit ");
					outtextxy(WINX/2-60,WINY/2,s);
					sprintf(s,"    *_*   press r to play this Battle again  *_* ");
					outtextxy(WINX/2-30,WINY/2+30,s);
					settextstyle(COMPLEX_FONT, HORIZ_DIR, 12);
					sprintf(s,"   copyright// ___ Mehedi, iRuhit ___");
					outtextxy(WINX/2-20,WINY/2+60,s);
					again:
					char fc=(char)getch();
					if(fc=='q')
						break;
					else if(fc=='r')
					{

						//initial_game_window();
						//initial_bubble(rad);
						//score=0;
						goto restart;
					}
					else
					{
						goto again;
					}

				}


			}
			else if(c==KEY_LEFT)
			{
				erase_ball(x_fix,y_fix,rad);
				if(x_fix<=WINX-rad && x_fix>rad)
				{
					x_fix-=(rad*2);
				}


			}
			else if(c==KEY_RIGHT)
			{
				erase_ball(x_fix,y_fix,rad);
				if(x_fix<WINX-rad && x_fix>=rad)
				{
					x_fix+=(rad*2);
				}

			}
			else if(c=='q')
			{
				break;
			}

		}
		draw_ball(x_fix,y_fix,rad);
		//score print

		sprintf(sc,"Bubble Taken: %d",score);
		outtextxy(WINX+20,40,sc);
		sprintf(sc,"___press q to quit___",score);
		outtextxy(WINX+20,80,sc);
		sprintf(sc,"Time: %d unit",time);
		outtextxy(WINX+20,150,sc);
		sprintf(sc,"//copyright//");
		outtextxy(WINX+20,WINY-80,sc);

		sprintf(sc,"__Mehedi, Ruhit__");
		outtextxy(WINX+20,WINY-40,sc);
	}
	return 0;
}
