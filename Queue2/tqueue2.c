#include <stdio.h>
#include "tqueue2.h"

/***********************************/
/* Program   : tqueue2.h */
/* Deskripsi : file BODY modul queue karakter model II*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 29 Septemberz 2023*/
/***********************************/

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    if (head2(Q) == 0 && tail2(Q) == 0){
        return true;
    }else{
        return false;
    }
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    if (head2(Q) == 1 && tail2(Q) == 5){
        return true;
    }else{
        return false;
    }
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    if (sizeQueue2(Q) == 1){
        return true;
    }else{
        return false;
    }
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/ 
void createQueue2(tqueue2 *Q){
    //Kamus lokal
    int i;

    //Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for (i = 1; i <= 5; i++){
        (*Q).wadah[i] = '@';
    }
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[head2(Q)];
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[head2(Q)];
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    if (isEmptyQueue2(Q)){
        return 0;
    }else{
        return (tail2(Q) - head2(Q) + 1);
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = 1; i <= 5; i++){
        printf("%c", Q.wadah[i]);
        if (i != 5){
            printf(", ");
        }
    } printf("]");   
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = head2(Q); i <= tail2(Q); i++){
        printf("%c", Q.wadah[i]);
        if (i != tail2(Q)){
            printf(", ");
        }
    } printf("]");   
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q){
    //Kamus lokal

    //Algoritma
    if (tail2(Q) == 5){
        return true;
    }else{
        return false;
    }
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q){
    //Kamus lokal
    int i;
    int temp;

    //Algoritma
    temp = head2(*Q) - 1;
    if (head2(*Q) > 1 && isTailStop(*Q)){
        for (i = head2(*Q); i <= tail2(*Q); i++){
            (*Q).wadah[i - temp] = (*Q).wadah[i];
            (*Q).wadah[i] = '@';
        }
        (*Q).head = 1;
        (*Q).tail = tail2(*Q) - temp;
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
    //Kamus lokal

    //Algoritma
    if (isFullQueue2(*Q)){
        printf("Queue Penuh!!! \n");
    }else{
        if(isTailStop(*Q)){
            resetHead(Q);
        }else if(isEmptyQueue2(*Q)){
            (*Q).head = (*Q).head + 1;
        }
        (*Q).tail = tail2(*Q) + 1;
        (*Q).wadah[tail2(*Q)] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    // Kamus Lokal

    //Algoritma
    if(isEmptyQueue2(*Q)){
        printf("Queue Kosong!!! \n");
    }else{
        (*E) = infoHead2(*Q);
        if (isOneElement2(*Q)){
            createQueue2(Q);
        }else{
            (*Q).wadah[head2(*Q)] = '@';
            (*Q).head = head2(*Q) + 1;
        }
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N){
    //Kamus lokal
    int i;
    char X;
    int max;
    //Algoritma
    if (isTailStop(*Q)){
        resetHead(Q);
    }
    max = tail2(*Q) + N;
    if(max <= 5){
        for (i = tail2(*Q)+1; i <= max; i++){
            printf("Masukkan elemen ke-%d : ", i);
            scanf(" %c", &X);
            enqueue2(Q, X);
        }        
    }else{
        printf("N melewati kapasitas!!! \n");
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2){
    //Kamus lokal
    int i, j;
    int count;
    //Algoritma
    count = 0;
    if (sizeQueue2(Q1) != sizeQueue2(Q2)){
        return false;
    }else{
        for (i = head2(Q1); i <= tail2(Q1); i++){
            for (j = head2(Q2); j <= tail2(Q2); j++){
                if (Q2.wadah[j] == Q1.wadah[i]){
                    count = count + 1;
                }
            }
        }if (count == sizeQueue2(Q1)){
            return true;
        }else{
            return false;
        }
    }
}
