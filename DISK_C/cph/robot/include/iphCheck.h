#ifndef iphCheck.h
#define iphCheck.h

// �ֻ���֤���¼



/**************************************************
function:        checkin

description:     ��֤��������߼�,��ʵ����֤�뵯���������ֻ����뼰��֤�룬�����¼���ȡ��֤��

Input:           void

output:             
**************************************************************/
extern int checkin(int* x, int* y); 

/**************************************************
function:        checkin_interface

description:     ��Ӧ�õ�¼����

Input:           void

output:          
**************************************************************/
extern void checkin_interface();

/**************************************************
function:        checkin_click

description:     ������߼�������ÿһ�����������һ������ֵ

Input:           int mx,int my,int button

output:          
**************************************************************/
extern int checkin_click(int *mx,int *my,int button);



#endif