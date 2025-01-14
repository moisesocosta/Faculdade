#include <stdio.h>
#include <stdlib.h>

int q3c(int **A, int n, int k);

int main(){
    int **A, i, j;

    A = (int**)malloc(4 * sizeof(int*));
    for(int i = 0; i < 4; i++)
        A[i] = (int*)malloc(4 * sizeof(int));
    
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            A[i][j] = 0;
    
    printf("\n");
    
    A[0][1] = 1;
    A[1][2] = 1;
    A[2][0] = 1;
    A[3][3] = 1;
    A[2][3] = A[3][2] = 1;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    q3c(A, 4, 1);

    return 0;
}


int q3c(int **A, int n, int k){
    printf("q3c: ");
    for(int j = 0; j < n; j++)
        if(A[k][j] != A[j][k])
            return 0;
    return 1;
}