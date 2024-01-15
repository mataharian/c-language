#include <stdio.h>
#include "tqueue.h"
/***********************************/
/* Program   : tqueue.c */
/* Deskripsi : file BODY modul queue karakter */
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 22 September 2023*/
/***********************************/

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '$', head=tail=0 }*/ 
void createQueue(tqueue *Q){
    //Kamus lokal
    int i;
    
    //Algoritma
    for(i = 1; i <= 5; i++){
        (*Q).wadah[i] = '$';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
int infoHead(tqueue Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[head(Q)];
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
int infoTail(tqueue Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[tail(Q)];
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q){
    //Kamus lokal
    
    //Algoritma
     return tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = 1; i <= 5; i++){
        printf("%c", Q.wadah[i]);
        if (i != 5){
            printf(", ");
        }
    }
    printf("]");
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = 1; i <= tail(Q); i++){
        printf("%c", Q.wadah[i]);
        if (i != tail(Q)){
            printf(", ");
        }
    }
    printf("]");
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q){
    //Kamus lokal

    //Algoritma
    if (tail(Q) == 0){
        return true;
    }else{
        return false;
    }
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q){
    //Kamus lokal

    //Algoritma
    if (tail(Q) == 5){
        return true;
    }else{
        return false;
    }
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q){
    //Kamus lokal

    //Algoritma
    if (sizeQueue(Q) == 1){
        return true;
    }else{
        return false;
    }
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: Q,E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E){
    //Kamus lokal

    //Algoritma
    if (isFullQueue(*Q)){
        printf("Queue Penuh!!!");
    }else{
        if (head(*Q) == 0){
            (*Q).head = head(*Q) + 1;
        }
        (*Q).tail = tail(*Q) + 1;
        (*Q).wadah[tail(*Q)] = E;
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead(Q) atau E=' ' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E){
    //Kamus lokal
    int i;
    //Algoritma
    if(isEmptyQueue(*Q)){
        printf("Queue Kosong!!!");
    }else{
        (*E) = infoHead(*Q);
        if (isOneElement(*Q)){
            createQueue(Q);
        }else{
            for (i = 1; i <= tail(*Q); i++){
                (*Q).wadah[i] = (*Q).wadah[i+1];
            } (*Q).tail = tail(*Q) - 1;
        }
    }
}

/*tambahan, dikerjakan bila cukup waktu */

/*function maxlength(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int maxlength(tqueue Q1, tqueue Q2){
    //Kamus lokal

    //Algoritma
    if (sizeQueue(Q1) > sizeQueue(Q2)){
        return sizeQueue(Q1);
    }else{
        return sizeQueue(Q2);
    }

}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char E){
    //Kamus lokal

    //Algortima
    if (sizeQueue(*Q1) > sizeQueue(*Q2)){
        enqueue(&(*Q2), E);
    }else{
        enqueue(&(*Q1), E);
    }
}

/*procedure deQueue2( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2 atau E=' ' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *E){
    //Kamus lokal

    //Algoritma
    if (sizeQueue(*Q1) > sizeQueue(*Q2)){
        dequeue(&(*Q1), &(*E));
    }else{
        dequeue(&(*Q2), &(*E));
    }
}