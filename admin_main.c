#include "mms.h"

void admin_main(char *name){
    drawBorder();
    goToXY(60,3);
    printf("��ӭ����%s!",name);
    goToXY(28,3);
    printf("****�����б�****");
    goToXY(29,5);
    printf("1.�����Ʒ��Ϣ");
    goToXY(29,6);
    printf("2.�޸���Ʒ��Ϣ");
    goToXY(29,7);
    printf("3.�����ѯ��Ʒ");
    goToXY(29,8);
    printf("4.ɾ����Ʒ��Ϣ");
    goToXY(29,9);
    printf("5.�û�������Ϣ");
    goToXY(29,10);
    printf("6.�ؼ��ֲ�ѯ");
    goToXY(29,11);
    printf("7.���������ѯ");
    goToXY(29,12);
    printf("8.��ҳ��ʾ��Ʒ��Ϣ");
    goToXY(29,13);
    printf("9.���»�����Ϣ");
    goToXY(29,14);
    printf("10.���Ľ�����ɫ");
    goToXY(29,15);
    printf("11.��Ʒ��Ϣ����");
    goToXY(29,16);
    printf("12.ע���˻�");
    goToXY(29,17);
    printf("13.�˳�");

    goToXY(25,20);
    printf("����������ѡ��|");
    goToXY(45,20);
    printf("|");
    goToXY(43,20);
    int choice;
    scanf("%d",&choice);
    switch_admin(choice,name);


}
