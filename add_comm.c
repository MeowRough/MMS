#include "mms.h"

void add_comm(char *name)
{
    system("cls");
    drawBorder();

    struct commodity comm = {0,"",0.0,0.0,"",0,"",0,""};

    goToXY(28,3);
    printf("****��������Ʒ��Ϣ****");
    goToXY(20,9);
    printf("��Ʒ��ţ�");
    goToXY(20,10);
    printf("��Ʒ���ƣ�");
    goToXY(20,11);
    printf("���ۣ�");
    goToXY(20,12);
    printf("�ۼۣ�");
    goToXY(20,13);
    printf("��Ʒ������");
    goToXY(20,14);
    printf("�������");
    goToXY(20,15);
    printf("���");
    goToXY(20,16);
    printf("��������");
    goToXY(20,17);
    printf("�����̣�");


    goToXY(31,9);
    scanf("%d",&comm.num);
    goToXY(31,10);
    scanf("%s",comm.name);
    goToXY(27,11);
    scanf("%lf",&comm.in_price);
    goToXY(27,12);
    scanf("%lf",&comm.out_price);
    goToXY(31,13);
    scanf("%s",comm.desc);
    goToXY(29,14);
    scanf("%d",&comm.count);
    goToXY(27,15);
    scanf("%s",comm.sort);
    goToXY(29,16);
    scanf("%d",&comm.sold);
    goToXY(29,17);
    scanf("%s",comm.provider);





        FILE *file;
        file = fopen(PRODUCT,"ab+");
        fwrite(&comm,sizeof(struct commodity),1,file);
        fclose(file);

        int choice;

        while(TRUE){
            system("cls");
            drawBorder();
            goToXY(20,9);
            printf("�Ƿ���������Ʒ��������Yes/No:");
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
                add_comm(name);
                break;

            case 0:
                system("cls");
                admin_main(name);

        }


}
