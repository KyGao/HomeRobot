/******************函数清单***************************
1.  void comfort_ui(char *air1, char *air2, char *air3, char *H, char *PM, int value, int window);
2.	int iphcmfrt_click(int *mx,int *my,int *button);
3.	int match( int PM2);
4.	void window_button_on(int *flag);
5.	void window_button_off(int *flag);
6.	void window_check(int *flag);
7.	void temperature_subtract(int order);
8.	void temperature_add(int order);
9.	void airconditioner_blink(int x, int y, ROBOT_CASE *robot_position);
10.	void random_show(int air1, int air2, int air3, int PM, int H);
11.	void comfort_control(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y);
*****************************************************/
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

/******************

	手机界面
	
******************/
void comfort_ui(char *air1, char *air2, char *air3, char *H, char *PM, int value, int window)
{
	iph_frame(36410);

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
	bar_round_2(ORIGINX+180,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	
	
	/****************
		控制栏
	****************/
	//窗户
	bar(ORIGINX+4,ORIGINY+72,FINALX,ORIGINY+112,32313);		//121 198 204
	fdhz(ORIGINX+18,ORIGINY+77,2,2,"窗",65535);
	fdhz(ORIGINX+48,ORIGINY+77,2,2,"户",65535);
	//空调（主卧）
	bar(ORIGINX+4,ORIGINY+113,FINALX,ORIGINY+153,36410);		//138 198 210
	fdhz(ORIGINX+18,ORIGINY+118,2,2,"主",65535);
	fdhz(ORIGINX+48,ORIGINY+118,2,2,"卧",65535);
	fdhz(ORIGINX+78,ORIGINY+118,2,2,"空",65535);
	fdhz(ORIGINX+108,ORIGINY+118,2,2,"调",65535);
	//空调（客卧）
	bar(ORIGINX+4,ORIGINY+154,FINALX,ORIGINY+194,32313);		//138 198 210
	fdhz(ORIGINX+18,ORIGINY+159,2,2,"客",65535);
	fdhz(ORIGINX+48,ORIGINY+159,2,2,"卧",65535);
	fdhz(ORIGINX+78,ORIGINY+159,2,2,"空",65535);
	fdhz(ORIGINX+108,ORIGINY+159,2,2,"调",65535);
	//空调（客厅）
	bar(ORIGINX+4,ORIGINY+195,FINALX,ORIGINY+235,36410);		//138 198 210
	fdhz(ORIGINX+18,ORIGINY+200,2,2,"客",65535);
	fdhz(ORIGINX+48,ORIGINY+200,2,2,"厅",65535);
	fdhz(ORIGINX+78,ORIGINY+200,2,2,"空",65535);
	fdhz(ORIGINX+108,ORIGINY+200,2,2,"调",65535);
		
	/****************
		控制按钮
	****************/
	//窗户72——112
	if(window == 1)
	{
		bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313);
		bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,18221);
		FillCircle(ORIGINX+244-13, ORIGINY+81+11, 13, 65535);
	}
	else if(window == 0)
	{
		bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313); 
		bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,52825);
		FillCircle(ORIGINX+198+13, ORIGINY+81+11, 12, 65535);
	}
	//主卧113——153
	bar_round_2(ORIGINX+198,ORIGINY+122,ORIGINX+244,ORIGINY+144,11,1,65535);
	bar(ORIGINX+198+11,ORIGINY+122,ORIGINX+198+13,ORIGINY+144,36410);
	bar(ORIGINX+244-13,ORIGINY+122,ORIGINX+244-11,ORIGINY+144,36410);
	outtextxy(ORIGINX+198+10,ORIGINY+125,air1,1,1,8,0);
	bar(ORIGINX+198+2,ORIGINY+133,ORIGINX+198+9,ORIGINY+134,36410);//减号
	bar(ORIGINX+244-2,ORIGINY+133,ORIGINX+244-9,ORIGINY+134,36410);//加号
	bar(ORIGINX+244-5,ORIGINY+133-3,ORIGINX+244-6,ORIGINY+134+3,36410);//加号
	//客卧154——194
	bar_round_2(ORIGINX+198,ORIGINY+163,ORIGINX+244,ORIGINY+185,11,1,65535);
	bar(ORIGINX+198+11,ORIGINY+163,ORIGINX+198+13,ORIGINY+185,36410);
	bar(ORIGINX+244-13,ORIGINY+163,ORIGINX+244-11,ORIGINY+185,36410);
	outtextxy(ORIGINX+198+10,ORIGINY+166,air2,1,1,8,0);
	bar(ORIGINX+198+2,ORIGINY+174,ORIGINX+198+9,ORIGINY+175,36410);//减号
	bar(ORIGINX+244-2,ORIGINY+174,ORIGINX+244-9,ORIGINY+175,36410);//加号
	bar(ORIGINX+244-5,ORIGINY+174-3,ORIGINX+244-6,ORIGINY+175+3,36410);//加号
	//客厅195——235
	bar_round_2(ORIGINX+198,ORIGINY+204,ORIGINX+244,ORIGINY+226,11,1,65535);
	bar(ORIGINX+198+11,ORIGINY+204,ORIGINX+198+13,ORIGINY+226,36410);
	bar(ORIGINX+244-13,ORIGINY+204,ORIGINX+244-11,ORIGINY+226,36410);
	outtextxy(ORIGINX+198+10,ORIGINY+207,air3,1,1,8,0);
	bar(ORIGINX+198+2,ORIGINY+215,ORIGINX+198+9,ORIGINY+216,36410);//减号
	bar(ORIGINX+244-2,ORIGINY+215,ORIGINX+244-9,ORIGINY+216,36410);//加号
	bar(ORIGINX+244-5,ORIGINY+215-3,ORIGINX+244-6,ORIGINY+216+3,36410);//加号 
	
	/****************
		状态栏
	****************/
	//外框
	bar(ORIGINX+43,ORIGINY-30+275,ORIGINX+47,ORIGINY-30+490,65535);
	bar(ORIGINX+43,ORIGINY-30+273,ORIGINX+216,ORIGINY-30+277,65535);
	bar(ORIGINX+212,ORIGINY-30+275,ORIGINX+216,ORIGINY-30+490,65535);
	bar(ORIGINX+43,ORIGINY-30+490,ORIGINX+216,ORIGINY-30+494,65535);
	//内框
	bar(ORIGINX+47,ORIGINY-30+277,ORIGINX+212,ORIGINY-30+314,65535);
	bar(ORIGINX+47,ORIGINY-30+314,ORIGINX+212,ORIGINY-30+318,65535);
	bar(ORIGINX+47,ORIGINY-30+345,ORIGINX+212,ORIGINY-30+347,65535);
	bar(ORIGINX+47,ORIGINY-30+374,ORIGINX+212,ORIGINY-30+376,65535);
	bar(ORIGINX+47,ORIGINY-30+403,ORIGINX+212,ORIGINY-30+405,65535);
	bar(ORIGINX+47,ORIGINY-30+432,ORIGINX+212,ORIGINY-30+434,65535);
	bar(ORIGINX+47,ORIGINY-30+461,ORIGINX+212,ORIGINY-30+463,65535);
	//填字
	fdhz(ORIGINX+70,ORIGINY-30+280,2,2,"状",28153);
	fdhz(ORIGINX+110,ORIGINY-30+280,2,2,"态",28153);
	fdhz(ORIGINX+150,ORIGINY-30+280,2,2,"栏",28153);
	
	fdhz(ORIGINX+50,ORIGINY-30+322,1,1,"主",65535);
	fdhz(ORIGINX+70,ORIGINY-30+322,1,1,"卧",65535);
	fdhz(ORIGINX+90,ORIGINY-30+322,1,1,"温",65535);
	fdhz(ORIGINX+110,ORIGINY-30+322,1,1,"度",65535);
	
	fdhz(ORIGINX+50,ORIGINY-30+351,1,1,"客",65535);
	fdhz(ORIGINX+70,ORIGINY-30+351,1,1,"卧",65535);
	fdhz(ORIGINX+90,ORIGINY-30+351,1,1,"温",65535);
	fdhz(ORIGINX+110,ORIGINY-30+351,1,1,"度",65535);
	
	fdhz(ORIGINX+50,ORIGINY-30+380,1,1,"客",65535);
	fdhz(ORIGINX+70,ORIGINY-30+380,1,1,"厅",65535);
	fdhz(ORIGINX+90,ORIGINY-30+380,1,1,"温",65535);
	fdhz(ORIGINX+110,ORIGINY-30+380,1,1,"度",65535);
	
	fdhz(ORIGINX+50,ORIGINY-30+409,1,1,"湿",65535);
	fdhz(ORIGINX+70,ORIGINY-30+409,1,1,"度",65535);
	
	outtextxy(ORIGINX+40,ORIGINY-30+438,"PM2.5",1,1,12,65535);

	fdhz(ORIGINX+50,ORIGINY-30+467,1,1,"空",65535);	
	fdhz(ORIGINX+70,ORIGINY-30+467,1,1,"气",65535);
	fdhz(ORIGINX+90,ORIGINY-30+467,1,1,"质",65535);
	fdhz(ORIGINX+110,ORIGINY-30+467,1,1,"量",65535);
	
	/****************
		状态栏示数
	****************/
	outtextxy(ORIGINX+180,ORIGINY-30+322,air1,1,1,12,65535);
	outtextxy(ORIGINX+180,ORIGINY-30+351,air2,1,1,12,65535);
	outtextxy(ORIGINX+180,ORIGINY-30+380,air3,1,1,12,65535);
	outtextxy(ORIGINX+180,ORIGINY-30+409,H,1,1,12,65535);
	outtextxy(ORIGINX+168,ORIGINY-30+438,PM,1,1,12,65535);
	if(value == 1){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  优",65535);
	}
	else if(value == 2){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  良",65535);
	}
	else if(value == 3){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"轻度污染",65535);
	}
	else if(value == 4){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"中度污染",65535);
	}
	else if(value == 5){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"重度污染",65535);
	}
	else if(value == 6){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"严重污染",65535);
	}
	
}

/******************

	鼠标点击位置检测 
	
******************/
int iphcmfrt_click(int *mx,int *my,int *button)
 {
	 /*********
	按钮位置标准化
	将所有可能的按钮位置坐标储存在二维数组中
	*********/
	int a[9][4];
	a[0][0] = 0;	//	a[0][]:点击左上角退出程序
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	
	a[1][0] = ORIGINX+198;		//	a[1][]:点击窗户开关按钮 	①窗户按钮变化②机器人移动④湿度响应，PM2.5响应	
	a[1][1] = ORIGINX+244;
	a[1][2] = ORIGINY+81;
	a[1][3] = ORIGINY+103;
	
	a[2][0] = ORIGINX+198;		//	a[2][]:点击主卧空调【-】	①按钮数字变化②状态栏数值响应④空调闪红闪绿⑥PM2.5降低响应 	
	a[2][1]	= ORIGINX+198+11;
	a[2][2]	= ORIGINY+122;
	a[2][3] = ORIGINY+144;
	
	a[3][0] = ORIGINX+244-11;		//	a[3][]:点击主卧空调【+】	
	a[3][1]	= ORIGINX+244;
	a[3][2]	= ORIGINY+122;
	a[3][3] = ORIGINY+144;
	
	a[4][0] = ORIGINX+198;		//	a[4][]:点击客卧空调【-】			
	a[4][1]	= ORIGINX+198+11;
	a[4][2]	= ORIGINY+163;
	a[4][3] = ORIGINY+185;	
	
	a[5][0] = ORIGINX+244-11;		//	a[5][]:点击客卧空调【+】	
	a[5][1]	= ORIGINX+244;
	a[5][2]	= ORIGINY+163;
	a[5][3] = ORIGINY+185;
	
	a[6][0] = ORIGINX+198;		//	a[6][]:点击客厅空调【-】				
	a[6][1]	= ORIGINX+198+11;
	a[6][2]	= ORIGINY+204;
	a[6][3] = ORIGINY+226;	

	a[7][0] = ORIGINX+244-11;		//	a[7][]:点击客厅空调【+】				
	a[7][1]	= ORIGINX+244;
	a[7][2]	= ORIGINY+204;
	a[7][3] = ORIGINY+226;

	a[8][0] = ORIGINX+100;		//	a[7][]:点击【主页】回到主页				
	a[8][1]	= ORIGINX+155;
	a[8][2]	= ORIGINY+485;
	a[8][3] = ORIGINY+535;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && *button)	return 1;   //if(鼠标点击退出区域)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && *button)	return 2;   //if(鼠标点击【窗户】)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && *button)	return 3;   //if(鼠标点击主卧空调【-】)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && *button)	return 4;   //if(鼠标点击主卧空调【+】)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && *button)	return 5; 	//if(鼠标点击客卧空调【-】)
	else if (*mx >= a[5][0] && *mx <= a[5][1] && *my >= a[5][2] && *my <= a[5][3] && *button)	return 6;   //if(鼠标点击客卧空调【+】)
	else if (*mx >= a[6][0] && *mx <= a[6][1] && *my >= a[6][2] && *my <= a[6][3] && *button)	return 7;   //if(鼠标点击客厅空调【-】)
	else if (*mx >= a[7][0] && *mx <= a[7][1] && *my >= a[7][2] && *my <= a[7][3] && *button)	return 8; 	//if(鼠标点击客厅空调【+】)
	else if (*mx >= a[8][0] && *mx <= a[8][1] && *my >= a[8][2] && *my <= a[8][3] && *button)	return 9; 	//if(鼠标点击【主页】)
	else return 0;
 }

/******************

	将PM2.5的值与空气质量相匹配

******************/
int match( int PM2)
 {
	if(PM2 <50){
		return 1;
	}
	else if(PM2 >=50  && PM2 <100){
		return 2;
	}
	else if(PM2 >=100 && PM2 <150){
		return 3;
	}
	else if(PM2 >=150 && PM2 <200){
		return 4;
	}
	else if(PM2 >=200 && PM2 <300){
		return 5;
	}
	else if(PM2 >=300){
		return 6;
	}
 }

/******************

	窗户开启和关闭的按钮状态 
	
******************/ 
void window_button_on(int *flag)
 {
	bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313);
	bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,18221);
	FillCircle(ORIGINX+244-13, ORIGINY+81+11, 13, 65535);
	*flag = 1;	//标记窗户是开启状态
 }
 
/******************

	窗户开启和关闭的按钮状态 
	
******************/ 
void window_button_off(int *flag)
 {
	bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313); 
	bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,52825);
	FillCircle(ORIGINX+198+13, ORIGINY+81+11, 12, 65535);
	*flag = 0;	//标记窗户是关闭状态
 }
 
 /******************

	窗户开关在手机界面的响应 
	
******************/
 void window_check(int *flag)
 {
 	if(*flag)
	{//开着	所以要关闭
		window_button_off(flag);
		
		ChangeHouse(1,0);
		ChangeHouse(5,-100);			//	关窗会降低PM2.5
		ChangeHouse(7,-20);			//	关窗会降低湿度
	}
	else
	{//关着 所以要开启
		window_button_on(flag);
	
		ChangeHouse(1,1);
		ChangeHouse(5,100);			//	开窗会增加PM2.5
		ChangeHouse(7,20);			//	开窗会增加湿度
	}
 }

 /******************

	降低空调温度の按钮变化 
	
******************/
void temperature_subtract(int order)
{
	int delta_y = 41;	//偏移量
	int delta_num = order-1;	//作为偏移的参考数量
	int func_num = order+1;		//作为changehouse的输入值
	char set_temperature[3] ;		//显示温度时用
	
	ChangeHouse(func_num,-1);	//文件修改
	//画图显示
	bar(ORIGINX+198+13,ORIGINY+122+delta_y*delta_num,ORIGINX+244-13,ORIGINY+144+delta_y*delta_num,65535);
	itoa(CheckHouse(func_num),set_temperature,10);
	set_temperature[2] = '\0';
	outtextxy(ORIGINX+198+10,ORIGINY+125+delta_y*delta_num,set_temperature,1,1,8,0);
}

/******************

	升高空调温度の按钮变化 
	
******************/
void temperature_add(int order)
{
	int delta_y = 41;	//偏移量
	int delta_num = order-1;	//作为偏移的参考数量
	int func_num = order+1;		//作为changehouse的输入值
	char set_temperature[3] ;		//显示温度时用
	
	ChangeHouse(func_num,1);	//文件修改
	//画图显示
	bar(ORIGINX+198+13,ORIGINY+122+delta_y*delta_num,ORIGINX+244-13,ORIGINY+144+delta_y*delta_num,65535);
	itoa(CheckHouse(func_num),set_temperature,10);
	set_temperature[2] = '\0';
	outtextxy(ORIGINX+198+10,ORIGINY+125+delta_y*delta_num,set_temperature,1,1,8,0);
}
 
/******************

	空调动画，闪烁一下 
	
******************/
void airconditioner_blink(int x, int y, ROBOT_CASE *robot_position)
{
	if((*robot_position).position == 1)
	{
		aircon(x,y,0);
		delay(50);
		aircon(x,y,1);
	}
}	

/******************

	状态栏信息随机显示 
	
******************/
void random_show(int air1, int air2, int air3, int PM, int H)
{
	int  interval;		//波动区间
	char aircon1[3],aircon2[3],aircon3[3];
	char PM_show[4],H_show[3];
	
	srand((unsigned)(time(NULL)));
	
	//主卧温度状态显示
	interval = -1+rand()%3;	//生成波动区间
	air1 += interval;	//波动赋值
	itoa(air1, aircon1, 10);	//将数值转换为字符串
	aircon1[2] = '\0';	//二次保险
	bar(ORIGINX+180,ORIGINY-30+322,ORIGINX+210,ORIGINY-30+342,36410);	//清空之前显示
	outtextxy(ORIGINX+180,ORIGINY-30+322,aircon1,1,1,12,65535);	//print
	//客卧温度状态显示
	interval = -1+rand()%3;	//生成波动区间
	air2 += interval;	//波动赋值
	itoa(air2, aircon2, 10);	//将数值转换为字符串
	aircon2[2] = '\0';	//二次保险
	bar(ORIGINX+180,ORIGINY-30+351,ORIGINX+210,ORIGINY-30+371,36410);	//清空之前显示
	outtextxy(ORIGINX+180,ORIGINY-30+351,aircon2,1,1,12,65535);	//print
	//客厅温度状态显示
	interval = -1+rand()%3;	//生成波动区间
	air3 += interval;	//波动赋值
	itoa(air3, aircon3, 10);	//将数值转换为字符串
	aircon3[2] = '\0';	//二次保险
	bar(ORIGINX+180,ORIGINY-30+380,ORIGINX+210,ORIGINY-30+400,36410);	//清空之前显示
	outtextxy(ORIGINX+180,ORIGINY-30+380,aircon3,1,1,12,65535);	//print
	//湿度状态显示
	interval = -1+rand()%9;	//生成波动区间
	H += interval;	//波动赋值
	itoa(H, H_show, 10);	//将数值转换为字符串
	H_show[2] = '\0';	//二次保险
	bar(ORIGINX+180,ORIGINY-30+409,ORIGINX+210,ORIGINY-30+429,36410);	//清空之前显示	
	outtextxy(ORIGINX+180,ORIGINY-30+409,H_show,1,1,12,65535);	//print
	//PM2.5状态显示
	interval = -1+rand()%199;	//生成波动区间
	PM += interval;	//波动赋值
	itoa(PM, PM_show, 10);	//将数值转换为字符串
	PM_show[3] = '\0';	//二次保险
	bar(ORIGINX+168,ORIGINY-30+438,ORIGINX+210,ORIGINY-30+458,36410);	//清空之前显示
	outtextxy(ORIGINX+168,ORIGINY-30+438,PM_show,1,1,12,65535);	//print
	//空气质量显示
	//match(str,PM);	//根据PM2.5的值判断空气质量
	bar(ORIGINX+140,ORIGINY-30+467,ORIGINX+210,ORIGINY-30+487,36410);	//清空之前显示
	if(match(PM) == 1){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  优",65535);
	}
	else if(match(PM) == 2){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  良",65535);
	}
	else if(match(PM) == 3){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"轻度污染",65535);
	}
	else if(match(PM) == 4){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"中度污染",65535);
	}
	else if(match(PM) == 5){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"重度污染",65535);
	}
	else if(match(PM) == 6){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"严重污染",65535);
	}

}

/******************

	整个舒适功能的主逻辑 
	
******************/
void comfort_control(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y)
{
	int buttons;
	int state = 1;//如果点击主页之后state变为0，退出循环
	int click;	//记录鼠标状态flag
	int window = CheckHouse(1);	//记录窗户开关状态
	int PM2 = CheckHouse(5);	//初始化PM2.5的值
	char main_room_temperature[3],guest_room_temperature[3],living_room_temperature[3],H[3],PM[4];
	int ranran;
	
	//转换成可以输出的字符串
	itoa(CheckHouse(2),main_room_temperature,10);
	itoa(CheckHouse(3),guest_room_temperature,10);
	itoa(CheckHouse(4),living_room_temperature,10);
	itoa(CheckHouse(7),H,10);
	itoa(PM2,PM,10);

	
	//二次保险
	main_room_temperature[2] = '\0';
	guest_room_temperature[2] = '\0';
	living_room_temperature[2] = '\0';
	H[2] = '\0';
	PM[3] = '\0';
	
	ranran = match(PM2);
	mousehide(*x,*y);
	comfort_ui(main_room_temperature,guest_room_temperature,living_room_temperature,H,PM,ranran,window);
	
	
	
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&buttons);
		
		//状态栏示数
		random_show(CheckHouse(2),CheckHouse(3),CheckHouse(4),CheckHouse(5),CheckHouse(7));
		
		click = iphcmfrt_click(x,y,&buttons);
		switch(click)
		{
			case 0:	
					break;
			case 1:
					exit(1);
					break;
			case 2:
					if(window == 1){
						ranran = 0;
					}
					else{
						ranran = 1;
					}
					mousehide(*x,*y);
					window_check(&window);		//窗户按钮变化
					reset_mouse(x,y);
					open_window(robot_position,save,ranran,x,y);
					break;
			case 3:		//主卧
					temperature_subtract(1);//手机界面
					airconditioner_blink(4,2,robot_position);		//空调动画
					break;
			case 4:		//主卧
					temperature_add(1);			//手机界面
					airconditioner_blink(4,2,robot_position);		//空调动画
					break;
			case 5:		//客卧
					temperature_subtract(2);	//手机界面
					airconditioner_blink(18,1,robot_position);		//空调动画
					break;
			case 6:		//客卧
					temperature_add(2);		//手机界面
					airconditioner_blink(18,1,robot_position);		//空调动画
					break;
			case 7:		//客厅
					temperature_subtract(3);	//手机界面
					airconditioner_blink(12,14,robot_position);		//空调动画
					break;
			case 8:		//客厅
					temperature_add(3);		//手机界面
					airconditioner_blink(12,14,robot_position);		//空调动画
					break;
			case 9:		//主页
					ph_main();	//回去
					state = 0;	//可退出此鼠标检测循环
					break;
		}
		
		
		//判断是否可以退出循环
		if(state == 0){
			break;
		}
	}
		//回去
}

