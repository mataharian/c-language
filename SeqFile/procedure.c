#include <stdio.h>
#ifndef PROCEDURE_C
#define PROCEDURE_C
#include "procedure.h"
#include <string.h>

void Merge(char* Arsip1, char* Arsip2, char* Arsip3){
    /*kamus Lokal*/
    wanita data_wanita;
    FILE *FILEPABO1;
    FILE *FILEPABO2;
    FILE *FILEPABO3;
    int retval;

    //Algo
    FILEPABO1 = fopen(Arsip1,"r");
    FILEPABO2 = fopen(Arsip2,"r");
    FILEPABO3 = fopen(Arsip3,"w");

    if(FILEPABO1 != NULL){
        retval = fscanf(FILEPABO1, "%s %s \n",&data_wanita.nama,&data_wanita.status);
        while (retval != -1){
            fprintf(FILEPABO3,"%s %s \n",&data_wanita.nama,&data_wanita.status);
            retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        }
    fclose(FILEPABO1);
    }
    if(FILEPABO2 != NULL){
        retval = fscanf(FILEPABO2, "%s %s",&data_wanita.nama,&data_wanita.status);
        while (retval != -1){
            fprintf(FILEPABO3,"%s %s \n",&data_wanita.nama,&data_wanita.status);
            retval = fscanf(FILEPABO2, "%s %s",&data_wanita.nama,&data_wanita.status);
        }
        fclose(FILEPABO2);
    }
    fclose(FILEPABO3);
}

void Diterima(char* Arsip1, char* Arsip2){
    /*kamus Lokal*/
    wanita data_wanita;
    FILE *FILEPABO1;
    FILE *FILEPABO2;
    int retval;

    //algo
    FILEPABO1 = fopen(Arsip1,"r");
    FILEPABO2 = fopen(Arsip2,"w");
    if(FILEPABO1 != NULL){
        retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        while (retval != -1){
            if(strcmp(data_wanita.status, "Diterima")==0) // ini fungsi untuk mencocokan string kawan
            {
                fprintf(FILEPABO2,"%s %s \n", &data_wanita.nama,&data_wanita.status);
            }
            retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        }
    }
    fclose(FILEPABO1);
    fclose(FILEPABO2);
}

void Ditolak(char* Arsip1, char* Arsip2){
    /*kamus Lokal*/
    wanita data_wanita;
    FILE *FILEPABO1;
    FILE *FILEPABO2;
    int retval;

    //algo
    FILEPABO1 = fopen(Arsip1,"r");
    FILEPABO2 = fopen(Arsip2,"w");
    if(FILEPABO1 != NULL){
        retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        while (retval != -1){
            if(strcmp(data_wanita.status, "Ditolak")==0) // ini fungsi untuk mencocokan string kawan
            {
                fprintf(FILEPABO2, "%s %s \n",&data_wanita.nama,&data_wanita.status);
            }
            retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        }
    }
    fclose(FILEPABO1);
    fclose(FILEPABO2);
}

void Append(char* Arsip1, char* Arsip2){
    wanita data_wanita;
    FILE *FILEPABO1;
    FILE *FILEPABO2;
    int retval;

    FILEPABO1 = fopen(Arsip1,"r");
    FILEPABO2 = fopen(Arsip2,"a");

    if(FILEPABO1 != NULL){
        retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        while (retval != -1){
            fprintf(FILEPABO2, "%s %s \n",data_wanita.nama,data_wanita.status);
            retval = fscanf(FILEPABO1, "%s %s",&data_wanita.nama,&data_wanita.status);
        }
    }
    fclose(FILEPABO1);
    fclose(FILEPABO2);
}

#endif