#ifndef idCheck.h
#define idCheck.h

//验证码登录输入逻辑

/**************************************************
function:        save_code

description:     验证码信息存储，包括生成验证码，验证码弹窗

Input:           验证码真值的地址

output:         
**************************************************************/
extern void save_code(char* id_real); 

/**************************************************
function:        message_box

description:     验证码弹窗并保存生成的真值并上传

Input:           void

output:          return一个验证码真值
**************************************************************/
extern void message_box(char* id_real);

/**************************************************
function:        input_num

description:     手机号输入与验证。若输入手机号正确则iph_num为1，之后获取验证码时可以收到短信；否则收不到验证码

Input:           int *mx,int *my,int *judge	鼠标变量与判断手机号正确的flag

output:          
**************************************************************/
extern void input_num(int *mx,int *my,int *judge,unsigned int *text1save);

/**************************************************
function:        id_check

description:     验证码输入，可以整型保存输入的验证码值

Input:           int *mx,int *my,int *id_code	鼠标变量与验证码输入值的地址

output:          
**************************************************************/
extern void id_check(int *mx,int *my,char *id_code,unsigned int *text2save);

#endif