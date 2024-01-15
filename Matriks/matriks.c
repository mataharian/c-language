#include <stdio.h>
#include "matriks.h"

/***********************************/
/* Program   : matriks.c*/
/* Deskripsi : header file modul matriks*/
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : */
/***********************************/

/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
void makeMatriks(Matriks *M){
    //Kamus lokal
    int i,j;

    //Algoritma
    (*M).nbbar = 0;
    (*M).nbkol = 0;
    for (i=1; i <= 10; i++){
        for (j=1; j <= 10; j++){
            (*M).wadah[i][j]= -999;
        }
    }
}

/*DESTRUKTOR tidak perlu*/

/**********SELEKTOR*/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
int getNbbar(Matriks M){
    //Kamus lokal

    //Algoritma
    return M.nbbar;
}

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak kolom matriks M}*/
int getNbkol(Matriks M){
    //Kamus lokal

    //Algoritma
    return M.nbkol;
}

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
int getInfoCell(Matriks M, int X, int Y){
    //Kamus lokal

    //Algoritma
    return M.wadah[X][Y];
}


/*********MUTATOR*/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
void setNbbar(Matriks *M, int X){
    //Kamus lokal

    //Algoritma
    (*M).nbbar = X;
}

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
void setNbkol(Matriks *M, int Y){
    //Kamus lokal

    //Algoritma
    (*M).nbkol = Y;
}

/*procedure setInfoCell(input/output M:Matriks, 
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
void setInfoCell(Matriks *M, int X, int Y, int C){
    //Kamus lokal

    //Algoritma
    (*M).wadah[X][Y] = C;
}

/*********PREDIKAT*/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
boolean isEmptyMatriks(Matriks M){
    //Kamus lokal
    int i, j, size;
    //Algoritma
    size = getNbbar(M)*getNbkol(M);
    if (size == 0){
        return true;
    }else{
        for (i = 1; i <= 10; i++){
            for (j = 1; j <= 10; j++){
                if(getInfoCell(M,i,j) > -999){
                    return false;
                }
            }
        }
        return true;
    }
}

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
boolean isFullMatriks(Matriks M){
    //Kamus lokal
    int i, j, size;
    //Algoritma
    size = getNbbar(M)*getNbkol(M);
    if (size == 0){
        return false;
    }else{
        for (i = 1; i <= 10; i++){
            for (j = 1; j <= 10; j++){
                if(getInfoCell(M,i,j) == -999){
                    return false;
                }
            }
        }
        return true;
    }
}

/*********SUBRUTIN LAIN*/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
void printMatriks(Matriks M){
    //Kamus lokal
    int i,j;

    //Algoritma
    for (i = 1; i <= 10; i++){
        printf("[");
        for (j = 1; j <= 10; j++){
            printf("%d", getInfoCell(M,i,j));
            if (j != 10){
                printf(" ");
            }
        }
        printf("]");
        printf("\n");
    }
}

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
void viewMatriks(Matriks M){
    //Kamus lokal
    int i,j;

    //Algoritma
    for (i = 1; i <= getNbbar(M); i++){
        printf("[");
        for (j = 1; j <= getNbkol(M); j++){
            printf("%d", getInfoCell(M,i,j));
            if (j != getNbkol(M)){
                printf(" ");
            }
        }
        printf("]");
        printf("\n");
    }
}

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
int sumCellMatriks(Matriks M){
    //Kamus lokal
    int i, j, sum;

    //Algoritma
    sum = 0;
        for (i = 1; i <= getNbbar(M); i++){
            for (j = 1; j <= getNbkol(M); j++){
                if (getInfoCell(M,i,j) != -999){
                    sum = sum + getInfoCell(M,i,j);
                }
            }
        }
    return sum;
}

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
float avgCellMatriks(Matriks M){
    //Kamus lokal

    //Algoritma
    return sumCellMatriks(M)/(getNbbar(M)*getNbkol(M));
}

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
int maxCellMatriks(Matriks M){
    //Kamus lokal
    int i, j, max;

    //Algoritma
    max = getInfoCell(M,1,1);
        for (i = 1; i <= getNbbar(M); i++){
            for (j = 1; j <= getNbkol(M); j++){
                if (getInfoCell(M,i,j) > max){
                    max = getInfoCell(M,i,j);
                }
            }
        }
    return max;        
}

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
int minCellMatriks(Matriks M){
    //Kamus lokal
    int i, j, min;

    //Algoritma
    min = getInfoCell(M,1,1);
        for (i = 1; i <= getNbbar(M); i++){
            for (j = 1; j <= getNbkol(M); j++){
                if (getInfoCell(M,i,j != -999)){
                    if (getInfoCell(M,i,j) < min){
                        min = getInfoCell(M,i,j);
                    }
                }
            }
        }
    return min;
}

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
int countA(Matriks M, int A){
     //Kamus lokal
    int i, j, count;

    //Algoritma
    count = 0;
        for (i = 1; i <= getNbbar(M); i++){
            for (j = 1; j <= getNbkol(M); j++){
                if (getInfoCell(M,i,j == A)){
                    count += 1;
                }
            }
        }   
    return count;
}

/*procedure searchMatriks(input M:Matriks, input A:integer, 
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
void searchMatriks(Matriks M, int A){
     //Kamus lokal
    int i, j, X, Y;

    //Algoritma
    X = Y = -999;
        for (i = 1; i <= getNbbar(M); i++){
            for (j = 1; j <= getNbkol(M); j++){
                    if (getInfoCell(M,i,j) == A){
                        X = i;
                        Y = j;
                }
            }
        }       
}

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks, 
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
void transpose(Matriks *M){
    //Kamus lokal
    int i, j, N;
    Matriks A;

    //Algoritma
    for (i = 1; i <= getNbbar(*M); i++){
        for (j = 1; j <= getNbkol(*M); j++){
            A.wadah[j][i] = (*M).wadah[i][j];
        }
    } 
    *M = A;
    N = (*M).nbbar;
    (*M).nbbar = (*M).nbkol;
    (*M).nbkol = N;
}

/*procedure setMatriks(input/output M:Matriks, 
  input X:integer, input Y:integer)*/
/*{I.S.: M,X,Y, terdefinisi}*/
/*{F.S.: M terdefinisi, M.nbbar=X, M.nbkol=Y }*/
/*{proses: membuat matriks dengan baris dan kolom efektif yang diinputkan }*/
void setMatriks(Matriks *M, int X, int Y){
    //Kamus lokal
    int i, j;
    
    //Algoritma
    X = (*M).nbbar;
    Y = (*M).nbkol;
    printf("Masukkan jumlah baris : ");
    scanf("%d", &X);
    setNbbar(M, X);
    printf("Masukkan jumlah kolom : ");
    scanf("%d", &Y);
    setNbbar(M, Y);
    for (i = 1; i <= X; i++){
        for (j = 1; j <= Y; j++){
        printf("Masukkan nilai indeks ke-%d,%d : ", i,j);
        scanf("%d", &(*M).wadah[i][j]);
        }
    }
}
