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
                printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
                goToXY(26,6);
                printf("��  ��  �ǳ�");
                goToXY(26,8);
                printf("��      �Ա�");
                goToXY(26,10);
                printf("��      ����");
                goToXY(26,12);
                printf("��      �ֻ���");
                goToXY(26,14);
                printf("��      ����");

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
                        printf("��");
                    }
                    else if(choice == 80){
                        goToXY(30,6+state*2);
                        printf("\b  ");
                        state += 1;
                        if(state == 5){
                            state = 0;
                        }
                        goToXY(30,6+state*2);
                        printf("��");
                    }else if(choice == '\r'){
                        system("cls");
                        drawBorder();
                        goToXY(24,10);
                        printf("��������Ҫ�޸ĵ���Ϣ��");
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
     progressBar("���ڸ��ĸ�����Ϣ�����Ժ�");
     system("cls");
     drawBorder();
     goToXY(25,11);
     printf("������Ϣ�޸ĳɹ����������������");
     getch();
     system("cls");
     if(ver == 1)
        admin_login_login();
     else if(ver == 2)
        cus_login_login();

}
