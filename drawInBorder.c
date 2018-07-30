#include "mms.h"

void drawInBorder(){
     goToXY(5,2);
     for(i = 0;i < 40;i++){
         if(i == 20){
             goToXY(54,2);
         }
         printf("*");
     }
     for(i = 1;i < 7;i++){
         goToXY(5,2+3*i);
         for(j = 0;j < 70;j++){
             printf("-");
         }
     }

 }
