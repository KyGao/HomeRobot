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
#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764


//	界面框架
void main_interface(void)
{
	/********
	界面背景
	********/
	FillCircle(ORIGINX+200,ORIGINY+157,40,36410);	//138 198 210
	fill_bow_right_up(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	fill_bow_right_down(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	
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
	//聊天气泡
	FillCircle(ORIGINX+178, ORIGINY+529, 4, 65535);
	FillCircle(ORIGINX+183, ORIGINY+514, 7, 65535);
	bar_round_2(ORIGINX+190,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	
	/********
	功能按钮
	********/
	//卫生
	bar_round_2(ORIGINX+15,ORIGINY+300,ORIGINX+126,ORIGINY+372,10,1,65535);
	fdhz(ORIGINX+25,ORIGINY+315,3,3,"卫",28153);	//107 190 202
	fdhz(ORIGINX+74,ORIGINY+315,3,3,"生",28153);	//107 190 202
	//舒适
	bar_round_2(ORIGINX+130,ORIGINY+300,ORIGINX+242,ORIGINY+372,10,1,65535);
	fdhz(ORIGINX+140,ORIGINY+315,3,3,"舒",28153);	//107 190 202
	fdhz(ORIGINX+189,ORIGINY+315,3,3,"适",28153);	//107 190 202
	//安全(应改为便捷)
	bar_round_2(ORIGINX+15,ORIGINY+377,ORIGINX+126,ORIGINY+449,10,1,65535);
	fdhz(ORIGINX+25,ORIGINY+389,3,3,"便",28153);	//107 190 202
	fdhz(ORIGINX+74,ORIGINY+389,3,3,"捷",28153);	//107 190 202
	//充电
	bar_round_2(ORIGINX+130,ORIGINY+377,ORIGINX+242,ORIGINY+449,10,1,65535);
	fdhz(ORIGINX+140,ORIGINY+389,3,3,"安",28153);	//107 190 202
	fdhz(ORIGINX+189,ORIGINY+389,3,3,"全",28153);	//107 190 202
	//状态
	bar_round_2(ORIGINX+188,ORIGINY+52,ORIGINX+242,ORIGINY+72,10,1,65535);
	fdhz(ORIGINX+195,ORIGINY+52,1,1,"充",28153);	//107 190 202
	fdhz(ORIGINX+215,ORIGINY+52,1,1,"电",28153);	//107 190 202
	
	/*************
	文字状态
	*************/
	fdhz(ORIGINX+12,ORIGINY+108,3,3,"我",65535);
	fdhz(ORIGINX+62,ORIGINY+108,3,3,"的",65535);
	fdhz(ORIGINX+112,ORIGINY+108,3,3,"家",65535);
	
}

int iphmain_click(int *mx,int *my,int *button)
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
	
	a[1][0] = ORIGINX+20;		//	a[1][]:点击熊爪 进入遥控状态	
	a[1][1] = ORIGINX+73;
	a[1][2] = ORIGINY+486;
	a[1][3] = ORIGINY+530;
	
	a[2][0] = ORIGINX+175;		//	a[2][]:点击气泡 进入聊天界面	
	a[2][1]	= ORIGINX+225;
	a[2][2]	= ORIGINY+486;
	a[2][3] = ORIGINY+530;
	
	a[3][0] = ORIGINX+15;		//	a[3][]:点击【卫生】功能		垃圾,除草	
	a[3][1]	= ORIGINX+126;
	a[3][2]	= ORIGINY+300;
	a[3][3] = ORIGINY+372;
	
	a[4][0] = ORIGINX+130;		//	a[4][]:点击【舒适】功能		空调，窗			
	a[4][1]	= ORIGINX+242;
	a[4][2]	= ORIGINY+300;
	a[4][3] = ORIGINY+372;	
	
	a[5][0] = ORIGINX+15;		//	a[5][]:点击【安全/便捷】功能		搬椅子，拿书	
	a[5][1]	= ORIGINX+126;
	a[5][2]	= ORIGINY+377;
	a[5][3] = ORIGINY+449;
	
	a[6][0] = ORIGINX+130;		//	a[6][]:点击【充电】功能					
	a[6][1]	= ORIGINX+242;
	a[6][2]	= ORIGINY+377;
	a[6][3] = ORIGINY+449;	

	a[7][0] = ORIGINX+188;		//	a[7][]:点击【状态】查询					
	a[7][1]	= ORIGINX+242;
	a[7][2]	= ORIGINY+52;
	a[7][3] = ORIGINY+72;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && *button)	return 1;   //if(鼠标点击退出区域)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && *button)	return 2;   //if(鼠标点击熊爪 进入遥控状态)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && *button)	return 3;   //if(鼠标点击气泡 进入聊天界面)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && *button)	return 4;   //if(鼠标点击【卫生】功能)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && *button)	return 5; 	//if(鼠标点击【舒适】功能)
	else if (*mx >= a[5][0] && *mx <= a[5][1] && *my >= a[5][2] && *my <= a[5][3] && *button)	return 6;   //if(鼠标点击【便捷】功能)
	else if (*mx >= a[6][0] && *mx <= a[6][1] && *my >= a[6][2] && *my <= a[6][3] && *button)	return 7;   //if(鼠标点击【充电】功能)
	else if (*mx >= a[7][0] && *mx <= a[7][1] && *my >= a[7][2] && *my <= a[7][3] && *button)	return 8; 	//if(鼠标点击【状态】查询)
	//else if (*button)																			return 9;	//if(鼠标点击其他区域)
    else return 0;
 }
 
 void ph_main(void)
 {
	iph_frame(28153);
	main_interface();
 }