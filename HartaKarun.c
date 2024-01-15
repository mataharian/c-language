#include <stdio.h>
#include <stdlib.h>

int* kubur(int value) {
    //Kamus Lokal
    int *p;
    //Algoritma
    p = malloc(sizeof(int));
    *p = value;
    return p;
}

int gali(int* lokasi) {
    //Kamus Lokal

    //Algoritma
    return *lokasi; //deference
}

int main() {
    int n;
    int* map[20];
    int harta_karun;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
            scanf("%d", &harta_karun);
            map[i] = kubur(harta_karun);
    }

    for (int i = 0; i < n; i++) {
            printf("Harta karun ke-%d telah digali\n"
                   "lokasi: %X\n"
                   "isi: %d\n\n", i+1, map[i], gali(map[i]));
    }
}
