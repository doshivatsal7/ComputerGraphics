#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void drawEllipse(float xc, float yc, float a, float b);

void main()
{
	int gd=DETECT,gm;
	float a,b,xc,yc;
	initgraph(&gd,&gm,"");
	cleardevice();
	printf("Enter the co-ordinates of centre: ");
	scanf("%f %f",&xc,&yc);
	printf("Enter the values of a and b: ");
	scanf("%f %f",&a,&b);
	drawEllipse(xc,yc,a,b);
	getch();
	closegraph();
	restorecrtmode();
}

void drawEllipse(float xc, float yc, float a, float b)
{
	int i
float x,y,p;
	x=0;
	y=b;
	p=b*b-a*a*b+(a*a/4);
	do
	{
		delay(100);
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		if(p<0)
		{
			x=x+1;
			p=p+2*b*b*x+b*b;
		}
		else
		{
			x=x+1;
			y=y-1;
			p=p+2*b*b*x-2*a*a*y+b*b;
		}
	}while(b*b*x<=a*a*y);
	p=b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) – a*a*b*b;
	
do
	{       	
		delay(100);
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		if(p>0)
		{
			y=y-1;
			p=p-2*a*a*y+a*a;
		}
		else
		{
				x=x+1;
				y=y-1;
				p=p-2*a*a*y+2*b*b*x+a*a;
		}
	}while(y!=0);
}
