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

#define ROBOTx 894
#define ROBOTy 404


//	�����ܮ�
void checkin_interface(unsigned int *text1save,unsigned int *text2save)
{
	
	/**************
	���汳����
	**************/
	FillCircle(ORIGINX+77,ORIGINY+124,60,32313);
	fill_bow_left_up(ORIGINX+250,ORIGINY+375,120,36410);
	fill_bow_left_down(ORIGINX+250,ORIGINY+375,120,36410);
		//	�ȱ������ֱ����ͼ���Ա�֮�������ʱ�ܹ��������
	get_image(ORIGINX+60,ORIGINY+180,ORIGINX+245,ORIGINY+207,text1save);	//�ֻ���
	get_image(ORIGINX+60,ORIGINY+226,ORIGINX+245,ORIGINY+253,text2save);	//��֤��

	
	/**************
	������ͷ��
	**************/
	FillCircle(ROBOTx,ROBOTy-60,20,255);
	FillCircle(ROBOTx,ROBOTy-56,16,65535);
	circle(ROBOTx,ROBOTy-56,16,0);
	FillCircle(ROBOTx,ROBOTy-60,2,40966);
	//bar(ROBOTx-16,ROBOTy-48,ROBOTx+16,ROBOTy-20,255);
	//bar(ROBOT.x-17,ROBOT.y-21+ROBOT.leg_left,ROBOT.x,ROBOT.y-13+ROBOT.leg_left,0);
	//bar(ROBOT.x,ROBOT.y-21+ROBOT.leg_right,ROBOT.x+17,ROBOT.y-13+ROBOT.leg_right,0);
	//bar(ROBOT.x-16,ROBOT.y-20+ROBOT.leg_left,ROBOT.x-1,ROBOT.y-14+ROBOT.leg_left,65535);
	//bar(ROBOT.x+1,ROBOT.y-20+ROBOT.leg_right,ROBOT.x+16,ROBOT.y-14+ROBOT.leg_right,65535);
	FillCircle(ROBOTx,ROBOTy-36,14,65535);
	bar(ROBOTx-16,ROBOTy-48,ROBOTx+16,ROBOTy-44,63488);
	Fillellipse(ROBOTx-6,ROBOTy-70,ROBOTx-6,ROBOTy-66,6,65535);
	Fillellipse(ROBOTx+6,ROBOTy-70,ROBOTx+6,ROBOTy-66,6,65535);
	ellipse(ROBOTx+6,ROBOTy-70,ROBOTx+6,ROBOTy-66,6,0);
	ellipse(ROBOTx-6,ROBOTy-70,ROBOTx-6,ROBOTy-66,6,0);
	semicircle_down(ROBOTx+4,ROBOTy-68,2,0);
	semicircle_down(ROBOTx-4,ROBOTy-68,2,0);
	bow(ROBOTx,ROBOTy-72,22,0);
	linever(ROBOTx,ROBOTy-58,ROBOTx,ROBOTy-50,1,0);
	//Horizline(ROBOTx-8,ROBOTy-40,16,0);
	//semicircle_up(ROBOTx,ROBOTy-40,8,0);
	
	/****************
	�����
	****************/
	//	������
	bar(ORIGINX+39,ORIGINY+207,ORIGINX+216,ORIGINY+208,0);
	bar(ORIGINX+39,ORIGINY+253,ORIGINX+216,ORIGINY+254,0);
	//	ͼ��
	FillCircle(ORIGINX+45,ORIGINY+196,3,255);
	fill_bow_left_up(ORIGINX+45,ORIGINY+205,7,255);
	fill_bow_right_up(ORIGINX+45,ORIGINY+205,7,255);
	bar(ORIGINX+39,ORIGINY+244,ORIGINX+51,ORIGINY+253,255);
	fill_bow_left_up(ORIGINX+45,ORIGINY+244,4,255);
	fill_bow_right_up(ORIGINX+45,ORIGINY+244,4,255);
	
	fill_bow_left_up(ORIGINX+45,ORIGINY+244,3,28153);
	fill_bow_right_up(ORIGINX+45,ORIGINY+244,3,28153);
	//	������ʾ
	fdhz(ORIGINX+65,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+80,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+95,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+110,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+125,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+140,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+155,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+170,ORIGINY+190,1,1,"��",25388);
	fdhz(ORIGINX+65,ORIGINY+235,1,1,"��",25388);
	fdhz(ORIGINX+80,ORIGINY+235,1,1,"��",25388);
	fdhz(ORIGINX+95,ORIGINY+235,1,1,"��",25388);
	fdhz(ORIGINX+110,ORIGINY+235,1,1,"��",25388);
	fdhz(ORIGINX+125,ORIGINY+235,1,1,"��",25388);
	fdhz(ORIGINX+140,ORIGINY+235,1,1,"��",25388);
	fdhz(ORIGINX+155,ORIGINY+235,1,1,"֤",25388);
	fdhz(ORIGINX+170,ORIGINY+235,1,1,"��",25388);
	
	/************
	��֤����հ�ť
	************/
	bar(ORIGINX+39,ORIGINY+309,ORIGINX+216,ORIGINY+310,255);
	bar(ORIGINX+39,ORIGINY+337,ORIGINX+216,ORIGINY+338,255);
	bar(ORIGINX+39,ORIGINY+310,ORIGINX+40,ORIGINY+337,255);
	bar(ORIGINX+215,ORIGINY+310,ORIGINX+216,ORIGINY+337,255);
	fdhz(ORIGINX+80,ORIGINY+315,1,1,"��",65535);
	fdhz(ORIGINX+100,ORIGINY+315,1,1,"ȡ",65535);
	fdhz(ORIGINX+120,ORIGINY+315,1,1,"��",65535);
	fdhz(ORIGINX+140,ORIGINY+315,1,1,"֤",65535);
	fdhz(ORIGINX+160,ORIGINY+315,1,1,"��",65535);
	
	/************
	��¼��ť
	************/
	bar(ORIGINX+39,ORIGINY+360,ORIGINX+216,ORIGINY+388,255);
	fdhz(ORIGINX+100,ORIGINY+370,1,1,"��",65535);
	fdhz(ORIGINX+140,ORIGINY+370,1,1,"¼",65535);
}





//	���߼�
int checkin(int* x, int* y)
{
	
	int button=0,mx=0,my=0,mouse=0;		/*������������*/
	int iph_num=0;		/*����ֻ����Ƿ�������ȷ*/
	char id_code[5]={'\0','\0','\0','\0','\0'};		/*�洢�������֤��*/
	char id_real[5]={'1','\0','\0','\0','\0'};		/*�洢���ɵ���֤��*/
	unsigned int *text1save=(unsigned int *)malloc(185*27*sizeof(unsigned int));	//	�������ֱ����ͼ��
	unsigned int *text2save=(unsigned int *)malloc(185*27*sizeof(unsigned int));	//	�������ֱ����ͼ��
	
	if(text1save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(text2save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	mousehide(*x,*y);
	//mouseInit(&mx, &my, &button);	//	��ʼ�����
	iph_frame(28153);	//	�ֻ�����
	checkin_interface(text1save,text2save);	//	��¼����
    
	reset_mouse(x,y);
	while(1){
		newxy(x,y,&button);
		mx = *x;
		my = *y;
		mouse = checkin_click(x,y,button);

		switch(mouse)
		{
			case 0:
					break;
			case 1:			//	������Ͻ��˳�����
					exit(1);
					break;
			case 2:			//	�������ֻ�����ȷ��iph_numΪ1��֮���ȡ��֤��ʱ�����յ����ţ������ղ�����֤��
					iph_num = 0;
					input_num(x,y,&iph_num,text1save);	
					break;
			case 3:			//	id_codeΪ�������֤��ֵ�������¼ʱ�ɹ�����������¼ʱ����������Ϣ
					id_check(x,y,id_code,text2save);		
					break;
			case 4:			//	������֤�뵯����ͣ��1.5s
					if(iph_num == 1){
						save_code(id_real);
					}
				
					break;
			case 5:			//	�˶���֤�����ȷ�Բ�������һ����
					if(strcmp(id_code,id_real)==0){
						mousehide(*x,*y);
						bar(0,0,1024,768,0);
						fdhz(200,200,3,3,"���",65535);
						return 0;
						}
					else{
						fdhz(ORIGINX+65,ORIGINY+215,1,1,"��֤���������",25388);
						delay(500);
						bar(ORIGINX+65,ORIGINY+215,ORIGINX+210,ORIGINY+235,28153);
						//error_box();
					}
					reset_mouse(x,y);
					//ti
					
					
			case 6:
					break;
					
		}
		
		mouse=0;
		/*********************
		//	������Ͻ��˳�
		if(mx>=(0)&&mx<=(200)&&my<=(200)&&my>=(0)&&button){
			exit(1);
		}
		
		
		//���"��ȡ��֤��"������ͣ��3s
		if(mx>=(ORIGINX+39)&&mx<=(ORIGINX+216)&&my<=(ORIGINY+338)&&my>=(ORIGINY+309)&&button){
			get_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
			message_box();
			delay(3000);
			put_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
			free(image_save);
			image_save = NULL;
		}
		
		************************/
		//	��������û����������������ģʽ
	}
	
	free(text1save);		//�ͷ��ڴ�
	free(text2save);
	text1save = NULL;
	text2save = NULL;
	
	return 1;
}



int checkin_click(int *mx,int *my,int button)
 {
	 /*********
	��ťλ�ñ�׼��
	�����п��ܵİ�ťλ�����괢���ڶ�ά������
	*********/
	int a[5][4];
	a[0][0] = 0;	//	a[0][]:������Ͻ��˳�����
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	a[1][0] = ORIGINX+60;		//	a[1][]:��������ֻ���	get_image(ORIGINX+60,ORIGINY+194,ORIGINX+170,ORIGINY+207,text1save);	
	a[1][1] = ORIGINX+240;
	a[1][2] = ORIGINY+190;
	a[1][3] = ORIGINY+207;
	a[2][0] = ORIGINX+60;		//	a[2][]:���������֤��	get_image(ORIGINX+60,ORIGINY+239,ORIGINX+170,ORIGINY+253,text2save);
	a[2][1]	= ORIGINX+240;
	a[2][2]	= ORIGINY+235;
	a[2][3] = ORIGINY+253;
	a[3][0] = ORIGINX+39;		//	a[3][]:�����ȡ��֤��			39 216 309 338
	a[3][1]	= ORIGINX+216;
	a[3][2]	= ORIGINY+309;
	a[3][3] = ORIGINY+338;
	a[4][0] = ORIGINX+39;		//	a[4][]:�����¼					ORIGINX+39,ORIGINY+360,ORIGINX+216,ORIGINY+388
	a[4][1]	= ORIGINX+216;
	a[4][2]	= ORIGINY+360;
	a[4][3] = ORIGINY+388;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && button)	return 1;   //if(������˳�����)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && button)	return 2;   //if(��������ֻ������롿����)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && button)	return 3;   //if(���������֤�����롿����)
	else if (*mx >= a[3][0] && *mx <= a[3][1] && *my >= a[3][2] && *my <= a[3][3] && button)	return 4;   //if(���������ȡ��֤�롿����)
	else if (*mx >= a[4][0] && *mx <= a[4][1] && *my >= a[4][2] && *my <= a[4][3] && button)	return 5; 	//if(���������¼������)
	else if (button)																		return 6;	//if(�������������)
    else return 0;
 }