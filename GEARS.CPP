#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void introgears();
void reference();
void guide();
void gear1(double start,int x,int y);
void gear2(double start,int x,int y);
void checkmotion1(int xco[],int yco[],int dir[],int &z);
void checkmotion2(int xco[],int yco[],int dir[],int &z);
void gameover(int xco[],int yco[],int dir[],int gc,int &k);

void main ()
{

clrscr();
int gm,gd=DETECT;
initgraph(&gd,&gm,"C:\\turboC3\\bgi");
double x,y,x1,y1;
clock_t start;
start = clock();
introgears();
int dx=1,dh,ux[200],uy[200],i,z=1,gec=10,ged[200];
for(i=0;i<200;i++)
{
ux[i]=0;
uy[i]=0;
}
ux[0]=100;
uy[0]=300;
ux[11]=300;
uy[11]=100;
ged[0]=1;
ged[11]=1;
//--------------------------------------------------------------------------
outtextxy(100,100,"Press A to Put Gear");
outtextxy(100,200,"Press Any key to continue");
gear2(start,ux[0],uy[0]);
gear1(start,ux[11],uy[11]);
reference();
guide();
getch();
do
{
if(dx==2)
{
return;
}
dh=0;
if(kbhit()!=0)
	{
	dh = toupper(getch());
	}


cleardevice();
gear2(start,ux[0],uy[0]);
gear2(start,ux[11],uy[11]);
reference();
if(dh==65 && gec>=0)
{
	cleardevice();
	clrscr();
	cout<<"Gear Input";
	cout<<"Enter position of Gear";
	cout<<" \n \n X coordinate : ";
	cin>>ux[z];
	cout<<"\n \n Y coordinate : ";
	cin>>uy[z];
	cout<<"\n \n Enter 1 for Clockwise and 2 for Anti-Clockwise :";
	cin>>ged[z];
	checkmotion1(ux,uy,ged,z);
	checkmotion2(ux,uy,ged,z);
	gameover(ux,uy,ged,gec,dx);
	++z;
	getch();

	--gec;
}
for(i=1;i<20;i++)
{
if(ux[i]!=0 && uy[i]!=0)
{
if(ged[i]==1)
{
gear2(start,ux[i],uy[i]);
}
if(ged[i]==2)
{
gear1(start,ux[i],uy[i]);
}
}
}
if(dh==69)
{
return;
}
if(dh==67)
{
guide();
getch();
}
delay(10);

}while(dx==1);

getch();
closegraph();
}


void gear1(double start,int x,int y)
{
double t,x1,x2,x3,x4,x5,y5,x6,y6,y1,y2,y3,y4,r=20;
clock_t end;
end=clock();
t = (end-start);
x1 = x + r*cos(25*t);
y1 = y + r*sin(25*t);
x2 = x + r*cos(25*t+200);
y2 = y + r*sin(25*t +200);
x3 = x + r*cos(25*t+400);
y3 = y + r*sin(25*t+400);
x4 = x + r*cos(25*t+600);
y4 = y + r*sin(25*t +600);
x5 = x + r*cos(25*t+800);
y5 = y + r*sin(25*t +800);
x6 = x + r*cos(25*t+1000);
y6 = y + r*sin(25*t +1000);
circle(x,y,20);
circle(x,y,7);
circle(x1,y1,5);
circle(x2,y2,5);
circle(x3,y3,5);
circle(x4,y4,5);
circle(x5,y5,5);
circle(x6,y6,5);
}


void gear2(double start,int x,int y)
{
double t,x1,x2,x3,x4,x5,y5,x6,y6,y1,y2,y3,y4,r=20;
clock_t end;
end=clock();
t = (end-start);
x1 = x + r*cos(-25*t);
y1 = y + r*sin(-25*t);
x2 = x + r*cos(-25*t+200);
y2 = y + r*sin(-25*t +200);
x3 = x + r*cos(-25*t+400);
y3 = y + r*sin(-25*t+400);
x4 = x + r*cos(-25*t+600);
y4 = y + r*sin(-25*t +600);
x5 = x + r*cos(-25*t+800);
y5 = y + r*sin(-25*t +800);
x6 = x + r*cos(-25*t+1000);
y6 = y + r*sin(-25*t +1000);
circle(x,y,20);
circle(x,y,7);
circle(x1,y1,5);
circle(x2,y2,5);
circle(x3,y3,5);
circle(x4,y4,5);
circle(x5,y5,5);
circle(x6,y6,5);
}

//condition to check inter-locking
//---------------------------------------------------------------------------------


void checkmotion1(int xco[],int yco[],int dir[],int &z)  /*to ckeck up-down
							  arrangement*/
{
int i,j,k;
cleardevice();
for(i=z+1;xco[i]!=0;i++)
{

	if(abs(xco[z]-xco[i])<50 && abs(yco[z]-yco[i])<50 )
	{
		outtextxy(200,200,"Gear Overlapping not allowed");
		xco[z]=0;
		yco[z]=0;
		z--;
		getch();
	}

	if((xco[z]-xco[i]) ==0 && abs(yco[z]-yco[i])==50 && dir[z]==dir[i])
	{
	       outtextxy(200,200,"Adjacent Gears should have opp Dirction");
	       xco[z]=0;
	       yco[z]=0;
	       z--;
	       getch();
	}
	if((yco[z] -yco[i])==0 && abs(xco[z]-xco[i])==50 && dir[z]==dir[i])
	{
	       outtextxy(200,200,"Adjacent Gears should have opp Dirction");
	       xco[z]=0;
	       yco[z]=0;
	       z--;
	       getch();
	}


}
}


void checkmotion2(int xco[],int yco[],int dir[],int &z)   /*to check side
							   arrangement*/

{
int i,j,k;
cleardevice();
for(i=z-1;i>=0; i--)
{

	if((abs(xco[z]-xco[i])<50) && (abs(yco[z]-yco[i])<50) )
	{
		outtextxy(200,200,"Gear Overlapping not allowed");
		xco[z]=0;
		yco[z]=0;
		z--;
		getch();
	}
	if((xco[z]-xco[i]) ==0 && abs(yco[z]-yco[i])==50 && dir[z]==dir[i])
	{
	       outtextxy(200,200,"Adjacent Gears should have opp Dirction");
	       xco[z]=0;
	       yco[z]=0;
	       z--;
	       getch();
	}
	if((yco[z] -yco[i])==0 && abs(xco[z]-xco[i])==50 && dir[z]==dir[i])
	{
	       outtextxy(200,200,"Adjacent Gears should have opp Dirction");
	       xco[z]=0;
	       yco[z]=0;
	       z--;
	       getch();
	}


}
}


void gameover(int xco[],int yco[],int dir[],int gc,int &k)      /*condition
							  to check game over*/
{
int ak;
char g[10];
ak = 10 - gc;
itoa(ak,g,10);
int i;
for(i=0;i<11;i++)
{
		if(abs(xco[11]-xco[i])==50 && yco[11]-yco[i]==0 && dir[11]!=dir[i])
		{
		cleardevice();
		outtextxy(200,200,"You have completed all levels");
		outtextxy(200,230,"Press any key to exit");
		getch();
		k=2;
		}

		if(abs(yco[11]-yco[i])==50 && xco[11]-xco[i]==0 && dir[11]!=dir[i])
		{
		cleardevice();
		outtextxy(200,200,"You have completed all levels");
		outtextxy(200,230,"No. of Gears Used");
		outtextxy(270,230,g);
		outtextxy(200,270,"Press any key to exit");
		getch();
		k=2;
		}
		if(abs(yco[11]-yco[i])==20 && abs(xco[11]-xco[i])==45 && dir[11]!=dir[i])
		{
		cleardevice();
		outtextxy(200,200,"You have completed all levels");
		outtextxy(200,230,"No. of Gears Used");
		outtextxy(270,230,g);
		outtextxy(200,270,"Press any key to exit");
		getch();
		k=2;
		}

}
}

//F-X for Gears
//------------------------------------------------------------------------------

void introgears()        //introduction fx
{
int i;
clock_t st;
st = clock();
settextstyle(4,0,4);
for(i=1;i<100;i++)
{
cleardevice();
outtextxy(250,150,"Gears");
outtextxy(250,250,"Loading");
gear1(st,270,350);
gear2(st,320,350);
delay(20);
}
outtextxy(150,420,"Press C any time during the game to access guide");
outtextxy(150,400,"Press Any key to continue");
settextstyle(14,0,1);
getch();
cleardevice();
}

void guide()          //about-game and controls
{
outtextxy(20,50,"50");
outtextxy(20,100,"100");
outtextxy(20,150,"150");
outtextxy(20,200,"200");
outtextxy(20,250,"250");
outtextxy(20,300,"300");
outtextxy(20,350,"350");
outtextxy(20,400,"400");
outtextxy(20,450,"450");
outtextxy(20,500,"500");
outtextxy(50,20,"50");
outtextxy(100,20,"100");
outtextxy(150,20,"150");
outtextxy(200,20,"200");
outtextxy(250,20,"250");
outtextxy(300,20,"300");
outtextxy(350,20,"350");
outtextxy(400,20,"400");
outtextxy(450,20,"450");
outtextxy(500,20,"500");
outtextxy(200,300,"1. Press A to place gears");
outtextxy(200,320,"2. In the next screen enter the x,y co-ordinates of ");
outtextxy(200,340,"center of gears (all gears are of width 50 pixels");
outtextxy(200,360,"3. Add up to 10 gears to complete game by connecting first");
outtextxy(200,380,"and the last gear");
outtextxy(200,400,"4. Adjacent gears should have opposite rotation");
}


void reference()           //axis for co-ordinates
{
int i;
line(0,50,getmaxx(),50);
line(50,0,50,getmaxy());
for(i=0;i<=10;i++)
{
line(50*i,45,50*i,55);
line(45,50*i,55,50*i);
}
}
//------------------------------------------------------------------------------

