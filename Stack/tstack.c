#include <stdio.h>
#include "tstack.h"
/***********************************/
/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 15 September 2023*/
/***********************************/

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    //Kamus lokal
    int i;
    //Algoritma
    for (i = 1; i <= 10; i++){
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    //Kamus lokal
    
    //Algoritma
    if (top(T) == 0){
        return true;
    }else{
        return false;
    }
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    //Kamus lokal
    
    //Algoritma
    if (top(T) == 10){
        return true;
    }else{
        return false;
    }
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    //Kamus lokal

    //ALgoritma
    if (isFullStack(*T)){
        printf("Stack Penuh!!! \n");
    }else{
        (*T).top = top(*T) + 1;
        (*T).wadah[top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    //Kamus lokal

    //ALgoritma
    if (isEmptyStack(*T)){
        printf("Stack Kosong!!! \n");
    }else{
        (*X) = infotop(*T);
        (*T).wadah[top(*T)] = '#';
        (*T).top = top(*T) - 1;
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    //Kamus lokal
    int i;
    //Algoritma
    for (i=10; i >= 1; i--){
        printf("%c; \n", T.wadah[i]);
    }
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    //Kamus lokal
    int i;
    //Algoritma
    for (i=top(T); i >= 1; i--){
        printf("%c; \n", T.wadah[i]);
    }
}

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    //Kamus lokal
    int i;
    char X;
    //Algoritma
    int max = top(*T) + N;
    if (max <= 10){
        for (i = top(*T)+1; i <= max; i++){
            printf("Elemen ke-%d: ", i);
            scanf(" %c", &X);
            push(T, X);
        }
    }else{
        printf("N Melewati ukuran stack!!! \n");
    }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E){
    //Kamus Lokal
    
    //Algoritma
    if (isFullStack(*T)){
        createStack(&(*T));
    }else{
        push(&(*T), E);
    }

}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E){
    //Kamus Lokal

    //ALgoritma
    if(infotop(*T) == E){
        (*T).wadah[top(*T)] = '#';
        (*T).top = top(*T) - 1;
    }else{
        push(&(*T), E);
    }
}


