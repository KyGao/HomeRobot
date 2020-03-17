#ifndef myhouse.h
#define myhouse.h
/*房间中环境信息的结构体*/
typedef struct{
	int win;
	int aircon[3];
	int weedx[3];
	int weedy[3];
	int PM1;
	int T;
	int H;
	char trash;//场面上有无垃圾
	int trashx[3];
	int trashy[3];
	int trashbin[3];//垃圾桶内垃圾数量
	int battery;
	int battery_on;
}ENVIR;


extern int CheckMove(int x,int y,int floor);

extern void CreateHouseFile();

extern int CheckCarry(int x,int y,int floor);

extern void ChangeCarry(int x,int y,int floor,int change);

extern void ChangeMove(int x,int y,int floor,int change);

extern int CheckHouse(int check);

extern void ChangeHouse(int check,int change);

extern void ShowFile();
#endif 