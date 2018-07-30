#include "mms.h"

void receive_mes(char *name){

     system("cls");
     drawBorder();
     //goToXY(23,3);
     //printf("****这里存放着%d封用户反馈的信息！****",count_mes());
     show_page(MES,"用户反馈",name,1);

 }
