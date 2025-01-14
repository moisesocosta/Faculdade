#include <stdio.h>

int q1(int **A, int m, int n);

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
    q1(A, 4, 4);

    return 0;
}

int q1(int **A, int m, int n){
    int  cont0, cont1;

    printf("q1: ");
    for(int i = 0; i < m; i++){
        cont0 = 0;
        cont1 = 0;
        for (int j = 0; j < n; j++){
            if(A[i][j] == 0)
                cont0++;
            if(A[i][j] == 1)
                cont1++;
        }
        if(cont0 != n - 1 || cont1 != 1)
            return 0;
    }

    for(int j = 0; j < m; j++){
        cont0 = 0;
        cont1 = 0;
        for (int i = 0; i < n; i++){
            if(A[i][j] == 0)
                cont0++;
            if(A[i][j] == 1)
                cont1++;
        }
        if(cont0 != m - 1 || cont1 != 1)
            return 0;
    }
}