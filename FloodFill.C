#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void fFill_four(int x, int y, int ocolor, int fcolor);
void fFill_eight(int x, int y, int ocolor, int fcolor);
void drawPolygon();

void main()
{
	int choice,gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	drawPolygon();
	getch();
	closegraph();
	restorecrtmode();
}

void drawPolygon()
{
	int choice,ocolor=0,fcolor,n,x[10],y[10],seedx,seedy,i;
	printf("Enter the number of co-ordinates: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the co-ordinates of point %d: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
	}
	x[n]=x[0];
	y[n]=y[0];
	printf("Enter Fill Color: ");
	scanf("%d",&fcolor);
	for(i=0;i<n;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	printf("1. 4-Connected\n");
	printf("2. 8-Connected\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : printf("Enter seed point: ");
			    scanf("%d %d",&seedx,&seedy);
			    fFill_four(seedx,seedy,ocolor,fcolor);
			    break;

		case 2 : printf("Enter seed point: ");
			    scanf("%d %d",&seedx,&seedy);
			    
     fFill_eight(seedx,seedy,ocolor,fcolor);
                     break;

		default : printf("Invalid choice");
	}
}

void fFill_four(int x, int y, int ocolor, int fcolor)
{
	int current;
	current=getpixel(x,y);
	if(current==ocolor)
	{
		delay(1);
		putpixel(x,y,fcolor);
		fFill_four(x+1,y,ocolor,fcolor);
		fFill_four(x,y+1,ocolor,fcolor);
		fFill_four(x,y-1,ocolor,fcolor);
		fFill_four(x-1,y,ocolor,fcolor);
	}
}

void fFill_eight(int x, int y, int ocolor, int fcolor)
{
	int current;
	current=getpixel(x,y);
	if(current==ocolor)
	{
		delay(1);
		putpixel(x,y,fcolor);
		fFill_eight(x+1,y,ocolor,fcolor);
		fFill_eight(x-1,y,ocolor,fcolor);
		fFill_eight(x,y+1,ocolor,fcolor);
		fFill_eight(x,y-1,ocolor,fcolor);
		fFill_eight(x+1,y-1,ocolor,fcolor);
		fFill_eight(x+1,y+1,ocolor,fcolor);
		fFill_eight(x-1,y-1,ocolor,fcolor);
		fFill_eight(x-1,y+1,ocolor,fcolor);
	}
}
