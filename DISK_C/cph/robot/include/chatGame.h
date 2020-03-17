#ifndef chatGame.h
#define chatGame.h

/**************************************************
function:        void show_gg(char *temp);

description:     退出字谜游戏要说的最后一句话

Input:           char *temp

output:         
**************************************************************/
extern void show_gg(char *temp);

/**************************************************
function:        int question_generator(char **question,char **answer);

description:     生成题目,返回已经考过的题号

Input:           char **question,char **answer，记录题目和问题

output:          int 传回采用的题号，对于之后的重复性检测
**************************************************************/
extern int question_generator(char *question,char *answer);

/**************************************************
function:        int check_answer(char *incode,char *answer);

description:     检查是不是答案，是的话返回1

Input:           char *incode,char *answer

output:         int 判断是否是答案的bool值
**************************************************************/
extern int check_answer(char *incode,char *answer);

/**************************************************
function:        void word_game(void);

description:     字谜部分，输入“我不玩了”即可退出游戏

Input:           void

output:          void
**************************************************************/
extern void word_game(unsigned int *box_save);

#endif