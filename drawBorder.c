#include "mms.h"

void drawBorder(){
    goToXY(0,0);
    for(i = 1;i < WIDTH;i++){
        printf("=");
    }
    goToXY(0,0);
    printf("¨X");
    goToXY(WIDTH-2,0);
    printf("¨[");
    for(i = 1;i < HEIGHT;i++){
        goToXY(0,i);
        printf("¨U");
        goToXY(WIDTH-2,i);
        printf("¨U");
    }
    goToXY(0,HEIGHT);
    for(i = 1;i < WIDTH;i++){
            printf("=");
    }
    goToXY(0,HEIGHT);
    printf("¨^");
    goToXY(WIDTH-2,HEIGHT);
    printf("¨a");
}
