#include <stdio.h>
#include "procedure.c"
#include "procedure.h"

int main(){
    char ArsipDataCampur[] = "DataCampur.txt";
    char ArsipDataDitolak[] = "DataDitolak.txt";
    char ArsipDataDiterima[] = "DataDiterima.txt";
    char ArsipDataJadian[] = "DataJadian.txt";
    char ArsipDataRapi[] = "DataRapi.txt";

    // printf("File akan diklasifikansikan Berdasarkan Status \n");
    // printf("Program Berjalan . . . \n");
    // Diterima(ArsipDataCampur,ArsipDataDiterima);
    // Ditolak(ArsipDataCampur,ArsipDataDitolak);
    // printf("Program Selesai Mengklasifikasi ~ \n\n");\

    // printf("Sesaat lagi file akan di merge \n");
    // Merge(ArsipDataDitolak, ArsipDataDiterima,ArsipDataRapi);
    // printf("Program Selesai merge \n");

    printf("Memasukkan Data Tambahan . . . \n");
    Append(ArsipDataJadian,ArsipDataRapi);
    printf("File Sudah Ditambahkan, Silahkan Cek FIle ANDA!!!");
    return 0;

}