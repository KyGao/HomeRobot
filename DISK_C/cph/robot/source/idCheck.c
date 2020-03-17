#include "main.h"//	验证码信息弹窗
#include <ctype.h>
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

	//	验证码弹窗
void message_box(char* id_real)
{
	int a,i;
	char b[5],c[2],d[2],e[2];
	
	//弹窗界面
	bar_round_2(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+96,10,1,65535);
	bar_round_2(ORIGINX+11,ORIGINY+46,ORIGINX+24,ORIGINY+56,4,1,18155);
	fdhz(ORIGINX+30,ORIGINY+44,1,1,"短",0);
	fdhz(ORIGINX+45,ORIGINY+44,1,1,"信",0);
	fdhz(ORIGINX+45,ORIGINY+60,1,1,"用",0);
	fdhz(ORIGINX+60,ORIGINY+60,1,1,"户",0);
	fdhz(ORIGINX+75,ORIGINY+60,1,1,"您",0);
	fdhz(ORIGINX+90,ORIGINY+60,1,1,"好",0);
	fdhz(ORIGINX+105,ORIGINY+60,1,1,"，",0);
	fdhz(ORIGINX+120,ORIGINY+60,1,1,"您",0);
	fdhz(ORIGINX+135,ORIGINY+60,1,1,"本",0);
	fdhz(ORIGINX+150,ORIGINY+60,1,1,"次",0);
	fdhz(ORIGINX+165,ORIGINY+60,1,1,"登",0);
	fdhz(ORIGINX+180,ORIGINY+60,1,1,"录",0);
	fdhz(ORIGINX+195,ORIGINY+60,1,1,"的",0);
	fdhz(ORIGINX+210,ORIGINY+60,1,1,"验",0);
	fdhz(ORIGINX+225,ORIGINY+60,1,1,"证",0);
	fdhz(ORIGINX+15,ORIGINY+75,1,1,"码",0);
	fdhz(ORIGINX+30,ORIGINY+75,1,1,"为",0);
	
	//随机数种子
	srand((unsigned)time(0));
	a=rand()%10000;
	itoa(a,b,5);
	/*itoa(a[1],c,5);
	itoa(a[2],d,5);
	itoa(a[3],e,5);
	b[1]='\0';
	c[1]='\0';
	d[1]='\0';
	e[1]='\0';*/
	b[4]='\0';			//存在问题，似乎每次出现的数字虽然不同，但都是3开头的
	
	for(i=0;i<5;i++){
		id_real[i] = b[i];
	}
	
	
	outtextxy(ORIGINX+40,ORIGINY+75,b,2,1,15,0);
	return b;
}


	

	//	验证码信息存储
void save_code(char* id_real)//id_real直接接上一级message_box的返回值，再传给下一级
{
	unsigned int *image_save=(unsigned int *)malloc(246*60*sizeof(unsigned int));	//	保存验证码弹窗背后的图案
		
	if(image_save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	get_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
	message_box(id_real);
	delay(1500);
	put_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
	free(image_save);
	image_save = NULL;
	
}


//	若输入手机号正确则iph_num为1，之后获取验证码时可以收到短信；否则收不到验证码
void input_num(int *mx,int *my,int *judge,unsigned int *text1save)
{
	char ph_num[12];	//保存字符串的数组
	char real_num[12] = {'0','0','0','0','0','0','0','0','0','0','0','\0'};
	char *p = ph_num;	//输入字符的中间指针变量,相当于ph_num[12]的手术刀
	int key;			//读取键值的标识
	int i=0;			//用于计算已输入字符数目
	char ch;			//用于临时储存键值所对应字符的变量
	int m_case=0;		//用于判断鼠标点击哪里并且进行下一步操作
	int button;
	char temp[2] = {'\0','\0'};	//	确保第二位是'\0'，到时候outtext出来的时候才能正常输出
	
	put_image(ORIGINX+60,ORIGINY+180,ORIGINX+245,ORIGINY+207,text1save);//(ORIGINX+60,ORIGINY+194,ORIGINX+170,ORIGINY+207,text1save);	//
	
	for(i=0;i<12;i++){
		ph_num[i] = '\0';
	}
	i=0;
	
	while(1)
	{
		newxy(mx,my,&button);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}			//清空键盘缓冲区//
		if(key == 0xe08)	//点击退格键时的操作
	    {
		    if(p != ph_num)		//检测是否是首位（地址是否相同）
		    {
			    bar(ORIGINX+50+ i * 13+3, ORIGINY+192, ORIGINX+50+18 + i * 13, ORIGINY+206,28153);
			    p--;			//指针		往前移
			    i--;			//记字数	往前移
		    }
			*p = '\0';			//	同样将最后一位换成'\0'
	    }
		
		//	将按键对应的字符一个个存入ph_num数组中
	    ch = searchKeyValue(key);
	    if ((ch != '\0') && (i<11) && (ch>='0') && (ch<='9'))	//一定要是数字才能输出
	    {
			temp[0] = ch;
			outtextxy(ORIGINX+50+5+i*13,ORIGINY+192,temp,2,1,10,0);

		//	将字符存入数组中
		    *p = ch;
		    p++;
		    *p = '\0';		// 每次操作都要归'\0'
		    i++;
	    }
		
		m_case = checkin_click(mx,my,button);	//	若鼠标点击输入手机号框则不发生任何事，若点击其他区域则跳出循环，回到主逻辑的鼠标检测逻辑
		if(m_case!=2 && m_case!=0 || key == 0x1c0d){
			break;
		}
	}
	
	ph_num[11] = '\0';

	if(strcmp(ph_num,real_num)==0){
		*judge=1;	//若输入手机号正确，则可接收到验证码
	}
	
	return;
}

	//	若输入验证码匹配则id_code为1，点击登录时成功，否则点击登录时跳出错误信息
void id_check(int *mx,int *my,char *id_code,unsigned int *text2save)
{
	char id_num[5];	//保存字符串的数组
	char *p = id_num;	//输入字符的中间指针变量,相当于ph_num[12]的手术刀
	int key;			//读取键值的标识
	int i=0;			//用于计算已输入字符数目
	char ch;			//用于临时储存键值所对应字符的变量
	int m_case=0;		//用于判断鼠标点击哪里并且进行下一步操作
	int button;
	char temp[2] = {'\0','\0'};	//	确保第二位是'\0'，到时候outtext出来的时候才能正常输出
	
	put_image(ORIGINX+60,ORIGINY+226,ORIGINX+245,ORIGINY+253,text2save);	
	
	for(i=0;i<5;i++){
		id_num[i] = '\0';
	}
	i=0;
	
	while(1)
	{
		newxy(mx,my,&button);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}			//清空键盘缓冲区//
		if(key == 0xe08)	//点击退格键时的操作
	    {
		    if(p != id_num)		//检测是否是首位（地址是否相同）
		    {
			    bar(ORIGINX+50+ i * 13+3, ORIGINY+239, ORIGINX+50+18 + i * 13, ORIGINY+251,28153);
			    p--;
			    i--;
		    }
			*p = '\0';			//	同样将最后一位换成'\0'
	    }
		
		//	将按键对应的字符一个个存入id_num数组中
	    ch = searchKeyValue(key);
	    if ((ch != '\0') && (i<4) && (ch>='0') && (ch<='9'))	//一定要是数字才能输出
	    {
			temp[0] = ch;
			outtextxy(ORIGINX+50+5+i*13,ORIGINY+238,temp,2,1,10,0);

		//	将字符存入数组中
		    *p = ch;
		    p++;
		    *p = '\0';		// 每次操作（进位后）都要归'\0'
		    i++;
	    }
		
		m_case = checkin_click(mx,my,button);	//	若鼠标点击输入验证码框则不发生任何事，若点击其他区域则跳出循环，回到主逻辑的鼠标检测逻辑
		if(m_case!=3 && m_case!=0 || key == 0x1c0d){
			break;
		}
	}
	
	id_num[4] = '\0';
	for(i=0;i<5;i++){
		id_code[i] = id_num[i];
	}
	
}