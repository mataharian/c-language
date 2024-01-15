#include <stdio.h>
#include <stdlib.h>
#include "list2.c"

int main() { 
  //Kamus
  address A; 
  list2 L;
  infotype V;

  //Algortima
  printf("=============Create List=============\n");
  CreateList(&L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============InsertVFirst============\n");
  InsertVFirst(&L,'D');
  InsertVFirst(&L,'C');
  InsertVFirst(&L,'B');
  InsertVFirst(&L,'A');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============InsertVLast=============\n");
  InsertVLast(&L,'E');
  InsertVLast(&L,'F');
  InsertVLast(&L,'G');
  InsertVLast(&L,'H');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeletetVFirst============\n");
  DeleteVFirst(&L, &V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeletetVLast=============\n");
  DeleteVLast(&L, &V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================DeleteX===============\n");
  DeleteX(&L,'B');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================SearchX===============\n");
  SearchX(L,'D',&A);
  PrintList(L);
  printf("Nilai elemen = %c \n", info(A));
  printf("Alamat elemen = %d \n", A);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================UpdateX===============\n");
  printf("List sebelum diupdate : \n");
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("List setelah diupdate : \n");
  UpdateX(&L,'C','D');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("================Invers================\n");
  printf("List sebelum diinvers : \n");
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  Invers(&L);
  printf("List setelah diinvers : \n");
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("============InsertVAfterX=============\n");
  InsertVAfterX(&L,'E','E');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("============InsertVBeforeX============\n");
  InsertVBeforeX(&L,'G','H');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("==============DeleteVAfterX=============\n");
  DeleteVAfterX(&L,'D',&V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeleteVBeforeX=============\n");
  DeleteVBeforeX(&L,'G',&V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================CountX================\n");
  PrintList(L);
  printf("Kemunculan nilai = %d \n", CountX(L,'D'));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("==============FrekuensiX==============\n");
  PrintList(L);
  printf("Kemunculan nilai X = %d \n", CountX(L, 'D'));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Frekuensi nilai X = %.2f \n", FrekuensiX(L,'D'));
  printf("\n");

  printf("================Modus================\n");
  PrintList(L);
  printf("Elemen paling banyak muncul = %c \n", Modus(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("==============SearchAllX=============\n");
  PrintList(L);
  printf("Nilai ada di indeks ke = ");
  SearchAllX(L,'D');
  printf("\n");

  return 0;
}
