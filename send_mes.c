#include "mms.h"

void send_mes(char *name){
     struct message mes = {"","","",""};
     system("cls");
     drawBorder();
     goToXY(23,3);
     printf("****反馈信息页面,期待着您的声音！****");
     goToXY(15,8);
     printf("请输入反馈信息：");
     goToXY(10,10);
     printf("请输入您的联系方式，以便我们与您取得联系：");
     goToXY(31,8);
     scanf("%s",mes.content);
     goToXY(52,10);
     scanf("%s",mes.contract);
     strcpy(mes.name,name);
     char date[10];
     time_t timep;
     struct tm *p;
     time (&timep);
     p=gmtime(&timep);
     sprintf(date,"%d-%d-%d",p->tm_year + 1900,p->tm_mon + 1,p->tm_mday);
     strcpy(mes.date,date);
     FILE *file = fopen(MES,"ab+");
     fwrite(&mes,sizeof(struct message),1,file);
     fclose(file);
     goToXY(22,18);
     printf("已经收到您的来信，请您期待更好的我们！");
     goToXY(29,19);
     printf("按任意键返回主界面！");
     getch();
     system("cls");
     cus_main(name);
 }
