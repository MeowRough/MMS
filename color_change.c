#include "mms.h"

void color_change(char *name){
     int state = 0;
     system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****���Ľ�����ɫ****");
     goToXY(26,8);
     printf("��  ��  �׵׺���(��ϵͳĬ������)");
     goToXY(26,10);
     printf("��      �������");
     goToXY(26,12);
     printf("��      �ڵ׺���");
     goToXY(26,14);
     printf("��      �̵�����");
     goToXY(26,16);
     printf("��      �ڵ�����");
     goToXY(26,18);
     printf("��      �̵װ���");
     goToXY(26,20);
     printf("��      �˳���������ɫ����");
     while(TRUE){
         char choice;
         choice = getch();
         if(choice == 72){
             goToXY(30,8+state*2);
             printf("\b  ");
             state -= 1;
             if(state == -1){
                 state = 6;
             }
             goToXY(30,8+state*2);
             printf("��");
         }
         else if(choice == 80){
             goToXY(30,8+state*2);
             printf("\b  ");
             state += 1;
             if(state == 7){
                 state = 0;
             }
             goToXY(30,8+state*2);
             printf("��");
         }else if(choice == '\r'){
             switch(state){
                 case 0:
                     system("color F0");
                     break;
                 case 1:
                     system("color 40");
                     break;
                 case 2:
                     system("color 04");
                     break;
                 case 3:
                     system("color 21");
                     break;
                 case 4:
                     system("color 0A");
                     break;
                 case 5:
                     system("color 3f");
                     break;
                 case 6:
                     system("cls");
                     admin_main(name);
                     break;
             }
         }
     }
     getchar();
 }
