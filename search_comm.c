#include "mms.h"

void search_comm(char *name,int ver)
{
system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****�ؼ��ֲ�ѯ��Ʒ****");
     goToXY(24,10);
     printf("������ؼ���:");
     char key[15];
     scanf("%s",key);
     FILE *file = fopen(PRODUCT,"ab+");
     FILE *file_copy;
     file_copy = fopen("copy1.dat","w");
     struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&comm,sizeof(struct commodity),1,file);
         if(result != 0){
             if(strstr(comm.name,key)!=NULL){
                 fwrite(&comm,sizeof(struct commodity),1,file_copy);
             }
         }
     }
     fclose(file);
     fclose(file_copy);
     show_page("copy1.dat","��Ʒ��Ϣ",name,ver);
}
