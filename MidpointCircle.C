•rcle using Midpoint Circle Algorithm.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void drawCircle(float xc, float yc, float r);

void main()
{
	int gd=DETECT,gm,i;
	float r,xc,yc;
	initgraph(&gd,&gm,"");
	cleardevice();
	printf("Enter the co-ordinates of centre: ");
	scanf("%f %f",&xc,&yc);
	printf("Enter the radius ");
	scanf("%f",&r);
	drawCircle(xc,yc,r);
	getch();
	closegraph();
	restorecrtmode();
}

void drawCircle(float xc, float yc, float r)
{
	float x,y,d;
	d=(5/4)-r;
	x=0;
	y=r;
	do
	{
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		if(d<0)
			d=d+2*x+3;
		else
		{
			d=d+2*(x-y)+5;
			y=y-1;
		}
		x=x+1;
	}while(x<=y);
}
