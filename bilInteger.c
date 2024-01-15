/*
Nama            : Dzu Sunan Muhammad
NIM             : 24060122120034
Nama Program    : bilInteger.c
Deskripsi       : Menentukan dan menampilkan apakah suatu bilangan integer sembarang merupakan bilangan bulat positif atau nol atau bulat negative
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Kamus
    int i;

    //Algoritma
    printf("Masukkan bilangan integer sembarang : ");
    scanf("%d",&i);
    if (i > 0){
        printf("bilangan %d merupakan bilangan bulat positif",i);
    } else if (i == 0){
         printf("bilangan %d merupakan nol",i);
    } else if (i < 0) {
         printf("bilangan %d merupakan bilangan bulat negatif",i);
    } else {
        printf("Bukan termasuk sebuah bilangan");
    }
}
