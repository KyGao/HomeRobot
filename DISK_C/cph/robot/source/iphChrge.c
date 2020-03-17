/******************�����嵥***************************
1.  void charge_ui();
2.	void  charging(int battery);
3.	void charge_move_forward(ROBOT_CASE *robot_position, int *x, int *y);
4.	void charge_move_back(ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y);
5.	void charge_main(ROBOT_CASE *robot_position,int *x,int *y);
6.	int iphcharge_click(int *mx,int *my,int *button);
7.	void battery_show(ROBOT_CASE *robot_position, int battery, int *x, int *y);
*****************************************************/
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
#include"main.h"

#define SCREENCENTER_x 894 
#define SCREENCENTER_y 493
#define SCREENLENGTH 250 
#define SCREENHEIGHT 541
#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764

/**************

	������

**************/
void charge_ui(void)
{
	iph_frame(36410);
	bar(SCREENCENTER_x-30, SCREENCENTER_y-100,SCREENCENTER_x+30,SCREENCENTER_y+100,0);
	bar(SCREENCENTER_x-28, SCREENCENTER_y-90,SCREENCENTER_x+28,SCREENCENTER_y+90,65535);
	bar(SCREENCENTER_x-10, SCREENCENTER_y-105,SCREENCENTER_x+10,SCREENCENTER_y-100,0);
	//��ҳͼ�꣨˫Բ��
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	
	
}

/**************

	��綯��

**************/
void  charging(int battery)
{
	int i;	//counting
	int delta_battery = 180-battery;	//�����޸�house״̬
	
	fdhz(SCREENCENTER_x-50,SCREENCENTER_y-150,2,2,"�����",65535);
	//��綯��
	for(i=battery;i<180;i++)
	{
		if(i<100){
			bar(SCREENCENTER_x-28, SCREENCENTER_y+90-i,SCREENCENTER_x+28,SCREENCENTER_y+90,63488);
		}
		else{
			bar(SCREENCENTER_x-28, SCREENCENTER_y+90-i,SCREENCENTER_x+28,SCREENCENTER_y+90,2016);
		}
		
		delay0(50);
	}
	//����
	bar(SCREENCENTER_x-50,SCREENCENTER_y-170,SCREENCENTER_x+80,SCREENCENTER_y-120,36410);
	fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"������",65535);
	
	ChangeHouse(25,delta_battery);	//��֪�ṹ��������
}

/**************

	�ߵ����ߵĵط�

**************/
void charge_move_forward(ROBOT_CASE *robot_position, int *x, int *y)
{
	switch((*robot_position).position)	//�ж��ڼ�¥
	{
		case 0:	//�ڻ�԰
		{
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,9,8,x,y);
			break;
		}
		case 1:	//��һ¥
		{
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,9,8,x,y);
			break;
		}
		case 2:	//�ڶ�¥
		{
			
			break;
		}
		
	}
	aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,9,9,x,y);
}

/**************

	�ص��ûصĵط�

**************/
void charge_move_back(ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y)
{
	switch(rec_floor)
	{
		case 0:	//��Ҫȥ��԰������һ¥�ٳ���԰
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,1,10,x,y);
			break;
		}
		case 1:	//��һ¥
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);	
			break;
		}
		case 2:	//����
		{
			break;
		}
		
	}
	aimmove(robot_position,rec_floor,(*robot_position).x,(*robot_position).y,rec_x,rec_y,x,y);
}

/**************

	������߼�

**************/
void charge_main(ROBOT_CASE *robot_position,int *x,int *y)
{
	int rec_x = (*robot_position).x;	//��¼�����˳��ǰ�ĳ�ʼλ��
	int rec_y = (*robot_position).y;	//����֮��ص��õ��������
	int rec_floor = (*robot_position).position;
	int battery = CheckHouse(25);	//���ǰ����
	
	mousehide(*x,*y);
	
	save_image(ORIGINX, ORIGINY, FINALX, FINALY);	//�������ڽ��е��������
	charge_ui();	//��ؽ���
	reset_mouse(x,y);
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y-70,2,2,"��",25388);	//����
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y-30,2,2,"��",25388);
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y+10,2,2,"��",25388);
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y+50,2,2,"��",25388);
	
	ChangeHouse(26,1);	//��֪����ǰ������·�ϣ��ɲ��ü��
	charge_move_forward(robot_position, x, y);	//ǰ�����׮
	charging(battery);	//��綯��
	delay(1000);		//��Ļ��ס
	mousehide(*x,*y);
	printf_image(ORIGINX, ORIGINY, FINALX, FINALY);		//����֮ǰ���������
	charge_move_back(robot_position, rec_x, rec_y, rec_floor, x, y);	//�ص�ԭ��������ĵص�
	ChangeHouse(26,0);	//�ָ�δ���״̬
	
	reset_mouse(x,y);
}

/**************

	�����λ�ü�� 

**************/
int iphcharge_click(int *mx,int *my,int *button)
 {
	 /*********
	��ťλ�ñ�׼��
	�����п��ܵİ�ťλ�����괢���ڶ�ά������
	*********/
	int a[3][4];
	a[0][0] = 0;	//	a[0][]:������Ͻ��˳�����
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	
	a[1][0] = SCREENCENTER_x-20;		//	a[1][]:�����簴ť 
	a[1][1] = SCREENCENTER_x+20;
	a[1][2] = ORIGINY+400;
	a[1][3] = ORIGINY+420;

	a[2][0] = ORIGINX+100;		//	a[2][]:�������ҳ���ص���ҳ				
	a[2][1]	= ORIGINX+155;
	a[2][2]	= ORIGINY+485;
	a[2][3] = ORIGINY+535;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && *button)	return 1;   //if(������˳�����)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && *button)	return 2;   //if(�������������)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && *button)	return 3; 	//if(���������ҳ��)
	else return 0;
 }
 
/**************

	������ʾҳ��

**************/
void battery_show(ROBOT_CASE *robot_position, int battery, int *x, int *y)
{
	int buttons;
	int click;
	int state = 1;//��������ҳ֮��state��Ϊ0���˳�ѭ��

	charge_ui();
	//��ʾ��ǰ����
	if(battery<100){
		bar(SCREENCENTER_x-28, SCREENCENTER_y+90-battery,SCREENCENTER_x+28,SCREENCENTER_y+90,63488);
	}
	else{
		bar(SCREENCENTER_x-28, SCREENCENTER_y+90-battery,SCREENCENTER_x+28,SCREENCENTER_y+90,2016);
	}
	
	mousehide(*x,*y);
	//��簴ťui
	bar_round_2(SCREENCENTER_x-20,ORIGINY+400,SCREENCENTER_x+20,ORIGINY+420,10,1,65535);
	fdhz(SCREENCENTER_x-18,ORIGINY+402,1,1,"��",36410);
	fdhz(SCREENCENTER_x+2,ORIGINY+402,1,1,"��",36410);
	
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&buttons);
		
		click = iphcharge_click(x,y,&buttons);
		switch(click)
		{
			case 0:	
					break;
			case 1:
					exit(0);
					break;
			case 2:
					ChangeHouse(26,1);
					mousehide(*x,*y);
					charge_move_forward(robot_position, x, y);
					charging(battery);
					reset_mouse(x,y);
					ChangeHouse(26,0);
					break;
			case 3:		//��ҳ
					ph_main();	//��ȥ
					state = 0;	//���˳��������ѭ��
					break;
		}
		
		
		//�ж��Ƿ�����˳�ѭ��
		if(state == 0){
			break;
		}
	}
	
}