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
/*初始化栈*/
void InitStack(STACK *S)
{
	S->base = (UNIT *)malloc(INIT_SIZE * sizeof(UNIT));
	if(!S->base)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	else
	{
		S->top = S->base;
		S->size = INIT_SIZE;
	}
}

/*清空,并使各参数复原,但空间保留*/
void ClearStack(STACK *S)
{
	S->top = S->base;
	S->totalstep=0;
}
/*压栈*/
void Push(STACK *S,UNIT e)
{
	if(S->top - S->base >= S->size)
	{
		S->base = (UNIT *)realloc(S->base,(S->size + INCRE_SIZE) * sizeof(UNIT));
		if(!S->base)
		{
			overflow_box(500,500);
			getch();
			exit(1);
		}
		else
		{
            S->top = S->base + S->size;
			S->size += INCRE_SIZE;
		}
	}
	*(S->top) = e;
	S->top++;
}

/*弹出栈顶元素*/
void Pop(STACK *S,UNIT *e)
{
	//栈为空
	if(S->base==S->top)
	{
		pop_error(500,500);
		getch();
		exit(1);
	}
	S->top--;
	*e = *(S->top);
	if(S->top == S->base)
	{
		S->size = 0;
		S->totalstep=0;
	}
}

/*判断栈是否为空*/
int StackEmpty(STACK *S)//empty:1
{
	if(S->base==S->top)
	{
		return 1;
	}
	else return 0;
}

/*销毁栈*/
void DestroyStack(STACK *S)
{
	int i,len;
	len = S->size;
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	S->size = 0;
	S->totalstep=0;
}

/*判断是否已经走过该路线*/
int FindSame(int x,int y,char (*p)[19])//same:1
{
	if(*(*(p+x)+y)!=0)
		return 1;
	else return 0;
}

/*寻路函数*/
int FindWay(int f,int x0,int y0,int xt,int yt,STACK *S)//floor,...return 0:False,return 1:True,以(0,0)为初始坐标
{
	char i,j;//遍历变量
	UNIT *e=NULL;//存储一个单元格的信息
	/*当前位置*/
	int tempx,tempy;
	int step;//步数
	/*路径记录*/
	char save[19][19];
	char (*p)[19] = NULL;//0:未经过,1:走过,2:不能通行
    int pre_di=0;//前一步方向
	
	/*当前位置为起点*/
	tempx = x0;
	tempy = y0;
	/*初始化路径记录*/
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			save[i][j] = 0;
		}
	}
	/*将数组指针指向二维数组*/
	p = save;
	
	/*分配空间*/
	e = (UNIT *)malloc(sizeof(UNIT));
	if(e==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	
	
	S->totalstep = 0;
	step=1;
	do{
		if(CheckMove(tempx+1,tempy+1,f)==1 && !FindSame(tempx,tempy,p))
		{
			*(*(p+tempx)+tempy) = 1;
			e->ord = step;
			e->floor = f;
			e->x = tempx;
			e->y = tempy;
			e->di_num=0;
			/*
			if(pre_di != 0)
			{
				e->di = pre_di;
			}*/
			/*根据当前位置信息改变方向*/
			if(tempx<xt && tempy<=yt)
			{
				e->di = 1;
			}
			else
			{
				if(tempx>xt && tempy>=yt)
				{
					e->di = 2;
				}
				else
				{
					if(tempy<yt)
					{
						e->di = 4;
					}
					else
					{
						e->di = 3;
					}
				}
			}
			
			
			Push(S,*e);
			
			if(tempx == xt && tempy == yt)//若已经是终点
			{
				S->totalstep = e->ord;
				/*终点不需要再移动，弹出栈顶元素*/
				Pop(S,e);
				/*释放空间*/
				free(e);
				e = NULL;
				p = NULL;
				
				return 1;
			}
			
			step++;//步数增加
			switch(e->di){
				/*根据方向改变当前位置值*/
						case 1:
						{
							tempx = e->x+1;
							tempy = e->y;
							break;
						}
						case 2:
						{
							tempx = e->x-1;
							tempy = e->y;
							break;
						}
						
						case 3:
						{
							tempy = e->y-1;
							tempx = e->x;
							break;
						}
						case 4:
						{
							tempy = e->y+1;
							tempx = e->x;
							break;
						}
					}
		}
		else
		{
			if(!StackEmpty(S))
			{
				Pop(S,e);
				
				while(e->di_num ==3 && !StackEmpty(S))
				{
					*(*(p+e->x)+e->y) = 2;
					Pop(S,e);
				}
				if(e->di_num !=3)
				{
					/*改变方向*/
					switch(e->di){
						case 1:
						{
							e->di = 4;
							break;
						}
						case 2:
						{
							e->di = 3;
							break;
						}
						case 3:
						{
							e->di = 1;
							break;
						}
						case 4:
						{
							e->di = 2;
							break;
						}
					}
					e->di_num++;
					Push(S,*e);
				}
			
			}
			
			/*根据方向得到下一步的坐标*/
			switch(e->di){
						case 1:
						{
							tempx = e->x+1;
							tempy = e->y;
							break;
						}
						case 2:
						{
							tempx = e->x-1;
							tempy = e->y;
							break;
						}
						
						case 3:
						{
							tempy = e->y-1;
							tempx = e->x;
							break;
						}
						case 4:
						{
							tempy = e->y+1;
							tempx = e->x;
							break;
						}
					}
					
		}
		
	}while(!StackEmpty(S));
	
	/*回收空间*/
	free(e);
	e = NULL;
	p = NULL;

	return 0;
	
}