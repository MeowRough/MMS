#include "mms.h"

void del_comm(char *name){
     system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****ɾ����Ʒ��Ϣ****");
     goToXY(24,10);
     printf("������Ҫɾ������Ʒ���:");
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
     progressBar("����ɾ����Ʒ�����Ժ�");
     system("cls");
     drawBorder();
     goToXY(30,9);
     printf("��Ʒ��ţ�%d",del_num);
     goToXY(25,11);
     printf("��Ʒɾ���ɹ����������������");
     getch();
     system("cls");
     admin_main(name);


 }
