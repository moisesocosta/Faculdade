#include <stdio.h>
#include <time.h>

int f_rec(int n){
    if(n <= 1)
        return n;
    return f_rec(n - 1) + f_rec(n - 2);
}

int f(int n){
    if(n <= 1)
        return n;
    
    int a = 0, b = 1;
    for(int i = 2; i <= n; i++){
        b = b + a;
        a = b - a;
    }
}

int main(){
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    clock_t ti, tf;

    for(int i = 0; i<= n; i++){
        printf("i = %d\n", i);
        ti = clock();
        printf("f = %d --", f(i));
        tf = clock();
        printf('Tempo = %f ms\n', (double)1000 * (tf - ti) / (double) (CLOCKS_PER_SECOND));

        ti = clock();
        printf("f_rec = %d --", f_rec(i));
        tf = clock();
        printf('Tempo = %f ms\n', (double)1000 * (tf - ti) / (double) (CLOCKS_PER_SECOND));
    }

    return 0;
}