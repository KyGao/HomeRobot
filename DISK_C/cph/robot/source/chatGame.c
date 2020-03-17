/******************�����嵥***************************
1.  void show_gg(char *temp);
2.	int question_generator(char **question,char **answer);
3.	int check_answer(char *incode,char *answer);
4.	void word_game();
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

	Ҫ�˳�������Ϸ���˵һ�仰
	
**************/
void show_gg(char *temp)
{
	int begin_y;	//���ÿ�ζԻ������ʱ�Ķ���y������ȷ��putimage�ķ�Χ
	
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//���Ҫ��ʾ�ظ���Ϣ������
	show_reply(temp,&begin_y);	//��ʼ��ʾ�ظ���Ϣ
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
	return;
}

/**************
	
	������Ŀ,�����Ѿ����������
	
**************/
int question_generator(char *question,char *answer)
{
	FILE *game;
	int tm;		//����ȷ������ѡ������
	int i=0;	//�����ʱѡ������
	
	srand((unsigned)(time(NULL)));		//�����������
	tm = rand()%10;
	game = fopen("BGI\\game.txt","r");
	if (game == NULL)
	{
		printf("the file cant open \n");
		exit(1);
	}
	
	rewind(game);	//ʹָ��ָ���ļ����Ŀ�ͷ
	while(feof(game)==0)	//���ļ���ȡ��ϻ��������ѡ��������ʱ
	{	

		fscanf(game,"%s",question);
		fscanf(game,"%s",answer);
		if(i==tm){
			break;
		}
		i++;
	}
	
	fclose(game);
	return tm;
}

/**************

	����ǲ��Ǵ𰸣��ǵĻ�����1
	
**************/
int check_answer(char *incode,char *answer)
{
	if(strcmp(incode,answer)==0){
		return 1;
	}
	return 0;
}

/**************
	
	���ղ��֣����롰�Ҳ����ˡ������˳���Ϸ
	
**************/
void word_game(unsigned int *box_save)
{
	 Area box_area = { {ORIGINX+15+2,ORIGINY+415} , {ORIGINX+240,ORIGINY+460} };		//��������Ͻ�����
	 Coordinate current_show_position = {ORIGINX+17,ORIGINY+407};		//������������ֵ����Ͻ�����
	 int *qhwh=(int *)malloc(sizeof(int)*MAXTXT);		//���ֵ�����λ��
	// unsigned int *box_save=(unsigned int *)malloc(200*35*sizeof(unsigned int));	//�������뷨���е�ͼ��
	int begin_y;	//���ÿ�ζԻ������ʱ�Ķ���y������ȷ��putimage�ķ�Χ
	char *question=(char *)malloc(30*sizeof(char));	//֮���ǵ��ļ��е��ʾ䲿��
	char *answer=(char *)malloc(2*sizeof(char));	//֮���ǵ��ļ��еĴ�䲿��
	char *incode=(char *)malloc(30*sizeof(char));	//�û��������������
	
	char *temp;	//�����ɱ�ظ���֮��ظ�������Ѿ��������������͡��ðɣ������ǲ�������֮����õ�
	
	int tm;	//��Ǹ���ѡ�е����
	int tm_done=0;	//����Ѿ��ʹ�����Ŀ����
	int have_done[9]={0};	//�û��Ѿ��¹�����ű��Ϊ1
	
	if(qhwh==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(box_save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(question==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(answer==NULL)
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
	get_image(ORIGINX+25,ORIGINY+365/*365*/,ORIGINX+225,ORIGINY+400/*400*/, box_save);
	
	//����
	temp = "�����������ǿ�ʼ��";
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//���Ҫ��ʾ�ظ���Ϣ������
	show_reply(temp,&begin_y);	//��ʼ��ʾ�ظ���Ϣ
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);	
	temp = NULL;

	while(1)
	{
		/************
			show
		************/
		while(1)	//ȷ�����ѡ�е���Ŀû�г��ֹ�
		{
			tm = question_generator(question,answer);	//���еڼ���
			if(have_done[tm]==0)	//�������û�б��ʹ�
			{
				have_done[tm] = 1;	//��Ǹ��ⱻ�ʹ�
				tm_done++;			//�ʹ���������һ
				break;	
			}
			if(tm_done==9)	//���������Ŀ�Ѿ����������˳�
			{
				delay(500);
				temp = "����Ѿ�����������";
				show_gg(temp);
				temp = NULL;
				return;
			}
		}
		//����Ŀչʾ����
		save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
		bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//���Ҫ��ʾ�ظ���Ϣ������
		show_reply(question,&begin_y);	//��ʼ��ʾ�ظ���Ϣ
		printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
		
		//fdhz(200,100,2,2,question,0);
		//fdhz(200,200,2,2,answer,0);
		
		/**************put&check******************/
		while(1)
		{
			/************
				put
			************/
			QhwhToZero(qhwh);	//��ʼ����λ��
			ShowChTab(box_area,current_show_position/*������������ֵ����Ͻ�����*/,16,qhwh, box_save);	//��ʼ�û��ı���
			bar(ORIGINX+15, ORIGINY+405, ORIGINX+240, ORIGINY+460,65535);	//�س���֮��ˢ�����촰��

			//����ʾ�û�������ַ�
			save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
			bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);	//���Ҫ��ʾ�û�������Ϣ������
			show_order(qhwh,&begin_y);	//��ʼ��ʾ�û�������Ϣ
			printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
			
			/***********
				check
			***********/
			get_str( qhwh, incode);		//�õ�������ַ�������
			
			//fdhz(200,300,2,2,incode,0);
			
			if(strcmp(incode,"�Ҳ�����")==0)	//�����������
			{
				delay(500);
				return;							//���˳�
			}
			
			if(strcmp(incode,"��һ��")==0)	//���ѡ����һ��
			{
				delay(500);
				temp = "��һ��Ҫ����ѽ��";
				show_gg(temp);
				temp = NULL;
				break;
			}

			if(check_answer(incode,answer)==1)	//��������
			{
				delay(500);
				temp = "����ˣ�̫���ˣ�";
				show_gg(temp);
				temp = NULL;
				break;
			}
			else if(check_answer(incode,answer)==0)	//��������
			{
				delay(500);
				temp = "���Բ���";
				show_gg(temp);
				temp = NULL;
			}
		}
	}
	
	//�ͷ��ڴ�
	free(question);
	free(answer);
	free(incode);
	//free(box_save);
	free(qhwh);
	qhwh = NULL;
	//box_save = NULL;
	question = NULL;
	answer = NULL;
	incode = NULL;
}


