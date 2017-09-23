#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int gd=DETECT,gm,i;
	float x1,y1,x2,y2,dx,dy,xinc,yinc,x,y,e;
	initgraph(&gd,&gm,"");
	cleardevice();
	printf("Enter the co-ordinates of point1: ");
	scanf("%f %f",&x1,&y1);
	printf("Enter the co-ordinates of point2: ");
	scanf("%f %f",&x2,&y2);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(x1<x2)
		xinc=1;
	else
		xinc=-1;

	if(y1<y2)
		yinc=1;
	else
		yinc=-1;
	x=x1;
	y=y1;
	putpixel((int)x,(int)y,WHITE);
	if(dx>=dy)
	{
		e=2*dy-dx;
		while(x!=x2)
		{
			if(e<0)
				e=e+2*dy;
			else
			{
				e=e+2*(dy-dx);
				y=y+yinc;
			}
			x=x+xinc;
			putpixel((int)x,(int)y,WHITE);
		}
	}
	


else
{		
	e=2*dx-dy;
		while(y!=y2)
		{
			if(e<0)
				e=e+2*dx;
			else
			{
				e=e+2*(dx-dy);
				x=x+xinc;
			}
			y=y+yinc;
			putpixel((int)x,(int)y,WHITE);
		}
	}
	getch();
	closegraph();
	restorecrtmode();
}


 


