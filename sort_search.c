#include "mms.h"

void sort_search(char *name,int ver){
    remove("tmp_1.dat");
    int state = 0;
    system("cls");
    drawBorder();
    char input[20];
    goToXY(23,3);
    printf("****�����ѯҳ��,���Ի����Ĳ�ѯ��****");
    goToXY(20,7);
    printf("��������Ҫ��ѯ����Ʒ���");
    scanf("%s",input);
    FILE *file_tmp = fopen("tmp_1.dat","ab+");
    FILE *file = fopen(PRODUCT,"ab+");
    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if((result == 1)&&(!strcmp(comm.sort,input))){
            fwrite(&comm,sizeof(struct commodity),1,file_tmp);
            state = 1;
        }
    }
    fclose(file);
    fclose(file_tmp);
    progressBar("ϵͳ���ڶԸ������Ϣ���в�ѯ�����Ժ�");
    if(state == 0){
        system("cls");
        drawBorder();
        goToXY(18,11);
        printf("������ѯ����Ʒ��𲻴��ڣ�����������������棡");
        getch();
        switch(ver){
            case 1:
                system("cls");
                admin_main(name);
                break;
            case 2:
                system("cls");
                cus_main(name);
                break;
        }
    }else if(state == 1){
        show_page("tmp_1.dat","������Ʒ",name,ver);
    }
}
