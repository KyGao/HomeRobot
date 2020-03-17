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
/*********************************************
功能ui及控制模块（余泽泰部分）
void move_ui(void);
void easy_ui(void);
void clean_ui(void);
void move_control(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y);
void clean_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y);
void easy_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y);
**********************************************/
/*安全功能ui*/
void move_ui(void)
{
	iph_frame(36410);
	/*图形框*/
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y-SCREENHEIGHT/7+2,180,SCREENHEIGHT/7-20,15,1,0);//黑色背景，造成阴影效果
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y+2,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-SCREENHEIGHT/7,180,SCREENHEIGHT/7-20,15,1,18202);
	bar_round(SCREENCENTER_x, SCREENCENTER_y,180,SCREENHEIGHT/7-20,15,1,34431);
	/*文字*/
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-SCREENHEIGHT/7-20,2,2,"随机巡逻",65535);
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-20,2,2,"定向巡逻",65535);
	
		//主页图标（双圆环
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
}

/*便捷功能ui*/
void easy_ui(void)
{
	iph_frame(36410);
	/*图形框*/
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y-SCREENHEIGHT/7+2,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-SCREENHEIGHT/7,180,SCREENHEIGHT/7-20,15,1,18202);
    /*文字*/
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-SCREENHEIGHT/7-20,2,2,"搬椅子",65535);
	
		//主页图标（双圆环
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
}

/*卫生ui*/
void clean_ui(void)
{
	iph_frame(36410);
	/*图形框*/
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y-SCREENHEIGHT/7+2-90,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y+2-90,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y+SCREENHEIGHT/7+2-90,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-SCREENHEIGHT/7-90,180,SCREENHEIGHT/7-20,15,1,18202);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-90,180,SCREENHEIGHT/7-20,15,1,34431);
	bar_round(SCREENCENTER_x, SCREENCENTER_y+SCREENHEIGHT/7-90,180,SCREENHEIGHT/7-20,15,1,17244);
	/*文字*/
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-SCREENHEIGHT/7-110,2,2,"除草",65535);
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-110,2,2,"打扫",65535);
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y+SCREENHEIGHT/7-110,2,2,"倒垃圾",65535);
	
		//主页图标（双圆环
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	/*文字*/
	fdhz(SCREENCENTER_x-100,SCREENCENTER_y+50,1,1,"垃圾桶一",65535);
	fdhz(SCREENCENTER_x-100,SCREENCENTER_y+110,1,1,"垃圾桶二",65535);
	fdhz(SCREENCENTER_x-100,SCREENCENTER_y+170,1,1,"垃圾桶三",65535);
}

/*安全功能逻辑*/
int move_control(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y)
{
	int button;
	int judge=-1;//判断调用功能
	int click=0;//判断退出
	mousehide(*x,*y);
	move_ui();
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		/*检查是否点击退出按钮*/
		click=esc_check(esc1,x,y,&button);
		if(click==1)
		{
			return 1;
		}
		/*随机移动*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2 && button)
		{
			/*动画效果*/
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,65535);
            linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,0);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,65535);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,0);
			delay0(10);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,18202);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,18202);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			
			while(1)
			{
				judge = randmove(robot_position,esc1,x,y);
				if(judge == -2)
				{
					break;
				}
				//换楼层

				/*ground to outside*/
				if (((*robot_position).y == 9 || (*robot_position).y == 10) && ((*robot_position).x == 1) && ((*robot_position).position == 1))
				{
					/*更新机器人位置*/
					(*robot_position).position = 0;
					mousehide(*x,*y);
					/*绘制地图*/
					bar(0, 0, 764, 768, 65535);
					_outside();
					/*重置鼠标*/
					reset_mouse(x, y);
					/*机器人动作复位*/
					(*robot_position).x = 10;
					(*robot_position).y = 10;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					/*获取背景图像*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*画出机器人*/
					forebodyhead(*robot_position);
				}
				/*outside to ground*/
				if (((*robot_position).x == 11) && ((*robot_position).y == 10) && ((*robot_position).position == 0))
				{
					/*更新机器人位置*/
					(*robot_position).position = 1;
					mousehide(*x,*y);
					/*绘制地图*/
					bar(0, 0, 764, 768, 65535);
					_ground();
					/*重置鼠标*/
					reset_mouse(x, y);
					/*机器人动作复位*/
					(*robot_position).x = 2;
					(*robot_position).y = 9;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					/*获取背景图像*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*画出机器人*/
					forebodyhead(*robot_position);

				}
				/*ground to room*/
				if (((*robot_position).x == 9) && ((*robot_position).y == 8) && ((*robot_position).position == 1))
				{
					/*更新机器人位置*/
					(*robot_position).position = 2;
					/*机器人动作复位*/
					(*robot_position).x = 5;
					(*robot_position).y = 4;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					mousehide(*x,*y);
					/*绘制地图*/
					bar(0, 0, 764, 768, 0);
					floor_R();
					/*重置鼠标*/
					reset_mouse(x, y);
					/*获取背景图像*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*画出机器人*/
					forebodyhead(*robot_position);
				}
				/*room to ground*/
				if (((*robot_position).x == 6) && ((*robot_position).y == 4) && ((*robot_position).position == 2))
				{
					/*更新机器人位置*/
					(*robot_position).position = 1;
					/*机器人动作复位*/
					(*robot_position).x = 10;
					(*robot_position).y = 8;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					mousehide(*x,*y);
					/*绘制地图*/
					bar(0, 0, 764, 768, 65535);
					_ground();
					/*重置鼠标*/
					reset_mouse(x, y);
					/*获取背景图像*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*画出机器人*/
					forebodyhead(*robot_position);
				}
			}
			
		}
		/*定向巡逻*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+2-SCREENHEIGHT/7+20 && *y <= SCREENCENTER_y+2+SCREENHEIGHT/7-20 && button)
		{
			/*调用定向巡逻功能*/
			go_to(robot_position,esc1,x,y);
			break;
		}
		/*返回主界面*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)||(judge==-2))
		{
			/*切换界面*/
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			judge = -1;
			break;
		}
		
	
	}
}

/*卫生功能逻辑*/
int clean_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y)
{
	int button;
	int judge=-1;//判断调用功能
	int click=0;//判断退出
	mousehide(*x,*y);
	clean_ui();
	reset_mouse(x,y);
	ShowTrashNum();
	while(1)
	{
		newxy(x,y,&button);
		
		/*检查是否点击退出按钮*/
		click = esc_check(esc1,x,y,&button);
		if(click==1)
		{
			return 1;
		}
		/*除杂草*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2-90 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-90 && button)
		{
			/*动画效果*/
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,2,65535);
            linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,2,0);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,65535);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,0);
			delay0(10);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,2,18202);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,2,18202);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,18202);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,18202);
			clean_weed(robot_position,x,y);
			
		}
		/*打扫*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+2-SCREENHEIGHT/7+20-70 && *y <= SCREENCENTER_y+2+SCREENHEIGHT/7-110 && button)
		{
			clean(robot_position,save,x,y);
			ShowTrashNum();
			button = 0;
			
		}
		/*倒垃圾*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+SCREENHEIGHT/7+2-SCREENHEIGHT/7-70 && *y <= SCREENCENTER_y+SCREENHEIGHT/7+2+SCREENHEIGHT/7-110 && button)
		{
			throw_trash(robot_position,x,y);
			mousehide(*x,*y);
			ShowTrashNum();
		}
		/*返回主界面*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)||(judge==-2))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			//mousehide(*x,*y);
			judge = -1;
			break;
		}
	}
}

/*便捷功能逻辑*/
int easy_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y)
{
	int click=0;
	int button;
	int judge=-1;
	easy_ui();
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		
		/*检查是否点击退出按钮*/
		click=esc_check(esc1,x,y,&button);
		if(click==1)
		{
			return 1;
		}
		/*搬椅子*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2 && button)
		{
			/*动画效果*/
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,65535);
            linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,0);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,65535);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,0);
			delay0(10);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,18202);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,18202);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			/*搬椅子功能*/
			movechair(robot_position,save,x,y);
		}
		
		/*返回主界面*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)||(judge==-2))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			judge = -1;
			break;
		}
	}
}

