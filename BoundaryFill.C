#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void bFill_four(int x, int y, int bcolor, int fcolor);
void bFill_eight(int x, int y, int bcolor, int fcolor);
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
	int choice,bcolor,fcolor,n,x[10],y[10],seedx,seedy,i;
	printf("Enter the number of co-ordinates: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the co-ordinates of point %d: ",i+1);
		scanf("%d %d",&x[i],&y[i]);
	}
	x[n]=x[0];
	y[n]=y[0];
	printf("Enter Boundary Color: ");
	scanf("%d",&bcolor);
	setcolor(bcolor);
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
			    bFill_four(seedx,seedy,bcolor,fcolor);
			    break;

		case 2 : printf("Enter seed point: ");
			    scanf("%d %d",&seedx,&seedy);
			    bFill_eight(seedx,seedy,bcolor,fcolor);
			    break;

		default : printf("Invalid choice");
	}
}

void bFill_four(int x, int y, int bcolor, int fcolor)
{
	int current;
	current=getpixel(x,y);
	if(current!=bcolor && current!=fcolor)
	{
		delay(1);
		putpixel(x,y,fcolor);
		bFill_four(x+1,y,bcolor,fcolor);
		bFill_four(x,y+1,bcolor,fcolor);
		bFill_four(x,y-1,bcolor,fcolor);
		bFill_four(x-1,y,bcolor,fcolor);
	}
}

void bFill_eight(int x, int y, int bcolor, int fcolor)
{
	int current;
	current=getpixel(x,y);
	if(current!=bcolor && current!=fcolor)
	{
		delay(1);
		putpixel(x,y,fcolor);
		bFill_eight(x+1,y,bcolor,fcolor);
		bFill_eight(x-1,y,bcolor,fcolor);
		bFill_eight(x,y+1,bcolor,fcolor);
		bFill_eight(x,y-1,bcolor,fcolor);
		bFill_eight(x+1,y-1,bcolor,fcolor);
		bFill_eight(x+1,y+1,bcolor,fcolor);
		bFill_eight(x-1,y-1,bcolor,fcolor);
		bFill_eight(x-1,y+1,bcolor,fcolor);
	}
}		





