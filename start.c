#include "mms.h"

void start(){
    int state = 0;//�����û������ѡ����Ϣ��0Ϊ����Ա��1Ϊ�˿�
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("��ѡ��������ݽ��е�¼��ע�᣺");
    goToXY(26,12);
    printf("��  ��  ���й���Ա");
    goToXY(26,14);
    printf("��      �˿�");
    goToXY(26,16);
    printf("��      �˳�ϵͳ");

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
                    progressBar("ϵͳ���ڼ��أ����Ժ�");
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
                    printf("��л����ʹ�ã��ټ���");
                    goToXY(0,24);
                    exit(0);
            }
        }
    }
    getchar();
}
