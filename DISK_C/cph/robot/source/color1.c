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
/****************************************************
颜色转换及渐变色相关函数
int transcolor(int r,int g,int b)
void linelevel_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
void linever_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
void circle_color(int x0,int y0,int r1,int g1,int b1,int r2,int g2,int b2,int r)
****************************************************/

/*将rgb颜色值转换为64k色*/
int transcolor(int r,int g,int b)
{
	int rgb;
	/*
	double r_mid,g_mid,b_mid;
	r_mid = (32*(double)(r)/255);
	g_mid = (64*(double)(g)/255);
	b_mid = (32*(double)(b)/255);
	rgb = ((int)(r_mid)<<11) || ((int)(g_mid)<<5) || ((int)(b_mid));
	
	*/
	/*0x117模式下，原图红绿蓝各8位分别近似为5位、6位、5位*/
			r >>= 3;
			g >>= 2;
			b >>= 3;
			rgb = ((((unsigned int)r) << 11)
			| (((unsigned int)g) << 5)
			| ((unsigned int)b));
			return rgb;
}

/*水平线性渐变*/
void linelevel_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
{
	float fbegin = 0.0,fend = 0.0,rstep = 0.0,gstep = 0.0,bstep = 0.0;
	int rRed,rGreen,rBlue,rgb;
	int x,y,wide=x2-x1;	
	for(x=x1;x<=x2;x++)
	{	
	    fbegin = (float)(r1);
	    fend = (float)(r2);
	    rstep = (fend-fbegin)/(wide);
        rRed = (int)(fbegin+rstep*x);
		
		//green
	    fbegin = (float)(g1);
	    fend = (float)(g2);
	    gstep = (fend-fbegin)/(wide);
		rGreen = (int)(fbegin+gstep*x);
		
		//blue
	    fbegin = (float)(b1);
	    fend = (float)(b2);
	    bstep = (fend-fbegin)/(wide);
		rBlue = (int)(fbegin+bstep*x);
		rgb = transcolor(rRed,rGreen,rBlue);
		for(y=y1;y<=y2;y++)
		{
			Putpixel64k(x,y,rgb);
		}
		
	}
}

/*竖直线性渐变*/
void linever_color(int x1,int y1,int x2,int y2,int r1,int g1,int b1,int r2,int g2,int b2)
{
	float fbegin = 0.0,fend = 0.0,rstep = 0.0,gstep = 0.0,bstep = 0.0;
	unsigned int rRed,rGreen,rBlue,rgb;
	int x,y,wide=y2-y1;	
	for(y=y1;y<y2;y++)
	{	
	    fbegin = (float)(r1);
	    fend = (float)(r2);
	    rstep = (fend-fbegin)/(wide);
        rRed = (int)(fbegin+rstep*y);
		
		//green
	    fbegin = (float)(g1);
	    fend = (float)(g2);
	    gstep = (fend-fbegin)/(wide);
		rGreen = (int)(fbegin+gstep*y);
		
		//blue
	    fbegin = (float)(b1);
	    fend = (float)(b2);
	    bstep = (fend-fbegin)/(wide);
		rBlue = (int)(fbegin+bstep*y);
		rgb = transcolor(rRed,rGreen,rBlue);
		for(x=x1;x<=x2;x++)
		{
			Putpixel64k(x,y,rgb);
		}
		
	}
}
/*轴向渐变*/
void circle_color(int x0,int y0,int r1,int g1,int b1,int r2,int g2,int b2,int r)
{
	int i;
	float fbegin = 0.0,fend = 0.0,rstep = 0.0,gstep = 0.0,bstep = 0.0;
	int rRed,rGreen,rBlue,rgb;	
	
		
	for(i=1;i<r;i++)
	{	
	    fbegin = (float)(r1);
	    fend = (float)(r2);
	    rstep = (fend-fbegin)/(r);
        rRed = (int)(fbegin+rstep*i);
		
		//green
	    fbegin = (float)(g1);
	    fend = (float)(g2);
	    gstep = (fend-fbegin)/(r);
		rGreen = (int)(fbegin+gstep*i);
		
		//blue
	    fbegin = (float)(b1);
	    fend = (float)(b2);
	    bstep = (fend-fbegin)/(r);
		rBlue = (int)(fbegin+bstep*i);
		rgb = transcolor(rRed,rGreen,rBlue);
		
		circle(x0,y0,i,rgb);
	}
}
