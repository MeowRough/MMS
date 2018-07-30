#include "mms.h"

void admin_register(){

    struct user admin = {"","","","","",""};
    char code[10];

    goToXY(28,3);
    printf("****管理员注册信息****");
    goToXY(20,9);
    printf("昵称：");
    goToXY(20,10);
    printf("性别：");
    goToXY(20,11);
    printf("邮箱：");
    goToXY(20,12);
    printf("手机号：");
    goToXY(20,13);
    printf("管理员注册码：");
    goToXY(20,15);
    printf("密码：");
    goToXY(20,16);
    printf("重复密码：");


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
       	pw = getch(); //继续输入字符ch
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
        	pw = getch(); //继续输入字符ch
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
             printf("用户名：%s",admin.name);
             goToXY(25,11);
             printf("管理员身份注册成功，按任意键继续！");
             getch();
             system("cls");
             admin_login();
         }
         else
         {
             system("cls");
             drawBorder();
             goToXY(25,11);
             printf("用户名重复，注册失败！");
             getch();
             system("cls");
             admin_login();
         }

     }
     else{


        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("注册失败！");
        getch();
        system("cls");
        admin_login();


    }


}
