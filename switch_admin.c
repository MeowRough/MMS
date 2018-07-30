#include "mms.h"

void switch_admin(int choice,char *name){
	switch(choice){
        case 1:
            add_comm(name);
            break;
        case 2:
            change_comm(name);
            break;
        case 3:
            sort_search(name,1);
            break;
        case 4:
            del_comm(name);
            break;
        case 5:
            receive_mes(name);
            break;
        case 6:
            search_comm(name,1);
            break;
        case 7:
            sales_ranking_query(name,1);
            break;
        case 8:
            show_page(PRODUCT,"商品信息",name,1);
            break;
        case 9:
            info_change(name,1);
            break;
        case 10:
            color_change(name);
            break;
        case 11:
            out_file(name,1);
            break;
        case 12:
            admin_unsubscribe(name);
            break;
        case 13:
            system("cls");
            start();
            break;
    }
}
