#include "mms.h"

void buy_product(char *name){
     int state = 0;//��ʾ��ѯ��Ʒʱ��״̬
     int buy_code;
     int buy_count;
     system("cls");
     drawBorder();
     goToXY(23,3);
     printf("****��Ʒѡ��ҳ��,�ڴ������Ĺ��٣�****");
     goToXY(20,6);
     printf("��������Ҫ��������Ʒ��ţ�");

     goToXY(20,6);
     printf("��������Ҫ��������Ʒ��ţ�");
     scanf("%d",&buy_code);
     progressBar("���ڼ������ݿ⣬���Ժ�");

     FILE *file = fopen(PRODUCT,"ab+");
     struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&comm,sizeof(struct commodity),1,file);
         if((result == 1)&&(buy_code == comm.num)){
             state = 1;
             break;
         }
     }
     fclose(file);
     if(state == 1){
         goToXY(25,8);
         printf("��Ʒ��ţ�%d",comm.num);
         goToXY(25,9);
         printf("��Ʒ���ƣ�%s",comm.name);
         goToXY(25,10);
         printf("��Ʒ������%s",comm.desc);
         goToXY(25,11);
         printf("��Ʒ���%s",comm.sort);
         goToXY(25,12);
         printf("��Ʒ�����̣�%s",comm.provider);
         goToXY(25,13);
         printf("��Ʒ�ۼۣ�%.1lf",comm.out_price);
         goToXY(18,16);
         printf("��������Ҫ�������Ʒ������");
         scanf("%d",&buy_count);
         progressBar("ϵͳ���ڽ��㣬���Ժ�");

         FILE *file = fopen(BUY_RECORD,"ab+");
         struct record rec = {"","",0,""};
         strcpy(rec.name,name);
         strcpy(rec.product,comm.name);
         rec.quantity = buy_count;
         char date[10];
         time_t timep;
         struct tm *p;
         time (&timep);
         p=gmtime(&timep);
         sprintf(date,"%d-%d-%d",p->tm_year + 1900,p->tm_mon + 1,p->tm_mday);
         strcpy(rec.date,date);
         fwrite(&rec,sizeof(struct record),1,file);
         fclose(file);
         system("cls");
         drawBorder();
         goToXY(25,11);
         printf("ѡ����Ʒ�Ѿ�����ɹ����������������");
         getch();
         system("cls");
         cus_main(name);
     }else if(state == 0){
         goToXY(18,8);
         printf("��ʱδ����������Ҫ���ҵ���Ʒ�����ڴ������ϼܣ�");
         goToXY(28,14);
         printf("�������������");
         getch();
         system("cls");
         cus_main(name);
     }

 }
