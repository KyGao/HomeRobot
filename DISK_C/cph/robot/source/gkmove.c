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
#define SCREENCENTER_x 894 
#define SCREENCENTER_y 493
#define SCREENLENGTH 250 
#define SCREENHEIGHT 541
#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764
//	界面框架
void remote_interface()
{
	iph_frame(36410);
	/**************
	界面背景
	**************
	FillCircle(ORIGINX+77,ORIGINY+124,60,32313);
	fill_bow_left_up(ORIGINX+250,ORIGINY+375,120,36410);
	fill_bow_left_down(ORIGINX+250,ORIGINY+375,120,36410);?
	
	
	/********
	底部导航栏
	********/

	bar_round_2(ORIGINX+3,ORIGINY+473,ORIGINX+252,ORIGINY+542,30,1,36410);	//138 198 210
	
	//熊爪图标
	FillCircle(ORIGINX+24, ORIGINY+503, 5, 65535);
	FillCircle(ORIGINX+37, ORIGINY+491, 5, 65535);
	FillCircle(ORIGINX+55, ORIGINY+491, 5, 65535);
	FillCircle(ORIGINX+69, ORIGINY+503, 5, 65535);
	bar_round_2(ORIGINX+31,ORIGINY+502,ORIGINX+64,ORIGINY+529,10,1,65535);
	//主页图标（双圆环
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	/*聊天气泡
	FillCircle(ORIGINX+178, ORIGINY+529, 4, 65535);
	FillCircle(ORIGINX+183, ORIGINY+514, 7, 65535);
	bar_round_2(ORIGINX+190,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	*/
	
	
	/************
	遥控界面
	************/
	fdhz(ORIGINX+18,ORIGINY+58,2,2,"远",65535);
	fdhz(ORIGINX+48,ORIGINY+58,2,2,"程",65535);
	fdhz(ORIGINX+78,ORIGINY+58,2,2,"操",65535);
	fdhz(ORIGINX+108,ORIGINY+58,2,2,"控",65535);
		
	//中心熊爪
	FillCircle(ORIGINX+24+83, ORIGINY+503-234, 5, 65535);
	FillCircle(ORIGINX+37+83, ORIGINY+491-234, 5, 65535);
	FillCircle(ORIGINX+55+83, ORIGINY+491-234, 5, 65535);
	FillCircle(ORIGINX+69+83, ORIGINY+503-234, 5, 65535);
	bar_round_2(ORIGINX+31+83,ORIGINY+502-234,ORIGINX+64+83,ORIGINY+529-234,10,1,65535);
	
	//方向操控
	bar(ORIGINX+91,ORIGINY+167,ORIGINX+161,ORIGINY+237,65535);	//上
	
	bar(ORIGINX+91,ORIGINY+309,ORIGINX+161,ORIGINY+379,65535);	//下
	
	bar(ORIGINX+20,ORIGINY+238,ORIGINX+90,ORIGINY+308,65535);	//左
	
	bar(ORIGINX+162,ORIGINY+238,ORIGINX+232,ORIGINY+308,65535);	//右
	
}

//鼠标检测函数
int remote_click(int *mx,int *my,int button)
 {
	 /*********
	按钮位置标准化
	将所有可能的按钮位置坐标储存在二维数组中
	*********/
	int a[8][4];
	a[0][0] = 0;	//	a[0][]:点击左上角退出程序
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	
	a[1][0] = ORIGINX+100;		//	a[1][]:点击主页 进入主页	
	a[1][1] = ORIGINX+155;
	a[1][2] = ORIGINY+485;
	a[1][3] = ORIGINY+535;
	
	a[2][0] = ORIGINX+175;		//	a[2][]:点击气泡 进入聊天界面	
	a[2][1]	= ORIGINX+225;
	a[2][2]	= ORIGINY+486;
	a[2][3] = ORIGINY+530;
	
	a[3][0] = ORIGINX+91;		//	a[3][]:点击【上】功能			
	a[3][1]	= ORIGINX+161;
	a[3][2]	= ORIGINY+167;
	a[3][3] = ORIGINY+237;
	
	a[4][0] = ORIGINX+91;		//	a[4][]:点击【下】功能					
	a[4][1]	= ORIGINX+161;
	a[4][2]	= ORIGINY+309;
	a[4][3] = ORIGINY+379;	
	
	a[5][0] = ORIGINX+20;		//	a[5][]:点击【左】功能			
	a[5][1]	= ORIGINX+90;
	a[5][2]	= ORIGINY+238;
	a[5][3] = ORIGINY+308;
	
	a[6][0] = ORIGINX+162;		//	a[6][]:点击【右】功能				
	a[6][1]	= ORIGINX+232;
	a[6][2]	= ORIGINY+238;
	a[6][3] = ORIGINY+308;	

	a[7][0] = ORIGINX+91;		//	a[7][]:点击【熊爪】按钮进行操作					
	a[7][1]	= ORIGINX+161;
	a[7][2]	= ORIGINY+238;
	a[7][3] = ORIGINY+308;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && button)	return 1;   //if(鼠标点击退出区域)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && button)	return 2;   //if(鼠标点击主页 进入主页)
	//else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && button)	return 3;   //if(鼠标点击气泡 进入聊天界面)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && button)	return 4;   //if(鼠标点击【上】功能)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && button)	return 5; 	//if(鼠标点击【下】功能)
	else if (*mx >= a[5][0] && *mx <= a[5][1] && *my >= a[5][2] && *my <= a[5][3] && button)	return 6;   //if(鼠标点击【左】功能)
	else if (*mx >= a[6][0] && *mx <= a[6][1] && *my >= a[6][2] && *my <= a[6][3] && button)	return 7;   //if(鼠标点击【右】功能)
	//else if (*mx >= a[7][0] && *mx <= a[7][1] && *my >= a[7][2] && *my <= a[7][3] && button)	return 8; 	//if(鼠标点击【熊爪】操作)
	
    else return 0;
 }
 
int move_one_step(ROBOT_CASE *robot_position,int *x,int *y)
{
	int button = 0,judge;
	mousehide(*x,*y);
	remote_interface();
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		judge = remote_click(x,y,button);
		
		switch(judge)
		{
			case 1:
			{
				exit(0);
			}
			case 2:
			{
				mousehide(*x,*y);
				ph_main();
				reset_mouse(x,y);
				return -2;
			}
			case 4:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//挡掉“被挡住了哦”
				if(CheckMove((*robot_position).x+1,(*robot_position).y+0,(*robot_position).position)==1)	//向上走可以走吗
				{
					(*robot_position).direction = 3;	//3代表上
					move0(robot_position,x,y);		//走一步
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"被挡住了哦",65535);
				}
				break;
			}
			case 5:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//挡掉“被挡住了哦”
				if(CheckMove((*robot_position).x+1,(*robot_position).y+2,(*robot_position).position) == 1)	//向下走可以走吗
				{
					(*robot_position).direction = 4;	//4代表下
					move0(robot_position,x,y);		//走一步
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"被挡住了哦",65535);
				}
				break;
			}
			case 6:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//挡掉“被挡住了哦”
				if(CheckMove((*robot_position).x,(*robot_position).y+1,(*robot_position).position) == 1)	//向左走可以走吗
				{
					(*robot_position).direction = 2;	//2代表左
					move0(robot_position,x,y);		//走一步
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"被挡住了哦",65535);
				}
				break;
			}
			case 7:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//挡掉“被挡住了哦”
				if(CheckMove((*robot_position).x+2,(*robot_position).y+1,(*robot_position).position) == 1)		//向右走可以走吗
				{
					(*robot_position).direction = 1;	//1代表右
					move0(robot_position,x,y);		//走一步
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"被挡住了哦",65535);
				}
				break;
			}

		}
	}
	
}
void tri(int x,int y,int di)
{
	switch(di)
	{
		case 1:
		{
			triangleleft(x,y,10,0);
			bar(x,y-5,x+5,y+5,0);
		}
		case 2:
		{
			triangleright(x,y,10,0);
			bar(x,y-5,x+5,y+5,0);
		}
		case 3:
		{
			triangle2(x,y,10,0);
			bar(x-5,y,x+5,y+20,0);
		}
		case 4:
		{
			triangledown(x,y,10,0);
			bar(x-5,y,x+5,y-20,0);
		}
	}
}