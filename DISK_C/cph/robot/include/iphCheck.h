#ifndef iphCheck.h
#define iphCheck.h

// 手机验证码登录



/**************************************************
function:        checkin

description:     验证码界面主逻辑,可实现验证码弹窗，输入手机号码及验证码，点击登录与获取验证码

Input:           void

output:             
**************************************************************/
extern int checkin(int* x, int* y); 

/**************************************************
function:        checkin_interface

description:     画应用登录界面

Input:           void

output:          
**************************************************************/
extern void checkin_interface();

/**************************************************
function:        checkin_click

description:     鼠标检测逻辑，对于每一个点击区域都有一个返回值

Input:           int mx,int my,int button

output:          
**************************************************************/
extern int checkin_click(int *mx,int *my,int button);



#endif