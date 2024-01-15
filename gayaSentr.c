/*
Nama    		: Dzu Sunan Muhammad
NIM     		: 24060122120034
Nama Program 	: gayaSentr.c
Deskripsi 		: Menghitung dan menampilkan gaya sentripetal
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    //Kamus
    float m,v,r,F;

    //Algoritma
    printf("Masukkan : \n");
    printf("m = ");
    scanf("%f",&m);
    printf("v = ");
    scanf("%f",&v);
    printf("r = ");
    scanf("%f",&r);

    F = m*(v*v/r);
    printf("F = %.2f \n", F);
    printf("Jadi gaya sentripetalnya adalah %.2f",F);
}
