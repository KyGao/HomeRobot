#ifndef __MYSYSTEM_H
#define __MYSYSTEM_H


/**************************************************
function:        CreateTrash

description:     创建垃圾

Input:           *robot_position,save(垃圾图像存储),k(代表要生成的垃圾编号)

out:             根据垃圾编号生成对应垃圾，并修改文件中的垃圾数量和位置；

quote:           CheckMove,ChangeHouse,CheckHouse,trash1,trash2,trash3
**************************************************************/
extern void CreateTrash(ROBOT_CASE *robot_position,SAVE *save,int k);

/**************************************************
function:        esc_check

description:     检查退出按钮情况

Input:           BUTTONS *,int *x,int *y,int *button

out:             若点击退出则返回-1，否则返回0

quote:           
**************************************************************/
extern int esc_check(BUTTONS *esc1,int *x,int *y,int *button);



extern void esc_init(BUTTONS *esc1);



extern void CheckHeap(int i);
#endif