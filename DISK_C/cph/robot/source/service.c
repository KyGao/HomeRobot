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
#define PI 3.1415926

/*******************************
���ֹ��ܺ���
void open_window(ROBOT_CASE *robot_position,SAVE *save,int win_case,int *x,int *y);
*******************************/
void open_window(ROBOT_CASE *robot_position,SAVE *save,int win_case,int *x,int *y)//�򿪴���
{
	/*�ƶ���һ¥*/
	switch((*robot_position).position)
	{
		case 0:
		{
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
			break;
		}
		case 2:
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);
			break;
		}
		case 1:
		{
			break;
		}
	}

	/*�ƶ�������*/
	aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,7,3,x,y);
	/*�жϴ����Ŀ��������ִ����Ӧ�Ŀ��ش�����*/
	if(!win_case)
	{
		wave(robot_position);
		window_close(8,2);	
	}
	else
	{
		wave(robot_position);
		window_open(8,2);
		aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,(*robot_position).x,(*robot_position).y+1,x,y);
		
		/*���������������*/
		if(CheckHouse(8) == 1)
		{
			if(CheckHouse(9) == 0 && CheckHouse(10)==0)//������δ���������
			{
				CreateTrash(robot_position,save,0);
			}
			if(CheckHouse(11) == 0 && CheckHouse(12)==0)//������δ���������
			{
				CreateTrash(robot_position,save,1);
			}
			ChangeHouse(24,1);
		}
	}
}



/*����Ѳ�ߺ���,ע�⣬x0,y0��1��ͷ����condition��0��ͷ*/
void go_to(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y)
{
	int judge=-1;
	int button;//�������Ƿ���;
	int x0,y0;//ת��Ϊ�ο�������(��1��ʼ)
	int xpixel,ypixel;//����ʵ������
	//STACK *S;
	/*����ռ�*/
	//S = (STACK*)malloc(sizeof(STACK));
	/*�������Ƿ�ɹ�
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}*/
	/*��ʼ��ջ*/
	//InitStack(S);
	while(1)
	{
		newxy(x,y,&button);
		/*ת������*/
		x0 = (*x)/40+1;
	    y0 = ((*y)-4)/40+1;
		
		/*��HOME��*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button) || (judge==0))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			break;
		}
		/*
		if(!FindWay((*robot_position).position,(*robot_position).x,(*robot_position).y,x0,y0,S) && x0<=19 &&y0<=19 &&button)
		{
			//Ѱ·����
		    trap(300,500);
			getch();
			ClearStack(S);
			mousehide(*x,*y);
			bar(0,0,760,768,0);
			switch((*robot_position).position)
			{
				case 0:
				{
					_outside();
					break;
				}
				case 1:
				{
					_ground();
					break;
				}
				case 2:
				{
					floor_R();
					break;
				}
			}
			reset_mouse(x,y);
			forebodyhead(*robot_position);
			continue;
		}*/
		/*���÷�������ƶ����ƶ���ȥ*/
		if(((x0-1!=(*robot_position).x) || (y0-1!=(*robot_position).y)) && button && x0<=19 && y0<=19)
		{	
			if((CheckMove(x0,y0,(*robot_position).position)==1))
			{
				aimmove(robot_position,(*robot_position).position,(*robot_position).x,(*robot_position).y,x0-1,y0-1,x,y);
			}
		}
		/*����������Ѳ�ߺ���*/
		if(*x >= 804 && *x <= 984 && *y >= SCREENCENTER_y-SCREENHEIGHT/7+2-SCREENHEIGHT/7+20 && *y <= SCREENCENTER_y-SCREENHEIGHT/7+2+SCREENHEIGHT/7-20 && button)
		{
			while(1)
			{
				judge = randmove(robot_position,esc1,x,y);
				if(judge == -2)
				{
					judge=0;
					break;
				}
			}
			
		}
		
	}
	/*
	DestroyStack(S);
	free(S);
*/
}

void clean_weed(ROBOT_CASE *robot_position,int *x,int *y)
{
	int i;
	unsigned int *CutSave;
	
	
	STACK *S;
	/*Ϊջ�����ڴ�*/
	S = (STACK *)malloc(sizeof(STACK));
	/*�ж��ڴ��Ƿ����ɹ�*/
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	/*��ʼ��ջ*/
	InitStack(S);
	/*Ϊ���ݻ���ͼ�����ռ�*/
	CutSave = (unsigned int*)malloc(48*40*sizeof(unsigned int));
	/*�ж��ڴ��Ƿ����ɹ�*/
	if(CutSave==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	/*�ƶ�������*/
	switch((*robot_position).position)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,1,10,x,y);
			break;
		}
		case 2:
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,1,10,x,y);
			break;
		}
		
	}
	
	
	for(i=0;i<3;i++)
	{//����Ҫ��һЩ�жϣ��ұ߲��������
        if((CheckMove(CheckHouse(18+2*i)+2,CheckHouse(19+2*i)-1,0) == 1)  && (FindWay(0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)+2,CheckHouse(19+2*i)-1,S)))
		{
			
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)+2,CheckHouse(19+2*i)-1,x,y);//�ƶ����Ӳ��ҷ�����
	        meadow(CheckHouse(18+2*i),CheckHouse(19+2*i));//��ȥ�Ӳ�
			
			/*�����������*/
			tree(5,5);
	        tree(5,12);
			
			get_image((*robot_position).xpixel-80,(*robot_position).ypixel-40,(*robot_position).xpixel-32,(*robot_position).ypixel,CutSave);
		    Cut_Machine1((*robot_position).xpixel-80,(*robot_position).ypixel-40);//���Ƴ��ݻ�
		    
			CutWeed(robot_position,CutSave,1);//����
		    put_image((*robot_position).xpixel-80,(*robot_position).ypixel-40,(*robot_position).xpixel-32,(*robot_position).ypixel,CutSave);
		    
		}
		else
		{
			if((CheckMove(CheckHouse(18+2*i)-4,CheckHouse(19+2*i)-1,0) == 1) && (FindWay(0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)-4,CheckHouse(19+2*i)-1,S)))
			{
				aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)-4,CheckHouse(19+2*i)-1,x,y);//�ƶ����Ӳ�������
	            meadow(CheckHouse(18+2*i),CheckHouse(19+2*i));
				
				/*�����������*/
			    tree(5,5);
	            tree(5,12);
				
			    get_image((*robot_position).xpixel+72,(*robot_position).ypixel-40,(*robot_position).xpixel+120,(*robot_position).ypixel,CutSave);
			    Cut_Machine2((*robot_position).xpixel+40,(*robot_position).ypixel-40);
		        CutWeed(robot_position,CutSave,2);
			    meadow((*robot_position).x+2,(*robot_position).y);
			    meadow((*robot_position).x+3,(*robot_position).y);//��ȥ�Ӳ�
			
			}
			else//����һ���ֲ����ƶ���ȥ�����ʱֱ��Ĩȥ�Ӳ���ȷ��ϵͳ��ȫ
			{
				getch();
				meadow(CheckHouse(18+2*i),CheckHouse(19+2*i));
			}
		}
	    ChangeMove(CheckHouse(18+2*i),CheckHouse(19+2*i),0,1);//ʹԭ���Ӳ�����λ�ÿ��ƶ�
	}
	
	forebodyhead(*robot_position);	
	/*�����ѷ���ռ䲢��ָ����Ϊ��*/
	free(CutSave);
	CutSave = NULL;
	DestroyStack(S);
	free(S);
	S = NULL;
	
	/*�ص�һ¥*/
	aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
}


void movechair(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y)
{
    int judge=-1,i,j,originx,originy;
	int button,count=0;//�������Ƿ���,�������;
	int x0,y0;//ת��Ϊ�ο�������(��1��ʼ)
	int xpixel,ypixel;//����ʵ������
	int error=0;//Ѱ·�Ƿ�ɹ�
	
	/*Ϊջ�����ڴ沢�жϷ����Ƿ�ɹ�*/
	STACK *S;
	S = (STACK *)malloc(sizeof(STACK));
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/*��ʼ��ջ*/
	InitStack(S);
	
	/*�ƶ���һ¥*/
	switch((*robot_position).position)
	{
		case 0:
		{
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
			break;
		}
		case 2:
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);
			break;
		}
		case 1:
		{
			break;
		}
	}
	
	while(1)
	{
		newxy(x,y,&button);
		
		x0 = (*x)/40+1;
	    y0 = ((*y)-4)/40+1;
		xpixel = (x0-1)*40;
		ypixel = (y0-1)*40;
		
		/*��ѡ*/
		if(CheckCarry(x0,y0,1) == 1 && ((x0-1!=(*robot_position).x) || (y0-1!=(*robot_position).y)) && button && x0<=19 && y0<=19 &&count==0)
		{
            bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+100,SCREENCENTER_y-120,36410);
			count=1;
			originx = x0;
			originy = y0;
			fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"��ѡ��",65535);
			continue;
		}
		
		/*�õ�Ŀ�ĵغ�ִ����Ӧ����*/
		if(CheckMove(x0,y0,(*robot_position).position) == 1 && ((x0-1!=(*robot_position).x) || (y0-1!=(*robot_position).y)) && button && x0<=19 && y0<=19 &&count==1)
		{
			count=0;
			bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+100,SCREENCENTER_y-120,36410);
			
			/*�����˷�Χ��������*/
			if(originx<=9&&originx>=2&&originy<=12&&originy>=8 && (x0>9 || y0>12 || y0<8))
			{
				fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,1,1,"���Ӳ��ܰ������Ŷ",65535);
				continue;
			}
			if(originx>=11 &&originx<=16 && originy>=2 && originy<=5 && (x0<11 || x0>16 || y0<2 || y0>5))
			{
				fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,1,1,"���Ӳ��ܰ������Ŷ",65535);
				continue;
			}
			
			
			/*�����ӵ�ס��ȥ·*/
			if(CheckMove(originx+1,originy,(*robot_position).position) == 1)
			{
				if(!FindWay(1,(*robot_position).x,(*robot_position).y,originx,originy-1,S))
			    {
				    trap(300,500);
				    getch();
					count=0;
					ClearStack(S);
					bar(0,0,760,768,0);
					_ground();
					forebodyhead(*robot_position);
				    continue;
			    }
				aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,originx,originy-1,x,y);
			}
			/*����*/
			else
			{
				if(!FindWay(1,(*robot_position).x,(*robot_position).y,originx-2,originy-1,S))
			    {
				    trap(300,500);
				    getch();
					count=0;
					ClearStack(S);
					bar(0,0,760,768,0);
					_ground();
					forebodyhead(*robot_position);
				    continue;
			    }
				aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,originx-2,originy-1,x,y);
			}
			
			/*���ǵ�ԭ��������*/
			if(originx<=9&&originx>=2&&originy<=12&&originy>=8)//�����
			{
				bar((originx-1)*40+5,(originy-1)*40+8,(originx-1)*40+36,(originy-1)*40+35,52816);
			}
			else
			{
				green(originx,originy);
			}
			
			/*�ı���ƶ��Ͱ��˷�Χ*/
			ChangeMove(originx,originy,(*robot_position).position,1);
			ChangeCarry(originx,originy,(*robot_position).position,0);
			
			put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
			
			/*�ƶ���Ŀ�ĵ�����*/
			if(CheckMove(x0+1,y0,(*robot_position).position == 1))
			{
				error = take_chair(robot_position,(*robot_position).position,(*robot_position).x,(*robot_position).y,x0,y0-1,x,y);
			}
			else
			{
				error = take_chair(robot_position,1,(*robot_position).x,(*robot_position).y,x0-2,y0-1,x,y);
			}
			if(error)
			{
				continue;
		    }
			
			
			ChangeMove(x0,y0,(*robot_position).position,0);
			ChangeCarry(x0,y0,(*robot_position).position,1);
			/*��������*/
			seat((x0-1)*40,(y0-1)*40);
			get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
			forebodyhead(*robot_position);
			
			/*�ص�ĳ��λ��
			ClearStack(S);//���ջ���ٴ�Ѱ·
			if(!FindWay(1,(*robot_position).x,(*robot_position).y,5,3,S))
			{
				trap(300,500);
				getch();
				bar(0,0,760,768,0);
				_ground();
				forebodyhead(*robot_position);
				ClearStack(S);
				continue;
			}
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,5,3,x,y);*/
		}
		
		/*�����home��*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button) || (judge==0))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			break;
		}
	}
	
	/*�������������*/
	if(CheckHouse(13) == 0  && CheckHouse(14)==0)
	{
		CreateTrash(robot_position,save,2);
	    ChangeHouse(24,1);
	}
	/*����ջ*/
	DestroyStack(S);
	free(S);
	S = NULL;
}


/*��ɨ����*/
void clean(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y)
{
	int trashnum=0,trashbinnum,i=0,j=0,judge=0;

	int trashx[3],trashy[3];
	
	if(CheckHouse(24) == 1)//���������������
	{
		for(i=0;i<3;i++)
		{
			/*���ļ��л�ȡ����λ��*/
			trashx[i] = CheckHouse(9+i*2);
			trashy[i] = CheckHouse(10+i*2);
			
			if(trashx[i] != 0 && trashy[i] != 0)
			{
				if(CheckMove(trashx[i]-1,trashy[i],1) == 1)//��������
	            {
					/*�ƶ���������*/
		            aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i]-2,trashy[i]-1,x,y);
	            }
	            else
	            {
					if(CheckMove(trashx[i],trashy[i]-1,1) == 1)//���Ϸ�����
		            {
			             aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i]-1,trashy[i]-2,x,y);
		            } 
		            else
		            {
						if(CheckMove(trashx[i]+1,trashy[i],1) == 1)//���ҷ�����
			            {
				            aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i]+1,trashy[i],x,y);
			            }
			            else
			            {
							if(CheckMove(trashx[i],trashy[i]+1,1) == 1)//���·�����
				            {
					            aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i],trashy[i]+1,x,y);
				            }
				            else
				            {
					            //put_image((house->trashx-1)*40,(house->trashy-1)*40,(house->trashx-1)*40+40,(house->trashy-1)*40+40,house->trashsave);
				            }
			            }
		            }
	            }
				/*ʰȡ��������*/
				take_trash(robot_position);
				delay0(300);
				
				/*�ı������ͻ����Ŀ��ƶ����*/
	            switch(i)
			    {
				    case 0:
				    {
						if(CheckHouse(9+i*2) != 0 &&CheckHouse(10+i*2)!=0)
						{
							put_image((trashx[i]-1)*40,(trashy[i]-1)*40,(trashx[i]-1)*40+40,(trashy[i]-1)*40+40,save->trashsave1);
						    ChangeMove(trashx[i],trashy[i],1,1);
				            ChangeHouse(9+i*2,0);//change trashx,y
				            ChangeHouse(10+i*2,0);
							trashnum++;
						}
					    break;
				    }
				    case 1:
				    {
					    if(CheckHouse(9+i*2) != 0 &&CheckHouse(10+i*2)!=0)
						{
							put_image((trashx[i]-1)*40,(trashy[i]-1)*40,(trashx[i]-1)*40+40,(trashy[i]-1)*40+40,save->trashsave2);
						    ChangeMove(trashx[i],trashy[i],1,1);
				            ChangeHouse(9+i*2,0);//change trashx,y
				            ChangeHouse(10+i*2,0);
							trashnum++;
						}						
					    break;
				    }
				    case 2:
				    {
					    if(CheckHouse(9+i*2) != 0 &&CheckHouse(10+i*2)!=0)
						{
							put_image((trashx[i]-1)*40,(trashy[i]-1)*40,(trashx[i]-1)*40+40,(trashy[i]-1)*40+40,save->trashsave3);
							ChangeMove(trashx[i],trashy[i],1,1);
				            ChangeHouse(9+i*2,0);//change trashx,y
				            ChangeHouse(10+i*2,0);
							trashnum++;
						}
					    break;
				    }
			    }
				
				
		    }
		}
		   //ѡ�����������Ͱ
	    trashbinnum = find_trashbin(robot_position);
	    switch(trashbinnum)
	    {
		    case 1:
		    {
			    aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,11,4,x,y);
				take_trash(robot_position);
				delay0(300);
				ChangeHouse(15,trashnum);//trashbin[0]++;
			    break;
		    }
		    case 2:
		    {
			    aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,2,8,x,y);
				take_trash(robot_position);
				delay0(300);
				ChangeHouse(16,trashnum);
			    break;
		    }
		    case 3:
		    {
			    aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,14,17,x,y);
				take_trash(robot_position);
				delay0(300);
				ChangeHouse(17,trashnum);
			    break;
		    }
	    }
		
	}
	ChangeHouse(24,0);//�������е��������ޱ�Ϊ��
	
	//���˾͵�����
	
	for(i=0;i<3;i++)
	{
		if(CheckHouse(15+i) >= 5)
		{
			take_trash(robot_position);
			ChangeHouse(15+i,(-1)*CheckHouse(15+i));//trashbin[i] = 0;
	        ShowTrashNum();
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,1,10,x,y);
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,1,12,x,y);
			take_trash(robot_position);
	        delay0(1000);
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
		}
	}
	
}

/*Ѱ�����������Ͱ*/
int find_trashbin(ROBOT_CASE *robot_position)
{
	
	if((*robot_position).y>6)
	{
		if((*robot_position).y>14)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 1;
	}
}

/*����������*/
void throw_trash(ROBOT_CASE *robot_position,int *x,int *y)
{
	/*�ƶ���һ¥*/
	switch((*robot_position).position)
	{
		case 0:
		{
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
			break;
		}
		case 2:
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);
			break;
		}
		case 1:
		
		{
			break;
		}
	}
	
	/*�����ƶ�����������Ͱ*/
	aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,11,4,x,y);
	ChangeHouse(15,(-1)*CheckHouse(15));//trashbin[0] = 0;
	ShowTrashNum();
	delay0(1000);
	aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,14,17,x,y);
	ChangeHouse(17,(-1)*CheckHouse(17));//trashbin[2] = 0
	ShowTrashNum();
	delay0(1000);
	trash3to2(robot_position,x,y);
	ChangeHouse(16,(-1)*CheckHouse(16));
	ShowTrashNum();
	delay0(1000);
	
	trash2to_outside(robot_position,x,y);//�ƶ�������
	aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,1,12,x,y);
	delay0(2000);
	aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
}

/*������Ͱ���ƶ�������Ͱ��*/
void trash3to2(ROBOT_CASE *robot_position,int *x,int *y)
{
	int t3to2[23] = {3,3,3,2,3,3,2,2,2,3,3,2,2,2,2,4,2,2,2,2,3,3,3};
	int i;
	for(i=0;i<23;i++)
	{
		(*robot_position).direction = t3to2[i];
		move0(robot_position,x,y);
	}
}

/*������Ͱ���ƶ�������*/
void trash2to_outside(ROBOT_CASE *robot_position,int *x,int *y)
{
	int t2to_out[2] = {4,2};
	int i;
	for(i=0;i<2;i++)
	{
		(*robot_position).direction = t2to_out[i];
		move0(robot_position,x,y);
	}
	(*robot_position).position=0;
	mousehide(*x,*y);
	bar(0, 0, 764, 768, 65535);
	_outside();
	reset_mouse(x, y);
	(*robot_position).x = 10;
	(*robot_position).y = 10;
	(*robot_position).xpixel = ((*robot_position).x) * 40 + 20;
	(*robot_position).ypixel = ((*robot_position).y) * 40 + 4 + 50;
	(*robot_position).leg = 0;
	(*robot_position).leg_left = 0;
	(*robot_position).leg_right = 0;
	get_image((*robot_position).xpixel - 32, (*robot_position).ypixel - 80, (*robot_position).xpixel + 32, (*robot_position).ypixel - 3, (*robot_position).cat);
	forebodyhead(*robot_position);
}

void wave(ROBOT_CASE *robot_position)//����ʱ���ֶ���
{
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	backbodyhead_open(*robot_position);
	/*������ֱ� */
	theta_bar((*robot_position).xpixel,(*robot_position).ypixel-36,14,20,-45,0);
	theta_bar((*robot_position).xpixel,(*robot_position).ypixel-36,14,20,-45,255);
	FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-50,7,0);
    FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-50,6,65535);
	delay0(2000);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	/*�ı�ڶ��Ƕ�*/
	backbodyhead_open(*robot_position);
	theta_bar((*robot_position).xpixel-3,(*robot_position).ypixel-36,14,20,-15,0);
	theta_bar((*robot_position).xpixel-3,(*robot_position).ypixel-36,14,20,-15,255);
	FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-40,7,0);
    FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-40,6,65535);
	delay0(2000);
}


int take_chair(ROBOT_CASE *robot_position,int f,int x0,int y0,int xt,int yt,int *x,int *y)
{
	unsigned int *withchair=NULL;//�洢����ͼ����Ϣ
	
	UNIT *t = NULL;//(��ΪѰ·���м����)
	/*STACK ��ʼ��*/
	STACK S;
	/*����һ��ջ��·������洢*/
	STACK R;
	
	/*��ʼ��ջ*/
	InitStack(&S);
	
	InitStack(&R);
	
	/*Ϊ���ӷ���ռ�*/
	withchair = (unsigned int *)malloc(96*77*sizeof(unsigned int));
	if(withchair==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/*Ϊ�м��������ռ�*/
	t = (UNIT *)malloc(sizeof(UNIT));
	if(t==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/*���»�����λ����Ϣ*/
	(*robot_position).x = x0;
	(*robot_position).y = y0;
	/*�����յ���ͬ*/
	if(x0==xt && y0==yt)
	{
		return 0;
	}
	
	/*Ѱ·*/
	if(!FindWay(f,x0,y0,xt,yt,&S))//���������(0,0)��ʼ
	{
		//Ѱ·����
		trap(300,500);
		getch();
		bar(0,0,760,768,0);
		_ground();
		DestroyStack(&S);
	    DestroyStack(&R);
	    free(t);
	    t = NULL;
	    free(withchair);
	    withchair = NULL;
        return 1;
	}
	else
	{
		while(!StackEmpty(&S))
		{
			Pop(&S,t);
			Push(&R,*t);
		}
		get_image((*robot_position).xpixel-48,(*robot_position).ypixel-80,(*robot_position).xpixel+48,(*robot_position).ypixel-3,withchair);
		while(!StackEmpty(&R))
		{
				Pop(&R,t);
			    (*robot_position).direction = t->di;
			    move2(robot_position,x,y,withchair);
		}
		/*����ջ*/
		DestroyStack(&S);
	    DestroyStack(&R);
	    free(t);
	    t = NULL;
	    free(withchair);
	    withchair = NULL;
	    if((*robot_position).x != xt || (*robot_position).y!= yt)
	    {
		    take_chair(robot_position,f,(*robot_position).x,(*robot_position).y,xt,yt,x,y);
	    }
	}
	return 0;
	
}

/*��ʾ����������Ͱ��������������*/
void ShowTrashNum()
{
	bar(SCREENCENTER_x,SCREENCENTER_y+40,SCREENCENTER_x+24,SCREENCENTER_y+90,0);
	bar(SCREENCENTER_x,SCREENCENTER_y+100,SCREENCENTER_x+24,SCREENCENTER_y+150,0);
	bar(SCREENCENTER_x,SCREENCENTER_y+160,SCREENCENTER_x+24,SCREENCENTER_y+210,0);
	show_num(SCREENCENTER_x+2,SCREENCENTER_y+45,CheckHouse(15));
	show_num(SCREENCENTER_x+2,SCREENCENTER_y+105,CheckHouse(16));
	show_num(SCREENCENTER_x+2,SCREENCENTER_y+165,CheckHouse(17));
}



void take_trash(ROBOT_CASE *robot_position)//���������Ķ���
{
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	
	
	/*������ֱ� */
	theta_bar((*robot_position).xpixel+5-5,(*robot_position).ypixel-36-10,14,20,45,0);
	theta_bar((*robot_position).xpixel+5-5,(*robot_position).ypixel-36-10,14,20,45,255);
	FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-28,7,0);
    FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-28,6,65535);
	forebodyhead_open(*robot_position);
	delay0(2000);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	/*�ı�ڶ��Ƕ�*/
	
	theta_bar((*robot_position).xpixel-3-10,(*robot_position).ypixel-36-8,25,20,15,0);
	theta_bar((*robot_position).xpixel-3-10,(*robot_position).ypixel-36-8,25,20,15,255);
	FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-35,7,0);
    FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-35,6,65535);
	forebodyhead_open(*robot_position);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	forebodyhead(*robot_position);
	delay0(2000);
}