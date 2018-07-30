#include "mms.h"

double vault(double out_price,int number)
{
    double total;
    FILE *file;
    file = fopen(VAULT,"ab+");
    fread(&total,sizeof(double),1,file);
    fclose(file);
    total = total + out_price*number;
    file = fopen(VAULT,"w");
    fwrite(&total,sizeof(double),1,file);
    fclose(file);
    return total;
}
