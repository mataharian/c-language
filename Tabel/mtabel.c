#include <stdio.h>
#include "tabel.c"

/************************************/
/* Program   : mtabel.c */
/*Deskripsi  : driver ADT tabel integer*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 8 September 2023*/
/***********************************/

int main() {
	//Kamus lokal
	Tabel A;
	int Pos, byk;
	
	//Algoritma
	printf("=======================Create Tabel========================\n");
	createTable(&A);
	printTable(A);
	printf("\n");
	printf("Ukuran tabel A adalah : %d \n", getSize(A));
	printf("Elemen tabel A yang belum terisi : %d \n", countEmpty(A));
	printf("Apakah tabel A kosong? : %s \n", isEmptyTable(A) == 1? "True" : "False");
	printf("Apakah tabel A penuh? : %s \n", isFullTable(A) == 1? "True" : "False");
	printf("\n");

	printf("===================Mengisi 5 Elemen Tabel===================\n");
	populate1(&A, 5);
	viewTable(A);
	printf("\n");
	printf("Ukuran tabel A adalah : %d \n", getSize(A));
	printf("Elemen tabel A yang belum terisi : %d \n", countEmpty(A));
	printf("Apakah tabel A kosong? : %s \n", isEmptyTable(A) == 1? "True" : "False");
	printf("Apakah tabel A penuh? : %s \n", isFullTable(A) == 1? "True" : "False");
	printf("-----------------------Mencari nilai X----------------------\n");
	searchX1(A, 5, &Pos);
	printf("----------------Menhitung banyaknya nilai X-----------------\n");
	countX(A, 2, &byk);
	printf("Jumlah nilai 2 pada tabel : %d  \n", byk);
	printf("---------------------Nilai Max dan Min----------------------\n");
	printf("Nilai maximum tabel A : %d \n", getMaxEl(A));
	printf("Nilai minimum tabel A : %d \n", getMinEl(A));
	printf("\n");
	printf("----------------Mengisi tabel dengan nilai X----------------\n");
	printf("Menambahkan nilai 6 dalam tabel \n");
	addXTable(&A, 6);
	viewTable(A);
	printf("\n");
	printf("----------------Menghapus 1 elemen bernilai X---------------\n");
	delXTable(&A, 4);
	viewTable(A);
	printf("\n");
	printf("--------------Menghapus semua elemen bernilai X-------------\n");
	delAllXTable(&A,2);
	viewTable(A);
	printf("\n");
	printf("\n");

	printf("=================Mengisi Sisa Elemen Tabel==================\n");
	populate2(&A);
	viewTable(A);
	printf("\n");
	printf("Ukuran tabel A adalah : %d \n", getSize(A));
	printf("Elemen tabel A yang belum terisi : %d \n", countEmpty(A));
	printf("Apakah tabel A kosong? : %s \n", isEmptyTable(A) == 1? "True" : "False");
	printf("Apakah tabel A penuh? : %s \n", isFullTable(A) == 1? "True" : "False");
	printf("-----------------Menjumlah nilai dalam tabel----------------\n");
	printf("Jumlah total nilai elemen : %d  \n", SumEl(A));
	printf("------------Menghitung rata-rata nilai dalam tabel-----------\n");
	printf("Nilai rata-rata elemen : %d  \n", AverageEl(A));
	printf("----------------Mencari nilai modus dalam tabel--------------\n");
	printf("Nilai modus elemen : %d\n", Modus(A));
	
	return 0;
}
