#include "mms.h"

void page_down(char *file_name,char *str,int num,char *name,int ver){
    int nums = 0;//����
    system("cls");
    drawBorder();
    goToXY(25,2);
    printf("****�����ǲ�ѯ����%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");


    if(!strcmp(file_name,PRODUCT) || !strcmp(file_name,"copy1.dat") || !strcmp(file_name,"select.dat")){
        if(ver == 1){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
                    int result = fread(&comm,sizeof(struct commodity),1,file);
                    if(result == 1){
                        goToXY(6,4+3*i);
                        printf("%d",comm.num);
                        goToXY(15,4+3*i);
                        printf("%s",comm.name);
                        goToXY(25,4+3*i);
                        printf("%s",comm.desc);
                        goToXY(33,4+3*i);
                        printf("%s",comm.sort);
                        goToXY(42,4+3*i);
                        printf("%s",comm.provider);
                        goToXY(50,4+3*i);
                        printf("%d",comm.sold);
                        goToXY(56,4+3*i);
                        printf("%d",comm.count);
                        goToXY(63,4+3*i);
                        printf("%.1lf",comm.in_price);
                        goToXY(68,4+3*i);
                        printf("%.1lf",comm.out_price);
                    }else{
                        break;
                    }
                }
        }else if(ver == 2){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t\t������\t��Ʒ�۸�");
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
        }
    }else if(!strcmp(file_name,MES)){
        fseek(file,sizeof(struct message)*5*num,SEEK_SET);
        struct message mes = {"","","",""};
        goToXY(6,4);
        printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
            for(i = 1;i < 6;i ++){
                int result = fread(&mes,sizeof(struct message),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",mes.name);
                    goToXY(25,4+3*i);
                    printf("%s",mes.content);
                    goToXY(49,4+3*i);
                    printf("%s",mes.contract);
                    goToXY(65,4+3*i);
                    printf("%s",mes.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp.dat")){
        fseek(file,sizeof(struct record)*5*num,SEEK_SET);
        struct record rec = {"","",0,""};
        goToXY(6,4);
        printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
        for(i = 1;i < 6;i ++){
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(65,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp_1.dat")){
        if(ver == 1){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
                    int result = fread(&comm,sizeof(struct commodity),1,file);
                    if(result == 1){
                        goToXY(6,4+3*i);
                        printf("%d",comm.num);
                        goToXY(15,4+3*i);
                        printf("%s",comm.name);
                        goToXY(25,4+3*i);
                        printf("%s",comm.desc);
                        goToXY(33,4+3*i);
                        printf("%s",comm.sort);
                        goToXY(42,4+3*i);
                        printf("%s",comm.provider);
                        goToXY(50,4+3*i);
                        printf("%d",comm.sold);
                        goToXY(56,4+3*i);
                        printf("%d",comm.count);
                        goToXY(63,4+3*i);
                        printf("%.1lf",comm.in_price);
                        goToXY(68,4+3*i);
                        printf("%.1lf",comm.out_price);
                    }else{
                        break;
                    }
                }
        }else if(ver == 2){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t\t������\t��Ʒ�۸�");
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
        }

    }
    fclose(file);
    char choice = getch();
    switch(choice){
        case 110://N��
            num++;
            page_down(file_name,str,num,name,ver);
            break;
        case 112://P��
            num--;
            if(num < 0){
                num = 0;
            }
            page_up(file_name,str,num,name,ver);
            break;
        case 27:
            system("cls");
            switch(ver){
                case 1:
                    admin_main(name);
                    break;
                case 2:
                    cus_main(name);
                    break;
            }
            break;
    }
}
