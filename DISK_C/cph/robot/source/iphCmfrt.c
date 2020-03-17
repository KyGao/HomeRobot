/******************�����嵥***************************
1.  void comfort_ui(char *air1, char *air2, char *air3, char *H, char *PM, int value, int window);
2.	int iphcmfrt_click(int *mx,int *my,int *button);
3.	int match( int PM2);
4.	void window_button_on(int *flag);
5.	void window_button_off(int *flag);
6.	void window_check(int *flag);
7.	void temperature_subtract(int order);
8.	void temperature_add(int order);
9.	void airconditioner_blink(int x, int y, ROBOT_CASE *robot_position);
10.	void random_show(int air1, int air2, int air3, int PM, int H);
11.	void comfort_control(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y);
*****************************************************/
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

/******************

	�ֻ�����
	
******************/
void comfort_ui(char *air1, char *air2, char *air3, char *H, char *PM, int value, int window)
{
	iph_frame(36410);

	/********
		���汳��
	********/
	FillCircle(ORIGINX+200,ORIGINY+157,40,36410);	//138 198 210
	fill_bow_right_up(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	fill_bow_right_down(ORIGINX+3,ORIGINY+305,120,32313);	//121 198 204
	
	
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
	//��������
	FillCircle(ORIGINX+178, ORIGINY+529, 4, 65535);
	FillCircle(ORIGINX+183, ORIGINY+514, 7, 65535);
	bar_round_2(ORIGINX+180,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	
	
	/****************
		������
	****************/
	//����
	bar(ORIGINX+4,ORIGINY+72,FINALX,ORIGINY+112,32313);		//121 198 204
	fdhz(ORIGINX+18,ORIGINY+77,2,2,"��",65535);
	fdhz(ORIGINX+48,ORIGINY+77,2,2,"��",65535);
	//�յ������ԣ�
	bar(ORIGINX+4,ORIGINY+113,FINALX,ORIGINY+153,36410);		//138 198 210
	fdhz(ORIGINX+18,ORIGINY+118,2,2,"��",65535);
	fdhz(ORIGINX+48,ORIGINY+118,2,2,"��",65535);
	fdhz(ORIGINX+78,ORIGINY+118,2,2,"��",65535);
	fdhz(ORIGINX+108,ORIGINY+118,2,2,"��",65535);
	//�յ������ԣ�
	bar(ORIGINX+4,ORIGINY+154,FINALX,ORIGINY+194,32313);		//138 198 210
	fdhz(ORIGINX+18,ORIGINY+159,2,2,"��",65535);
	fdhz(ORIGINX+48,ORIGINY+159,2,2,"��",65535);
	fdhz(ORIGINX+78,ORIGINY+159,2,2,"��",65535);
	fdhz(ORIGINX+108,ORIGINY+159,2,2,"��",65535);
	//�յ���������
	bar(ORIGINX+4,ORIGINY+195,FINALX,ORIGINY+235,36410);		//138 198 210
	fdhz(ORIGINX+18,ORIGINY+200,2,2,"��",65535);
	fdhz(ORIGINX+48,ORIGINY+200,2,2,"��",65535);
	fdhz(ORIGINX+78,ORIGINY+200,2,2,"��",65535);
	fdhz(ORIGINX+108,ORIGINY+200,2,2,"��",65535);
		
	/****************
		���ư�ť
	****************/
	//����72����112
	if(window == 1)
	{
		bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313);
		bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,18221);
		FillCircle(ORIGINX+244-13, ORIGINY+81+11, 13, 65535);
	}
	else if(window == 0)
	{
		bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313); 
		bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,52825);
		FillCircle(ORIGINX+198+13, ORIGINY+81+11, 12, 65535);
	}
	//����113����153
	bar_round_2(ORIGINX+198,ORIGINY+122,ORIGINX+244,ORIGINY+144,11,1,65535);
	bar(ORIGINX+198+11,ORIGINY+122,ORIGINX+198+13,ORIGINY+144,36410);
	bar(ORIGINX+244-13,ORIGINY+122,ORIGINX+244-11,ORIGINY+144,36410);
	outtextxy(ORIGINX+198+10,ORIGINY+125,air1,1,1,8,0);
	bar(ORIGINX+198+2,ORIGINY+133,ORIGINX+198+9,ORIGINY+134,36410);//����
	bar(ORIGINX+244-2,ORIGINY+133,ORIGINX+244-9,ORIGINY+134,36410);//�Ӻ�
	bar(ORIGINX+244-5,ORIGINY+133-3,ORIGINX+244-6,ORIGINY+134+3,36410);//�Ӻ�
	//����154����194
	bar_round_2(ORIGINX+198,ORIGINY+163,ORIGINX+244,ORIGINY+185,11,1,65535);
	bar(ORIGINX+198+11,ORIGINY+163,ORIGINX+198+13,ORIGINY+185,36410);
	bar(ORIGINX+244-13,ORIGINY+163,ORIGINX+244-11,ORIGINY+185,36410);
	outtextxy(ORIGINX+198+10,ORIGINY+166,air2,1,1,8,0);
	bar(ORIGINX+198+2,ORIGINY+174,ORIGINX+198+9,ORIGINY+175,36410);//����
	bar(ORIGINX+244-2,ORIGINY+174,ORIGINX+244-9,ORIGINY+175,36410);//�Ӻ�
	bar(ORIGINX+244-5,ORIGINY+174-3,ORIGINX+244-6,ORIGINY+175+3,36410);//�Ӻ�
	//����195����235
	bar_round_2(ORIGINX+198,ORIGINY+204,ORIGINX+244,ORIGINY+226,11,1,65535);
	bar(ORIGINX+198+11,ORIGINY+204,ORIGINX+198+13,ORIGINY+226,36410);
	bar(ORIGINX+244-13,ORIGINY+204,ORIGINX+244-11,ORIGINY+226,36410);
	outtextxy(ORIGINX+198+10,ORIGINY+207,air3,1,1,8,0);
	bar(ORIGINX+198+2,ORIGINY+215,ORIGINX+198+9,ORIGINY+216,36410);//����
	bar(ORIGINX+244-2,ORIGINY+215,ORIGINX+244-9,ORIGINY+216,36410);//�Ӻ�
	bar(ORIGINX+244-5,ORIGINY+215-3,ORIGINX+244-6,ORIGINY+216+3,36410);//�Ӻ� 
	
	/****************
		״̬��
	****************/
	//���
	bar(ORIGINX+43,ORIGINY-30+275,ORIGINX+47,ORIGINY-30+490,65535);
	bar(ORIGINX+43,ORIGINY-30+273,ORIGINX+216,ORIGINY-30+277,65535);
	bar(ORIGINX+212,ORIGINY-30+275,ORIGINX+216,ORIGINY-30+490,65535);
	bar(ORIGINX+43,ORIGINY-30+490,ORIGINX+216,ORIGINY-30+494,65535);
	//�ڿ�
	bar(ORIGINX+47,ORIGINY-30+277,ORIGINX+212,ORIGINY-30+314,65535);
	bar(ORIGINX+47,ORIGINY-30+314,ORIGINX+212,ORIGINY-30+318,65535);
	bar(ORIGINX+47,ORIGINY-30+345,ORIGINX+212,ORIGINY-30+347,65535);
	bar(ORIGINX+47,ORIGINY-30+374,ORIGINX+212,ORIGINY-30+376,65535);
	bar(ORIGINX+47,ORIGINY-30+403,ORIGINX+212,ORIGINY-30+405,65535);
	bar(ORIGINX+47,ORIGINY-30+432,ORIGINX+212,ORIGINY-30+434,65535);
	bar(ORIGINX+47,ORIGINY-30+461,ORIGINX+212,ORIGINY-30+463,65535);
	//����
	fdhz(ORIGINX+70,ORIGINY-30+280,2,2,"״",28153);
	fdhz(ORIGINX+110,ORIGINY-30+280,2,2,"̬",28153);
	fdhz(ORIGINX+150,ORIGINY-30+280,2,2,"��",28153);
	
	fdhz(ORIGINX+50,ORIGINY-30+322,1,1,"��",65535);
	fdhz(ORIGINX+70,ORIGINY-30+322,1,1,"��",65535);
	fdhz(ORIGINX+90,ORIGINY-30+322,1,1,"��",65535);
	fdhz(ORIGINX+110,ORIGINY-30+322,1,1,"��",65535);
	
	fdhz(ORIGINX+50,ORIGINY-30+351,1,1,"��",65535);
	fdhz(ORIGINX+70,ORIGINY-30+351,1,1,"��",65535);
	fdhz(ORIGINX+90,ORIGINY-30+351,1,1,"��",65535);
	fdhz(ORIGINX+110,ORIGINY-30+351,1,1,"��",65535);
	
	fdhz(ORIGINX+50,ORIGINY-30+380,1,1,"��",65535);
	fdhz(ORIGINX+70,ORIGINY-30+380,1,1,"��",65535);
	fdhz(ORIGINX+90,ORIGINY-30+380,1,1,"��",65535);
	fdhz(ORIGINX+110,ORIGINY-30+380,1,1,"��",65535);
	
	fdhz(ORIGINX+50,ORIGINY-30+409,1,1,"ʪ",65535);
	fdhz(ORIGINX+70,ORIGINY-30+409,1,1,"��",65535);
	
	outtextxy(ORIGINX+40,ORIGINY-30+438,"PM2.5",1,1,12,65535);

	fdhz(ORIGINX+50,ORIGINY-30+467,1,1,"��",65535);	
	fdhz(ORIGINX+70,ORIGINY-30+467,1,1,"��",65535);
	fdhz(ORIGINX+90,ORIGINY-30+467,1,1,"��",65535);
	fdhz(ORIGINX+110,ORIGINY-30+467,1,1,"��",65535);
	
	/****************
		״̬��ʾ��
	****************/
	outtextxy(ORIGINX+180,ORIGINY-30+322,air1,1,1,12,65535);
	outtextxy(ORIGINX+180,ORIGINY-30+351,air2,1,1,12,65535);
	outtextxy(ORIGINX+180,ORIGINY-30+380,air3,1,1,12,65535);
	outtextxy(ORIGINX+180,ORIGINY-30+409,H,1,1,12,65535);
	outtextxy(ORIGINX+168,ORIGINY-30+438,PM,1,1,12,65535);
	if(value == 1){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  ��",65535);
	}
	else if(value == 2){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  ��",65535);
	}
	else if(value == 3){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"�����Ⱦ",65535);
	}
	else if(value == 4){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"�ж���Ⱦ",65535);
	}
	else if(value == 5){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"�ض���Ⱦ",65535);
	}
	else if(value == 6){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"������Ⱦ",65535);
	}
	
}

/******************

	�����λ�ü�� 
	
******************/
int iphcmfrt_click(int *mx,int *my,int *button)
 {
	 /*********
	��ťλ�ñ�׼��
	�����п��ܵİ�ťλ�����괢���ڶ�ά������
	*********/
	int a[9][4];
	a[0][0] = 0;	//	a[0][]:������Ͻ��˳�����
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	
	a[1][0] = ORIGINX+198;		//	a[1][]:����������ذ�ť 	�ٴ�����ť�仯�ڻ������ƶ���ʪ����Ӧ��PM2.5��Ӧ	
	a[1][1] = ORIGINX+244;
	a[1][2] = ORIGINY+81;
	a[1][3] = ORIGINY+103;
	
	a[2][0] = ORIGINX+198;		//	a[2][]:������Կյ���-��	�ٰ�ť���ֱ仯��״̬����ֵ��Ӧ�ܿյ��������̢�PM2.5������Ӧ 	
	a[2][1]	= ORIGINX+198+11;
	a[2][2]	= ORIGINY+122;
	a[2][3] = ORIGINY+144;
	
	a[3][0] = ORIGINX+244-11;		//	a[3][]:������Կյ���+��	
	a[3][1]	= ORIGINX+244;
	a[3][2]	= ORIGINY+122;
	a[3][3] = ORIGINY+144;
	
	a[4][0] = ORIGINX+198;		//	a[4][]:������Կյ���-��			
	a[4][1]	= ORIGINX+198+11;
	a[4][2]	= ORIGINY+163;
	a[4][3] = ORIGINY+185;	
	
	a[5][0] = ORIGINX+244-11;		//	a[5][]:������Կյ���+��	
	a[5][1]	= ORIGINX+244;
	a[5][2]	= ORIGINY+163;
	a[5][3] = ORIGINY+185;
	
	a[6][0] = ORIGINX+198;		//	a[6][]:��������յ���-��				
	a[6][1]	= ORIGINX+198+11;
	a[6][2]	= ORIGINY+204;
	a[6][3] = ORIGINY+226;	

	a[7][0] = ORIGINX+244-11;		//	a[7][]:��������յ���+��				
	a[7][1]	= ORIGINX+244;
	a[7][2]	= ORIGINY+204;
	a[7][3] = ORIGINY+226;

	a[8][0] = ORIGINX+100;		//	a[7][]:�������ҳ���ص���ҳ				
	a[8][1]	= ORIGINX+155;
	a[8][2]	= ORIGINY+485;
	a[8][3] = ORIGINY+535;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && *button)	return 1;   //if(������˳�����)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && *button)	return 2;   //if(�������������)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && *button)	return 3;   //if(��������Կյ���-��)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && *button)	return 4;   //if(��������Կյ���+��)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && *button)	return 5; 	//if(��������Կյ���-��)
	else if (*mx >= a[5][0] && *mx <= a[5][1] && *my >= a[5][2] && *my <= a[5][3] && *button)	return 6;   //if(��������Կյ���+��)
	else if (*mx >= a[6][0] && *mx <= a[6][1] && *my >= a[6][2] && *my <= a[6][3] && *button)	return 7;   //if(����������յ���-��)
	else if (*mx >= a[7][0] && *mx <= a[7][1] && *my >= a[7][2] && *my <= a[7][3] && *button)	return 8; 	//if(����������յ���+��)
	else if (*mx >= a[8][0] && *mx <= a[8][1] && *my >= a[8][2] && *my <= a[8][3] && *button)	return 9; 	//if(���������ҳ��)
	else return 0;
 }

/******************

	��PM2.5��ֵ�����������ƥ��

******************/
int match( int PM2)
 {
	if(PM2 <50){
		return 1;
	}
	else if(PM2 >=50  && PM2 <100){
		return 2;
	}
	else if(PM2 >=100 && PM2 <150){
		return 3;
	}
	else if(PM2 >=150 && PM2 <200){
		return 4;
	}
	else if(PM2 >=200 && PM2 <300){
		return 5;
	}
	else if(PM2 >=300){
		return 6;
	}
 }

/******************

	���������͹رյİ�ť״̬ 
	
******************/ 
void window_button_on(int *flag)
 {
	bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313);
	bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,18221);
	FillCircle(ORIGINX+244-13, ORIGINY+81+11, 13, 65535);
	*flag = 1;	//��Ǵ����ǿ���״̬
 }
 
/******************

	���������͹رյİ�ť״̬ 
	
******************/ 
void window_button_off(int *flag)
 {
	bar(ORIGINX+196,ORIGINY+79,ORIGINX+246,ORIGINY+105,32313); 
	bar_round_2(ORIGINX+198,ORIGINY+81,ORIGINX+244,ORIGINY+103,11,1,52825);
	FillCircle(ORIGINX+198+13, ORIGINY+81+11, 12, 65535);
	*flag = 0;	//��Ǵ����ǹر�״̬
 }
 
 /******************

	�����������ֻ��������Ӧ 
	
******************/
 void window_check(int *flag)
 {
 	if(*flag)
	{//����	����Ҫ�ر�
		window_button_off(flag);
		
		ChangeHouse(1,0);
		ChangeHouse(5,-100);			//	�ش��ή��PM2.5
		ChangeHouse(7,-20);			//	�ش��ή��ʪ��
	}
	else
	{//���� ����Ҫ����
		window_button_on(flag);
	
		ChangeHouse(1,1);
		ChangeHouse(5,100);			//	����������PM2.5
		ChangeHouse(7,20);			//	����������ʪ��
	}
 }

 /******************

	���Ϳյ��¶Ȥΰ�ť�仯 
	
******************/
void temperature_subtract(int order)
{
	int delta_y = 41;	//ƫ����
	int delta_num = order-1;	//��Ϊƫ�ƵĲο�����
	int func_num = order+1;		//��Ϊchangehouse������ֵ
	char set_temperature[3] ;		//��ʾ�¶�ʱ��
	
	ChangeHouse(func_num,-1);	//�ļ��޸�
	//��ͼ��ʾ
	bar(ORIGINX+198+13,ORIGINY+122+delta_y*delta_num,ORIGINX+244-13,ORIGINY+144+delta_y*delta_num,65535);
	itoa(CheckHouse(func_num),set_temperature,10);
	set_temperature[2] = '\0';
	outtextxy(ORIGINX+198+10,ORIGINY+125+delta_y*delta_num,set_temperature,1,1,8,0);
}

/******************

	���߿յ��¶Ȥΰ�ť�仯 
	
******************/
void temperature_add(int order)
{
	int delta_y = 41;	//ƫ����
	int delta_num = order-1;	//��Ϊƫ�ƵĲο�����
	int func_num = order+1;		//��Ϊchangehouse������ֵ
	char set_temperature[3] ;		//��ʾ�¶�ʱ��
	
	ChangeHouse(func_num,1);	//�ļ��޸�
	//��ͼ��ʾ
	bar(ORIGINX+198+13,ORIGINY+122+delta_y*delta_num,ORIGINX+244-13,ORIGINY+144+delta_y*delta_num,65535);
	itoa(CheckHouse(func_num),set_temperature,10);
	set_temperature[2] = '\0';
	outtextxy(ORIGINX+198+10,ORIGINY+125+delta_y*delta_num,set_temperature,1,1,8,0);
}
 
/******************

	�յ���������˸һ�� 
	
******************/
void airconditioner_blink(int x, int y, ROBOT_CASE *robot_position)
{
	if((*robot_position).position == 1)
	{
		aircon(x,y,0);
		delay(50);
		aircon(x,y,1);
	}
}	

/******************

	״̬����Ϣ�����ʾ 
	
******************/
void random_show(int air1, int air2, int air3, int PM, int H)
{
	int  interval;		//��������
	char aircon1[3],aircon2[3],aircon3[3];
	char PM_show[4],H_show[3];
	
	srand((unsigned)(time(NULL)));
	
	//�����¶�״̬��ʾ
	interval = -1+rand()%3;	//���ɲ�������
	air1 += interval;	//������ֵ
	itoa(air1, aircon1, 10);	//����ֵת��Ϊ�ַ���
	aircon1[2] = '\0';	//���α���
	bar(ORIGINX+180,ORIGINY-30+322,ORIGINX+210,ORIGINY-30+342,36410);	//���֮ǰ��ʾ
	outtextxy(ORIGINX+180,ORIGINY-30+322,aircon1,1,1,12,65535);	//print
	//�����¶�״̬��ʾ
	interval = -1+rand()%3;	//���ɲ�������
	air2 += interval;	//������ֵ
	itoa(air2, aircon2, 10);	//����ֵת��Ϊ�ַ���
	aircon2[2] = '\0';	//���α���
	bar(ORIGINX+180,ORIGINY-30+351,ORIGINX+210,ORIGINY-30+371,36410);	//���֮ǰ��ʾ
	outtextxy(ORIGINX+180,ORIGINY-30+351,aircon2,1,1,12,65535);	//print
	//�����¶�״̬��ʾ
	interval = -1+rand()%3;	//���ɲ�������
	air3 += interval;	//������ֵ
	itoa(air3, aircon3, 10);	//����ֵת��Ϊ�ַ���
	aircon3[2] = '\0';	//���α���
	bar(ORIGINX+180,ORIGINY-30+380,ORIGINX+210,ORIGINY-30+400,36410);	//���֮ǰ��ʾ
	outtextxy(ORIGINX+180,ORIGINY-30+380,aircon3,1,1,12,65535);	//print
	//ʪ��״̬��ʾ
	interval = -1+rand()%9;	//���ɲ�������
	H += interval;	//������ֵ
	itoa(H, H_show, 10);	//����ֵת��Ϊ�ַ���
	H_show[2] = '\0';	//���α���
	bar(ORIGINX+180,ORIGINY-30+409,ORIGINX+210,ORIGINY-30+429,36410);	//���֮ǰ��ʾ	
	outtextxy(ORIGINX+180,ORIGINY-30+409,H_show,1,1,12,65535);	//print
	//PM2.5״̬��ʾ
	interval = -1+rand()%199;	//���ɲ�������
	PM += interval;	//������ֵ
	itoa(PM, PM_show, 10);	//����ֵת��Ϊ�ַ���
	PM_show[3] = '\0';	//���α���
	bar(ORIGINX+168,ORIGINY-30+438,ORIGINX+210,ORIGINY-30+458,36410);	//���֮ǰ��ʾ
	outtextxy(ORIGINX+168,ORIGINY-30+438,PM_show,1,1,12,65535);	//print
	//����������ʾ
	//match(str,PM);	//����PM2.5��ֵ�жϿ�������
	bar(ORIGINX+140,ORIGINY-30+467,ORIGINX+210,ORIGINY-30+487,36410);	//���֮ǰ��ʾ
	if(match(PM) == 1){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  ��",65535);
	}
	else if(match(PM) == 2){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"  ��",65535);
	}
	else if(match(PM) == 3){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"�����Ⱦ",65535);
	}
	else if(match(PM) == 4){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"�ж���Ⱦ",65535);
	}
	else if(match(PM) == 5){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"�ض���Ⱦ",65535);
	}
	else if(match(PM) == 6){
		fdhz(ORIGINX+140,ORIGINY-30+467,1,1,"������Ⱦ",65535);
	}

}

/******************

	�������ʹ��ܵ����߼� 
	
******************/
void comfort_control(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y)
{
	int buttons;
	int state = 1;//��������ҳ֮��state��Ϊ0���˳�ѭ��
	int click;	//��¼���״̬flag
	int window = CheckHouse(1);	//��¼��������״̬
	int PM2 = CheckHouse(5);	//��ʼ��PM2.5��ֵ
	char main_room_temperature[3],guest_room_temperature[3],living_room_temperature[3],H[3],PM[4];
	int ranran;
	
	//ת���ɿ���������ַ���
	itoa(CheckHouse(2),main_room_temperature,10);
	itoa(CheckHouse(3),guest_room_temperature,10);
	itoa(CheckHouse(4),living_room_temperature,10);
	itoa(CheckHouse(7),H,10);
	itoa(PM2,PM,10);

	
	//���α���
	main_room_temperature[2] = '\0';
	guest_room_temperature[2] = '\0';
	living_room_temperature[2] = '\0';
	H[2] = '\0';
	PM[3] = '\0';
	
	ranran = match(PM2);
	mousehide(*x,*y);
	comfort_ui(main_room_temperature,guest_room_temperature,living_room_temperature,H,PM,ranran,window);
	
	
	
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&buttons);
		
		//״̬��ʾ��
		random_show(CheckHouse(2),CheckHouse(3),CheckHouse(4),CheckHouse(5),CheckHouse(7));
		
		click = iphcmfrt_click(x,y,&buttons);
		switch(click)
		{
			case 0:	
					break;
			case 1:
					exit(1);
					break;
			case 2:
					if(window == 1){
						ranran = 0;
					}
					else{
						ranran = 1;
					}
					mousehide(*x,*y);
					window_check(&window);		//������ť�仯
					reset_mouse(x,y);
					open_window(robot_position,save,ranran,x,y);
					break;
			case 3:		//����
					temperature_subtract(1);//�ֻ�����
					airconditioner_blink(4,2,robot_position);		//�յ�����
					break;
			case 4:		//����
					temperature_add(1);			//�ֻ�����
					airconditioner_blink(4,2,robot_position);		//�յ�����
					break;
			case 5:		//����
					temperature_subtract(2);	//�ֻ�����
					airconditioner_blink(18,1,robot_position);		//�յ�����
					break;
			case 6:		//����
					temperature_add(2);		//�ֻ�����
					airconditioner_blink(18,1,robot_position);		//�յ�����
					break;
			case 7:		//����
					temperature_subtract(3);	//�ֻ�����
					airconditioner_blink(12,14,robot_position);		//�յ�����
					break;
			case 8:		//����
					temperature_add(3);		//�ֻ�����
					airconditioner_blink(12,14,robot_position);		//�յ�����
					break;
			case 9:		//��ҳ
					ph_main();	//��ȥ
					state = 0;	//���˳��������ѭ��
					break;
		}
		
		
		//�ж��Ƿ�����˳�ѭ��
		if(state == 0){
			break;
		}
	}
		//��ȥ
}

