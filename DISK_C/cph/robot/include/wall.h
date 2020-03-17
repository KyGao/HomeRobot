#ifndef wall.h
#define wall.h


/**************************************************
function:        extern void w_blue(int x, int y);

description:     蓝墙

Input:           int x, int y

output:             
**************************************************************/
extern void w_blue(int x, int y);

/**************************************************
function:        extern void w_right(int x,int y);

description:     右墙

Input:           int x,int y

output:             
**************************************************************/
extern void w_right(int x,int y);

/**************************************************
function:        extern void w_left(int x, int y);

description:     左墙

Input:           int x, int y

output:             
**************************************************************/
extern void w_left(int x, int y);

/**************************************************
function:        extern void w_down(int x, int y);

description:     下侧的墙

Input:           int x, int y

output:             
**************************************************************/
extern void w_down(int x, int y);

/**************************************************
function:        extern void o_right(int x,int y);

description:     花园右墙

Input:           int x,int y

output:             
**************************************************************/
extern void o_right(int x,int y);

/**************************************************
function:        extern void o_left(int x, int y);

description:     花园左墙

Input:           int x, int y

output:             
**************************************************************/
extern void o_left(int x, int y);

/**************************************************
function:        extern void o_wall(int x, int y);

description:     花园外墙

Input:           int x, int y

output:             
**************************************************************/
extern void o_wall(int x, int y);





#endif