# include "iGraphics.h"
#include<math.h>
#include<time.h>
#include<iostream>
using namespace std;


double o,x=500,y=360+250,sx,sy,p;
double xm=500,ym=360+220,mx,my,pm;
double xh=500,yh=360+200,hx,hy,ph;
double H,M,S;
int i,l,m,r,s,a,b,digital=1,analog=0;

void iDraw()
{
	
	iClear();

	iText(25, 25, "Press 'd' for Digital Clock , 'a' for Analog Clock , END for exit. :) ",GLUT_BITMAP_TIMES_ROMAN_24);

	if(analog)
	{
		iSetColor(10,10,10);
	iFilledCircle(500,360,300);//Large
	   iSetColor(0,255,0);
	   iCircle(500,360,305);//out
	iSetColor(0,0,255);
	iCircle(500,360,275);//nextout
	iSetColor(255,0,0);
	for (i=1,o=(6/57.29);i<=60;i++,o+=(6/57.29))
	{   if(i%5!=0)
			iFilledCircle(500+295*cos(o),360+295*sin(o),4);
		if (i%5==0)
			iFilledCircle(0,0,0);
	}


	iSetColor(255,0,0);
	iLine(500,360,x,y);///second
	iSetColor(0,120,120);
	iLine(500,360,xm,ym);///minit
	iSetColor(20,200,40);
	iLine(500,360,xh,yh);//HR
	iSetColor(255,0,0);
	iText(500+244,360-150,"IV");//4(500+259,360-150)point
    iText(500+145,360-256,"V");//	iFilledCircle(500+150,360-260,5);//60
	iText(495,60,"VI");//iFilledCircle(500,65,5);//lower
	iText(500-155,360-257,"VII");//iFilledCircle(500-150,360-260,5);//120
	iText(200,360,"IX");//iFilledCircle(205,360,5);//left
	iText(500-255,360+145,"X");//iFilledCircle(500-260,360+150,5);//150
	iText(500+240,360+150,"II");//iFilledCircle(500+259,360+150,5);//330
	iText(500+140,360+252,"I");//	iFilledCircle(500+150,360+260,5);//300
	iText(490,650,"XII");//	iFilledCircle(500,655,5);//upper
	iText(777,360,"III");//	iFilledCircle(795,360,5);//right
	iText(500-150,360+250,"XI");//	iFilledCircle(500-150,360+260,5);//240
	iText(500-260,360-150,"VIII");//	iFilledCircle(500-260,360-150,5);//210
    iSetColor(20,50,210);
	iFilledCircle(500,360,20);//small
	}


	if(digital)
	{
	iSetColor(255,255,255);
	iFilledRectangle(340,236,30,30);
	iFilledRectangle(340,452,30,30);
	iFilledRectangle(630,236,30,30);
	iFilledRectangle(630,452,30,30);
	int delx=0,n;
	for(i=1;i<=6;i++)
	{
		if(i==1){n=l;delx=0;}
		if(i==2){n=m;delx=120;}
		if(i==3){n=r;delx=290;}
		if(i==4){n=s;delx=410;}
		if(i==5){n=a;delx=580;}
		if(i==6){n=b;delx=700;}


	int n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0,n11=0,n12=0,n13=0;
	if(n==1){n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(255,0,0);}
	if(n==2){n1=1,n2=1,n3=1,n5=1,n6=1,n7=1,n8=1,n9=1,n11=1,n12=1,n13=1;iSetColor(255,102,0);}
	if(n==3){n1=1,n3=1,n5=1,n6=1,n7=1,n8=1,n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(255,204,0);}
	if(n==4){n3=1,n4=1,n5=1,n7=1,n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(255,255,102);}
	if(n==5){n1=1,n3=1,n4=1,n5=1,n6=1,n7=1,n8=1,n9=1,n10=1,n11=1,n13=1;iSetColor(0,180,0);}
	if(n==6){n1=1,n2=1,n3=1,n4=1,n5=1,n6=1,n7=1,n8=1,n9=1,n10=1,n11=1,n13=1;iSetColor(0,230,0);}
	if(n==7){n5=1,n8=1,n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(153,255,153);}
	if(n==8){n1=1,n2=1,n3=1,n4=1,n5=1,n6=1,n7=1,n8=1,n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(0,104,255);}
	if(n==9){n1=1,n3=1,n4=1,n5=1,n6=1,n7=1,n8=1,n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(153,0,204);}
	if(n==0){n1=1,n2=1,n3=1,n4=1,n5=1,n6=1,n8=1,n9=1,n10=1,n11=1,n12=1,n13=1;iSetColor(255,0,255);}
	if(n1==1)iFilledRectangle(100+delx,110,16,16);
	if(n2==1)iFilledRectangle(100+delx,126,16,226);
	if(n3==1)iFilledRectangle(100+delx,352,16,16);
	if(n4==1)iFilledRectangle(100+delx,366,16,226);
	if(n5==1)iFilledRectangle(100+delx,592,16,16);

	if(n6==1)iFilledRectangle(116+delx,110,68,16);
	if(n7==1)iFilledRectangle(116+delx,352,68,16);
	if(n8==1)iFilledRectangle(116+delx,592,68,16);

	if(n9==1)iFilledRectangle(184+delx,110,16,16);
	if(n10==1)iFilledRectangle(184+delx,126,16,226);
	if(n11==1)iFilledRectangle(184+delx,352,16,16);
	if(n12==1)iFilledRectangle(184+delx,368,16,226);
	if(n13==1)iFilledRectangle(184+delx,592,16,16);
	}
	}
}


void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'a')
	{
		analog=1;
		digital=0;
	}
	if(key == 'd')
	{
		analog=0;
		digital=1;
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

void second()
 
{
	  sx=250*cos(p/57.29);
	  sy=250*sin(p/57.29);
	  x=500+sx;
	  y=360+sy;
      p=p-6;
}
void minute()
{
      mx=220*cos(pm/57.29);
	  my=220*sin(pm/57.29);
	  xm=500+mx;
	  ym=360+my;
	  pm=pm-.1;
}
void hour()
{
	hx=200*cos(ph/57.29);
	hy=200*sin(ph/57.29);
	xh=500+hx;
	yh=360+hy;
	ph=ph-1/600;
}

void timeNow()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );
	ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	M=ptm->tm_min;
	S=(ptm->tm_sec)+2;

	l=((int)H/10);
	m=(int)H%10;
	r=((int)M/10);
	s=(int)M%10;
	a=((int)S/10);
	b=(int)S%10;
	if(a==6 & r==6){a=0;r=0;}
}

int main()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	M=ptm->tm_min;
	S=(ptm->tm_sec)+2;

	cout<<H<<"     "<<M<<"     "<<S<<endl;

	l=((int)H/10);
	m=(int)H%10;
	r=((int)M/10);
	s=(int)M%10;
	a=((int)S/10);
	b=(int)S%10;
	if(a==6 & r==6){a=0;r=0;}

	iSetTimer(1000,timeNow);

	ph =(3-H)*30.0-30*M/60.0-30*S/3600.0+.1/600+270+90;
     
	pm= (15-M)*6.0-S/60.0+.1+270+90;

	p = (15-S)*6.0+6+270+90;

    second();
    minute();
    hour();
	
   
	
    iSetTimer(1000,second);
	iSetTimer(1000,minute);
	iSetTimer(1000,hour);

	iInitialize(1000, 720, "Clock");
	return 0;
}	