#include <stdio.h>
#include <stdlib.h>
#include "pohon2.c"
#include "pohon1.c"

int main() { 
  //Kamus
  bintree T;
  infotype V;

  //Algortima           
  printf("============BuildBalanceTree============\n");
  T = BuildBalanceTree(5);
  PrintPref(T);
  printf("\n");
  printf("IsBalanceTree? %s \n", IsBalanceTree(T) == 1? "True" : "False");
  printf("\n");
  
  printf("================PrintLevel==============\n");
  PrintLevel(T,3);
  printf("\n");

  printf("==============AddDaunTerkiri============\n");
  AddDaunTerkiri(&T, 'E');
  PrintPref(T);
  printf("\n \n");

  printf("==================AddDaun===============\n");
  AddDaun(&T,'G','E', true);
  PrintPref(T);
  printf("\n \n");

  printf("==================InsertX===============\n");
  InsertX(&T,'F');
  PrintPref(T);
  printf("\n \n");

  printf("==============DelDaunTerkiri============\n");
  DelDaunTerkiri(&T,&V);
  PrintPref(T);
  printf("\n \n");

  printf("==================DelDaun===============\n");
  DelDaun(&T, 'F');
  PrintPref(T);
  printf("\n \n");

  printf("==================DeleteX===============\n");
  DeleteX(&T, 'D');
  PrintPref(T);
  printf("\n \n");

  printf("================UpdateALLX==============\n");
  UpdateAllX(&T,'E','H');
  PrintPref(T);
  printf("\n \n");

  printf("==================MaxTree===============\n");
  printf("MaxTree = %c", maxTree(T));
  printf("\n \n");

  printf("==================MinTree===============\n");
  printf("MinTree = %c", minTree(T));
  printf("\n \n");

  printf("==================BSearch===============\n");
  PrintPref(T);
  printf("\n");
  printf("BSearch 'G' = %s \n", BSearch(T,'G') == 1? "True" : "False");
  printf("\n");

  printf("=================InsSearch==============\n");
  InsSearch(T,'X');
  PrintPref(T);
  printf("\n \n");

  printf("=================DelBTree===============\n");
  DelBtree(&T,'X');
  PrintPref(T);
  printf("\n");


  return 0;
}
