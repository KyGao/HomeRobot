#ifndef chatShow.h
#define chatShow.h

/**************************************************
function:        extern void show_order(int *qhwh,int *y);

description:     打印用户命令

Input:           int *qhwh,int *y

output:          
**************************************************************/
extern void show_order(int *qhwh,int *y);

/**************************************************
function:        extern void get_str(int *qhwh, char *incode);

description:     得到机器人回复的字符串

Input:           int *qhwh, char *incode

output:          
**************************************************************/
extern void get_str(int *qhwh, char *incode);

/**************************************************
function:        extern void reply_match(char * str,char *order,char **reply);

description:     去文件中比对命令以得到需要的回复

Input:           char * str,char *order,char **reply

output:          
**************************************************************/
extern void reply_match(char * str,char *order,char **reply,unsigned int *box_save);

/**************************************************
function:        extern void show_reply(char *incode, int * y);

description:     打印机器人回复

Input:           char *incode, int * y

output:          
**************************************************************/
extern void show_reply(char *incode, int * y);

/**************************************************
function:        extern void show_main(int *qhwh);

description:     显示聊天内容主逻辑

Input:           int *qhwh

output:          
**************************************************************/
extern void show_main(int *qhwh,unsigned int *box_save);

#endif