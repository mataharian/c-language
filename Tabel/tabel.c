#include "tabel.h"
#include <stdio.h>

/************************************/
/* Program   : tabel.c */
/* Deskripsi : realisasi body modul Tabel*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 8 September 2023*/
/***********************************/

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T){
    //Kamus lokal
    int i;

    //Algoritma
    (*T).size = 0;
    for (i = 1; i <= 10; i++){
        (*T).wadah[i] = -999;
    }
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = 1; i <= 9; i++){
        printf("%d, ",T.wadah[i]);
    }
    printf("%d",T.wadah[10]);  
    printf("]");
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = 1; i <= getSize(T) - 1; i++){
        printf("%d, ",T.wadah[i]);
    }
    printf("%d",T.wadah[T.size]);  
    printf("]");
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    //Kamus lokal

    //Algoritma
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T){
    //Kamus lokal
    
    //Algoritma
    return 10 - getSize(T);
}

/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T){
    if (getSize(T) == 0){
        return true;
    }else{
        return false;
    }
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T){
    if (getSize(T) == 10){
        return true;
    }else{
        return false;
    }
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N){
    //Kamus lokal
    int i, j;

    //Algoritma
    for (i = getSize(*T) + 1; i <= N ; i++){
        printf("Masukkan elemen ke-%d : ", i);
        scanf("%d", &j);
        while(j <= 0){
            printf("Angka harus positif \n");
            printf("Masukkan elemen ke-%d : ", i);
            scanf("%d", &j);
        }
        (*T).wadah[i] = j;
        (*T).size++;
        }
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos){
    //Kamus lokal
    int i;

    //Algoritma
    *Pos = -999;
    if (getSize(T) == 0){
        printf("Tabel kosong!! \n");
    }else{
        for (i=1; i <= getSize(T); i++){
            if (X == T.wadah[i]){
                *Pos = i;
                break;
            }
        }if (*Pos == i){
            printf("Nilai %d terdapat dalam elemen ke-%d \n", X, *Pos);
        }else{
            printf("Nilai %d tidak ditemukan \n", X);
        }
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk){
    //Kamus lokal
    int i;
    
    //Algoritma
    *Byk = 0;
    if(getSize(T) == 0){
        printf("Tabel Kosong!! \n");
    }else{
        for(i=1; i <= getSize(T) + 1; i++){
            if((T).wadah[i]== X){
                *Byk += 1;
            }
        }
    }
}

/*function SumEl ( T:Tabel ) -> integer 
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl (Tabel T){
    //Kamus lokal
    int i, sum;

    // Algoritma
    sum = 0;
    for (i = 1; i <= getSize(T); i++){
        sum += T.wadah[i];
    }
    return sum;
}

/*function AverageEl ( T:Tabel ) -> integer 
	{mengembalikan nilai rata-rata elemen pengisi T } */
int AverageEl (Tabel T){
    //Kamus lokal

    //Algoritma
    return SumEl(T)/getSize(T);
}

/*function getMaxEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl (Tabel T){
    //Kamus lokal
    int i;
    int max;

    //Algoritma
    max = T.wadah[1];
    for (i = 1; i <= getSize(T); i++){
        if (T.wadah[i] > max){
            max = T.wadah[i];
        }
    }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil} */
int getMinEl (Tabel T){
    //Kamus lokal
    int i;
    int min;

    //Algoritma
    min = T.wadah[1];
    for (i = 1; i <= getSize(T); i++){
        if (T.wadah[i] < min){
            min = T.wadah[i];
        }
    }
    return min;
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka 
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2 (Tabel *T){
    //Kamus lokal
    int i, j;

    //Algoritma
    for (i = getSize(*T) + 1; i <= 10 ; i++){
        printf("Masukkan elemen ke-%d : ", i);
        scanf("%d", &j);
        if (j <= 0){
            printf("Angka harus positif \n");
            break;
        }else{
            (*T).wadah[i] = j;
            (*T).size++;
        }
    }
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X){
    //Kamus lokal

    //Algoritma
    if (getSize(*T) + 1 <= 10){
        (*T).wadah[getSize(*T)+1] = X;
        (*T).size += 1;
    } else{
        printf("Tabel penuh!!\n");
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X){
    //Kamus lokal
    int i, pos;

    //Algoritma
    searchX1(*T, X, &pos);
    if(pos != -999){
        for(i = pos; i <= getSize(*T); i++){
            (*T).wadah[i] = (*T).wadah[i+1];
        }
        (*T).wadah[i] = -999;
        (*T).size -= 1;
    }
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X){
    //Kamus lokal
    int i;

    //Algoritma
    for (i = 1; i <= getSize(*T); i++){
        delXTable(T,X);
    }
}

/*function Modus ( T:Tabel ) -> integer 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus (Tabel T){
	//Kamus lokal
	int i, a, modus, jum, jumax;
	
	//Algoritma
	modus = 0;
	jumax = 0;
	for (i = 1; i <= getSize(T); i++) {
    	jum = 0;
    	for (a = 1; a <= getSize(T); a++)
      	if (T.wadah[i] == T.wadah[a])
        	jum++;
    
    	if (jum > jumax) {
      	jumax = jum;
     	modus = i;
    	}
  	}
    return T.wadah[modus];
}