/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : Jumat, 1 September 2023*/
/***********************************/
#include <stdio.h>
#include "titik.c"
#include <stdbool.h>

int main() {
	//kamus main
	Titik A,B;
	
	
	//algoritma
	printf("Mengisi nilai absis dan ordinat titik A dengan 0 \n");
	makeTitik(&A);
	printf("Absis A = %d \n", getAbsis(A));
	printf("Ordinat A = %d \n", getOrdinat(A));
	if (isOrigin(A)){
		printf("isOrigin = True \n");
	}else{
		printf("isOrigin = False \n");
	}
	printf("-------------------------------------------------\n");

	printf("Mengisi nilai absis dan odinat titik A \n");
	setAbsis(&A,3);
	setOrdinat(&A,5);
	printf("Absis A = %d \n", getAbsis(A));
	printf("Ordinat A = %d \n", getOrdinat(A));
	if (isOrigin(A)){
		printf("isOrigin = True \n");
	}else{
		printf("isOrigin = False \n");
	}
	printf("-------------------------------------------------\n");

	printf("Menggeser titik A sejauh (-3,1) \n");
	geserXY(&A, -3, 1);
	printf("Absis A = %d \n", getAbsis(A));
	printf("Ordinat A = %d \n", getOrdinat(A));
	printf("Kuadran A = %d \n", Kuadran(A));
	printf("-------------------------------------------------\n");

	printf("Mengisi nilai absis dan ordinat titik B \n");
	setAbsis(&B,6);
	setOrdinat(&B,2);
	printf("Absis B = %d \n", getAbsis(B));
	printf("Ordinat B = %d \n", getOrdinat(B));
	printf("-------------------------------------------------\n");

	printf("Merefleksikan nilai absis dan odinat pada titik B \n");
	refleksiSumbuX(&B);
	refleksiSumbuY(&B);
	printf("Absis B = %d \n", getAbsis(B));
	printf("Ordinat B = %d \n", getOrdinat(B));
	printf("Kuadran B = %d \n", Kuadran(B));
	printf("-------------------------------------------------\n");

	printf("Menghitung jarak antara titik A dan B \n");
	printf("Titik A = %d %d \n", getAbsis(A), getOrdinat(A));
	printf("Titik B = %d %d \n", getAbsis(B), getOrdinat(B));
	printf("Jarak titik A dan B = %.2f \n", Jarak(A,B));

	return 0;
}
