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

#define ROBOTx 894
#define ROBOTy 404


//	界面框架
void checkin_interface(unsigned int *text1save,unsigned int *text2save)
{
	
	/**************
	界面背景
	**************/
	FillCircle(ORIGINX+77,ORIGINY+124,60,32313);
	fill_bow_left_up(ORIGINX+250,ORIGINY+375,120,36410);
	fill_bow_left_down(ORIGINX+250,ORIGINY+375,120,36410);
		//	先保存文字背后的图像，以便之后鼠标点击时能够清除文字
	get_image(ORIGINX+60,ORIGINY+180,ORIGINX+245,ORIGINY+207,text1save);	//手机号
	get_image(ORIGINX+60,ORIGINY+226,ORIGINX+245,ORIGINY+253,text2save);	//验证码

	
	/**************
	机器人头像
	**************/
	FillCircle(ROBOTx,ROBOTy-60,20,255);
	FillCircle(ROBOTx,ROBOTy-56,16,65535);
	circle(ROBOTx,ROBOTy-56,16,0);
	FillCircle(ROBOTx,ROBOTy-60,2,40966);
	//bar(ROBOTx-16,ROBOTy-48,ROBOTx+16,ROBOTy-20,255);
	//bar(ROBOT.x-17,ROBOT.y-21+ROBOT.leg_left,ROBOT.x,ROBOT.y-13+ROBOT.leg_left,0);
	//bar(ROBOT.x,ROBOT.y-21+ROBOT.leg_right,ROBOT.x+17,ROBOT.y-13+ROBOT.leg_right,0);
	//bar(ROBOT.x-16,ROBOT.y-20+ROBOT.leg_left,ROBOT.x-1,ROBOT.y-14+ROBOT.leg_left,65535);
	//bar(ROBOT.x+1,ROBOT.y-20+ROBOT.leg_right,ROBOT.x+16,ROBOT.y-14+ROBOT.leg_right,65535);
	FillCircle(ROBOTx,ROBOTy-36,14,65535);
	bar(ROBOTx-16,ROBOTy-48,ROBOTx+16,ROBOTy-44,63488);
	Fillellipse(ROBOTx-6,ROBOTy-70,ROBOTx-6,ROBOTy-66,6,65535);
	Fillellipse(ROBOTx+6,ROBOTy-70,ROBOTx+6,ROBOTy-66,6,65535);
	ellipse(ROBOTx+6,ROBOTy-70,ROBOTx+6,ROBOTy-66,6,0);
	ellipse(ROBOTx-6,ROBOTy-70,ROBOTx-6,ROBOTy-66,6,0);
	semicircle_down(ROBOTx+4,ROBOTy-68,2,0);
	semicircle_down(ROBOTx-4,ROBOTy-68,2,0);
	bow(ROBOTx,ROBOTy-72,22,0);
	linever(ROBOTx,ROBOTy-58,ROBOTx,ROBOTy-50,1,0);
	//Horizline(ROBOTx-8,ROBOTy-40,16,0);
	//semicircle_up(ROBOTx,ROBOTy-40,8,0);
	
	/****************
	输入框
	****************/
	//	输入线
	bar(ORIGINX+39,ORIGINY+207,ORIGINX+216,ORIGINY+208,0);
	bar(ORIGINX+39,ORIGINY+253,ORIGINX+216,ORIGINY+254,0);
	//	图标
	FillCircle(ORIGINX+45,ORIGINY+196,3,255);
	fill_bow_left_up(ORIGINX+45,ORIGINY+205,7,255);
	fill_bow_right_up(ORIGINX+45,ORIGINY+205,7,255);
	bar(ORIGINX+39,ORIGINY+244,ORIGINX+51,ORIGINY+253,255);
	fill_bow_left_up(ORIGINX+45,ORIGINY+244,4,255);
	fill_bow_right_up(ORIGINX+45,ORIGINY+244,4,255);
	
	fill_bow_left_up(ORIGINX+45,ORIGINY+244,3,28153);
	fill_bow_right_up(ORIGINX+45,ORIGINY+244,3,28153);
	//	汉字显示
	fdhz(ORIGINX+65,ORIGINY+190,1,1,"请",25388);
	fdhz(ORIGINX+80,ORIGINY+190,1,1,"输",25388);
	fdhz(ORIGINX+95,ORIGINY+190,1,1,"入",25388);
	fdhz(ORIGINX+110,ORIGINY+190,1,1,"您",25388);
	fdhz(ORIGINX+125,ORIGINY+190,1,1,"的",25388);
	fdhz(ORIGINX+140,ORIGINY+190,1,1,"手",25388);
	fdhz(ORIGINX+155,ORIGINY+190,1,1,"机",25388);
	fdhz(ORIGINX+170,ORIGINY+190,1,1,"号",25388);
	fdhz(ORIGINX+65,ORIGINY+235,1,1,"请",25388);
	fdhz(ORIGINX+80,ORIGINY+235,1,1,"输",25388);
	fdhz(ORIGINX+95,ORIGINY+235,1,1,"入",25388);
	fdhz(ORIGINX+110,ORIGINY+235,1,1,"您",25388);
	fdhz(ORIGINX+125,ORIGINY+235,1,1,"的",25388);
	fdhz(ORIGINX+140,ORIGINY+235,1,1,"验",25388);
	fdhz(ORIGINX+155,ORIGINY+235,1,1,"证",25388);
	fdhz(ORIGINX+170,ORIGINY+235,1,1,"码",25388);
	
	/************
	验证码接收按钮
	************/
	bar(ORIGINX+39,ORIGINY+309,ORIGINX+216,ORIGINY+310,255);
	bar(ORIGINX+39,ORIGINY+337,ORIGINX+216,ORIGINY+338,255);
	bar(ORIGINX+39,ORIGINY+310,ORIGINX+40,ORIGINY+337,255);
	bar(ORIGINX+215,ORIGINY+310,ORIGINX+216,ORIGINY+337,255);
	fdhz(ORIGINX+80,ORIGINY+315,1,1,"获",65535);
	fdhz(ORIGINX+100,ORIGINY+315,1,1,"取",65535);
	fdhz(ORIGINX+120,ORIGINY+315,1,1,"验",65535);
	fdhz(ORIGINX+140,ORIGINY+315,1,1,"证",65535);
	fdhz(ORIGINX+160,ORIGINY+315,1,1,"码",65535);
	
	/************
	登录按钮
	************/
	bar(ORIGINX+39,ORIGINY+360,ORIGINX+216,ORIGINY+388,255);
	fdhz(ORIGINX+100,ORIGINY+370,1,1,"登",65535);
	fdhz(ORIGINX+140,ORIGINY+370,1,1,"录",65535);
}





//	主逻辑
int checkin(int* x, int* y)
{
	
	int button=0,mx=0,my=0,mouse=0;		/*检测鼠标点击区域*/
	int iph_num=0;		/*检测手机号是否输入正确*/
	char id_code[5]={'\0','\0','\0','\0','\0'};		/*存储输入的验证码*/
	char id_real[5]={'1','\0','\0','\0','\0'};		/*存储生成的验证码*/
	unsigned int *text1save=(unsigned int *)malloc(185*27*sizeof(unsigned int));	//	保存文字背后的图案
	unsigned int *text2save=(unsigned int *)malloc(185*27*sizeof(unsigned int));	//	保存文字背后的图案
	
	if(text1save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(text2save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	mousehide(*x,*y);
	//mouseInit(&mx, &my, &button);	//	初始化鼠标
	iph_frame(28153);	//	手机桌面
	checkin_interface(text1save,text2save);	//	登录界面
    
	reset_mouse(x,y);
	while(1){
		newxy(x,y,&button);
		mx = *x;
		my = *y;
		mouse = checkin_click(x,y,button);

		switch(mouse)
		{
			case 0:
					break;
			case 1:			//	点击左上角退出程序
					exit(1);
					break;
			case 2:			//	若输入手机号正确则iph_num为1，之后获取验证码时可以收到短信；否则收不到验证码
					iph_num = 0;
					input_num(x,y,&iph_num,text1save);	
					break;
			case 3:			//	id_code为输入的验证码值，点击登录时成功，否则点击登录时跳出错误信息
					id_check(x,y,id_code,text2save);		
					break;
			case 4:			//	接受验证码弹窗并停留1.5s
					if(iph_num == 1){
						save_code(id_real);
					}
				
					break;
			case 5:			//	核对验证码的正确性并进入下一界面
					if(strcmp(id_code,id_real)==0){
						mousehide(*x,*y);
						bar(0,0,1024,768,0);
						fdhz(200,200,3,3,"你好",65535);
						return 0;
						}
					else{
						fdhz(ORIGINX+65,ORIGINY+215,1,1,"验证码输入错误",25388);
						delay(500);
						bar(ORIGINX+65,ORIGINY+215,ORIGINX+210,ORIGINY+235,28153);
						//error_box();
					}
					reset_mouse(x,y);
					//ti
					
					
			case 6:
					break;
					
		}
		
		mouse=0;
		/*********************
		//	点击左上角退出
		if(mx>=(0)&&mx<=(200)&&my<=(200)&&my>=(0)&&button){
			exit(1);
		}
		
		
		//点击"获取验证码"弹窗并停留3s
		if(mx>=(ORIGINX+39)&&mx<=(ORIGINX+216)&&my<=(ORIGINY+338)&&my>=(ORIGINY+309)&&button){
			get_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
			message_box();
			delay(3000);
			put_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
			free(image_save);
			image_save = NULL;
		}
		
		************************/
		//	点击输入用户名或密码进入输入模式
	}
	
	free(text1save);		//释放内存
	free(text2save);
	text1save = NULL;
	text2save = NULL;
	
	return 1;
}



int checkin_click(int *mx,int *my,int button)
 {
	 /*********
	按钮位置标准化
	将所有可能的按钮位置坐标储存在二维数组中
	*********/
	int a[5][4];
	a[0][0] = 0;	//	a[0][]:点击左上角退出程序
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	a[1][0] = ORIGINX+60;		//	a[1][]:点击输入手机号	get_image(ORIGINX+60,ORIGINY+194,ORIGINX+170,ORIGINY+207,text1save);	
	a[1][1] = ORIGINX+240;
	a[1][2] = ORIGINY+190;
	a[1][3] = ORIGINY+207;
	a[2][0] = ORIGINX+60;		//	a[2][]:点击输入验证码	get_image(ORIGINX+60,ORIGINY+239,ORIGINX+170,ORIGINY+253,text2save);
	a[2][1]	= ORIGINX+240;
	a[2][2]	= ORIGINY+235;
	a[2][3] = ORIGINY+253;
	a[3][0] = ORIGINX+39;		//	a[3][]:点击获取验证码			39 216 309 338
	a[3][1]	= ORIGINX+216;
	a[3][2]	= ORIGINY+309;
	a[3][3] = ORIGINY+338;
	a[4][0] = ORIGINX+39;		//	a[4][]:点击登录					ORIGINX+39,ORIGINY+360,ORIGINX+216,ORIGINY+388
	a[4][1]	= ORIGINX+216;
	a[4][2]	= ORIGINY+360;
	a[4][3] = ORIGINY+388;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && button)	return 1;   //if(鼠标点击退出区域)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && button)	return 2;   //if(鼠标点击【手机号输入】区域)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && button)	return 3;   //if(鼠标点击【验证码输入】区域)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && button)	return 4;   //if(鼠标点击【获取验证码】区域)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && button)	return 5; 	//if(鼠标点击【登录】区域)
	else if (button)																		return 6;	//if(鼠标点击其他区域)
    else return 0;
 }