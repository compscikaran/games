#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>

#include<stdio.h>
void intro();                         //funtion to give intro
void reset();                         //function to reset screen
void left(int &x,int &y,int &);       //function to move left
void right(int &x,int &y,int &);      //function to move right
void shoot(int &x,int &y);            //function to shoot bullet
void enemykill(int &x,int &ko);       //function to kill enemy
void displayp(int x,int y);           //function to redisplay player
void displaye1(int x,int y);          //function to redisplay enemy 1
void displaye2(int x,int y);          //function to redisplay enemy 2
void displaye3(int x,int y);          //funtion to redisplay enemy 3
void shield(int x,int y);             //fuction to shield from enemy fire
void lifebar(int life);	              //funtion to display life remaining
void scorebar(int score);             //function to display score
void levelcomp(int x,int y,int le);   // function for animation on level completion
void grenade (int &x,int &y ,int&z);  //function for using grenade
void explosion(int x,int y,int x2,int y2);          //function for animation for explosion
void weaponsbar(int z);               //function to display weapons available
void timebar(int start, int &t);      //function to display time elapsed
void displaymenu(int x, int y,int cq); //function to display menu
void displayrec(int x,int y);          //function to move menu rectangle
void bird(int x,int y,int time);                 //Function to display bird
void moverec(int &x);                   //function to move rectangle barriers
void rec(int x,int y,int random);       //function to display rectangle
void movebird(int &y,int &g);                  //function to move bird
void killplayer(int bx,int by,int recx,int random,int &exit);   //Kill condition
void introflappy();                             //animation for introduction
void gameover(int score);                          //animation for gameover
void background();
void headgear(int x1,int y1,int x2,int y2);
void sword(int x,int y,int pos);

void main ()
{
//----------------------------------------------------------------------------------

clrscr();
int midx,midy,dx,i,u=0,v=0,t=0,z=0,ai=0,zq,ranshoot,ranpos,def,ptr1,ptr2,ts,exit,q,j,level=2,gc;
char ch,dh;                         //initializing values and graphics
long int lc;
char cheat[20];
char name[20];
int gm,gd=DETECT;
initgraph(&gd,&gm,"C:\\turboC3\\bgi");
midx=getmaxx()/2;
midy=getmaxy()/2;
//-------------------------------------------------------------------------------

int l3=0,l1=0,l2=0,l4=0,l7=0;
lc=7;
reset();

intro();
exit = getch();
if(exit==27)
{
return;
}
reset();
randomize();

main :
struct player              //initiliazing structures
{
int x;
int y;
}p = {midx-100,midy};

struct bullet
{
int x;
int y;
}b;

struct enemy
{
int x;
int y;
};

struct swordfight
{
int x;
int y;
}s;

struct grenadefire
{
int x;
int y;
}g;

struct menu

{
int x;
int y;
}r;

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
int inc=0,ran1=0,ran2=0,ran3=0,score=0,a,ax,acg=1;;

enemy e1,e2,e3;      //initializing structure variables values
e1.y=midy;
b.x=0;
b.y= p.y+30;
g.x=0;
g.y=p.y+30;
s.x=0;
s.y=p.y+35;
e1.x = p.x + 170;
e2.x=p.x + 300;
e2.y=midy;
e3.x = p.x + 170;
e3.y=midy;
r.x = midx -200;
r.y= 150;

int ky=0;
int kh,lh;
int qc=1;
int kz;
int st=0;
//-------------------------------------------------------------------------------

while(ky==0)        //infinite while loop for selecting choice of mode
{
lh=0;
displayrec(r.x,r.y);
displaymenu(midx,midy,qc);
//-------------
if (kbhit()!=0)
{
lh = toupper(getch());
}

if(lh==87 && r.y > 150 )       //condition to move rectangle up
	{
	  cleardevice();
	  r.y-=50;
	  displayrec(r.x,r.y);
	  displaymenu(midx,midy,qc);
	}

if(lh==83 && r.y < 350)      //condition to move rectangle down
	 {
	   cleardevice();
	   r.y+=50;
	   displayrec(r.x,r.y);
	   displaymenu(midx,midy,qc);
	  }
if(lh==27)
{
return;
}
if(lh==13)
{
ky=1;
}
if(r.y==150)              //conditions to change color of option selected
{
qc=1;
}
if(r.y==200)
{
qc=2;
}
if(r.y==300)
{
qc=4;
}
if(r.y==250)
{
qc=3;
}
if(r.y==350)
{
qc=5;
}
}

//-------------------------------------------------------------------
if(r.y==150)               //conditions to apply changes
{
level=2;
}
if(r.y==200)
{
level=4;
}
if(r.y==250)
{
level=5;
}

if(r.y==300)
{
level=7;
}
if(r.y==350)
{
return;
}
reset();

//-------------------------------------------------------------------------------
if(level==1 ||level==4)
{
displayp(p.x,p.y);            //initializing player and background
outtextxy(midx-70,100,"Press any key to start");
gc=5;
dx=0;
}
int time=0;
clock_t start;       //time variable for start point
start=clock();
//-------------------------------------------------------------------------------
do               //Main loop containing all levels
{
while(level==1)       //infinite loop for level 1
{
ranshoot=random(2);
ranpos = random(100);
displaye2(e2.x,e2.y);
displayp(p.x,p.y);
lifebar(lc);
scorebar(l1);
timebar(start,time);
weaponsbar(gc);

//----------------
if(!kbhit())                 //taking user input
	{
	ch = getch();
	dh = toupper(ch);
	}

if(ranshoot==1)                  //condition for random motion of enemy
{
  ai=e2.x;
  for(i=0;i<=400;i++)
	{
	cleardevice();
	left(e2.x,e2.y,t);
	displayp(p.x,p.y);
	displaye2(e2.x,e2.y);
	if(kbhit()!=0)
	{
	def=toupper(getch());
		if(def==81)
		{
		shield(p.x,p.y);
		break;
		}

		if(def==69)
		{
			for(i=1;i<500;i++)      //loop to launch bullet
			{
			cleardevice();
			displayp(p.x,p.y);
			shoot(b.x,b.y);
			j= b.x + p.x + 20;
			displaye2(e2.x,e2.y);
			line(j+15,p.y+20,j+25,p.y+20);

				if(j==e2.x)       //condition to kill enemy
					{
					enemykill(e2.x,zq);
					cleardevice();
					displayp(p.x,p.y);
					delay(800);

					break;
					}
			delay(1);
			}

		b.x=0;
		e2.x=ai;
		delay(1);
		}
	}
	 if(e2.x==p.x)
		{
		lc--;
		}
		if(ts==1)
		{
		delay(15);
		}
		else
		{
		delay(3);
		}
	 }
	 e2.x=ai;
}
//----------------------------------------------------------------------------

if(dh==81)                              //condition to use shield
	{
	shield(p.x,p.y);
	}
if(dh==68)                           //condition to move right
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	right(p.x,p.y,v);
	displayp(p.x,p.y);
	displaye2(e2.x,e2.y);
	delay(10);
	}
	}
if(dh==65)                          //condition to move left
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	left(p.x,p.y,u);
	displayp(p.x,p.y);
	displaye2(e2.x,e2.y);
	delay(10);
	}
	}
if(dh==69)                        //condition to shoot enemy
	{
	ai=e2.x;
	for(i=1;i<500;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	shoot(b.x,b.y);
	q= b.x + p.x + 20;
	displaye2(e2.x,e2.y);
	line(q+15,p.y+20,q+25,p.y+20);
	if(e2.x==q)
		{
		enemykill(e2.x,l1);
			cleardevice();
			displayp(p.x,p.y);
			delay(800);
			break;

		 }
	delay(1);
	}
	b.x=0;
	e2.x =ai;
	delay(1);
	}
if(lc==0)
{
  break;
  }

if(dh==43)
{
cleardevice();
cout<<"Enter the cheat \t";
gets(cheat);
ptr1=strcmpi(cheat,"ilovefighting");
ptr2=strcmpi(cheat,"slowdown");
if(ptr1==0)
{
lc=lc+5;
}
if(ptr2==0)
{
ts=1;
}
cleardevice();
displayp(p.x,p.y);
displaye2(e2.x,e2.y);
}
if(dh==80)
{
cleardevice();
outtextxy(100,100,"Game Paused");
outtextxy(100,130,"Press M to return to  Main Menu");
outtextxy(100,190,"Press any key to Continue");
outtextxy(100,160,"Press Esc to quit");
kz = toupper(getch());
if(kz==77)
{
cleardevice();
goto main;
}
if(kz==27)
{
return;
}
}


if(dh==67)                //condition to display controls
{
	cleardevice();
	settextstyle(3,0,2);
	outtextxy(100,100," Controls ");
	outtextxy(100,130,"A - To go Left");
	outtextxy(100,160,"D - To go Right");
	outtextxy(100,190,"E - Shoot enemy with Handgun");
	outtextxy(100,220,"G - Use Sword at close distance");
	outtextxy(100,250,"Q - Use Shield to defend enemy fire");
	outtextxy(100,280,"F - To Quit");
	getch();
	reset();
	displayp(p.x,p.y);
	displaye2(e2.x,e2.y);
	}
	if(l1==10)
	{
	levelcomp(midx,midy,level);
	reset();
	level=2;
	break;
	}
}


//-------------------------------------------------------------------------------
e2.x=p.x + 170;
e2.y=midy;

while(level==2)                       //infinite loop for level 2
{
dh=0;
lifebar(lc);
scorebar(l2);
timebar(start,time);
weaponsbar(gc);
ranshoot=random(10);
ranpos = random(100);
displaye1(e1.x,e1.y);
displayp(p.x,p.y);
//----------------
if(kbhit()!=0)                           //taking input
	{
	dh = toupper(getch());

	}

if(ranshoot==1)                        //condition for enemy to randomly shoot
{

  for(i=0;i<=400;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	q=e1.x-20-i;
	line(q+15,e1.y+30,q+25,e1.y+30);

	if(kbhit()!=0)
	{
	def=toupper(getch());
		if(def==81)
		{
		shield(p.x,p.y);
		delay(70);
		break;
		}
	}
	 if(q <= p.x)
		{
		lc--;
		break;
		}
		if(ts==1)
		{
		delay(15);
		}
		else
		{
		delay(2);
		}
	}
	}



if(ranshoot==2)                   //condition for enemy to randomly move towards player
{
for(i=0;i<10;i++)
	{
		cleardevice();
		left(e1.x,e1.y,t);
		displayp(p.x,p.y);
		displaye1(e1.x,e1.y);
		delay(10);
			if(e1.x==p.x)
			{
			lc--;
			break;
			}
	}
}


//----------------------------------------------------------------------------

if(dh==81)                          //condition to use shield
	{
	shield(p.x,p.y);
	}
if(dh==68)                         //condition to move player right
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	right(p.x,p.y,v);
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	delay(10);
	}
	}
if(dh==65)                      //condition for to move player left
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	left(p.x,p.y,u);
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	delay(10);
	}
	}
if(dh==69)                          //condition to shoot enemy
	{
	for(i=1;i<500;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	shoot(b.x,b.y);
	q= b.x + p.x + 20;
	displaye1(e1.x,e1.y);
	line(q+15,b.y,q+25,b.y);
	line(q+15,b.y+1,q+25,b.y+1);
	line(q+15,b.y+2,q+25,b.y+2);
	line(q+15,b.y+3,q+25,b.y+3);
	if(e1.x <= q)
		{
		enemykill(e1.x,l2);
		 cleardevice();
		 displayp(p.x,p.y);
		 delay(800);
		 break;
		 }
	delay(1/5);
	}
	b.x=0;
	e1.x =  p.x +130+ranpos;
	delay(1);
	}
if(lc==0)
{
break;
}

if(dh==72)                            //condition to use grenade
{
if(gc>0)
{
for(i=1;i<500;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	grenade(g.x,g.y,z);
	q= p.x + g.x + 20;
	displaye1(e1.x,e1.y);
	circle(q,g.y,5);
	if(e1.x==q)
		{
		 explosion(e1.x,e1.y,p.x,p.y);
		 enemykill(e1.x,l2);
		 cleardevice();
		 displayp(p.x,p.y);
		 delay(600);
		 break;
		 }
	delay(1);
	}
	g.x=0;
	g.y=p.y + 30;
	e1.x =  p.x +130+ranpos;
	delay(1);
	gc--;
}

}


if(dh==43)
{
cleardevice();
cout<<"Enter the cheat \t";
gets(cheat);
ptr1=strcmpi(cheat,"ilovefighting");
ptr2=strcmpi(cheat,"slowdown");
if(ptr1==0)
{
lc=lc+5;
}
if(ptr2==0)
{
ts=1;
}
cleardevice();
displayp(p.x,p.y);
displaye1(e1.x,e1.y);
}

if(dh==71)                       //condition to use sword
{
    for(i=1;i<=60;i++)
    {
    cleardevice();
    q=s.x + p.x+ 110 + (i/2);
    displayp(p.x,p.y);
    displaye1(e1.x,e1.y);
    line(s.x+p.x+35,s.y,q,s.y-60+i);
	if(e1.x==q)
		{
		enemykill(e1.x,l2);

		}

	delay(2);
	}
	delay(100);
	cleardevice();
	delay(50);
	displayp(p.x,p.y);
	s.x=0;
	e1.x=p.x + 130 + ranpos;

}

if(dh==80)
{
cleardevice();
setcolor(WHITE);
outtextxy(100,100,"Game Paused");
outtextxy(100,130,"Press M to return to  Main Menu");
outtextxy(100,190,"Press any key to Continue");
outtextxy(100,160,"Press Esc to quit");
kz = toupper(getch());
if(kz==77)
{
cleardevice();
goto main;
}
if(kz==27)
{
return;
}
}


if(dh==67)                       //condition to display controls
{
	cleardevice();
	settextstyle(3,0,2);
	setcolor(BLUE);
	outtextxy(100,100," Controls ");
	setcolor(WHITE);
	outtextxy(100,130,"A - To go Left");
	outtextxy(100,160,"D - To go Right");
	outtextxy(100,190,"E - Shoot enemy with Handgun");
	outtextxy(100,220,"G - Use Sword at close distance");
	outtextxy(100,250,"Q - Use Shield to defend enemy fire");
	outtextxy(100,280,"H - For grenade fire");
	outtextxy(100,310,"P - To Pause Game");
	getch();
	reset();
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	}
	if(l2==10)                //condition to complete level
	{
	levelcomp(midx,midy,level);
	reset();
	level=3;
	break;
	}
	}
//----------------------------------------------------------------------------

e3.x = p.x + 250;
e3.y=midy;

while(level==3)                 //infinite loop for level 3
{
dh=0;
lifebar(lc);
scorebar(l3);
timebar(start,time);
weaponsbar(gc);
ranshoot=random(3);
ranpos = random(100);
displaye3(e3.x,e3.y);
displayp(p.x,p.y);
//----------------
if(!kbhit())                  //taking user input

	{
	dh = toupper(getch());
	}

if(ranshoot==1)            //condition to make enemy shoot randomly
{

  for(i=0;i<=400;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	displaye3(e3.x,e3.y);
	q=e3.x-50-i;
	outtextxy(q,e3.y-10,"<=");

	if(kbhit()!=0)
	{
	def=toupper(getch());
		if(def==81)
		{
		shield(p.x,p.y);
		delay(70);
		break;
		}
		}
	if(q <= p.x)
		{
		lc--;
		}
		if(ts==1)
		{
		delay(15);
		}
		else
		{
		delay(1/5);

	}
	}

}

if(ranshoot==2)             //condition to move enemy randomely
{
for(i=0;i<10;i++)
	{
		cleardevice();
		left(e3.x,e3.y,t);
		displayp(p.x,p.y);
		displaye3(e3.x,e3.y);
		delay(10);
			if(e3.x==p.x)
			{
			lc=0;
			break;
			}
	}
}


//----------------------------------------------------------------------------

if(dh==81)                     //  condition to use shield
	{
	shield(p.x,p.y);
	}
if(dh==68)                    //condition to move right
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	right(p.x,p.y,v);
	displayp(p.x,p.y);
	displaye3(e3.x,e3.y);
	delay(10);
	}
	}
if(dh==65)                    //condition to move left
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	left(p.x,p.y,u);
	displayp(p.x,p.y);
	displaye3(e3.x,e3.y);
	delay(10);
	}
	}
if(dh==69)                     //condition to shoot enemy
	{
	for(i=1;i<500;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	shoot(b.x,b.y);
	q= b.x + p.x + 20;
	displaye3(e3.x,e3.y);
	line(q+15,b.y,q+25,b.y);
	if(e3.x <= q)
		{

		 ++l3;
		 delay(10);
		 break;
		 }
	delay(1);
	}
	b.x=0;

	delay(1);
	}
if(lc==0)
{
  break;
  }

if(dh==43)
{
cleardevice();
cout<<"Enter the cheat \t";
gets(cheat);
ptr1=strcmpi(cheat,"ilovefighting");
ptr2=strcmpi(cheat,"slowdown");
if(ptr1==0)
{
lc=lc+5;
}
if(ptr2==0)
{
ts=1;
}
cleardevice();
displayp(p.x,p.y);
displaye3(e3.x,e3.y);
}

if(dh==71)                    //condition to use sword
{
    for(i=1;i<=60;i++)
    {
    cleardevice();
    q=s.x + p.x+ 110 + (i/2);
    displayp(p.x,p.y);
    displaye3(e3.x,e3.y);
    line(s.x+p.x+35,s.y,q,s.y-60+i);
	if(e3.x==q)
		{
		l3++;

		break;

		}

	delay(2);
	}
	delay(100);
	cleardevice();
	delay(50);
	displayp(p.x,p.y);
	s.x=0;
	e3.x=p.x + 170 + ranpos;

}
if(dh==72)             //condition to use grenade
{
if(gc>0)
{
for(i=1;i<500;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	grenade(g.x,g.y,z);
	q= p.x + g.x + 20;
	displaye3(e3.x,e3.y);
	circle(q,g.y,5);
	if(e3.x==q)
		{
		 explosion(e3.x,e3.y,p.x,p.y);
		 enemykill(e3.x,l3);
		 cleardevice();
		 displayp(p.x,p.y);
		 delay(600);
		 break;
		 }
	delay(1);
	}
	g.x=0;
	g.y=p.y + 30;
	e3.x =  p.x +130+ranpos;
	delay(1);
    gc--;
    }

}

if(dh==80)
{
setcolor(WHITE);
cleardevice();
outtextxy(100,100,"Game Paused");
outtextxy(100,130,"Press M to return to  Main Menu");
outtextxy(100,190,"Press any key to Continue");
outtextxy(100,160,"Press Esc to quit");
kz = toupper(getch());
if(kz==77)
{
cleardevice();
goto main;
}
if(kz==27)
{
return;
}
}


if(dh==67)                     //condition to display controls
{
	cleardevice();
	settextstyle(3,0,2);
	outtextxy(100,100," Controls ");
	outtextxy(100,130,"A - To go Left");
	outtextxy(100,160,"D - To go Right");
	outtextxy(100,190,"E - Shoot enemy with Handgun");
	outtextxy(100,220,"G - Use Sword at close distance");
	outtextxy(100,250,"Q - Use Shield to defend enemy fire");
	outtextxy(100,280,"P - To Pause Game");
	getch();
	reset();
	displayp(p.x,p.y);
	displaye3(e3.x,e3.y);
	}
	if(l3==7)               //condition to complete all levels
	{
	enemykill(e3.x,0);
	cleardevice();
	displayp(p.x,p.y);
	displaye3(e3.x,e3.y);
	outtextxy(midx-90,100,"You Have completed All Levels");
	getch();
	levelcomp(midx,midy,level);
	reset();
	level=8;
	break;
	}
	}

while(level==4)                //infinite loop for survival mode
{
dh=0;
lifebar(lc);
scorebar(l4);
timebar(start,time);
weaponsbar(gc);
ranshoot=random(10);
ranpos = random(100);
displaye1(e1.x,e1.y);
displayp(p.x,p.y);
//----------------
if(kbhit()!=0)             //taking user input
	{
	dh = toupper(getch());
	}

if(ranshoot==1)           //condition for making enemy shoot randomely
{

  for(i=0;i<=100;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	q=e1.x-20-(i*10);
	line(q+15,e1.y+30,q+25,e1.y+30);

	if(kbhit()!=0)              //condition to shield from enemy fire
	{
	def=toupper(getch());
		if(def==81)
		{
		shield(p.x,p.y);
		delay(70);
		break;
		}
		if(def==69)
		{
			for(i=1;i<100;i++)
			{
			cleardevice();
			displayp(p.x,p.y);
			shoot(b.x,b.y);
			j= b.x + p.x + 20;
			displaye1(e1.x,e1.y);
			line(j+15,b.y,j+25,b.y);

				if(j >= q)
					{
					break;
					}
			delay(1);
			}
		b.x=0;
		delay(1);
		}
	break;
	}
	 if(q <= p.x)
		{
		lc--;
		break;
		}
		if(ts==1)
		{
		delay(15);
		}
		else
		{
		delay(2);

	}
	}

}

if(ranshoot==2)          //condition to move enemy randomely towards player
{
for(i=0;i<10;i++)
	{
		cleardevice();
		left(e1.x,e1.y,t);
		displayp(p.x,p.y);
		displaye1(e1.x,e1.y);
		delay(10);
			if(e1.x==p.x)
			{
			lc--;
			break;
			}
	}
}


//----------------------------------------------------------------------------

if(dh==81)                // condition to use shield
	{
	shield(p.x,p.y);
	}
if(dh==68)                  //condition to move right
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	right(p.x,p.y,v);
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	delay(10);
	}
	}
if(dh==65)                 //condition to move left
	{
	for(i=1;i<=10;i++)
	{
	cleardevice();
	left(p.x,p.y,u);
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	delay(10);
	}
	}
if(dh==69)                     //condition to shoot enemy
	{
	for(i=1;i<100;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	shoot(b.x,b.y);
	q= b.x + p.x + 20;
	displaye1(e1.x,e1.y);
	line(q+15,b.y,q+25,b.y);
	if(e1.x <= q)
		{
		enemykill(e1.x,l4);
		 cleardevice();
		 displayp(p.x,p.y);
		 delay(800);
		 break;
		 }
	delay(1);
	}
	b.x=0;
	e1.x =  p.x +130+ranpos;
	delay(1);
	}
if(lc==0)                  //condition for game over
{
level=8;
}

if(dh==72)                 //condition to use grenade
{
if(gc>0)
{
for(i=1;i<100;i++)
	{
	cleardevice();
	displayp(p.x,p.y);
	grenade(g.x,g.y,z);
	q= p.x + g.x + 20;
	displaye1(e1.x,e1.y);
	circle(q,g.y,5);
	if(e1.x <= q)
		{
		 explosion(e1.x,e1.y,p.x,p.y);
		 enemykill(e1.x,l4);
		 cleardevice();
		 displayp(p.x,p.y);
		 delay(600);
		 break;
		 }
	delay(1);
	}
	g.x=0;
	g.y=p.y + 30;
	e1.x =  p.x +130+ranpos;
	delay(1);
	 gc--;
	}

}


if(dh==43)
{
cleardevice();
cout<<"Enter the cheat \t";
gets(cheat);
ptr1=strcmpi(cheat,"ilovefighting");
ptr2=strcmpi(cheat,"slowdown");
if(ptr1==0)
{
lc=lc+5;
}
if(ptr2==0)
{
ts=1;
}
cleardevice();
displayp(p.x,p.y);
displaye1(e1.x,e1.y);
}

if(dh==71)                  //condition to use sword
{
    for(i=1;i<=60;i++)
    {
    cleardevice();
    q=s.x + p.x+ 110 + (i/2);
    displayp(p.x,p.y);
    displaye1(e1.x,e1.y);
    line(s.x+p.x+35,s.y,q,s.y-60+i);
	if(e1.x==q)
		{
		enemykill(e1.x,l4);
		}

	delay(2);
	}
	cleardevice();
	delay(70);
	displayp(p.x,p.y);
	s.x=0;
	e1.x=p.x + 130 + ranpos;

}

if(dh==80)
{
cleardevice();
setcolor(WHITE);
outtextxy(100,100,"Game Paused");
outtextxy(100,130,"Press M to return to  Main Menu");
outtextxy(100,190,"Press any key to Continue");
outtextxy(100,160,"Press Esc to quit");
kz = toupper(getch());
if(kz==77)
{
cleardevice();
goto main;
}
if(kz==27)
{
return;
}
}

if(dh==67)             //condition to display controls
{
	cleardevice();
	settextstyle(3,0,2);
	outtextxy(100,100," Controls ");
	outtextxy(100,130,"A - To go Left");
	outtextxy(100,160,"D - To go Right");
	outtextxy(100,190,"E - Shoot enemy with Handgun");
	outtextxy(100,220,"G - Use Sword at close distance");
	outtextxy(100,250,"Q - Use Shield to defend enemy fire");
	outtextxy(100,280,"H - For grenade fire");
	outtextxy(100,300,"F - To Quit");
	getch();
	reset();
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	}
	}

while(level==5)
{
if(inc==0)
{
introflappy();
cleardevice();
bird(bi.x,bi.y,start);
rec(r1.x,r1.y,ran1);
int ky=0;
clock_t start;
start=clock();
outtextxy(100,100,"Press W to fly");
getch();
}
cleardevice();
a=0;
killplayer(bi.x,bi.y,r1.x,ran1,level);
killplayer(bi.x,bi.y,r2.x,ran2,level);
killplayer(bi.x,bi.y,r3.x,ran3,level);

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
if(bi.y < (getmaxy()-10))
{
movebird(bi.y,acg);
}
timebar(start,time);
scorebar(score);
i++;
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

if(level==6)
{
cleardevice();
gameover(score);
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
		level=8;;
		}

}
if(a==27)
{
return;
}
inc++;
}

while(level==7)
{
int qw=0;
s.x = p.x;
s.y = p.y;
dh=0;
ranshoot = random(15);
ranpos = random(100);
displaye1(e1.x,e1.y);
displayp(p.x,p.y);
lifebar(lc);
scorebar(l7);
timebar(start,time);
sword(p.x,p.y,st);
//----------------
if(kbhit()!=0)                 //taking user input
	{
	dh = toupper(getch());
	}

if(ranshoot==1)
{
	for(i=0;i<=10;i++)
	{
	setcolor(WHITE);
	cleardevice();
	displayp(p.x,p.y);
	sword(s.x,s.y,st);
	headgear(p.x,p.y,e1.x,e1.y);
	displaye1(e1.x,e1.y);
	q = e1.x - 60 - (i*5);
	line(e1.x-40,e1.y+35,q,e1.y+35);
	if(kbhit()!=0)
	{
	     qw = toupper(getch());
	}
	if(qw==' ')
	{
	st=2;
	}
	if(q <= (s.x + 50))
	{
	delay(1000);
	break;
	}
	if(q <= p.x)
	{
	lc--;
	}
	delay(2);
}
}
if(ranshoot==2)                  //condition for random motion of enemy
{
  if(e1.x >= (p.x+120))
  {
  for(i=0;i<=10;i++)
	{
	setcolor(WHITE);
	sword(s.x,s.y,st);
	cleardevice();
	left(e1.x,e1.y,t);
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	headgear(p.x,p.y,e1.x,e1.y);
	delay(10);
	}
	}
}
//----------------------------------------------------------------------------

if(dh==81)                              //condition to use shield
	{
	st=0;
	setcolor(WHITE);
	cleardevice();
	displayp(p.x,p.y);
	sword(s.x,s.y,st);
	headgear(p.x,p.y,e1.x,e1.y);
	displaye1(e1.x,e1.y);
	line(e1.x-40,e1.y+35,e1.x-120,e1.y+35);
	}
if(dh==68)                           //condition to move right
	{
	for(i=1;i<=10;i++)
	{
	setcolor(WHITE);
	sword(s.x,s.y,st);
	cleardevice();
	right(p.x,p.y,v);
	headgear(p.x,p.y,e1.x,e1.y);
	displayp(p.x,p.y);
	displaye1(e1.x,e1.y);
	line(e1.x-40,e1.y+35,e1.x-120,e1.y+35);
	delay(10);
	}
	}
if(dh==65)                          //condition to move left
	{
	for(i=1;i<=10;i++)
	{
	setcolor(WHITE);
	sword(s.x,s.y,st);
	cleardevice();
	left(p.x,p.y,u);
	displayp(p.x,p.y);
	headgear(p.x,p.y,e1.x,e1.y);
	displaye1(e1.x,e1.y);
	line(e1.x-40,e1.y+35,e1.x-120,e1.y+35);
	}
	}
if(dh==69)                        //condition to shoot enemy
	{
	for(i=1;i<=10;i++)
	{
	setcolor(WHITE);
	cleardevice();
	q = p.x+(i*5)+50;
	line(p.x+35,p.y+35,q,p.y+35);
	displayp(p.x,p.y);
	headgear(p.x,p.y,e1.x,e1.y);
	displaye1(e1.x,e1.y);
	line(e1.x-40,e1.y+35,e1.x-120,e1.y+35);
	}
	}
if(q >= e1.x)
{
cleardevice();
enemykill(e1.x,l7);
displaye1(e1.x,e1.y);
displayp(p.x,p.y);
headgear(p.x,p.y,e1.x,e1.y);
delay(600);
cleardevice();
e1.x = p.x+170;
}
if(lc==0)
{
  break;
  }

if(dh==80)
{
cleardevice();
outtextxy(100,100,"Game Paused");
outtextxy(100,130,"Press M to return to  Main Menu");
outtextxy(100,190,"Press any key to Continue");
outtextxy(100,160,"Press Esc to quit");
kz = toupper(getch());
if(kz==77)
{
cleardevice();
goto main;
}
if(kz==27)
{
return;
}
}


if(dh==67)                //condition to display controls
{
	cleardevice();
	settextstyle(3,0,2);
	outtextxy(100,100," Controls ");
	outtextxy(100,130,"A - To go Left");
	outtextxy(100,160,"D - To go Right");
	outtextxy(100,190,"E - Shoot enemy with Handgun");
	outtextxy(100,220,"G - Use Sword at close distance");
	outtextxy(100,250,"Q - Use Shield to defend enemy fire");
	outtextxy(100,280,"F - To Quit");
	getch();
	reset();
	displayp(p.x,p.y);
	displaye2(e2.x,e2.y);
	}
	if(l1==10)
	{
	levelcomp(midx,midy,level);
	reset();
	level=8;
	break;
	}
}

}while(dx==1);       //end of main loop

//-------------------------------------------------------------------------------

cout<<endl<<u<<v<<endl<<"life remaining  "<<lc;
cout<<endl<<"score is  "<<((l1+l2+l3+l4)*1000); //displaying score
getch();

//--------------------------------------------------------------------------------

goto main;                  //loop condition to return to main menu
closegraph();
}

//--------------------------------------------------------------------------------

void left(int &x, int &y,int &z)
{
--x;                          //reducing x co-ordinate
++z;
}

void right(int &x,int &y,int &z)
{
++x;                             //increasing x co-ordinate
++z;
}



void shoot(int &x,int &y)
{
x = x+10;
}


void enemykill(int &x,int &ko)
{                               //killing enemy by displaying it at far away place
++ko;
x=1000;
}




void scorebar(int score)
{
char s[100];
itoa(score,s,10);           //converting integer to character
outtextxy(400,20,"Score");
outtextxy(400,50,s);
}



void shield(int x,int y)
{
setcolor(WHITE);
rectangle(x+50,y-30,x+40,y+50);
}


void grenade(int &x,int &y,int &z)
{
x = x+5;
--z;
}


void displayp(int x,int y)
{
setcolor(WHITE);
circle(x,y,20);
setfillstyle(SOLID_FILL,WHITE);
floodfill(x,y,WHITE);
setcolor(RED);
rectangle(x-10,y+49,x+10,y+21);
setfillstyle(SOLID_FILL,RED);
floodfill(x,y+24,RED);
rectangle(x+11,y+30,x+36,y+40);
setfillstyle(SOLID_FILL,RED);
floodfill(x+25,y+37,RED);
setcolor(10);
rectangle(0,y+50,700,y+55);
setfillstyle(SOLID_FILL,10);
floodfill(300,y+52,RED);
setcolor(BLACK);
circle(x+7,y,1);
circle(x+7,y,2);
circle(x+7,y,3);
circle(x+7,y,4);
line(x+11,y+30,x+11,y+40);
}




void displaye1(int x,int y)
{
setcolor(WHITE);
circle(x,y,20);
setfillstyle(SOLID_FILL,WHITE);
floodfill(x,y,WHITE);
setcolor(BLUE);
rectangle(x-10,y+49,x+10,y+21);
setfillstyle(SOLID_FILL,BLUE);
floodfill(x,y+24,BLUE);
setcolor(BLUE);
rectangle(x-11,y+30,x-36,y+40);
floodfill(x-25,y+35,BLUE);
setcolor(BLACK);
circle(x-7,y,1);
circle(x-7,y,2);
circle(x-7,y,3);
circle(x-7,y,4);
line(x-11,y+30,x-11,y+40);
setcolor(WHITE);
}



void displaye2(int x,int y)
{
setcolor(WHITE);
circle(x,y+10,15);
setfillstyle(SOLID_FILL,WHITE);
floodfill(x,y+10,WHITE);
setcolor(BLUE);
rectangle(x-10,y+26,x+10,y+49);
setfillstyle(SOLID_FILL,BLUE);
floodfill(x,y+30,BLUE);
setcolor(7);
rectangle(x-5,y+35,x+1,y+45);
setfillstyle(SOLID_FILL,7);
floodfill(x-2,y+40,7);
setcolor(BLACK);
circle(x-5,y+10,1);
circle(x-5,y+10,2);
circle(x-5,y+10,3);
rectangle(x-5,y+35,x+2,y+45);
setcolor(WHITE);
}


void displaye3(int x,int y)
{
setcolor(WHITE);
circle(x,y-30,20);
setfillstyle(SOLID_FILL,WHITE);
floodfill(x,y-20,WHITE);
setcolor(BLUE);
rectangle(x-20,y-9,x+20,y+49);
setfillstyle(SOLID_FILL,BLUE);
floodfill(x,y+30,BLUE);
rectangle(x-21,y+10,x-45,y+25);
floodfill(x-27,y+20,BLUE);
setcolor(7);
rectangle(x-21,y-1,x-55,y+9);
setfillstyle(SOLID_FILL,7);
floodfill(x-30,y+4,7);
setcolor(BLACK);
circle(x-7,y-30,1);
circle(x-7,y-30,2);
circle(x-7,y-30,3);
circle(x-7,y-30,4);
line(x-21,y+10,x-21,y+25);
setcolor(WHITE);
}



void reset()
{
settextstyle(1,0,3);
cleardevice();
}



void lifebar(int life)
{
setcolor(10);
outtextxy(50,20,"Life");
setcolor(14);
rectangle(50,50,70+(life*30),60);
setfillstyle(SLASH_FILL,14);
floodfill(65,55,14);
}





void levelcomp(int x,int y,int le)
{
cleardevice();
int i;
char level[20];
itoa(le,level,10);          //converting integers to character
for(i=0;i<=300;i++)
{
cleardevice();
setcolor(i/10);
arc(x,y,-i+10,60-i,150);
arc(x,y,-i+10,60-i,151);
arc(x,y,-i+10,60-i,152);
arc(x,y,-i+10,60-i,153);
arc(x,y,-i+10,60-i,154);
arc(x,y,i,60+i,170);
arc(x,y,i,60+i,171);
arc(x,y,i,60+i,172);
arc(x,y,i,60+i,173);
arc(x,y,i,60+i,174);
circle(x,y,205);
circle(x,y,206);
circle(x,y,207);
circle(x,y,208);
circle(x,y,209);
settextstyle(1,0,2);
outtextxy(x-100,y-70,"Congratulations!!");
outtextxy(x-100,y-50,"You have completed");
outtextxy(x-50,y-10,"level  ");
outtextxy(x+40,y-10,level);
delay(10);
}
outtextxy(x-150,y+20,"Press Enter to Proceed");
outtextxy(x-100,y+50,"to Next Level");
getch();
}



void intro()
{
cleardevice();
int we,end;
for(we=0;we<=100;we++)
{
circle(we,we,we);
circle(630-we,we,we);
settextstyle(3,0,8);
outtextxy(300,300," FIGHT++");
setcolor(we/10);
delay(50);
}
cleardevice();
setcolor(9);
for(we=0;we<=400;we++)
{
outtextxy(200,100,"Loading");
arc(300,250,-we+10,60-we,25);
arc(300,250,-we+10,60-we,26);
arc(300,250,-we+10,60-we,27);
arc(300,250,we+10,60+we,15);
arc(300,250,we+10,60+we,16);
arc(300,250,we+10,60+we,17);

delay(5);

}
setcolor(10);
cleardevice();
settextstyle(1,0,1);
outtextxy(200,100,"FIGHT++");
outtextxy(200,140,"Controls");
outtextxy(50,180,"Press C- for controls anytime during the game");
outtextxy(200,220,"Enter to continue");
outtextxy(200,260,"Press Esc to Exit");
}



void explosion(int x,int y,int x2,int y2)
{
int i;
for(i=0;i<=1000;i++)
{

cleardevice();

setcolor(RED);
line(x+i,y,x+5+i,y);
line(x-i,y,x-5-i,y);
line(x-i,y-i,x-5-i,y-5-i);
line(x+i,y+i,x+5+i,y+5+i);
line(x+i,y-i,x+5+i,y-5-i);
line(x-i,y+i,x-5-i,y+5+i);
line(x+i/2,y,x+5+i/2,y);
line(x-i/2,y,x-5-i/2,y);
line(x-i/2,y-i/2,x-5-i/2,y-5-i/2);
line(x+i/2,y+i/2,x+5+i/2,y+5+i/2);
line(x+i/2,y-i/2,x+5+i/2,y-5-i/2);
line(x-i/2,y+i/2,x-5-i/2,y+5+i/2);
line(x-i/3,y-i/3,x-5-i/3,y-5-i/3);
line(x+i/3,y+i/3,x+5+i/3,y+5+i/3);
line(x+i/3,y-i/3,x+5+i/3,y-5-i/3);
line(x-i/3,y+i/3,x-5-i/3,y+5+i/3);
line(x-i/4,y-i/4,x-5-i/4,y-5-i/4);
line(x+i/4,y+i/4,x+5+i/4,y+5+i/4);
line(x+i/4,y-i/4,x+5+i/4,y-5-i/4);
line(x-i/4,y+i/4,x-5-i/4,y+5+i/4);
delay(1/5);
}
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

void weaponsbar(int z)
{
char weapon[20];
itoa(z,weapon,10);      //converting integers to character
settextstyle(1,0,2);
outtextxy(30,350,"Weapons");
outtextxy(30,380,"Sword");
outtextxy(30,400,"Handgun--- Infinite");
outtextxy(30,420,"Grenades---");
outtextxy(160,420,weapon);
settextstyle(1,0,3);
}

void displaymenu(int x,int y ,int cq)
{
setcolor(4);
rectangle(0,0,620,500);
setfillstyle(WIDE_DOT_FILL,4);
floodfill(20,20,4);
//--------------
settextstyle(10,0,3);
outtextxy(x-80,50,"Main Menu");
line(0,100,620,100);
line(0,101,620,101);
line(0,102,620,102);
line(0,103,620,103);
settextstyle(1,0,3);
setcolor(10);
if(cq==1)
{
setcolor(3);
}
outtextxy(x-70,160,"Story Mode (RPG)");
setcolor(10);
if(cq==2)
{
setcolor(3);
}
outtextxy(x-70,210,"Survival Mode");
setcolor(10);
if(cq==3)
{
setcolor(3);
}
outtextxy(x-70,260,"Flappy Birds");
setcolor(10);
if(cq==4)
{
setcolor(3);
}
outtextxy(x-70,310,"Fencing");
setcolor(10);
if(cq==5)
{
setcolor(3);
}
outtextxy(x-60,350,"Quit");
setcolor(10);
settextstyle(1,0,1);
outtextxy(50,450,"Copyright Karan Gupta & Yasheel Vyas Version 0.1.5");
}



void displayrec(int x,int y)
{
rectangle(x,y,x+400,y+50);
line(x+5,y+55,x+405,y+55);
line(x+405,y+5,x+405,y+55);
line(x,y+50,x+5,y+55);
line(x+400,y+50,x+405,y+55);
line(x+400,y,x+405,y+5);
}




void headgear(int x1,int y1,int x2,int y2)
{
setcolor(BLACK);
rectangle(x1+20,y1+10,x1-20,y1+15);
setcolor(WHITE);
rectangle(x1+20,y1-25,x1+25,y1+25);
setcolor(BLACK);
rectangle(x2-20,y2+10,x2+20,y2+15);
setcolor(WHITE);
rectangle(x2-20,y2-25,x2-25,y2+25);

}


void sword(int x,int y,int pos)
{
setcolor(WHITE);
if(pos==0)
{
line(x+35,y+35,x+35,y-50);
}
if(pos==1)
{
line(x+35,y+35,x+120,y+35);
}
if(pos==2)
{
line(x+35,y+35,x+120,y+50);
}
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
exit=6;
}

if(bx >= recx && bx <= (recx+20) && by >= 0 && by <= (175+random))
{
exit=6;
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

if(score>=10)
{
setfillstyle(SOLID_FILL,7);
floodfill(x+30,y+20,10);
setcolor(BLACK);
outtextxy(x+27,y+17,"S");
setcolor(10);
}


if(score>=20)
{
setfillstyle(SOLID_FILL,YELLOW);
floodfill(x+30,y+20,10);
setcolor(BLACK);
outtextxy(x+27,y+17,"G");
}
getch();
}


