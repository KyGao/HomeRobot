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
/*********************************************
����ui������ģ�飨����̩���֣�
void move_ui(void);
void easy_ui(void);
void clean_ui(void);
void move_control(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y);
void clean_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y);
void easy_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y);
**********************************************/
/*��ȫ����ui*/
void move_ui(void)
{
	iph_frame(36410);
	/*ͼ�ο�*/
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y-SCREENHEIGHT/7+2,180,SCREENHEIGHT/7-20,15,1,0);//��ɫ�����������ӰЧ��
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y+2,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-SCREENHEIGHT/7,180,SCREENHEIGHT/7-20,15,1,18202);
	bar_round(SCREENCENTER_x, SCREENCENTER_y,180,SCREENHEIGHT/7-20,15,1,34431);
	/*����*/
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-SCREENHEIGHT/7-20,2,2,"���Ѳ��",65535);
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-20,2,2,"����Ѳ��",65535);
	
		//��ҳͼ�꣨˫Բ��
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
}

/*��ݹ���ui*/
void easy_ui(void)
{
	iph_frame(36410);
	/*ͼ�ο�*/
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y-SCREENHEIGHT/7+2,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-SCREENHEIGHT/7,180,SCREENHEIGHT/7-20,15,1,18202);
    /*����*/
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-SCREENHEIGHT/7-20,2,2,"������",65535);
	
		//��ҳͼ�꣨˫Բ��
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
}

/*����ui*/
void clean_ui(void)
{
	iph_frame(36410);
	/*ͼ�ο�*/
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y-SCREENHEIGHT/7+2-90,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y+2-90,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x+2, SCREENCENTER_y+SCREENHEIGHT/7+2-90,180,SCREENHEIGHT/7-20,15,1,0);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-SCREENHEIGHT/7-90,180,SCREENHEIGHT/7-20,15,1,18202);
	bar_round(SCREENCENTER_x, SCREENCENTER_y-90,180,SCREENHEIGHT/7-20,15,1,34431);
	bar_round(SCREENCENTER_x, SCREENCENTER_y+SCREENHEIGHT/7-90,180,SCREENHEIGHT/7-20,15,1,17244);
	/*����*/
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-SCREENHEIGHT/7-110,2,2,"����",65535);
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y-110,2,2,"��ɨ",65535);
	fdhz(SCREENCENTER_x-80,SCREENCENTER_y+SCREENHEIGHT/7-110,2,2,"������",65535);
	
		//��ҳͼ�꣨˫Բ��
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	/*����*/
	fdhz(SCREENCENTER_x-100,SCREENCENTER_y+50,1,1,"����Ͱһ",65535);
	fdhz(SCREENCENTER_x-100,SCREENCENTER_y+110,1,1,"����Ͱ��",65535);
	fdhz(SCREENCENTER_x-100,SCREENCENTER_y+170,1,1,"����Ͱ��",65535);
}

/*��ȫ�����߼�*/
int move_control(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y)
{
	int button;
	int judge=-1;//�жϵ��ù���
	int click=0;//�ж��˳�
	mousehide(*x,*y);
	move_ui();
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		/*����Ƿ����˳���ť*/
		click=esc_check(esc1,x,y,&button);
		if(click==1)
		{
			return 1;
		}
		/*����ƶ�*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2 && button)
		{
			/*����Ч��*/
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,65535);
            linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,0);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,65535);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,0);
			delay0(10);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,18202);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,18202);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			
			while(1)
			{
				judge = randmove(robot_position,esc1,x,y);
				if(judge == -2)
				{
					break;
				}
				//��¥��

				/*ground to outside*/
				if (((*robot_position).y == 9 || (*robot_position).y == 10) && ((*robot_position).x == 1) && ((*robot_position).position == 1))
				{
					/*���»�����λ��*/
					(*robot_position).position = 0;
					mousehide(*x,*y);
					/*���Ƶ�ͼ*/
					bar(0, 0, 764, 768, 65535);
					_outside();
					/*�������*/
					reset_mouse(x, y);
					/*�����˶�����λ*/
					(*robot_position).x = 10;
					(*robot_position).y = 10;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					/*��ȡ����ͼ��*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*����������*/
					forebodyhead(*robot_position);
				}
				/*outside to ground*/
				if (((*robot_position).x == 11) && ((*robot_position).y == 10) && ((*robot_position).position == 0))
				{
					/*���»�����λ��*/
					(*robot_position).position = 1;
					mousehide(*x,*y);
					/*���Ƶ�ͼ*/
					bar(0, 0, 764, 768, 65535);
					_ground();
					/*�������*/
					reset_mouse(x, y);
					/*�����˶�����λ*/
					(*robot_position).x = 2;
					(*robot_position).y = 9;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					/*��ȡ����ͼ��*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*����������*/
					forebodyhead(*robot_position);

				}
				/*ground to room*/
				if (((*robot_position).x == 9) && ((*robot_position).y == 8) && ((*robot_position).position == 1))
				{
					/*���»�����λ��*/
					(*robot_position).position = 2;
					/*�����˶�����λ*/
					(*robot_position).x = 5;
					(*robot_position).y = 4;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					mousehide(*x,*y);
					/*���Ƶ�ͼ*/
					bar(0, 0, 764, 768, 0);
					floor_R();
					/*�������*/
					reset_mouse(x, y);
					/*��ȡ����ͼ��*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*����������*/
					forebodyhead(*robot_position);
				}
				/*room to ground*/
				if (((*robot_position).x == 6) && ((*robot_position).y == 4) && ((*robot_position).position == 2))
				{
					/*���»�����λ��*/
					(*robot_position).position = 1;
					/*�����˶�����λ*/
					(*robot_position).x = 10;
					(*robot_position).y = 8;
					(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
					(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
					(*robot_position).leg = 0;
					(*robot_position).leg_left = 0;
					(*robot_position).leg_right = 0;
					mousehide(*x,*y);
					/*���Ƶ�ͼ*/
					bar(0, 0, 764, 768, 65535);
					_ground();
					/*�������*/
					reset_mouse(x, y);
					/*��ȡ����ͼ��*/
					get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
					/*����������*/
					forebodyhead(*robot_position);
				}
			}
			
		}
		/*����Ѳ��*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+2-SCREENHEIGHT/7+20 && *y <= SCREENCENTER_y+2+SCREENHEIGHT/7-20 && button)
		{
			/*���ö���Ѳ�߹���*/
			go_to(robot_position,esc1,x,y);
			break;
		}
		/*����������*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)||(judge==-2))
		{
			/*�л�����*/
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			judge = -1;
			break;
		}
		
	
	}
}

/*���������߼�*/
int clean_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y)
{
	int button;
	int judge=-1;//�жϵ��ù���
	int click=0;//�ж��˳�
	mousehide(*x,*y);
	clean_ui();
	reset_mouse(x,y);
	ShowTrashNum();
	while(1)
	{
		newxy(x,y,&button);
		
		/*����Ƿ����˳���ť*/
		click = esc_check(esc1,x,y,&button);
		if(click==1)
		{
			return 1;
		}
		/*���Ӳ�*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2-90 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-90 && button)
		{
			/*����Ч��*/
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,2,65535);
            linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,2,0);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,65535);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,0);
			delay0(10);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2-90,2,18202);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2-90,2,18202);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,18202);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5-90,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5-90,2,18202);
			clean_weed(robot_position,x,y);
			
		}
		/*��ɨ*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+2-SCREENHEIGHT/7+20-70 && *y <= SCREENCENTER_y+2+SCREENHEIGHT/7-110 && button)
		{
			clean(robot_position,save,x,y);
			ShowTrashNum();
			button = 0;
			
		}
		/*������*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y+SCREENHEIGHT/7+2-SCREENHEIGHT/7-70 && *y <= SCREENCENTER_y+SCREENHEIGHT/7+2+SCREENHEIGHT/7-110 && button)
		{
			throw_trash(robot_position,x,y);
			mousehide(*x,*y);
			ShowTrashNum();
		}
		/*����������*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)||(judge==-2))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			//mousehide(*x,*y);
			judge = -1;
			break;
		}
	}
}

/*��ݹ����߼�*/
int easy_control(ROBOT_CASE *robot_position,BUTTONS *esc1,SAVE *save,int *x,int *y)
{
	int click=0;
	int button;
	int judge=-1;
	easy_ui();
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		
		/*����Ƿ����˳���ť*/
		click=esc_check(esc1,x,y,&button);
		if(click==1)
		{
			return 1;
		}
		/*������*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2 && button)
		{
			/*����Ч��*/
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,65535);
            linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,0);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,65535);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,0);
			delay0(10);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,965,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-2,2,18202);
			linelevel(824,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,965,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+2,2,18202);
			linever(806,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,806,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			linever(982,SCREENCENTER_y-SCREENHEIGHT/7+2-(SCREENHEIGHT/7-20)/2+5,982,SCREENCENTER_y-SCREENHEIGHT/7+2+(SCREENHEIGHT/7-20)/2-5,2,18202);
			/*�����ӹ���*/
			movechair(robot_position,save,x,y);
		}
		
		/*����������*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button)||(judge==-2))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			judge = -1;
			break;
		}
	}
}

