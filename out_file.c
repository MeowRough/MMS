#include "mms.h"

void out_file(char *name,int ver){
    if(ver == 1){
        FILE *file_out = fopen("��Ϣ����_����Ա.txt","w");
        FILE *file = fopen(PRODUCT,"ab+");
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
        while(!feof(file)){
            char info[100];
            int result = fread(&comm,sizeof(struct commodity),1,file);
            if(result == 1){
                sprintf(info,"��Ʒ��ţ�%d\t��Ʒ���ƣ�%s\t��Ʒ������%s\t��Ʒ���%s\t��Ʒ�����̣�%s\t��������%d\t�������%d\t���ۣ�%.1lf\t�ۼۣ�%.1lf\n",comm.num,comm.name,comm.desc,comm.sort,comm.provider,comm.sold,comm.count,comm.in_price,comm.out_price);
                fputs(info,file_out);
            }
        }
        fclose(file);
        fclose(file_out);
        system("cls");
        drawBorder();
        progressBar("���ڽ�ϵͳ��Ʒ����ת��Ϊ�ļ������Ժ�");
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("��Ʒ��Ϣ�����ɹ����������������");
        getch();
        system("cls");
        admin_main(name);
    }else if(ver == 2){
        FILE *file_out = fopen("��Ϣ����_�˿��û�.txt","w");
        FILE *file = fopen(PRODUCT,"ab+");
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
        while(!feof(file)){
            char info[100];
            int result = fread(&comm,sizeof(struct commodity),1,file);
            if(result == 1){
                sprintf(info,"��Ʒ��ţ�%d\t��Ʒ���ƣ�%s\t��Ʒ������%s\t��Ʒ���%s\t��Ʒ�����̣�%s\t��Ʒ��������%d\t��Ʒ�ۼۣ�%.1lf\n",comm.num,comm.name,comm.desc,comm.sort,comm.provider,comm.sold,comm.out_price);
                fputs(info,file_out);
            }
        }
        fclose(file);
        fclose(file_out);
        system("cls");
        drawBorder();
        progressBar("���ڽ�ϵͳ��Ʒ����ת��Ϊ�ļ������Ժ�");
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("��Ʒ��Ϣ�����ɹ����������������");
        getch();
        system("cls");
        cus_main(name);
    }
}
