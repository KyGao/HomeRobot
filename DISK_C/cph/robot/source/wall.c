#include "main.h"
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
#define YG 40
#define M 4
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define UP_DOWN 5
#define LEFT_RIGHT 6

	//	墙

void w_blue(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,y*YG+M,42260);		//	163 163 163
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+5,31625);	//122 112 77
}

void w_right(int x,int y)
{
	bar(x*YG-5,(y-1)*YG+M,x*YG,y*YG+M,31625);
}

void w_left(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+5,y*YG+M,31625);
}

void w_down(int x, int y)
{
	bar((x-1)*YG,y*YG+M-5,x*YG,y*YG+M,31625);
}

void o_right(int x,int y)
{
	bar(x*YG-10,(y-1)*YG+M,x*YG,y*YG+M,54903);	//211 206 189
	bar(x*YG-10,(y-1)*YG+M,x*YG,(y-1)*YG+M+1,44338);	//169 166 149
	bar(x*YG-10,y*YG+M,x*YG,y*YG+M-1,44338);	//169 166 149
}

void o_left(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+10,y*YG+M,54903);
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+10,(y-1)*YG+M+1,44338);
	bar((x-1)*YG,y*YG+M,(x-1)*YG+10,y*YG+M-1,44338);
}

void o_wall(int x, int y)
{
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+10,54903);
	bar((x-1)*YG,(y-1)*YG+M+10,x*YG,(y+1)*YG+M,44273);		//170 157 140
	bar((x-1)*YG,(y-1)*YG+M,x*YG,(y-1)*YG+M+2,35821);		//143 126 110
	bar((x-1)*YG,(y-1)*YG+M+10,x*YG,(y-1)*YG+M+12,35821);
	bar((x-1)*YG,(y-1)*YG+M+20,x*YG,(y-1)*YG+M+22,35821);
	bar((x-1)*YG,(y-1)*YG+M+30,x*YG,(y-1)*YG+M+32,35821);	//143 126 110
	bar((x-1)*YG,(y-1)*YG+M+40,x*YG,(y-1)*YG+M+42,35821);
	bar((x-1)*YG,(y-1)*YG+M+50,x*YG,(y-1)*YG+M+52,35821);	
	bar((x-1)*YG,(y-1)*YG+M+78,x*YG,(y-1)*YG+M+80,35821);	
	bar((x-1)*YG,(y-1)*YG+M,(x-1)*YG+1,(y+1)*YG+M,35821);
	bar(x*YG-1,(y-1)*YG+M,x*YG,(y+1)*YG+M,35821);	
}