#include <stdio.h>

int FindMe(int arr[], int N, int X){
    int idx;

    if(N == 0){
            return -1;
    }
    else if (arr[0] == X){
        return 0;
    }
    else {
        idx = FindMe (arr+1, N-1, X);
        if (idx == -1){
            return -1;
        }
        else {
            idx + 1;
        }
    }
}

int main(){

    int i;
    int N;
    scanf("%d", &N);

    int arr[N];

    for (i = 0; i < N; i++){
        scanf ("%d", &arr[i]);
    }

    int X;
    scanf ("%d", &X);

    int Hasil;
    Hasil = FindMe (arr, N, X);
    printf ("%d", Hasil);
    return 0;
}
