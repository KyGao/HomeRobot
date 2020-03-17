/******************函数清单***************************
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

	要退出字谜游戏最后说一句话
	
**************/
void show_gg(char *temp)
{
	int begin_y;	//标记每次对话框输出时的顶端y坐标以确定putimage的范围
	
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//清空要显示回复消息的区域
	show_reply(temp,&begin_y);	//开始显示回复消息
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
	return;
}

/**************
	
	生成题目,返回已经考过的题号
	
**************/
int question_generator(char *question,char *answer)
{
	FILE *game;
	int tm;		//用来确定最终选择的题号
	int i=0;	//标记暂时选择的题号
	
	srand((unsigned)(time(NULL)));		//种随机数种子
	tm = rand()%10;
	game = fopen("BGI\\game.txt","r");
	if (game == NULL)
	{
		printf("the file cant open \n");
		exit(1);
	}
	
	rewind(game);	//使指针指向文件流的开头
	while(feof(game)==0)	//当文件读取完毕或标记题号与选中题号相符时
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

	检查是不是答案，是的话返回1
	
**************/
int check_answer(char *incode,char *answer)
{
	if(strcmp(incode,answer)==0){
		return 1;
	}
	return 0;
}

/**************
	
	字谜部分，输入“我不玩了”即可退出游戏
	
**************/
void word_game(unsigned int *box_save)
{
	 Area box_area = { {ORIGINX+15+2,ORIGINY+415} , {ORIGINX+240,ORIGINY+460} };		//输入框左上角坐标
	 Coordinate current_show_position = {ORIGINX+17,ORIGINY+407};		//现在正在码的字的左上角坐标
	 int *qhwh=(int *)malloc(sizeof(int)*MAXTXT);		//汉字的区号位号
	// unsigned int *box_save=(unsigned int *)malloc(200*35*sizeof(unsigned int));	//保存输入法框中的图像
	int begin_y;	//标记每次对话框输出时的顶端y坐标以确定putimage的范围
	char *question=(char *)malloc(30*sizeof(char));	//之后标记到文件中的问句部分
	char *answer=(char *)malloc(2*sizeof(char));	//之后标记到文件中的答句部分
	char *incode=(char *)malloc(30*sizeof(char));	//用户输入的内码序列
	
	char *temp;	//用作可变回复，之后回复“题库已经被你问完啦”和“好吧，那咱们不玩啦”之类的用到
	
	int tm;	//标记该轮选中的题号
	int tm_done=0;	//标记已经问过的题目数量
	int have_done[9]={0};	//用户已经猜过的题号标记为1
	
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
	
	//界面
	temp = "好啦！那我们开始吧";
	save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
	bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//清空要显示回复消息的区域
	show_reply(temp,&begin_y);	//开始显示回复消息
	printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);	
	temp = NULL;

	while(1)
	{
		/************
			show
		************/
		while(1)	//确保随机选中的题目没有出现过
		{
			tm = question_generator(question,answer);	//抽中第几题
			if(have_done[tm]==0)	//如果该题没有被问过
			{
				have_done[tm] = 1;	//标记该题被问过
				tm_done++;			//问过的数量加一
				break;	
			}
			if(tm_done==9)	//如果题库的题目已经问完了则退出
			{
				delay(500);
				temp = "题库已经被你问完啦";
				show_gg(temp);
				temp = NULL;
				return;
			}
		}
		//把题目展示上来
		save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
		bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);		//清空要显示回复消息的区域
		show_reply(question,&begin_y);	//开始显示回复消息
		printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
		
		//fdhz(200,100,2,2,question,0);
		//fdhz(200,200,2,2,answer,0);
		
		/**************put&check******************/
		while(1)
		{
			/************
				put
			************/
			QhwhToZero(qhwh);	//初始化区位号
			ShowChTab(box_area,current_show_position/*现在正在码的字的左上角坐标*/,16,qhwh, box_save);	//开始用户的表演
			bar(ORIGINX+15, ORIGINY+405, ORIGINX+240, ORIGINY+460,65535);	//回车键之后刷新聊天窗口

			//先显示用户输入的字符
			save_image(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1);	
			bar(ORIGINX+13,ORIGINY+250,ORIGINX+243,ORIGINY+345,36410);	//清空要显示用户输入消息的区域
			show_order(qhwh,&begin_y);	//开始显示用户输入消息
			printf_image_2(ORIGINX+13, ORIGINY+50, ORIGINX+243+1, ORIGINY+345+1,begin_y);
			
			/***********
				check
			***********/
			get_str( qhwh, incode);		//得到输入的字符串内码
			
			//fdhz(200,300,2,2,incode,0);
			
			if(strcmp(incode,"我不玩了")==0)	//如果不想玩了
			{
				delay(500);
				return;							//就退出
			}
			
			if(strcmp(incode,"下一题")==0)	//如果选择下一题
			{
				delay(500);
				temp = "下一题要加油呀！";
				show_gg(temp);
				temp = NULL;
				break;
			}

			if(check_answer(incode,answer)==1)	//如果答对了
			{
				delay(500);
				temp = "答对了！太棒了！";
				show_gg(temp);
				temp = NULL;
				break;
			}
			else if(check_answer(incode,answer)==0)	//如果答错了
			{
				delay(500);
				temp = "不对不对";
				show_gg(temp);
				temp = NULL;
			}
		}
	}
	
	//释放内存
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


