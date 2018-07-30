#include "mms.h"

void admin_unsubscribe(char *name)
 {
     int state=0;
     system("cls");
     drawBorder();
     goToXY(28,3);
     printf("你确定要注销该账号？");
     goToXY(26,12);
     printf("①  ★  确定");
     goToXY(26,14);
     printf("②      取消");
     while(TRUE)
     {
         char choice;
         choice = getch();
         if(choice == 72)
         {
             goToXY(30,12+state*2);
             printf("\b  ");
             state -= 1;
             if(state == -1)
             {
                 state = 1;
             }
             goToXY(30,12+state*2);
             printf("★");
         }
         else if(choice == 80)
         {
             goToXY(30,12+state*2);
             printf("\b  ");
             state += 1;
             if(state == 2)
             {
                 state = 0;
             }
             goToXY(30,12+state*2);
             printf("★");
         }
         else if(choice == '\r')
         {
             switch(state)
             {
             case 0:
                {
                 FILE *file = fopen("user_1.dat","ab+");
                 FILE *file_copy = fopen("copy.dat","ab+");
                 struct user User= {"","","","","",""};
                 rewind(file);
                 while(!feof(file))
                 {
                     int result = fread(&User,sizeof(struct user),1,file);
                     if(result != 0)
                     {
                         if(strcmp(User.name,name)!=0)
                         {
                             fwrite(&User,sizeof(struct user),1,file_copy);
                         }
                     }
                 }
                 fclose(file);
                 fclose(file_copy);
                 remove("user_1.dat");
                 rename("copy.dat","user_1.dat");
                 system("cls");
                 drawBorder();
                 goToXY(28,9);
                 printf("账户注销成功，按任意键退出！");
                 getch();
                 system("cls");
                 start();
                 break;}
             case 1:
                 system("cls");
                 admin_main(name);
             }
         }

     }
 }
