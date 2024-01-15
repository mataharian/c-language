/*
Nama    		: Dzu Sunan Muhammad
NIM     		: 24060122120034
Nama Program 	: gayaSentr.c
Deskripsi 		: Menghitung dan menampilkan volume bola dan volume kerucut
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    //Kamus
    float s1,s2,d1,d2,luas,Kell;

    //Algoritma
    printf("Masukkan : \n");
    printf("s1 = ");
    scanf("%f",&s1);
    printf("s2 = ");
    scanf("%f",&s2);
    printf("d1 = ");
    scanf("%f",&d1);
    printf("d2 = ");
    scanf("%f",&d2);

    luas = 0.5*d1*d2;
    printf("luas = %.2f \n",luas);

    Kell = 2*(s1+s2);
    printf("Kell = %.2f \n",Kell);

    printf("Jadi luas layang-layang adalah %.2f \n",&luas);
    printf("Jadi Keliling layang-layang adalah %.2f",&Kell);
}
