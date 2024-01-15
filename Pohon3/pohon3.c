#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list1.c"
#include "pohon3.h"

/* DEFINISI bintree3 kosong = NIL = ( ) ))*/

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* procedure Alokasi (output P:bintree3) */ 
/* {I.S. - 
    F.S. P ter-alokasi 
	Proses: Memesan ruang memori untuk bintree3 P} */
void Alokasi3 (bintree3 *P){
    //Kamus lokal

    //Algoritma
    (*P) = (bintree3) malloc (sizeof(node3));
}
 
/* procedure Dealokasi (input/output P:bintree3) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree3 P} */
void Dealokasi3 (bintree3 *P){
    //Kamus lokal

    //Algoritma
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN bintree3 KOSONG ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
    //Kamus lokal
    bintree3 P;

    //Algoritma
    Alokasi3(&P);
    if(P != NIL){
        parent(P) = A;
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
    }
    return P;
}

/****** SELEKTOR *****/

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P){
    //Kamus lokal

    //Algoritma
    return P == NIL;

}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL) && (left(P) == NIL) && (right(P) == NIL); 
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL) && (left(P) != NIL) && (right(P) != NIL); 
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL) && (left(P) != NIL) && (right(P) == NIL); 
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P){
    //Kamus lokal

    //Algoritma
    return (P != NIL) && (left(P) == NIL) && (right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree3 P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree3 P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        printf("( )");
    } else{
        printf("%c(", info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P){
    //Kamus lokal
    
    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    } else{
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P){
    //Kamus lokal
    
    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    } else if (IsDaun(P)){
        return 1;
    }else{
        return NbDaun(left(P)) + NbDaun(right(P));
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

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P) || NbElmTree(P) == 1){
        return 0;
    }else{
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }else{
        if (NbElmTree(P) == 1){
            return 1;
        } else{
            if (Level(left(P)) != 0){
                return Level(left(P)) + 1;
            } else if(Level(right(P)) != 0){
                return Level(right(P)) + 1;
            } else{
                return 0;
            }
        }
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }else if (T == 1){
        return 1;
    } else{
        return CountLevelT(left(P),T-1) + CountLevelT(right(P),T-1);
    }
}

/*** operator khusus List1 ***/
//printList sudah ADA di List1.h

/*procedure concat( input/output Asli:List1, input Tambahan:List1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void pconcat(List1 *Asli, List1 Tambahan){
    //Kamus lokal
    address P;

    //Algoritma
    if (IsEmptyList(*Asli)){
        *Asli = Tambahan;
    } else{
        P = First(*Asli);
        while (next(P) != NIL){
            P = next(P);
        }
        next (P) = First(Tambahan);
    }
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 fconcat(List1 Asli, List1 Tambahan){
    //Kamus lokal
    address P;
    List1 B;

    //Algoritma
    if (IsEmptyList(Asli)){
        return Tambahan;
    } else{
        B = Asli;
        P = First(B);
        while (next(P) != NIL){
            P = next(P);
        }
        next (P) = First(Tambahan);
        return B;
    }
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 linearPrefix(bintree3 P){
    //Kamus lokal
    List1 L;

    //Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)){
        InsertVLast(&L, info(P));
        pconcat(&L, linearPrefix(left(P)));
        pconcat(&L, linearPrefix(right(P)));
    }
    return L;
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 linearPosfix(bintree3 P){
    //Kamus lokal
    List1 L;

    //Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)){
        pconcat(&L, linearPrefix(left(P)));
        pconcat(&L, linearPrefix(right(P)));
        InsertVLast(&L, info(P));
    }
    return L;
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 linearInfix(bintree3 P){
    //Kamus lokal
    List1 L;

    //Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)){
        pconcat(&L, linearPrefix(left(P)));
        InsertVLast(&L, info(P));
        pconcat(&L, linearPrefix(right(P)));
    }
    return L;
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 linearBFSHelper (bintree3 P, int T){
    /*Kamus Lokal*/
    List1 L;

    /*Algoritma*/
    CreateList(&L);
    if (P != NIL){
        if (T == 1){
            InsertVFirst(&L,info(P));
        }
        else{
            pconcat(&L, linearBFSHelper(right(P),T-1));
            pconcat(&L, linearBFSHelper(left(P),T-1));

        }
    }
    return L;
}

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 linearBreadthFS(bintree3 P){
    //Kamus lokal
    List1 L;
    int lv;

    //Algoritma
    CreateList(&L);
    if (!IsEmptyTree(P)) {
        for (lv = Level(P); lv >= 1; lv--){
            pconcat(&L, linearBFSHelper(P,lv));
        }
    }
    Invers(&L);
    return L;
}


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
boolean cariX(bintree3 P, infotype X){
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)){
        return false;
    }
    else {
        if (akar(P) == X){
            return true;
        }
        else {
            return cariX(left(P), X) || cariX(right(P), X);
        }
    }
}

void printPathX(bintree3 P, infotype X){
    //kamus lokal
    boolean ketemu;

    //algoritma
    ketemu = false;
    if (!IsEmptyTree(P) && ketemu == false && cariX(P, X)){
        printf("%c ", info(P));
        if (cariX(left(P), X)){
            printPathX(left(P), X);
        }
        else {
            if (cariX(right(P), X)){
                printPathX(right(P), X);
            }
        }
        if (info(P) == X){
            ketemu = true;
        }
    }
}

boolean cariDaunX(bintree3 P, infotype X){
    //kamus lokal

    //algoritma
    if (IsEmptyTree(P)){
        return false;
    }
    else {
        if (akar(P) == X && IsDaun(P)){
            return true;
        }
        else {
            return cariDaunX(left(P), X) || cariDaunX(right(P), X);
        }
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X){
    //kamus lokal
    boolean ketemu;

    //algoritma
    ketemu = false;
    if (!IsEmptyTree(P) && ketemu == false && cariDaunX(P, X)){
        printf("%c ", info(P));
        if (cariDaunX(left(P), X)){
            printPathX(left(P), X);
        }
        else {
            if (cariDaunX(right(P), X)){
                printPathX(right(P), X);
            }
        }
        if (info(P) == X){
            ketemu = true;
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P){
    //Kamus lokal

    //Algoritma
    if (!IsEmptyTree(P)) {
        printf("%c ", info(P));
        if (IsDaun(P)) {
            printf("\n");
        } else {
            printAllPaths(left(P));
            printAllPaths(right(P));
        }
    }
}