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
#define PI 3.1415926

/*****************************
欢迎界面，登录注册界面及调用相关函数的逻辑（相关函数在filefun,sign中）
void outwelcome(void);
void load_page(void);
void zhuce_page(void);
int enterpage(void);
int mainpage(void)
******************************/
/*欢迎界面，天空，机器人，街道和房子*/
void outwelcome(void)
{
	/*背景图*/
	linever_color(0,0,1024,500,0,191,255,255,222,173);
	/*立体字效果*/
	fdhz(78,78,4,4,"家居机器人模拟器",65535);
	fdhz(82,78,4,4,"家居机器人模拟器",65535);
	fdhz(78,82,4,4,"家居机器人模拟器",65535);
	fdhz(82,82,4,4,"家居机器人模拟器",65535);
	fdhz(80,80,4,4,"家居机器人模拟器",transcolor(0,191,255));
	/*机器人*/
	FillCircle(250,450,120,255);
	FillCircle(250,480,96,65535);
	circle(250,480,96,0);
	fill_bow_right_down(250,450,70,transcolor(255,0,0));
    fill_bow_left_down(250,450,70,transcolor(255,0,0));
	bow_left_down(250,450,70,0);
    bow_right_down(250,450,70,0);
	fill_bow_down(250,350,120,65535);
	fill_bow_right_up(250,520,40,transcolor(240,128,128));
	fill_bow_left_up(250,520,40,transcolor(240,128,128));
	Fillellipse(223,365,223,385,25,65535);
	Fillellipse(277,365,277,385,25,65535);
	ellipse(223,365,223,385,25,0);
	ellipse(277,365,277,385,25,0);
	Fillellipse(230,360,230,380,8,0);
	Fillellipse(270,360,270,380,8,0);
	FillCircle(230,365,4,65535);
	FillCircle(270,365,4,65535);
	FillCircle(250,420,20,40966);
	
	
	/*街道*/
	bar(0,500,1024,768,transcolor(168,168,168));
	theta_bar(130,768,250,375,-45,transcolor(105,105,105));
	theta_bar(380,768,245,210,-45,transcolor(105,105,105));
	theta_bar(400,500,250,400,45,transcolor(105,105,105));
	theta_bar(410,600,250,400,45,transcolor(105,105,105));
	
	theta_bar(135,768,70,120,-45,transcolor(220,220,220));
	theta_bar(273,630,60,80,-45,transcolor(220,220,220));
	theta_bar(363,540,50,40,-45,transcolor(220,220,220));
	
	theta_bar(608,513,50,40,45,transcolor(220,220,220));
	theta_bar(653,570,60,80,45,transcolor(220,220,220));
	theta_bar(760,683,70,120,45,transcolor(220,220,220));
	
	/*房子*/
	bar(700,400,900,500,0);
	bar(701,400,899,500,transcolor(205,133,63));
	window_close(20,11);
	linelevel(700,405,900,405,1,0);
	linelevel(700,402,900,402,1,0);
	bar(700,406,710,500,65535);
	bar(890,406,900,500,65535);
	bar(700,300,900,400,transcolor(205,133,63));
	bar(700,300,710,400,65535);
	bar(890,300,900,400,65535);
	linelevel(710,395,890,395,1,0);
	linelevel(710,392,890,392,1,0);
	triangle2(800,220,70,transcolor(165,42,42));
	bar(650,290,950,300,65535);
}

/*登录界面（静态）*/
void load_page(void)
{
	   bar(0,0,1024,768,1503);
	   FillCircle(200,150,80,34429);
	   FillCircle(700,300,200,34431);
       bar_round_with_shadow(500,200,400,50,5,1,65535);
       bar_round_with_shadow(500,350,400,50,5,1,65535);
	   fdhz(250,190,1,1,"帐",0);
	   fdhz(270,190,1,1,"号",0);
	   fdhz(250,340,1,1,"密",0);
	   fdhz(270,340,1,1,"码",0);
	   bar_round(300,600,200,150,20,1,31694);
	   bar_round(700,600,200,150,20,1,31694);
       fdhz(240,570,3,3,"登",0);
	   fdhz(320,570,3,3,"录",0);
	   fdhz(640,570,3,3,"注",0);
	   fdhz(720,570,3,3,"册",0);
}

/*注册界面（静态）*/
void zhuce_page(void)
{
	bar(0,0,1024,768,1503);
	fdhz(370,80,2,3,"注",0);
	fdhz(600,80,2,3,"册",0);
	bar_round_with_shadow(100,100,50,50,3,1,255);
	bar_round_with_shadow(500,200,200,30,5,1,65535);//用户名
    bar_round_with_shadow(500,300,200,30,5,1,65535);//密码
    bar_round_with_shadow(500,400,200,30,5,1,65535);//再次输入密码
	bar_round_with_shadow(500,700,100,50,5,1,255);
	fdhz(320,200,1,1,"帐",0);
	fdhz(340,200,1,1,"号",0);
	fdhz(320,300,1,1,"密",0);
	fdhz(340,300,1,1,"码",0);
	fdhz(460,680,2,2,"完",0);
	fdhz(510,680,2,2,"成",0);
	outtextxy(83,95,"back",1,1,10,65535);
}

/*登录界面逻辑
判断变量judge:
1:登录成功
2:输入id
3:输入password 
5：返回登录界面*/
int enterpage(void)
{
	USERS user;
	USERS *head = NULL;
	int temp,error=0;
	int button,x,y,judge=0;
	user.account[0] = '\0';
	user.code[0] = '\0';
	
	if ((head = (USERS *)malloc(sizeof(USERS))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	CreateUserList(head);
	load_page();
	mouseInit(&x, &y,&button);
    while(1)

	{
		newxy(&x, &y, &button);
				    /*初始化，接受缓冲区数据*/
		
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}

		/*登录*/
		if(x>=200&&x<=400&&y<=675&&y>=525&&button)
		{
			linelevel(220,525,385,525,2,65535);
            linelevel(220,673,385,673,2,0);
			linever(200,535,200,655,2,65535);
			linever(400,535,400,655,2,0);
			delay0(10);
			linelevel(220,673,385,673,2,31694);
			linelevel(220,525,385,525,2,31694);
			linever(200,535,200,655,2,31694);
			linever(400,535,400,655,2,31694);
			judge = sign_in_check(head,&user.account,&user.code);
			
		}

		
			/*注册*/
		if(x>=600&&x<=800&&y>=525&&y<=675&&button)
		{
			linelevel(620,525,785,825,2,65535);
            linelevel(620,673,785,673,2,0);
			linever(600,535,600,655,2,65535);
			linever(800,535,800,655,2,0);
			delay0(10);
			linelevel(620,673,785,673,2,31694);
			linelevel(620,525,785,525,2,31694);
			linever(600,535,600,655,2,31694);
			linever(800,535,800,655,2,31694);
			judge = UserRegist(head,&user.account,&user.code,&x,&y,&button);
		}

		if(x>=300&&x<=700&&y>=175&&y<=225&&button)
		{
			judge = 2;
		}
		
		if(x>=300&&x<=700&&y>=325&&y<=375&&button)
		{
			judge = 3;
		}
		
		if(judge==2)//输入id
		{
			judge = input_account(head,&user.account,&user.code,&x,&y);

		}
		if(judge==3)//输入password
		{
			judge = input_code(head,&user.account,&user.code,&x,&y);
		}
		if(judge==1)
		{
			freeUserlist(&head);
			return 1;
		}
		//返回登录界面
		if(judge==5)
		{
			return 5;
		}

	}
}

/*点击手机进入系统，并开启主进程*/
int mainpage(void)
{
	int fail,x,y;
	bar(1,1,1024,767,65535);
	
    fail = dis_iph(&x,&y);
    if(fail==-1)
	{
		//以某种方式显示错误
		null_box(500,500);
		getch();
	}
	mainprocess(&x,&y);
	
}
