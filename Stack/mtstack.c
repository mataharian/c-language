#include <stdio.h>
#include "tstack.c"
#include <string.h>

/***********************************/
/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 15 September 2023*/
/***********************************/

int main() 
{	/* kamus main */
	Tstack A;
	char X;
	Tstack SS;
	char c, kata[15];
	int p, i;
	boolean hasil;

	/* algoritma */
	printf("==============Create Stack==============\n");
	createStack(&A);
	printf("Top nya adalah : %d \n", top(A));
	printStack(A);
	printf("Apakah stack kosong? %s \n",  isEmptyStack(A) == 1? "True" : "False");
	printf("Apakah stack penuh? %s \n",  isFullStack(A) == 1? "True" : "False");
	printf("\n");

	printf("=====Mengisi Elemen Top Dengan Push=====\n");
	push(&A, 'a');
	push(&A, 'b');
	push(&A, 'c');
	push(&A, 'd');
	printf("Top nya adalah : %d \n", top(A));
	viewStack(A);
	printf("Apakah stack kosong? %s \n",  isEmptyStack(A) == 1? "True" : "False");
	printf("Apakah stack penuh? %s \n",  isFullStack(A) == 1? "True" : "False");
	printf("\n");

	printf("====Mengambil Elemen Top Dengan Pop====\n");
	pop(&A, &X);
	printf("Top nya adalah : %d \n", top(A));
	viewStack(A);
	printf("Apakah stack kosong? %s \n",  isEmptyStack(A) == 1? "True" : "False");
	printf("Apakah stack penuh? %s \n",  isFullStack(A) == 1? "True" : "False");
	printf("\n");

	printf("===============Push Zuma===============\n");
	pushZuma(&A, 'c');
	printf("Top nya adalah : %d \n", top(A));
	viewStack(A);
	printf("Apakah stack kosong? %s \n",  isEmptyStack(A) == 1? "True" : "False");
	printf("Apakah stack penuh? %s \n",  isFullStack(A) == 1? "True" : "False");
	printf("\n");

	printf("=====Mengisi Elemen Top Baru N Kali====\n");
	pushN(&A, 8);
	printf("Top nya adalah : %d \n", top(A));
	viewStack(A);
	printf("Apakah stack kosong? %s \n",  isEmptyStack(A) == 1? "True" : "False");
	printf("Apakah stack penuh? %s \n",  isFullStack(A) == 1? "True" : "False");
	printf("\n");

	printf("=============Push Babel================\n");
	pushBabel1(&A, 'k');
	printf("Top nya adalah : %d \n", top(A));
	viewStack(A);
	printf("Apakah stack kosong? %s \n",  isEmptyStack(A) == 1? "True" : "False");
	printf("Apakah stack penuh? %s \n",  isFullStack(A) == 1? "True" : "False");
	printf("\n");

	printf("==============IsPolindrom==============\n");
	printf("Masukkan kata : ");
	scanf("%s", kata);
	p = strlen(kata);
	hasil = false; 
	if (p > 0){
		createStack(&SS);
		for (i = 0; i <= (p/2) - 1; i++){
			push(&SS, kata[i]);
		}
		if (p % 2 == 1){
			do{
				i = i + 1;
				pop(&SS, &c);
			} while ((c == kata[i]) && (i < p-1));
		}else{
			for (i = i - 1; i < p - 1; i++){
				pop(&SS, &c);
			}
		}
		if (c == kata[i]){
			hasil = true;
		}
	}
	printf("IsPalindrom? %s \n",  hasil == true? "True" : "False");


	return 0;
}
