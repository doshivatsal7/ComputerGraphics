#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void matrix(float x[4][3],float y[3][3],float z[4][3]);
float a[4][3],t1[3][3],r[3][3],t2[3][3],f[4][3],f1[4][3],f2[4][3];
void main()
{
	int i,j,gd=DETECT,gm;
	float theta;
	initgraph(&gd,&gm,"");
	cleardevice();
	printf("Enter the co-ordinates of the polygon:\n");
	for(i=0;i<4;i++)
	{
		scanf("%f %f",&a[i][0],&a[i][1]);
		a[i][2]=1;
	}
	cleardevice();
	line(0,240,640,240);
	line(320,0,320,480);
	for(i=0;i<4;i++)
	{
		line(320+a[i][0],240-a[i][1], 320+a[(i+1)%4][0],240-a[(i+1)%4][1]);
	}
	getch();
	cleardevice();
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				t1[i][j]=1;
			else
				t1[i][j]=0;
		}
	}
	t1[2][0]=-a[0][0];
	t1[2][1]=-a[0][1];
	t1[2][2]=1;
	matrix(a,t1,f);
	printf("Enter the degree of rotation in degrees: ");
	scanf("%f",&theta);
	theta=theta*3.14/180;
	r[0][0]=r[1][1]=cos(theta);
	r[0][1]=sin(theta);
	r[1][0]=-sin(theta);
	r[0][2]=r[1][2]=r[2][0]=r[2][1]=0;
	r[2][2]=1;
	
matrix(f,r,f1);
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				t2[i][j]=1;
			else
				t2[i][j]=0;
		}
	}
	t2[2][0]=+a[0][0];
	t2[2][1]=+a[0][1];
	t2[2][2]=1;
	matrix(f1,t2,f2);
}


void matrix(float x[4][3],float y[3][3], float z[4][3])
{
	int i,j,k;
	line(0,240,640,240);
	line(320,0,320,480);
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			z[i][j]=0;
			for(k=0;k<3;k++)
			{
				z[i][j]=(int)z[i][j]+(int)(x[i][k]*y[k][j]);
			}
		}
	}
	for(i=0;i<4;i++)
	{
		line(320+z[i][0],240-z[i][1], 320+z[(i+1)%4][0],240-z[(i+1)%4][1]);
	}
	getch();
	cleardevice();
}






