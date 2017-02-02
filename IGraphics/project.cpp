# include "iGraphics.h"
#include <math.h>
#include <string.h>

int title=1,menu=0,math=0,algo=0,calc=0,eqn=0,base=0;
//for calc
char str[20],mprestr[8][10]={"sin ","log ","cos ","ln ","sqrt ","tan ","1/ ","sq "},mnumone[30]="",mnumtwo[30]="";
char mpoststr[7][5]={" ^ "," * "," + "," / "," - "};

double mnumkey=0,mpreflag=0,mpostflag=0,mpre[8],mpost[5],mcount=0,mcount2=0,mprev,mlen,mdot=0,mnum1=0,mnum2=0,mrev=0;
double mans=0,mexp1=0,mexp2=0,mresult=0,mup=0;
char s[40];
int mbaseto=10,mbasefrom=10,mbasenum=0,mbaseoutput=0;
int eqn1=0,eqn2=0,eqn3=0;
int meqna1=0,meqnb1=0,meqnc1=0,meqnd1=0,meqna2=0,meqnb2=0,meqnc2=0,meqnd2=0,meqna3=0,meqnb3=0,meqnc3=0,meqnd3=0,mcounta1=0,mcountb1=0,mcountc1=0,mcountd1=0,mcounta2=0,mcountb2=0,mcountc2=0,mcountd2=0,mcounta3=0,mcountb3=0,mcountc3=0,mcountd3=0;
int	ma1taking=0,mb1taking=0,mc1taking=0,md1taking=0,ma2taking=0,mb2taking=0,mc2taking=0,md2taking=0,ma3taking=0,mb3taking=0,mc3taking=0,md3taking=0,meqnsolflag=0;
double ea1=0,eb1=0,ec1=0,ed1=0,ea2=0,eb2=0,ec2=0,ed2=0,ea3=0,eb3=0,ec3=0,ed3=0;
double ex=0,ey=0,ez=0,einvalid=0;
char ma1[15]="",mb1[15]="",mc1[15]="",md1[15]="",ma2[15]="",mb2[15]="",mc2[15]="",md2[15]="",ma3[15]="",mb3[15]="",mc3[15]="",md3[15]="",meqnsol[15]="";
/* 
	function iDraw() is called again and again by the system.
	
*/
int mbaseerror(int base,char num[])
{
	int mi,mvalue;
	for(mi=0;mi<strlen(num);mi++)
	{
		if(num[mi]=='A')mvalue=10;
		else if(num[mi]=='B')mvalue=11;
		else if(num[mi]=='C')mvalue=12;
		else if(num[mi]=='D')mvalue=13;
		else if(num[mi]=='E')mvalue=14;
		else if(num[mi]=='C')mvalue=15;
		else mvalue=num[mi]-'0';
		if(mvalue>=base)break;
	}
	if(mi==strlen(num))return 0;
	return 1;
}
void mrefreshcalc()
{
	mpreflag=0;
	mans=0;
	mpostflag=0;
	mnumkey=0;
	mnumone[0]='\0';
	mnumtwo[0]='\0';
	for(int i=0;i<8;i++)mpre[i]=0;
	for(int i=0;i<5;i++)mpost[i]=0;
	mup=0;
	mexp1=0;mexp2=0;mdot=0;
	mcount=0;mcount2=0;
}
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
int mbasestrtonum(char num[],int base)
{
	int mi,mvalue,msum=0;
	for(mi=0;mi<strlen(num);mi++)
	{
		if(num[mi]=='A')mvalue=10;
		else if(num[mi]=='B')mvalue=11;
		else if(num[mi]=='C')mvalue=12;
		else if(num[mi]=='D')mvalue=13;
		else if(num[mi]=='E')mvalue=14;
		else if(num[mi]=='C')mvalue=15;
		else mvalue=num[mi]-'0';
		msum=msum*base+mvalue;
	}
	return msum;
}
void mbasechange(char num[],int base,int n)
{
	int mi=0,mvalue,mj;
	while(n!=0)
	{
		mvalue=n%base;
		if(mvalue==10)num[mi]='A';
		else if(mvalue==11)num[mi]='B';
		else if(mvalue==12)num[mi]='C';
		else if(mvalue==13)num[mi]='D';
		else if(mvalue==14)num[mi]='E';
		else if(mvalue==15)num[mi]='F';
		else num[mi]=mvalue+'0';
		mi++;
		n/=base;
	}
	num[mi]='\0';
	for(mi=0,mj=strlen(num)-1;mi<strlen(num)/2;mi++,mj--)
	{
		char temp;
		temp=num[mi];
		num[mi]=num[mj];
		num[mj]=temp;
	}
	
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
void iDraw()
{
	//place your drawing codes here
	iClear();

	

	if(title)
	{
		iShowBMP(0,0,"title.bmp");
		iSetColor(0,191,255);
		iFilledRectangle(300,350,140,70);
		iSetColor(255,255,255);
		iText(335,375,"CLICK",GLUT_BITMAP_TIMES_ROMAN_24);
		//iSetColor(0,0,255);
		
	}

	if(menu)
	{
		iShowBMP(0,0,"menu.bmp");
		iSetColor(0,191,255);
		//iFilledRectangle(190,580,500,70);
		//iFilledRectangle(190,495,500,70);
	}

	if(math)
	{
		iShowBMP(0,0,"math_menu.bmp");
		iSetColor(0,191,255);
		//iFilledRectangle(190,580,500,70);
		//iFilledRectangle(190,495,500,70);
		//iFilledRectangle(190,420,500,65);
	}

	if(calc)
	{

		iShowBMP(0,0,"calc.bmp");
		iSetColor(0,191,255);
		
		
		//iSetColor(0,0,0);
		
		//strcpy(str,"Anik");
		/*for(int i=0;i<12;i++)
		{
			if(mnum[i]==1)
			{ 
				if(i<10)sprintf(str, "%d", i);
				else if(i==11)strcpy(str,"e");
			}
		}*/
		if(mpreflag)
		{
			iSetColor(255,0,0);
			for(int i=0;i<8;i++)
			{
				if(mpre[i])
				{
					iText(675-mcount*11,450+mup,mprestr[i],GLUT_BITMAP_TIMES_ROMAN_24);
				}

			}
		}
		if(mnumkey)
		{
			iSetColor(0,0,0);
			iText(720-mcount*11,450+mup,mnumone,GLUT_BITMAP_TIMES_ROMAN_24);
			//if(mnum[11]){iText(728,450+mup,"e",GLUT_BITMAP_TIMES_ROMAN_24);mlen=728;}
			//else if(mdot==0 || mnum[10])
			//{
			//	sprintf(str, "%d", (int)mnum1);
			//	
			//	//sprintf(str, "%nlf", (double)mnum1);
			//	iText(720-mcount*10,450+mup,str,GLUT_BITMAP_TIMES_ROMAN_24);
			//	mlen=720-mcount*10;
			//}
			//else if(mnum[11]==0)
			//{
			//	//mn=0.1*mdot;
			//	sprintf(str, "%0.6lf", mnum1);
			//	iText(mlen,450+mup,str,GLUT_BITMAP_TIMES_ROMAN_24);
			//}
			//if(mnum[10])iText(730,450,dot,GLUT_BITMAP_TIMES_ROMAN_24);
			
		}
		if(mans)
		{
			sprintf(str, "%0.6lf", mresult);
			iText(720-mcount*11,450,str,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(mpostflag)
		{
			iSetColor(0,0,255);
			for(int i=0;i<8;i++)
			{
				if(mpost[i])
				{
					iText(725-mcount2*11,450+mup,mpoststr[i],GLUT_BITMAP_TIMES_ROMAN_24);
				}

			}
			iSetColor(0,0,0);
			iText(755-mcount2*11,450+mup,mnumtwo,GLUT_BITMAP_TIMES_ROMAN_24);

		}

		//ifilledrectangle(140,299,80,45);//1/x    (*1)
		//ifilledrectangle(140,241,80,45);//sin(0)
		//ifilledrectangle(140,183,80,45);//log(1)
		/*iFilledRectangle(228,299,80,45);//x*x    (*2)
		iFilledRectangle(228,241,80,45);//cos(2)
		iFilledRectangle(228,183,80,45);//ln(3) */
		/*iFilledRectangle(316,299,80,45);//sqrt(4)
		iFilledRectangle(316,241,80,45);//tan(5)
		iFilledRectangle(316,183,80,45);//pow      (*3)*/

		/*iFilledRectangle(412,299,80,45);// 7
		iFilledRectangle(412,241,80,45);// 4
		iFilledRectangle(412,183,80,45);// 1 
		iFilledRectangle(412,125,80,45);// 0 */
		//iFilledRectangle(500,299,80,45);// 8
		//iFilledRectangle(500,241,80,45);// 5
		//iFilledRectangle(500,183,80,45);// 2
		//iFilledRectangle(500,125,80,45);// (.)(10)
		//iFilledRectangle(588,299,80,45);// 9
		//iFilledRectangle(588,241,80,45);// 6
		//iFilledRectangle(588,183,80,45);// 3
		//iFilledRectangle(588,125,80,45);// e (11)

		//iFilledRectangle(684,299,168,45);//del  
		//iFilledRectangle(684,241,80,45);// *  (*4)
		//iFilledRectangle(684,183,80,45);// +  (*5)
		//iFilledRectangle(684,125,80,45);// ans
		//iFilledRectangle(772,241,80,45);// (/) (*6)
		//iFilledRectangle(772,183,80,45);// -   (*7)
		//iFilledRectangle(772,125,80,45);// =
	}
	if(base)
	{
		iShowBMP(0,0,"base.bmp");
		iSetColor(255,0,0);
		//iFilledRectangle(163,389,118,73);
		if(meqnb1)
		{
			iText(363-mcountb1*11,502,mb1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqna1)
		{
			iText(363-mcounta1*11,591,ma1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc1)
		{
			iText(363-mcountc1*5,405,mc1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnsolflag)
		{
			iText(810-strlen(meqnsol)*11,501,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
	if(eqn)
	{
		iShowBMP(0,0,"eqn.bmp");
		iSetColor(0,191,255);
		//iFilledRectangle(192,480,415,47);
	}
	if(eqn1)
	{
		iShowBMP(0,0,"eqn1.bmp");
		iSetColor(255,0,0);
		//iFilledRectangle(423,552,218,38);
		if(meqna1)
		{
			iText(360-mcounta1*11,562,ma1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnb1)
		{
			iText(360-mcountb1*11,500,mb1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc1)
		{
			iText(360-mcountc1*11,440,mc1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqna2)
		{
			iText(630-mcounta2*11,562,ma2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnb2)
		{
			iText(630-mcountb2*11,500,mb2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc2)
		{
			iText(630-mcountc2*11,440,mc2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		if(meqnsolflag)
		{
			sprintf(meqnsol, "%0.3lf", ex);
			iText(364-strlen(meqnsol)*11,371,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(meqnsol, "%0.3lf", ey);
			iText(633-strlen(meqnsol)*11,373,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
		}

	}
	if(eqn2)
	{
		iShowBMP(0,0,"eqn2.bmp");
		iSetColor(255,0,0);
		//eqn1
		if(meqna1)
		{
			iText(360-mcounta1*11,578,ma1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnb1)
		{
			iText(360-mcountb1*11,528,mb1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc1)
		{
			iText(360-mcountc1*11,480,mc1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnd1)
		{
			iText(360-mcountd1*11,432,md1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//eqn2
		if(meqna2)
		{
			iText(632-mcounta2*11,578,ma2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnb2)
		{
			iText(632-mcountb2*11,528,mb2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc2)
		{
			iText(632-mcountc2*11,480,mc2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnd2)
		{
			iText(632-mcountd2*11,432,md2,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//eqn3
		if(meqna3)
		{
			iText(905-mcounta3*11,578,ma3,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnb3)
		{
			iText(905-mcountb3*11,528,mb3,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc3)
		{
			iText(905-mcountc3*11,480,mc3,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnd3)
		{
			iText(905-mcountd3*11,432,md3,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		if(meqnsolflag)
		{
			sprintf(meqnsol, "%0.3lf", ex);
			iText(364-strlen(meqnsol)*11,371,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(meqnsol, "%0.3lf", ey);
			iText(633-strlen(meqnsol)*11,373,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(meqnsol, "%0.3lf", ez);
			iText(902-strlen(meqnsol)*11,373,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//iFilledRectangle(695,573,218,38);
	}
	if(eqn3)
	{
		iShowBMP(0,0,"eqn3.bmp");
		iSetColor(255,0,0);
		//iFilledRectangle(423,552,218,38);
		if(meqna1)
		{
			iText(360-mcounta1*11,562,ma1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnb1)
		{
			iText(360-mcountb1*11,500,mb1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if(meqnc1)
		{
			iText(360-mcountc1*11,440,mc1,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		if(meqnsolflag)
		{
			if(einvalid)
			{
				iText(364-strlen("INVALID!")*11,371,"INVALID!",GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else 
			{
				sprintf(meqnsol, "%0.3lf", ex);
				iText(364-strlen(meqnsol)*11,371,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
				sprintf(meqnsol, "%0.3lf", ey);
				iText(633-strlen(meqnsol)*11,373,meqnsol,GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		
	}


}
//cnrt+k  and cntrl+c  ==comment
//cnrt+k  and cntrl+u  ==uncomment
/* 
	function imousemove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void imousemove(int mx, int my)
{
	//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/* 
	function imouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void imouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//title
		if(title)
		{
			if(mx>=300 && mx<=440 && my>=350 && my<=420)
			{
				title=0;menu=1;
			}
		}
		//menu

		if(math)
		{	
			if(mx>=190 && mx<=690 && my>=580 && my<=650)
			{
				math=0;calc=1;
			}
			if(mx>=190 && mx<=690 && my>=495 && my<=565)
			{
				math=0;eqn=1;
			}
			if(mx>=190 && mx<=690 && my>=420 && my<=485)
			{
				math=0;base=1;
			}
			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				math=0;menu=1;
			}

		}

		if(calc)
		{
			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				calc=0;math=1;
				mrefreshcalc();
			}

			//preoper
			if(mans==0){
			
			if(mpostflag==0)
			{
			if(mx>=140 && mx<=220 && my>=241 && my<=286)
			{
				mpreflag=1;mpre[0]=1;
				for(int i=0;i<8;i++){if(i!=0)mpre[i]=0;}
			}
			if(mx>=140 && mx<=220 && my>=183 && my<=228)
			{
				mpreflag=1;mpre[1]=1;
				for(int i=0;i<8;i++){if(i!=1)mpre[i]=0;}
			}
			if(mx>=228 && mx<=308 && my>=241 && my<=286)
			{
				mpreflag=1;mpre[2]=1;
				for(int i=0;i<8;i++){if(i!=2)mpre[i]=0;}
			}
			if(mx>=228 && mx<=308 && my>=183 && my<=228)
			{
				mpreflag=1;mpre[3]=1;
				for(int i=0;i<8;i++){if(i!=3)mpre[i]=0;}
			}
			if(mx>=316 && mx<=396 && my>=299 && my<=344)
			{
				mpreflag=1;mpre[4]=1;
				for(int i=0;i<8;i++){if(i!=4)mpre[i]=0;}
			}
			if(mx>=316 && mx<=396 && my>=241 && my<=286)
			{
				mpreflag=1;mpre[5]=1;
				for(int i=0;i<8;i++){if(i!=5)mpre[i]=0;}
			}
			if(mx>=140 && mx<=220 && my>=299 && my<=344)
			{
				mpreflag=1;mpre[6]=1;
				for(int i=0;i<8;i++){if(i!=6)mpre[i]=0;}
			}
			if(mx>=228 && mx<=308 && my>=299 && my<=344)
			{
				mpreflag=1;mpre[7]=1;
				for(int i=0;i<8;i++){if(i!=7)mpre[i]=0;}
			}

			}
			if(mexp1==0||(mexp2==0 && mpostflag==1)){
			//numbers
			if(mx>=412 && mx<=492 && my>=125 && my<=170)
			{
				mnumkey=1;//mnum[0]=1;if(mcount){mnum[mprev]=0;mprev=0;}
				if(mpostflag==1){maddstr(mnumtwo,'0');mcount2++;}
				else maddstr(mnumone,'0');
				mcount++;
			}
			if(mx>=412 && mx<=492 && my>=183 && my<=228)
			{
				mnumkey=1;//mnum[1]=1;if(mcount){mnum[mprev]=0;mprev=1;}
				if(mpostflag==1){maddstr(mnumtwo,'1');mcount2++;}
				else maddstr(mnumone,'1');
				mcount++;
			}
			if(mx>=500 && mx<=580 && my>=183 && my<=228)
			{
				mnumkey=1;//mnum[2]=1;if(mcount){mnum[mprev]=0;mprev=2;}
				if(mpostflag==1){maddstr(mnumtwo,'2');mcount2++;}
				else maddstr(mnumone,'2');
				mcount++;
			}
			if(mx>=588 && mx<=668 && my>=183 && my<=228)
			{
				mnumkey=1;//mnum[3]=1;if(mcount){mnum[mprev]=0;mprev=3;}
				if(mpostflag==1){maddstr(mnumtwo,'3');mcount2++;}
				else maddstr(mnumone,'3');
				mcount++;
			}
			if(mx>=412 && mx<=492 && my>=241 && my<=286)
			{
				mnumkey=1;//mnum[4]=1;if(mcount){mnum[mprev]=0;mprev=4;}
				if(mpostflag==1){maddstr(mnumtwo,'4');mcount2++;}
				else maddstr(mnumone,'4');
				mcount++;
			}
			if(mx>=500 && mx<=580 && my>=241 && my<=286)
			{
				mnumkey=1;//mnum[5]=1;if(mcount){mnum[mprev]=0;mprev=5;}
				if(mpostflag==1){maddstr(mnumtwo,'5');mcount2++;}
				else maddstr(mnumone,'5');
				mcount++;
			}
			if(mx>=588 && mx<=668 && my>=241 && my<=286)
			{
				mnumkey=1;//mnum[6]=1;if(mcount){mnum[mprev]=0;mprev=6;}
				if(mpostflag==1){maddstr(mnumtwo,'6');mcount2++;}
				else maddstr(mnumone,'6');
				mcount++;
			}
			if(mx>=412 && mx<=492 && my>=299 && my<=344)
			{
				mnumkey=1;//mnum[7]=1;if(mcount){mnum[mprev]=0;mprev=7;}
				if(mpostflag==1){maddstr(mnumtwo,'7');mcount2++;}
				else maddstr(mnumone,'7');
				mcount++;
			}
			if(mx>=500 && mx<=580 && my>=299 && my<=344)
			{
				mnumkey=1;//mnum[8]=1;if(mcount){mnum[mprev]=0;mprev=8;}
				if(mpostflag==1){maddstr(mnumtwo,'8');mcount2++;}
				else maddstr(mnumone,'8');
				mcount++;
			}
			if(mx>=588 && mx<=668 && my>=299 && my<=344)
			{
				mnumkey=1;//mnum[9]=1;if(mcount){mnum[mprev]=0;mprev=9;}
				if(mpostflag==1){maddstr(mnumtwo,'9');mcount2++;}
				else maddstr(mnumone,'9');
				mcount++;
			}
			if(mx>=500 && mx<=580 && my>=125 && my<=170)
			{
				mnumkey=1;
				if(mpostflag==1)
				{
					mdot=1;
					for(int i=0;i<strlen(mnumtwo);i++)
					{
						if(mnumtwo[i]=='.'){mdot=0;break;}
					}
				if(mdot){maddstr(mnumtwo,'.');mcount2++;mdot=1;mcount++;}
				}
				else 
				{
					mdot=1;
					for(int i=0;i<strlen(mnumone);i++)
					{
						if(mnumone[i]=='.'){mdot=0;break;}
					}
				if(mdot){
					maddstr(mnumone,'.');
				mcount++;
				mdot=1;
				}
				}
			}

			}

			if(mx>=588 && mx<=668 && my>=125 && my<=170)
			{
				mnumkey=1;
				if(mpostflag==1 && strlen(mnumtwo)==0){maddstr(mnumtwo,'e');mcount2++;mcount++;mexp2=1;}
				else if(mpostflag==0 && strlen(mnumone)==0) {maddstr(mnumone,'e');mcount++;mexp1=1;}
				
			}

			if(mx>=684 && mx<=764 && my>=125 && my<=170)
			{
				mnumkey=1;mnum1=mresult;//if(mcount){mnum[mprev]=0;mprev=11;}mcount++;
			}

			if(mpreflag==0){
			if(mx>=316 && mx<=396 && my>=183 && my<=228)
			{
				mpostflag=1;mpost[0]=1;
				for(int i=0;i<5;i++){if(i!=0)mpost[i]=0;}
			}
			if(mx>=684 && mx<=764 && my>=241 && my<=286)
			{
				mpostflag=1;mpost[1]=1;
				for(int i=0;i<5;i++){if(i!=1)mpost[i]=0;}
			}
			if(mx>=684 && mx<=764 && my>=183 && my<=228)
			{
				mpostflag=1;mpost[2]=1;
				for(int i=0;i<5;i++){if(i!=2)mpost[i]=0;}
			}
			if(mx>=772 && mx<=852 && my>=241 && my<=286)
			{
				mpostflag=1;mpost[3]=1;
				for(int i=0;i<5;i++){if(i!=3)mpost[i]=0;}
			}
			if(mx>=772 && mx<=852 && my>=183 && my<=228)
			{
				mpostflag=1;mpost[4]=1;
				for(int i=0;i<5;i++){if(i!=4)mpost[i]=0;}
			}
			}
			
			}

			//(=) key
			if(mx>=772 && mx<=852 && my>=125 && my<=170)
			{
				mnum1=mstrtonum(mnumone);
				mresult=mnum1;
				mup=55;
				mans=1;
				if(mpreflag)
				{
					if(mpre[0])mresult=sin(mnum1*acos(-1.0)/180);
					else if(mpre[1])mresult=log10(mnum1);
					else if(mpre[2])mresult=cos(mnum1*acos(-1.0)/180);
					else if(mpre[3])mresult=log(mnum1);
					else if(mpre[4])mresult=sqrt(mnum1);
					else if(mpre[5])mresult=tan(mnum1*acos(-1.0)/180);
					else if(mpre[6])mresult=1/mnum1;
					else if(mpre[7])mresult=mnum1*mnum1;
				}
				if(mpostflag)
				{
					mnum2=mstrtonum(mnumtwo);
					if(mpost[0])mresult=pow(mnum1,mnum2);
					else if(mpost[1])mresult=mnum1*mnum2;
					else if(mpost[2])mresult=mnum1+mnum2;
					else if(mpost[3])mresult=mnum1/mnum2;
					else if(mpost[4])mresult=mnum1-mnum2;
				}
			}
			
			//del
			if(mx>=684 && mx<=852 && my>=299 && my<=344)
			{
				if(mans==0 && strlen(mnumone)>0)
				{
					if(mpostflag==0){mdelstr(mnumone);mcount--;}
					else if(strlen(mnumtwo)>0)
					{
						mdelstr(mnumtwo);
						mcount--;
						mcount2--;
						if(strlen(mnumtwo)==0)mexp2=0;
					}
					
				}
			}

			//refresh
			if(mx>=140 && mx<=396 && my>=125 && my<=170)
			{
				mrefreshcalc();
			}

			//ans key
			if(mx>=684 && mx<=764 && my>=125 && my<=170)
			{
				if(mpostflag==0 && strlen(mnumone)==0){sprintf(mnumone, "%lf", mresult);mcount=strlen(mnumone);}
				else if(mpostflag==1 && strlen(mnumtwo)==0) {sprintf(mnumtwo, "%lf", mresult);mcount+=strlen(mnumtwo);mcount2=strlen(mnumtwo);}
			}
		}

		if(base)
		{
			if(mx>=163 && mx<=572 && my>=579 && my<=654)//from
			{
				meqna1=1;ma1[0]='\0';mcounta1=0;mb1taking=0;ma1taking=1;mc1taking=0;meqnsolflag=0;
			}
			if(mx>=163 && mx<=572 && my>=482 && my<=559)//to
			{
				meqnb1=1;mb1[0]='\0';mcountb1=0;mb1taking=1;ma1taking=0;mc1taking=0;meqnsolflag=0;
			}
			if(mx>=163 && mx<=572 && my>=389 && my<=462)//num
			{
				meqnc1=1;mc1[0]='\0';mcountc1=0;mb1taking=0;ma1taking=0;mc1taking=1;meqnsolflag=0;
			}
			//numkey
			if(mx>=182 && mx<=300 && my>=260 && my<=315)//7
			{
				if(ma1taking){maddstr(ma1,'7');mcounta1++;}
				if(mb1taking){maddstr(mb1,'7');mcountb1++;}
				if(mc1taking){maddstr(mc1,'7');mcountc1++;}
			}
			if(mx>=182 && mx<=300 && my>=193 && my<=248)//4
			{
				if(ma1taking){maddstr(ma1,'4');mcounta1++;}
				if(mb1taking){maddstr(mb1,'4');mcountb1++;}
				if(mc1taking){maddstr(mc1,'4');mcountc1++;}
			}
			if(mx>=182 && mx<=300 && my>=127 && my<=182)//1
			{
				if(ma1taking){maddstr(ma1,'1');mcounta1++;}
				if(mb1taking){maddstr(mb1,'1');mcountb1++;}
				if(mc1taking){maddstr(mc1,'1');mcountc1++;}
			}
			if(mx>=182 && mx<=300 && my>=62 && my<=117)//0
			{
				if(ma1taking){maddstr(ma1,'0');mcounta1++;}
				if(mb1taking){maddstr(mb1,'0');mcountb1++;}
				if(mc1taking){maddstr(mc1,'0');mcountc1++;}
			}
			if(mx>=309 && mx<=427 && my>=260 && my<=315)//8
			{
				if(ma1taking){maddstr(ma1,'8');mcounta1++;}
				if(mb1taking){maddstr(mb1,'8');mcountb1++;}
				if(mc1taking){maddstr(mc1,'8');mcountc1++;}
			}
			if(mx>=309 && mx<=427 && my>=193 && my<=248)//5
			{
				if(ma1taking){maddstr(ma1,'5');mcounta1++;}
				if(mb1taking){maddstr(mb1,'5');mcountb1++;}
				if(mc1taking){maddstr(mc1,'5');mcountc1++;}
			}
			if(mx>=309 && mx<=427 && my>=127 && my<=182)//2
			{
				if(ma1taking){maddstr(ma1,'2');mcounta1++;}
				if(mb1taking){maddstr(mb1,'2');mcountb1++;}
				if(mc1taking){maddstr(mc1,'2');mcountc1++;}
			}
			if(mx>=435 && mx<=553 && my>=260 && my<=315)//9
			{
				if(ma1taking){maddstr(ma1,'9');mcounta1++;}
				if(mb1taking){maddstr(mb1,'9');mcountb1++;}
				if(mc1taking){maddstr(mc1,'9');mcountc1++;}
			}
			if(mx>=435 && mx<=553 && my>=193 && my<=248)//6
			{
				if(ma1taking){maddstr(ma1,'6');mcounta1++;}
				if(mb1taking){maddstr(mb1,'6');mcountb1++;}
				if(mc1taking){maddstr(mc1,'6');mcountc1++;}
			}
			if(mx>=435 && mx<=553 && my>=127 && my<=182)//3
			{
				if(ma1taking){maddstr(ma1,'3');mcounta1++;}
				if(mb1taking){maddstr(mb1,'3');mcountb1++;}
				if(mc1taking){maddstr(mc1,'3');mcountc1++;}
			}
			if(mx>=558 && mx<=676 && my>=260 && my<=315)//a
			{
				if(mc1taking){maddstr(mc1,'a');mcountc1++;}
				
			}
			if(mx>=558 && mx<=676 && my>=193 && my<=248)//b
			{
				if(mc1taking){maddstr(mc1,'b');mcountc1++;}
			}
			if(mx>=558 && mx<=676 && my>=127 && my<=182)//c
			{
				if(mc1taking){maddstr(mc1,'c');mcountc1++;}
			}
			if(mx>=684 && mx<=802 && my>=260 && my<=315)//d
			{
				if(mc1taking){maddstr(mc1,'d');mcountc1++;}
			}
			if(mx>=684 && mx<=802 && my>=193 && my<=248)//e
			{
				if(mc1taking){maddstr(mc1,'e');mcountc1++;}
			}
			if(mx>=684 && mx<=802 && my>=127 && my<=182)//f
			{
				if(mc1taking){maddstr(mc1,'f');mcountc1++;}
			}

			//del
			if(mx>=309 && mx<=553 && my>=62 && my<=117)
			{
				if(ma1taking)mdelstr(ma1);
				if(mb1taking)mdelstr(mb1);
				if(mc1taking)mdelstr(mc1);
			}

			//ok
			if(mx>=558 && mx<=802 && my>=62 && my<=117)
			{
				if(ma1taking)ma1taking=0;
				if(mb1taking)mb1taking=0;
				if(mc1taking)mc1taking=0;
				if(strlen(ma1)&& strlen(mb1)&& strlen(mc1))
				{
					meqnsolflag=1;
					mbaseto=(int)mstrtonum(mb1);
					mbasefrom=(int)mstrtonum(ma1);
					if(mbaseerror(mbasefrom,mc1)==1){strcpy(meqnsol,"input incompitable!");}
					else 
					{
						mbaseoutput=mbasestrtonum(mc1,mbasefrom);
						mbasechange(meqnsol,mbaseto,mbaseoutput);
					}
					//error check
					
				}
				
			}

			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				base=0;math=1;mb1taking=0;ma1taking=0;mc1taking=0;mbaseto=10;mbasefrom=10;mbasenum=0;mbaseoutput=0;meqnb1=0;meqna1=0;meqnc1=0;meqnsolflag=0;
				mcountb1=0;mcounta1=0;mcountc1=0;
				mb1[0]='\0';ma1[0]='\0';mc1[0]='\0';meqnsol[0]='\0';
			}
		}

		if(eqn)
		{
			
			if(mx>=192 && mx<=607 && my>=615 && my<=662)
			{
				eqn1=1;eqn=0;
			}
			if(mx>=192 && mx<=607 && my>=545 && my<=592)
			{
				eqn2=1;eqn=0;
			}
			if(mx>=192 && mx<=607 && my>=480 && my<=527)
			{
				eqn3=1;eqn=0;
			}
			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				eqn=0;
				math=1;
			}
		}

		if(eqn1)
		{
			if(mx>=152 && mx<=370 && my>=552 && my<=590)//from
			{
				meqna1=1;ma1[0]='\0';mcounta1=0;ma1taking=1;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=490 && my<=528)//from
			{
				meqnb1=1;mb1[0]='\0';mcountb1=0;ma1taking=0;mb1taking=1;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=430 && my<=468)//from
			{
				meqnc1=1;mc1[0]='\0';mcountc1=0;ma1taking=0;mb1taking=0;mc1taking=1;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=432 && mx<=641 && my>=552 && my<=590)//from
			{
				meqna2=1;ma2[0]='\0';mcounta2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=1;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=432 && mx<=641 && my>=490 && my<=528)//from
			{
				meqnb2=1;mb2[0]='\0';mcountb2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=1;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=432 && mx<=641 && my>=430 && my<=468)//from
			{
				meqnc2=1;mc2[0]='\0';mcountc2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=1;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}

			//numkey
			if(mx>=182 && mx<=300 && my>=260 && my<=315)//7
			{
				if(ma1taking){maddstr(ma1,'7');mcounta1++;}
				if(mb1taking){maddstr(mb1,'7');mcountb1++;}
				if(mc1taking){maddstr(mc1,'7');mcountc1++;}
				if(md1taking){maddstr(md1,'7');mcountd1++;}
				if(ma2taking){maddstr(ma2,'7');mcounta2++;}
				if(mb2taking){maddstr(mb2,'7');mcountb2++;}
				if(mc2taking){maddstr(mc2,'7');mcountc2++;}
				if(md2taking){maddstr(md2,'7');mcountd2++;}
				if(ma3taking){maddstr(ma3,'7');mcounta3++;}
				if(mb3taking){maddstr(mb3,'7');mcountb3++;}
				if(mc3taking){maddstr(mc3,'7');mcountc3++;}
				if(md3taking){maddstr(md3,'7');mcountd3++;}
				
			}
			if(mx>=182 && mx<=300 && my>=193 && my<=248)//4
			{
				if(ma1taking){maddstr(ma1,'4');mcounta1++;}
				if(mb1taking){maddstr(mb1,'4');mcountb1++;}
				if(mc1taking){maddstr(mc1,'4');mcountc1++;}
				if(md1taking){maddstr(md1,'4');mcountd1++;}
				if(ma2taking){maddstr(ma2,'4');mcounta2++;}
				if(mb2taking){maddstr(mb2,'4');mcountb2++;}
				if(mc2taking){maddstr(mc2,'4');mcountc2++;}
				if(md2taking){maddstr(md2,'4');mcountd2++;}
				if(ma3taking){maddstr(ma3,'4');mcounta3++;}
				if(mb3taking){maddstr(mb3,'4');mcountb3++;}
				if(mc3taking){maddstr(mc3,'4');mcountc3++;}
				if(md3taking){maddstr(md3,'4');mcountd3++;}
			}
			if(mx>=182 && mx<=300 && my>=127 && my<=182)//1
			{
				if(ma1taking){maddstr(ma1,'1');mcounta1++;}
				if(mb1taking){maddstr(mb1,'1');mcountb1++;}
				if(mc1taking){maddstr(mc1,'1');mcountc1++;}
				if(md1taking){maddstr(md1,'1');mcountd1++;}
				if(ma2taking){maddstr(ma2,'1');mcounta2++;}
				if(mb2taking){maddstr(mb2,'1');mcountb2++;}
				if(mc2taking){maddstr(mc2,'1');mcountc2++;}
				if(md2taking){maddstr(md2,'1');mcountd2++;}
				if(ma3taking){maddstr(ma3,'1');mcounta3++;}
				if(mb3taking){maddstr(mb3,'1');mcountb3++;}
				if(mc3taking){maddstr(mc3,'1');mcountc3++;}
				if(md3taking){maddstr(md3,'1');mcountd3++;}
			}
			if(mx>=182 && mx<=300 && my>=62 && my<=117)//0
			{
				if(ma1taking){maddstr(ma1,'0');mcounta1++;}
				if(mb1taking){maddstr(mb1,'0');mcountb1++;}
				if(mc1taking){maddstr(mc1,'0');mcountc1++;}
				if(md1taking){maddstr(md1,'0');mcountd1++;}
				if(ma2taking){maddstr(ma2,'0');mcounta2++;}
				if(mb2taking){maddstr(mb2,'0');mcountb2++;}
				if(mc2taking){maddstr(mc2,'0');mcountc2++;}
				if(md2taking){maddstr(md2,'0');mcountd2++;}
				if(ma3taking){maddstr(ma3,'0');mcounta3++;}
				if(mb3taking){maddstr(mb3,'0');mcountb3++;}
				if(mc3taking){maddstr(mc3,'0');mcountc3++;}
				if(md3taking){maddstr(md3,'0');mcountd3++;}
			}
			if(mx>=309 && mx<=427 && my>=260 && my<=315)//8
			{
				if(ma1taking){maddstr(ma1,'8');mcounta1++;}
				if(mb1taking){maddstr(mb1,'8');mcountb1++;}
				if(mc1taking){maddstr(mc1,'8');mcountc1++;}
				if(md1taking){maddstr(md1,'8');mcountd1++;}
				if(ma2taking){maddstr(ma2,'8');mcounta2++;}
				if(mb2taking){maddstr(mb2,'8');mcountb2++;}
				if(mc2taking){maddstr(mc2,'8');mcountc2++;}
				if(md2taking){maddstr(md2,'8');mcountd2++;}
				if(ma3taking){maddstr(ma3,'8');mcounta3++;}
				if(mb3taking){maddstr(mb3,'8');mcountb3++;}
				if(mc3taking){maddstr(mc3,'8');mcountc3++;}
				if(md3taking){maddstr(md3,'8');mcountd3++;}
			}
			if(mx>=309 && mx<=427 && my>=193 && my<=248)//5
			{
				if(ma1taking){maddstr(ma1,'5');mcounta1++;}
				if(mb1taking){maddstr(mb1,'5');mcountb1++;}
				if(mc1taking){maddstr(mc1,'5');mcountc1++;}
				if(md1taking){maddstr(md1,'5');mcountd1++;}
				if(ma2taking){maddstr(ma2,'5');mcounta2++;}
				if(mb2taking){maddstr(mb2,'5');mcountb2++;}
				if(mc2taking){maddstr(mc2,'5');mcountc2++;}
				if(md2taking){maddstr(md2,'5');mcountd2++;}
				if(ma3taking){maddstr(ma3,'5');mcounta3++;}
				if(mb3taking){maddstr(mb3,'5');mcountb3++;}
				if(mc3taking){maddstr(mc3,'5');mcountc3++;}
				if(md3taking){maddstr(md3,'5');mcountd3++;}
			}
			if(mx>=309 && mx<=427 && my>=127 && my<=182)//2
			{
				if(ma1taking){maddstr(ma1,'2');mcounta1++;}
				if(mb1taking){maddstr(mb1,'2');mcountb1++;}
				if(mc1taking){maddstr(mc1,'2');mcountc1++;}
				if(md1taking){maddstr(md1,'2');mcountd1++;}
				if(ma2taking){maddstr(ma2,'2');mcounta2++;}
				if(mb2taking){maddstr(mb2,'2');mcountb2++;}
				if(mc2taking){maddstr(mc2,'2');mcountc2++;}
				if(md2taking){maddstr(md2,'2');mcountd2++;}
				if(ma3taking){maddstr(ma3,'2');mcounta3++;}
				if(mb3taking){maddstr(mb3,'2');mcountb3++;}
				if(mc3taking){maddstr(mc3,'2');mcountc3++;}
				if(md3taking){maddstr(md3,'2');mcountd3++;}
			}
			if(mx>=435 && mx<=553 && my>=260 && my<=315)//9
			{
				if(ma1taking){maddstr(ma1,'9');mcounta1++;}
				if(mb1taking){maddstr(mb1,'9');mcountb1++;}
				if(mc1taking){maddstr(mc1,'9');mcountc1++;}
				if(md1taking){maddstr(md1,'9');mcountd1++;}
				if(ma2taking){maddstr(ma2,'9');mcounta2++;}
				if(mb2taking){maddstr(mb2,'9');mcountb2++;}
				if(mc2taking){maddstr(mc2,'9');mcountc2++;}
				if(md2taking){maddstr(md2,'9');mcountd2++;}
				if(ma3taking){maddstr(ma3,'9');mcounta3++;}
				if(mb3taking){maddstr(mb3,'9');mcountb3++;}
				if(mc3taking){maddstr(mc3,'9');mcountc3++;}
				if(md3taking){maddstr(md3,'9');mcountd3++;}
			}
			if(mx>=435 && mx<=553 && my>=193 && my<=248)//6
			{
				if(ma1taking){maddstr(ma1,'6');mcounta1++;}
				if(mb1taking){maddstr(mb1,'6');mcountb1++;}
				if(mc1taking){maddstr(mc1,'6');mcountc1++;}
				if(md1taking){maddstr(md1,'6');mcountd1++;}
				if(ma2taking){maddstr(ma2,'6');mcounta2++;}
				if(mb2taking){maddstr(mb2,'6');mcountb2++;}
				if(mc2taking){maddstr(mc2,'6');mcountc2++;}
				if(md2taking){maddstr(md2,'6');mcountd2++;}
				if(ma3taking){maddstr(ma3,'6');mcounta3++;}
				if(mb3taking){maddstr(mb3,'6');mcountb3++;}
				if(mc3taking){maddstr(mc3,'6');mcountc3++;}
				if(md3taking){maddstr(md3,'6');mcountd3++;}
			}
			if(mx>=435 && mx<=553 && my>=127 && my<=182)//3
			{
				if(ma1taking){maddstr(ma1,'3');mcounta1++;}
				if(mb1taking){maddstr(mb1,'3');mcountb1++;}
				if(mc1taking){maddstr(mc1,'3');mcountc1++;}
				if(md1taking){maddstr(md1,'3');mcountd1++;}
				if(ma2taking){maddstr(ma2,'3');mcounta2++;}
				if(mb2taking){maddstr(mb2,'3');mcountb2++;}
				if(mc2taking){maddstr(mc2,'3');mcountc2++;}
				if(md2taking){maddstr(md2,'3');mcountd2++;}
				if(ma3taking){maddstr(ma3,'3');mcounta3++;}
				if(mb3taking){maddstr(mb3,'3');mcountb3++;}
				if(mc3taking){maddstr(mc3,'3');mcountc3++;}
				if(md3taking){maddstr(md3,'3');mcountd3++;}
			}
			//del
			if(mx>=309 && mx<=427 && my>=62 && my<=117)
			{
				if(ma1taking){mdelstr(ma1);mcounta1--;}
				if(mb1taking){mdelstr(mb1);mcountb1--;}
				if(mc1taking){mdelstr(mc1);mcountc1--;}
				if(md1taking){mdelstr(md1);mcountd1--;}
				if(ma2taking){mdelstr(ma2);mcounta2--;}
				if(mb2taking){mdelstr(mb2);mcountb2--;}
				if(mc2taking){mdelstr(mc2);mcountc2--;}
				if(md2taking){mdelstr(md2);mcountd2--;}
				if(ma3taking){mdelstr(ma3);mcounta3--;}
				if(mb3taking){mdelstr(mb3);mcountb3--;}
				if(mc3taking){mdelstr(mc3);mcountc3--;}
				if(md3taking){mdelstr(md3);mcountd3--;}
				
			}

			//ok
			if(mx>=435 && mx<=553 && my>=62 && my<=117)
			{
				if(ma1taking)ma1taking=0;
				if(mb1taking)mb1taking=0;
				if(mc1taking)mc1taking=0;
				if(md1taking)md1taking=0;
				if(ma2taking)ma2taking=0;
				if(mb2taking)mb2taking=0;
				if(mc2taking)mc2taking=0;
				if(md2taking)md2taking=0;
				if(ma3taking)ma3taking=0;
				if(mb3taking)mb3taking=0;
				if(mc3taking)mc3taking=0;
				if(md3taking)md3taking=0;
				if(strlen(ma1)&& strlen(mb1)&& strlen(mc1)&& strlen(ma2)&& strlen(mb2)&& strlen(mc2))
				{
					meqnsolflag=1;
					ea1=mstrtonum(ma1);
					eb1=mstrtonum(mb1);
					ec1=mstrtonum(mc1);
					ea2=mstrtonum(ma2);
					eb2=mstrtonum(mb2);
					ec2=mstrtonum(mc2);

					//if(mbaseerror(mbasefrom,mc1)==1){strcpy(meqnsol,"input incompitable!");}
			
					ex=(ec1*eb2-eb1*ec2)/(ea1*eb2-eb1*ea2);
					ey=(ea1*ec2-ec1*ea2)/(ea1*eb2-eb1*ea2);
					
					//error check
				}
				
			}

			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				eqn1=0;
				eqn=1;
				meqna1=0;meqnb1=0;meqnc1=0;meqnd1=0;meqna2=0;meqnb2=0;meqnc2=0;meqnd2=0;meqna3=0;meqnb3=0;meqnc3=0;meqnd3=0;mcounta1=0;mcountb1=0;mcountc1=0;mcountd1=0;mcounta2=0;mcountb2=0;mcountc2=0;mcountd2=0;mcounta3=0;mcountb3=0;mcountc3=0;mcountd3=0;
				ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
				ea1=0;eb1=0;ec1=0;ed1=0;ea2=0;eb2=0;ec2=0;ed2=0;ea3=0;eb3=0;ec3=0;ed3=0;
				ex=0;ey=0;ez=0;
				ma1[0]='\0';mb1[0]='\0';mc1[0]='\0';md1[0]='\0';ma2[0]='\0';mb2[0]='\0';mc2[0]='\0';md2[0]='\0';ma3[0]='\0';mb3[0]='\0';mc3[0]='\0';md3[0]='\0';meqnsol[0]='\0';


			}
		}

		if(eqn2)
		{
			//eqn1
			if(mx>=152 && mx<=370 && my>=573 && my<=611)//from
			{
				meqna1=1;ma1[0]='\0';mcounta1=0;ma1taking=1;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=522 && my<=560)//from
			{
				meqnb1=1;mb1[0]='\0';mcountb1=0;ma1taking=0;mb1taking=1;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=474 && my<=512)//from
			{
				meqnc1=1;mc1[0]='\0';mcountc1=0;ma1taking=0;mb1taking=0;mc1taking=1;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=427 && my<=465)//from
			{
				meqnd1=1;md1[0]='\0';mcountd1=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=1;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			//eqn2
			if(mx>=423 && mx<=641 && my>=573 && my<=611)//from
			{
				meqna2=1;ma2[0]='\0';mcounta2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=1;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=423 && mx<=641 && my>=522 && my<=560)//from
			{
				meqnb2=1;mb2[0]='\0';mcountb2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=1;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=423 && mx<=641 && my>=474 && my<=512)//from
			{
				meqnc2=1;mc2[0]='\0';mcountc2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=1;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=423 && mx<=641 && my>=427 && my<=465)//from
			{
				meqnd2=1;md2[0]='\0';mcountd2=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=1;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			//eqn3
			if(mx>=695 && mx<=913 && my>=573 && my<=611)//from
			{
				meqna3=1;ma3[0]='\0';mcounta3=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=1;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=695 && mx<=913 && my>=522 && my<=560)//from
			{
				meqnb3=1;mb3[0]='\0';mcountb3=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=1;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=695 && mx<=913 && my>=474 && my<=512)//from
			{
				meqnc3=1;mc3[0]='\0';mcountc3=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=1;md3taking=0;meqnsolflag=0;
			}
			if(mx>=695 && mx<=913 && my>=427 && my<=465)//from
			{
				meqnd3=1;md3[0]='\0';mcountd3=0;ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=1;meqnsolflag=0;
			}
			

			//numkey
			if(mx>=182 && mx<=300 && my>=260 && my<=315)//7
			{
				if(ma1taking){maddstr(ma1,'7');mcounta1++;}
				if(mb1taking){maddstr(mb1,'7');mcountb1++;}
				if(mc1taking){maddstr(mc1,'7');mcountc1++;}
				if(md1taking){maddstr(md1,'7');mcountd1++;}
				if(ma2taking){maddstr(ma2,'7');mcounta2++;}
				if(mb2taking){maddstr(mb2,'7');mcountb2++;}
				if(mc2taking){maddstr(mc2,'7');mcountc2++;}
				if(md2taking){maddstr(md2,'7');mcountd2++;}
				if(ma3taking){maddstr(ma3,'7');mcounta3++;}
				if(mb3taking){maddstr(mb3,'7');mcountb3++;}
				if(mc3taking){maddstr(mc3,'7');mcountc3++;}
				if(md3taking){maddstr(md3,'7');mcountd3++;}
				
			}
			if(mx>=182 && mx<=300 && my>=193 && my<=248)//4
			{
				if(ma1taking){maddstr(ma1,'4');mcounta1++;}
				if(mb1taking){maddstr(mb1,'4');mcountb1++;}
				if(mc1taking){maddstr(mc1,'4');mcountc1++;}
				if(md1taking){maddstr(md1,'4');mcountd1++;}
				if(ma2taking){maddstr(ma2,'4');mcounta2++;}
				if(mb2taking){maddstr(mb2,'4');mcountb2++;}
				if(mc2taking){maddstr(mc2,'4');mcountc2++;}
				if(md2taking){maddstr(md2,'4');mcountd2++;}
				if(ma3taking){maddstr(ma3,'4');mcounta3++;}
				if(mb3taking){maddstr(mb3,'4');mcountb3++;}
				if(mc3taking){maddstr(mc3,'4');mcountc3++;}
				if(md3taking){maddstr(md3,'4');mcountd3++;}
			}
			if(mx>=182 && mx<=300 && my>=127 && my<=182)//1
			{
				if(ma1taking){maddstr(ma1,'1');mcounta1++;}
				if(mb1taking){maddstr(mb1,'1');mcountb1++;}
				if(mc1taking){maddstr(mc1,'1');mcountc1++;}
				if(md1taking){maddstr(md1,'1');mcountd1++;}
				if(ma2taking){maddstr(ma2,'1');mcounta2++;}
				if(mb2taking){maddstr(mb2,'1');mcountb2++;}
				if(mc2taking){maddstr(mc2,'1');mcountc2++;}
				if(md2taking){maddstr(md2,'1');mcountd2++;}
				if(ma3taking){maddstr(ma3,'1');mcounta3++;}
				if(mb3taking){maddstr(mb3,'1');mcountb3++;}
				if(mc3taking){maddstr(mc3,'1');mcountc3++;}
				if(md3taking){maddstr(md3,'1');mcountd3++;}
			}
			if(mx>=182 && mx<=300 && my>=62 && my<=117)//0
			{
				if(ma1taking){maddstr(ma1,'0');mcounta1++;}
				if(mb1taking){maddstr(mb1,'0');mcountb1++;}
				if(mc1taking){maddstr(mc1,'0');mcountc1++;}
				if(md1taking){maddstr(md1,'0');mcountd1++;}
				if(ma2taking){maddstr(ma2,'0');mcounta2++;}
				if(mb2taking){maddstr(mb2,'0');mcountb2++;}
				if(mc2taking){maddstr(mc2,'0');mcountc2++;}
				if(md2taking){maddstr(md2,'0');mcountd2++;}
				if(ma3taking){maddstr(ma3,'0');mcounta3++;}
				if(mb3taking){maddstr(mb3,'0');mcountb3++;}
				if(mc3taking){maddstr(mc3,'0');mcountc3++;}
				if(md3taking){maddstr(md3,'0');mcountd3++;}
			}
			if(mx>=309 && mx<=427 && my>=260 && my<=315)//8
			{
				if(ma1taking){maddstr(ma1,'8');mcounta1++;}
				if(mb1taking){maddstr(mb1,'8');mcountb1++;}
				if(mc1taking){maddstr(mc1,'8');mcountc1++;}
				if(md1taking){maddstr(md1,'8');mcountd1++;}
				if(ma2taking){maddstr(ma2,'8');mcounta2++;}
				if(mb2taking){maddstr(mb2,'8');mcountb2++;}
				if(mc2taking){maddstr(mc2,'8');mcountc2++;}
				if(md2taking){maddstr(md2,'8');mcountd2++;}
				if(ma3taking){maddstr(ma3,'8');mcounta3++;}
				if(mb3taking){maddstr(mb3,'8');mcountb3++;}
				if(mc3taking){maddstr(mc3,'8');mcountc3++;}
				if(md3taking){maddstr(md3,'8');mcountd3++;}
			}
			if(mx>=309 && mx<=427 && my>=193 && my<=248)//5
			{
				if(ma1taking){maddstr(ma1,'5');mcounta1++;}
				if(mb1taking){maddstr(mb1,'5');mcountb1++;}
				if(mc1taking){maddstr(mc1,'5');mcountc1++;}
				if(md1taking){maddstr(md1,'5');mcountd1++;}
				if(ma2taking){maddstr(ma2,'5');mcounta2++;}
				if(mb2taking){maddstr(mb2,'5');mcountb2++;}
				if(mc2taking){maddstr(mc2,'5');mcountc2++;}
				if(md2taking){maddstr(md2,'5');mcountd2++;}
				if(ma3taking){maddstr(ma3,'5');mcounta3++;}
				if(mb3taking){maddstr(mb3,'5');mcountb3++;}
				if(mc3taking){maddstr(mc3,'5');mcountc3++;}
				if(md3taking){maddstr(md3,'5');mcountd3++;}
			}
			if(mx>=309 && mx<=427 && my>=127 && my<=182)//2
			{
				if(ma1taking){maddstr(ma1,'2');mcounta1++;}
				if(mb1taking){maddstr(mb1,'2');mcountb1++;}
				if(mc1taking){maddstr(mc1,'2');mcountc1++;}
				if(md1taking){maddstr(md1,'2');mcountd1++;}
				if(ma2taking){maddstr(ma2,'2');mcounta2++;}
				if(mb2taking){maddstr(mb2,'2');mcountb2++;}
				if(mc2taking){maddstr(mc2,'2');mcountc2++;}
				if(md2taking){maddstr(md2,'2');mcountd2++;}
				if(ma3taking){maddstr(ma3,'2');mcounta3++;}
				if(mb3taking){maddstr(mb3,'2');mcountb3++;}
				if(mc3taking){maddstr(mc3,'2');mcountc3++;}
				if(md3taking){maddstr(md3,'2');mcountd3++;}
			}
			if(mx>=435 && mx<=553 && my>=260 && my<=315)//9
			{
				if(ma1taking){maddstr(ma1,'9');mcounta1++;}
				if(mb1taking){maddstr(mb1,'9');mcountb1++;}
				if(mc1taking){maddstr(mc1,'9');mcountc1++;}
				if(md1taking){maddstr(md1,'9');mcountd1++;}
				if(ma2taking){maddstr(ma2,'9');mcounta2++;}
				if(mb2taking){maddstr(mb2,'9');mcountb2++;}
				if(mc2taking){maddstr(mc2,'9');mcountc2++;}
				if(md2taking){maddstr(md2,'9');mcountd2++;}
				if(ma3taking){maddstr(ma3,'9');mcounta3++;}
				if(mb3taking){maddstr(mb3,'9');mcountb3++;}
				if(mc3taking){maddstr(mc3,'9');mcountc3++;}
				if(md3taking){maddstr(md3,'9');mcountd3++;}
			}
			if(mx>=435 && mx<=553 && my>=193 && my<=248)//6
			{
				if(ma1taking){maddstr(ma1,'6');mcounta1++;}
				if(mb1taking){maddstr(mb1,'6');mcountb1++;}
				if(mc1taking){maddstr(mc1,'6');mcountc1++;}
				if(md1taking){maddstr(md1,'6');mcountd1++;}
				if(ma2taking){maddstr(ma2,'6');mcounta2++;}
				if(mb2taking){maddstr(mb2,'6');mcountb2++;}
				if(mc2taking){maddstr(mc2,'6');mcountc2++;}
				if(md2taking){maddstr(md2,'6');mcountd2++;}
				if(ma3taking){maddstr(ma3,'6');mcounta3++;}
				if(mb3taking){maddstr(mb3,'6');mcountb3++;}
				if(mc3taking){maddstr(mc3,'6');mcountc3++;}
				if(md3taking){maddstr(md3,'6');mcountd3++;}
			}
			if(mx>=435 && mx<=553 && my>=127 && my<=182)//3
			{
				if(ma1taking){maddstr(ma1,'3');mcounta1++;}
				if(mb1taking){maddstr(mb1,'3');mcountb1++;}
				if(mc1taking){maddstr(mc1,'3');mcountc1++;}
				if(md1taking){maddstr(md1,'3');mcountd1++;}
				if(ma2taking){maddstr(ma2,'3');mcounta2++;}
				if(mb2taking){maddstr(mb2,'3');mcountb2++;}
				if(mc2taking){maddstr(mc2,'3');mcountc2++;}
				if(md2taking){maddstr(md2,'3');mcountd2++;}
				if(ma3taking){maddstr(ma3,'3');mcounta3++;}
				if(mb3taking){maddstr(mb3,'3');mcountb3++;}
				if(mc3taking){maddstr(mc3,'3');mcountc3++;}
				if(md3taking){maddstr(md3,'3');mcountd3++;}
			}
			//del
			if(mx>=309 && mx<=427 && my>=62 && my<=117)
			{
				if(ma1taking){mdelstr(ma1);mcounta1--;}
				if(mb1taking){mdelstr(mb1);mcountb1--;}
				if(mc1taking){mdelstr(mc1);mcountc1--;}
				if(md1taking){mdelstr(md1);mcountd1--;}
				if(ma2taking){mdelstr(ma2);mcounta2--;}
				if(mb2taking){mdelstr(mb2);mcountb2--;}
				if(mc2taking){mdelstr(mc2);mcountc2--;}
				if(md2taking){mdelstr(md2);mcountd2--;}
				if(ma3taking){mdelstr(ma3);mcounta3--;}
				if(mb3taking){mdelstr(mb3);mcountb3--;}
				if(mc3taking){mdelstr(mc3);mcountc3--;}
				if(md3taking){mdelstr(md3);mcountd3--;}
				
			}

			//Ok
			if(mx>=435 && mx<=553 && my>=62 && my<=117)
			{
				if(ma1taking)ma1taking=0;
				if(mb1taking)mb1taking=0;
				if(mc1taking)mc1taking=0;
				if(md1taking)md1taking=0;
				if(ma2taking)ma2taking=0;
				if(mb2taking)mb2taking=0;
				if(mc2taking)mc2taking=0;
				if(md2taking)md2taking=0;
				if(ma3taking)ma3taking=0;
				if(mb3taking)mb3taking=0;
				if(mc3taking)mc3taking=0;
				if(md3taking)md3taking=0;
				if(strlen(ma1)&& strlen(mb1)&& strlen(mc1)&& strlen(md1)&& strlen(ma2)&& strlen(mb2)&& strlen(mc2)&& strlen(md2)&&strlen(ma3)&& strlen(mb3)&& strlen(mc3)&& strlen(md3))
				{
					meqnsolflag=1;
					ea1=mstrtonum(ma1);
					eb1=mstrtonum(mb1);
					ec1=mstrtonum(mc1);
					ed1=mstrtonum(md1);
					ea2=mstrtonum(ma2);
					eb2=mstrtonum(mb2);
					ec2=mstrtonum(mc2);
					ed2=mstrtonum(md2);
					ea3=mstrtonum(ma3);
					eb3=mstrtonum(mb3);
					ec3=mstrtonum(mc3);
					ed3=mstrtonum(md3);

					//if(mbaseerror(mbasefrom,mc1)==1){strcpy(meqnsol,"INPUT INCOMPITABLE!");}
					double ed=ea1*(eb2*ec3-eb3*ec2)-eb1*(ea2*ec3-ea3*ec2)+ec1*(ea2*eb3-ea3*eb2);
					ex=(ed1*(eb2*ec3-eb3*ec2)-eb1*(ed2*ec3-ed3*ec2)+ec1*(ed2*eb3-ed3*eb2))/ed;
					ey=(ea1*(ed2*ec3-ed3*ec2)-ed1*(ea2*ec3-ea3*ec2)+ec1*(ea2*ed3-ea3*ed2))/ed;
					ez=(ea1*(eb2*ed3-eb3*ed2)-eb1*(ea2*ed3-ea3*ed2)+ed1*(ea2*eb3-ea3*eb2))/ed;
					//error check
				}
				
			}


			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				eqn2=0;
				eqn=1;
				meqna1=0;meqnb1=0;meqnc1=0;meqnd1=0;meqna2=0;meqnb2=0;meqnc2=0;meqnd2=0;meqna3=0;meqnb3=0;meqnc3=0;meqnd3=0;mcounta1=0;mcountb1=0;mcountc1=0;mcountd1=0;mcounta2=0;mcountb2=0;mcountc2=0;mcountd2=0;mcounta3=0;mcountb3=0;mcountc3=0;mcountd3=0;
				ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
				ea1=0;eb1=0;ec1=0;ed1=0;ea2=0;eb2=0;ec2=0;ed2=0;ea3=0;eb3=0;ec3=0;ed3=0;
				ex=0;ey=0;ez=0;
				ma1[0]='\0';mb1[0]='\0';mc1[0]='\0';md1[0]='\0';ma2[0]='\0';mb2[0]='\0';mc2[0]='\0';md2[0]='\0';ma3[0]='\0';mb3[0]='\0';mc3[0]='\0';md3[0]='\0';meqnsol[0]='\0';
			}
		}

		if(eqn3)
		{
			if(mx>=152 && mx<=370 && my>=552 && my<=590)//from
			{
				meqna1=1;ma1[0]='\0';mcounta1=0;ma1taking=1;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=490 && my<=528)//from
			{
				meqnb1=1;mb1[0]='\0';mcountb1=0;ma1taking=0;mb1taking=1;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			if(mx>=152 && mx<=370 && my>=430 && my<=468)//from
			{
				meqnc1=1;mc1[0]='\0';mcountc1=0;ma1taking=0;mb1taking=0;mc1taking=1;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
			}
			//numkey
			if(mx>=182 && mx<=300 && my>=260 && my<=315)//7
			{
				if(ma1taking){maddstr(ma1,'7');mcounta1++;}
				if(mb1taking){maddstr(mb1,'7');mcountb1++;}
				if(mc1taking){maddstr(mc1,'7');mcountc1++;}
				
				
			}
			if(mx>=182 && mx<=300 && my>=193 && my<=248)//4
			{
				if(ma1taking){maddstr(ma1,'4');mcounta1++;}
				if(mb1taking){maddstr(mb1,'4');mcountb1++;}
				if(mc1taking){maddstr(mc1,'4');mcountc1++;}
				
			}
			if(mx>=182 && mx<=300 && my>=127 && my<=182)//1
			{
				if(ma1taking){maddstr(ma1,'1');mcounta1++;}
				if(mb1taking){maddstr(mb1,'1');mcountb1++;}
				if(mc1taking){maddstr(mc1,'1');mcountc1++;}
				
			}
			if(mx>=182 && mx<=300 && my>=62 && my<=117)//0
			{
				if(ma1taking){maddstr(ma1,'0');mcounta1++;}
				if(mb1taking){maddstr(mb1,'0');mcountb1++;}
				if(mc1taking){maddstr(mc1,'0');mcountc1++;}
				
			}
			if(mx>=309 && mx<=427 && my>=260 && my<=315)//8
			{
				if(ma1taking){maddstr(ma1,'8');mcounta1++;}
				if(mb1taking){maddstr(mb1,'8');mcountb1++;}
				if(mc1taking){maddstr(mc1,'8');mcountc1++;}
			
			}
			if(mx>=309 && mx<=427 && my>=193 && my<=248)//5
			{
				if(ma1taking){maddstr(ma1,'5');mcounta1++;}
				if(mb1taking){maddstr(mb1,'5');mcountb1++;}
				if(mc1taking){maddstr(mc1,'5');mcountc1++;}
		
			}
			if(mx>=309 && mx<=427 && my>=127 && my<=182)//2
			{
				if(ma1taking){maddstr(ma1,'2');mcounta1++;}
				if(mb1taking){maddstr(mb1,'2');mcountb1++;}
				if(mc1taking){maddstr(mc1,'2');mcountc1++;}
				
			}
			if(mx>=435 && mx<=553 && my>=260 && my<=315)//9
			{
				if(ma1taking){maddstr(ma1,'9');mcounta1++;}
				if(mb1taking){maddstr(mb1,'9');mcountb1++;}
				if(mc1taking){maddstr(mc1,'9');mcountc1++;}
			}
			if(mx>=435 && mx<=553 && my>=193 && my<=248)//6
			{
				if(ma1taking){maddstr(ma1,'6');mcounta1++;}
				if(mb1taking){maddstr(mb1,'6');mcountb1++;}
				if(mc1taking){maddstr(mc1,'6');mcountc1++;}

			}
			if(mx>=435 && mx<=553 && my>=127 && my<=182)//3
			{
				if(ma1taking){maddstr(ma1,'3');mcounta1++;}
				if(mb1taking){maddstr(mb1,'3');mcountb1++;}
				if(mc1taking){maddstr(mc1,'3');mcountc1++;}
			}
			//del
			if(mx>=309 && mx<=427 && my>=62 && my<=117)
			{
				if(ma1taking){mdelstr(ma1);mcounta1--;}
				if(mb1taking){mdelstr(mb1);mcountb1--;}
				if(mc1taking){mdelstr(mc1);mcountc1--;}
				
			}

			//ok
			if(mx>=435 && mx<=553 && my>=62 && my<=117)
			{
				if(ma1taking)ma1taking=0;
				if(mb1taking)mb1taking=0;
				if(mc1taking)mc1taking=0;
				if(strlen(ma1)&& strlen(mb1)&& strlen(mc1)&& strlen(ma2)&& strlen(mb2)&& strlen(mc2))
				{
					meqnsolflag=1;
					ea1=mstrtonum(ma1);
					eb1=mstrtonum(mb1);
					ec1=mstrtonum(mc1);
					//error check
					double ed=eb1*eb1-4*ea1*ec1;
					if(ed<0)einvalid=1;
					else {
					ex=(-eb1+sqrt(ed))/(2*ea1);
					ey=(-eb1-sqrt(ed))/(2*ea1);
					}
					
				}
				
			}

			//back
			if(mx>=26 && mx<=110 && my>=610 && my<=678)
			{
				eqn3=0;
				eqn=1;
				meqna1=0;meqnb1=0;meqnc1=0;meqnd1=0;meqna2=0;meqnb2=0;meqnc2=0;meqnd2=0;meqna3=0;meqnb3=0;meqnc3=0;meqnd3=0;mcounta1=0;mcountb1=0;mcountc1=0;mcountd1=0;mcounta2=0;mcountb2=0;mcountc2=0;mcountd2=0;mcounta3=0;mcountb3=0;mcountc3=0;mcountd3=0;
				ma1taking=0;mb1taking=0;mc1taking=0;md1taking=0;ma2taking=0;mb2taking=0;mc2taking=0;md2taking=0;ma3taking=0;mb3taking=0;mc3taking=0;md3taking=0;meqnsolflag=0;
				ea1=0;eb1=0;ec1=0;ed1=0;ea2=0;eb2=0;ec2=0;ed2=0;ea3=0;eb3=0;ec3=0;ed3=0;
				ex=0;ey=0;ez=0;
				ma1[0]='\0';mb1[0]='\0';mc1[0]='\0';md1[0]='\0';ma2[0]='\0';mb2[0]='\0';mc2[0]='\0';md2[0]='\0';ma3[0]='\0';mb3[0]='\0';mc3[0]='\0';md3[0]='\0';meqnsol[0]='\0';


			}
		}

		if(menu)
		{	
			if(mx>=190 && mx<=690 && my>=580 && my<=650)
			{
				menu=0;math=1;
				
			}
			if(mx>=190 && mx<=690 && my>=495 && my<=565)
			{
				menu=0;algo=1;
			}
		}
		
		
			//printf("x = %d, y= %d\n",mx,my);
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
	if(key == 'm')
	{
		math=1;menu=0;
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

void pf()
{
	printf("%d %d\n",mcount,mprev);
}
int main()
{
	//place your own initialization codes here. 	
	iInitialize(1000, 700, "Malgo Simulation");
	for(int i=0;i<8;i++)mpre[i]=0;
	for(int i=0;i<5;i++)mpost[i]=0;
	/*mnum1[0]='\0';
	mnum1[0]='\0';*/

	return 0;
}	