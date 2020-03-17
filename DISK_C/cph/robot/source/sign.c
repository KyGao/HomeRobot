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
int input_account(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *p=account;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;
	char temp[2] = {'\0','\0'};
	
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(p != account)
		    {
			    bar(290 + i * 18, 195, 310 + i * 18, 213,65535);
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//防止鼠标遮挡
		if(*x>=300&&*x<=700&&*y>=175&&*y<=225)
		{
			mousehide(*x,*y);
		}
		
		//登录键
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&buttons)
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
			judge = sign_in_check(head,account,code);
			return judge;
		}
		
		//密码输入
		if(*x>=300&&*x<=700&&*y>=325&&*y<=375&&buttons)
		{
			return 3;
		}
		
		
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&buttons)
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
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}
		
		
	/*将按键对应的字符存入account中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			temp[0] = ch;
			outtextxy(300+i*18,195,temp,2,1,10,0);


		/*将字符存入数组中*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }
	}
}

int input_code(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *u = code;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;

	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(u != code)
		    {
			    bar(275 + i * 25, 335, 305 + i * 25, 360,65535);
			    u--;
			    i--;
		    }
			*u = '\0';
	    }
		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//登录键
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&buttons)
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
			judge = sign_in_check(head,account,code);
			return judge;
		}
		
		//防止输入时遮挡
		if(*x>=300&&*x<=700&&*y>=325&&*y<=375)
		{
			mousehide(*x,*y);
		}
	
	
		//输入账号
		if(*x>=300&&*x<=700&&*y>=175&&*y<=225&&buttons)
		{
			
			return 2;
		}
		
		//注册框
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&buttons)
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
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}
		
		
	/*将按键对应的字符存入code数组中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
		    
		    
		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(315+i*25,350,8,0);
		    
		/*将字符存入数组中*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
}

/***********************************************************
Function: RegisteraccountsInput
Description: 1、用户注册界面的账号输入函数
             2、只能是大小写字母与数字
             3、能输入1到10位
Attention:鼠标位置参数必须要以指针形式传递过来！
Return:返回2在userRegister中调用LogincodeInput函数
       返回3在userRegister中调用RegistersecondcodeInput函数
       返回4在userRegister中使用登陆功能
       返回5在userRegister中使用注册功能
************************************************************/
int RegisteraccountsInput(char *account, int *mx, int *my)
{
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = account;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int buttons;    //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组


    /*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}



	while (1)
	{
		newxy(mx, my, &buttons);

		/*重置键值并得到新键值*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		
		/*if(按了一次enter键或鼠标点击密码输入区域或按了一次下方向键)返回2表示调用RegistercodeInput函数*/
		if (*mx >= 400 && *mx <= 600&& *my >= 285 && *my <= 315 && buttons || key == 0x1c0d || key == 0x5000)
		{
			return 2;
		}

		/*if（鼠标点击再一次输入密码区域）返回3表示调用RegistersecondcodeInput函数*/
		if (*mx >= 400 && *mx <= 600 && *my >= 385 && *my <= 415 && buttons)
		{
			return 3;
		}

		/*if(点击注册完成区域)返回4表示注册完成并发送登录请求 */
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{
			return 4;
		}

		/*if(点击已有账号并登录区域)返回5表示返回登陆界面*/
		if (*mx >= 75 && *mx <= 125 && *my >= 75 && *my <= 125 && buttons)
		{
			return 5;
		}

		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != account)
			{
				
				bar(385 + i * 18, 185, 405 + i * 18, 213,65535);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入accounts数组中*/
		ch = searchKeyValue(key);
		temp[0] = ch;
		
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

            outtextxy(390+i*18,195,&temp,1,1,8,0);

		}

	}
}

/***********************************************************
Function: RegistercodeInput
Description: 1、用户注册界面的密码输入函数
             2、只能是大小写字母与数字
             3、能输入1到10位
Attention:鼠标位置参数必须要以指针形式传递过来！
Return:返回1在userRegister中调用RegisteraccountsInput函数
       返回3在userRegister中调用RegistersecondcodeInput函数
       返回4在userRegister中使用登陆功能
       返回5在userRegister中使用注册功能
************************************************************/
int RegistercodeInput(char *code, int *mx, int *my) //登陆界面新密码输入函数
{
	int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = code;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int buttons;     //鼠标的参数变量

	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);

		/*重置键值并得到新键值*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		/*if(鼠标点击账号输入区域或按了一次上方向键)返回1表示调用RegisteraccountsInput函数*/
		if (*mx >= 400 && *mx <= 600&& *my >= 185 && *my <= 215 && buttons || key == 0x4800)
		{

			return 1;
		}

		/*if(鼠标点击再次输入密码区域或按了一次enter键或下方向键) 返回3表示调用RegistersecondcodeInput函数*/
		if (*mx >= 400 && *mx <= 600 && *my >= 385 && *my <= 415 && buttons || key == 0x5000 || key == 0x1c0d)
		{

			return 3;
		}

		/*if(点击注册完成区域) 返回4表示注册完成并登陆*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{

			return 4;
		}

		/*if(点击已有账号区域) 返回5表示返回登陆界面*/
		if (*mx >= 75 && *mx <= 125 && *my >= 75 && *my <= 125 && buttons)
		{

			return 5;
		}

		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				bar(385 + i * 15, 285, 398 + i * 15, 305,65535);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将键值存入code数组*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

			FillCircle(392 + i * 15, 297, 5, 0);


		}
	}
}


/***********************************************************
Function: RegistersecondcodeInput
Description: 1、用户注册界面的密码第二次输入函数
             2、只能是大小写字母与数字
             3、能输入1到10位
Attention:鼠标位置参数必须要以指针形式传递过来！
Return:返回1在userRegister中调用RegisteraccountsInput函数
       返回2在userRegister中调用RegistercodeInput函数
	   返回4在userRegister中使用登陆功能
	   返回5在userRegister中使用注册功能
************************************************************/
int RegistersecondcodeInput(char *secondcode, int *mx, int *my)
{
	int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = secondcode;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int buttons=0; 



	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);

		/*重置键值并得到新键值*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		/*if(鼠标点击账号输入区域)返回1表示调用RegisteraccountsInput函数*/
		if (*mx >= 400 && *mx <= 600&& *my >= 185 && *my <= 215 && buttons)
		{
			
			return 1;
		}

		/*if(鼠标点击新密码输入区域或按了一下上方向键)返回2表示调用RegistercodeInput函数*/
		if (*mx >= 400 && *mx <= 600 && *my >= 285 && *my <= 315 && buttons || key == 0x4800)
		{
	
			return 2;
		}

		/*if(按了一次enter键或点击登陆区域)返回4表示注册完成并登陆*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons || key == 0x1c0d)
		{

			return 4;
		}

		/*if(点击已有账号区域)返回5表示返回登陆界面*/
		if (*mx >= 75 && *mx <= 125 && *my >= 75 && *my <= 125 && buttons)
		{
			return 5;
		}

		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != secondcode)
			{
				bar(385 + i * 15, 385, 398 + i * 15, 405,65535);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将键值存入secondcode数组*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;


			FillCircle(392 + i * 15, 397, 5, 0);


		}
	}
}

int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *buttons)
{
	int judge = 0; //判断应该调用那些函数的变量
	int flag1 = 0, flag2 = 0, flag3 = 0;  //分别为为用户名、密码、二次密码是否正确的判断变量
	int temp;  //用于吸收键盘缓冲区的变量
	char secondcode[11];  //第二次输入密码串
    

	/*必要的初始化过程*/
	secondcode[0] = '\0';
	*account = '\0';
	*code = '\0';
	mousehide(*x,*y);
    zhuce_page();
	reset_mouse(x,y);
	while (1)
	{
		newxy(x, y, buttons);

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}
		
		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}
		
		//返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 5;
		}
		//注册并登录
		if(*x>=450&&*x<=550&&*y>=675&&*y<=725&&*buttons)
		{
			judge = 4;
			//yanzheng
		}
		//账号输入
		if(*x>=400&&*x<=600&&*y>=185&&*y<=215&&*buttons)
		{
			judge = 1;
		}
		//密码
		if(*x>=400&&*x<=600&&*y>=285&&*y<=315&&*buttons)
		{
			judge = 2;
		}
		//二次确认密码
		if(*x>=400&&*x<=600&&*y>=385&&*y<=415&&*buttons)
		{
			judge = 3;
		}
		
		
		
		switch(judge)
		{
		
		//调用账号输入函数
		case 1:
		    judge = RegisteraccountsInput(account, x, y);
		    if (SearchAccounts(head, account) != NULL)
			{
				/*画红色的叉并提示该账号已被注册&flag1=0*/
				bar(800,180,900,250,1503);
				red_cross(800,200);
				bar(210,500,900,530,1503);
				fdhz(210,500,1,1,"该账号已被注册",0);
/*此处动画可能需要修改
				setfillstyle(1, LIGHTBLUE);
				bar(560, 120, 600, 165);
				drawRedFork(560, 130);
				backgroundChange(mx,my,560, 120, 600, 165);
				setfillstyle(1, LIGHTBLUE);
				bar(210, 170, 550, 195);
				fdhz(210,170, "璇ヨ处鍙峰凡琚敞鍐岋紒", 16, 16, RED);
				backgroundChange(mx,my,210, 170, 550, 195);
*/
				flag1 = 0;
			}
		    else
			{
				/*画一个绿色的勾&falg1=1*/
/*
				setfillstyle(1, LIGHTBLUE);
				bar(210, 170, 550, 195);
				bar(560, 120, 600, 165);
				drawGreenHook(560, 130);
				backgroundChange(mx,my,560, 120, 600, 165);
				backgroundChange(mx,my,210, 170, 550, 195);
*/              
                bar(800,180,900,250,1503);
                green_tick(800,200);
				flag1 = 1;

			}
			break;
		/*case 2:调用密码输入函数*/
		case 2:
			judge = RegistercodeInput(code, x, y);
			if (strlen(code) < 6)
			{
				/*画红色的叉并提示密码不得少于六位&flag2=0*/
/*
			   setfillstyle(1, LIGHTBLUE);
				bar(560, 200, 600, 245);
				drawRedFork(560, 210);
				backgroundChange(mx, my, 560, 200, 600, 245);
				setfillstyle(1, LIGHTBLUE);
				bar(210, 250, 550, 275);
				puthz(210, 250, "瀵嗙爜涓嶅緱灏戜簬鍏綅锛?, 16, 16, RED);
				backgroundChange(mx, my, 210, 250, 550, 275);
*/
                bar(800,280,900,350,1503);
                red_cross(800,300);
				bar(210,500,500,530,1503);
				fdhz(210,500,1, 1, "密码不得少于六位",  0);
				flag2 = 0;
			}
			else
			{
				/*画一个绿色的勾&flag2=1*/
/*
				setfillstyle(1, LIGHTBLUE);
				bar(210, 250, 550, 275);
				bar(560, 200, 600, 245);
				drawGreenHook(560, 210);
				backgroundChange(mx, my, 560, 200, 600, 245);
				backgroundChange(mx, my, 210, 250, 550, 275);
*/
                bar(210,500,900,530,1503);
                bar(800,280,900,350,1503);
                green_tick(800,300);
				flag2 = 1;
			}
			break;

		/*case 3:调用二次密码输入函数*/
		case 3:
			judge = RegistersecondcodeInput(secondcode, x, y);
			if (strcmp(code, secondcode) != 0)
			{
				/*画红色的叉并提示两次密码输入不同&&flag3=0*/
				
				/*
                setfillstyle(1, LIGHTBLUE);
				bar(560, 280, 600, 325);
				drawRedFork(560, 290);
				backgroundChange(mx, my, 560, 280, 600, 325);
				setfillstyle(1, LIGHTBLUE);
				bar(210, 330, 550, 355);
				puthz(210, 330, "涓ゆ瀵嗙爜杈撳叆涓嶅悓锛?, 16, 16, RED);
				backgroundChange(mx, my, 210, 330, 550, 355);
*/
                bar(800,380,900,450,1503);
                red_cross(800,400);
				bar(210,500,900,530,1503);
				fdhz(210,500, 1, 1, "两次输入的密码不同", 0);
				flag3 = 0;
			}
			else
			{
				/*画一个绿色的勾&flag3=1*/
/*
                setfillstyle(1,LIGHTBLUE);
				bar(210, 330, 550, 355);
				bar(560, 280, 600, 325);
				drawGreenHook(560, 290);
				backgroundChange(mx, my, 560, 280, 600, 325);
				backgroundChange(mx, my, 210, 330, 550, 355);
*/
                bar(210,700,900,750,1503);
                bar(800,380,900,450,1503);
                green_tick(800,400);

				flag3 = 1;
			}
			break;

		/*case 4:判断是否注册成功*/
		case 4:if (flag1 == 1 && flag2 == 1 && flag3 == 1)
		{
			AddNewUser(head, account, code);
			/*
			if(Choose("注册成功！\n是否自动登录？",&mx,&my,GREEN)==1)return 2;
			else return 0;*/
			return 1;
		}
			   break;

	    /*case 5:返回登录界面*/
		case 5: return 5;
		
		}
		
	}
}

int sign_in_check(USERS *head,char *account,char *code)
{
	char *rightcode= NULL;
	rightcode = SearchAccounts(head, account);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //登录成功
	else
	{
		fdhz(410, 300,1, 1, "用户名或密码输入错误", 0);
        getch();
		return 5;
	}
}
