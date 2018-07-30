#include "mms.h"

void cus_login(){
    int state = 0;//0±íÊ¾×¢²á£¬1±íÊ¾µÇÂ½
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("ÇëÑ¡ÔñµÇÂ¼»ò×¢²á£º");
    goToXY(26,12);
    printf("¢Ù  ¡ï  ¹Ë¿Í×¢²á");
    goToXY(26,14);
    printf("¢Ú      ¹Ë¿ÍµÇÂ½");
    goToXY(26,16);
    printf("¢Û      ÍË³ö");


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
            printf("¡ï");
        }
        else if(choice == 80){
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("¡ï");
        }else if(choice == '\r'){
            switch(state){
                case 0:
                    system("cls");
                    drawBorder();
                    cus_register();
                    break;

                case 1:
                    system("cls");
                    drawBorder();
                    cus_login_login();
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
