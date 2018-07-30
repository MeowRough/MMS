#include "mms.h"

void info_change(char *name,int ver)
{
     FILE *file;
     if(ver == 1){
        file = fopen(USER_1,"ab+");
     }
    else if(ver == 2){
        file = fopen(USER_2,"ab+");
    }
    FILE *file_copy = fopen("copy.dat","ab+");
     struct user use = {"","","","","",""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&use,sizeof(struct user),1,file);
         if(result != 0){
             if(strcmp(use.name,name)){
                fwrite(&use,sizeof(struct user),1,file_copy);
             }
             if(!strcmp(use.name,name)){
                system("cls");
                int state = 0;
                drawBorder();
                goToXY(24,3);
                printf("请选择您要修改的信息：");
                goToXY(26,6);
                printf("①  ★  昵称");
                goToXY(26,8);
                printf("②      性别");
                goToXY(26,10);
                printf("③      邮箱");
                goToXY(26,12);
                printf("④      手机号");
                goToXY(26,14);
                printf("⑤      密码");

                while(TRUE){
                    char choice;
                    choice = getch();
                    if(choice == 72){
                        goToXY(30,6+state*2);
                        printf("\b  ");
                        state -= 1;
                        if(state == -1){
                            state = 4;
                        }
                        goToXY(30,6+state*2);
                        printf("★");
                    }
                    else if(choice == 80){
                        goToXY(30,6+state*2);
                        printf("\b  ");
                        state += 1;
                        if(state == 5){
                            state = 0;
                        }
                        goToXY(30,6+state*2);
                        printf("★");
                    }else if(choice == '\r'){
                        system("cls");
                        drawBorder();
                        goToXY(24,10);
                        printf("请输入你要修改的信息：");
                        switch(state){
                            case 0:
                                scanf("%s",use.name);
                                break;

                            case 1:
                                scanf("%s",use.sex);
                                break;

                            case 2:
                                scanf("%s",use.mail);
                                break;

                            case 3:
                                scanf("%s",use.phone);
                                break;

                            case 4:
                                scanf("%s",use.pass);
                                strcpy(use.pass_double,use.pass);
                                break;
                        }
                        fwrite(&use,sizeof(struct user),1,file_copy);
                        break;
                    }
                }
            }
        }
    }

     fclose(file);
     fclose(file_copy);
     if(ver == 1){
        remove(USER_1);
        rename("copy.dat",USER_1);
     }
     else if(ver == 2){
        remove(USER_2);
        rename("copy.dat",USER_2);
     }
     progressBar("正在更改个人信息，请稍后！");
     system("cls");
     drawBorder();
     goToXY(25,11);
     printf("个人信息修改成功，按任意键继续！");
     getch();
     system("cls");
     if(ver == 1)
        admin_login_login();
     else if(ver == 2)
        cus_login_login();

}
