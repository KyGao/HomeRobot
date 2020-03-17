#ifndef iphCharge.h
#define iphCharge.h

/**************************************************
function:        void charge_ui(void)

description:     充电界面UI

Input:           void

output:             
**************************************************************/
extern void charge_ui(void);

/**************************************************
function:        extern void charging(int battery);

description:     充电动画

Input:           void

output:             
**************************************************************/
extern void charging(int battery);

/**************************************************
function:        extern void charge_move_forward(ROBOT_CASE *robot_position, int *x, int *y);

description:     走向充电桩的动画

Input:           ROBOT_CASE *robot_position, int *x, int *y

output:             
**************************************************************/
extern void charge_move_forward(ROBOT_CASE *robot_position, int *x, int *y);

/**************************************************
function:        extern void charge_move_back(ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y);

description:     充电完成，走回之前的中断

Input:           ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y

output:             
**************************************************************/
extern void charge_move_back(ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y);

/**************************************************
function:        extern void charge_main(ROBOT_CASE *robot_position,int *x,int *y);

description:     没电时前往充电的主逻辑

Input:           ROBOT_CASE *robot_position,int *x,int *y

output:             
**************************************************************/
extern void charge_main(ROBOT_CASE *robot_position,int *x,int *y);

/**************************************************
function:        iphcharge_click(int *mx,int *my,int *button);

description:     查看充电状态界面的鼠标点击检测

Input:           int *mx,int *my,int *button

output:             
**************************************************************/
extern int iphcharge_click(int *mx,int *my,int *button);

/**************************************************
function:        extern void battery_show(ROBOT_CASE *robot_position, int battery, int *x, int *y);

description:     充电界面主逻辑，可选择去充电

Input:           ROBOT_CASE *robot_position, int battery, int *x, int *y

output:             
**************************************************************/
extern void battery_show(ROBOT_CASE *robot_position, int battery, int *x, int *y);

#endif