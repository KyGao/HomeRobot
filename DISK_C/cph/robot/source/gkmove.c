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
//	�����ܮ�
void remote_interface()
{
	iph_frame(36410);
	/**************
	���汳����
	**************
	FillCircle(ORIGINX+77,ORIGINY+124,60,32313);
	fill_bow_left_up(ORIGINX+250,ORIGINY+375,120,36410);
	fill_bow_left_down(ORIGINX+250,ORIGINY+375,120,36410);?
	
	
	/********
	�ײ�������
	********/

	bar_round_2(ORIGINX+3,ORIGINY+473,ORIGINX+252,ORIGINY+542,30,1,36410);	//138 198 210
	
	//��צͼ��
	FillCircle(ORIGINX+24, ORIGINY+503, 5, 65535);
	FillCircle(ORIGINX+37, ORIGINY+491, 5, 65535);
	FillCircle(ORIGINX+55, ORIGINY+491, 5, 65535);
	FillCircle(ORIGINX+69, ORIGINY+503, 5, 65535);
	bar_round_2(ORIGINX+31,ORIGINY+502,ORIGINX+64,ORIGINY+529,10,1,65535);
	//��ҳͼ�꣨˫Բ��
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	/*��������
	FillCircle(ORIGINX+178, ORIGINY+529, 4, 65535);
	FillCircle(ORIGINX+183, ORIGINY+514, 7, 65535);
	bar_round_2(ORIGINX+190,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	*/
	
	
	/************
	ң�ؽ���
	************/
	fdhz(ORIGINX+18,ORIGINY+58,2,2,"Զ",65535);
	fdhz(ORIGINX+48,ORIGINY+58,2,2,"��",65535);
	fdhz(ORIGINX+78,ORIGINY+58,2,2,"��",65535);
	fdhz(ORIGINX+108,ORIGINY+58,2,2,"��",65535);
		
	//������צ
	FillCircle(ORIGINX+24+83, ORIGINY+503-234, 5, 65535);
	FillCircle(ORIGINX+37+83, ORIGINY+491-234, 5, 65535);
	FillCircle(ORIGINX+55+83, ORIGINY+491-234, 5, 65535);
	FillCircle(ORIGINX+69+83, ORIGINY+503-234, 5, 65535);
	bar_round_2(ORIGINX+31+83,ORIGINY+502-234,ORIGINX+64+83,ORIGINY+529-234,10,1,65535);
	
	//����ٿ�
	bar(ORIGINX+91,ORIGINY+167,ORIGINX+161,ORIGINY+237,65535);	//��
	
	bar(ORIGINX+91,ORIGINY+309,ORIGINX+161,ORIGINY+379,65535);	//��
	
	bar(ORIGINX+20,ORIGINY+238,ORIGINX+90,ORIGINY+308,65535);	//��
	
	bar(ORIGINX+162,ORIGINY+238,ORIGINX+232,ORIGINY+308,65535);	//��
	
}

//����⺯��
int remote_click(int *mx,int *my,int button)
 {
	 /*********
	��ťλ�ñ�׼��
	�����п��ܵİ�ťλ�����괢���ڶ�ά������
	*********/
	int a[8][4];
	a[0][0] = 0;	//	a[0][]:������Ͻ��˳�����
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	
	a[1][0] = ORIGINX+100;		//	a[1][]:�����ҳ ������ҳ	
	a[1][1] = ORIGINX+155;
	a[1][2] = ORIGINY+485;
	a[1][3] = ORIGINY+535;
	
	a[2][0] = ORIGINX+175;		//	a[2][]:������� �����������	
	a[2][1]	= ORIGINX+225;
	a[2][2]	= ORIGINY+486;
	a[2][3] = ORIGINY+530;
	
	a[3][0] = ORIGINX+91;		//	a[3][]:������ϡ�����			
	a[3][1]	= ORIGINX+161;
	a[3][2]	= ORIGINY+167;
	a[3][3] = ORIGINY+237;
	
	a[4][0] = ORIGINX+91;		//	a[4][]:������¡�����					
	a[4][1]	= ORIGINX+161;
	a[4][2]	= ORIGINY+309;
	a[4][3] = ORIGINY+379;	
	
	a[5][0] = ORIGINX+20;		//	a[5][]:������󡿹���			
	a[5][1]	= ORIGINX+90;
	a[5][2]	= ORIGINY+238;
	a[5][3] = ORIGINY+308;
	
	a[6][0] = ORIGINX+162;		//	a[6][]:������ҡ�����				
	a[6][1]	= ORIGINX+232;
	a[6][2]	= ORIGINY+238;
	a[6][3] = ORIGINY+308;	

	a[7][0] = ORIGINX+91;		//	a[7][]:�������צ����ť���в���					
	a[7][1]	= ORIGINX+161;
	a[7][2]	= ORIGINY+238;
	a[7][3] = ORIGINY+308;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && button)	return 1;   //if(������˳�����)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && button)	return 2;   //if(�������ҳ ������ҳ)
	//else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && button)	return 3;   //if(��������� �����������)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && button)	return 4;   //if(��������ϡ�����)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && button)	return 5; 	//if(��������¡�����)
	else if (*mx >= a[5][0] && *mx <= a[5][1] && *my >= a[5][2] && *my <= a[5][3] && button)	return 6;   //if(��������󡿹���)
	else if (*mx >= a[6][0] && *mx <= a[6][1] && *my >= a[6][2] && *my <= a[6][3] && button)	return 7;   //if(��������ҡ�����)
	//else if (*mx >= a[7][0] && *mx <= a[7][1] && *my >= a[7][2] && *my <= a[7][3] && button)	return 8; 	//if(���������צ������)
	
    else return 0;
 }
 
int move_one_step(ROBOT_CASE *robot_position,int *x,int *y)
{
	int button = 0,judge;
	mousehide(*x,*y);
	remote_interface();
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		judge = remote_click(x,y,button);
		
		switch(judge)
		{
			case 1:
			{
				exit(0);
			}
			case 2:
			{
				mousehide(*x,*y);
				ph_main();
				reset_mouse(x,y);
				return -2;
			}
			case 4:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//����������ס��Ŷ��
				if(CheckMove((*robot_position).x+1,(*robot_position).y+0,(*robot_position).position)==1)	//�����߿�������
				{
					(*robot_position).direction = 3;	//3������
					move0(robot_position,x,y);		//��һ��
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"����ס��Ŷ",65535);
				}
				break;
			}
			case 5:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//����������ס��Ŷ��
				if(CheckMove((*robot_position).x+1,(*robot_position).y+2,(*robot_position).position) == 1)	//�����߿�������
				{
					(*robot_position).direction = 4;	//4������
					move0(robot_position,x,y);		//��һ��
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"����ס��Ŷ",65535);
				}
				break;
			}
			case 6:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//����������ס��Ŷ��
				if(CheckMove((*robot_position).x,(*robot_position).y+1,(*robot_position).position) == 1)	//�����߿�������
				{
					(*robot_position).direction = 2;	//2������
					move0(robot_position,x,y);		//��һ��
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"����ס��Ŷ",65535);
				}
				break;
			}
			case 7:
			{
				bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+120,SCREENCENTER_y-110,36410);	//����������ס��Ŷ��
				if(CheckMove((*robot_position).x+2,(*robot_position).y+1,(*robot_position).position) == 1)		//�����߿�������
				{
					(*robot_position).direction = 1;	//1������
					move0(robot_position,x,y);		//��һ��
				}
				else
				{
					fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"����ס��Ŷ",65535);
				}
				break;
			}

		}
	}
	
}
void tri(int x,int y,int di)
{
	switch(di)
	{
		case 1:
		{
			triangleleft(x,y,10,0);
			bar(x,y-5,x+5,y+5,0);
		}
		case 2:
		{
			triangleright(x,y,10,0);
			bar(x,y-5,x+5,y+5,0);
		}
		case 3:
		{
			triangle2(x,y,10,0);
			bar(x-5,y,x+5,y+20,0);
		}
		case 4:
		{
			triangledown(x,y,10,0);
			bar(x-5,y,x+5,y-20,0);
		}
	}
}