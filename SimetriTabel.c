#include <stdio.h>

int main() {
    int N, M, i, count = 0;

    scanf("%d", &N);
    int T1[N];

    for(i = 0; i < N; i++) {
        scanf("%d", &T1[i]);
    }

    scanf("%d", &M);
    int T2[M];
    for(i = 0; i < M; i++) {
        scanf("%d", &T2[i]);
    }

    if(N != M) {
        printf("Tidak simetri");
    } else {
        for(i = 0; i < N; i++) {
            if(T1[i] != T2[i]) {
                count++;
                break;
            }
        }
        if(count == 0) {
            printf("Simetri");
        } else {
            printf("Tidak simetri");
        }
    }
    return 0;
}
