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
int CheckMove(int x,int y,int floor)//判断该位置（(1,1)开头）能否移动过去，不能返回0，能返回1
{
	int k;
	FILE *fp;
	x = x-1;
	y = y-1;
	switch(floor)
	{
		case 1:
		{
			if((fp = fopen("system\\floor1.dat", "rb")) == NULL)
	        {
				fclose(fp);
				fp = NULL;
		        CreateHouseFile();
	        }
	        else
	        {
	        }
			break;
		}
		case 0:
		{
			if((fp = fopen("system\\floor0.dat", "rb")) == NULL)
	        {
				fclose(fp);
				fp = NULL;
		        CreateHouseFile();
	        }
	        else
	        {
	        }
			break;
		}
		case 2:
		{
			if((fp = fopen("system\\floor2.dat", "rb")) == NULL)
	        {
				fclose(fp);
				fp = NULL;
		        CreateHouseFile();
	        }
	        else
	        {
	        }
			break;
		}
	}
	fseek(fp,sizeof(int)*(19*x+y),0);
	fread(&k,1,sizeof(int),fp);	
	fclose(fp);
	fp = NULL;
	return k;
}


void ChangeMove(int x,int y,int floor,int change)//改变能否移动的信息
{
	int k;
	FILE *fp;
	x = x-1;
	y = y-1;
	
	switch(floor)
	{
		case 1:
		{
			if((fp = fopen("system\\floor1.dat", "r+b")) == NULL)
	        {
				fclose(fp);
				fp = NULL;
		        CreateHouseFile();
	        }
	        else
	        {
	        }
			break;
		}
		case 0:
		{
			if((fp = fopen("system\\floor0.dat", "r+b")) == NULL)
	        {
				fclose(fp);
				fp = NULL;
		        CreateHouseFile();
	        }
	        else
	        {
	        }
			break;
		}
		case 2:
		{
			if((fp = fopen("system\\floor2.dat", "r+b")) == NULL)
	        {
				fclose(fp);
				fp = NULL;
		        CreateHouseFile();
	        }
	        else
	        {
	        }
			break;
		}
	}
	fseek(fp,sizeof(int)*(19*x+y),0);
	fwrite(&change,sizeof(int),1,fp);
	fclose(fp);
	fp = NULL;
}

int CheckCarry(int x,int y,int floor)//判断该位置（(1,1)开头）能否移动过去，不能返回0，能返回1
{
	int k;
	FILE *fp;
	x = x-1;
	y = y-1;
	if(floor == 1)
	{
		if((fp = fopen("system\\floorcarry.dat", "rb")) == NULL)
	    {
			fclose(fp);
			fp = NULL;
		    CreateHouseFile();
	    }
	    else
	    {
			fseek(fp,sizeof(int)*(19*x+y),0);
	        fread(&k,1,sizeof(int),fp);	
	        fclose(fp);
			fp = NULL;
	    }
	}
	else
	{
		fclose(fp);
		fp = NULL;
		//error
		exit(1);
	}
	
	
	return k;
}


void ChangeCarry(int x,int y,int floor,int change)//改变能否搬运的信息
{
	int k;
	FILE *fp;
	x = x-1;
	y = y-1;
	if(floor == 1)
	{
		if((fp = fopen("system\\floorcarry.dat", "r+b")) == NULL)
	    {
			fclose(fp);
			fp = NULL;
		    CreateHouseFile();
	    }
	    else
	    {
	    }
	}
	else
	{
		fclose(fp);
		fp = NULL;
		//error
		exit(1);
	}
	fseek(fp,sizeof(int)*(19*x+y),0);
	fwrite(&change,sizeof(int),1,fp);
	fclose(fp);
	fp = NULL;
}

int CheckHouse(int check)//获取环境相关信息
{
	FILE *fp;
	ENVIR house;
	if((fp = fopen("system\\house.dat", "rb")) == NULL)
	{
		CreateHouseFile();
	}
	fread(&house,1,sizeof(ENVIR),fp);
	fclose(fp);
	fp = NULL;
	switch(check)
	{
		case 1:
		{
			return house.win;
		}
		case 2:
		{
			return house.aircon[0];
		}
		case 3:
		{
			return house.aircon[1];
		}
		case 4:
		{
			return house.aircon[2];
		}
		case 5:
		{
			return house.PM1;
		}
		case 6:
		{
			return house.T;
		}
		case 7:
		{
			return house.H;
		}
		case 8:
		{
			return house.win;
		}
		case 9:
		{
			return house.trashx[0];
		}
		case 10:
		{
			return house.trashy[0];
		}
		case 11:
		{
			return house.trashx[1];
		}
		case 12:
		{
			return house.trashy[1];
		}
		case 13:
		{
			return house.trashx[2];
		}
		case 14:
		{
			return house.trashy[2];
		}
		case 15:
		{
			return house.trashbin[0];
		}
		case 16:
		{
			return house.trashbin[1];
		}
		case 17:
		{
			return house.trashbin[2];
		}
		case 18:
		{
			return house.weedx[0];
		}
		case 19:
		{
			return house.weedy[0];
		}
		case 20:
		{
			return house.weedx[1];
		}
		case 21:
		{
			return house.weedy[1];
		}
		case 22:
		{
			return house.weedx[2];
		}
		case 23:
		{
			return house.weedy[2];
		}
		case 24:
		{
			return house.trash;
		}
		case 25:
		{
			return house.battery;
		}
		case 26:
		{
			return house.battery_on;
		}
	}
}

//唯有T,H,trashbin的change是改变量,即Change(T,1) => T+=1;
void ChangeHouse(int check,int change)//改变环境情况
{
	FILE *fp;
	ENVIR house;
	if((fp = fopen("system\\house.dat", "rb")) == NULL)
	{
		CreateHouseFile();
	}
	fread(&house,1,sizeof(ENVIR),fp);
	fclose(fp);
	fp = NULL;
	switch(check)
	{
		case 1:
		{
			house.win = change;
			break;
		}
		case 2:
		{
			house.aircon[0] += change;
			break;
		}
		case 3:
		{
			house.aircon[1] += change;
			break;
		}
		case 4:
		{
			house.aircon[2] += change;
			break;
		}
		case 5:
		{
			house.PM1 += change;
			break;
		}
		case 6:
		{
			house.T += change;
			break;
		}
		case 7:
		{
			house.H += change;
			break;
		}
		case 8:
		{
			house.win = change;
			break;
		}
		case 9:
		{
			house.trashx[0] = change;
			break;
		}
		case 10:
		{
			house.trashy[0] = change;
			break;
		}
		case 11:
		{
			house.trashx[1] = change;
			break;
		}
		case 12:
		{
			house.trashy[1] = change;
			break;
		}
		case 13:
		{
			house.trashx[2] = change;
            break;
		}
		case 14:
		{
			house.trashy[2] = change;
			break;
		}
		case 15:
		{
			house.trashbin[0] += change;
			break;
		}
		case 16:
		{
			house.trashbin[1] += change;
			break;
		}
		case 17:
		{
			house.trashbin[2] += change;
			break;
		}
		case 18:
		{
			house.weedx[0] = change;
			break;
		}
		case 19:
		{
			house.weedy[0] = change;
			break;
		}
		case 20:
		{
			house.weedx[1] = change;
			break;
		}
		case 21:
		{
			house.weedy[1] = change;
			break;
		}
		case 22:
		{
			house.weedx[2] = change;
			break;
		}
		case 23:
		{
			house.weedy[2] = change;
			break;
		}
		case 24:
		{
			house.trash = change;
			break;
		}
		case 25:
		{
			house.battery += change;
			break;
		}
		case 26:
		{
			house.battery_on = change;
		}
	}
	fp = fopen("system\\house.dat", "wb");
	fwrite(&house,1,sizeof(ENVIR),fp);
	fclose(fp);
	fp = NULL;
}
void CreateHouseFile()//初始化所有环境信息
{
	FILE *fp1,*fp2,*fp3,*fp4,*fp5;
	int carryable[19][19];
	int i,j;
	
	ENVIR house;
	
	int moveable1[19][19] = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0 },
		{ 0,0,1,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,0 },
		{ 0,0,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,1,0 },
		{ 0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,0 },
		{ 0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0 },
		{ 0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0 },
		{ 0,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0 },
		{ 0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0 },
		{ 0,1,1,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0 },
		{ 0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,0 },
		{ 0,0,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0 },
		{ 0,1,1,1,1,0,0,1,0,1,1,0,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,1,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	};
		
	int moveable0[19][19] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	};
	
	int moveable2[19][19] = {
		{ 0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	};//(7,5)为楼梯
	
	
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			if( (((i==13)||(i==14))&&(j==2)) || ((j==9)&&((i==3)||(i==6))) || (((i==4)||(i==5))&&(j==8)) || (((i==4)||(i==5))&&(j==10)) )
			{
				carryable[i][j]=1;
			}
			else
			{
				carryable[i][j]=0;
			}
		}
	}
	
	//window_init
	house.win = 0;               //1
	//air-condition init
	house.aircon[0] = 26;         //2
	house.aircon[1] = 26;         //3
	house.aircon[2] = 26;         //4
	//T,H,PM2.5 init
	house.PM1 = 100+rand()%100;      //5
	house.T = 26;                //6
	house.H = 50;                //7
	house.trash = 0;//场面上无垃圾//8
	house.battery = 180;
	house.battery_on = 0;

	for(i=0;i<3;i++)
	{
		house.trashx[i] = 0;     //9,11,13
		house.trashy[i] = 0;     //10,12,14
	}
	//初始化垃圾桶内数量
	for(i=0;i<3;i++)
	{
		house.trashbin[i] = 0;   //15,16,17
		house.weedx[i] = 0;      //18,20,22
		house.weedy[i] = 0;      //19,21,23
	}
	
	/*存入文件中*/
	fp1 = fopen("system\\floor1.dat", "wb");
	if(fp1 == NULL)
	{
		exit(1);
	}
	fwrite(moveable1,sizeof(int),19*19,fp1);
	fclose(fp1);
	fp1 = NULL;
	fp2 = fopen("system\\floor0.dat", "wb");
	if(fp2 == NULL)
	{
		exit(1);
	}
	fwrite(moveable0,sizeof(int),19*19,fp2);
	fclose(fp2);
	fp2 = NULL;
	fp3 = fopen("system\\floor2.dat", "wb");
	if(fp3 == NULL)
	{
		exit(1);
	}
	fwrite(moveable2,sizeof(int),19*19,fp3);
	fclose(fp3);
	fp3 = NULL;
	fp4 = fopen("system\\floorcarry.dat", "wb");
	if(fp4 == NULL)
	{
		exit(1);
	}
	fwrite(carryable,sizeof(int),19*19,fp4);
	fclose(fp4);
	fp4 = NULL;
	fp5 = fopen("system\\house.dat", "wb");
	if(fp5 == NULL)
	{
		exit(1);
	}
	fwrite(&house,sizeof(ENVIR),1,fp5);
	fclose(fp5);
	fp5 = NULL;
}

//for test
void ShowFile()
{
	int i,j,k;
	FILE *fp;
	fp = fopen("system\\floorcarry.dat", "rb");
	if(fp==NULL)
	{
		exit(1);
	}
	for(i=0;i<19;i++)
	{
		for(j = 0;j<19;j++)
		{
			fread(&k,1,sizeof(int),fp);
			printf("%d,",k);
		}
		printf("\n");
	}
	fclose(fp);
	fp = NULL;
}



