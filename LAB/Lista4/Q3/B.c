#include <stdio.h>
#include <stdlib.h>

int q3b(int **A, int n);

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

    q3b(A, 4);

    return 0;
}


int q3b(int **A, int n){
    int i, j, s = 0, s1 = 0, cid = 0;

    printf("\nq3b: ");
    for(i = 0; i < n; i++)
        s = s + A[i][0];
    
    for(j = 1; j < n; j++){
        s1 = 0;
        for(i = 0; i < n; i++)
            s1 = s1 + A[i][j];
        if(s1 > s){
            s = s1;
            cid = j;
        }
    }
    return cid;
}