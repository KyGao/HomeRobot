#ifndef select.h
#define select.h
#define INIT_SIZE 50
#define INCRE_SIZE 10
/*路径中单元格的结构体*/
typedef struct{
	int ord;
	int floor;
	int x;
	int y;
	int di;
	int di_num;//记录该步换的方向数量
}UNIT;

/*存储路径的栈*/
typedef struct{
	UNIT *base;//底
	UNIT *top;//顶
	int size;//当前分配大小
	int totalstep;//步数
}STACK;

extern void InitStack(STACK *S);

extern void Push(STACK *S,UNIT e);

extern void Pop(STACK *S,UNIT *e);

extern int StackEmpty(STACK *S);

extern void DestroyStack(STACK *S);

extern void ClearStack(STACK *S);

extern int FindSame(int x,int y,char (*p)[19]);

extern int FindWay(int f,int x0,int y0,int xt,int yt,STACK *S);



#endif