#include "mms.h"

void change_comm(char *name)
{
    system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****修改商品信息****");
     goToXY(24,10);
     printf("请输入要修改的商品编号:");
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
                                printf("请选择您要修改的信息：");
                                goToXY(26,6);
                                printf("①  ★  进价");
                                goToXY(26,8);
                                printf("②      售价");
                                goToXY(26,10);
                                printf("③      商品描述");
                                goToXY(26,12);
                                printf("④      库存");
                                goToXY(26,14);
                                printf("⑤      类别");
                                goToXY(26,16);
                                printf("⑥      销售量");
                                goToXY(26,18);
                                printf("⑦      生产商");

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
                                        printf("★");
                                    }
                                    else if(choice == 80){
                                        goToXY(30,6+state*2);
                                        printf("\b  ");
                                        state += 1;
                                        if(state == 7){
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
     progressBar("正在更改商品信息，请稍后！");
     system("cls");
     drawBorder();
     goToXY(30,9);
     printf("商品编号：%d",change_num);
     goToXY(25,11);
     printf("商品修改成功，按任意键继续！");
     getch();
     system("cls");

     int choice;

        while(TRUE){
            system("cls");
            drawBorder();
            goToXY(20,9);
            printf("是否继续修改商品信息？请输入Yes/No:");
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
            printf("输入错误！");
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
