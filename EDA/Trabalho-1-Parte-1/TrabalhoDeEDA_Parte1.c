#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Troca(A, B)  \
    {                \
        int aux = A; \
        A = B;       \
        B = aux;     \
    }

#define True 1
#define False 0
#define NumeroDeOuro 0.5
#define TamMAX 100000

//Função para subir o valor no vetor
void subir(int i, int *T)
{
    int p = i / 2; //Pai de i
    if (p >= 1)
    {
        if (T[i] > T[p])
        {
            Troca(T[i], T[p]);
            subir(p, T);
        }
    }
}

//Função para descer o valor no vetor
void descer(int i, int n, int *T)
{
    int l = 2 * i;
    int r = l + 1;
    int maior = i;
    if (l <= n && T[l] > T[i])
    {
        maior = l;
    }
    if (r <= n && T[r] > T[maior])
    {
        maior = r;
    }
    if (maior != i)
    {
        Troca(T[i], T[maior]);
        descer(maior, n, T);
    }
}

//Função para inserir um elemento no vetor
void inserir(int novo, int n, int *T)
{
    T = (int *)realloc(T, (n + 2) * sizeof(int));
    n = n + 1;
    subir(n, T);
}

//Função para remover um elemento no vetor
void remover(int *T, int n)
{
    T[1] = T[n];
    n = n - 1;
    T = (int *)realloc(T, (n + 1) * sizeof(int));
    descer(1, n, T);
}

//Função para construir o vetor
void construir(int *T, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        descer(i, n, T);
    }
}

//Algoritmo de ordenação HeapSort
void heap_sort(int *T, int n)
{
    construir(T, n);
    for (int i = n; i > 1; i--)
    {
        Troca(T[1], T[i]);
        n = n - 1;
        descer(1, n, T);
    }
}

//Algoritmo de ordenação InsertionSort
void insertion_sort(int *A, int n)
{
    int chave, i;
    for (int j = 2; j < n; j++)
    {
        chave = A[j]; //Já está ordenada
        i = j - 1;
        while (A[i] > chave && i >= 0)
        { //Comparando e ordenando
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = chave; //i menor que a chave ou i = 0
    }
}

//Função para construir a tabela
int inicializarTabela(int *Tabela)
{
    for (int i = 0; i < TamMAX; i++)
    {
        Tabela[i] = 0;
    }
}

//Função para fazer o método da divisão na tabela hash
int metodo_da_divisao(int chave, int tam)
{
    return chave % tam;
}

//Função para fazer o método da multiplicação na tabela hash
int metodo_da_multiplicacao(int chave, int tam)
{
    double valor = chave * NumeroDeOuro;
    valor = valor - (int)valor;
    return (int)(tam * valor);
}

int main()
{
    srand(time(NULL));
    int *vetorI, *vetorH, *vetorT, tabela1[TamMAX], tabela2[TamMAX], n, tam, pos, contt1, contt2, status;
    clock_t th, ti;

    printf("Digite a quantidade de elementos do vetor para a parte do Heap\n");
    printf("Opcoes: 1.000, 10.000, 10.000.000, 1.000.000.000\n");
    scanf("%d", &n);
    printf("\n\n");

    printf("Digite o tamanho do vetor das chaves para a parte da Tabela de Dispersão\n");
    scanf("%d", &tam);
    printf("\n\n");

    vetorI = (int *)malloc((n + 1) * sizeof(int));
    vetorH = (int *)malloc((n + 1) * sizeof(int));
    vetorT = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        do
        {
            vetorH[i] = rand() % n;
            status = True;
            for (int j = 0; j < i; ++j)
            {
                if (vetorH[i] == vetorH[j])
                {
                    status = False;
                }
            }
            //inserir(vetorH[i], n, vetorH);
        } while (status == False);
        //inserir(vetor[i], n, vetor);
    }

    memcpy(vetorI, vetorH, n);

    for (int i = 0; i < tam; i++)
    {
        vetorT[i] = rand() % 2000000000;
    }

    /*
    //Parte do Heap
    th = clock();
    heap_sort(vetorH, n);
    th = clock() - th;
    printf("\nTempo de execucao do HeapSort: %f ms\n", ((double)th) / ((CLOCKS_PER_SEC / 1000)));
    free(vetorH);

    ti = clock();
    insertion_sort(vetorI, n);
    ti = clock() - ti;
    printf("\nTempo de execucao do InsertionSort: %f ms\n", ((double)ti) / ((CLOCKS_PER_SEC / 1000)));
    free(vetorI);
    */

    //Parte da Tabela de Dispersão
    inicializarTabela(tabela1);
    for (int i = 0; i < tam; i++)
    {
        pos = metodo_da_divisao(vetorT[i], n);
        if (tabela1[pos] == 0)
        {
            tabela1[pos] = vetorT[i];
        }
        else
        {
            contt1++;
        }
    }
    printf("Numero de colisoes no metodo da divisao: %d\n", contt1);

    inicializarTabela(tabela2);
    for (int i = 0; i < tam; i++)
    {
        pos = metodo_da_multiplicacao(vetorT[i], n);
        if (tabela2[pos] == 0)
        {
            tabela2[pos] = vetorT[i];
        }
        else
        {
            contt2++;
        }
    }
    printf("Numero de colisoes no metodo da multiplicacao: %d\n", contt2);

    system("pause");
    return 0;
}
