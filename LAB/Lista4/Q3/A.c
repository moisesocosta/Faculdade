#include <stdio.h>
#include <stdlib.h>

void q3a(int **A, int n, int k);

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

    q3a(A, 4, 2);

    return 0;
}

void q3a(int **A, int n, int k){
    int contl = 0, contc = 0;
    printf("q3a: ");

    for(int i = 0; i < n; i++){
        contl = contl + A[k][i];
        contc = contc + A[i][k];
    }
    printf("%d saem %d e chegam %d", k, contl, contc);
}