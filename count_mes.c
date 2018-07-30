#include "mms.h"

int count_mes(){
     int count = 0;
     FILE *file = fopen(MES,"ab+");
     struct message mes = {"","","",""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&mes,sizeof(struct message),1,file);
         if(result != 0){
             count ++;
         }
     }
     fclose(file);
     return count;
 }
