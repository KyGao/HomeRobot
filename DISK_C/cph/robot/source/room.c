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
	
	
void charge_stop(void)
{
	FillCircle(9*40+20, 9*40+4+20, 10, 65535);
	FillCircle(9*40+20, 9*40+4+20, 8, 0);
	FillCircle(9*40+20, 9*40+4+20, 6, 65535);
}

/******
地形
******/
void floor_R(void)
{
	int i,j;
	

	
	//	走廊
	for(i=1;i<=6;i++){
		for(j=5;j<=7;j++){
			wood_hor(i, j);	
		}
	}
	
	//	房间
	tatami(1,8,DOWN);
	tatami(1,9,UP);
	tatami(1,10,DOWN);
	tatami(1,11,LEFT_RIGHT);
	tatami(1,12,UP);
	
	tatami(2,8,RIGHT);
	tatami(2,9,RIGHT);
	tatami(2,10,RIGHT);
	tatami(2,11,DOWN);
	tatami(2,12,UP);
	
	tatami(3,8,UP_DOWN);
	tatami(3,9,UP_DOWN);
	tatami(3,10,LEFT);
	tatami(3,11,RIGHT);
	tatami(3,12,RIGHT);

	tatami(4,8,LEFT);
	tatami(4,9,LEFT);
	tatami(4,10,RIGHT);
	tatami(4,11,LEFT);
	tatami(4,12,LEFT);

	tatami(5,8,DOWN);
	tatami(5,9,UP);
	tatami(5,10,UP_DOWN);
	tatami(5,11,DOWN);
	tatami(5,12,UP);

	tatami(6,8,DOWN);
	tatami(6,9,UP);
	tatami(6,10,LEFT);
	tatami(6,11,RIGHT);
	tatami(6,12,RIGHT);

	tatami(7,8,DOWN);
	tatami(7,9,LEFT_RIGHT);
	tatami(7,10,UP);
	tatami(7,11,LEFT);
	tatami(7,12,LEFT);

	//桌子
	rect_table(4,10);
	seat1(3,10);
	seat2(6,10);
	seat3(4,9);
	seat4(4,12);
	
	//哆啦A梦衣柜
	closet(8, 10);
	for(i=9;i<=10;i++){
		for(j=8;j<=12;j++){
			closet(i,j);
		}
	}
	
	//	走廊的墙
	w_blue(1,4);
	w_blue(2,4);
	w_blue(3,4);
	w_blue(4,4);
	w_blue(5,4);	
	w_blue(6,4);

	//	房间的墙
	w_blue(1,7);
	w_blue(2,7);
	w_blue(3,7);
	//w_blue(4,7);
	// w_blue(5,7);
	w_blue(6,7);
	w_blue(7,7);

	//衣柜的墙
	w_blue(9,7);
	w_blue(10,7);
	w_blue(8,9);
		
		
		//	楼梯
	stairs(7,5);
	
	charge_stop();
}
	
	
	
	//	main
void _room(void)
{
	floor_R();
	charge_stop();
}
