#include <stdio.h>

int q9(int *v, int n);

int main(){
    int x[] = {1, 3, 6, 8, 9, 11, 2, 4, 1, 7, 6, 8};
    
    printf("%d \n", 19(x, 12));
    return 0;
}


int q9(int *v, int n){
    int i = 0, ip = 0, a = 1, b = 1;

    for(int k = 1; k <= n; k++){
        a = 1;
        b = 1;
        i = 0;
        while (i < n && (a == 1 || b == 1)){
            if(i % k == 0)
                ip = (ip + 1) % 2;
            if(v[i] % 2 != ip)
                a = 0;
            if(v[i] % 2 != (ip + 1) % 2)
                b = 0;
            i++;
        }
        if(a == 1 || b == 1)
            return k;
    }
    return 0;
}