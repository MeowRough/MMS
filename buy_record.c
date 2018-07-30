#include "mms.h"

void buy_record(char *name){
     system("cls");
     drawBorder();
     remove("tmp.dat");
     FILE *file = fopen(BUY_RECORD,"ab+");
     FILE *file_tmp = fopen("tmp.dat","ab+");

     struct record rec = {"","",0,""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&rec,sizeof(struct record),1,file);
         if(result != 0){
             if(!strcmp(name,rec.name)){
                 fwrite(&rec,sizeof(struct record),1,file_tmp);
             }
         }
     }

     fclose(file);
     fclose(file_tmp);

     show_page("tmp.dat","购买记录",name,2);
 }
