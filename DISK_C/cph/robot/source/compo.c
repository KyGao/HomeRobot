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
void forebodyhead(ROBOT_CASE robot_position)//范围：robot_position.xpixel+-30;robot_position.ypixel-80~robot_position.ypixel-14;
{
	robot_hand_right(robot_position.xpixel+3,robot_position.ypixel-13,45);
	robot_hand_left(robot_position.xpixel-28,robot_position.ypixel-5,-45);
	FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	FillCircle(robot_position.xpixel,robot_position.ypixel-56,16,65535);
	circle(robot_position.xpixel,robot_position.ypixel-56,16,0);
	FillCircle(robot_position.xpixel,robot_position.ypixel-60,2,40966);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-20,255);
	bar(robot_position.xpixel-17,robot_position.ypixel-21+robot_position.leg_left,robot_position.xpixel,robot_position.ypixel-13+robot_position.leg_left,0);
	bar(robot_position.xpixel,robot_position.ypixel-21+robot_position.leg_right,robot_position.xpixel+17,robot_position.ypixel-13+robot_position.leg_right,0);
	bar(robot_position.xpixel-16,robot_position.ypixel-20+robot_position.leg_left,robot_position.xpixel-1,robot_position.ypixel-14+robot_position.leg_left,65535);
	bar(robot_position.xpixel+1,robot_position.ypixel-20+robot_position.leg_right,robot_position.xpixel+16,robot_position.ypixel-14+robot_position.leg_right,65535);
	FillCircle(robot_position.xpixel,robot_position.ypixel-36,14,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-44,63488);
	Fillellipse(robot_position.xpixel-6,robot_position.ypixel-70,robot_position.xpixel-6,robot_position.ypixel-66,6,65535);
	Fillellipse(robot_position.xpixel+6,robot_position.ypixel-70,robot_position.xpixel+6,robot_position.ypixel-66,6,65535);
	ellipse(robot_position.xpixel+6,robot_position.ypixel-70,robot_position.xpixel+6,robot_position.ypixel-66,6,0);
	ellipse(robot_position.xpixel-6,robot_position.ypixel-70,robot_position.xpixel-6,robot_position.ypixel-66,6,0);
	semicircle_down(robot_position.xpixel+4,robot_position.ypixel-68,2,0);
	semicircle_down(robot_position.xpixel-4,robot_position.ypixel-68,2,0);
	bow(robot_position.xpixel,robot_position.ypixel-72,22,0);
	linever(robot_position.xpixel,robot_position.ypixel-58,robot_position.xpixel,robot_position.ypixel-50,1,0);
	Horizline(robot_position.xpixel-8,robot_position.ypixel-40,16,0);
	semicircle_up(robot_position.xpixel,robot_position.ypixel-40,8,0);

}

void backbodyhead(ROBOT_CASE robot_position)//范围：x+30,-30,y-80~y-14;
{
	robot_hand_right(robot_position.xpixel,robot_position.ypixel-13,45);
	robot_hand_left(robot_position.xpixel-28,robot_position.ypixel-5,-45);
    FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-20,255);
	bar(robot_position.xpixel-16,robot_position.ypixel-20+robot_position.leg_left,robot_position.xpixel,robot_position.ypixel-14+robot_position.leg_left,65535);
	bar(robot_position.xpixel,robot_position.ypixel-20+robot_position.leg_right,robot_position.xpixel+16,robot_position.ypixel-14+robot_position.leg_right,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-44,63488);
	linever(robot_position.xpixel,robot_position.ypixel-20,robot_position.xpixel,robot_position.ypixel-14,2,0);
}





void left(ROBOT_CASE robot_position)//x-23~x+20,y-80~y-9
{
    FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	fill_bow_down(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_left(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_right_up(robot_position.xpixel-14,robot_position.ypixel-46,28,65535);
	Fillellipse(robot_position.xpixel-14,robot_position.ypixel-73,robot_position.xpixel-14,robot_position.ypixel-69,5,65535);
	ellipse(robot_position.xpixel-14,robot_position.ypixel-73,robot_position.xpixel-14,robot_position.ypixel-69,5,0);
	Fillellipse(robot_position.xpixel-17,robot_position.ypixel-71,robot_position.xpixel-17,robot_position.ypixel-70,1,0);
	FillCircle(robot_position.xpixel-20,robot_position.ypixel-62,3,40966);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-44,63488);
	bar(robot_position.xpixel-15,robot_position.ypixel-15+robot_position.leg_left,robot_position.xpixel+15,robot_position.ypixel-9+robot_position.leg_left,0);
	bar(robot_position.xpixel-14,robot_position.ypixel-14+robot_position.leg_left,robot_position.xpixel+14,robot_position.ypixel-10+robot_position.leg_left,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+16,robot_position.ypixel-14,255);
	bow(robot_position.xpixel-12,robot_position.ypixel-84,30,0);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+4,robot_position.ypixel-36,65535);
	fill_bow_right_down(robot_position.xpixel-16,robot_position.ypixel-44,20,65535);
	bar(robot_position.xpixel-15,robot_position.ypixel-15+robot_position.leg_right,robot_position.xpixel+15,robot_position.ypixel-9+robot_position.leg_right,0);
	bar(robot_position.xpixel-14,robot_position.ypixel-14+robot_position.leg_right,robot_position.xpixel+14,robot_position.ypixel-10+robot_position.leg_right,65535);
    robot_hand_left(robot_position.xpixel-17,robot_position.ypixel-4,-45-robot_position.hand_left);
}

void right(ROBOT_CASE robot_position)//x-20~x+26,y-80~y-5
{
	
	FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	fill_bow_down(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_right(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_left_up(robot_position.xpixel+14,robot_position.ypixel-46,28,65535);
	Fillellipse(robot_position.xpixel+14,robot_position.ypixel-73,robot_position.xpixel+14,robot_position.ypixel-69,5,65535);
	ellipse(robot_position.xpixel+14,robot_position.ypixel-73,robot_position.xpixel+14,robot_position.ypixel-69,5,0);
	Fillellipse(robot_position.xpixel+17,robot_position.ypixel-71,robot_position.xpixel+17,robot_position.ypixel-70,1,0);
	FillCircle(robot_position.xpixel+20,robot_position.ypixel-62,3,40966);
	bar(robot_position.xpixel,robot_position.ypixel-16+robot_position.leg_right,robot_position.xpixel+26,robot_position.ypixel-6+robot_position.leg_right,0);
	bar(robot_position.xpixel+1,robot_position.ypixel-15+robot_position.leg_right,robot_position.xpixel+24,robot_position.ypixel-7+robot_position.leg_right,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+16,robot_position.ypixel-14,255);
	bow(robot_position.xpixel+12,robot_position.ypixel-84,30,0);
	bar(robot_position.xpixel-15,robot_position.ypixel-15+robot_position.leg_left,robot_position.xpixel+11,robot_position.ypixel-5+robot_position.leg_left,0);
	bar(robot_position.xpixel-14,robot_position.ypixel-14+robot_position.leg_left,robot_position.xpixel+10,robot_position.ypixel-6+robot_position.leg_left,65535);
	fill_bow_left_down(robot_position.xpixel+16,robot_position.ypixel-44,20,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+18,robot_position.ypixel-40,63488);
	robot_hand_right(robot_position.xpixel-15,robot_position.ypixel-13,45+robot_position.hand_right);
}

void right_hold(ROBOT_CASE robot_position)//向右拿东西的图像
{
	FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	fill_bow_down(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_right(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_left_up(robot_position.xpixel+14,robot_position.ypixel-46,28,65535);
	Fillellipse(robot_position.xpixel+14,robot_position.ypixel-73,robot_position.xpixel+14,robot_position.ypixel-69,5,65535);
	ellipse(robot_position.xpixel+14,robot_position.ypixel-73,robot_position.xpixel+14,robot_position.ypixel-69,5,0);
	Fillellipse(robot_position.xpixel+17,robot_position.ypixel-71,robot_position.xpixel+17,robot_position.ypixel-70,1,0);
	FillCircle(robot_position.xpixel+20,robot_position.ypixel-62,3,40966);
	bar(robot_position.xpixel,robot_position.ypixel-16+robot_position.leg_right,robot_position.xpixel+26,robot_position.ypixel-6+robot_position.leg_right,0);
	bar(robot_position.xpixel+1,robot_position.ypixel-15+robot_position.leg_right,robot_position.xpixel+24,robot_position.ypixel-7+robot_position.leg_right,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+16,robot_position.ypixel-14,255);
	bow(robot_position.xpixel+12,robot_position.ypixel-84,30,0);
	bar(robot_position.xpixel-15,robot_position.ypixel-15+robot_position.leg_left,robot_position.xpixel+11,robot_position.ypixel-5+robot_position.leg_left,0);
	bar(robot_position.xpixel-14,robot_position.ypixel-14+robot_position.leg_left,robot_position.xpixel+10,robot_position.ypixel-6+robot_position.leg_left,65535);
	fill_bow_left_down(robot_position.xpixel+16,robot_position.ypixel-44,20,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+18,robot_position.ypixel-40,63488);
	robot_hand_right(robot_position.xpixel-15,robot_position.ypixel-13,45);
}

void left_hold(ROBOT_CASE robot_position)//向左拿东西的图像
{
    FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	fill_bow_down(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_left(robot_position.xpixel,robot_position.ypixel-60,20,65535);
	fill_bow_right_up(robot_position.xpixel-14,robot_position.ypixel-46,28,65535);
	Fillellipse(robot_position.xpixel-14,robot_position.ypixel-73,robot_position.xpixel-14,robot_position.ypixel-69,5,65535);
	ellipse(robot_position.xpixel-14,robot_position.ypixel-73,robot_position.xpixel-14,robot_position.ypixel-69,5,0);
	Fillellipse(robot_position.xpixel-17,robot_position.ypixel-71,robot_position.xpixel-17,robot_position.ypixel-70,1,0);
	FillCircle(robot_position.xpixel-20,robot_position.ypixel-62,3,40966);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-44,63488);
	bar(robot_position.xpixel-15,robot_position.ypixel-15+robot_position.leg_left,robot_position.xpixel+15,robot_position.ypixel-9+robot_position.leg_left,0);
	bar(robot_position.xpixel-14,robot_position.ypixel-14+robot_position.leg_left,robot_position.xpixel+14,robot_position.ypixel-10+robot_position.leg_left,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+16,robot_position.ypixel-14,255);
	bow(robot_position.xpixel-12,robot_position.ypixel-84,30,0);
	bar(robot_position.xpixel-16,robot_position.ypixel-44,robot_position.xpixel+4,robot_position.ypixel-36,65535);
	fill_bow_right_down(robot_position.xpixel-16,robot_position.ypixel-44,20,65535);
	bar(robot_position.xpixel-15,robot_position.ypixel-15+robot_position.leg_right,robot_position.xpixel+15,robot_position.ypixel-9+robot_position.leg_right,0);
	bar(robot_position.xpixel-14,robot_position.ypixel-14+robot_position.leg_right,robot_position.xpixel+14,robot_position.ypixel-10+robot_position.leg_right,65535);
    robot_hand_left(robot_position.xpixel-17,robot_position.ypixel-4,-45);
}


/*拿着椅子的左视图*/
void left_chair(ROBOT_CASE robot_position)
{
	left_hold(robot_position);
	seat(robot_position.xpixel-28,robot_position.ypixel-40);
}

/*拿着椅子的右视图*/
void right_chair(ROBOT_CASE robot_position)
{
	right_hold(robot_position);
	seat(robot_position.xpixel,robot_position.ypixel-44);
}

/*拿着椅子的前视图*/
void fore_chair(ROBOT_CASE robot_position)
{
	forebodyhead(robot_position);
	seat(robot_position.xpixel,robot_position.ypixel-40);
}

/*背后直接用backbodyhead*/

/*机器人打开窗户的图像*/
void backbodyhead_open(ROBOT_CASE robot_position)//范围：x+30,-30,y-80~y-14;
{
	robot_hand_left(robot_position.xpixel-28,robot_position.ypixel-5,-45);
    FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-20,255);
	bar(robot_position.xpixel-16,robot_position.ypixel-20+robot_position.leg_left,robot_position.xpixel,robot_position.ypixel-14+robot_position.leg_left,65535);
	bar(robot_position.xpixel,robot_position.ypixel-20+robot_position.leg_right,robot_position.xpixel+16,robot_position.ypixel-14+robot_position.leg_right,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-44,63488);
	linever(robot_position.xpixel,robot_position.ypixel-20,robot_position.xpixel,robot_position.ypixel-14,2,0);
}

/*机器人拾取垃圾的图像*/
void forebodyhead_open(ROBOT_CASE robot_position)
{
	robot_hand_left(robot_position.xpixel-28,robot_position.ypixel-5,-45);
	FillCircle(robot_position.xpixel,robot_position.ypixel-60,20,255);
	FillCircle(robot_position.xpixel,robot_position.ypixel-56,16,65535);
	circle(robot_position.xpixel,robot_position.ypixel-56,16,0);
	FillCircle(robot_position.xpixel,robot_position.ypixel-60,2,40966);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-20,255);
	bar(robot_position.xpixel-17,robot_position.ypixel-21+robot_position.leg_left,robot_position.xpixel,robot_position.ypixel-13+robot_position.leg_left,0);
	bar(robot_position.xpixel,robot_position.ypixel-21+robot_position.leg_right,robot_position.xpixel+17,robot_position.ypixel-13+robot_position.leg_right,0);
	bar(robot_position.xpixel-16,robot_position.ypixel-20+robot_position.leg_left,robot_position.xpixel-1,robot_position.ypixel-14+robot_position.leg_left,65535);
	bar(robot_position.xpixel+1,robot_position.ypixel-20+robot_position.leg_right,robot_position.xpixel+16,robot_position.ypixel-14+robot_position.leg_right,65535);
	FillCircle(robot_position.xpixel,robot_position.ypixel-36,14,65535);
	bar(robot_position.xpixel-16,robot_position.ypixel-48,robot_position.xpixel+16,robot_position.ypixel-44,63488);
	Fillellipse(robot_position.xpixel-6,robot_position.ypixel-70,robot_position.xpixel-6,robot_position.ypixel-66,6,65535);
	Fillellipse(robot_position.xpixel+6,robot_position.ypixel-70,robot_position.xpixel+6,robot_position.ypixel-66,6,65535);
	ellipse(robot_position.xpixel+6,robot_position.ypixel-70,robot_position.xpixel+6,robot_position.ypixel-66,6,0);
	ellipse(robot_position.xpixel-6,robot_position.ypixel-70,robot_position.xpixel-6,robot_position.ypixel-66,6,0);
	semicircle_down(robot_position.xpixel+4,robot_position.ypixel-68,2,0);
	semicircle_down(robot_position.xpixel-4,robot_position.ypixel-68,2,0);
	bow(robot_position.xpixel,robot_position.ypixel-72,22,0);
	linever(robot_position.xpixel,robot_position.ypixel-58,robot_position.xpixel,robot_position.ypixel-50,1,0);
	Horizline(robot_position.xpixel-8,robot_position.ypixel-40,16,0);
	semicircle_up(robot_position.xpixel,robot_position.ypixel-40,8,0);

}