#include <stdio.h>

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        int sum = 0;
        for(j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
        printf("Baris ke-%d ", i+1);
        for(j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if(j < m-1) {
                printf(" + ");
            }
        }
        printf(" = %d\n", sum);
    }


    for(j = 0; j < m; j++) {
        int sum = 0;
        for(i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        printf("Kolom ke-%d ", j+1);
        for(i = 0; i < n; i++) {
            printf("%d", matrix[i][j]);
            if(i < n-1) {
                printf(" + ");
            }
        }
        printf(" = %d\n", sum);
    }

    return 0;
}
