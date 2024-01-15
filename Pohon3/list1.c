/* File : list1.c */
/* Deskripsi : file body modul list berkait dengan representasi fisik pointer */
/* NIM & Nama : 20460122120034/Dzu Sunan Muhammad*/
/* Tanggal : 3 November 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
    //Kamus lokal

    //Algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
    //Kamus lokal

    //Algoritma
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List1 L){
    //Kamus lokal
    address P;

    //Algoritma
    P = First(L);
    printf("List = [");
    while (P != NIL){
        printf("%c", info(P));
        if (next(P) != NIL){
                printf(", ");
        }
        P = next(P);
    }
    printf("] \n");
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
    //Kamus lokal
    address P;
    int len;

    //Algoritma
    P = First(L);
    len = 0;
    while (P != NIL){
        len = len + 1;
        P = next(P);
    }
    return len;
}

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:address) */ 
/* {I.S. - 
    F.S. P ter-alokasi 
	Proses: Memesan ruang memori untuk address P} */
void Alokasi (address *P){
    //Kamus lokal

    //Algoritma
    *P = (address) malloc(sizeof(ElmList));
}
 
/* procedure Dealokasi (P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address P){
    //Kamus lokal

    //ALgoritma
    free(P);
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V){
    //Kamus lokal
    address P;

    //Algoritma
    Alokasi(&P);
    if (P != NIL){
        info(P) = V;
        next(P) = First(*L);
        First(*L) = P;
    }
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V){
    //Kamus lokal
    address Last;
    address P;
    
    //Algoritma
    Alokasi(&P);
    info(P) = V;
    next(P) = NIL;
    Last = First(*L);
    if (IsEmptyList(*L)){
        InsertVFirst(L, V);
    }else{
        while (next(Last) != NIL){
            Last = next(Last);
        }
        next(Last) = P;
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
    //Kamus lokal
    address P;

    //Algortima
    P = First(*L);
    *V = info (P);
    First(*L) = next(P);
    Dealokasi(P);
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
    //Kamus lokal
    address Last;
    address P;

    //Algortima
    if (IsEmptyList(*L)){
        DeleteVFirst(L,V);
    }else{
        Last = First(*L);
        while (next(next(Last)) != NIL){
            Last = next(Last);
        }
        P = next(Last);
        *V = info(Last);
        next(Last) = NIL;
        Dealokasi(P);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
    //Kamus lokal
    address P;

    //Algoritma
    *A = NIL;
    P = First(L);
    while (P != NIL && *A == NIL){
        if (info(P) == X){
            *A = P;
        }
        P = next(P);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
    //Kamus lokal
    address P;
    address A;

    //Algortima
    P = First(*L);
    A = NIL;
    while(!IsEmptyList(*L) && A == NIL){
        if (info(P) == X){
            A = P;
            info(A) = Y;
        }
    P = next(P);
    }
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List1 *L){
    //Kamus lokal
    address P;
    List1 Lb;

    //Algoritma
    CreateList(&Lb);
    Alokasi(&P);
    P = First(*L);
    while (P != NIL){
        InsertVFirst(&Lb, info(P));
        P = next(P);
    }
    (*L) = Lb;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L){
    //Kamus lokal
    address P;
    int count;

    //Algoritma
    P = First(L);
    count = 0;
    while (P != NIL){
        if (info(P) == 'X'){
            count = count + 1;
        }
        P = next(P);
    }
    return count;
}

/*function FrekeuensiX(L:List1) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekeuensiX(List1 L){
    //Kamus lokal

    //Algoritma
    return (float) CountX(L)/NbElm(L);
}

/*function Modus(L:List1) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List1 L){
    //Kamus lokal
    address P;
    address Q;
    char modus;
    int count;
    int max;

    //Algoritma
    P = First(L);
    while (P != NIL){
        count = 0;
        max = 0;
        Q = First(L);
        while (Q != NIL){
            if (info(P) == info(Q)){
                count++;
            }
            Q = next(Q);
        }
        if (count > max){
            max = count;
            modus = info(P);
        }
        P = next(P);
    }
    return modus;
}

// /*Procedure SearchAllX(input L:List1, input X:infotype)
// { I.S. L, X terdefinisi }
// { F.S. -
// Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
    //Kamus lokal
    address P;
    int count;

    //Algortima
    count = 0;
    P = First(L);
    while (P != NIL){
        if (info(P) == X){
            printf("%d ", count);
        }
        count++;
        P = next(P);
    }

}

// /* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
// { I.S. List L mungkin kosong, V, S terdefinisi }
// { F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
// { Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ){
    //Kamus lokal
    address P;
    address Q;

    //Algoritma
    Alokasi(&P);
    Alokasi(&Q);
    info(P) = VA;
    Q = First(*L);
    while (info(Q) != V){
        Q = next(Q);
    }
    next(P) = next(Q);
    next(Q) = P;
}
