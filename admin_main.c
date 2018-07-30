#include "mms.h"

void admin_main(char *name){
    drawBorder();
    goToXY(60,3);
    printf("欢迎您，%s!",name);
    goToXY(28,3);
    printf("****功能列表****");
    goToXY(29,5);
    printf("1.添加商品信息");
    goToXY(29,6);
    printf("2.修改商品信息");
    goToXY(29,7);
    printf("3.分类查询商品");
    goToXY(29,8);
    printf("4.删除商品信息");
    goToXY(29,9);
    printf("5.用户反馈信息");
    goToXY(29,10);
    printf("6.关键字查询");
    goToXY(29,11);
    printf("7.销量排序查询");
    goToXY(29,12);
    printf("8.分页显示商品信息");
    goToXY(29,13);
    printf("9.更新基本信息");
    goToXY(29,14);
    printf("10.更改界面颜色");
    goToXY(29,15);
    printf("11.商品信息导出");
    goToXY(29,16);
    printf("12.注销账户");
    goToXY(29,17);
    printf("13.退出");

    goToXY(25,20);
    printf("请输入您的选择：|");
    goToXY(45,20);
    printf("|");
    goToXY(43,20);
    int choice;
    scanf("%d",&choice);
    switch_admin(choice,name);


}
