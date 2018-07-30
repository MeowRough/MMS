#include "mms.h"

void start(){
    int state = 0;//保存用户的身份选择信息，0为管理员，1为顾客
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("请选择您的身份进行登录或注册：");
    goToXY(26,12);
    printf("①  ★  超市管理员");
    goToXY(26,14);
    printf("②      顾客");
    goToXY(26,16);
    printf("③      退出系统");

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
            printf("★");
        }
        else if(choice == 80){
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("★");
        }else if(choice == '\r'){
            switch(state){
                case 0:
                    progressBar("系统正在加载，请稍候！");
                    Sleep(100);
                    system("cls");
                    admin_login();
                    break;

                case 1:
                    system("cls");
                    cus_login();
                    break;
                case 2:
                    system("cls");
                    drawBorder();
                    goToXY(28,11);
                    printf("感谢您的使用，再见！");
                    goToXY(0,24);
                    exit(0);
            }
        }
    }
    getchar();
}
