#include "mms.h"

void cus_register(){
    struct user cus = {"","","","","",""};

    goToXY(28,3);
    printf("****�˿��û�ע����Ϣ****");
    goToXY(20,9);
    printf("�ǳƣ�");
    goToXY(20,10);
    printf("�Ա�");
    goToXY(20,11);
    printf("���䣺");
    goToXY(20,12);
    printf("�ֻ��ţ�");
    goToXY(20,15);
    printf("���룺");
    goToXY(20,16);
    printf("�ظ����룺");


    goToXY(27,9);
    scanf("%s",cus.name);
    goToXY(27,10);
    scanf("%s",cus.sex);
    goToXY(27,11);
    scanf("%s",cus.mail);
    goToXY(29,12);
    scanf("%s",cus.phone);
    goToXY(27,15);
    i=0;
     char pw;
 	pw=getch();
     while ( pw != 13){
       	if(pw == 8){
 			if(i!=0) {printf("%c %c",pw,pw);i--;}
         }else if(i==20&&pw!=8) {}
         else{
     		printf("*");
            	cus.pass[i] = pw;
           	i++;
         }
        	pw = getch(); //���������ַ�ch
     }
     cus.pass[i]='\0';
    goToXY(31,16);
    i=0;
     pw=getch();
     while( pw != 13) //�����ַ�ch��ΪEnter
 	{
 		if(pw == 8)  //�����ַ�chΪBackSpace
         {if(i!=0) {printf("%c %c",pw,pw);i--;}}
         else if(i==20&&pw!=8) {}
         else{
           	printf("*");
            	cus.pass_double[i] = pw;
           	i++;
         }
        	pw = getch(); //���������ַ�ch
     }
     cus.pass_double[i]='\0';

     if(!strcmp(cus.pass,cus.pass_double)){

        FILE *file;
        file = fopen(USER_2,"ab+");
        rewind(file);
         struct user User= {"","","","","",""};
         while(!feof(file))
         {
             int result = fread(&User,sizeof(struct user),1,file);
             if(result != 0)
             {
                 if(strcmp(User.name,cus.name)==0)  break;
             }
         }
         if(feof(file))
         {
             fwrite(&cus,sizeof(struct user),1,file);
             fclose(file);
             system("cls");
             drawBorder();
             goToXY(30,9);
             printf("�û�����%s",cus.name);
             goToXY(25,11);
             printf("�˿����ע��ɹ����������������");
             getch();
             system("cls");
             cus_login();
         }
         else
         {
             system("cls");
             drawBorder();
             goToXY(25,11);
             printf("�û����ظ���ע��ʧ�ܣ�");
             getch();
             system("cls");
             cus_login();
         }
     }
     else
     {

        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("�����������벻һ�£�ע��ʧ�ܣ�");
        getch();
        system("cls");
        cus_login();

    }

}
