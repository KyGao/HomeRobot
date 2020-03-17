#ifndef control.h
#define control.h

/**************************************************
function:        move_ui

description:     安全功能ui

Input:           

out:             

quote:           advancegf.h
**************************************************************/
extern void move_ui(void);
/**************************************************
function:        easy_ui

description:     便捷功能ui

Input:           

out:             

quote:           advancegf.h
**************************************************************/
extern void easy_ui(void);
/**************************************************
function:        clean_ui

description:     卫生ui

Input:          

out:             

quote:           advancegf.h
**************************************************************/
extern void clean_ui(void);
/**************************************************
function:        move_control

description:     安全功能逻辑控制函数

Input:           ROBOT_CASE *robot_position,BUTTONS *,int *x,int *y

out:             

quote:           randmove,go_to,move_ui
**************************************************************/
extern int move_control(ROBOT_CASE *robot_position,BUTTONS *,int *x,int *y);
/**************************************************
function:        clean_control

description:     卫生功能逻辑控制函数

Input:           ROBOT_CASE *robot_position,BUTTONS *,SAVE *save,int *x,int *y

out:             

quote:           clean_ui,clean_weed,clean,ShowTrashNum,throw_trash,
**************************************************************/
extern int clean_control(ROBOT_CASE *robot_position,BUTTONS *,SAVE *save,int *x,int *y);
/**************************************************
function:        easy_control

description:     便捷功能逻辑控制函数

Input:           ROBOT_CASE *robot_position,BUTTONS *,SAVE *save,int *x,int *y

out:             

quote:           easy_ui,move_chair;
**************************************************************/
extern int easy_control(ROBOT_CASE *robot_position,BUTTONS *,SAVE *save,int *x,int *y);


#endif