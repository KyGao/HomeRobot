#ifndef iphCmfrt.h
#define iphCmfrt.h

/**************************************************
function:        extern void comfort_ui(char *air1, char *air2, char *air3, char *H, char *PM, int value, int window);

description:     舒适界面ui及状态初始化

Input:           char *air1, char *air2, char *air3, char *H, char *PM, int value, int window

output:             
**************************************************************/
extern void comfort_ui(char *air1, char *air2, char *air3, char *H, char *PM, int value, int window);

/**************************************************
function:        extern int iphcmfrt_click(int *mx,int *my,int *button);

description:     检测舒适界面鼠标点击区域

Input:           int *mx,int *my,int *button

output:             
**************************************************************/
extern int iphcmfrt_click(int *mx,int *my,int *button);

/**************************************************
function:        extern int match( int PM2);

description:     通过PM2.5的值寻找空气质量

Input:           int PM2

output:             
**************************************************************/
extern int match( int PM2);

/**************************************************
function:        extern void window_button_on(int *flag);

description:     开窗的按钮动画

Input:           int *flag

output:             
**************************************************************/
extern void window_button_on(int *flag);

/**************************************************
function:        extern void window_button_off(int *flag);

description:     关窗的按钮动画

Input:           int *flag

output:             
**************************************************************/
extern void window_button_off(int *flag);

/**************************************************
function:        extern void window_check(int *flag);

description:     检查窗户的开关状态并切换

Input:           int *flag

output:             
**************************************************************/
extern void window_check(int *flag);

/**************************************************
function:        extern void temperature_subtract(int order);

description:     减温的按钮变化与文件操作

Input:           int order

output:             
**************************************************************/
extern void temperature_subtract(int order);

/**************************************************
function:        extern void temperature_add(int order);

description:     减温的按钮变化与文件操作

Input:           int order

output:             
**************************************************************/
extern void temperature_add(int order);

/**************************************************
function:        extern void airconditioner_blink(int x, int y, ROBOT_CASE *robot_position);

description:     空调灯闪烁表示操作

Input:           int x, int y, ROBOT_CASE *robot_position

output:             
**************************************************************/
extern void airconditioner_blink(int x, int y, ROBOT_CASE *robot_position);

/**************************************************
function:        extern void random_show(int air1, int air2, int air3, int PM, int H);

description:     波动状态显示

Input:           int air1, int air2, int air3, int PM, int H

output:             
**************************************************************/
extern void random_show(int air1, int air2, int air3, int PM, int H);

/**************************************************
function:        extern void comfort_control(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y);

description:     舒适界面主逻辑

Input:           ROBOT_CASE *robot_position,SAVE *save,int *x,int *y

output:             
**************************************************************/
extern void comfort_control(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y);

#endif