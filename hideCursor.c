#include "mms.h"

void hideCursor(){
    CONSOLE_CURSOR_INFO cursor_info;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
