#include <stdio.h>
#include <stdlib.h>

int q3d(int **A, int n);

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

    q3d(A, 4);

    return 0;
}

int q3d(int **A, int n){
    int contl = 0, contc = 0, cont = 0;
    printf("q3d: \n");

    for(int k = 0; k < n; k++){
        contl = 0; contc = 0;
        for(int i = 0; i < n; i++){
            contl = contl + A[k][i];
            contc = contc + A[i][k];
        }
        if(contl == 1 && contc == 1)
            cont++;
    }
    return cont;
}