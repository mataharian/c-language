/*
Nama    		: Dzu Sunan Muhammad
NIM     		: 24060122120034
Nama Program 	: BilPrimaN.c
Deskripsi 		: Mengidentifikasi dan menampilkan pada layar pada sampai deret berapakah inputan N
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    // Kamus
    int N, i, j, c;

    // Algoritma
    printf("Masukkan bilangan : ");
    scanf("%d",&N);

    for (j=2; j<=N; j++){
        c = 0;
        for(i=2; i<=(sqrt(j)); i++){
            if (j % i == 0){
                c = 1;
                break;
            }
        }
        if(c == 0){
            printf("%d \n",j);
        }
    }

    return 0;
}
