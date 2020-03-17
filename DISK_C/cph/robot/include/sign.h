#ifndef sign.h
#define sign.h

extern int input_account(USERS *head,char *account,char *code,int *x,int *y);

extern int input_code(USERS *head,char *account,char *code,int *x,int *y);

extern int RegisteraccountsInput(char *account, int *mx, int *my);

extern int RegistercodeInput(char *code, int *mx, int *my);

extern int RegistersecondcodeInput(char *secondcode, int *mx, int *my);

extern int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *button);

extern int sign_in_check(USERS *head,char *account,char *code);

#endif