#ifndef service.h
#define service.h


/**************************************************
function:        open_window

description:     开关门窗,save为垃圾图像存储,win_case0表示目前为关，1为开,打开窗会生成垃圾

Input:           ROBOT_CASE *,SAVE *,int win_case,int *x,int *y

out:             

quote:           aimmove,wave, ChangeHouse,CreateTrash
**************************************************************/
extern void open_window(ROBOT_CASE *robot_position,SAVE *save,int win_case,int *x,int *y);

/**************************************************
function:        go_to

description:     通过鼠标点击移动到相应位置，能移动区域有绿色显示??

Input:           ROBOT_CASE *,int *x,int *y

out:             

quote:           CheckMove,reset_mouse,randmove
**************************************************************/
extern void go_to(ROBOT_CASE *robot_position,BUTTONS *,int *x,int *y);

/**************************************************
function:        clean_weed

description:     走到outside,移动到三个除草位置将杂草除去，并移动回ground

Input:           ROBOT_CASE *,int *x,int *y

out:             

quote:           InitStack,DestroyStack,aimmove,CheckMove,CheckHouse,Cut_Machine1,Cut_Machine2,meadow
                 get_image,put_image,forebodyhead
**************************************************************/
extern void clean_weed(ROBOT_CASE *robot_position,int *x,int *y);

/**************************************************
function:        movechair

description:     鼠标点击选中椅子并提示，再次点击选中目的地，若目的地可前往，搬运椅子前往目的地，
                 操作结束后回到初始位置，并生成三号垃圾。

Input:           ROBOT_CASE *,SAVE *,int *x,int *y

out:             

quote:           InitStack,DestroyStack,aimmove,CheckMove,ChangeMove,CheckHouse,CheckCarry,ChangeCarry
                 CreateTrash,fdhz,trap
**************************************************************/
extern void movechair(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y);

extern void clean(ROBOT_CASE *robot_position,SAVE *save,int *x,int *y);

extern int find_trashbin(ROBOT_CASE *robot_position);

extern void throw_trash(ROBOT_CASE *robot_position,int *x,int *y);

extern void trash3to2(ROBOT_CASE *robot_position,int *x,int *y);

extern void trash2to_outside(ROBOT_CASE *robot_position,int *x,int *y);

extern void wave(ROBOT_CASE *robot_position);

extern int take_chair(ROBOT_CASE *robot_position,int f,int x0,int y0,int xt,int yt,int *x,int *y);

extern void ShowTrashNum();

extern void take_trash(ROBOT_CASE *robot_position);
#endif