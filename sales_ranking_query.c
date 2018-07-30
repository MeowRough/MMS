#include "mms.h"

void sales_ranking_query(char *name,int ver){
     system("cls");
     drawBorder();
     goToXY(23,5);
     char view_sort[30];
     printf("输入您想查看的商品类别：");
     scanf("%s",view_sort);
     FILE *file =fopen("product.dat","ab+");
     FILE *file_select=fopen("select.dat","ab+");
     struct commodity select_comm= {0,"",0,0,"",0,"",0,""};
     rewind(file);
     struct commodity product_select[1000];
     i=0;
     while(!feof(file))
     {
         int result = fread(&select_comm,sizeof(struct commodity),1,file);
         if(result != 0)
         {
             if(strcmp(select_comm.sort,view_sort)==0)
             {
                 product_select[i]=select_comm;
                 fwrite(&select_comm,sizeof(struct commodity),1,file_select);
                 i++;
             }
         }
     }
     for(j=i-1; j>0; j--)
     {
         for(k=0; k<j; k++)
         {
             if(product_select[k].sold>product_select[k+1].sold)
             {
                 struct commodity tmp=product_select[k];
                 product_select[k]=product_select[k+1];
                 product_select[k+1]=tmp;
             }
         }
     }
     fclose(file);
     file_select=fopen("select.dat","w");   //删除原来数据
     rewind(file_select);
     for(j=0; j<i; j++)
     {
         fwrite(&product_select[j],sizeof(struct commodity),1,file_select);
     }
     fclose(file_select);
 	show_page("select.dat","商品销量排序",name,ver);
 }
