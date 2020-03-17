#ifndef gkmove.h
#define gkmove.h

extern void remote_interface();

extern int remote_click(int *mx,int *my,int button);

extern int move_one_step(ROBOT_CASE *robot_position,int *x,int *y);

extern void tri(int x,int y,int di);
#endif