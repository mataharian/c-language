#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tqueue3.h"

/***********************************/
/* Program   : tqueue2.h */
/* Deskripsi : file BODY modul queue karakter model III*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : 6 Oktober 2023*/
/***********************************/

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q){
    //Kamus lokal

    //ALgoritma
    if (head3(Q) == 0  && tail3(Q) == 0){
        return true;
    }else{
        return false;
    }
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q){
    //Kamus lokal

    //Algoritma
    if (sizeQueue3(Q) == 5){
        return true;
    }else{
        return false;
    }
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement3(tqueue3 Q){
    //Kamus lokal

    //ALgoritma
    if(!isEmptyQueue3(Q) && head3(Q) == tail3(Q)){
        return true;
    }else{
        return false;
    }
    
}

/*procedure createQueue3 (output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q){
    //Kamus lokal
    int i;

    //Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for (i = 1; i <= 5; i++){
        (*Q).wadah[i] = '#';
    }
}

/*Function Head3(Q:Tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q){
    //Kamus lokal

    //Algoritma
    return Q.head;
}

/*Function Tail3(Q:Tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q){
    //Kamus lokal

    //Algoritma
    return Q.tail;
}

/*Function InfoHead3(Q:Tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q){
    //Kamus lokal

    //Algoritma
    return Q.wadah[head3(Q)];
}

/*Function InfoTail3(Q:Tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q){
    //Kamus lokal

    //ALgortima
    return Q.wadah[tail3(Q)];
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q){
    //Kamus lokal
    int i, size;
    //Algoritma
    if (isEmptyQueue3(Q)){
        return 0;
    }else{
        size = 0;
        for (i = 1; i <= 5; i++){
            if (Q.wadah[i] != '#'){
                size = size + 1;
            }
        } return size;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue3(tqueue3 Q){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = 1; i<= 5; i++){
        printf("%c", Q.wadah[i]);
        if (i != 5){
            printf(", ");
        }
    }printf("]");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q){
    //Kamus lokal
    int i;

    //Algoritma
    printf("[");
    for (i = head3(Q) - 1; i <= head3(Q) + sizeQueue3(Q) - 2; i++){
        printf("%c", Q.wadah[(i % 5) + 1]);
        if (i != head3(Q)+sizeQueue3(Q)-2){
            printf(", ");
        }
    }printf("]");
}
//head = 2
//tail = 1
//size = 5
//[1..5]
//[b,c,d,e,]

/*procedure enQueue3(input/output Q:tQueue3, input E: character)
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue3(tqueue3 *Q, char E){
    //Kamus lokal

    //Algoritma
    if (isFullQueue3(*Q)){
        printf ("Queue Penuh!!! \n");
    }else{
        if (isEmptyQueue3(*Q)){
            (*Q).head = head3(*Q) + 1;
        }
        (*Q).tail = (tail3(*Q) % 5) + 1;
        (*Q).wadah[tail3(*Q)] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue3, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E){
    //Kamus lokal

    //Algoritma
    if (isEmptyQueue3(*Q)){
        printf("Queue Kosong!!! \n");
    }else{
        *E = (*Q).wadah[head3(*Q)];
        (*Q).wadah[head3(*Q)] = '#';
        if (isOneElement3(*Q)){
            createQueue3(Q);
        }else{
            (*Q).head = (head3(*Q) % 5) + 1;
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q){
    //Kamus lokal

    //Algoritma
    if(head3(Q) > tail3(Q)){
        return true;
    }else{
        return false;
    }
}

/*function countMember(Q:tQueue3, E:character) -> integer
{mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E){
    //Kamus lokal
    int i;
    int count;
    //ALgoritma
    count = 0;
    for (i = 1; i <= 5; i++){
        if (Q.wadah[i] == E){
            count = count + 1;
        } 
    }return count;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E){
    //Kamus lokal

    //Algoritma
    if (isFullQueue3(*Q)){
        printf("Queue Penuh!!! \n");
    }else{
        if (countMember(*Q, E) == 0){
            enqueue3(Q, E);
        }else{
            printf("E sudah ada dalam Q!!! \n");
        }
    }
}

    //     if (countMember(*Q, E) > 0){
    //         if(head3(*Q) == 1 && tail3(*Q) == 5){
    //             for (i = 1; i <= 5; i++){
    //                 if ((*Q).wadah[i] == '#'){
    //                     (*Q).wadah[i] = E;
    //                     break;
    //                 }
    //             }
                
    //         }else{
    //             if (isEmptyQueue3(*Q)){
    //                 (*Q).head = head3(*Q) + 1;
    //             }
    //             (*Q).tail = (tail3(*Q) % 5) + 1;
    //             (*Q).wadah[tail3(*Q)] = E;
    //         }
    //     }else{
    //         if (isTailOverHead(*Q)){
    //             printf("Tidak dapat melakukan Enqueue3E!!! \n");
    //             if(head3(*Q) == 1 && tail3(*Q) == 5){
    //                 for (i = 1; i <= 5; i++){
    //                     if ((*Q).wadah[i] == '#'){
    //                     (*Q).wadah[i] = E;
    //                     break;
    //                 }
                    
    //             }
    //         }else{
    //             if((*Q).wadah[1] == '#' && tail3(*Q) == 5){
    //                 (*Q).wadah[1] = E;
    //             }else{
    //                 (*Q).tail = tail3(*Q) + 1;
    //                 for (i = 5; i >= 2; i--){
    //                     (*Q).wadah[i] = (*Q).wadah[i-1];
    //                 }
    //             }
    //             (*Q).head = 1;
    //             (*Q).wadah[head3(*Q)] = E;
    //         }
    //     }
    // }

    // //Kamus lokal
    // int i;

    // //Algoritma
    // if (isFullQueue3(*Q)){
    //     printf("Queue Penuh!!! \n");
    // }else{
    //     if (countMember(*Q, E) > 0){
    //         if (head3(*Q) - tail3(*Q) == 1){
    //             printf("Tidak dapat melakukan Enqueue3E!!! \n");
    //         }else{
    //             enqueue3(Q, E);
    //         }
    //     }else{
    //         if (isTailOverHead(*Q)){
    //             printf("Tidak dapat melakukan Enqueue3E!!! \n");
    //         }else{
    //             (*Q).tail = tail3(*Q) + 1;
    //             for (i = 5; i >= 2; i--){
    //                 (*Q).wadah[i] = (*Q).wadah[i-1];
    //             }
    //             (*Q).tail = 1;
    //             (*Q).wadah[tail3(*Q)] = E;
    //             (*Q).head = head3(*Q) + 1;
    //         }
    //     }
    // }