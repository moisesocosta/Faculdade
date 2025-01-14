#include <stdio.h>
#include <stdlib.h>

int q3g(int **A, int n, int *cam, int n);

int main(){
    int **A, i, j, cam[] = {2, 3, 2, 0, 0};

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
    A[2][3] = A[3][2] = 0;
    A[0][1] = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    q3g(A, 4, cam, 5);

    return 0;
}

int q3g(int **A, int n, int *cam, int n){
    printf("q3g: ");
    for(int i = 1; i < m; i++)
        if(A[cam[i - 1]][cam[i]] == 0)
            return 0;
    return 1;
}