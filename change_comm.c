#include "mms.h"

void change_comm(char *name)
{
    system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****�޸���Ʒ��Ϣ****");
     goToXY(24,10);
     printf("������Ҫ�޸ĵ���Ʒ���:");
     scanf("%d",&change_num);
     FILE *file = fopen(PRODUCT,"ab+");
     FILE *file_copy = fopen("copy.dat","ab+");
     struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&comm,sizeof(struct commodity),1,file);
         if(result != 0){
             if(comm.num != change_num){
                fwrite(&comm,sizeof(struct commodity),1,file_copy);
             }
             if(comm.num == change_num){


                                system("cls");
                                int state = 0;
                                drawBorder();
                                goToXY(24,3);
                                printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
                                goToXY(26,6);
                                printf("��  ��  ����");
                                goToXY(26,8);
                                printf("��      �ۼ�");
                                goToXY(26,10);
                                printf("��      ��Ʒ����");
                                goToXY(26,12);
                                printf("��      ���");
                                goToXY(26,14);
                                printf("��      ���");
                                goToXY(26,16);
                                printf("��      ������");
                                goToXY(26,18);
                                printf("��      ������");

                                while(TRUE){
                                    char choice;
                                    choice = getch();
                                    if(choice == 72){
                                        goToXY(30,6+state*2);
                                        printf("\b  ");
                                        state -= 1;
                                        if(state == -1){
                                            state = 6;
                                        }
                                        goToXY(30,6+state*2);
                                        printf("��");
                                    }
                                    else if(choice == 80){
                                        goToXY(30,6+state*2);
                                        printf("\b  ");
                                        state += 1;
                                        if(state == 7){
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
                                                scanf("%lf",&comm.in_price);
                                                break;

                                            case 1:
                                                scanf("%lf",&comm.out_price);
                                                break;

                                            case 2:
                                                scanf("%s",comm.desc);
                                                break;

                                            case 3:
                                                scanf("%d",&comm.count);
                                                break;

                                            case 4:
                                                scanf("%s",comm.sort);
                                                break;

                                            case 5:
                                                scanf("%d",&comm.sold);
                                                break;

                                            case 6:
                                                scanf("%s",comm.provider);
                                                break;
                                        }
                                        fwrite(&comm,sizeof(struct commodity),1,file_copy);
                                        break;
                                    }
                                }
                            }

                }
         }

     fclose(file);
     fclose(file_copy);
     remove(PRODUCT);
     rename("copy.dat",PRODUCT);
     progressBar("���ڸ�����Ʒ��Ϣ�����Ժ�");
     system("cls");
     drawBorder();
     goToXY(30,9);
     printf("��Ʒ��ţ�%d",change_num);
     goToXY(25,11);
     printf("��Ʒ�޸ĳɹ����������������");
     getch();
     system("cls");

     int choice;

        while(TRUE){
            system("cls");
            drawBorder();
            goToXY(20,9);
            printf("�Ƿ�����޸���Ʒ��Ϣ��������Yes/No:");
            char y_n[4];
            gets(y_n);
            if(!strcmp(y_n,"Yes")){
                choice = 1;
                break;
            }
            else if(!strcmp(y_n,"No")){
                choice = 0;
                break;
            }
            else
            printf("�������");
        }

        switch(choice)
        {
            case 1:
                change_comm(name);
                break;

            case 0:
                system("cls");
                admin_main(name);

        }
}
