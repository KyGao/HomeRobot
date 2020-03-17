#include"main.h"
#include<stdio.h>
#include "nmouse.h"
#include "move.h"
#include"svgahead.h"
#include"basicgf.h"
#include"compo.h"
#include<conio.h>
#include"advance.h"
#include"frame.h"
#include"hzxs.h"
#include"module_b.h"
#include<string.h>
#include<bios.h>
#include"input.h"
#include"color1.h"
#include"roomgf.h"
#include"sign.h"
#include"filefun.h"
#include"room.h"
#include"ground.h"
#include"brick.h"
#include"wall.h"
#include"outside.h"
#include"iphone.h"
#include"iphCheck.h"
#include"idCheck.h"
#include"select.h"
#include"service.h"
#include"manage.h"
#include"time.h"
#include"control.h"
#include"chat.h"
#include"chatHanz.h"
#include"chatInpu.h"
#include"chatQhwh.h"
#include"chatShow.h"
#include"gkmove.h"
#include"myhouse.h"
#include"chatGame.h"
#include"iphCmfrt.h"
#include"mysystem.h"

void CreateTrash(ROBOT_CASE *robot_position,SAVE *save,int k)
{
	int i=0,j=0,judge=0;
	int x,y;
	//初始化垃圾位置
	while(CheckMove(i+1,j+1,1) == 0 ||judge == 0 ||  ( (i==(*robot_position).x) &&  ((j==(*robot_position).y) || (j==(*robot_position).y-1))  ))
	{
	    i = rand()%19;
	    j = rand()%19;
        if( (((i==5) || (i==6) || (i==7)) && ((j==2) || (j==3) || (j==4) || (j==5))) || (((i==13) || (i==14) || (i==15) || (i==16)) && ((j==9) || (j==10))))
        {
	        judge=1;
	    }
	    else
	    {
	        judge=0;
	    }
	}
	ChangeHouse(9+k*2,i+1);
	ChangeHouse(10+k*2,j+1);
	x = CheckHouse(9+k*2)-1;
	y = CheckHouse(10+k*2)-1;
	switch(k)
	{
		case 0:
		{
			get_image((x)*40,(y)*40,(x)*40+40,(y)*40+40,save->trashsave1);
			trash1(x+1,y+1);
			break;
		}
		case 1:
		{
			get_image((x)*40,(y)*40,(x)*40+40,(y)*40+40,save->trashsave2);
			trash2(CheckHouse(9+k*2),CheckHouse(10+k*2));
	        
			break;
		}
		case 2:
		{
			get_image((x)*40,(y)*40,(x)*40+40,(y)*40+40,save->trashsave3);
			trash3(x+1,y+1);
			break;
		}
	}
	ChangeMove(x+1,y+1,1,0);
	
}


void esc_init(BUTTONS *esc1)
{
	int x=900,y=50,wide=50,height=25;
	bar(x-wide/2,y-height/2,x+wide/2,y+height/2,transcolor(176,224,230));
	outtextxy(x-10,y-5,"esc",1,1,10,44373);
	
	esc1->x = x-wide/2;
	esc1->y = y-height/2;
	esc1->wide = wide;
	esc1->height = height;
	esc1->click=0;
	esc1->over=0;

}

int esc_check(BUTTONS *esc1,int *x,int *y,int *button)
{
	
	if(*x>=esc1->x && *y>=esc1->y && *x<=esc1->x+esc1->wide && *y<=esc1->y+esc1->height)
	{
		esc1->over=1;
		
	}
	if(*x<=esc1->x || *y<=esc1->y || *x>=esc1->x+esc1->wide || *y>=esc1->y+esc1->height)
	{
		esc1->over=0;
		
	}
	if(esc1->over)
	{
		outtextxy(890,45,"esc",1,1,10,0);
	}
	else
	{
		outtextxy(890,45,"esc",1,1,10,44373);
	}
	
	if(esc1->over && *button)
	{
		return 1;//退出系统
	}
}
/*

void CheckStack()
{
	_SP;
	outtextxy(10,100,,1,1,10,65535);
}
*/
void CheckHeap(int i)
{
	int num;
	static int j=0;
	if(j<i)
	{
		j++;
		return ;
	}
	num=0;
	bar(0,0,1024,768,0);
	while(malloc(1024))num++;
	textmode(0);
	printf("%d",num);
	getch();
	exit(0);
}