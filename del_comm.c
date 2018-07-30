#include "mms.h"

void del_comm(char *name){
     system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****删除商品信息****");
     goToXY(24,10);
     printf("请输入要删除的商品编号:");
     scanf("%d",&del_num);
     FILE *file = fopen(PRODUCT,"ab+");
     FILE *file_copy = fopen("copy.dat","ab+");
     struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&comm,sizeof(struct commodity),1,file);
         if(result != 0){
             if(comm.num != del_num){
                 fwrite(&comm,sizeof(struct commodity),1,file_copy);
             }
         }
     }
     fclose(file);
     fclose(file_copy);
     remove(PRODUCT);
     rename("copy.dat",PRODUCT);
     progressBar("正在删除商品，请稍后！");
     system("cls");
     drawBorder();
     goToXY(30,9);
     printf("商品编号：%d",del_num);
     goToXY(25,11);
     printf("商品删除成功，按任意键继续！");
     getch();
     system("cls");
     admin_main(name);


 }
