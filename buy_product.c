#include "mms.h"

void buy_product(char *name){
     int state = 0;//表示查询商品时的状态
     int buy_code;
     int buy_count;
     system("cls");
     drawBorder();
     goToXY(23,3);
     printf("****商品选购页面,期待着您的光临！****");
     goToXY(20,6);
     printf("请输入您要搜索的商品编号：");

     goToXY(20,6);
     printf("请输入您要搜索的商品编号：");
     scanf("%d",&buy_code);
     progressBar("正在检索数据库，请稍候！");

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
         printf("商品编号：%d",comm.num);
         goToXY(25,9);
         printf("商品名称：%s",comm.name);
         goToXY(25,10);
         printf("商品描述：%s",comm.desc);
         goToXY(25,11);
         printf("商品类别：%s",comm.sort);
         goToXY(25,12);
         printf("商品生产商：%s",comm.provider);
         goToXY(25,13);
         printf("商品售价：%.1lf",comm.out_price);
         goToXY(18,16);
         printf("请输入您要购买的商品件数：");
         scanf("%d",&buy_count);
         progressBar("系统正在结算，请稍候！");

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
         printf("选购商品已经购买成功，按任意键继续！");
         getch();
         system("cls");
         cus_main(name);
     }else if(state == 0){
         goToXY(18,8);
         printf("暂时未能搜索到你要查找的商品，请期待它的上架！");
         goToXY(28,14);
         printf("按任意键继续！");
         getch();
         system("cls");
         cus_main(name);
     }

 }
