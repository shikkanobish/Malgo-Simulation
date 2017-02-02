#include"iGraphics.h"
#include<math.h>
#include<time.h>
void timenow();



//double o,x=500,y=360+250,sx,sy,p;
//double xm=500,ym=360+220,mx,my,pm;
double H,M,S;
int j,w,l,m,n,o;

void iDraw()
{
	
	iClear();
	iSetColor(0,255,0);
	iFilledRectangle(385,230,10,10);
	iFilledRectangle(385,320,10,10);
	iFilledRectangle(605,230,10,10);
	iFilledRectangle(605,320,10,10);
	

	int j1=0,j2=0,j3=0,j4=0,j5=0,j6=0,j7=0,k1=0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,l7=0,m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,o1=0,o2=0,o3=0,o4=0,o5=0,o6=0,o7=0,delx=110;
	if (j==1) {j6=1;j4=1;}
	if (j==2) {j7=1;j6=1;j5=1;j2=1;j3=1;}
	if (j==3) {j7=1;j6=1;j5=1;j4=1;j3=1;}
	if (j==4) {j1=1;j5=1;j6=1;j4=1;}
	if (j==5) {j7=1;j1=1;j5=1;j4=1;j3=1;}
	if (j==6) {j7=1;j1=1;j5=1;j2=1;j3=1;j4=1;}
	if (j==7) {j7=1;j6=1;j4=1;}
	if (j==8) {j6=1;j7=1;j1=1;j2=1;j3=1;j4=1;j5=1;}
	if (j==9) {j1=1;j3=1;j4=1;j5=1;j6=1;j7=1;}
	if (j==0) {j6=1;j7=1;j1=1;j2=1;j3=1;j4=1;}

	if (l==1) {l6=1;l4=1;}
	if (l==2) {l7=1;l6=1;l5=1;l2=1;l3=1;}
	if (l==3) {l7=1;l6=1;l5=1;l4=1;l3=1;}
	if (l==4) {l1=1;l5=1;l6=1;l4=1;}
	if (l==5) {l7=1;l1=1;l5=1;l4=1;l3=1;}
	if (l==6) {l7=1;l1=1;l5=1;l2=1;l3=1;l4=1;}
	if (l==7) {l7=1;l6=1;l4=1;}
	if (l==8) {l6=1;l7=1;l1=1;l2=1;l3=1;l4=1;l5=1;}
	if (l==9) {l1=1;l3=1;l4=1;l5=1;l6=1;l7=1;}
	if (l==0) {l6=1;l7=1;l1=1;l2=1;l3=1;l4=1;}

    if (m==1) {m6=1;m4=1;}
	if (m==2) {m7=1;m6=1;m5=1;m2=1;m3=1;}
	if (m==3) {m7=1;m6=1;m5=1;m4=1;m3=1;}
	if (m==4) {m1=1;m5=1;m6=1;m4=1;}
	if (m==5) {m7=1;m1=1;m5=1;m4=1;m3=1;}
	if (m==6) {m7=1;m1=1;m5=1;m2=1;m3=1;m4=1;}
	if (m==7) {m7=1;m6=1;m4=1;}
	if (m==8) {m6=1;m7=1;m1=1;m2=1;m3=1;m4=1;m5=1;}
	if (m==9) {m1=1;m3=1;m4=1;m5=1;m6=1;m7=1;}
	if (m==0) {m6=1;m7=1;m1=1;m2=1;m3=1;m4=1;}

	if (n==1) {n6=1;n4=1;}
	if (n==2) {n7=1;n6=1;n5=1;n2=1;n3=1;}
	if (n==3) {n7=1;n6=1;n5=1;n4=1;n3=1;}
	if (n==4) {n1=1;n5=1;n6=1;n4=1;}
	if (n==5) {n7=1;n1=1;n5=1;n4=1;n3=1;}
	if (n==6) {n7=1;n1=1;n5=1;n2=1;n3=1;n4=1;}
	if (n==7) {n7=1;n6=1;n4=1;}
	if (n==8) {n6=1;n7=1;n1=1;n2=1;n3=1;n4=1;n5=1;}
	if (n==9) {n1=1;n3=1;n4=1;n5=1;n6=1;n7=1;}
	if (n==0) {n6=1;n7=1;n1=1;n2=1;n3=1;n4=1;}

	if (o==1) {o6=1;o4=1;}
	if (o==2) {o7=1;o6=1;o5=1;o2=1;o3=1;}
	if (o==3) {o7=1;o6=1;o5=1;o4=1;o3=1;}
	if (o==4) {o1=1;o5=1;o6=1;o4=1;}
	if (o==5) {o7=1;o1=1;o5=1;o4=1;o3=1;}
	if (o==6) {o7=1;o1=1;o5=1;o2=1;o3=1;o4=1;}
	if (o==7) {o7=1;o6=1;o4=1;}
	if (o==8) {o6=1;o7=1;o1=1;o2=1;o3=1;o4=1;o5=1;}
	if (o==9) {o1=1;o3=1;o4=1;o5=1;o6=1;o7=1;}
	if (o==0) {o6=1;o7=1;o1=1;o2=1;o3=1;o4=1;}
	
	if (w==1) {k6=1;k4=1;}
	if (w==2) {k7=1;k6=1;k5=1;k2=1;k3=1;}
	if (w==3) {k7=1;k6=1;k5=1;k4=1;k3=1;}
	if (w==4) {k1=1;k5=1;k6=1;k4=1;}
	if (w==5) {k7=1;k1=1;k5=1;k4=1;k3=1;}
	if (w==6) {k7=1;k1=1;k5=1;k2=1;k3=1;k4=1;}
	if (w==7) {k7=1;k6=1;k4=1;}
	if (w==8) {k6=1;k7=1;k1=1;k2=1;k3=1;k4=1;k5=1;}
	if (w==9) {k1=1;k3=1;k4=1;k5=1;k6=1;k7=1;}
	if (w==0) {k6=1;k7=1;k1=1;k2=1;k3=1;k4=1;}



	if(j1==1) iFilledRectangle(180,290,20,50);
	if(j2==1) iFilledRectangle(180,220,20,50);
	if(j3==1) iFilledRectangle(200,200,50,20);
	if(j4==1) iFilledRectangle(250,220,20,50);
	if(j5==1) iFilledRectangle(200,270,50,20);
	if(j6==1) iFilledRectangle(250,290,20,50);
	if(j7==1) iFilledRectangle(200,340,50,20);

	
	if(k1==1) iFilledRectangle(180+delx,290,20,50);
	if(k2==1) iFilledRectangle(180+delx,220,20,50);
	if(k3==1) iFilledRectangle(200+delx,200,50,20);
	if(k4==1) iFilledRectangle(250+delx,220,20,50);
	if(k5==1) iFilledRectangle(200+delx,270,50,20);
	if(k6==1) iFilledRectangle(250+delx,290,20,50);
	if(k7==1) iFilledRectangle(200+delx,340,50,20);



	
	if(l1==1) iFilledRectangle(180+2*delx,290,20,50);
	if(l2==1) iFilledRectangle(180+2*delx,220,20,50);
	if(l3==1) iFilledRectangle(200+2*delx,200,50,20);
	if(l4==1) iFilledRectangle(250+2*delx,220,20,50);
	if(l5==1) iFilledRectangle(200+2*delx,270,50,20);
	if(l6==1) iFilledRectangle(250+2*delx,290,20,50);
	if(l7==1) iFilledRectangle(200+2*delx,340,50,20);


	
	if(m1==1) iFilledRectangle(180+3*delx,290,20,50);
	if(m2==1) iFilledRectangle(180+3*delx,220,20,50);
	if(m3==1) iFilledRectangle(200+3*delx,200,50,20);
	if(m4==1) iFilledRectangle(250+3*delx,220,20,50);
	if(m5==1) iFilledRectangle(200+3*delx,270,50,20);
	if(m6==1) iFilledRectangle(250+3*delx,290,20,50);
	if(m7==1) iFilledRectangle(200+3*delx,340,50,20);



	
	if(n1==1) iFilledRectangle(180+4*delx,290,20,50);
	if(n2==1) iFilledRectangle(180+4*delx,220,20,50);
	if(n3==1) iFilledRectangle(200+4*delx,200,50,20);
	if(n4==1) iFilledRectangle(250+4*delx,220,20,50);
	if(n5==1) iFilledRectangle(200+4*delx,270,50,20);
	if(n6==1) iFilledRectangle(250+4*delx,290,20,50);
	if(n7==1) iFilledRectangle(200+4*delx,340,50,20);


	
	if(o1==1) iFilledRectangle(180+5*delx,290,20,50);
	if(o2==1) iFilledRectangle(180+5*delx,220,20,50);
	if(o3==1) iFilledRectangle(200+5*delx,200,50,20);
	if(o4==1) iFilledRectangle(250+5*delx,220,20,50);
	if(o5==1) iFilledRectangle(200+5*delx,270,50,20);
	if(o6==1) iFilledRectangle(250+5*delx,290,20,50);
	if(o7==1) iFilledRectangle(200+5*delx,340,50,20);



	/*iFilledCircle(500,360,300);//Large
	   iSetColor(0,0,255);
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


	iSetColor(0,255,0);
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
	iFilledCircle(500,360,20);//small*/

}
void timenow()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	M=ptm->tm_min;
	S=(ptm->tm_sec)+2;
	j=(int)H/10;
	w=(int)H%10;
	l=(int)M/10;
	m=(int)M%10;
	n=(int)S/10;
	o=(int)S%10;
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
	if(key == 'q')
	{
		
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

/*void second()
 
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
}*/
int main()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	M=ptm->tm_min;
	S=(ptm->tm_sec)+2;

	j=(int)H/10;
	w=(int)H%10;
	l=(int)M/10;
	m=(int)M%10;
	n=(int)S/10;
	o=(int)S%10;
	

	//ph =(3-H)*30.0-30*M/60.0-30*S/3600.0+.1/600+270+90;
     
	//pm= (15-M)*6.0-S/60.0+.1+270+90;

	//p = (15-S)*6.0+6+270+90;

    //second();
    //minute();
    //hour();
	
   
	
    //iSetTimer(1000,second);
	//iSetTimer(1000,minute);
	iSetTimer(1000,timenow);
	
	iInitialize(1000, 720, "demo");
	return 0;
}