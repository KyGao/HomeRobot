#include"main.h"
#include <time.h>
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
#define TRUE 1
#define SCREENCENTER_x 894 
#define SCREENCENTER_y 493
#define SCREENLENGTH 250 
#define SCREENHEIGHT 541
#define APPSIZE 41
#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764



void iph_frame(int color)	//	手机外框等固定元素，任何界面都需要显示
{
	//	外形
	bar(760,210,1024,768,65535);
	bar_round_2(767,ORIGINY,255+ORIGINX,546+ORIGINY,30,1,0);
	bar_round_2(767,ORIGINY,FINALX,FINALY,29,1,color);
	bar_round(SCREENCENTER_x,223,139,60,20,0,0);
	linelevel(824,228,964,228,5,0);
	bar(769,170,1024,220,65535);
	FillCircle(SCREENCENTER_x+40,236,2,4523);												//	RGB�?0 52 91
	bar_round(SCREENCENTER_x,236,30,4,2,1,12768);											//	RGB: 20 20 20				
	
	//	信号&电源
	bar(968,250,971,253,65535);
	bar(972,247,975,253,65535);
	bar(976,244,979,253,65535);
	bar(980,241,983,253,65535);																//	RGB: 10 10 10
	bar_round(1000,247,20,12,2,1,65535);
	
}


void apps(void)		//	初始桌面上的应用程序
{
	
	//	桌面
	bar_round(SCREENCENTER_x-87,SCREENCENTER_y-180,APPSIZE,APPSIZE,7,1,0);
	bar_round(SCREENCENTER_x-29,SCREENCENTER_y-180,APPSIZE,APPSIZE,7,1,0);
	bar_round(SCREENCENTER_x+29,SCREENCENTER_y-180,APPSIZE,APPSIZE,7,1,0);
	bar_round(SCREENCENTER_x+87,SCREENCENTER_y-180,APPSIZE,APPSIZE,7,1,0);


}





int dis_iph(int* mx, int* my)
{
	int button=0,x=0,y=0,state=1;
	iph_frame(36410);
	//	iph_time();
	apps();
	//mouseInit(&x, &y, &button);
	
	while(TRUE)
	   {

		
		newxy(mx,my,&button);
		x = *mx;
		y = *my;
		//	点击左上角退出
		if(x>=(0)&&x<=(200)&&y<=(200)&&y>=(0)&&button){
			exit(1);
		}

		//	点击第一个应用进入app
		if(x>=(SCREENCENTER_x-87-20)&&x<=(SCREENCENTER_x-87+20)&&y<=(SCREENCENTER_y-180+20)&&y>=(SCREENCENTER_y-180-20)&&state&&button)
		{
			
			if(checkin(mx,my)!=0){
				delay(5000);

				exit(1);
			}
			
			//ti
			else{return 0;}
			state = 0;
		}
		//	点击第二个应用退出
		if(x>=(SCREENCENTER_x-29-20)&&x<=(SCREENCENTER_x-29+20)&&y<=(SCREENCENTER_y-180+20)&&y>=(SCREENCENTER_y-180-20)&&state&&button)
		{
			exit(1);
		}
	}
		
	return TRUE;
}

