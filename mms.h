//引入头文件
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <time.h>

//宏定义
#define HEIGHT 23
#define WIDTH 80
#define USER_1 "user_1.dat"
#define USER_2 "user_2.dat"
#define PRODUCT "product.dat"
#define MES "mes.dat"
#define BUY_RECORD "buy_record.dat"
#define VAULT "vault.dat"

struct message{
     char name[30];
     char content[100];
     char contract[20];
     char date[30];
 };//保存用户的反馈信息

 struct record{
     char name[20];
     char product[30];
     int quantity;
     char date[15];
 };//保存用户的购买记录

struct commodity{
    int num;//商品编号
    char name[15];//商品名称
    double in_price;//进价
    double out_price;//售价
    char desc[100];//商品描述
    int count;//库存量
    char sort[30];//类别
    int sold;//销售量
    char provider[50];//生产商

} ;
//结构体数组
struct user{
    char name[20];
    char sex[10];
    char phone[20];
    char mail[30];
    char pass[20];
    char pass_double[20];
};
//保存用户的信息




void start();
void goToXY();
void drawBorder();
void drawTitle();
void admin_main(char *name);
void cus_main(char *name);
void progressBar(char *text);
void admin_login();
void cus_login();
void admin_register();
void cus_register();
void admin_login_login();
void cus_login_login();
void add_comm(char *name);
void change_comm(char *name);
void del_comm(char *name);
void hideCursor();
void switch_admin(int choice,char *name);
void switch_cus(int choice,char *name);
void color_change(char *name);
void send_mes(char *name);
void receive_mes(char *name);
int count_mes();//计算用户反馈信息的条数
void show_page(char *file_name,char *str,char *name,int ver);
void page_up(char *file_name,char *str,int num,char *name,int ver);
void page_down(char *file_name,char *str,int num,char *name,int ver);
void drawInBorder();//画出分页查询的内部表格边框
void buy_record(char *name);
void buy_product(char *name);
void sort_search(char *name,int ver);
void info_change(char *name,int ver);
void admin_unsubscribe(char *name);
void cus_unsubscribe(char *name);
void search_comm(char *name,int ver);
void out_file(char *name,int ver);
void sales_ranking_query(char *name,int ver);



int i,j,k;//定义循环变量

int del_num;
int change_num;
