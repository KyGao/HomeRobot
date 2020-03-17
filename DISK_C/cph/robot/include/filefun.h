#ifndef filefun.h
#define filefun.h

extern void CreateUserList(USERS *head);

extern void AddNewUser(USERS *head,char *s1,char *s2);

extern char *SearchAccounts(USERS *head,char *string);

extern void freeUserlist(USERS **head);
#endif