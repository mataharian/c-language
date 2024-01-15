#include <stdio.h>
#ifndef PROCEDURE_H
#define PROCEDURE_H

typedef struct{
    char nama[15];
    char status[10];
} wanita;

void Merge();
/*
input  : Dua arsip sequiential, terurut, sejenis
proses : Menggabung kedua arsip menjadi sebuah arsip yang terurut
output : Sequential file baru yang terurut
*/

void Diterima();

void Ditolak();

void Append();

#endif