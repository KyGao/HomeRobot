#include "main.h"//	��֤����Ϣ����
#include <ctype.h>
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

	//	��֤�뵯��
void message_box(char* id_real)
{
	int a,i;
	char b[5],c[2],d[2],e[2];
	
	//��������
	bar_round_2(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+96,10,1,65535);
	bar_round_2(ORIGINX+11,ORIGINY+46,ORIGINX+24,ORIGINY+56,4,1,18155);
	fdhz(ORIGINX+30,ORIGINY+44,1,1,"��",0);
	fdhz(ORIGINX+45,ORIGINY+44,1,1,"��",0);
	fdhz(ORIGINX+45,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+60,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+75,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+90,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+105,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+120,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+135,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+150,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+165,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+180,ORIGINY+60,1,1,"¼",0);
	fdhz(ORIGINX+195,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+210,ORIGINY+60,1,1,"��",0);
	fdhz(ORIGINX+225,ORIGINY+60,1,1,"֤",0);
	fdhz(ORIGINX+15,ORIGINY+75,1,1,"��",0);
	fdhz(ORIGINX+30,ORIGINY+75,1,1,"Ϊ",0);
	
	//���������
	srand((unsigned)time(0));
	a=rand()%10000;
	itoa(a,b,5);
	/*itoa(a[1],c,5);
	itoa(a[2],d,5);
	itoa(a[3],e,5);
	b[1]='\0';
	c[1]='\0';
	d[1]='\0';
	e[1]='\0';*/
	b[4]='\0';			//�������⣬�ƺ�ÿ�γ��ֵ�������Ȼ��ͬ��������3��ͷ��
	
	for(i=0;i<5;i++){
		id_real[i] = b[i];
	}
	
	
	outtextxy(ORIGINX+40,ORIGINY+75,b,2,1,15,0);
	return b;
}


	

	//	��֤����Ϣ�洢
void save_code(char* id_real)//id_realֱ�ӽ���һ��message_box�ķ���ֵ���ٴ�����һ��
{
	unsigned int *image_save=(unsigned int *)malloc(246*60*sizeof(unsigned int));	//	������֤�뵯�������ͼ��
		
	if(image_save==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	get_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
	message_box(id_real);
	delay(1500);
	put_image(ORIGINX+4,ORIGINY+40,ORIGINX+250,ORIGINY+100,image_save);
	free(image_save);
	image_save = NULL;
	
}


//	�������ֻ�����ȷ��iph_numΪ1��֮���ȡ��֤��ʱ�����յ����ţ������ղ�����֤��
void input_num(int *mx,int *my,int *judge,unsigned int *text1save)
{
	char ph_num[12];	//�����ַ���������
	char real_num[12] = {'0','0','0','0','0','0','0','0','0','0','0','\0'};
	char *p = ph_num;	//�����ַ����м�ָ�����,�൱��ph_num[12]��������
	int key;			//��ȡ��ֵ�ı�ʶ
	int i=0;			//���ڼ����������ַ���Ŀ
	char ch;			//������ʱ�����ֵ����Ӧ�ַ��ı���
	int m_case=0;		//�����ж���������ﲢ�ҽ�����һ������
	int button;
	char temp[2] = {'\0','\0'};	//	ȷ���ڶ�λ��'\0'����ʱ��outtext������ʱ������������
	
	put_image(ORIGINX+60,ORIGINY+180,ORIGINX+245,ORIGINY+207,text1save);//(ORIGINX+60,ORIGINY+194,ORIGINX+170,ORIGINY+207,text1save);	//
	
	for(i=0;i<12;i++){
		ph_num[i] = '\0';
	}
	i=0;
	
	while(1)
	{
		newxy(mx,my,&button);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}			//��ռ��̻�����//
		if(key == 0xe08)	//����˸��ʱ�Ĳ���
	    {
		    if(p != ph_num)		//����Ƿ�����λ����ַ�Ƿ���ͬ��
		    {
			    bar(ORIGINX+50+ i * 13+3, ORIGINY+192, ORIGINX+50+18 + i * 13, ORIGINY+206,28153);
			    p--;			//ָ��		��ǰ��
			    i--;			//������	��ǰ��
		    }
			*p = '\0';			//	ͬ�������һλ����'\0'
	    }
		
		//	��������Ӧ���ַ�һ��������ph_num������
	    ch = searchKeyValue(key);
	    if ((ch != '\0') && (i<11) && (ch>='0') && (ch<='9'))	//һ��Ҫ�����ֲ������
	    {
			temp[0] = ch;
			outtextxy(ORIGINX+50+5+i*13,ORIGINY+192,temp,2,1,10,0);

		//	���ַ�����������
		    *p = ch;
		    p++;
		    *p = '\0';		// ÿ�β�����Ҫ��'\0'
		    i++;
	    }
		
		m_case = checkin_click(mx,my,button);	//	������������ֻ��ſ��򲻷����κ��£��������������������ѭ�����ص����߼���������߼�
		if(m_case!=2 && m_case!=0 || key == 0x1c0d){
			break;
		}
	}
	
	ph_num[11] = '\0';

	if(strcmp(ph_num,real_num)==0){
		*judge=1;	//�������ֻ�����ȷ����ɽ��յ���֤��
	}
	
	return;
}

	//	��������֤��ƥ����id_codeΪ1�������¼ʱ�ɹ�����������¼ʱ����������Ϣ
void id_check(int *mx,int *my,char *id_code,unsigned int *text2save)
{
	char id_num[5];	//�����ַ���������
	char *p = id_num;	//�����ַ����м�ָ�����,�൱��ph_num[12]��������
	int key;			//��ȡ��ֵ�ı�ʶ
	int i=0;			//���ڼ����������ַ���Ŀ
	char ch;			//������ʱ�����ֵ����Ӧ�ַ��ı���
	int m_case=0;		//�����ж���������ﲢ�ҽ�����һ������
	int button;
	char temp[2] = {'\0','\0'};	//	ȷ���ڶ�λ��'\0'����ʱ��outtext������ʱ������������
	
	put_image(ORIGINX+60,ORIGINY+226,ORIGINX+245,ORIGINY+253,text2save);	
	
	for(i=0;i<5;i++){
		id_num[i] = '\0';
	}
	i=0;
	
	while(1)
	{
		newxy(mx,my,&button);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}			//��ռ��̻�����//
		if(key == 0xe08)	//����˸��ʱ�Ĳ���
	    {
		    if(p != id_num)		//����Ƿ�����λ����ַ�Ƿ���ͬ��
		    {
			    bar(ORIGINX+50+ i * 13+3, ORIGINY+239, ORIGINX+50+18 + i * 13, ORIGINY+251,28153);
			    p--;
			    i--;
		    }
			*p = '\0';			//	ͬ�������һλ����'\0'
	    }
		
		//	��������Ӧ���ַ�һ��������id_num������
	    ch = searchKeyValue(key);
	    if ((ch != '\0') && (i<4) && (ch>='0') && (ch<='9'))	//һ��Ҫ�����ֲ������
	    {
			temp[0] = ch;
			outtextxy(ORIGINX+50+5+i*13,ORIGINY+238,temp,2,1,10,0);

		//	���ַ�����������
		    *p = ch;
		    p++;
		    *p = '\0';		// ÿ�β�������λ�󣩶�Ҫ��'\0'
		    i++;
	    }
		
		m_case = checkin_click(mx,my,button);	//	�������������֤����򲻷����κ��£��������������������ѭ�����ص����߼���������߼�
		if(m_case!=3 && m_case!=0 || key == 0x1c0d){
			break;
		}
	}
	
	id_num[4] = '\0';
	for(i=0;i<5;i++){
		id_code[i] = id_num[i];
	}
	
}