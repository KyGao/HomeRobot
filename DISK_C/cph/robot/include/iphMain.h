#ifndef iphone.h
#define iphone.h

/**************************************************
function:        extern void main_interface(void);

description:     主页界面

Input:           void

output:             
**************************************************************/
extern void main_interface(void);

/**************************************************
function:        extern int iphmain_click(int *mx,int *my,int *button);

description:     主页的鼠标检测逻辑

Input:           int *mx,int *my,int *button

output:             
**************************************************************/
extern int iphmain_click(int *mx,int *my,int *button);

/**************************************************
function:        extern void ph_main(void);

description:     主页主逻辑

Input:           void

output:             
**************************************************************/
extern void ph_main(void);

#endif