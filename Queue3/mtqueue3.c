#include <stdio.h>
#include "tqueue3.c"

/***********************************/
/* Program   : tqueue3.h */
/* Deskripsi : file DRIVER modul queue karakter model III*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 6 Oktober 2023*/
/***********************************/

int main(void){
    //Kamus
    tqueue3 A;
    char e;

    //Algoritma
    printf("=============Create Queue=============\n");
    createQueue3(&A);
    printf("Queue A = ");
    printQueue3(A);
    printf("\n");
    printf("head : %d \n", head3(A));
    printf("tail : %d \n", tail3(A));
    printf("Size : %d \n", sizeQueue3(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue3(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement3(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue3(A) == 1? "True" : "False");
    printf("isTailOverHead? %s \n", isTailOverHead(A) == 1? "True" : "False");
    printf("\n");

    printf("============Menambah Queue============\n");
    enqueue3(&A, 'a');
    enqueue3(&A, 'b');
    enqueue3(&A, 'c');
    printf("Queue A = ");
    viewQueue3(A);
    printf("\n");
    printf("head : %d \n", head3(A));
    printf("tail : %d \n", tail3(A));
    printf("Size : %d \n", sizeQueue3(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue3(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement3(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue3(A) == 1? "True" : "False");
    printf("isTailOverHead? %s \n", isTailOverHead(A) == 1? "True" : "False");
    printf("\n");

    printf("===========Mengurangi Queue===========\n");
    dequeue3(&A, &e);
    printf("Queue A = ");
    printQueue3(A);
    printf("\n");
    printf("head : %d \n", head3(A));
    printf("tail : %d \n", tail3(A));
    printf("Size : %d \n", sizeQueue3(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue3(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement3(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue3(A) == 1? "True" : "False");
    printf("isTailOverHead? %s \n", isTailOverHead(A) == 1? "True" : "False");
    printf("\n");

    printf("=============Count Member=============\n");
    printf("Queue A = ");
    printQueue3(A);
    printf("\n");
    printf("Jumlah huruf e = %d \n", countMember(A,'e'));
    printf("\n");

    printf("==============Enqueue3E===============\n");
    enqueue3E(&A, 'a');
    enqueue3E(&A, 'd');
    enqueue3E(&A, 'e');
    printf("Dengan PrintQueue \n");
    printf("Queue A = ");
    printQueue3(A);
    printf("\n");
    printf("Dengan ViewQueue \n");
    printf("Queue A = ");
    viewQueue3(A);
    printf("\n");
    printf("head : %d \n", head3(A));
    printf("tail : %d \n", tail3(A));
    printf("Size : %d \n", sizeQueue3(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue3(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement3(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue3(A) == 1? "True" : "False");
    printf("isTailOverHead? %s \n", isTailOverHead(A) == 1? "True" : "False");
    printf("\n");
    
    return 0;
}