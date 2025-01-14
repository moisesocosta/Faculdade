#include <stdio.h>

void q8(int *x, int k);

int main(){
    int x[] = {7, 9, 8, 5, 4, 5, 4, 8, 6};
    
    q8(x, 9);
    return 0;
}

void q8(int *x, int k){
    int m, j;

    for(int i = 0; i < k; i++){
        m = 1;
        while(i + 2 * m - 1 < k){
            j = 0;
            while(x[i + j] == x[i + m + j] && j < m){
                j++;
            }
            if(j == m){
                printf("\n\ni = %d ", i);
                printf("m = %d\n", m);
                for(int k = i; k < i + 2 * m; k++){
                    printf("%d", x[k]);
                }
            }
            m++;
        }
        
    }
}