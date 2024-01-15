#include <stdio.h>
#include <stdbool.h>

 void seqSearch(int N, int data[], int X){
  //Kamus Lokal
     int i;
    
  //Algoritma
 	for (i = 0; i < N; i++){
 	    if (data[i] == X){
 	        printf("Data ditemukan pada indeks ke-%d\n", i);
 	    }
 	}
	
 	if (i == N){
 	    printf("Data tidak ditemukan\n");
	}
 }



int main()
{
    int N = 14;
    int data[14] = {2, 4, 0, 6, 0, 1, 2, 2, 1, 2, 0, 0, 3, 4};
    int X = 9;
    seqSearch(N, data, X);
    return 0;
}