#ifndef __MANAGE_H
#define __MANAGE_H

/**************************************************
function:        mainprocess

description:     系统主进程

Input:           x,y(鼠标位置指针)

out:             

quote:           esc_init,esc_check,iphmain_click,move_one_step,chat_main,
                 clean_control,comfort_control,easy_control,move_control,
				 battery_show,_ground,ph_main,overflow_box
**************************************************************/
extern void mainprocess(int *x,int *y);

#endif