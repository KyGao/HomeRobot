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
/*******
地形
*******/
void floor_O(void)
{
	int i,j,x,y;
	
	//	花园
	
	for(i=4;i<=12;i++)
	{
		for(j=4;j<=13;j++)
		{
			meadow(i,j);
		}
	}
	//
	o_right(12,4);
	o_right(12,5);
	o_right(12,6);
	o_right(12,7);
	o_right(12,8);
	o_right(12,9);
	//o_right(12,10);
	//o_right(12,11);
	o_right(12,12);
	o_right(12,13);
	
	for(i=4;i<=12;i++){
		o_wall(i,12);
		o_wall(i,2);
	}
	o_right(12,2);
	o_right(12,3);
	o_left(4,2);
	o_left(4,3);
	
	//树
	tree(5,5);
	tree(5,12);
	
	//random weed
	
	for(i=0;i<3;i++)
	{
		/*避免两个杂草混在一起*/
		if(i==1)
		{
			while(y == CheckHouse(19+2*i-2))
			{
				x = rand()%6+5;
				y = rand()%6+5;
			}
		}
		else
		{
			if(i==2)
			{
				while((y == CheckHouse(19+2*i-2)) || (y == CheckHouse(19+2*i-4)))
			    {
				    x = rand()%6+5;
				    y = rand()%6+5;
			    }
			}
			else
			{
				x = rand()%6+5;
			    y = rand()%6+5;
			}
			
		}
		ChangeHouse(18+2*i,x);
		ChangeHouse(19+2*i,y);
		weed(x,y);
		ChangeMove(x,y,0,0);
	}
	
	
	//	马路
	for(i=1;i<=3;i++){
		for(j=1;j<=13;j++){
			grey(i,j);
		}
	}
	for(i=1;i<=12;i++){
		for(j=14;j<=15;j++){
			grey(i,j);
		}
	}
	
	//连接踏板
	step(12,10);

	
	big_trashbin(1,13);
}

	//	main
void _outside(void)
{
	floor_O();
}