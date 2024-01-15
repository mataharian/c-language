#include <stdio.h>
#include "tqueue.c"

/***********************************/
/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 22 September 2023*/
/***********************************/

int main(void){
    //Kamus
    tqueue A, B;
    char e;

    //Algoritma
    printf("=============Create Queue=============\n");
    createQueue(&A);
    printf("Queue A = ");
    printQueue(A);
    printf("\n");
    printf("head : %d \n", head(A));
    printf("tail : %d \n", tail(A));
    printf("Size : %d \n", sizeQueue(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement(A) == 1? "True" : "False");
    printf("\n");

    createQueue(&B);
    printf("Queue B = ");
    printQueue(B);
    printf("\n");
    printf("head : %d \n", head(B));
    printf("tail : %d \n", tail(B));
    printf("Size : %d \n", sizeQueue(B));
    printf("isEmptyQueue? %s \n", isEmptyQueue(B) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue(B) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement(B) == 1? "True" : "False");
    printf("\n");


    printf("============Menambah Queue============\n");
    enqueue(&A, 'a');
    enqueue(&A, 'b');
    enqueue(&A, 'c');
    enqueue(&A, 'd');
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("head : %d \n", head(A));
    printf("tail : %d \n", tail(A));
    printf("Size : %d \n", sizeQueue(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement(A) == 1? "True" : "False");
    printf("\n");

    enqueue(&B, 'e');
    enqueue(&B, 'f');
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");
    printf("head : %d \n", head(B));
    printf("tail : %d \n", tail(B));
    printf("Size : %d \n", sizeQueue(B));
    printf("isEmptyQueue? %s \n", isEmptyQueue(B) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue(B) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement(B) == 1? "True" : "False");
    printf("\n");


    printf("===========Mengurangi Queue===========\n");
    dequeue(&A, &e);
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("head : %d \n", head(A));
    printf("tail : %d \n", tail(A));
    printf("Size : %d \n", sizeQueue(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement(A) == 1? "True" : "False");
    printf("\n");

    dequeue(&B, &e);
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");
    printf("head : %d \n", head(B));
    printf("tail : %d \n", tail(B));
    printf("Size : %d \n", sizeQueue(B));
    printf("isEmptyQueue? %s \n", isEmptyQueue(B) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue(B) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement(B) == 1? "True" : "False");
    printf("\n");

    printf("==============Max Length==============\n");
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");
    printf("Size queue terpanjang = %d \n", maxlength(A, B));
    printf("\n");


    printf("===============Enqueue2===============\n");
    printf("Sebelum : \n");
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");
    enqueue2(&A, &B, 'g');
    printf("\n");

    printf("Sesudah : \n");
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");
    printf("\n");


    printf("===============Dequeue2===============\n");
    printf("Sebelum : \n");
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");
    dequeue2(&A, &B, &e);
    printf("\n");

    printf("Sesudah : \n");
    printf("Queue A = ");
    viewQueue(A);
    printf("\n");
    printf("Queue B = ");
    viewQueue(B);
    printf("\n");


    return 0;
}