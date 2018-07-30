#include "mms.h"

void show_page(char *file_name,char *str,char *name,int ver){
    int page_num = 0;//记录当前的翻页数
    system("cls");
    drawBorder();
    goToXY(25,2);
    printf("****以下是查询到的%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");

    if(!strcmp(file_name,PRODUCT) || !strcmp(file_name,"copy1.dat") || !strcmp(file_name,"select.dat")){
        if(ver == 1){
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("商品编号 商品名称 商品描述 商品类别 生产商 销售量 库存量 进价 售价");
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
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("商品编号\t商品名称\t商品描述\t\t生产商\t商品价格");
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
        struct message mes = {"","","",""};
            goToXY(6,4);
            printf("反馈用户昵称\t反馈内容\t\t联系方式\t反馈日期");
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
        struct record rec = {"","",0,""};
        goToXY(6,4);
        printf("购买用户昵称\t商品名称\t\t商品件数\t购买日期");
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
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("商品编号 商品名称 商品描述 商品类别 生产商 销售量 库存量 进价 售价");
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
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("商品编号\t商品名称\t商品描述\t\t生产商\t商品价格");
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
        case 110://N键
            page_num++;
            page_down(file_name,str,page_num,name,ver);
            break;
        case 112://P键
            page_num--;
            if(page_num < 0){
                page_num = 0;
            }
            page_up(file_name,str,page_num,name,ver);
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
