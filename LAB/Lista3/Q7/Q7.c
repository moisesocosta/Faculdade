#include <stdio.h>

int* q7(int *x, int y, int n);

int main(){
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3};
    int *z = q7(x, y, 3);
    for(int i = 0; i < 6; i++){
        printf("%d", z[i]);
    }
    return 0;
}

int* q7(int *x, int y, int n){
    int i = 0, j = 0;
    int *z = malloc(2 * n * sizeof(int));

    for(int k = 0; k < 2 * n; k++){
        if(i == n){
            z[k] = y[j];
            j++;
        }else if(j == n){
            z[k] = x[i];
            i++;
        }

        if(i < n && j < n){
            if(x[i] < y[i]){
                z[k] = x[i];
                i++;
            }else{
                z[k] = y[j];
                j++;
            }
        }
    }
    return z;
}