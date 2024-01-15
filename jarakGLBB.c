/*
Nama    		: Dzu Sunan Muhammad
NIM     		: 24060122120034
Nama Program 	: jarakGLBB.c
Deskripsi 		: Menghitung dan menampilkan jarak GLBB
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    //Kamus
    float v0,t,a,s;

    //Algoritma
    printf("Masukkan \n");
    printf("v0 = ");
    scanf("%f",&v0);
    printf("t = ");
    scanf("%f",&t);
    printf("a = ");
    scanf("%f",&a);

    s = v0*t*(a*t*t/2);
    printf("s = %.2f \n", s);
    printf("Jadi jarak GLBB yang ditempuh adalah %.2f", s);

    return 0;
}
