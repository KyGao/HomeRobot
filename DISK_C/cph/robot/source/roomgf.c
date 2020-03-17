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
/********************************************
绘制房间中的物件的函数
除seat,CutMachine1,2外输入的坐标值均为以(1,1)为起始点的相对坐标
********************************************/
void trashbin(int x,int y)
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x+15,y,x+35,y+40,65187);
	ever_Fillellipse(x+23,y,x+27,y,8,65187);
	ever_Fillellipse(x+23,y,x+27,y,6,0);
	ever_Fillellipse(x+23,y,x+27,y,5,65535);
}

void door(int x,int y)
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x-55,y-30,x+55,y+70,35362);
	bar(x-50,y-20,x-3,y+20,17);
	bar(x+5,y-20,x+50,y+20,17);
	linever(x,y-30,x,y+70,2,0);
}

void brick0(int x,int y)//左上角坐标
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if((i+j)%2==0)
			{
				bar(x+i*14+1,y+j*14+1,x+12+i*14+1,y+12+j*14+1,65535);
			}
			else
			{
				bar(x+i*14+1,y+j*14+1,x+12+i*14+1,y+12+j*14+1,63281);
			}
		}
	}
	linever(x,y,x,y+40,1,0);
    linever(x+12+1,y,x+12+1,y+40,1,0);
	linever(x+26+2,y,x+26+2,y+40,1,0);
	linever(x+39,y,x+39,y+40,1,0);
	linelevel(x,y,x+40,y,1,0);
	linelevel(x,y+12+1,x+40,y+12+1,1,0);
	linelevel(x,y+26+2,x+40,y+26+2,1,0);
	linelevel(x,y+39,x+40,y+39,1,0);
}

void floor0()
{
	int i,j;
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
		{
			brick0(i*40,j*40);
		}
}

void tree(int x,int y)//树底部坐标
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x-5,y-40,x+5,y,41605);
	triangle1(x,y-90,50,40915);
	triangle1(x,y-120,50,40915);
}

void bed(int x,int y)
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	theta_bar(x-5,y-48,30,4,-45,62604);
	theta_bar(x+20,y-50,32,4,45,62604);
	lean_line(x,y-48,4,-45,0);
	lean_line(x+48,y-50,4,45,0);
	bar(x-5,y-48,x+55,y-32,52263);
	bar(x-5,y-32,x+55,y+42,65535);
	bar(x+4,y-35,x+46,y-15,0);
	bar(x+5,y-35,x+45,y-15,65535);
	fill_bow_right_down(x+25,y-48,20,52263);
	fill_bow_left_down(x+25,y-48,20,52263);
	fill_bow_up(x+25,y+21,43,64950);
	bar(x-3,y-7,x+53,y+10,64950);
	fill_bow_up(x+25,y+28,40,65535);
	bar(x-4,y,x+54,y+42,0);
	bar(x-3,y,x+53,y+42,65535);
	bar(x-5,y+53,x+2,y+59,52263);
	bar(x+48,y+53,x+55,y+59,52263);
	bar(x-5,y+42,x+55,y+55,44373);
	bar(x-5,y+42,x+2,y+55,57083);
	bar(x+11,y+42,x+18,y+55,57083);
	bar(x+32,y+42,x+39,y+55,57083);
	bar(x+48,y+42,x+55,y+55,57083);
	linelevel(x-3,y+42,x+53,y+42,3,42260);
	linever(x+2,y+45,x+2,y+55,1,0);
	linever(x+11,y+45,x+11,y+55,1,0);
	linever(x+18,y+45,x+18,y+55,1,0);
	linever(x+32,y+45,x+32,y+55,1,0);
	linever(x+39,y+45,x+39,y+55,1,0);
	linever(x+48,y+45,x+48,y+55,1,0);
	fill_bow_down(x-2,y+53,4,65535);
    fill_bow_down(x+14,y+53,4,65535);
	fill_bow_down(x+36,y+53,4,65535);
	fill_bow_down(x+53,y+53,4,65535);
	linelevel(x-5,y-48,x+55,y-48,1,0);
	linever(x,y-48,x,y-32,1,0);
	linever(x+50,y-48,x+50,y-32,1,0);
}

void window_close(int x,int y)
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y+10,x+80,y+35,27469);
	bar(x+3,y+13,x+77,y+32,17430);
	bar(x+35,y+12,x+45,y+32,29714);
	linever(x+40,y+10,x+40,y+35,1,0);
}

void window_open(int x,int y)
{
	int i,x0,y0;
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y+10,x+80,y+35,6350);
	for(i=0;i<3;i++)
	{
		//star
		x0 = x+30+rand()%50;
		y0 = y+10+ rand()%25;
		FillCircle(x0,y0,1,65535);
		
	}
	//moon
	FillCircle(x+25,y+20,5,65187);
	FillCircle(x+28,y+20,5,6350);
}



void cupboard(int x,int y)
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	theta_bar(x,y+5,20,10,-30,56612);
	theta_bar(x+12,y,20,10,30,56612);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,56612);
	linelevel(x,y+5,x+40,y+40,1,0);
	linever(x+20,y+5,x+20,y+40,1,0);
	circle(x+16,y+20,2,0);
	circle(x+24,y+20,2,0);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
}

void weed(int x,int y)//40*40
{
    //int color = 13925;	
	int color = 800;
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x+17,y,x+23,y+40,color);
	theta_bar(x+20,y+20,10,15,-45,color);
	theta_bar(x+5,y+30,5,15,45,color);
}

void aircon(int x,int y,int open)//80*40,open==1为开启
{
	
	int color[2] = {2016,55463};
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y+10,x+80,y+40,65535);
	linelevel(x,y+30,x+80,y+30,1,0);
	linever(x+4,y+30,x+4,y+40,1,0);
	linever(x+76,y+30,x+76,y+40,1,0);
	linelevel(x+10,y+34,x+70,y+34,1,0);
	linelevel(x+10,y+37,x+70,y+37,1,0);
	if(open)
	{
		FillCircle(x+5,y+15,3,color[0]);
	}
	else
	{
		FillCircle(x+5,y+15,3,color[1]);
	}
	
}

void WashMach(int x,int y)//40*40
{
	int color[3] = {17430/*钢蓝*/,29714/*石板灰*/,50712/*灰色，用于制作阴影效果*/};
	x = (x-1)*40;
	y = (y-1)*40+4;

	theta_bar(x,y+5,20,10,-30,color[2]);
	theta_bar(x+12,y,20,10,30,color[2]);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
	bar(x,y+5,x+40,y+40,0);
	bar(x+1,y+6,x+39,y+39,65535);
	linelevel(x,y+5,x+40,y+5,1,0);
	FillCircle(x+20,y+23,10,color[1]);
	FillCircle(x+20,y+23,7,color[0]);
	circle(x+20,y+23,8,0);

}


void bookshelf(int x,int y)//40*80
{
	int color[5] = {44373,64033,64594,34816,45312};//深灰色，橙红色，深橙色，深红色，耐火砖
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y,x+40,y+2,65535);
	bar(x,y+40,x+40,y+42,65535);
	bar(x,y+2,x+2,y+40,color[0]);
	bar(x+38,y+2,x+40,y+40,color[0]);
	bar(x,y+42,x+2,y+80,color[0]);
	bar(x+38,y+42,x+40,y+80,color[0]);
	
	//book
	bar(x+2,y+30,x+7,y+40,color[1]);
	bar(x+7,y+30,x+12,y+40,color[2]);
	bar(x+12,y+20,x+20,y+40,color[3]);
	bar(x+20,y+20,x+28,y+40,65535);
	bar(x+28,y+20,x+36,y+40,color[4]);
}

void table(int x,int y)//80*40
{
	int color[2] = {54083,41605};//巧克力色，黄锗土色
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y,x+80,y+25,color[0]);
	bar(x,y+25,x+80,y+32,color[1]);
	bar(x,y+32,x+10,y+40,color[1]);
	bar(x+70,y+32,x+80,y+40,color[1]);
	
}

void seat(int x,int y)//40*40,控制在12至28之间
{
	//int color = 64950;//LightPink
	int color = 64340;//HotPink
	/*
	x = (x-1)*40;
	y = (y-1)*40+4;
	
	bar(x+11,y+10,x+30,y+30,0);
	bar(x+12,y+11,x+29,y+29,color);
	ever_Fillellipse(x+15,y+10,x+25,y+10,5,0);
	ever_Fillellipse(x+15,y+10,x+25,y+10,4,color);
	*/
	bar(x+13,y+14,x+27,y+29,0);
	bar(x+14,y+15,x+26,y+28,color);
	ever_Fillellipse(x+18,y+14,x+22,y+14,4,0);
	ever_Fillellipse(x+18,y+14,x+22,y+14,3,color);
}

void trash1(int x,int y)//40*40，纸张
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	FillCircle(x+20,y+30,5,transcolor(189,183,107));
	triangle1(x+12,y+23,7,transcolor(189,183,107));
	triangle1(x+25,y+12,10,transcolor(189,183,107));
	lean_line(x+25,y+30,7,-45,0);
	bow(x+23,y+21,12,0);
	
}

void trash2(int x,int y)//40*40,菜叶
{
    x = (x-1)*40;
    y = (y-1)*40+4;
    linever(x+20,y+15,x+20,y+25,2,transcolor(127,255,0));
    linever(x+14,y+15,x+14,y+25,2,transcolor(127,255,0));
    linever(x+18,y+15,x+18,y+25,2,transcolor(127,255,0));
    lean_line(x+20,y+25,10,45,transcolor(127,255,0));
    lean_line(x+14,y+25,10,45,transcolor(127,255,0));
	lean_line(x+18,y+25,10,45,transcolor(127,255,0));
}

void trash3(int x,int y)//40*40,果核
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x+18,y+10,x+22,y+25,transcolor(255,215,0));
	ever_Fillellipse(x+12,y+10,x+28,y+10,3,63488);
	linever(x+20,y,x+20,y+10,1,0);
}

void pc(int x,int y)
{
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y,x+40,y+20,0);
	bar(x+2,y+2,x+38,y+18,65535);
	bar(x+16,y+20,x+24,y+25,0);
	bar(x+12,y+25,x+28,y+28,0);
}

void TV(int x,int y)//40*40+天线
{
	int color = 44373;
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar(x,y,x+40,y+40,0);
	bar_round(x+20,y+20,30,30,8,1,color);
	bar(x+4,y-10,x+5,y,0);
	bar(x+3,y-11,x+6,y-10,0);
}

//木条纹方桌
void rect_table(int x,int y)//80*80
{
	int i;
	int color[3]={63222,54705,35362};
	x = (x-1)*40;
	y = (y-1)*40+4;
	bar_round(x+40,y+35,80,70,3,1,0);
	bar_round(x+40,y+35,78,68,3,1,color[1]);
	bar(x+5,y+1,x+7,y+69,color[0]);
	bar(x+5+1*15,y+1,x+9+1*15,y+69,color[0]);
	bar(x+5+2*15,y+1,x+13+2*15,y+69,color[0]);
	bar(x+5+48,y+1,x+9+3*15,y+69,color[0]);
	bar(x+5+64,y+1,x+7+4*15,y+69,color[0]);
	theta_bar(x,y+71,50,6,45,color[2]);
	theta_bar(x+40,y+74,38,5,-45,color[2]);
	bar(x+10,y+75,x+14,y+80,color[2]);
	bar(x+68,y+75,x+74,y+80,color[2]);
}

//配套的坐垫,left
void seat1(int x,int y)//40*80
{
	x = (x-1)*40;
	y = (y-1)*40;
	ever_Fillellipse(x+17,y+38,x+27,y+38,10,0);
	ever_Fillellipse(x+15,y+35,x+25,y+35,10,56210);
}


//配套的坐垫,right
void seat2(int x,int y)//40*80
{
	x = (x-1)*40;
	y = (y-1)*40;
	ever_Fillellipse(x+17,y+38,x+27,y+38,10,0);
	ever_Fillellipse(x+15,y+35,x+25,y+35,10,11338);
}

//配套的坐垫,up
void seat3(int x,int y)//40*80
{
	x = (x-1)*40;
	y = (y-1)*40;
	ever_Fillellipse(x+37,y+22,x+47,y+22,10,0);
	ever_Fillellipse(x+35,y+20,x+45,y+20,10,34431);
}


//配套的坐垫,down
void seat4(int x,int y)//40*80
{
	x = (x-1)*40;
	y = (y-1)*40;
	ever_Fillellipse(x+37,y+22,x+47,y+22,10,0);
	ever_Fillellipse(x+35,y+20,x+45,y+20,10,56612);
}

//大垃圾桶
void big_trashbin(int x,int y)//40*80
{
	int color[3] = {17430/*钢蓝*/,29714/*石板灰*/,50712/*灰色，用于制作阴影效果*/};
	x = (x-1)*40;
	y = (y-1)*40;
	theta_bar(x,y+5,20,10,-30,color[2]);
	theta_bar(x+12,y,20,10,30,color[2]);
	lean_line(x,y+5,10,-30,0);
	lean_line(x+31,y,10,30,0);
	linelevel(x+8,y,x+30,y,1,0);
	bar(x,y+5,x+40,y+80,0);
	bar(x+1,y+6,x+39,y+79,color[1]);
	bar(x,y+5,x+40,y+10,color[2]);
	linelevel(x,y+5,x+40,y+5,1,0);
	Fillellipse(x+10,y+25,x+10,y+65,2,color[2]);
	Fillellipse(x+20,y+25,x+20,y+65,2,color[2]);
	Fillellipse(x+30,y+25,x+30,y+65,2,color[2]);
}

void Cut_Machine1(int xpixel,int ypixel)//80*40,x从0到28(为了防止运动时遮挡),柄在右
{
	/*
	x = (x-1)*40;
	y = (y-1)*40;
	bar_round_2(x,y+10,x+40,y+35,3,1,29714);
	bar(x,y+35,x+40,y+40,0);
	theta_bar(x+35,y+10,5,16,-30,0);
	*/
	bar_round_2(xpixel+1,ypixel+10,xpixel+39,ypixel+35,3,1,29714);
	bar(xpixel+1,ypixel+35,xpixel+39,ypixel+39,0);
	theta_bar(xpixel+35,ypixel+10,5,16,-30,0);
}
void Cut_Machine2(int xpixel,int ypixel)//80*40,柄在左
{
	bar_round_2(xpixel+40,ypixel+10,xpixel+80,ypixel+35,3,1,29714);
	bar(xpixel+40,ypixel+35,xpixel+80,ypixel+39,0);
	theta_bar(xpixel+32,ypixel+2,5,16,30,0);
}


/*                 7                                       
                  ***
                1 * * 6
                  ***  5 
                2 * * 4
				  ***
                   3                              */
void show_num(int x,int y,int num)//x,y为左上角坐标，大小20*40;
{
	switch(num)
	{
		case 0:
		{
			Fillellipse(x+3,y+3,x+3,y+13,2,2047);//1
			Fillellipse(x+3,y+27,x+3,y+37,2,2047);//2
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 1:
		{
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			break;
		}
		case 2:
		{
			Fillellipse(x+3,y+27,x+3,y+37,2,2047);//2
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 3:
		{
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 4:
		{
			Fillellipse(x+3,y+3,x+3,y+13,2,2047);//1
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			break;
		}
		case 5:
		{
			Fillellipse(x+3,y+3,x+3,y+13,2,2047);//1
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 6:
		{
			Fillellipse(x+3,y+3,x+3,y+13,2,2047);//1
			Fillellipse(x+3,y+27,x+3,y+37,2,2047);//2
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 7:
		{
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 8:
		{
			Fillellipse(x+3,y+3,x+3,y+13,2,2047);//1
			Fillellipse(x+3,y+27,x+3,y+37,2,2047);//2
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
		case 9:
		{
			Fillellipse(x+3,y+3,x+3,y+13,2,2047);//1
			ever_Fillellipse(x+3,y+37,x+17,y+37,2,2047);//3
			Fillellipse(x+17,y+27,x+17,y+37,2,2047);//4
			ever_Fillellipse(x+3,y+20,x+17,y+20,2,2047);//5
			Fillellipse(x+17,y+3,x+17,y+13,2,2047);//6
			ever_Fillellipse(x+3,y+3,x+17,y+3,2,2047);//7
			break;
		}
	}
}