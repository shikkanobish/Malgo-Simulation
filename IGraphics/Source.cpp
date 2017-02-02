
# include "iGraphics.h"
#include<math.h>
#include<time.h>

double x = 200, y = 550;
int flag = 1;
int t = 0;

void flag_control()
{
	//t++;

	if (t > 500 || y > 500)
	{
		t = 0;
		flag *= -1;
	}
}

void iDraw()
{

	iClear();

	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 1500, 1000);

	y = y - .3;

	if (flag == -1)
	{
		y = y + .6;
		flag_control();
	}

	iShowBMP(x, y, "flp.bmp");

}


void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


void iKeyboard(unsigned char key) {
	if (key == 'p')
	{

	}

}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_UP)
	{
		flag *= -1;
	}
}



int main()
{

	iInitialize(1200, 650, "Flappy Bird");


	return 0;
}