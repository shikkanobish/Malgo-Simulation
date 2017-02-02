/*
author: S. M. Shahriar Nirjon
last modified: August 8, 2008
*/
# include "iGraphics.h"
# include "gl.h"
int n;
int x,z;
int i,a,b,c,d=0,flag1=1,flag2=1,start=0;

int algo=1,bubble=0,insert=0,selection=0,algo_menu=0;
int flagin1=1,flagin2=0,flagin3=1,cin=1,din=0;
int flagsel1=1,flagsel2=1,csel=0,dsel=0,position=0;

int eqn1=0,eqn2=0,eqn3=0;
int meqna1=0,meqnb1=0,meqnc1=0,meqnd1=0,meqna2=0,meqnb2=0,meqnc2=0,meqnd2=0,meqna3=0,meqnb3=0,meqnc3=0,meqnd3=0,mcounta1=0,mcountb1=0,mcountc1=0,mcountd1=0,mcounta2=0,mcountb2=0,mcountc2=0,mcountd2=0,mcounta3=0,mcountb3=0,mcountc3=0,mcountd3=0;
int	ma1taking=0,mb1taking=0,mc1taking=0,md1taking=0,ma2taking=0,mb2taking=0,mc2taking=0,md2taking=0,ma3taking=0,mb3taking=0,mc3taking=0,md3taking=0,meqnsolflag=0;
double ea1=0,eb1=0,ec1=0,ed1=0,ea2=0,eb2=0,ec2=0,ed2=0,ea3=0,eb3=0,ec3=0,ed3=0;
double ex=0,ey=0,ez=0,einvalid=0;
char ma1[20]="",mb1[15]="",mc1[15]="",md1[15]="",ma2[15]="",mb2[15]="",mc2[15]="",md2[15]="",ma3[15]="",mb3[15]="",mc3[15]="",md3[15]="",meqnsol[15]="";

//int ball_x1=700, ball_y1=350,ball_x=100, ball_y=350,;
int ball_x2[8]={150,250,350,450,550,650,750,850},ball_y2[8]={350,350,350,350,350,350,350,350};
int ball_z1[8]={255,0,0,155,0,255,255,155},ball_z2[8]={0,255,0,155,255,255,0,0},ball_z3[8]={0,0,255,155,255,0,255,0};
int num[8]={0},numcopy[8]={0};
int dx=10, dy=10;
char name[10][15]={"number0.bmp","number1.bmp","number2.bmp","number3.bmp","number4.bmp","number5.bmp","number6.bmp","number7.bmp","number8.bmp","number9.bmp"};


void maddstr(char s[],char ch)
{
	s[strlen(s)+1]='\0';
	s[strlen(s)]=ch;
	s[strlen(s)+1]=ch;
}
void mdelstr(char s[])
{
	s[strlen(s)-1]='\0';
}
double mstrtonum(char s[])
{
	double mret=0,mflag=0;
	if(strcmp(s,"e")==0)return exp(1.0);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')mflag=1;
		else if(mflag>=1)mret=mret+(double)(s[i]-'0')/pow(10,mflag++);
		else mret=mret*10+(double)(s[i]-'0');
	}
	return mret;
}
/* 
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();
	if(algo)
	{
		iShowBMP(0,0,"algo-input.bmp");
		iSetColor(255, 0,0);
		//iFilledRectangle(155,548,420,90);
		//iFilledRectangle(154,428,620,86);
		if(meqnb1)
		{
			iText(365-mcountb1*5,558,mb1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqna1)
		{
			iText(464-mcounta1*5,438,ma1,GLUT_BITMAP_TIMES_ROMAN_24);
		}

	}

	if(algo_menu)
	{
		iShowBMP(0,0,"algo_menu.bmp");
	}

	if(bubble||insert||selection)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(0,0,1000,708);
		iShowBMP(0,0,"start_algo.bmp");
		iShowBMP(900,0,"back_algo.bmp");
	iSetColor(255, 100, 10);
	for(i=0;i<n;i++){
		iFilledRectangle(ball_x2[i]+x, ball_y2[i],5,90);
		iFilledRectangle(ball_x2[i]+x, ball_y2[i],75,5);
		iFilledRectangle(ball_x2[i]+70+x,ball_y2[i],5,90);
		iFilledRectangle(ball_x2[i]+x, ball_y2[i]+85,75,5);
		iSetColor(ball_z1[i],ball_z2[i],ball_z3[i]);

		iShowBMP(ball_x2[i]+x+5,ball_y2[i]+5,name[num[i]]);
	}
	}
	//iFilledCircle(399, 399, 7);

	/*iSetColor(255, 255, 255);
	iFilledRectangle(ball_x1, ball_y1,5,50);
	iFilledRectangle(ball_x1, ball_y1,50,5);
	iFilledRectangle(ball_x1+45, ball_y1,5,50);
	iFilledRectangle(ball_x1, ball_y1+45,50,5);*/
	//iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

/* 
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(bubble||insert||selection)
		{
			if(mx>=0 && mx<=100 && my>=0 && my<=100)
			{
				start=1;
			}
			//back
			if(mx>=900 && mx<=1000 && my>=0 && my<=100)
			{
				algo_menu=1;bubble=0;insert=0;selection=0;
				flagin1=1;flagin2=0;flagin3=1;cin=1;din=0;
				flagsel1=1;flagsel2=1;csel=0;dsel=0;position=0;
				start=0;flag1=1;flag2=1;d=0;
			}

		}
		if(algo_menu)
		{
			if(mx>=190 && mx<=690 && my>=580 && my<=650)
			{
				bubble=1;algo_menu=0;c=n-1;
				printf("%d\n",n);
				for(int mi=0;mi<n;mi++)
				{
					num[mi]=numcopy[mi];
					printf("%d ",num[mi]);
				}
				
			}
			if(mx>=190 && mx<=690 && my>=495 && my<=565)
			{
				selection=1;algo_menu=0;
				for(int mi=0;mi<n;mi++)
				{
					num[mi]=numcopy[mi];
				}
			}
			if(mx>=190 && mx<=690 && my>=420 && my<=485)
			{
				insert=1;algo_menu=0;
				for(int mi=0;mi<n;mi++)
				{
					num[mi]=numcopy[mi];
				}
			}
			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				//algo_menu=0;menu=1;
			}
		}
		if(algo)
		{
			if(mx>=155 && mx<=575 && my>=548 && my<=638)//from
			{
				meqnb1=1;mb1[0]='\0';mcountb1=0;ma1taking=0;mb1taking=1;
			}
			if(mx>=154 && mx<=774 && my>=428 && my<=518)//from
			{
				meqna1=1;ma1[0]='\0';mcounta1=0;ma1taking=1;mb1taking=0;
			}
			if(mx>=182 && mx<=300 && my>=260 && my<=315)//7
			{
				if(ma1taking){maddstr(ma1,'7');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'7');mcountb1++;}
			}
			if(mx>=182 && mx<=300 && my>=193 && my<=248)//4
			{
				if(ma1taking){maddstr(ma1,'4');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'4');mcountb1++;}
			}
			if(mx>=182 && mx<=300 && my>=127 && my<=182)//1
			{
				if(ma1taking){maddstr(ma1,'1');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'1');mcountb1++;}
			}
			if(mx>=182 && mx<=300 && my>=62 && my<=117)//0
			{
				if(ma1taking){maddstr(ma1,'0');mcounta1++;maddstr(ma1,',');mcounta1++;}
				
			}
			if(mx>=309 && mx<=427 && my>=260 && my<=315)//8
			{
				if(ma1taking){maddstr(ma1,'8');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'8');mcountb1++;}
			}
			if(mx>=309 && mx<=427 && my>=193 && my<=248)//5
			{
				if(ma1taking){maddstr(ma1,'5');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'5');mcountb1++;}
			}
			if(mx>=309 && mx<=427 && my>=127 && my<=182)//2
			{
				if(ma1taking){maddstr(ma1,'2');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'2');mcountb1++;}
			}
			if(mx>=435 && mx<=553 && my>=260 && my<=315)//9
			{
				if(ma1taking){maddstr(ma1,'9');mcounta1++;maddstr(ma1,',');mcounta1++;}
				
			}
			if(mx>=435 && mx<=553 && my>=193 && my<=248)//6
			{
				if(ma1taking){maddstr(ma1,'6');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'6');mcountb1++;}
			}
			if(mx>=435 && mx<=553 && my>=127 && my<=182)//3
			{
				if(ma1taking){maddstr(ma1,'3');mcounta1++;maddstr(ma1,',');mcounta1++;}
				if(mb1taking){maddstr(mb1,'3');mcountb1++;}
			}
			
			//del
			if(mx>=309 && mx<=427 && my>=62 && my<=117)
			{
				if(ma1taking){mdelstr(ma1);mdelstr(ma1);}
				if(mb1taking)mdelstr(mb1);
			}

			//ok
			if(mx>=435 && mx<=553 && my>=62 && my<=117)
			{
				if(strlen(mb1)==1 &&(strlen(ma1)==2*(int)mstrtonum(mb1)) )
				{
					n=(int)mstrtonum(mb1);
					x=(8-n)*50;
					for(int mi=0,mj=0;mi<strlen(ma1);mi+=2,mj++)
					{
						numcopy[mj]=ma1[mi]-'0';
						printf("%d ",numcopy[mj]);
					}
					printf("\n");
					algo_menu=1;
					algo=0;
					
					mb1taking=0;ma1taking=0;meqnb1=0;meqna1=0;
					mcountb1=0;mcounta1=0;
					mb1[0]='\0';ma1[0]='\0';
				}
				
			}

			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				mb1taking=0;ma1taking=0;meqnb1=0;meqna1=0;
				mcountb1=0;mcounta1=0;
				mb1[0]='\0';ma1[0]='\0';
			}


		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use 
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}
void arrswap(int c, int d)
{




}
//int a=ball_x2[2];
void ballChange(){
	
	if(insert && start){
		if(cin<n)
		{
			if(flagin3){din=cin;flagin3=0;}
			
			if(num[din]<num[din-1]){flagin2=1;}
			else{flagin2=0;}

			if(flagin2)
			{
				if(flagin1){a=ball_x2[din];b=ball_x2[din-1];flagin1=0;}
				
				if(ball_y2[din-1]!=500 && ball_x2[din-1]==b)
				{
					ball_y2[din-1] += dy;
					ball_y2[din] -= dy;
				}
				if(ball_x2[din-1]!=a && ball_y2[din-1]==500)
				{
					ball_x2[din-1] += dx;
					ball_x2[din] -= dx;
				}
				if(ball_y2[din-1]!=350 && ball_x2[din-1]==a)
				{
					ball_y2[din-1] -= dy;
					ball_y2[din] += dy;
				}

				if(ball_x2[din-1]==a && ball_y2[din-1]==350)
				{
					flagin1=1;
					z=ball_x2[din];
					ball_x2[din]=ball_x2[din-1];
					ball_x2[din-1]=z;
					z=num[din];
					num[din]=num[din-1];
					num[din-1]=z;

					din--;
					if(din==0){cin++;flagin3=1;}
				}
			}
			else
			{
			if(flagin1==1){if(ball_y2[din-1]!=500) {ball_y2[din-1] += dy; ball_y2[din] -= dy;}else{flagin1=0;}}
			if(flagin1==0){if(ball_y2[din-1]!=350) {ball_y2[din-1] -= dy; ball_y2[din] += dy;}else{flagin1=2;}}
			if(flagin1==2){
			din--;flagin1=1;
			if(din==0){cin++;flagin3=1;}
			
			}
			}
		}
	}

	if(bubble && start){
		if(c>0){
			if(num[d]<=num[d+1]){flag2=0;}

			if(flag2){
				if(flag1) {a=ball_x2[d+1];b=ball_x2[d];flag1=0;}

				if(ball_y2[d]!=500 && ball_x2[d]==b) {ball_y2[d] += dy; ball_y2[d+1] -= dy;} 
				if(ball_x2[d]!=a && ball_y2[d]==500) {ball_x2[d] += dx; ball_x2[d+1] -= dx;}
				if(ball_y2[d]!=350 && ball_x2[d]==a) {ball_y2[d] -= dy; ball_y2[d+1] += dy;}

				if(ball_x2[d]==a && ball_y2[d]==350)
				{
					flag1=1;
					z=ball_x2[d];ball_x2[d]=ball_x2[d+1];ball_x2[d+1]=z;
					z=num[d];num[d]=num[d+1];num[d+1]=z;
					d++;
					if(d==c){c--;d=0;}
				}
			} 
			else{
				
				if(flag1==1){if(ball_y2[d]!=500) {ball_y2[d] += dy; ball_y2[d+1] -= dy;}else{flag1=0;}}
				if(flag1==0){if(ball_y2[d]!=350) {ball_y2[d] -= dy; ball_y2[d+1] += dy;}else{flag1=2;}}
				if(flag1==2){
				flag2=1;flag1=1;
				d++;
				if(d==c){c--;d=0;}}
			}
		}
	}

	if(selection && start)
	{
		if(csel<n-1)   
		{
			/* if(flagsel1){  
			position = csel;
			dsel=csel+1;
			flagsel1=0;
			} */

			if(flagsel1){
				position=csel;
				for ( dsel = csel + 1 ; dsel < n ; dsel++ )
				{
					if ( num[position] > num[dsel] )
						position = dsel;
				}
				flagsel1=0;
			}
			/*if(flagsel1==0)
			{
			if(flagsel3)
			{
			if ( num[position] > num[dsel] )
			{position = dsel;}
			dsel++;
			if(dsel==n){flagsel3=0;}
			}
			}
			*/
			if(flagsel1==0){
				if ( position != csel )
				{
					if(flagsel2){a=ball_x2[position];b=ball_x2[csel];flagsel2=0;}
					
					if(ball_y2[csel]!=500 && ball_x2[csel]==b){ball_y2[csel] += dy;ball_y2[position] -= dy;}
					if(ball_x2[csel]!=a && ball_y2[csel]==500){ball_x2[csel] += dx;ball_x2[position] -= dx;}
					if(ball_y2[csel]!=350 && ball_x2[csel]==a){ball_y2[csel] -= dy;ball_y2[position] += dy;}

					if(ball_x2[csel]==a && ball_y2[csel]==350)
					{
						z=ball_x2[position];ball_x2[position]=ball_x2[csel];ball_x2[csel]=z;
						
						z=num[position];num[position]=num[csel];num[csel]=z;

						csel++;flagsel1=1;flagsel2=1;

					}
				}
				else {
					if(flagsel2==1){if(ball_y2[csel]!=500) {ball_y2[csel] += dy;}else{flagsel2=0;}}
					if(flagsel2==0){if(ball_y2[csel]!=350) {ball_y2[csel] -= dy;}else{flagsel2=2;}}
					if(flagsel2==2){csel++;flagsel1=1;flagsel2=1;}
			}
		}
	}
	}
}
//if(ball_x!=100 && ball_y==100) ball_x -= dx;


int main()
{
	//place your own initialization codes here. 



	iSetTimer(40,ballChange);
	dx = 10;
	dy = 10;
	iInitialize(1000, 708, "Ball Demo");

	return 0;
}	