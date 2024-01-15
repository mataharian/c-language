/*
Nama    		: Dzu Sunan Muhammad
NIM     		: 24060122120034
Nama Program 	: jarakPBola.c
Deskripsi 		: Menghitung dan menampilkan jarak gerak parabola
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    //Kamus
    float v0,t,y;
    const float g = 9.8;

    //Algoritma
    printf("Masukkan : \n");
    printf("v0 = ");
    scanf("%f",&v0);
    printf("t = ");
    scanf("%f",&t);

    y = (v0*t)-(g*t*t/2);
    printf("y = %.2f \n", y);
    printf("Jadi jarak gerak parabolanya adalah %.2f", y);
}
