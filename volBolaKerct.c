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
    float r,Vb,Vk;
    const float phi = 3.14;

    //Algoritma
    printf("Masukkan : \n");
    printf("r = ");
    scanf("%f",&r);

    Vb = (4/3)*(phi*r*r*r);
    printf("Vb = %.2f \n",Vb);

    Vk = 0.5*Vb;
    printf("Vk = %.2f \n",Vk);

    printf("Jadi besar volume bola adalah %.2f \n",Vb);
    printf("Jadi besar volume kerucut adalah %.2f",Vk);
}
