#include "mms.h"

void send_mes(char *name){
     struct message mes = {"","","",""};
     system("cls");
     drawBorder();
     goToXY(23,3);
     printf("****������Ϣҳ��,�ڴ�������������****");
     goToXY(15,8);
     printf("�����뷴����Ϣ��");
     goToXY(10,10);
     printf("������������ϵ��ʽ���Ա���������ȡ����ϵ��");
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
     printf("�Ѿ��յ��������ţ������ڴ����õ����ǣ�");
     goToXY(29,19);
     printf("����������������棡");
     getch();
     system("cls");
     cus_main(name);
 }
