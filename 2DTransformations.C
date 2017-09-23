#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void translation()
{
	int tx,ty,i;
	int t[5][2]= {10,10, 50,10, 50,50, 10,50, 10,10};
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
	printf("Enter translation in x and y: ");
	scanf("%d %d",&tx,&ty);
	for(i=0;i<5;i++)
	{
		t[i][0]=t[i][0]+tx;
		t[i][1]=t[i][1]+ty;
	}
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
}

void rotation()
{
	float theta;
	int rot[5][2]={0,0, 0,50, 70,50, 70,0, 0,0};
	int rot_dash[5][2];
	int i;
	setcolor(BLUE);
	for(i=0;i<4;i++)
	{
		line(320+rot[i][0],240-rot[i][1], 320+rot[i+1][0],240-rot[i+1][1]);
	}
	printf("Enter rotation in degrees: ");
	scanf("%f",&theta);
	theta=theta*3.14/180;
	for(i=0;i<5;i++)
	{
		rot_dash[i][0]=(int)(rot[i][0]*cos(theta))-(int)(rot[i][1]*sin(theta));
		rot_dash[i][1]=(int)(rot[i][0]*sin(theta))+(int)(rot[i][1]*cos(theta));
	}
	for(i=0;i<4;i++)
	
{
		line(320+rot_dash[i][0],240-rot_dash[i][1], 320+rot_dash[i+1][0],240-rot_dash[i+1][1]);
	}

}

void scaling()
{
	float scaling_factor;
	int t[5][2]={25,40, 25,-40, -25,-40, -25,40, 25,40};
	int i;
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
	printf("Enter scaling factor: ");
	scanf("%f",&scaling_factor);
	for(i=0;i<5;i++)
	{
		t[i][0]=(t[i][0]*scaling_factor);
		t[i][1]=(t[i][1]*scaling_factor);
	}
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
}

void reflection()
{
	int choice;
	int t[5][2]= {10,10, 50,10, 50,50, 10,50, 10,10};
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
	printf("\n******MAIN MENU*******\n");
	printf("1. About X\n");
	printf("2. About Y\n");
	printf("3. About O\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 : for(i=0;i<5;i++)
			 {
				t[i][1]=-t[i][1];
			 }
			 break;

		case 2 : for(i=0;i<5;i++)
			 
{
				t[i][0]=-t[i][0];
			 }
			 break;

		case 3 : for(i=0;i<5;i++)
			 {
				t[i][0]=-t[i][0];
				t[i][1]=-t[i][1];
			 }
			 break;
	}
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
	
}
void shearing()
{
	int shx,shy,i;
	int t[5][2]= {10,10, 50,10, 50,50, 10,50, 10,10};
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
	printf("Enter shear in x and y: ");
	scanf("%d %d",&tshx,&shy);
	for(i=0;i<5;i++)
	{
		t[i][0]=t[i][0]+t[i][0]*shy;
		t[i][1]=t[i][1]+t[i][1]*shx;
	}
	for(i=0;i<4;i++)
	{
		line(320+t[i][0],240-t[i][1], 320+t[i+1][0],240-t[i+1][1]);
	}
}

void main()
{
	int choice,gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	printf("\n******MAIN MENU*******\n");
	printf("1. Translation\n");
	printf("2. Rotation\n");
	printf("3. Scaling\n");
	printf("4. Reflection\n");
	printf("5. Shearing\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
clrscr();
	cleardevice();
	line(0,240,640,240);
	line(320,0,320,480);
	switch(choice)
	{
		case 1 : translation();
			 break;

		case 2 : rotation();
			 break;

		case 3 : scaling();
			 break;

		case 4 : reflection();
			 break;

		case 5 : shearing();
			 break;

		default : printf("Invalid choice");
	}
	getch();
	closegraph();
	restorecrtmode();
}

















