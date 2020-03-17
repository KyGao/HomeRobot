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
各种功能函数
void open_window(ROBOT_CASE *robot_position,SAVE *save,int win_case,int *x,int *y);
*******************************/
void open_window(ROBOT_CASE *robot_position,SAVE *save,int win_case,int *x,int *y)//打开窗户
{
	/*移动到一楼*/
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

	/*移动到窗边*/
	aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,7,3,x,y);
	/*判断窗户的开关情况并执行相应的开关窗操作*/
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
		
		/*开窗后出现了垃圾*/
		if(CheckHouse(8) == 1)
		{
			if(CheckHouse(9) == 0 && CheckHouse(10)==0)//该垃圾未产生则产生
			{
				CreateTrash(robot_position,save,0);
			}
			if(CheckHouse(11) == 0 && CheckHouse(12)==0)//该垃圾未产生则产生
			{
				CreateTrash(robot_position,save,1);
			}
			ChangeHouse(24,1);
		}
	}
}



/*定向巡逻函数,注意，x0,y0以1开头，而condition以0开头*/
void go_to(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y)
{
	int judge=-1;
	int button;//检测鼠标是否点击;
	int x0,y0;//转换为参考点坐标(以1开始)
	int xpixel,ypixel;//方块实际坐标
	//STACK *S;
	/*分配空间*/
	//S = (STACK*)malloc(sizeof(STACK));
	/*检查分配是否成功
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}*/
	/*初始化栈*/
	//InitStack(S);
	while(1)
	{
		newxy(x,y,&button);
		/*转换坐标*/
		x0 = (*x)/40+1;
	    y0 = ((*y)-4)/40+1;
		
		/*按HOME键*/
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
			//寻路出错
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
		/*若该方向可以移动则移动过去*/
		if(((x0-1!=(*robot_position).x) || (y0-1!=(*robot_position).y)) && button && x0<=19 && y0<=19)
		{	
			if((CheckMove(x0,y0,(*robot_position).position)==1))
			{
				aimmove(robot_position,(*robot_position).position,(*robot_position).x,(*robot_position).y,x0-1,y0-1,x,y);
			}
		}
		/*若点击了随机巡逻函数*/
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
	/*为栈分配内存*/
	S = (STACK *)malloc(sizeof(STACK));
	/*判断内存是否分配成功*/
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	/*初始化栈*/
	InitStack(S);
	/*为除草机的图像分配空间*/
	CutSave = (unsigned int*)malloc(48*40*sizeof(unsigned int));
	/*判断内存是否分配成功*/
	if(CutSave==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	/*移动到外面*/
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
	{//这里要加一些判断，右边不行走左边
        if((CheckMove(CheckHouse(18+2*i)+2,CheckHouse(19+2*i)-1,0) == 1)  && (FindWay(0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)+2,CheckHouse(19+2*i)-1,S)))
		{
			
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)+2,CheckHouse(19+2*i)-1,x,y);//移动到杂草右方三个
	        meadow(CheckHouse(18+2*i),CheckHouse(19+2*i));//除去杂草
			
			/*避免把树擦除*/
			tree(5,5);
	        tree(5,12);
			
			get_image((*robot_position).xpixel-80,(*robot_position).ypixel-40,(*robot_position).xpixel-32,(*robot_position).ypixel,CutSave);
		    Cut_Machine1((*robot_position).xpixel-80,(*robot_position).ypixel-40);//绘制除草机
		    
			CutWeed(robot_position,CutSave,1);//除草
		    put_image((*robot_position).xpixel-80,(*robot_position).ypixel-40,(*robot_position).xpixel-32,(*robot_position).ypixel,CutSave);
		    
		}
		else
		{
			if((CheckMove(CheckHouse(18+2*i)-4,CheckHouse(19+2*i)-1,0) == 1) && (FindWay(0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)-4,CheckHouse(19+2*i)-1,S)))
			{
				aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,CheckHouse(18+2*i)-4,CheckHouse(19+2*i)-1,x,y);//移动到杂草左方三个
	            meadow(CheckHouse(18+2*i),CheckHouse(19+2*i));
				
				/*避免把树擦除*/
			    tree(5,5);
	            tree(5,12);
				
			    get_image((*robot_position).xpixel+72,(*robot_position).ypixel-40,(*robot_position).xpixel+120,(*robot_position).ypixel,CutSave);
			    Cut_Machine2((*robot_position).xpixel+40,(*robot_position).ypixel-40);
		        CutWeed(robot_position,CutSave,2);
			    meadow((*robot_position).x+2,(*robot_position).y);
			    meadow((*robot_position).x+3,(*robot_position).y);//除去杂草
			
			}
			else//当万一出现不能移动过去的情况时直接抹去杂草以确保系统安全
			{
				getch();
				meadow(CheckHouse(18+2*i),CheckHouse(19+2*i));
			}
		}
	    ChangeMove(CheckHouse(18+2*i),CheckHouse(19+2*i),0,1);//使原来杂草所在位置可移动
	}
	
	forebodyhead(*robot_position);	
	/*回收已分配空间并将指针置为空*/
	free(CutSave);
	CutSave = NULL;
	DestroyStack(S);
	free(S);
	S = NULL;
	
	/*回到一楼*/
	aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
}


void movechair(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y)
{
    int judge=-1,i,j,originx,originy;
	int button,count=0;//检测鼠标是否点击,点击次数;
	int x0,y0;//转换为参考点坐标(以1开始)
	int xpixel,ypixel;//方块实际坐标
	int error=0;//寻路是否成功
	
	/*为栈分配内存并判断分配是否成功*/
	STACK *S;
	S = (STACK *)malloc(sizeof(STACK));
	if(S==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/*初始化栈*/
	InitStack(S);
	
	/*移动到一楼*/
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
		
		/*点选*/
		if(CheckCarry(x0,y0,1) == 1 && ((x0-1!=(*robot_position).x) || (y0-1!=(*robot_position).y)) && button && x0<=19 && y0<=19 &&count==0)
		{
            bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+100,SCREENCENTER_y-120,36410);
			count=1;
			originx = x0;
			originy = y0;
			fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"已选中",65535);
			continue;
		}
		
		/*得到目的地后执行相应操作*/
		if(CheckMove(x0,y0,(*robot_position).position) == 1 && ((x0-1!=(*robot_position).x) || (y0-1!=(*robot_position).y)) && button && x0<=19 && y0<=19 &&count==1)
		{
			count=0;
			bar(SCREENCENTER_x-100,SCREENCENTER_y-170,SCREENCENTER_x+100,SCREENCENTER_y-120,36410);
			
			/*若搬运范围超过房间*/
			if(originx<=9&&originx>=2&&originy<=12&&originy>=8 && (x0>9 || y0>12 || y0<8))
			{
				fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,1,1,"椅子不能搬出房间哦",65535);
				continue;
			}
			if(originx>=11 &&originx<=16 && originy>=2 && originy<=5 && (x0<11 || x0>16 || y0<2 || y0>5))
			{
				fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,1,1,"椅子不能搬出房间哦",65535);
				continue;
			}
			
			
			/*若椅子挡住了去路*/
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
			/*搬运*/
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
			
			/*覆盖掉原来的椅子*/
			if(originx<=9&&originx>=2&&originy<=12&&originy>=8)//起居室
			{
				bar((originx-1)*40+5,(originy-1)*40+8,(originx-1)*40+36,(originy-1)*40+35,52816);
			}
			else
			{
				green(originx,originy);
			}
			
			/*改变可移动和搬运范围*/
			ChangeMove(originx,originy,(*robot_position).position,1);
			ChangeCarry(originx,originy,(*robot_position).position,0);
			
			put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
			
			/*移动到目的地左右*/
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
			/*放下椅子*/
			seat((x0-1)*40,(y0-1)*40);
			get_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
			forebodyhead(*robot_position);
			
			/*回到某个位置
			ClearStack(S);//清空栈，再次寻路
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
		
		/*点击了home键*/
		if((*x >= 871 && *x <= 919 && *y >= 706 && *y <= 754 && button) || (judge==0))
		{
			mousehide(*x,*y);
			ph_main();
			reset_mouse(x,y);
			break;
		}
	}
	
	/*搬运完产生椅子*/
	if(CheckHouse(13) == 0  && CheckHouse(14)==0)
	{
		CreateTrash(robot_position,save,2);
	    ChangeHouse(24,1);
	}
	/*销毁栈*/
	DestroyStack(S);
	free(S);
	S = NULL;
}


/*打扫函数*/
void clean(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y)
{
	int trashnum=0,trashbinnum,i=0,j=0,judge=0;

	int trashx[3],trashy[3];
	
	if(CheckHouse(24) == 1)//如果环境中有垃圾
	{
		for(i=0;i<3;i++)
		{
			/*从文件中获取垃圾位置*/
			trashx[i] = CheckHouse(9+i*2);
			trashy[i] = CheckHouse(10+i*2);
			
			if(trashx[i] != 0 && trashy[i] != 0)
			{
				if(CheckMove(trashx[i]-1,trashy[i],1) == 1)//若左方能走
	            {
					/*移动到垃圾左方*/
		            aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i]-2,trashy[i]-1,x,y);
	            }
	            else
	            {
					if(CheckMove(trashx[i],trashy[i]-1,1) == 1)//若上方能走
		            {
			             aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i]-1,trashy[i]-2,x,y);
		            } 
		            else
		            {
						if(CheckMove(trashx[i]+1,trashy[i],1) == 1)//若右方能走
			            {
				            aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,trashx[i]+1,trashy[i],x,y);
			            }
			            else
			            {
							if(CheckMove(trashx[i],trashy[i]+1,1) == 1)//若下方能走
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
				/*拾取垃圾动画*/
				take_trash(robot_position);
				delay0(300);
				
				/*改变垃圾和环境的可移动情况*/
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
		   //选择最近的垃圾桶
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
	ChangeHouse(24,0);//将环境中的垃圾有无变为无
	
	//满了就倒垃圾
	
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

/*寻找最近的垃圾桶*/
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

/*扔垃圾动画*/
void throw_trash(ROBOT_CASE *robot_position,int *x,int *y)
{
	/*移动到一楼*/
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
	
	/*依次移动到三个垃圾桶*/
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
	
	trash2to_outside(robot_position,x,y);//移动到外面
	aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,1,12,x,y);
	delay0(2000);
	aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
}

/*从垃圾桶三移动到垃圾桶二*/
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

/*从垃圾桶二移动到外面*/
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

void wave(ROBOT_CASE *robot_position)//开窗时挥手动画
{
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	backbodyhead_open(*robot_position);
	/*上扬的手臂 */
	theta_bar((*robot_position).xpixel,(*robot_position).ypixel-36,14,20,-45,0);
	theta_bar((*robot_position).xpixel,(*robot_position).ypixel-36,14,20,-45,255);
	FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-50,7,0);
    FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-50,6,65535);
	delay0(2000);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	/*改变摆动角度*/
	backbodyhead_open(*robot_position);
	theta_bar((*robot_position).xpixel-3,(*robot_position).ypixel-36,14,20,-15,0);
	theta_bar((*robot_position).xpixel-3,(*robot_position).ypixel-36,14,20,-15,255);
	FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-40,7,0);
    FillCircle((*robot_position).xpixel+20,(*robot_position).ypixel-40,6,65535);
	delay0(2000);
}


int take_chair(ROBOT_CASE *robot_position,int f,int x0,int y0,int xt,int yt,int *x,int *y)
{
	unsigned int *withchair=NULL;//存储椅子图像信息
	
	UNIT *t = NULL;//(作为寻路的中间变量)
	/*STACK 初始化*/
	STACK S;
	/*用另一个栈把路径正向存储*/
	STACK R;
	
	/*初始化栈*/
	InitStack(&S);
	
	InitStack(&R);
	
	/*为椅子分配空间*/
	withchair = (unsigned int *)malloc(96*77*sizeof(unsigned int));
	if(withchair==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/*为中间变量分配空间*/
	t = (UNIT *)malloc(sizeof(UNIT));
	if(t==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	/*更新机器人位置信息*/
	(*robot_position).x = x0;
	(*robot_position).y = y0;
	/*若起终点相同*/
	if(x0==xt && y0==yt)
	{
		return 0;
	}
	
	/*寻路*/
	if(!FindWay(f,x0,y0,xt,yt,&S))//坐标计算以(0,0)开始
	{
		//寻路出错
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
		/*销毁栈*/
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

/*显示处各个垃圾桶的垃圾数量动画*/
void ShowTrashNum()
{
	bar(SCREENCENTER_x,SCREENCENTER_y+40,SCREENCENTER_x+24,SCREENCENTER_y+90,0);
	bar(SCREENCENTER_x,SCREENCENTER_y+100,SCREENCENTER_x+24,SCREENCENTER_y+150,0);
	bar(SCREENCENTER_x,SCREENCENTER_y+160,SCREENCENTER_x+24,SCREENCENTER_y+210,0);
	show_num(SCREENCENTER_x+2,SCREENCENTER_y+45,CheckHouse(15));
	show_num(SCREENCENTER_x+2,SCREENCENTER_y+105,CheckHouse(16));
	show_num(SCREENCENTER_x+2,SCREENCENTER_y+165,CheckHouse(17));
}



void take_trash(ROBOT_CASE *robot_position)//捡起垃圾的动画
{
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	
	
	/*上扬的手臂 */
	theta_bar((*robot_position).xpixel+5-5,(*robot_position).ypixel-36-10,14,20,45,0);
	theta_bar((*robot_position).xpixel+5-5,(*robot_position).ypixel-36-10,14,20,45,255);
	FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-28,7,0);
    FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-28,6,65535);
	forebodyhead_open(*robot_position);
	delay0(2000);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	/*改变摆动角度*/
	
	theta_bar((*robot_position).xpixel-3-10,(*robot_position).ypixel-36-8,25,20,15,0);
	theta_bar((*robot_position).xpixel-3-10,(*robot_position).ypixel-36-8,25,20,15,255);
	FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-35,7,0);
    FillCircle((*robot_position).xpixel+23,(*robot_position).ypixel-35,6,65535);
	forebodyhead_open(*robot_position);
	put_image((*robot_position).xpixel-32,(*robot_position).ypixel-80,(*robot_position).xpixel+32,(*robot_position).ypixel-3,(*robot_position).cat);
	forebodyhead(*robot_position);
	delay0(2000);
}