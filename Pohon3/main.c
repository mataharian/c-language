#include <stdio.h>
#include <stdlib.h>
#include "pohon3.c"

int main() { 
  //Kamus
  bintree3 T;
  // infotype V;

  //Algortima      
  printf("===============Pembuatan BinTree==============\n");
  T = Tree3(NIL,'A', false, Tree3('A', 'B', false, NIL, NIL), Tree3('A', 'C', false, NIL, NIL));
  PrintPrefix(T);
  printf("\n");
  printf("NbElmTree = %d \n", NbElmTree(T));
  printf("NbDaun = %d \n", NbDaun(T));
  printf("Tinggi = %d \n", Tinggi(T));
  printf("Level = %d \n", Level(T));
  printf("IsEmptyTree? %s \n", IsEmptyTree(T) == 1? "True" : "False");
  printf("IsDaun? %s \n", IsDaun(T) == 1? "True" : "False");
  printf("IsBiner? %s \n", IsBiner(T) == 1? "True" : "False");
  printf("IsUnerLeft? %s \n", IsUnerLeft(T) == 1? "True" : "False");
  printf("IsUnerRight? %s \n", IsUnerRight(T) == 1? "True" : "False");
  printf("\n");

  printf("===================CountLevelT================\n");
  PrintPrefix(T);
  printf("\n");
  printf("CountLevelT '2' = %d \n", CountLevelT(T, 2));
  printf("\n");

  printf("==================LinearPrefix================\n");
  PrintList(linearPrefix(T));
  printf("\n");

  printf("=================LinearPostfix================\n");
  PrintList(linearPosfix(T));
  printf("\n");

  printf("==================Linearinfix=================\n");
  PrintList(linearInfix(T));
  printf("\n");
  
  printf("================LinearBreadthFS===============\n");
  PrintList(linearBreadthFS(T));
  printf("\n");

  printf("==================PrintPathX==================\n");
  printPathX(T,'C');
  printf("\n");

  printf("=================PrintPathDaunX===============\n");
  printPathDaunX(T,'B');
  printf("\n");
  
  printf("==================PrintAllPaths===============\n");
  printAllPaths(T);
  printf("\n");
    


  return 0;
}
