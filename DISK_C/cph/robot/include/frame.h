#ifndef frame.h
#define frame.h

typedef struct{
	char account[11];
	char code[11];
    struct USERS *next;
}USERS;

/**************************************************
function:        load_page

description:     登录界面（静态）

Input:           

out:             

quote:           advancegf.h中相关画图函数
**************************************************************/
extern void load_page(void);

/**************************************************
function:        enterpage

description:     登录逻辑控制函数

Input:           

out:             

quote:           filefun(文件操作),sign(登录注册函数)
**************************************************************/
extern int enterpage(void);

/**************************************************
function:        zhuce_page

description:     注册界面（静态）

Input:           

out:             

quote:           advancegf.h中相关画图函数
**************************************************************/
extern void zhuce_page(void);

/**************************************************
function:        mainpage

description:     进入手机页面，并开启系统主进程

Input:           

out:             

quote:           dis_iph
**************************************************************/
extern int mainpage(void);

/**************************************************
function:        outwelcome

description:     欢迎页面

Input:           

out:             

quote:           advance.h,basic.h,color1.h
**************************************************************/
extern void outwelcome(void);
#endif