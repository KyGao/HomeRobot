#ifndef iphone.h
#define iphone.h

//	手机初始界面

/**************************************************
function:        apps

description:     画桌面应用分布

Input:           void

output:          
**************************************************************/
extern void apps(void);

/**************************************************
function:        iph_frame

description:     手机外框，固定框架

Input:           void

output:          
**************************************************************/
extern void iph_frame(int color);

/**************************************************
function:        dis_iph

description:     主界面逻辑，可实现点击第一个应用图标进入软件，点击第二个应用图标则退出

Input:           void

output:          
**************************************************************/
extern int dis_iph(int* mx, int* my);
#endif