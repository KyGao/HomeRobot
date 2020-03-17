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
/**************************************
控制机器人移动的函数
void dmove(ROBOT_CASE *robot_position,int *x,int *y);
void dmove2(ROBOT_CASE *robot_position,int *x,int *y,unsigned int *withchair);
void move0(ROBOT_CASE *robot_position,int *x,int *y);
void move2(ROBOT_CASE *robot_position,int *x,int *y,unsigned int *withchair);
int randmove(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y);
int aimmove(ROBOT_CASE *robot_position,int f,int x0,int y0,int xt,int yt,int *x,int *y);
void CutWeed(ROBOT_CASE *robot_position,unsigned int *CutSave,int direction);
**************************************/

/*机器人每一次移动的最小单位函数*/
void dmove(ROBOT_CASE *robot_position,int *x,int *y)
{
	int button=0;
	int x0 = (*robot_position).xpixel,y0 = (*robot_position).ypixel;
    
	//判断方向并移动相应距离
	switch((*robot_position).direction)
	{
		case 1:
		{
			right(*robot_position);
			x0 = x0+2;
			break;
		}
		case 2:
		{
			left(*robot_position);
			x0 = x0-2;
			break;
		}
		case 3:
		{
			backbodyhead(*robot_position);
			y0 = y0-2;
			break;
		}
		case 4:
		{
			forebodyhead(*robot_position);
			y0 = y0+2;
			break;
		}
		case 5://向左运动并持物
		{
			left_hold(*robot_position);
			x0 = x0-2;
			break;
		}
		case 6://向右运动并持物
		{
			right_hold(*robot_position);
			x0 = x0+2;
			break;
		}
		
	}
	/*保持图像*/
	delay0(50);
	newxy(x,y,&button);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	(*robot_position).xpixel = x0;
	(*robot_position).ypixel = y0;
	get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
}

/*搬椅子移动函数*/
void dmove2(ROBOT_CASE *robot_position,int *x,int *y,unsigned int *withchair)
{
	int button=0;
	int x0 = (*robot_position).xpixel,y0 = (*robot_position).ypixel;
    
	/*判断方向*/
	switch((*robot_position).direction)
	{
		case 1:
		{
			right_chair(*robot_position);
			x0 = x0+2;
			delay0(50);
	        newxy(x,y,&button);
	        put_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
	        (*robot_position).xpixel = x0;
	        (*robot_position).ypixel = y0;
	        get_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
			break;
		}
		case 2:
		{
			left_chair(*robot_position);
			x0 = x0-2;
			delay0(50);
	        newxy(x,y,&button);
	        put_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
	        (*robot_position).xpixel = x0;
	        (*robot_position).ypixel = y0;
	        get_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
			break;
		}
		case 3:
		{
			backbodyhead(*robot_position);
			y0 = y0-2;
			delay0(50);
	        newxy(x,y,&button);
	        put_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
	        (*robot_position).xpixel = x0;
	        (*robot_position).ypixel = y0;
	        get_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
			break;
		}
		case 4:
		{
			fore_chair(*robot_position);
			y0 = y0+2;
			delay0(50);
	        newxy(x,y,&button);
	        put_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
	        (*robot_position).xpixel = x0;
	        (*robot_position).ypixel = y0;
	        get_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
			break;
		}
	}
}

/*普通的移动函数,每次移动一格*/
void move0(ROBOT_CASE *robot_position,int *x,int *y)
{
	int i;
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	/*按一定的间隔改变机器人脚的位置*/
	for(i=0;i<20;i++)
	{
		if((*robot_position).leg)
		{
			(*robot_position).leg_right=0;
			(*robot_position).leg_left--;
		}
		else
		{
			(*robot_position).leg_left=0;
			(*robot_position).leg_right--;
		}
		if((*robot_position).leg_left<=-5||(*robot_position).leg_right<=-5)
		{
			(*robot_position).leg = !(*robot_position).leg;
		}
		/*改变手的角度*/
		if((*robot_position).hand)
		{
			(*robot_position).hand_left++;
			(*robot_position).hand_right--;
		}
		else//初始化时为0，即动右手
		{
			(*robot_position).hand_right++;
			(*robot_position).hand_left--;
		}
		if(((*robot_position).hand_right>=10)||((*robot_position).hand_left>=10)||((*robot_position).hand_right<=-10)||((*robot_position).hand_left<=-10))
		{
			(*robot_position).hand=!(*robot_position).hand;
		}
		/*调用最小移动单元*/
		dmove(robot_position,x,y);
	}
	/*更新机器人位置*/
	(*robot_position).x =   ((*robot_position).xpixel-20)/40;//因为大小关系，给x一个偏移量20
	(*robot_position).y = ((*robot_position).ypixel-4-50)/40;//偏移量50
	(*robot_position).leg = 0;
	(*robot_position).leg_left = 0;
	(*robot_position).leg_right = 0;
    forebodyhead(*robot_position);
	
	//走一步少一格电
	ChangeHouse(25,-1);
	if(CheckHouse(25)<50&&(!CheckHouse(26))){
		charge_main(robot_position,x,y);
	}
}


void move2(ROBOT_CASE *robot_position,int *x,int *y,unsigned int *withchair)//搬动椅子的移动
{
	int i;
	/*改变机器人的脚的位置*/
	for(i=0;i<20;i++)
	{
		if((*robot_position).leg)
		{
			(*robot_position).leg_right=0;
			(*robot_position).leg_left--;
		}
		else
		{
			(*robot_position).leg_left=0;
			(*robot_position).leg_right--;
		}
		if((*robot_position).leg_left<=-5||(*robot_position).leg_right<=-5)
		{
			(*robot_position).leg = !(*robot_position).leg;
		}
		
		if((*robot_position).hand)
		{
			(*robot_position).hand_left++;
			(*robot_position).hand_right--;
		}
		else//初始化时为0，即动右手
		{
			(*robot_position).hand_right++;
			(*robot_position).hand_left--;
		}
		if(((*robot_position).hand_right>=10)||((*robot_position).hand_left>=10)||((*robot_position).hand_right<=-10)||((*robot_position).hand_left<=-10))
		{
			(*robot_position).hand=!(*robot_position).hand;
		}
		
		dmove2(robot_position,x,y,withchair);
	}
	(*robot_position).x =   ((*robot_position).xpixel-20)/40;//因为大小关系，给x一个偏移量20
	(*robot_position).y = ((*robot_position).ypixel-4-50)/40;//偏移量50
	(*robot_position).leg = 0;
	(*robot_position).leg_left = 0;
	(*robot_position).leg_right = 0;
}

/*随机巡逻函数，自身在一个while中,返回-2时返回主界面*/
int randmove(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y)
{
	int expect_dire,expect_x,expect_y,floor = (*robot_position).position;
	int button;
	
	newxy(x,y,&button);
	/*点了定向巡逻函数*/
	if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+2-SCREENHEIGHT/7+20 && *y <= SCREENCENTER_y+2+SCREENHEIGHT/7-20 && button)
	{
		go_to(robot_position,esc1,x,y);
		return -2;//回到主页面
	}
	if(*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)
	{
		return -2;
	}
	/*生成随机方向*/
	expect_dire = rand() % 4 + 1;
	/*生成预期位置*/
	switch (expect_dire)
	{
	case 1:
	{
		expect_x = (*robot_position).x + 1;
		expect_y = (*robot_position).y;
		break;
	}
	case 2:
	{
		expect_x = (*robot_position).x - 1;
		expect_y = (*robot_position).y;
		break;
	}
	case 3:
	{
		expect_x = (*robot_position).x;
		expect_y = (*robot_position).y - 1;
		break;
	}
	case 4:
	{
		expect_x = (*robot_position).x;
		expect_y = (*robot_position).y + 1;
		break;
	}
	}
	/*判断该方向能否移动，能则移动*/
	if (CheckMove(expect_x + 1, expect_y + 1, floor) == 1)
	{
		(*robot_position).direction = expect_dire;
		move0(robot_position, x, y);
		delay0(300);
	}
	   
		
    		
}

/*寻路函数，给定起止点自动寻路并到达*/
int aimmove(ROBOT_CASE *robot_position,int f,int x0,int y0,int xt,int yt,int *x,int *y)//以(0,0)为开始
{
	UNIT *t=NULL;//作为每一次寻路的中间变量
	/*STACK 初始化*/
	STACK *S;
	/*用另一个栈把路径正向存储*/
	STACK *R;
	
	/*分配空间*/
	S = (STACK*)malloc(sizeof(STACK));
	R = (STACK*)malloc(sizeof(STACK));
	/*检查分配是否成功*/
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(R==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	/*初始化栈*/
	InitStack(S);
	InitStack(R);
	/*分配中间变量的空间*/
	t = (UNIT *)malloc(sizeof(UNIT));
	/*判断空间分配是否成功*/
	if(t==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	(*robot_position).x = x0;
	(*robot_position).y = y0;
	
	/*如果起点等于终点*/
	if(x0==xt && y0==yt)
	{
		return 0;
	}
	
	if(!FindWay(f,x0,y0,xt,yt,S))//坐标计算以(0,0)开始
	{
		//寻路出错
		FindWay_error(500,500);
		getch();
		exit(1);
	}
	else
	{
		/*将S中的元素弹出，压入R中*/
		while(!StackEmpty(S))
		{
			Pop(S,t);
			Push(R,*t);
		}
		/*弹出R中元素，并单步移动*/
		while(!StackEmpty(R))
		{
				Pop(R,t);
			    (*robot_position).direction = t->di;
			    move0(robot_position,x,y);
		}
		
	}
	/*先销毁S，再回收t,最后销毁R,并回收S、R的空间*/
	DestroyStack(S);
	free(t);
	DestroyStack(R);
	free(S);
	free(R);
	/*将指针置为空*/
	S = NULL;
	R = NULL;
	t = NULL;
	/*确保到达*/
	if((*robot_position).x != xt || (*robot_position).y!= yt)
	{
		aimmove(robot_position,f,(*robot_position).x,(*robot_position).y,xt,yt,x,y);
	}
	
	//换楼层
	/*ground to outside*/
	if((yt == 9 || yt == 10)&&(xt==1)&&(f==1))
	{
		(*robot_position).position=0;
		mousehide(*x,*y);
		bar(0,0,764,768,65535);
		_outside();
		reset_mouse(x,y);
		(*robot_position).x = 10;
		(*robot_position).y = 10;
	    (*robot_position).xpixel = ((*robot_position).x)*40+20;
		(*robot_position).ypixel = ((*robot_position).y)*40+4+50;
		(*robot_position).leg = 0;
	    (*robot_position).leg_left = 0;
	    (*robot_position).leg_right = 0;
		get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
		forebodyhead(*robot_position);
	}
	/*outside to ground*/
	if((xt == 11)&&(yt==10)&&(f==0))
	{
		(*robot_position).position=1;
		mousehide(*x,*y);
		bar(0,0,764,768,65535);
		_ground();
		reset_mouse(x,y);
		(*robot_position).x = 2;
		(*robot_position).y = 9;
		(*robot_position).xpixel = ((*robot_position).x)*40+20;
		(*robot_position).ypixel = ((*robot_position).y)*40+4+50;
		(*robot_position).leg = 0;
	    (*robot_position).leg_left = 0;
	    (*robot_position).leg_right = 0;
		get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
		forebodyhead(*robot_position);
		
	}
	/*ground to room*/
	if((xt == 9)&&(yt==8)&&(f==1))
	{
		(*robot_position).x = 5;
		(*robot_position).y = 4;
		(*robot_position).xpixel = ((*robot_position).x)*40+20;
		(*robot_position).ypixel = ((*robot_position).y)*40+4+50;
		(*robot_position).position=2;
		(*robot_position).leg = 0;
	    (*robot_position).leg_left = 0;
	    (*robot_position).leg_right = 0;
		mousehide(*x,*y);
		bar(0,0,764,768,0);
		floor_R();
		reset_mouse(x,y);
		get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
		forebodyhead(*robot_position);
	}
	/*room to ground*/
	if((xt == 6)&&(yt==4)&&(f==2))
	{
		(*robot_position).x = 10;
		(*robot_position).y = 8;
		(*robot_position).xpixel = ((*robot_position).x)*40+20;
		(*robot_position).ypixel = ((*robot_position).y)*40+4+50;
		(*robot_position).position=1;
		(*robot_position).leg = 0;
	    (*robot_position).leg_left = 0;
	    (*robot_position).leg_right = 0;
		mousehide(*x,*y);
		bar(0,0,764,768,65535);
		_ground();
		reset_mouse(x,y);
		get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
		forebodyhead(*robot_position);
	}
}

void CutWeed(ROBOT_CASE *robot_position,unsigned int *CutSave,int direction)//割草的动画,di == 1:右向左，2：左向右
{
	int i;
	int x0 = (*robot_position).xpixel,y0 = (*robot_position).ypixel;
	/*按照方向画出动画*/
	if(direction == 1)
	{
		put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	    for(i=0;i<20;i++)
	    {
		
		    Cut_Machine1((*robot_position).xpixel-80,(*robot_position).ypixel-40);
		    left_hold(*robot_position);
		    x0 = x0-2;
	        delay0(50);
		    put_image((*robot_position).xpixel-80,(*robot_position).ypixel-40,(*robot_position).xpixel-32,(*robot_position).ypixel,CutSave);
	        put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	    
	        (*robot_position).xpixel = x0;
	        (*robot_position).ypixel = y0;
	        get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	        get_image((*robot_position).xpixel-80,(*robot_position).ypixel-40,(*robot_position).xpixel-32,(*robot_position).ypixel,CutSave);
			
			if((*robot_position).leg)
		    {
			    (*robot_position).leg_right=0;
			    (*robot_position).leg_left--;
		    }
		    else
		    {
			    (*robot_position).leg_left=0;
			    (*robot_position).leg_right--;
		    }
		    if((*robot_position).leg_left<=-5||(*robot_position).leg_right<=-5)
		    {
			    (*robot_position).leg = !(*robot_position).leg;
		    }
		
		
	    }
	}
	else
	{
		put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	    for(i=0;i<20;i++)
	    {
		    Cut_Machine2((*robot_position).xpixel+40,(*robot_position).ypixel-40);
		    right_hold(*robot_position);
		    x0 = x0+2;
	        delay0(50);
		    put_image((*robot_position).xpixel+72,(*robot_position).ypixel-40,(*robot_position).xpixel+120,(*robot_position).ypixel,CutSave);
	        put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	    
	        (*robot_position).xpixel = x0;
	        (*robot_position).ypixel = y0;
	        get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	        get_image((*robot_position).xpixel+72,(*robot_position).ypixel-40,(*robot_position).xpixel+120,(*robot_position).ypixel,CutSave);
			
			if((*robot_position).leg)
		    {
			    (*robot_position).leg_right=0;
			    (*robot_position).leg_left--;
		    }
		    else
		    {
			    (*robot_position).leg_left=0;
			    (*robot_position).leg_right--;
		    }
		    if((*robot_position).leg_left<=-5||(*robot_position).leg_right<=-5)
		    {
			    (*robot_position).leg = !(*robot_position).leg;
		    }
	    }
	}
	(*robot_position).x =   ((*robot_position).xpixel-20)/40;//因为大小关系，给x一个偏移量20
	(*robot_position).y = ((*robot_position).ypixel-4-50)/40;//偏移量50
	(*robot_position).leg = 0;
	(*robot_position).leg_left = 0;
	(*robot_position).leg_right = 0;
    forebodyhead(*robot_position);
}

