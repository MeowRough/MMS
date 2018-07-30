#include "mms.h"

void switch_cus(int choice,char *name){
	switch(choice){
        case 1:
            buy_product(name);
            break;
        case 2:
            search_comm(name,2);
            break;
        case 3:
            sort_search(name,2);
            break;
        case 4:
            send_mes(name);
            break;
        case 5:
            buy_record(name);
            break;
        case 6:
            sales_ranking_query(name,2);
            break;
        case 7:
            info_change(name,2);
            break;
        case 8:
            show_page(PRODUCT,"商品信息",name,2);
            break;
        case 9:
            color_change(name);
            break;
        case 10:
            out_file(name,2);
            break;
        case 11:
            cus_unsubscribe(name);
            break;
        case 12:
        	system("cls");
            start();
            break;
    }
}
