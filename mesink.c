#ifndef MESINK_C
#define MESINK_C

#include <stdio.h>
#include <string.h>
#include "mesink.h"

char Pita_karakter[100] = "pitakar.txt";
static FILE *praktikum10;
static int retval;

void START()
{
    praktikum10 = fopen(Pita_karakter, "r");
    retval = fscanf(praktikum10, "%c", &CC);
}

void ADV()
{
    retval = fscanf(praktikum10, "%c", &CC);

    if (CC == MARK)
    {
        fclose(praktikum10);
    }
}

int EOP()
{
    return (CC == MARK);
}

void WordCnting()
{
    int NumofWord = 0;
    int Numofstr = 0;

    START();
    while (!EOP())
    {
        if (CC == ' ' || CC == Enter)
        {  
            NumofWord ++;
        }
        Numofstr ++;
        
        ADV();
    }
    if(Numofstr > 0) NumofWord ++;

    printf("\nJumlah kata: %d\n", NumofWord);


}

void Revs()
{
    char words[100];
    int wordlen = 0;

    START();
    printf("Pita asli:\n");
    while (!EOP())
    {
        wordlen ++;
        printf("%c", CC);
        words[wordlen] = CC;
        ADV();
    }
    printf("\n");

    int i;
    printf("\nPita setelah di-inverse:\n");
    for (i = wordlen; i > 0; i--)
    {
        printf("%c", words[i]);
    }
    printf("\n");
}

void IsPalindrome()
{
    char words[100];
    int wordlen = 0;
    int pal = 1;

    START();
    while (!EOP())
    {
        wordlen ++;
        words[wordlen] = CC;
        ADV();
    }
    printf("\n");

    int left = 1;
    int right = wordlen;
    while(left <= right){
        if(words[left] != words[right]) pal = 0;
        left ++;
        right --;
    }

    if (pal)
    {
        printf("Merupakan Palindrom\n");
    }
    else
    {
        printf("Bukan Palindrom\n");
    }

}


#endif // MESINCHAR_C

