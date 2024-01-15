#include <stdio.h>
#include <stdlib.h>
#include "list3.c"

int main() { 
  //Kamus
  address A; 
  List3 L;
  infotype V;

  //Algortima
  printf("=============Create List=============\n");
  CreateList(&L);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============InsertVFirst============\n");
  InsertVFirst(&L,'C');
  InsertVFirst(&L,'B');
  InsertVFirst(&L,'A');
  InsertVFirst(&L,'X');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");
  
  printf("=============InsertVLast=============\n");
  InsertVLast(&L,'D');
  InsertVLast(&L,'E');
  InsertVLast(&L,'F');
  InsertVLast(&L,'X');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeletetVFirst===========\n");
  DeleteVFirst(&L, &V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeletetVLast============\n");
  DeleteVLast(&L, &V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================DeleteX==============\n");
  DeleteX(&L,'F');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================SearchX==============\n");
  SearchX(L,'E',&A);
  PrintList(L);
  printf("Nilai elemen = %c \n", info(A));
  printf("Alamat elemen = %d \n", A);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("================UpdateX==============\n");
  printf("List sebelum diupdate : \n");
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("List setelah diupdate : \n");
  UpdateX(&L,'E','D');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("================Invers===============\n");
  printf("List sebelum diinvers : \n");
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  Invers(&L);
  printf("List setelah diinvers : \n");
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("================CountX===============\n");
  PrintList(L);
  printf("Kemunculan nilai = %d \n", CountX(L,'D'));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("==============FrekuensiX=============\n");
  PrintList(L);
  printf("Kemunculan nilai = %d \n", CountX(L, 'D'));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Frekuensi nilai = %.2f \n", FrekuensiX(L,'D'));
  printf("\n");

  printf("================Modus===============\n");
  PrintList(L);
  printf("Elemen paling banyak muncul = %c \n", Modus(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("==============CountVocal=============\n");
  PrintList(L);
  printf("Jumlah huruf vokal = %d \n", CountVocal(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("===============CountNG===============\n");
  InsertVFirst(&L,'G');
  InsertVFirst(&L,'N');
  PrintList(L);
  printf("Jumlah huruf NG = %d \n", CountNG(L));
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("\n");

  printf("============InsertVAfterX============\n");
  InsertVAfterX(&L,'G','E');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("============InsertVBeforeX===========\n");
  InsertVBeforeX(&L,'E','F');
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("=============DeleteVAfterX===========\n");
  DeleteVAfterX(&L,'A',&V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("============DeleteVBeforeX===========\n");
  DeleteVBeforeX(&L,'F',&V);
  PrintList(L);
  printf("Jumlah elemen list = %d \n", NbElm(L));
  printf("Apakah list kosong? %s \n", IsEmptyList(L) == 1? "True" : "False");
  printf("\n");

  printf("==============SearchAllX=============\n");
  PrintList(L);
  printf("Nilai ada di indeks ke = ");
  SearchAllX(L,'D');
  printf("\n");

  return 0;
}
