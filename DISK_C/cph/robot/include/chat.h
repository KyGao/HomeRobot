#ifndef chat.h
#define chat.h


typedef struct ChTab
{
    int qhwh;
    char str[7];
}CH;

typedef struct EnTab
{
    int qhwh;
    char str;
}EN;


typedef struct Coordinate
{
    int x;
    int y;
} Coordinate;

typedef struct Area
{
    Coordinate lt;
    Coordinate rb;
} Area;


/**************************************************
function:        chat_interface

description:     聊天界面

Input:           输入框的坐标,&box_area是输入框的坐标,&current_show_position是初始化输入第一个字定位的坐标

output:         
**************************************************************/
extern void chat_interface(unsigned int *box_save);

/**************************************************
function:        QhwhToZero

description:     将区号位号初始化

Input:           第一个区号位号的地址

output:         
**************************************************************/
extern int QhwhToZero(int *qhwh);

/**************************************************
function:        ClearKey

description:     清空键盘缓冲区

Input:           

output:         
**************************************************************/
extern void ClearKey(void);

/**************************************************
function:        chat_main

description:     聊天主逻辑实现

Input:           

output:         
**************************************************************/
extern void chat_main(void);

#endif