#include "main.h"
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
#define YG 40
#define M 4
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define UP_DOWN 5
#define LEFT_RIGHT 6

	//	走廊
void wood_ver(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,43845);		//	木色背景
	linever((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,1,31331);	//	五条竖线
	linever((x-1)*YG+10,(y-1)*YG+M,x*YG+10,y*YG+M,1,31331);
	linever((x-1)*YG+20,(y-1)*YG+M,x*YG+20,y*YG+M,1,31331);
	linever((x-1)*YG+30,(y-1)*YG+M,x*YG+30,y*YG+M,1,31331);
	linever((x-1)*YG+40,(y-1)*YG+M,x*YG+40,y*YG+M,1,31331);
}	

	//	浴室
void glass(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,48797);		//	蓝色背景
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,55070);	//	浅色边框
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,55070);
	bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,46651);			//	深色边框
	bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,46651);
	
	bar((x-1)*YG+2,(y-1)*YG+M+18,x*YG-2,(y-1)*YG+M+20,46651);			//中间十字
	bar((x-1)*YG+2,(y-1)*YG+M+20,x*YG-2,(y-1)*YG+M+22,55070);
	bar((x-1)*YG+18,(y-1)*YG+M+2,(x-1)*YG+20,y*YG+M-2,46651);
	bar((x-1)*YG+20,(y-1)*YG+M+2,(x-1)*YG+22,y*YG+M-2,55070);
}

void grey(int x,int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,38001);		//146 143 136
	FillCircle((x-1)*YG+12, (y-1)*YG+M+5, 1, 35888);		//138 135 128
	FillCircle((x-1)*YG+23, (y-1)*YG+M+37, 1, 35888);		//138 135 128
	FillCircle((x-1)*YG+35, (y-1)*YG+M+22, 1, 35888);		//138 135 128
	bar((x-1)*YG+29,(y-1)*YG+M+13,(x-1)*YG+31,(y-1)*YG+M+15, 35888);
	bar((x-1)*YG+20,(y-1)*YG+M+30,(x-1)*YG+22,(y-1)*YG+M+32, 35888);	//138 135 128
	FillCircle((x-1)*YG+8, (y-1)*YG+M+29, 1, 35888);		//138 135 128
}

void meadow(int x, int y)
{
	int a,i,j,c;
	srand((unsigned)time(0));
	for(i=(x-1)*YG;i<x*YG;i++)
	{
		for(j=(y-1)*YG+M;j<y*YG+M;j++)
		{
			a=rand()%5;
				 if(a==0)	c = 46699;			//177 205 92
			else if(a==1)	c = 36232;			//141 179 68
			else if(a==2)	c = 36297;			//136 185 75
			else if(a==3)	c = 38281;			//149 178 79
			else if(a==4)	c = 36330;			//137 190 85
			bar(i,j,i+1,j+1,c);
		}
	}

}


void closet(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,35459);		//	木色背景
	linever((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,1,20899);	//	五条竖线
	linever((x-1)*YG+10,(y-1)*YG+M,x*YG+10,y*YG+M,1,20899);
	linever((x-1)*YG+20,(y-1)*YG+M,x*YG+20,y*YG+M,1,20899);
	linever((x-1)*YG+30,(y-1)*YG+M,x*YG+30,y*YG+M,1,20899);
	linever((x-1)*YG+40,(y-1)*YG+M,x*YG+40,y*YG+M,1,20899);
}	


void step(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y+1)*YG+M,46251);		//	木色背景	180 149 88
	
	linever((x-1)*YG,(y-1)*YG+M,x*YG,(y+1)*YG+M,1,52557);	//	六条竖线	201 170 111
	linever((x-1)*YG+8,(y-1)*YG+M,x*YG+10,(y+1)*YG+M,1,52557);
	linever((x-1)*YG+16,(y-1)*YG+M,x*YG+20,(y+1)*YG+M,1,52557);
	linever((x-1)*YG+24,(y-1)*YG+M,x*YG+20,(y+1)*YG+M,1,52557);
	linever((x-1)*YG+32,(y-1)*YG+M,x*YG+30,(y+1)*YG+M,1,52557);
	linever((x-1)*YG+40,(y-1)*YG+M,x*YG+40,(y+1)*YG+M,1,52557);
	
	linelevel((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,3,52557);
	linelevel((x-1)*YG,(y+1)*YG+M-3,x*YG,(y+1)*YG+M,3,52557);
}


	//	厨房
void green(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,42552);		//	绿色背景
	
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+1,31922);	//	深色边框
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+1,y*YG+M,31922);
	bar((x-1)*YG,y*YG+M-1,x*YG,y*YG+M,31922);			
	bar(x*YG-1,(y-1)*YG+M,x*YG,y*YG+M,31922);
	
	bar((x-1)*YG+1,(y-1)*YG+M+19,x*YG-1,(y-1)*YG+M+20,31922);			//中间十字
	bar((x-1)*YG+1,(y-1)*YG+M+20,x*YG-1,(y-1)*YG+M+21,31922);
	bar((x-1)*YG+19,(y-1)*YG+M+1,(x-1)*YG+20,y*YG+M-1,31922);
	bar((x-1)*YG+20,(y-1)*YG+M+1,(x-1)*YG+21,y*YG+M-1,31922);
}

	//	会客室
void red(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,50612);		//	红色背景
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,52661);	//	浅色边框
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,52661);
	bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,46322);			//	深色边框
	bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,46322);
	
}

	//	洗衣房
void blck_wht(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+20,(y-1)*YG+M+20,65535);	//	白砖
	bar((x-1)*YG+20,(y-1)*YG+M+20,x*YG,y*YG+M,65535);
	bar((x-1)*YG,(y-1)*YG+M+20,(x-1)*YG+20,y*YG+M,21130);			//	黑砖
	bar((x-1)*YG+20,(y-1)*YG+M,x*YG,(y-1)*YG+M+20,21130);
}

	//	卧室
void yellow(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,54899);		//	黄色背景
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,52720);	//	深色边框
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,52720);
	bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,57010);			//	浅色边框
	bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,57010);
	
}

	//	二楼走廊
void wood_hor(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,44017);		//	木色背景
	linelevel((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,1,35689);	//	五条横线
	linelevel((x-1)*YG,(y-1)*YG+M+10,x*YG,y*YG+M+10,1,35689);
	linelevel((x-1)*YG,(y-1)*YG+M+20,x*YG,y*YG+M+20,1,35689);
	linelevel((x-1)*YG,(y-1)*YG+M+30,x*YG,y*YG+M+30,1,35689);
	linelevel((x-1)*YG,(y-1)*YG+M+40,x*YG,y*YG+M+40,1,35689);
}

	//	楼梯
void stairs(int x, int y)
{
		//	楼梯底层
	bar((x-1)*YG,y*YG+M,(x-1)*YG+10,(y+2)*YG+M,25159);		//41863
	bar((x-1)*YG+10,y*YG+M+10,(x-1)*YG+20,(y+2)*YG+M,25159);
	bar((x-1)*YG+20,y*YG+M+20,(x-1)*YG+30,(y+2)*YG+M,25159);
	bar((x-1)*YG+30,y*YG+M+30,(x-1)*YG+40,(y+2)*YG+M,25159);
	bar((x-1)*YG+40,y*YG+M+40,(x-1)*YG+50,(y+2)*YG+M,25159);	
	bar((x-1)*YG+50,y*YG+M+50,(x-1)*YG+60,(y+2)*YG+M,25159);	
	bar((x-1)*YG+60,y*YG+M+60,(x-1)*YG+70,(y+2)*YG+M,25159);	
	bar((x-1)*YG+70,y*YG+M+70,(x-1)*YG+80,(y+2)*YG+M,25159);
		//	楼梯踏板背景
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+10,y*YG+M,31331);		//50511
	bar((x-1)*YG+10,(y-1)*YG+M+10,(x-1)*YG+20,y*YG+M+10,31331);
	bar((x-1)*YG+20,(y-1)*YG+M+20,(x-1)*YG+30,y*YG+M+20,31331);
	bar((x-1)*YG+30,(y-1)*YG+M+30,(x-1)*YG+40,y*YG+M+30,31331);
	bar((x-1)*YG+40,(y-1)*YG+M+40,(x-1)*YG+50,y*YG+M+40,31331);
	bar((x-1)*YG+50,(y-1)*YG+M+50,(x-1)*YG+60,y*YG+M+50,31331);
	bar((x-1)*YG+60,(y-1)*YG+M+60,(x-1)*YG+70,y*YG+M+60,31331);
	bar((x-1)*YG+70,(y-1)*YG+M+70,(x-1)*YG+80,y*YG+M+70,31331);
		//	楼梯踏板
	bar((x-1)*YG+1,(y-1)*YG+M+1,(x-1)*YG+10-1,y*YG+M-1,43845);	//41995
	bar((x-1)*YG+10+1,(y-1)*YG+M+10+1,(x-1)*YG+20-1,y*YG+M+10-1,43845);
	bar((x-1)*YG+20+1,(y-1)*YG+M+20+1,(x-1)*YG+30-1,y*YG+M+20-1,43845);
	bar((x-1)*YG+30+1,(y-1)*YG+M+30+1,(x-1)*YG+40-1,y*YG+M+30-1,43845);
	bar((x-1)*YG+40+1,(y-1)*YG+M+40+1,(x-1)*YG+50-1,y*YG+M+40-1,43845);
	bar((x-1)*YG+50+1,(y-1)*YG+M+50+1,(x-1)*YG+60-1,y*YG+M+50-1,43845);
	bar((x-1)*YG+60+1,(y-1)*YG+M+60+1,(x-1)*YG+70-1,y*YG+M+60-1,43845);
	bar((x-1)*YG+70+1,(y-1)*YG+M+70+1,(x-1)*YG+80-1,y*YG+M+70-1,43845);
}



	

	//	榻榻米
void tatami(int x, int y, int head)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,52816);
	switch(head)
	{
		case UP:		//bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,33703);	//	上
						bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,33703);	//	左
						bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,33703);			//	下
						bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,33703);			//	右
						break;
					
		case LEFT:		bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,33703);	//	上
						//bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,33703);	//	左
						bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,33703);			//	下
						bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,33703);			//	右
						break;
					
		case DOWN:		bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,33703);	//	上
						bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,33703);	//	左
						//bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,33703);			//	下
						bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,33703);			//	右
						break;		

		case RIGHT:		bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,33703);	//	上
						bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,33703);	//	左
						bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,33703);			//	下
						//bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,33703);			//	右
						break;					
					
		case UP_DOWN:	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,33703);	//	上
						//bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,33703);	//	左
						bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,33703);			//	下
						//bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,33703);			//	右
						break;

		case LEFT_RIGHT: //bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,33703);//	上
						bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+2,y*YG+M,33703);	//	左
						//bar((x-1)*YG,y*YG+M-2,x*YG,y*YG+M,33703);			//	下
						bar(x*YG-2,(y-1)*YG+M,x*YG,y*YG+M,33703);			//	右
						break;

		default:		break;
	}
}