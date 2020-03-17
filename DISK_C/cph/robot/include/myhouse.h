#ifndef myhouse.h
#define myhouse.h
/*�����л�����Ϣ�Ľṹ��*/
typedef struct{
	int win;
	int aircon[3];
	int weedx[3];
	int weedy[3];
	int PM1;
	int T;
	int H;
	char trash;//��������������
	int trashx[3];
	int trashy[3];
	int trashbin[3];//����Ͱ����������
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