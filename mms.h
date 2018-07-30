//����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <time.h>

//�궨��
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
 };//�����û��ķ�����Ϣ

 struct record{
     char name[20];
     char product[30];
     int quantity;
     char date[15];
 };//�����û��Ĺ����¼

struct commodity{
    int num;//��Ʒ���
    char name[15];//��Ʒ����
    double in_price;//����
    double out_price;//�ۼ�
    char desc[100];//��Ʒ����
    int count;//�����
    char sort[30];//���
    int sold;//������
    char provider[50];//������

} ;
//�ṹ������
struct user{
    char name[20];
    char sex[10];
    char phone[20];
    char mail[30];
    char pass[20];
    char pass_double[20];
};
//�����û�����Ϣ




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
int count_mes();//�����û�������Ϣ������
void show_page(char *file_name,char *str,char *name,int ver);
void page_up(char *file_name,char *str,int num,char *name,int ver);
void page_down(char *file_name,char *str,int num,char *name,int ver);
void drawInBorder();//������ҳ��ѯ���ڲ����߿�
void buy_record(char *name);
void buy_product(char *name);
void sort_search(char *name,int ver);
void info_change(char *name,int ver);
void admin_unsubscribe(char *name);
void cus_unsubscribe(char *name);
void search_comm(char *name,int ver);
void out_file(char *name,int ver);
void sales_ranking_query(char *name,int ver);



int i,j,k;//����ѭ������

int del_num;
int change_num;
