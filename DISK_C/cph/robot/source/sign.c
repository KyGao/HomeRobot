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
int input_account(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *p=account;//�����ַ����м�ָ�����
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons,judge;
	char temp[2] = {'\0','\0'};
	
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(p != account)
		    {
			    bar(290 + i * 18, 195, 310 + i * 18, 213,65535);
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//��ֹ����ڵ�
		if(*x>=300&&*x<=700&&*y>=175&&*y<=225)
		{
			mousehide(*x,*y);
		}
		
		//��¼��
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&buttons)
		{
            linelevel(220,525,385,525,2,65535);
            linelevel(220,673,385,673,2,0);
			linever(200,535,200,655,2,65535);
			linever(400,535,400,655,2,0);
			delay0(10);
			linelevel(220,673,385,673,2,31694);
			linelevel(220,525,385,525,2,31694);
			linever(200,535,200,655,2,31694);
			linever(400,535,400,655,2,31694);
			judge = sign_in_check(head,account,code);
			return judge;
		}
		
		//��������
		if(*x>=300&&*x<=700&&*y>=325&&*y<=375&&buttons)
		{
			return 3;
		}
		
		
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&buttons)
		{
			linelevel(620,525,785,825,2,65535);
            linelevel(620,673,785,673,2,0);
			linever(600,535,600,655,2,65535);
			linever(800,535,800,655,2,0);
			delay0(10);
			linelevel(620,673,785,673,2,31694);
			linelevel(620,525,785,525,2,31694);
			linever(600,535,600,655,2,31694);
			linever(800,535,800,655,2,31694);
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}
		
		
	/*��������Ӧ���ַ�����account��*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			temp[0] = ch;
			outtextxy(300+i*18,195,temp,2,1,10,0);


		/*���ַ�����������*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }
	}
}

int input_code(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *u = code;//�����ַ����м�ָ�����
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons,judge;

	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(u != code)
		    {
			    bar(275 + i * 25, 335, 305 + i * 25, 360,65535);
			    u--;
			    i--;
		    }
			*u = '\0';
	    }
		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//��¼��
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&buttons)
		{
            linelevel(220,525,385,525,2,65535);
            linelevel(220,673,385,673,2,0);
			linever(200,535,200,655,2,65535);
			linever(400,535,400,655,2,0);
			delay0(10);
			linelevel(220,673,385,673,2,31694);
			linelevel(220,525,385,525,2,31694);
			linever(200,535,200,655,2,31694);
			linever(400,535,400,655,2,31694);
			judge = sign_in_check(head,account,code);
			return judge;
		}
		
		//��ֹ����ʱ�ڵ�
		if(*x>=300&&*x<=700&&*y>=325&&*y<=375)
		{
			mousehide(*x,*y);
		}
	
	
		//�����˺�
		if(*x>=300&&*x<=700&&*y>=175&&*y<=225&&buttons)
		{
			
			return 2;
		}
		
		//ע���
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&buttons)
		{
			linelevel(620,525,785,825,2,65535);
            linelevel(620,673,785,673,2,0);
			linever(600,535,600,655,2,65535);
			linever(800,535,800,655,2,0);
			delay0(10);
			linelevel(620,673,785,673,2,31694);
			linelevel(620,525,785,525,2,31694);
			linever(600,535,600,655,2,31694);
			linever(800,535,800,655,2,31694);
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}
		
		
	/*��������Ӧ���ַ�����code������*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
		    
		    
		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(315+i*25,350,8,0);
		    
		/*���ַ�����������*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
}

/***********************************************************
Function: RegisteraccountsInput
Description: 1���û�ע�������˺����뺯��
             2��ֻ���Ǵ�Сд��ĸ������
             3��������1��10λ
Attention:���λ�ò�������Ҫ��ָ����ʽ���ݹ�����
Return:����2��userRegister�е���LogincodeInput����
       ����3��userRegister�е���RegistersecondcodeInput����
       ����4��userRegister��ʹ�õ�½����
       ����5��userRegister��ʹ��ע�Ṧ��
************************************************************/
int RegisteraccountsInput(char *account, int *mx, int *my)
{
	int key;    //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	char *p = account;   //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons;    //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������


    /*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
	{
		i++;
		p++;
	}



	while (1)
	{
		newxy(mx, my, &buttons);

		/*���ü�ֵ���õ��¼�ֵ*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		
		/*if(����һ��enter������������������������һ���·����)����2��ʾ����RegistercodeInput����*/
		if (*mx >= 400 && *mx <= 600&& *my >= 285 && *my <= 315 && buttons || key == 0x1c0d || key == 0x5000)
		{
			return 2;
		}

		/*if���������һ�������������򣩷���3��ʾ����RegistersecondcodeInput����*/
		if (*mx >= 400 && *mx <= 600 && *my >= 385 && *my <= 415 && buttons)
		{
			return 3;
		}

		/*if(���ע���������)����4��ʾע����ɲ����͵�¼���� */
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{
			return 4;
		}

		/*if(��������˺Ų���¼����)����5��ʾ���ص�½����*/
		if (*mx >= 75 && *mx <= 125 && *my >= 75 && *my <= 125 && buttons)
		{
			return 5;
		}

		/*���˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != account)
			{
				
				bar(385 + i * 18, 185, 405 + i * 18, 213,65535);
				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����accounts������*/
		ch = searchKeyValue(key);
		temp[0] = ch;
		
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

            outtextxy(390+i*18,195,&temp,1,1,8,0);

		}

	}
}

/***********************************************************
Function: RegistercodeInput
Description: 1���û�ע�������������뺯��
             2��ֻ���Ǵ�Сд��ĸ������
             3��������1��10λ
Attention:���λ�ò�������Ҫ��ָ����ʽ���ݹ�����
Return:����1��userRegister�е���RegisteraccountsInput����
       ����3��userRegister�е���RegistersecondcodeInput����
       ����4��userRegister��ʹ�õ�½����
       ����5��userRegister��ʹ��ע�Ṧ��
************************************************************/
int RegistercodeInput(char *code, int *mx, int *my) //��½�������������뺯��
{
	int key;     //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	char *p = code;     //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons;     //���Ĳ�������

	/*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);

		/*���ü�ֵ���õ��¼�ֵ*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}

		/*if(������˺������������һ���Ϸ����)����1��ʾ����RegisteraccountsInput����*/
		if (*mx >= 400 && *mx <= 600&& *my >= 185 && *my <= 215 && buttons || key == 0x4800)
		{

			return 1;
		}

		/*if(������ٴ����������������һ��enter�����·����) ����3��ʾ����RegistersecondcodeInput����*/
		if (*mx >= 400 && *mx <= 600 && *my >= 385 && *my <= 415 && buttons || key == 0x5000 || key == 0x1c0d)
		{

			return 3;
		}

		/*if(���ע���������) ����4��ʾע����ɲ���½*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{

			return 4;
		}

		/*if(��������˺�����) ����5��ʾ���ص�½����*/
		if (*mx >= 75 && *mx <= 125 && *my >= 75 && *my <= 125 && buttons)
		{

			return 5;
		}

		/*���˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				bar(385 + i * 15, 285, 398 + i * 15, 305,65535);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*����ֵ����code����*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

			FillCircle(392 + i * 15, 297, 5, 0);


		}
	}
}


/***********************************************************
Function: RegistersecondcodeInput
Description: 1���û�ע����������ڶ������뺯��
             2��ֻ���Ǵ�Сд��ĸ������
             3��������1��10λ
Attention:���λ�ò�������Ҫ��ָ����ʽ���ݹ�����
Return:����1��userRegister�е���RegisteraccountsInput����
       ����2��userRegister�е���RegistercodeInput����
	   ����4��userRegister��ʹ�õ�½����
	   ����5��userRegister��ʹ��ע�Ṧ��
************************************************************/
int RegistersecondcodeInput(char *secondcode, int *mx, int *my)
{
	int key;     //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	char *p = secondcode;     //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons=0; 



	/*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);

		/*���ü�ֵ���õ��¼�ֵ*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}

		/*if(������˺���������)����1��ʾ����RegisteraccountsInput����*/
		if (*mx >= 400 && *mx <= 600&& *my >= 185 && *my <= 215 && buttons)
		{
			
			return 1;
		}

		/*if(����������������������һ���Ϸ����)����2��ʾ����RegistercodeInput����*/
		if (*mx >= 400 && *mx <= 600 && *my >= 285 && *my <= 315 && buttons || key == 0x4800)
		{
	
			return 2;
		}

		/*if(����һ��enter��������½����)����4��ʾע����ɲ���½*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons || key == 0x1c0d)
		{

			return 4;
		}

		/*if(��������˺�����)����5��ʾ���ص�½����*/
		if (*mx >= 75 && *mx <= 125 && *my >= 75 && *my <= 125 && buttons)
		{
			return 5;
		}

		/*���˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != secondcode)
			{
				bar(385 + i * 15, 385, 398 + i * 15, 405,65535);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*����ֵ����secondcode����*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;


			FillCircle(392 + i * 15, 397, 5, 0);


		}
	}
}

int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *buttons)
{
	int judge = 0; //�ж�Ӧ�õ�����Щ�����ı���
	int flag1 = 0, flag2 = 0, flag3 = 0;  //�ֱ�ΪΪ�û��������롢���������Ƿ���ȷ���жϱ���
	int temp;  //�������ռ��̻������ı���
	char secondcode[11];  //�ڶ����������봮
    

	/*��Ҫ�ĳ�ʼ������*/
	secondcode[0] = '\0';
	*account = '\0';
	*code = '\0';
	mousehide(*x,*y);
    zhuce_page();
	reset_mouse(x,y);
	while (1)
	{
		newxy(x, y, buttons);

		/*���ռ��̻���������*/
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}
		
		/*��esc���˳�*/
		if(temp == 0x11b)
		{
			exit(0);
		}
		
		//���ؼ�
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 5;
		}
		//ע�Ტ��¼
		if(*x>=450&&*x<=550&&*y>=675&&*y<=725&&*buttons)
		{
			judge = 4;
			//yanzheng
		}
		//�˺�����
		if(*x>=400&&*x<=600&&*y>=185&&*y<=215&&*buttons)
		{
			judge = 1;
		}
		//����
		if(*x>=400&&*x<=600&&*y>=285&&*y<=315&&*buttons)
		{
			judge = 2;
		}
		//����ȷ������
		if(*x>=400&&*x<=600&&*y>=385&&*y<=415&&*buttons)
		{
			judge = 3;
		}
		
		
		
		switch(judge)
		{
		
		//�����˺����뺯��
		case 1:
		    judge = RegisteraccountsInput(account, x, y);
		    if (SearchAccounts(head, account) != NULL)
			{
				/*����ɫ�Ĳ沢��ʾ���˺��ѱ�ע��&flag1=0*/
				bar(800,180,900,250,1503);
				red_cross(800,200);
				bar(210,500,900,530,1503);
				fdhz(210,500,1,1,"���˺��ѱ�ע��",0);
/*�˴�����������Ҫ�޸�
				setfillstyle(1, LIGHTBLUE);
				bar(560, 120, 600, 165);
				drawRedFork(560, 130);
				backgroundChange(mx,my,560, 120, 600, 165);
				setfillstyle(1, LIGHTBLUE);
				bar(210, 170, 550, 195);
				fdhz(210,170, "该账号已被注册！", 16, 16, RED);
				backgroundChange(mx,my,210, 170, 550, 195);
*/
				flag1 = 0;
			}
		    else
			{
				/*��һ����ɫ�Ĺ�&falg1=1*/
/*
				setfillstyle(1, LIGHTBLUE);
				bar(210, 170, 550, 195);
				bar(560, 120, 600, 165);
				drawGreenHook(560, 130);
				backgroundChange(mx,my,560, 120, 600, 165);
				backgroundChange(mx,my,210, 170, 550, 195);
*/              
                bar(800,180,900,250,1503);
                green_tick(800,200);
				flag1 = 1;

			}
			break;
		/*case 2:�����������뺯��*/
		case 2:
			judge = RegistercodeInput(code, x, y);
			if (strlen(code) < 6)
			{
				/*����ɫ�Ĳ沢��ʾ���벻��������λ&flag2=0*/
/*
			   setfillstyle(1, LIGHTBLUE);
				bar(560, 200, 600, 245);
				drawRedFork(560, 210);
				backgroundChange(mx, my, 560, 200, 600, 245);
				setfillstyle(1, LIGHTBLUE);
				bar(210, 250, 550, 275);
				puthz(210, 250, "密码不得少于六位�?, 16, 16, RED);
				backgroundChange(mx, my, 210, 250, 550, 275);
*/
                bar(800,280,900,350,1503);
                red_cross(800,300);
				bar(210,500,500,530,1503);
				fdhz(210,500,1, 1, "���벻��������λ",  0);
				flag2 = 0;
			}
			else
			{
				/*��һ����ɫ�Ĺ�&flag2=1*/
/*
				setfillstyle(1, LIGHTBLUE);
				bar(210, 250, 550, 275);
				bar(560, 200, 600, 245);
				drawGreenHook(560, 210);
				backgroundChange(mx, my, 560, 200, 600, 245);
				backgroundChange(mx, my, 210, 250, 550, 275);
*/
                bar(210,500,900,530,1503);
                bar(800,280,900,350,1503);
                green_tick(800,300);
				flag2 = 1;
			}
			break;

		/*case 3:���ö����������뺯��*/
		case 3:
			judge = RegistersecondcodeInput(secondcode, x, y);
			if (strcmp(code, secondcode) != 0)
			{
				/*����ɫ�Ĳ沢��ʾ�����������벻ͬ&&flag3=0*/
				
				/*
                setfillstyle(1, LIGHTBLUE);
				bar(560, 280, 600, 325);
				drawRedFork(560, 290);
				backgroundChange(mx, my, 560, 280, 600, 325);
				setfillstyle(1, LIGHTBLUE);
				bar(210, 330, 550, 355);
				puthz(210, 330, "两次密码输入不同�?, 16, 16, RED);
				backgroundChange(mx, my, 210, 330, 550, 355);
*/
                bar(800,380,900,450,1503);
                red_cross(800,400);
				bar(210,500,900,530,1503);
				fdhz(210,500, 1, 1, "������������벻ͬ", 0);
				flag3 = 0;
			}
			else
			{
				/*��һ����ɫ�Ĺ�&flag3=1*/
/*
                setfillstyle(1,LIGHTBLUE);
				bar(210, 330, 550, 355);
				bar(560, 280, 600, 325);
				drawGreenHook(560, 290);
				backgroundChange(mx, my, 560, 280, 600, 325);
				backgroundChange(mx, my, 210, 330, 550, 355);
*/
                bar(210,700,900,750,1503);
                bar(800,380,900,450,1503);
                green_tick(800,400);

				flag3 = 1;
			}
			break;

		/*case 4:�ж��Ƿ�ע��ɹ�*/
		case 4:if (flag1 == 1 && flag2 == 1 && flag3 == 1)
		{
			AddNewUser(head, account, code);
			/*
			if(Choose("ע��ɹ���\n�Ƿ��Զ���¼��",&mx,&my,GREEN)==1)return 2;
			else return 0;*/
			return 1;
		}
			   break;

	    /*case 5:���ص�¼����*/
		case 5: return 5;
		
		}
		
	}
}

int sign_in_check(USERS *head,char *account,char *code)
{
	char *rightcode= NULL;
	rightcode = SearchAccounts(head, account);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //��¼�ɹ�
	else
	{
		fdhz(410, 300,1, 1, "�û����������������", 0);
        getch();
		return 5;
	}
}
