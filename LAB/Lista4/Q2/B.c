#include <stdio.h>
#include <stdlib.h>

void q2b(int n);

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
    q2b(4);

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

void q2b(int n){
    int **A, i, j;

    printf("q2b: \n");
    A = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < 4; i++)
        A[i] = (int*)malloc(n * sizeof(int));
    
    do{
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                A[i][j] = rand() % 4;
    }while(q2a(A, n) != 1);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%d ");
        printf("\n");
    }
}