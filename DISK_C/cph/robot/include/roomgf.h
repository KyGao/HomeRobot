#ifndef roomgf.h
#define roomgf.h
/*均为画图函数*/

/**************************************************
function:        trashbin

description:     小垃圾桶

Input:           x,y

out: 
**************************************************************/
extern void trashbin(int x,int y);
/**************************************************
function:        door

description:     门

Input:           x,y

out: 
**************************************************************/
extern void door(int x,int y);
/**************************************************
function:        brick0

description:     黄白相间的地砖

Input:           x,y

out: 
**************************************************************/
extern void brick0(int x,int y);
/**************************************************
function:        floor0

description:     brick0构成的地板

Input:           x,y

out: 
**************************************************************/
extern void floor0();
/**************************************************
function:        tree

description:     树

Input:           x,y

out: 
**************************************************************/
extern void tree(int x,int y);
/**************************************************
function:         bed

description:     床

Input:           x,y

out: 
**************************************************************/
extern void bed(int x,int y);
/**************************************************
function:        window_close

description:     关闭的窗户

Input:           x,y

out: 
**************************************************************/
extern void window_close(int x,int y);
/**************************************************
function:        window_open

description:     打开的窗户

Input:           x,y

out: 
**************************************************************/
extern void window_open(int x,int y);
/**************************************************
function:        cupboard

description:     柜子

Input:           x,y

out: 
**************************************************************/
extern void cupboard(int x,int y);
/**************************************************
function:        weed

description:     杂草

Input:           x,y

out: 
**************************************************************/
extern void weed(int x,int y);
/**************************************************
function:        aircon

description:     空调

Input:           x,y

out: 
**************************************************************/
extern void aircon(int x,int y,int open);
/**************************************************
function:        WashMach

description:     洗衣机

Input:           x,y

out: 
**************************************************************/
extern void WashMach(int x,int y);
/**************************************************
function:        bookshelf

description:     书架

Input:           x,y

out: 
**************************************************************/
extern void bookshelf(int x,int y);
/**************************************************
function:        table

description:     桌子

Input:           x,y

out: 
**************************************************************/
extern void table(int x,int y);
/**************************************************
function:        seat

description:     可挪动的椅子

Input:           x,y(绝对坐标)

out: 
**************************************************************/
extern void seat(int x,int y);
/**************************************************
function:        trash1

description:     纸质垃圾

Input:           x,y

out: 
**************************************************************/
extern void trash1(int x,int y);
/**************************************************
function:        trash2

description:     菜叶

Input:           x,y

out: 
**************************************************************/
extern void trash2(int x,int y);
/**************************************************
function:        trash3

description:     苹果核

Input:           x,y

out: 
**************************************************************/
extern void trash3(int x,int y);
/**************************************************
function:        pc

description:     电脑

Input:           x,y

out: 
**************************************************************/
extern void pc(int x,int y);
/**************************************************
function:        TV

description:     小电视

Input:           x,y

out: 
**************************************************************/
extern void TV(int x,int y);
/**************************************************
function:        rect_table

description:     方桌

Input:           x,y

out: 
**************************************************************/
extern void rect_table(int x,int y);
/**************************************************
function:        seat1

description:     坐垫1

Input:           x,y

out: 
**************************************************************/
extern void seat1(int x,int y);
/**************************************************
function:        seat2

description:     坐垫2

Input:           x,y

out: 
**************************************************************/
extern void seat2(int x,int y);
/**************************************************
function:        seat3

description:     坐垫3

Input:           x,y

out: 
**************************************************************/
extern void seat3(int x,int y);
/**************************************************
function:        seat4

description:     坐垫4

Input:           x,y

out: 
**************************************************************/
extern void seat4(int x,int y);
/**************************************************
function:        big_trashbin

description:     大垃圾桶

Input:           x,y

out: 
**************************************************************/
extern void big_trashbin(int x,int y);
/**************************************************
function:        Cut_Machine1

description:     向左推时的除草机

Input:           x,y(绝对坐标)

out: 
**************************************************************/
extern void Cut_Machine1(int x,int y);
/**************************************************
function:        Cut_Machine2

description:     向右推时的除草机

Input:           x,y(绝对坐标)

out: 
**************************************************************/
extern void Cut_Machine2(int x,int y);
/**************************************************
function:        show_num

description:     数字显示函数

Input:           x,y,num

out: 
**************************************************************/
extern void show_num(int x,int y,int num);
#endif