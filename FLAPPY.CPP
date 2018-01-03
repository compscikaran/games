#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>

void bird(int x,int y,int time);                 //Function to display bird
void moverec(int &x);                   //function to move rectangle barriers
void rec(int x,int y,int random);       //function to display rectangle
void movebird(int &y,int &g);                  //function to move bird
void killplayer(int bx,int by,int recx,int random,int &exit);   //Kill condition
void introflappy();                             //animation for introduction
void gameover(int score);                          //animation for gameover
void background();
void timebar(int start, int &t);
void scorebar(int score);
void main ()
{
clrscr();
int gm,gd=DETECT,midx,midy;
initgraph(&gd,&gm,"C:\\turboC3\\bgi");
midx = getmaxx()/2;
midy = getmaxy()/2;
start :

struct flappybird
{
int x;
int y;
}bi={midx-100,midy};

struct rectangles
{
int x;
int y;
};
//----------------------------------------------------------------------------
rectangles r1,r2,r3;
r1.x = getmaxx()-250;
r1.y = midy;
r2.x = getmaxx()-100;
r2.y = midy;
r3.x = getmaxx()-400;
r3.y=midy;
int ran1=0,ran2=0,ran3=0,score=0,a,ax,acg=1,time;
settextstyle(1,0,4);
//----------------------------------------------------------------------------
introflappy();
//---------------------------------------------------------------------------
cleardevice();
clock_t start;
start =clock();
randomize();
bird(bi.x,bi.y,start);
rec(r1.x,r1.y,ran1);
int ky=0;
outtextxy(100,100,"Press W to fly");
getch();

do
{
cleardevice();
a=0;
killplayer(bi.x,bi.y,r1.x,ran1,ky);
killplayer(bi.x,bi.y,r2.x,ran2,ky);
killplayer(bi.x,bi.y,r3.x,ran3,ky);
if(kbhit()!=0)
{
	a = toupper(getch());

}
rec(r1.x,r1.y,ran1);
rec(r2.x,r2.y,ran2);
rec(r3.x,r3.y,ran3);
bird(bi.x,bi.y,start);
background();
moverec(r1.x);
moverec(r2.x);
moverec(r3.x);
scorebar(score);
timebar(start,time);
if(bi.y < (getmaxy()-30))
{
movebird(bi.y,acg);
}
if(bi.y>=(getmaxy()-30))
{
ky=1;
}
delay(100);

if(r1.x<=20 && r2.x<=20)
{
r1.x = getmaxx()-150;
ran1 = random(200);
r2.x = getmaxx();
ran2 = random(200);
r3.x = getmaxx()-300;
ran3 = random(200);
}

if(r1.x==bi.x || r2.x==bi.x || r3.x==bi.x)
{
score++;
}

//-----------------------------------------------------------------------------
if(a=='W')
{
bi.y=bi.y-20;
acg=1;
}

if(a=='C')
{
cleardevice();
outtextxy(50,70,"Contols");
outtextxy(50,100,"Press W to Go Up");
outtextxy(50,130,"Press Esc to Quit");
outtextxy(50,160,"Press A to Restart");
ax = getch();
cleardevice();
	if(ax==27)
		{
		return;
		}
	if(ax=='A')
		{
		goto start;
		}

}
if(a==27)
{
return;
}


//----------------------------------------------------------------------------


}while(ky==0);
gameover(score);
//----------------------------------------------------------------------------
getch();

closegraph();
}

void bird(int x,int y,int time)
{
float t;
clock_t end;
end = clock();
t = (end - time);
float yy;
yy = 8*sin(t);
setcolor(BLUE);
circle(x,y,10);
setfillstyle(SOLID_FILL,BLUE);
floodfill(x,y,BLUE);
setcolor(RED);
line(x-10,y+4,x-10,y + yy + 6);
line(x,y+4,x-10,y + yy +6);
line(x-10,y+4,x,y+4);
setcolor(YELLOW);
line(x+10,y-2,x+15,y+2);
line(x+10,y+2,x+15,y+2);
line(x+10,y+6,x+15,y+2);
line(x+10,y-2,x+10,y+6);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(x+12,y+1,YELLOW);
setcolor(WHITE);
circle(x+5,y,1);
circle(x+5,y,2);

}
void rec(int x,int y,int random)
{
setcolor(10);
rectangle(x,0,x+20,175+random);
rectangle(x,getmaxy(),x+20,getmaxy()-175+random);
}


void background()
{
setcolor(10);
line(0,0,getmaxx(),0);
line(0,getmaxy(),getmaxx(),getmaxy());
}


void moverec(int &x)
{
x= x-10;
}

void movebird(int &y ,int &g)
{
y = y + g;
g=g+2;
}




void killplayer(int bx,int by,int recx,int random,int &exit)
{
if(bx >= recx && bx <= (recx+20) && by <= getmaxy() && by >= (getmaxy()-175+random))
{
exit=1;
}

if(bx >= recx && bx <= (recx+20) && by >= 0 && by <= (175+random))
{
exit=1;
}
}


void introflappy()
{
for(int i=1;i<=400;i++)
{
setcolor(YELLOW);
outtextxy((getmaxx()/2)-100,(getmaxy()/2)-200,"FLaPPy BiRdS");
setcolor(BLUE);
arc(300,250,-i+10,60-i,25);
arc(300,250,-i+10,60-i,26);
arc(300,250,-i+10,60-i,27);
arc(300,250,i+10,60+i,15);
arc(300,250,i+10,60+i,16);
arc(300,250,i+10,60+i,17);
delay(5);
}
setcolor(YELLOW);
outtextxy((getmaxx()/2)-180,(getmaxy()/2)-100,"Press Any Key To Begin");
settextstyle(1,0,3);
outtextxy(50,getmaxy()-30,"Based on Flappy BirdsTM, Copyright .gears 2013 ");
getch();
setcolor(WHITE);
}


void gameover(int score)
{
int x,y;
x = getmaxx()/2;
y = getmaxy()/2;
char s[10];
itoa(score,s,10);
cleardevice();
background();
rectangle(x-100,y-50,x+100,y+50);
settextstyle(28,0,4);
outtextxy(x-50,y-30,"GAME OVER");
outtextxy(x-70,y-10,"Score" );
outtextxy(x-50,y+20,s);
outtextxy(x+20,y-10,"Medal");
circle(x+30,y+20,15);

if(score>=20)
{
setfillstyle(SOLID_FILL,7);
floodfill(x+30,y+20,10);
setcolor(BLACK);
outtextxy(x+27,y+17,"S");
setcolor(10);
}


if(score>=50)
{
setfillstyle(SOLID_FILL,YELLOW);
floodfill(x+30,y+20,10);
setcolor(BLACK);
outtextxy(x+27,y+17,"G");

}


getch();
}


void scorebar(int score)
{
char s[100];
itoa(score,s,10);           //converting integer to character
outtextxy(470,20,"Score");
outtextxy(470,50,s);
}


void timebar(int start, int &t)
{

char s[20];
clock_t end;              //declaring time end variable
end=clock();              //calculating time
t = (end-start)/CLOCKS_PER_SEC;
itoa(t,s,10);
outtextxy(400,350,"Time Elapsed");
outtextxy(400,380,s);
outtextxy(450,380,"Seconds");
}
