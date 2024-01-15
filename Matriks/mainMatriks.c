#include <stdio.h>
#include <stdlib.h>
#include "matriks.c"

/************************************/
/* Program   : mmatriks.c */
/*Deskripsi  : driver ADT matriks integer*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : */
/***********************************/

int main(void){
    //Kamus lokal
    Matriks A;
    int NBbar, NBkol;

    //Algoritma
    printf("=========================================================== \n");
    printf("========================Create Matriks===================== \n");
    printf("=========================================================== \n");
    makeMatriks(&A);
    printMatriks(A);
    printf("Matriks kosong : %s \n", isEmptyMatriks(A)?"True":"False");
    printf("Matriks penuh : %s \n", isFullMatriks(A)?"True":"False");
    printf("\n");

    // printf("=========================================================== \n");
    // printf("=====================Set Baris dan Kolom=================== \n");
    // printf("=========================================================== \n");
    // printf("Masukkan jumlah baris yang akan dipakai : ");
    // scanf("%d", &NBbar);
    // setNbbar(&A, NBbar);
    // printf("Baris dipakai : %d \n",getNbbar(A));
    // printf("Masukkan jumlah kolom yang akan dipakai : ");
    // scanf("%d", &NBkol);
    // setNbkol(&A, NBkol);
    // printf("Kolom dipakai : %d \n",getNbkol(A));
    // printf("\n");

    printf("=========================================================== \n");
    printf("=========================Set Matriks======================= \n");
    printf("=========================================================== \n");
    setMatriks(&A,NBbar, NBkol);
    viewMatriks(A);	
    printf("Matriks kosong : %s \n", isEmptyMatriks(A)?"True":"False");
    printf("Matriks penuh : %s \n", isFullMatriks(A)?"True":"False");
    printf("Jumlah elemen matriks : %d \n", sumCellMatriks(A));
    printf("Rata-rata elemen matriks : %d \n", avgCellMatriks(A));
    printf("\n");

    printf("=========================================================== \n");
    printf("======================Transpose Matriks==================== \n");
    printf("=========================================================== \n");
}