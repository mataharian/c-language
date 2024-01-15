/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060122120034/Dzu Sunan Muhammad*/
/* Tanggal   : Jumat, 1 September 2023*/
/***********************************/
#include <stdio.h>
#include <stdbool.h>
#include "titik.h"
#include <math.h>

void makeTitik(Titik *T) {
    (*T).absis = 0;
    (*T).ordinat = 0;
}

int getAbsis(Titik T){
    return T.absis;
}

int getOrdinat(Titik T){
    return T.ordinat;
}

void setAbsis(Titik *T, int xx){
    (*T).absis = xx;
}

void setOrdinat(Titik *T, int yy){
    (*T).ordinat = yy;
}

bool isOrigin(Titik T){
    return getAbsis(T) == 0 && getOrdinat(T) == 0;
}

void geserXY(Titik *T, int dx, int dy){
    (*T).absis += dx;
    (*T).ordinat += dy;
}

void refleksiSumbuX(Titik *T){
    (*T).ordinat *= -1;
}

void refleksiSumbuY(Titik *T){
    (*T).absis *= -1;
}

int Kuadran(Titik T){
    if (getAbsis(T) >= 0 && getOrdinat(T) >= 0){
        return 1;
    } else if (getAbsis(T) < 0 && getOrdinat(T) >= 0){
        return 2;
    } else if (getAbsis(T) < 0 && getOrdinat(T) < 0){
        return 3;
    } else{
        return 4;
    }
}

float Jarak(Titik T1, Titik T2){
    return sqrt((T1.absis - T2.absis)*(T1.absis - T2.absis) + (T1.ordinat - T2.ordinat)*(T1.ordinat - T2.ordinat));
}