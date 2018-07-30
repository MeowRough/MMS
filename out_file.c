#include "mms.h"

void out_file(char *name,int ver){
    if(ver == 1){
        FILE *file_out = fopen("信息导出_管理员.txt","w");
        FILE *file = fopen(PRODUCT,"ab+");
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
        while(!feof(file)){
            char info[100];
            int result = fread(&comm,sizeof(struct commodity),1,file);
            if(result == 1){
                sprintf(info,"商品编号：%d\t商品名称：%s\t商品描述：%s\t商品类别：%s\t商品生产商：%s\t已售量：%d\t库存量：%d\t进价：%.1lf\t售价：%.1lf\n",comm.num,comm.name,comm.desc,comm.sort,comm.provider,comm.sold,comm.count,comm.in_price,comm.out_price);
                fputs(info,file_out);
            }
        }
        fclose(file);
        fclose(file_out);
        system("cls");
        drawBorder();
        progressBar("正在将系统商品数据转存为文件，请稍候！");
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("商品信息导出成功，按任意键继续！");
        getch();
        system("cls");
        admin_main(name);
    }else if(ver == 2){
        FILE *file_out = fopen("信息导出_顾客用户.txt","w");
        FILE *file = fopen(PRODUCT,"ab+");
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
        while(!feof(file)){
            char info[100];
            int result = fread(&comm,sizeof(struct commodity),1,file);
            if(result == 1){
                sprintf(info,"商品编号：%d\t商品名称：%s\t商品描述：%s\t商品类别：%s\t商品生产商：%s\t商品已售量：%d\t商品售价：%.1lf\n",comm.num,comm.name,comm.desc,comm.sort,comm.provider,comm.sold,comm.out_price);
                fputs(info,file_out);
            }
        }
        fclose(file);
        fclose(file_out);
        system("cls");
        drawBorder();
        progressBar("正在将系统商品数据转存为文件，请稍候！");
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("商品信息导出成功，按任意键继续！");
        getch();
        system("cls");
        cus_main(name);
    }
}
