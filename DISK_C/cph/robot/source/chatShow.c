/******************�����嵥***************************
1.  void show_order(int *qhwh,int *y);
2.	void get_str(int *qhwh, char *incode);
3.	void reply_match(char * str,char *order,char *reply);
4.	void show_reply(char *incode, int * y);
5.	void show_main(int *qhwh);
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

#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764
#define MAXTXT 1000


/**************

	��ӡ����
	
**************/
void show_order(int *qhwh,int *y)
{
	int num_qhwh;	//�ַ���
	int num_line;	//���ӡ������
	int box_top;	//���������
	
	Area order_box;
	Coordinate order_begin;

	/***************
	����м����ֲ����Ի����	
	***************/
	num_qhwh = CheckQhwhNum(qhwh);	//�õ��ַ���
	num_line = num_qhwh/10+1;		//ȷ�ϴ�ӡ����
	box_top = 345-20*num_line;		//ȷ�϶Ի�������
	
	if(num_qhwh<=10){
		bar_round_2(ORIGINX+239-num_qhwh*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);
	}
	else{
		bar_round_2(ORIGINX+239-10*16-4,ORIGINY+box_top,ORIGINX+242,ORIGINY+345,5,1,65535);
	}
	
	/***************
	��ӡ���ֲ���ӡ�û�����
	***************/
	if(num_qhwh<=10)
	{
		order_box.lt.x = ORIGINX+239-num_qhwh*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-num_qhwh*16;
		order_begin.y = ORIGINY+box_top+2;
		
		ShowTxt(qhwh, order_box, &order_begin,16);
	}
	else{
		order_box.lt.x = ORIGINX+239-10*16-4;
		order_box.lt.y = ORIGINY+box_top;
		order_box.rb.x = ORIGINX+243;
		order_box.rb.y = ORIGINY+345;
		order_begin.x = ORIGINX+239-10*16;
		order_begin.y = ORIGINY+box_top+2;
		
		ShowTxt(qhwh, order_box, &order_begin,16);
	}
	
	fdhz(ORIGINX+243-16*2,ORIGINY+box_top-20,1,1,"��",65535);
	fdhz(ORIGINX+243-16*1,ORIGINY+box_top-20,1,1,"��",65535);
	
	/*************
	�ı�ظ������ռλ��¼ֵ
	*************/
	//*y = ORIGINY+box_top-25;
	*y = ORIGINY+50+20*num_line+25;
}

/**************

	�����õ��û�������ַ���

**************/
void get_str(int *qhwh, char *incode)
{
	char *p=incode;	//incode��λ��ָ��
	int num_qhwh = CheckQhwhNum(qhwh);
	int i;
	
	for(i=0;i<num_qhwh;i++)
	{
		qhwh2incode(*qhwh,p);
		p+=2;
		qhwh++;
	}
	*p = '\0';
	
}


	
/**************
	
	ǰ���ļ���Ѱ��ƥ��ظ�
	
**************/
void reply_match(char * str,char *order,char **reply,unsigned int *box_save)
{
	FILE *fp;                                              /*�����ļ�ָ��*/

	fp = fopen("BGI\\match.txt", "rt");
	if (fp == NULL)
	{
		printf("the file cant open \n");
		exit(1);
	}

	while (feof(fp) == 0)
	{
		fscanf(fp, "%s", order);
		fscanf(fp, "%s", *reply);
		if (strcmp( order, str) == 0)
		{ 
			if(strcmp(*reply,"�ã����ڿ�ʼ��")==0)
			{
				delay(300);
				word_game(box_save);
				*reply = "�´������氡";
			}
			fclose(fp);
			return;
		}
	}
	
}


/**************

	�����ظ�
	
**************/
void show_reply(char *incode, int * begin_y)
{
	int x=ORIGINX+17,y;	//��ӡ�ظ����ֵ�λ��
	int box_top;	//�Ի���׶�����������
	int i;			//temp
	int num_word=0;	//��Ҫ�ظ�������
	int num_line;	//�ظ�����
	char *p_incode=incode;	//incode��λ��ָ��
	
	/*************
	����м�����
	*************/
	while(*p_incode!=NULL)
	{
		p_incode+=2;
		num_word++;
	}
	
	/*************
	���Ի����
	*************/
	num_line = num_word/10+1;
	box_top = 345-20*num_line;
	if(num_word<=10){	//���粻��һ�У����ӡ��Ӧ�����Ŀ򣨿�ȿɵ���
		bar_round_2(ORIGINX+13,ORIGINY+box_top,ORIGINX+17+num_word*16+4,ORIGINY+345,5,1,65535);
	}
	else{		//���糬��һ�У����Ŀ�ȶ�����Ϊ�����
		bar_round_2(ORIGINX+13,ORIGINY+box_top,ORIGINX+17+10*16+4,ORIGINY+345,5,1,65535);
	}
	
	/*************
	��ӡ�ظ��ĺ���
	*************/
	i = 0;	//���������
	y = ORIGINY+box_top+2;
	while(*incode!=NULL)
	{
		while( (i<10)&&(*incode!=NULL) )
		{
			dishz(x,y,1,1,incode,36410);
			i++;
			x+=16*1;
			incode+=2;
		}
		i=0;
		x=ORIGINX+17;
		y+=20*1;
	}
	
	/*************
	��ӡ����è����
	*************/
	fdhz(ORIGINX+13+16*0,ORIGINY+box_top-20,1,1,"��",65535);
	fdhz(ORIGINX+13+16*1,ORIGINY+box_top-20,1,1,"��",65535);
	fdhz(ORIGINX+13+16*2,ORIGINY+box_top-20,1,1,"��",65535);
	fdhz(ORIGINX+13+16*3,ORIGINY+box_top-20,1,1,"��",65535);
	
	/*************
	�ı�ظ������ռλ��¼ֵ
	*************/
	//*y = ORIGINY+box_top-25;
	*begin_y = ORIGINY+50+20*num_line+25;

}




void show_main(int *qhwh,unsigned int *box_save)
{
	int num_qhwh;	//ͳ��������ַ�����
	int begin_y;	//���ÿ�ζԻ������ʱ�Ķ���y������ȷ��putimage�ķ�Χ
	char *order = (char *)malloc(30*sizeof(char));	//֮���ǵ��ļ��е��ʾ䲿��
	char *reply = (char *)malloc(30*sizeof(char));	//֮���ǵ��ļ��еĴ�䲿��
	char *incode = (char *)malloc(30*sizeof(char));	//�û��������������

	/*when_press_ENTER
	save_image
	checkQhwhNum
	Check_QhwhNum>10_
	put_image
	draw_box
	delay
	put_image_moveup
	draw_box_moveup_standard_height
	draw_another_box*/
	
	if(order==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(reply==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(incode==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/***************
	��ʾ�û����벿��
	***************/
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);	//���Ҫ��ʾ�û�������Ϣ������
	show_order(qhwh,&begin_y);	//��ʼ��ʾ�û�������Ϣ
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
	
	delay(500);	//�ȴ������˻ظ�
	
	/***************
	��ʾ�����˻ظ�����
	***************/
	
	//Ѱ��ƥ���
	//delay(2000);
	get_str( qhwh, incode);
	reply_match( incode, order, &reply,box_save);
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
	//delay(2000);
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//���Ҫ��ʾ�ظ���Ϣ������
	show_reply(reply,&begin_y);	//��ʼ��ʾ�ظ���Ϣ
	///////////////////////put_image_2(ORIGINX+13,ORIGINY+50,ORIGINX+243,ORIGINY+345, window_save, begin_y);
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
	
	//�ͷſռ�
	free(order);
	order = NULL;
	free(reply);
	reply = NULL;
	free(incode);
	incode = NULL;
	
}

