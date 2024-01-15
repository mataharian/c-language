/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal : 01 Desember 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N){
    //Kamus lokal

    //Algortima
    if (!IsEmptyTree(P)){
        if (N == 1){
            printf(" %c\n", GetAkar(P));
        }else{
            PrintLevel(GetLeft(P), N-1);
            PrintLevel(GetRight(P), N-1);
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca }*/
bintree BuildBalanceTree(int n){
    //Kamus lokal
    bintree P;
    infotype X;

    //Algortima
    if (n == 0){
        return NIL;
    }else{
        Alokasi(&P);
        printf("Masukkan node: ");
        scanf(" %c",&X);
        P = Tree(X,NIL,NIL);
        left(P) = BuildBalanceTree(n/2);
        right(P) = BuildBalanceTree((n - 1)/2);
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    //Kamus lokal

    //Algoritma
    return abs(NbElm(GetLeft(P)) - NbElm(GetRight(P))) <= 1;
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(*P)){
        *P = Tree(X,NIL,NIL);
    }else{
        if (IsUnerRight(*P)){
            left(*P) = Tree(X,NIL,NIL);
        }else{
            AddDaunTerkiri(&left(*P),X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri){
    //Kamus lokal

    //Algoritma
    if (*P != NIL) {
        if (akar(*P) == X){
            if (Kiri){
                bintree daunKiri = Tree(Y, NIL, NIL);
                left(*P) = daunKiri;
            }
            else{
                bintree daunKanan = Tree(Y, NIL, NIL);
                right(*P) = daunKanan;
            }
        }else{
            AddDaun(&left(*P), X, Y, Kiri);
            AddDaun(&right(*P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X){
    //Kamus lokal

    //Algortima
    if (IsEmptyTree(*P)){
        *P = Tree(X, NIL, NIL);
    }else{
        if (GetAkar(*P) > X){
            InsertX(&left(*P),X);
        }else{
            InsertX(&right(*P),X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X){
    //Kamus lokal

    //Algoritma
    if(!IsEmptyTree(*P)){
        if(IsDaun(*P)){
            *X = GetAkar(*P);
            (*P) = NIL;
        }else if (IsBiner(*P)){
                if(NbElm(left(*P)) >= NbElm(right(*P))){
                    DelDaunTerkiri(&left(*P), X);
                }else{
                    DelDaunTerkiri(&right(*P), X);
                }
        }else{
            if(IsUnerLeft(*P)){
                DelDaunTerkiri(&left(*P), X);
            }else{
                DelDaunTerkiri(&right(*P), X);
            }
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X){
    //Kamus lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if (IsDaun(*P) && GetAkar(*P) == X){
            (*P) = NIL;
        }else{
            DelDaun(&left(*P),X);
            DelDaun(&right(*P),X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
    //Kamus Lokal
    bintree temp;
    infotype V;

    //Algoritma
    if (*P != NIL) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                Dealokasi(P);
                *P = NIL;
            } else if (IsUnerLeft(*P)) {
                temp = *P;
                *P = left(*P);
                Dealokasi(&temp);
            } else if (IsUnerRight(*P)) {
                temp = *P;
                *P = right(*P);
                Dealokasi(&temp);
            } else {
                DelDaunTerkiri(&(right(*P)), &V);
                info(*P) = V;
            }
        } else {
            DeleteX(&(left(*P)), X);
            DeleteX(&(right(*P)), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    //Kamus lokal

    //Algoritma
    if (!IsEmptyTree(*P)){
        if (GetAkar(*P) == X){
            info(*P) = Y;
    }
    UpdateAllX(&left(*P),X,Y);
    UpdateAllX(&right(*P),X,Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P){
    // Kamus Lokal
    infotype a;
    infotype b;

    // Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else {
        a = maxTree(GetLeft(P));
        b = maxTree(GetRight(P));
        if (GetAkar(P) >= a && GetAkar(P) >= b){
            return GetAkar(P);
        }
        else if (a > GetAkar(P) && a >= b){
            return a;
        }
        else {
            return b;
        }
    }
}
/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P){
    // Kamus Lokal
    infotype a;
    infotype b;

    // Algoritma
    if (IsEmptyTree(P)){
        return 0;
    }
    else {
        a = maxTree(GetLeft(P));
        b = maxTree(GetRight(P));
        if (GetAkar(P) <= a && GetAkar(P) <= b){
            return GetAkar(P);
        }
        else if (a < GetAkar(P) && a <= b){
            return a;
        }
        else {
            return b;
        }
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }*/

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
    //Kamus lokal

    //Algoritma
    if (IsEmptyTree(P)){
        return false;
    }else{
        if (GetAkar(P) == X){
            return true;
        }else{
            return SearchX(GetLeft(P),X) || SearchX(GetRight(P),X);
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
    //Kamus lokal
    bintree B;
    //Algoritma
    B = P;
    if (!IsEmptyTree(B)){
        if (BSearch(B,X) == false){
            AddDaunTerkiri(&B,X);
        }
    }
    return B;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
    //Kamus Lokal
    bintree temp;
    infotype V;

    //Algoritma
    if (*P != NIL) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                Dealokasi(P);
                *P = NIL;
            } else if (IsUnerLeft(*P)) {
                temp = *P;
                *P = left(*P);
                Dealokasi(&temp);
            } else if (IsUnerRight(*P)) {
                temp = *P;
                *P = right(*P);
                Dealokasi(&temp);
            } else {
                DelDaunTerkiri(&(right(*P)), &V);
                info(*P) = V;
            }
        } else {
            DelBtree(&(left(*P)), X);
            DelBtree(&(right(*P)), X);
        }
    }
}