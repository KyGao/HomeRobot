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
#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764


//	�����ܮ�
void main_interface(void)
{
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
	bar_round_2(ORIGINX+190,ORIGINY+486,ORIGINX+238,ORIGINY+516,10,1,65535);
	bar(ORIGINX+195,ORIGINY+496,ORIGINX+225,ORIGINY+497,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+502,ORIGINX+225,ORIGINY+503,36410);	//138 198 210
	bar(ORIGINX+195,ORIGINY+508,ORIGINX+225,ORIGINY+509,36410);	//138 198 210
	
	/********
	���ܰ�ť
	********/
	//����
	bar_round_2(ORIGINX+15,ORIGINY+300,ORIGINX+126,ORIGINY+372,10,1,65535);
	fdhz(ORIGINX+25,ORIGINY+315,3,3,"��",28153);	//107 190 202
	fdhz(ORIGINX+74,ORIGINY+315,3,3,"��",28153);	//107 190 202
	//����
	bar_round_2(ORIGINX+130,ORIGINY+300,ORIGINX+242,ORIGINY+372,10,1,65535);
	fdhz(ORIGINX+140,ORIGINY+315,3,3,"��",28153);	//107 190 202
	fdhz(ORIGINX+189,ORIGINY+315,3,3,"��",28153);	//107 190 202
	//��ȫ(Ӧ��Ϊ���)
	bar_round_2(ORIGINX+15,ORIGINY+377,ORIGINX+126,ORIGINY+449,10,1,65535);
	fdhz(ORIGINX+25,ORIGINY+389,3,3,"��",28153);	//107 190 202
	fdhz(ORIGINX+74,ORIGINY+389,3,3,"��",28153);	//107 190 202
	//���
	bar_round_2(ORIGINX+130,ORIGINY+377,ORIGINX+242,ORIGINY+449,10,1,65535);
	fdhz(ORIGINX+140,ORIGINY+389,3,3,"��",28153);	//107 190 202
	fdhz(ORIGINX+189,ORIGINY+389,3,3,"ȫ",28153);	//107 190 202
	//״̬
	bar_round_2(ORIGINX+188,ORIGINY+52,ORIGINX+242,ORIGINY+72,10,1,65535);
	fdhz(ORIGINX+195,ORIGINY+52,1,1,"��",28153);	//107 190 202
	fdhz(ORIGINX+215,ORIGINY+52,1,1,"��",28153);	//107 190 202
	
	/*************
	����״̬
	*************/
	fdhz(ORIGINX+12,ORIGINY+108,3,3,"��",65535);
	fdhz(ORIGINX+62,ORIGINY+108,3,3,"��",65535);
	fdhz(ORIGINX+112,ORIGINY+108,3,3,"��",65535);
	
}

int iphmain_click(int *mx,int *my,int *button)
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
	
	a[1][0] = ORIGINX+20;		//	a[1][]:�����צ ����ң��״̬	
	a[1][1] = ORIGINX+73;
	a[1][2] = ORIGINY+486;
	a[1][3] = ORIGINY+530;
	
	a[2][0] = ORIGINX+175;		//	a[2][]:������� �����������	
	a[2][1]	= ORIGINX+225;
	a[2][2]	= ORIGINY+486;
	a[2][3] = ORIGINY+530;
	
	a[3][0] = ORIGINX+15;		//	a[3][]:���������������		����,����	
	a[3][1]	= ORIGINX+126;
	a[3][2]	= ORIGINY+300;
	a[3][3] = ORIGINY+372;
	
	a[4][0] = ORIGINX+130;		//	a[4][]:��������ʡ�����		�յ�����			
	a[4][1]	= ORIGINX+242;
	a[4][2]	= ORIGINY+300;
	a[4][3] = ORIGINY+372;	
	
	a[5][0] = ORIGINX+15;		//	a[5][]:�������ȫ/��ݡ�����		�����ӣ�����	
	a[5][1]	= ORIGINX+126;
	a[5][2]	= ORIGINY+377;
	a[5][3] = ORIGINY+449;
	
	a[6][0] = ORIGINX+130;		//	a[6][]:�������硿����					
	a[6][1]	= ORIGINX+242;
	a[6][2]	= ORIGINY+377;
	a[6][3] = ORIGINY+449;	

	a[7][0] = ORIGINX+188;		//	a[7][]:�����״̬����ѯ					
	a[7][1]	= ORIGINX+242;
	a[7][2]	= ORIGINY+52;
	a[7][3] = ORIGINY+72;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && *button)	return 1;   //if(������˳�����)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && *button)	return 2;   //if(�������צ ����ң��״̬)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && *button)	return 3;   //if(��������� �����������)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && *button)	return 4;   //if(�����������������)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && *button)	return 5; 	//if(����������ʡ�����)
	else if (*mx >= a[5][0] && *mx <= a[5][1] && *my >= a[5][2] && *my <= a[5][3] && *button)	return 6;   //if(���������ݡ�����)
	else if (*mx >= a[6][0] && *mx <= a[6][1] && *my >= a[6][2] && *my <= a[6][3] && *button)	return 7;   //if(���������硿����)
	else if (*mx >= a[7][0] && *mx <= a[7][1] && *my >= a[7][2] && *my <= a[7][3] && *button)	return 8; 	//if(�������״̬����ѯ)
	//else if (*button)																			return 9;	//if(�������������)
    else return 0;
 }
 
 void ph_main(void)
 {
	iph_frame(28153);
	main_interface();
 }