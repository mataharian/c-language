#include <stdio.h>
#include <stdlib.h>
#include "pohon1.c"

int main() { 
  //Kamus
  bintree T;

  //Algortima
  /*
  Tree :
              A
            /  \
          B     C 
        /  \     \
       E    D     F
  */
            
  printf("===============Pembuatan BinTree==============\n");
  T = Tree('A', Tree('B', Tree('E', NIL, NIL), Tree('D', NIL, NIL)), Tree('C', NIL, Tree('F', NIL, NIL)));
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("NbElm = %d \n", NbElm(T));
  printf("NbDaun = %d \n", NbDaun(T));
  printf("Tinggi = %d \n", Tinggi(T));
  printf("IsEmptyTree? %s \n", IsEmptyTree(T) == 1? "True" : "False");
  printf("IsDaun? %s \n", IsDaun(T) == 1? "True" : "False");
  printf("IsBiner? %s \n", IsBiner(T) == 1? "True" : "False");
  printf("IsUnerLeft? %s \n", IsUnerLeft(T) == 1? "True" : "False");
  printf("IsUnerRight? %s \n", IsUnerRight(T) == 1? "True" : "False");
  printf("IsSkewLeft? %s \n", IsSkewLeft(T) == 1? "True" : "False");
  printf("IsSkewRight? %s \n", IsSkewRight(T) == 1? "True" : "False");
  printf("\n");
  
  printf("====================SearchX===================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("SearchX 'D' = %s \n", SearchX(T, 'D') == 1? "True" : "False");
  printf("\n");

  printf("====================UpdateX===================\n");
  printf("Sebelum Update B Menjadi C: \n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("Setelah Update B Menjadi C: \n");
  UpdateX(&T, 'B', 'C');
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n \n");

  printf("=====================CountX===================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("CountX 'C' = %d \n", CountX(T, 'C'));
  printf("\n");

  printf("=====================LevelX===================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("LevelX 'D' = %d \n", LevelX(T,'D'));
  printf("\n");
  
  printf("===================CountLevelT================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("CountLevelT '2' = %d \n", CountLevelT(T, 2));
  printf("\n");

  printf("=================GetDaunTerkiri===============\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("GetDaunTerikiri = %c \n", GetDaunTerkiri(T));
  printf("\n");

  printf("===================FrekuensiX=================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("CountX 'C' = %d \n", CountX(T, 'C'));
  printf("NbElm = %d \n", NbElm(T));
  printf("FrekuensiX 'C' = %.2f \n", FrekuensiX(T,'C'));
  printf("\n");

  printf("===================CountVocal=================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("CountVocal = %d \n", CountVocal(T));
  printf("\n");

  printf("=====================Modus====================\n");
  PrintPrefix(T);
  printf("\n");
  PrintPref(T);
  printf("\n");
  printf("Modus = %c \n", Modus(T));
  printf("\n");


  return 0;
}
