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


void main()
{
	unsigned int a;
	int goin=0,finish=0,i,j,x,y,buttons;//返回1为验证失败
	
    
	
	SetSVGA64k();
    

    //CreateHouseFile();
	SetSVGA64k();
	a = GetSVGA();

	srand((int)time(0));
	
	
	
	
	outwelcome();
	getch();

	while(goin!=1)
	{
		goin = enterpage();
	}
    while(finish!=1)
    {
		finish = mainpage();
	}               
/*
	CreateHouseFile();

	srand((int)time(0));
	SetSVGA64k();



	mouseInit(&x,&y,&buttons);
	mousehide(x,y);
	mainprocess(&x,&y);*/
}
