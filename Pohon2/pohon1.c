/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal : 24 November 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree) */
/* {I.S. -
    F.S. P ter-alokasi
	Proses: Memesan ruang memori untuk bintree P} */
void Alokasi (bintree *P){
    //Kamus lokal

    //Algoritma
    (*P) = (bintree) malloc (sizeof(node));

} //representasi fisik prosedur
//bintree Alokasi(); //representasi fisik fungsi

/* procedure Dealokasi (input/output P:bintree) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P){
    //Kamus lokal

    //Algortima
    free(*P);
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right){
    //Kamus lokal
    bintree P;

    //Algoritma
    Alokasi(&P);
    if(P != NIL){
        info(P) = akar;
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P){
    //Kamus lokal

    //Algoritma
    return info(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    //Kamus lokal

    //Algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    //Kamus lokal

    //Algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    //Kamus lokal

    //Algoritma
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    //Kamus lokal

    //Algoritma
    return (GetLeft(P) == NIL) && (GetRight(P) == NIL);
}

/* function IsBiner (P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    //Kamus lokal

    //Algoritma
    return (GetLeft(P) != NIL) && (GetRight(P) != NIL);
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    //Kamus lokal

    //Algoritma
    return (GetLeft(P) != NIL) && (GetRight(P) == NIL);
}

/* function IsUnerRight(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    //Kamus lokal

    //Algoritma
    return (GetLeft(P) == NIL) && (GetRight(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        printf("( )");
    } else{
        printf("%c(", GetAkar(P));
        PrintPrefix(GetLeft(P));
        printf(",");
        PrintPrefix(GetRight(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    //Kamus lokal
    
    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    } else{
        return 1 + NbElm(GetLeft(P)) + NbElm(GetRight(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
// { Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
    //Kamus lokal
    
    //Algoritma
    if (!IsBiner(P)){
        return 1;
    }else{
        return NbDaun(GetLeft(P)) + NbDaun(GetRight(P));
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b){
    //Kamus lokal

    //Algoritma
    if (a > b){
        return a;
    }else{
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P) || NbElm(P) == 1){
        return 0;
    }else{
        return 1 + max2(Tinggi(GetLeft(P)), Tinggi(GetRight(P)));
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, temp:infotype) -> boolean
{ Mengirimkan true jika ada node dari P yang bernilai temp }*/
boolean SearchX(bintree P, infotype temp){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return false;
    }else{
        if (GetAkar(P) == temp){
            return true;
        }else{
            return SearchX(GetLeft(P),temp) || SearchX(GetRight(P),temp);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input temp:infotype, input Y:infotype)
{ I.S. L, temp, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai temp berubah menjadi Y.
Mengganti elemen bernilai temp menjadi Y}*/
void UpdateX(bintree *P, infotype temp, infotype Y){
    //Kamus lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if (GetAkar(*P) == temp){
            info(*P) = Y;
        }else {
            UpdateX(&left(*P), temp, Y);
            UpdateX(&right(*P), temp, Y);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, temp:infotype) -> integer
{ Mengirimkan banyaknya node dari P yang bernilai temp }*/
int CountX(bintree P, infotype temp){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }else{
        if (info(P) == temp){
            return 1 + CountX(GetLeft(P),temp) + CountX(GetRight(P),temp);
        }else{
            return CountX(GetLeft(P),temp) + CountX(GetRight(P),temp);
        }
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    //Kamus lokal

    //Algoritma
    if (IsUnerLeft(P)){
        return true;
    } else{
        return GetRight(P) == NIL && IsSkewLeft(GetLeft(P));
    }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    //Kamus lokal

    //Algoritma
    if (IsUnerRight(P)){
        return true;
    } else{
        return GetLeft(P) == NIL && IsSkewRight(GetRight(P));
    }
}

/* procedure PrintPref(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPref(bintree P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        printf("( )");
    } else{
        printf("%c", GetAkar(P));
        if (GetLeft(P) != NIL || GetRight(P) != NIL){
            printf("(");
            PrintPref(GetLeft(P));
            if (GetRight(P) != NIL){
                printf(",");
                PrintPref(GetRight(P));
            }
            printf(")");
        }
    } 
}

/*function LevelX(P:BinTree, temp:infotype)-> integer
{ Mengirimkan level dari node temp yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype temp){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }else{
        if (GetAkar(P) == temp){
            return 1;
        }else{
            if (LevelX(GetLeft(P),temp) != 0){
                return LevelX(GetLeft(P),temp) + 1;
            }else if(LevelX(GetRight(P),temp) != 0){
                return LevelX(GetRight(P),temp) + 1;
            }else{
                return 0;
            }
        }
    }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }else if (T == 1){
        return 1;
    } else{
        return CountLevelT(GetLeft(P),T-1) + CountLevelT(GetRight(P),T-1);
    }
}

/*function GetDaunTerkiri(bintree P)-> infotype
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return '#';
    }else if(IsDaun(P)){
        return GetAkar(P);
    }else{
        return GetDaunTerkiri(GetLeft(P));
    }

}

/*function FrekuensiX(L:bintree, temp:infotype) -> real */
/*{ mengembalikan rasio kemunculan temp dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype temp){
    //Kamus lokal

    //Algoritma
    return (float) CountX(P,temp)/NbElm(P);
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(L)){
        return 0;
    }else{
        if (GetAkar(L) == 'A' || GetAkar(L) == 'I' || GetAkar(L) == 'U' || GetAkar(L) == 'E' || GetAkar(L) == 'O'){
            return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        }else{
            return CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
        }
    }
}

char Modus(bintree P){
    //kamus lokal
    infotype temp;
    int count;
    char modus;

    //algoritma
    if (!IsEmptyTree(P)) {
        temp = GetAkar(P);
        count = CountX(P, temp); 
        modus = temp; 
        if (CountX(P, Modus(GetLeft(P))) > count) {
            modus = Modus(GetLeft(P));
            count = CountX(P, Modus(GetLeft(P)));
        }else if (CountX(P, Modus(GetRight(P))) > count) {
            modus = Modus(GetRight(P));
            count = CountX(P, Modus(GetRight(P)));
        }   
    }
    return modus;
}