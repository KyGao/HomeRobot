#ifndef compo.h
#define compo.h

/**************************************************
function:        backbodyhead

description:     机器人背面图

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h中相关画图函数
**************************************************************/
extern void backbodyhead(ROBOT_CASE robot_position);

/**************************************************
function:        left

description:     机器人左面图

Input:           ROBOT_CASE robot_position

out:            

quote:           advancegf.h中相关画图函数
**************************************************************/
extern void left(ROBOT_CASE robot_position);

/**************************************************
function:        forebodyhead

description:     机器人正面图

Input:           ROBOT_CASE robot_position

out:            

quote:           advancegf.h中相关画图函数
**************************************************************/
extern void forebodyhead(ROBOT_CASE robot_position);

/**************************************************
function:        right

description:     机器人右面图

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h中相关画图函数
**************************************************************/
extern void right(ROBOT_CASE robot_position);

/**************************************************
function:        right_hold

description:     机器人向右推除草机的图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void right_hold(ROBOT_CASE robot_position);

/**************************************************
function:        left_hold

description:     机器人向左推除草机的图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void left_hold(ROBOT_CASE robot_position);

/**************************************************
function:        right_hold

description:     机器人向右拿东西的图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void right_chair(ROBOT_CASE robot_position);

/**************************************************
function:        left_hold

description:     机器人向左拿东西的图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void left_chair(ROBOT_CASE robot_position);

/**************************************************
function:        fore_hold

description:     机器人向前拿东西的图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void fore_chair(ROBOT_CASE robot_position);

/**************************************************
function:        backbodyhead_open

description:     机器人开窗图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void backbodyhead_open(ROBOT_CASE robot_position);

/**************************************************
function:        forebodyhead_open

description:     机器人收集垃圾的图像

Input:           ROBOT_CASE robot_position

out:             

quote:           advancegf.h,basicgf.h中相关画图函数
**************************************************************/
extern void forebodyhead_open(ROBOT_CASE robot_position);
#endif