#include "mms.h"

void admin_login(){
    int state = 0;//0��ʾע�ᣬ1��ʾ��½
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("��ѡ���¼��ע�᣺");
    goToXY(26,12);
    printf("��  ��  ����Աע��");
    goToXY(26,14);
    printf("��      ����Ա��½");
    goToXY(26,16);
    printf("��      �˳�");

    while(TRUE){
        char choice;
        choice = getch();
        if(choice == 72){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == 80){

            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");

        }else if(choice == '\r'){
            switch(state){
                case 0:
                    system("cls");
                    drawBorder();
                    admin_register();
                    break;
                case 1:
                    system("cls");
                    drawBorder();
                    admin_login_login();
                    break;
                case 2:
                    system("cls");
                    start();
                    break;
            }
        }
    }
    getchar();
}
