#include "mms.h"

void cus_main(char *name){
    drawBorder();
    goToXY(60,3);
    printf("��ӭ����%s!",name);
    goToXY(28,3);
    printf("****�����б�****");
    goToXY(29,5);
    printf("1.ѡ����Ʒ");
    goToXY(29,6);
    printf("2.�ؼ��ֲ�ѯ");
    goToXY(29,7);
    printf("3.�����ѯ��Ʒ");
    goToXY(29,8);
    printf("4.����������Ϣ");
    goToXY(29,9);
    printf("5.��Ʒ�����¼");
    goToXY(29,10);
    printf("6.���������ѯ");
    goToXY(29,11);
    printf("7.���»�����Ϣ");
    goToXY(29,12);
    printf("8.��ҳ�鿴��Ʒ��Ϣ");
    goToXY(29,13);
    printf("9.���Ľ�����ɫ");
    goToXY(29,14);
    printf("10.��Ʒ��Ϣ����");
    goToXY(29,15);
    printf("11.ע���˻�");
    goToXY(29,16);
    printf("12.�˳�");




    goToXY(25,20);
    printf("����������ѡ��|");
    goToXY(45,20);
    printf("|");
    goToXY(43,20);
    int choice;
    scanf("%d",&choice);
    switch_cus(choice,name);
}
