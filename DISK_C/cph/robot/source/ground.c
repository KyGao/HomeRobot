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
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define UP_DOWN 5
#define LEFT_RIGHT 6

/******
地形
******/
void floor_G(void)
{
	int i,j;
	
	//	走廊
	for(i=6;i<=14;i++)		//	竖条
	{
		wood_ver(11,i);
		wood_ver(12,i);
	}

	for(i=11;i<=19;i++)		//	横条
	{
		wood_ver(i,14);
		wood_ver(i,13);
	}
	for(i=17;i<=19;i++)		//	门口区域
	{
		for(j=15;j<=18;j++)
		{
			wood_ver(i,j);
		}
	}
	
	
	//	厨房
	for(i=11;i<=19;i++){
		for(j=2;j<=5;j++){
			green(i,j);
		}
	}
	
	bed(18,4);
	trashbin(13,5);
	table(14,2);
	
	//seat(14,3);
	//seat(15,3);
	
	//	洗衣间
	for(i=13;i<=17;i++){
		for(j=7;j<=9;j++){
			blck_wht(i,j);
		}
	}
	
	
	//	卫生间
	for(i=13;i<=17;i++){
		for(j=10;j<=12;j++){
			glass(i,j);
		}
	}
	

	
	//	卧室
	for(i=3;i<=10;i++){
		for(j=3;j<=7;j++){
			yellow(i,j);
		}
	}
	
	//bed
	bed(4,5);
	/*桌椅
	table(8,5);
	seat(7,5);
	seat(8,6);
	*/
	
	
	//	起居室
	tatami(2,8,UP_DOWN);
	tatami(2,9,UP_DOWN);
	tatami(2,10,UP_DOWN);
	tatami(2,11,DOWN);
	tatami(2,12,UP);
	
	tatami(3,8,UP_DOWN);
	tatami(3,9,LEFT);
	tatami(3,10,LEFT);
	tatami(3,11,DOWN);
	tatami(3,12,UP);

	tatami(4,8,LEFT);
	tatami(4,9,DOWN);
	tatami(4,10,UP);
	tatami(4,11,RIGHT);
	tatami(4,12,RIGHT);

	tatami(5,8,DOWN);
	tatami(5,9,LEFT_RIGHT);
	tatami(5,10,UP);
	tatami(5,11,LEFT);
	tatami(5,12,UP_DOWN);

	tatami(6,8,RIGHT);
	tatami(6,9,RIGHT);
	tatami(6,10,DOWN);
	tatami(6,11,UP);
	tatami(6,12,LEFT);

	tatami(7,8,LEFT);
	tatami(7,9,LEFT);
	tatami(7,10,DOWN);
	tatami(7,11,LEFT_RIGHT);
	tatami(7,12,UP);

	tatami(8,8,DOWN);
	tatami(8,9,LEFT_RIGHT);
	tatami(8,10,UP);
	tatami(8,11,RIGHT);
	tatami(8,12,RIGHT);

	tatami(9,9,RIGHT);
	tatami(9,10,RIGHT);
	tatami(9,11,LEFT);
	tatami(9,12,LEFT);

	tatami(10,9,LEFT);
	tatami(10,10,LEFT);
	tatami(10,11,DOWN);
	tatami(10,12,UP);
	
	//桌椅
	//seat(5,9);//ok
	//seat(6,9);
	table(5,10);
	//seat(4,10);
	//seat(7,10);
	//seat(5,11);
	//seat(6,11);
	
	trashbin(2,9);
	
	
	
	
	
	//	会客室
	for(i=6;i<=16;i++){
		for(j=15;j<=18;j++){
			red(i,j);
		}
	}

	trashbin(16,18);
	rect_table(12,16);
	
	
	//	连接踏板
	step(1,10);
	
	
	
	//	起居室的墙
	w_blue(2,7);
	w_blue(3,7);
	w_blue(4,7);
	w_blue(5,7);
	w_blue(6,7);
	w_blue(7,7);
	w_blue(8,7);
	w_blue(9,7);
	w_blue(10,7);
	
	TV(4,8);//ok
	
	//	会客室的墙
	w_blue(6,14);
	w_blue(7,14);
	w_blue(8,14);
	w_blue(9,14);
	w_blue(10,14);
	w_blue(11,14);
	w_blue(12,14);
	w_blue(13,14);
	//w_blue(14,14);
	w_blue(15,14);
	w_blue(16,14);
	
	//空调
	if(CheckHouse(4) == 0)//check aircon[2]
	{
		aircon(12,14,0);
	}
	else
	{
		aircon(12,14,1);
	}
	
	/*
	//window
	window_close(10,14);*/

	//	卧室的墙
	w_blue(3,2);
	w_blue(4,2);
	w_blue(5,2);
	w_blue(6,2);
	w_blue(7,2);
	w_blue(8,2);
	w_blue(9,2);
	w_blue(10,2);
	
	//窗
	if(CheckHouse(1) == 0)//check win
	{
		window_close(8,2);
	}
	else
	{
		window_open(8,2);
	}

	
	//空调
	if(CheckHouse(2)==0)//check aircon[0]
	{
		aircon(4,2,0);
	}
	else
	{
		aircon(4,2,1);
	}
	
	
    //衣柜
	cupboard(9,3);
	cupboard(10,3);
	
	//	卫生间的墙
	w_blue(13,9);
	w_blue(14,9);
	w_blue(15,9);
	w_blue(16,9);
	w_blue(17,9);
	
	//	洗衣间的墙
	w_blue(13,6);
	w_blue(14,6);
	w_blue(15,6);
	w_blue(16,6);
	w_blue(17,6);
	
	//洗衣机
	WashMach(16,7);
	
	//	厨房的墙
	w_blue(11,1);
	w_blue(12,1);
	w_blue(13,1);
	w_blue(14,1);
	w_blue(15,1);
	w_blue(16,1);
	w_blue(17,1);
	w_blue(18,1);
	w_blue(19,1);
	
	
	if(CheckHouse(3)==0)//check aircon[1]
	{
		aircon(18,1,0);
	}
	else
	{
		aircon(18,1,1);
	}
	
	pc(14,2);
	
	

	//	走廊上方的墙
	w_blue(13,12);
	w_blue(14,12);
	w_blue(15,12);
	w_blue(16,12);
	w_blue(17,12);
	w_blue(18,12);
	w_blue(19,12);

	//	厨房边墙
	w_right(19,1);
	w_right(19,2);
	w_right(19,3);
	w_right(19,4);
	w_right(19,5);

	w_left(11,1);
	w_left(11,2);
	w_left(11,3);
	w_left(11,4);
	w_left(11,5);

	w_down(13,5);
	w_down(14,5);
	w_down(15,5);
	w_down(16,5);
	w_down(17,5);
	w_down(18,5);
	w_down(19,5);
	w_down(11,5);

	//	卧室边墙
	w_left(3,2);
	w_left(3,3);
	w_left(3,4);
	w_left(3,5);
	w_left(3,6);

	//	起居室边墙
	w_right(10,12);
	//w_right(10,11);
	w_right(10,10);
	w_right(10,7);
	w_right(10,8);

	
	w_left(2,7);
	w_left(2,8);
	w_left(2,9);
	//w_left(2,10);
	//w_left(2,11);
	w_left(2,12);
	
	w_down(2,12);
	w_down(3,12);
	w_down(4,12);
	w_down(5,12);
	w_down(6,12);
	w_down(7,12);
	w_down(8,12);
	w_down(9,12);
	w_down(10,12);
	
	
	//书架
	bookshelf(6,15);
	bookshelf(7,15);
	bookshelf(8,15);
	bookshelf(9,15);
	
	
	//	会客室边墙
	w_right(16,14);
	w_right(16,15);
	w_right(16,16);
	w_right(16,17);
	w_right(16,18);
	
	w_left(6,14);
	w_left(6,15);
	w_left(6,16);
	w_left(6,17);
	w_left(6,18);
	
	w_down(6,18);
	w_down(7,18);
	w_down(8,18);
	w_down(9,18);
	w_down(10,18);
	w_down(11,18);
	w_down(12,18);
	w_down(13,18);
	w_down(14,18);
	w_down(15,18);
	w_down(16,18);
	
	//	走廊边墙
	w_right(10,13);
	w_right(19,12);
	w_right(19,13);
	w_right(19,14);
	w_right(19,15);
	w_right(19,16);
	w_right(19,17);
	w_right(19,18);
	
	w_left(13,12);
	
	w_down(19,18);
	
	//	洗衣间与卫生间边墙
	w_right(17,11);
	w_right(17,10);
	w_right(17,9);
	w_right(17,8);
	w_right(17,7);
	w_right(17,6);
	
	w_left(13,11);
	//w_left(13,10);	
	w_left(13,9);
	w_left(13,8);
	// w_left(13,7);
	w_left(13,6);
	
	
	//	楼梯
	stairs(9,7);
}



	//	main
void _ground(void)
{
	int i,j,x,y;
	floor_G();
	for(i=1;i<=19;i++)
	{
		for(j=1;j<=19;j++)
		{
		    if(CheckCarry(i,j,1) == 1)
			{
				x = (i-1)*40;
				y = (j-1)*40;
				seat(x,y);
			}
		}
	}
	for(i=0;i<3;i++)
	{
		x = CheckHouse(9+i*2);
		y = CheckHouse(10+i*2);
		if(x!=0 && y!=0)
		{
			switch(i)
			{
				case 0:
				{
					trash1(x,y);
					break;
				}
				case 1:
				{
					trash2(x,y);
					break;
				}
				case 2:
				{
					trash3(x,y);
					break;
				}
			}
		}
	}
	
}




