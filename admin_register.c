#include "mms.h"

void admin_register(){

    struct user admin = {"","","","","",""};
    char code[10];

    goToXY(28,3);
    printf("****����Աע����Ϣ****");
    goToXY(20,9);
    printf("�ǳƣ�");
    goToXY(20,10);
    printf("�Ա�");
    goToXY(20,11);
    printf("���䣺");
    goToXY(20,12);
    printf("�ֻ��ţ�");
    goToXY(20,13);
    printf("����Աע���룺");
    goToXY(20,15);
    printf("���룺");
    goToXY(20,16);
    printf("�ظ����룺");


    goToXY(27,9);
    scanf("%s",admin.name);
    goToXY(27,10);
    scanf("%s",admin.sex);
    goToXY(27,11);
    scanf("%s",admin.mail);
    goToXY(29,12);
    scanf("%s",admin.phone);
    goToXY(35,13);
    scanf("%s",code);
    goToXY(27,15);
     i=0;
     char pw;
     pw=getch();
     while(pw != 13){
     	if(pw == 8){
 			if(i!=0){printf("%c %c",pw,pw);i--;}
         }
         else if(i==20&&pw!=8){}
         else
         {
           	printf("*");
            	admin.pass[i] = pw;
           	i++;
     	}
       	pw = getch(); //���������ַ�ch
     }
     admin.pass[i]='\0';
    goToXY(31,16);
     i=0;
     pw=getch();
     while(pw != 13){
 		if ( pw == 8){
 			if(i!=0) {printf("%c %c",pw,pw);i--;}
         }
         else if(i==20&&pw!=8) {}
         else{
           	printf("*");
            	admin.pass_double[i] = pw;
          	 i++;
         }
        	pw = getch(); //���������ַ�ch
     }
     admin.pass_double[i]='\0';



    if((!strcmp(code,"cjhz"))&&(!strcmp(admin.pass,admin.pass_double))){

        FILE *file;
        file = fopen(USER_1,"ab+");
        rewind(file);
         struct user User= {"","","","","",""};
         while(!feof(file))
         {
             int result = fread(&User,sizeof(struct user),1,file);
             if(result != 0)
             {
                 if(strcmp(User.name,admin.name)==0)  break;
             }
         }
         if(feof(file))
         {
             fwrite(&admin,sizeof(struct user),1,file);
             fclose(file);
             system("cls");
             drawBorder();
             goToXY(30,9);
             printf("�û�����%s",admin.name);
             goToXY(25,11);
             printf("����Ա���ע��ɹ����������������");
             getch();
             system("cls");
             admin_login();
         }
         else
         {
             system("cls");
             drawBorder();
             goToXY(25,11);
             printf("�û����ظ���ע��ʧ�ܣ�");
             getch();
             system("cls");
             admin_login();
         }

     }
     else{


        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("ע��ʧ�ܣ�");
        getch();
        system("cls");
        admin_login();


    }


}
