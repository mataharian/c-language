/*
Nama            : Dzu Sunan Muhammad
NIM             : 24060122120034
Nama Program    : bilInteger.c
Deskripsi       : Menentukan dan menampilakn jenis segitiga
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Kamus
    int s1, s2, s3;

    //Algoritma
    printf("Masukkan nilai sisi pertama segitiga : ");
    scanf("%d", &s1);
    printf("Masukkan nilai sisi kedua segitiga : ");
    scanf("%d", &s2);
    printf("Masukkan nilai sisi ketiga segitiga : ");
    scanf("%d", &s3);

    if (s1 <0 || s2 < 0 || s3 < 0){
        printf("Terdapat nilai yang bukan sisi segitiga");
    }
    else{
        if (s1==s2 && s2==s3){
            printf("Segitiga sama sisi");
        }
        else if (s1==s2 || s2==s3 || s1==s3){
            printf("Segitiga sama kaki");
        }
        else{
            printf("Segitiga sembarang");
        }
    }
    return 0;
}
