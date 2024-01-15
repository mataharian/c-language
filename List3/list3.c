/* File : list1.c */
/* Deskripsi : file body modul list berkait dengan representasi fisik pointer  */
/* NIM & Nama : 20460122120034/Dzu Sunan Muhammad*/
/* Tanggal : 17 November 2023*/

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L){
    //Kamus lokal

    //Algoritma
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L){
    //Kamus lokal

    //Algoritma
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List3 L){
    //Kamus lokal
    address P;

    //ALgoritma
    P = First(L);
    printf("List L = [");
    if (!IsEmptyList(L)){
        do{
            printf("%c", info(P));
            if (next(P) != First(L)){
                printf(", ");
            }
            P = next(P);
        }while (P != First(L));
    }
    printf("] \n");
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L){
    //Kamus lokal
    address P;
    int Len;

    //Algoritma
    Len = 0;
    P = First(L);
    if (P != NIL){
        Len = 1;
        while (next(P) != First(L)){
            Len = Len + 1;
            P = next(P);
        }
    }
    return Len;
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
    *P = (address) malloc (sizeof(ElmList3));
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
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ){
    //Kamus lokal
    address P;
    address Last;

    //Algortima
    Alokasi(&P);
    if (P != NIL){
        info(P) = V;
        if (IsEmptyList(*L)){
            First(*L) = P;
            next(P) = P;
        }else{
            Last = First(*L);
            while (next(Last) != First(*L)){
                Last = next(Last);
            }
            next(P) = First(*L);
            First(*L) = P;
            next(Last) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ){
    //Kamus lokal
    address P;
    address Last;

    //Algoritma
    Alokasi(&P);
    if (P != NIL){
        info(P) = V;
        if (IsEmptyList(*L)){
            First(*L) = P;
            next(P) = P;
        }else{
            Last = First(*L);
            while (next(Last) != First(*L)){
                Last = next(Last);
            }
            next(Last) = P;
            next(next(Last)) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V){
    //Kamus lokal
    address P;

    //Algortima
    if (First(*L) != NIL){
        P = First(*L);
        *V = info(P);
        if (next(P) == P){
            First(*L) = NIL;
        }else{
            while (next(P) != First(*L)){
                P = next(P);
            }
            next(P) = next(First(*L));
            P = First(*L);
            First(*L) = next(P);
        }
        Dealokasi(&P);
    }
}


/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V){
    //Kamus lokal
    address P;
    address Last;

    //Algoritm
    if (First(*L) != NIL){
        P = First(*L);
        *V = info(P);
        if (next(P) == First(*L)){
            First(*L) = NIL;
        }else{
            Last = First(*L);
            while (next(next(Last)) != First(*L)){
                Last = next(Last);
            }
            P = next(Last);
            next(Last) = First(*L);
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteX(List3 *L, infotype X){
    //Kamus lokal
    address AX;
    address BX;

    //Algortima
    if (First(*L) != NIL){
        AX = First(*L);
        while (next(AX) != First(*L) && info(AX) != X){
            AX = next(AX);
        }
        if (info(AX) == X){
            if (next(AX) == AX){
                First(*L) = NIL;
            }else{
                BX = First(*L);
                while (next(BX) != AX){
                    BX = next(BX);
                }if (AX == First(*L)){
                    First(*L) = next(AX);
                }
                next(BX) = next(AX);
            }
            Dealokasi(&AX);
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A){
    //Kamus lokal
    address P;

    //Algoritma
    P = First(L);
    *A = NIL;
    do{
        if (info(P) == X){
            *A = P;
        }
        P = next(P);
    } while (P != First(L) && *A == NIL);
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List3 *L, infotype X, infotype Y){
    //Kamus lokal
    address P;

    //Algoritma
    P = First(*L);
    do{
        if (info(P) == X){
            info(P) = Y;
        }
        P = next(P);
    } while (P != First(*L));
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L){
    //Kamus lokal
    address P;
    List3 Lb;

    //Algoritma
    CreateList(&Lb);
    Alokasi(&P);
    P = First(*L);
    do{
        InsertVFirst(&Lb, info(P));
        P = next(P);
    } while (P != First(*L));
    (*L) = Lb;
}


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X){
    //Kamus lokal
    address P;
    int count;

    //Algortima
    P = First(L);
    count = 0;
    do{
        if (info(P) == X){
            count = count + 1;
        }
        P = next(P);
    } while (P != First(L));
    return count;
}
    

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X){
    //Kamus lokal

    //Algortima
    return (float) CountX(L,X)/NbElm(L);
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L){
    //Kamus lokal
    address P;
    int count;
    int max;
    char modus;

    //Algortima
    P = First(L);
    max = 0;
    count = 0;
    do{
        count = CountX(L,info(P));
        if (count > max){
            max = count;
            modus = info(P);
        }
        P = next(P);
    } while (P != First(L));
    return modus;
}
    

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L){
    //Kamus lokal
    address P;
    int count;

    //Algoritma
    P = First(L);
    count = 0;
    do{
        if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O'){
                count = count + 1;
            }
            P = next(P);
    } while (P != First(L));
    return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L){
    //Kamus lokal
    address P;
    int count;

    //Algoritma
    count = 0;
    if (NbElm(L) >= 2){
        P = First(L);
        do{
            if (info(P) == 'N' && info(next(P)) == 'G'){
                count = count + 1;
            }
            P = next(P);
        } while (P != First(L));  
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V){
    //Kamus lokal
    address P;
    address AX;

    //Algoritma
    if (!IsEmptyList(*L)){
        AX = First(*L);
        while (info(AX) != X && next(AX) != First(*L)){
            AX = next(AX);
        }
        if (info(AX) == X){
            Alokasi(&P);
            if (P != NIL){
                info(P) = V;
                next(P) = next(AX);
                next(AX) = P;
            }            
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V){
    //Kamus lokal
    address P;
    address AX;
    address Last;

    //Algoritma
    if (!IsEmptyList(*L)){
        AX = First(*L);
        do{
            AX = next(AX);
        } while (info(next(AX)) != X && AX != First(*L));
        if (info(next(AX)) == X){
            Alokasi(&P);
            if (P != NIL){
                info(P) = V;
                if (next(AX) != First(*L)){
                    next(P) = next(AX);
                    next(AX) = P;
                }else{
                    Last = First(*L);
                    while (next(Last) != First(*L)){
                        Last = next(Last);
                    }
                    next(P) = First(*L);
                    First(*L) = P;
                    next(Last) = First(*L);
                }
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V){
    //Kamus lokal
    address P;
    address AX;

    //Algoritma
    if (NbElm(*L) >= 2){
        AX = First(*L);
        while (info(AX) != X && next(AX) != First(*L)){
            AX = next(AX);
        }
        P = next(AX);
        if (info(AX) == X){
            if (next(AX) == First(*L)){
                First(*L) = next(P);
            }
            P = next(AX);
            *V = info(P);
            next(AX) = next(P);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V){
    //Kamus lokal
    address P;
    address AX;

    //Algoritma
    if (NbElm(*L) >= 2){
        AX = First(*L);
        do{
            AX = next(AX);
        } while (info(next(next(AX))) != X && AX != First(*L));
        if (info(next(next(AX))) == X){
            P = next(AX);
            *V = info(P);
            if (next(AX) == First(*L)){
                First(*L) = next(P);
            }
            next(AX) = next(P);
            Dealokasi(&P);
        }
    }
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,2) menampilkan angka 1,6,9 */
/*misal L=[2,5,3,7,1,2,5,3,2], SearchAllX(L,8) menampilkan angka 0 */
void SearchAllX(List3 L, infotype X){
    //Kamus lokal
    address P;
    int count;

    //Algortima
    count = 0;
    P = First(L);
    do{
        if (info(P) == X){
            printf("%d ", count);
        }
        count = count + 1;
        P = next(P);
    } while (P != First(L));
}
