#ifndef __MOVE_H
#define __MOVE_H

/*机器人结构体,储存所有机器人相关信息*/
typedef struct{
	char leg;//左脚动为1，右脚动为0；
	char leg_left;
	char leg_right;//用于传入moveaim的参数，改变脚的矩形大小，使两个脚看起来像在走。
	char hand;//左手前为1，右手为0
	char hand_left;
	char hand_right;//手的运动参数,为θ
	char catch_th;//是否正在拾取
	unsigned int *cat;//存储其图像信息
	int x;
	int y;//19*19
	int xpixel;
	int ypixel;//1024*768
	int direction;//方向，1为右，2为左，3为上，4为下
	int position;//0位户外,1为ground,2为floor
}ROBOT_CASE;

/*存储垃圾背景图像*/
typedef struct{
	unsigned int *trashsave1;
	unsigned int *trashsave2;
	unsigned int *trashsave3;
}SAVE;

/*按钮结构体，定义按钮的各个属性*/
typedef struct{
	int x;//left_up
	int y;//left_up
	int height;
	int wide;
	int click;
	int over;
}BUTTONS;

/**************************************************
function:        dmove

description:     输入结构体，执行该方向移动(1像素点）

Input:           ROBOT_CASE *,int *x,int *y

out:             

quote:           get_image,put_image,left,right,back/forebodyhead,delay0,newxy
**************************************************************/
extern void dmove(ROBOT_CASE *,int *x,int *y);

/**************************************************
function:        dmove2

description:     输入结构体，执行该方向移动(1像素点）

Input:           ROBOT_CASE *,int *x,int *y,unsigned int *withchair(加上椅子的存储空间)

out:             搬椅子移动

quote:           get_image,put_image,left,right_chair,back/forebodyhead,delay0,newxy
**************************************************************/
extern void dmove2(ROBOT_CASE *robot_position,int *x,int *y,unsigned int *withchair);

/**************************************************
function:        move0

description:     输入结构体，执行该方向移动(1单元格，即40像素点）

Input:           ROBOT_CASE *,int *x,int *y

out:             

quote:           dmove
**************************************************************/
extern void move0(ROBOT_CASE *,int *x,int *y);//40 per step

/**************************************************
function:        move2

description:     输入结构体，执行该方向移动(1单元格，即40像素点）

Input:           ROBOT_CASE *,int *x,int *y,unsigned int *withchair

out:             拿着椅子的动画

quote:           dmove2
**************************************************************/
extern void move2(ROBOT_CASE *robot_position,int *x,int *y,unsigned int *withchair);

/**************************************************
function:        randmove

description:     随机生成移动方向移动一格

Input:           ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y

out:             返回值若为-2，则退出该函数返回主页

quote:           move0
**************************************************************/
extern int randmove(ROBOT_CASE *robot_position,BUTTONS *esc1,int *x,int *y);

/**************************************************
function:        aimmove

description:     输入结构体，执行该方向移动(1单元格，即40像素点）

Input:           ROBOT_CASE *robot_position,int f(floor),int x0,int y0(起点),int xt,int yt(终点),int *x,int *y(鼠标)

out:             若返回值为0，代表出发点等于目的地，不执行

quote:           move,FindWay,InitStack,DestroyStack,pop,push
**************************************************************/
extern int aimmove(ROBOT_CASE *robot_position,int f,int x0,int y0,int xt,int yt,int *x,int *y);

/**************************************************
function:        CutWeed

description:     输入结构体，执行该方向移动(1单元格，即40像素点）

Input:           ROBOT_CASE *robot_position,unsigned int *CutSave(割草机图像储存),int direction

out:             拿着椅子的动画

quote:           right_hold,left_hold,CutMachine
**************************************************************/
extern void CutWeed(ROBOT_CASE *robot_position,unsigned int *CutSave,int direction);

#endif