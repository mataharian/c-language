#include <stdio.h>

int main() {
    int n, arr[100][100];

    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int ka = 0, ki = n - 1;
    while (ka <= ki) {
        for (int i = ka; i <= ki; i++) {
            printf("%d ", arr[ka][i]);
        }
        for (int i = ka + 1; i <= ki; i++) {
            printf("%d ", arr[i][ki]);
        }
        for (int i = ki - 1; i >= ka; i--) {
            printf("%d ", arr[ki][i]);
        }
        for (int i = ki - 1; i > ka; i--) {
            printf("%d ", arr[i][ka]);
        }
        ka++;
        ki--;
    }

    return 0;
}
