/* File : list1.c */
/* Deskripsi : file body modul list berkait dengan representasi fisik pointer  */
/* NIM & Nama : 20460122120034/Dzu Sunan Muhammad*/
/* Tanggal : 10 November 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:list2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (list2 *L){
    //Kamus lokal

    //Algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:list2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (list2 L){
    //Kamus lokal

    //Algoritma
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:list2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(list2 L){
    //Kamus lokal
    address P;

    //ALgoritma
    P = First(L);
    while (P != NIL){
        printf("%c \n", info(P));
        P = next(P);
    }
}

/*function NbElm(L:list2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(list2 L){
    //Kamus lokal
    address P;
    int count;

    //Algoritma
    P = First(L);
    count = 0;
    while (P != NIL){
        count = count + 1;
        P = next(P);
    }
    return count;
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
    *P = (address) malloc (sizeof(ElmList2));
}
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //Kamus lokal

    //Algoritma
    free(P);
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(list2 *L, infotype V ){
    //Kamus lokal
    address P;

    //Algoritma
    Alokasi(&P);
    if (P != NIL){
        info(P) = V;
        if (First(*L) == NIL){
            First(*L) = P;
            prev(P) = NIL;
            next(P) = NIL;
        }else{
            next(P) = First(*L);
            prev(P) = NIL;
            prev(First(*L)) = P;
            First(*L) = P;
        }
    }

}

/*Procedure InsertVLast(input/output L:list2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(list2 *L, infotype V ){
    //Kamus lokal
    address P;
    address Last;

    //ALgoritma
    Alokasi(&P);
    if (P != NIL){
        if (First(*L) == NIL){
            InsertVFirst(L, V);
        }else{
            info(P) = V;
            next(P) = NIL;
            Last = First(*L);
            while (next(Last) != NIL){
                Last = next(Last);
            }
            prev(P) = Last;
            next(Last) = P;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(list2 *L, infotype *V){
    //Kamus lokal
    address P;

    //Algoritma
    P = First(*L);
    if (P != NIL){
        *V = info(P);
        First(*L) = next(P);
        if (next(P) != NIL){
            prev(First(*L)) = NIL;
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:list2, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(list2 *L, infotype *V){
    //Kamus lokal
    address Last;

    //Algoritma
    Last = First(*L);
    if (Last != NIL){
        while (next(Last) != NIL){
            Last = next(Last);
        }
        *V = info(Last);
        if (prev(Last) == NIL){
            Last = NIL;
        }else{
            next(prev(Last)) = NIL;
        }
        Dealokasi(&Last);
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(list2 *L, infotype X){
    //Kamus lokal
    // address P;
    address AX;
    infotype V;

    //Algoritma
    if (First(*L) != NIL){
        AX = First(*L);
        while (info(AX) != X && AX != NIL){
            AX = next(AX);
        }
        if (info(AX) == X){
            if (prev(AX) == NIL){
                DeleteVFirst(L, &V);
            }else{
                if (next(AX) == NIL){
                    DeleteVLast(L,&V);
                }else{
                    V = info(AX);
                    next(prev(AX)) = next(AX);
                    prev(next(AX)) = prev(AX);
                }
            }
            Dealokasi(&AX);
        }        
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:list2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(list2 L, infotype X, address *A){
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
/*Procedure UpdateX(input/output L:list2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(list2 *L, infotype X, infotype Y){
    //Kamus lokal
    address P;

    //Algoritma
    P = First(*L);
    while (P != NIL){
        if (info(P) == X){
            info(P) = Y;
        }
        P = next(P);
    }
}

/*Procedure Invers(input/output L:list2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(list2 *L){
    //Kamus lokal
    address P;
    list2 Lb;

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
/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(list2 *L, infotype X, infotype V){
    //Kamus lokal
    address P;
    address AX;

    //Algoritma
    if (First(*L) != NIL){ //Minimal 1 elemen
        AX = First(*L);
        while (info(AX) != X && next(AX) != NIL){ 
            AX = next(AX);
        }
        if (info(AX) == X){ 
            Alokasi(&P);
            if (P != NIL){ 
                info(P) = V;
                next(P) = next(AX);
                prev(P) = AX;
                if (next(AX) != NIL){ 
                    prev(next(AX)) = P;
                }
                next(AX) = P;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(list2 *L, infotype X, infotype V){
    //Kamus lokal
    address P;
    address AX;

    //Algoritma
    if (First(*L) != NIL){
        AX = First(*L);
        while (info(AX) != X && next(AX) != NIL){
            AX = next(AX);
        }
        if (info (AX) == X){
            Alokasi(&P);
            if (P != NIL){
                info(P) = V;
                next(P) = AX;
                prev(P) = prev(AX);
                if (prev(AX) != NIL){
                    next(prev(AX)) = P;
                }else{
                    First(*L) = P;
                }
                prev(AX) = P;
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(list2 *L, infotype X, infotype *V){
    // kamus lokal
    address AX;
    address P;

    // algoritma
    if(NbElm(*L) >= 2){
        AX = First(*L);
        while(info(AX) !=X && next(AX) != NIL){
            AX = next(AX);
        }
        if (info(AX) == X){
            if (next(AX) != NIL){
                P = next(AX);
                *V = info(P);
                next(AX) = next(P); 
                next(P) = AX;
                Dealokasi(&P);
            }
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(list2 *L, infotype X, infotype *V){
    //Kamus lokal
    address AX;
    address P;

    //Algoritma
    if(NbElm(*L) >= 2){
        AX = First(*L);
        while (info(AX) != X && next(AX) != NIL){
            AX = next(AX);
        }
        if (info(AX) == X){
            if (prev(AX) != NIL){
                P = prev(AX);
                *V = info(P);
                if (prev(P) != NIL){
                    next(prev(P)) = AX;
                    prev(AX) = prev(P);
                }
                else {
                    if (P != NIL){
                        prev(AX) = NIL;
                        First(*L) = AX;
                    }
                }
                Dealokasi(&P);
            }
        }
    }
}

/*function CountX(L:list2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(list2 L, infotype X){
    //Kamus lokal
    address P;
    int count;

    //Algoritma
    count = 0;
    P = First(L);
    while (P != NIL){
        if (info(P) == X){
            count = count + 1;
        }
        P = next(P);
    }
    return count;
}

/*function FrekuensiX(L:list2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(list2 L, infotype X){
    //Kamus lokal

    //Algoritma
    return (float) CountX(L,X)/NbElm(L);
}

/*function Modus(L:list2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(list2 L){
    //Kamus lokal
    address P;
    address Q;
    int count;
    int max;
    char modus;

    //Algortima
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

/*Procedure SearchAllX(input L:list2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,2) menampilkan angka 1,6,9 */
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,8) menampilkan angka 0 */
void SearchAllX(list2 L, infotype X){
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
