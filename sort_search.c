#include "mms.h"

void sort_search(char *name,int ver){
    remove("tmp_1.dat");
    int state = 0;
    system("cls");
    drawBorder();
    char input[20];
    goToXY(23,3);
    printf("****分类查询页面,个性化您的查询！****");
    goToXY(20,7);
    printf("情输入您要查询的商品类别：");
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
    progressBar("系统正在对该类别信息进行查询，请稍候！");
    if(state == 0){
        system("cls");
        drawBorder();
        goToXY(18,11);
        printf("您所查询的商品类别不存在，按任意键返回主界面！");
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
        show_page("tmp_1.dat","分类商品",name,ver);
    }
}
