#include "mms.h"

void admin_login_login(){
    char login_name[20];
    char login_pass[20];

    drawBorder();
    goToXY(30,3);
    printf("****����Ա��½****");
    goToXY(25,8);
    printf("�ǳƣ�");
    goToXY(25,9);
    printf("���룺");

    goToXY(31,8);
    scanf("%s",login_name);
    goToXY(31,9);
    i=0;
     char pw;
     pw=getch();
     while(pw != 13){
         if(pw == 8){if(i!=0) {printf("%c %c",pw,pw);i--;}}
         else if(i==20&&pw!=8) {}
         else{
             printf("*");
             login_pass[i] = pw;
             i++;
         }
         pw = getch();
     }
     login_pass[i]='\0';



    //��֤�˻�
    int correct = 0;//��֤״̬
    struct user vertify = {"","","","","",""};
    FILE *file = fopen("user_1.dat","ab+");
    rewind(file);
    while(!feof(file)){
        int result = fread(&vertify,sizeof(struct user),1,file);
        if(result != 0){
            if((!strcmp(vertify.name,login_name))&&(!strcmp(vertify.pass,login_pass))){
                correct = 1;
                break;
            }
        }
    }
    fclose(file);

    //progressBar("ϵͳ������֤���ĵ�¼��Ϣ�����Ժ�");
    system("cls");
    if(correct == 1){
        system("cls");
        admin_main(login_name);
    }else if(correct == 0){
        system("cls");
        drawBorder();
        goToXY(30,9);
        printf("�û�����%s",login_name);
        goToXY(23,11);
        printf("�û�����������󣬰������������");
        getch();
        system("cls");
        admin_login();
    }

}
