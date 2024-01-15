/*
Nama    		: Dzu Sunan Muhammad
NIM     		: 24060122120034
*/

#include <stdio.h>
#include <conio.h>
#include "mesink.h"
#include "mesink.c"

int main()
{
    printf("Awal pita\n");
    START();
    while (!EOP()){
        printf("%c", CC);
        ADV();
    }
    printf("\nAkhir pita\n");

    WordCnting();

    return 0;
}


