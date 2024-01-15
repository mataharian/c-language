#include <stdio.h>

int main(){
    int n;
    int i;


    scanf("%d", &n);
    int T3[n];
    for(i = 0; i<n;i++){
    scanf("%d",&T3[i]);
    }



    int max1 = 0;
    int max2 = 0;
    for (i = 0; i<n;i++){
        if(T3[i] > max1){
            max2= max1;
            max1 = T3[i];
        }
        else if(T3[i] > max2 && T3[i] != max1){
            max2 = T3[i];
        }

    }
    printf("Nilai maksimum kedua adalah : %d",max2);

}
