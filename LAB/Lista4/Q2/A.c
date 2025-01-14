#include <stdio.h>

int q2a(int **M, int n);

int main(){
    int **A, i, j;

    A = (int**)malloc(4 * sizeof(int*));
    for(int i = 0; i < 4; i++)
        A[i] = (int*)malloc(4 * sizeof(int));
    
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            A[i][j] = 0;
    A[0][1] = 1;
    A[1][2] = 1;
    A[2][0] = 1;
    A[3][3] = 1;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\n");
    q2a(A, 4);

    return 0;
}

int q2a(int **M, int n){
    int s = 0, s1 = 0, i, j;

    printf("q2a: ");

    for(i = 0; i < n; i++)
        s = s + M[i][j];

    for(j = 0; j < n; j++)
        s1 = s1 + M[i][n - j - 1];

    if(s != s1)
        return 0;

    for(i = 0; i < n; i++){
        s1 = 0;
        for(j = 0; j < n; j++){
            s1 = s1 + M[i][j];
        }
        if(s != s1)
            return 0;
    }

    for(j = 0; j < n; j++){
        s1 = 0;
        for(i = 0; i < n; i++){
            s1 = s1 + M[i][j];
        }
        if(s != s1)
            return 0;
    }
    return 1;
}