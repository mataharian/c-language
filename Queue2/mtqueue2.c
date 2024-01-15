#include <stdio.h>
#include "tqueue2.c"

/***********************************/
/* Program   : tqueue2.h */
/* Deskripsi : file DRIVER modul queue karakter model II*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 29 September 2023*/
/***********************************/

int main(void){
    //Kamus
    tqueue2 A;
    tqueue2 B;
    char e;

    //Algoritma
    printf("=============Create Queue=============\n");
    createQueue2(&A);
    printf("Queue A = ");
    printQueue2(A);
    printf("\n");
    printf("head : %d \n", head2(A));
    printf("tail : %d \n", tail2(A));
    printf("Size : %d \n", sizeQueue2(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(A) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(A) == 1? "True" : "False");
    printf("\n");

    createQueue2(&B);
    printf("Queue B = ");
    printQueue2(B);
    printf("\n");
    printf("head : %d \n", head2(B));
    printf("tail : %d \n", tail2(B));
    printf("Size : %d \n", sizeQueue2(B));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(B) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(B) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(B) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(B) == 1? "True" : "False");

    printf("============Menambah Queue============\n");
    enqueue2(&A, 'a');
    enqueue2(&A, 'b');
    enqueue2(&A, 'c');
    enqueue2(&A, 'd');
    enqueue2(&A, 'e');
    printf("Queue A = ");
    viewQueue2(A);
    printf("\n");
    printf("head : %d \n", head2(A));
    printf("tail : %d \n", tail2(A));
    printf("Size : %d \n", sizeQueue2(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(A) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(A) == 1? "True" : "False");
    printf("\n");

    enqueue2(&B, 'a');
    enqueue2(&B, 'b');
    enqueue2(&B, 'c');
    enqueue2(&B, 'e');
    printf("Queue B = ");
    viewQueue2(B);
    printf("\n");
    printf("head : %d \n", head2(B));
    printf("tail : %d \n", tail2(B));
    printf("Size : %d \n", sizeQueue2(B));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(B) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(B) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(B) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(B) == 1? "True" : "False");
    printf("\n");

    printf("===========Mengurangi Queue===========\n");
    dequeue2(&A, &e);
    dequeue2(&A, &e);
    dequeue2(&A, &e);
    dequeue2(&A, &e);
    printf("Queue A = ");
    printQueue2(A);
    printf("\n");
    printf("head : %d \n", head2(A));
    printf("tail : %d \n", tail2(A));
    printf("Size : %d \n", sizeQueue2(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(A) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(A) == 1? "True" : "False");
    printf("\n");

    dequeue2(&B, &e);
    printf("Queue B = ");
    printQueue2(B);
    printf("\n");
    printf("head : %d \n", head2(B));
    printf("tail : %d \n", tail2(B));
    printf("Size : %d \n", sizeQueue2(B));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(B) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(B) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(B) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(B) == 1? "True" : "False");
    printf("\n");

    printf("===========Menambah Queue N============\n");
    enqueue2N(&A, 2);
    printf("Queue A = ");
    printQueue2(A);
    printf("\n");
    printf("head : %d \n", head2(A));
    printf("tail : %d \n", tail2(A));
    printf("Size : %d \n", sizeQueue2(A));
    printf("isEmptyQueue? %s \n", isEmptyQueue2(A) == 1? "True" : "False");
    printf("isOneElement? %s \n", isOneElement2(A) == 1? "True" : "False");
    printf("isFullQueue? %s \n", isFullQueue2(A) == 1? "True" : "False");
    printf("isTailStop? %s \n", isTailStop(A) == 1? "True" : "False");
    printf("\n");

    printf("=============IsEqualQueue2=============\n");
    printf("Queue A = ");
    printQueue2(A);
    printf("\n");
    printf("head : %d \n", head2(A));
    printf("Queue B = ");
    printQueue2(B);
    printf("\n");
    printf("head : %d \n", head2(B));
    printf("\n");
    printf("isEqualQueue? %s \n", isEqualQueue2(A, B) == 1? "True" : "False");

    return 0;
}