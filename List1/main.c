#include <stdio.h>
#include <stdlib.h>
#include "list1.c"

int main() { 
  //Kamus
  address A; 
  List1 L;
  infotype V;

  //Algortima
  printf("=============Create List=============\n");
  CreateList(&L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============InsertVFirst============\n");
  InsertVFirst(&L,'C');
  InsertVFirst(&L,'B');
  InsertVFirst(&L,'A');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============InsertVLast=============\n");
  InsertVLast(&L,'D');
  InsertVLast(&L,'E');
  InsertVLast(&L,'F');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeletetVFirst============\n");
  DeleteVFirst(&L, &V);
  DeleteVFirst(&L, &V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeletetVLast=============\n");
  DeleteVLast(&L, &V);
  DeleteVLast(&L, &V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================SearchX===============\n");
  SearchX(L,'C',&A);
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
  UpdateX(&L,'C','A');
  UpdateX(&L,'D','B');
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

  printf("================CountX================\n");
  InsertVFirst(&L,'X');
  PrintList(L);
  printf("Kemunculan nilai X = %d \n", CountX(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("==============FrekuensiX==============\n");
  InsertVFirst(&L,'X');
  PrintList(L);
  printf("Kemunculan nilai X = %d \n", CountX(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Frekuensi nilai X = %.2f \n", FrekeuensiX(L));
  printf("\n");

  printf("================Modus================\n");
  PrintList(L);
  printf("Elemen paling banyak muncul = %c \n", Modus(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("==============SearchAllX=============\n");
  PrintList(L);
  printf("Nilai ada di indeks ke = ");
  SearchAllX(L,'X');
  printf("\n");

  printf("=============InsertVAfter============\n");
  InsertVAfter(&L,'B','D');
  InsertVAfter(&L,'A','C');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  return 0;
}
