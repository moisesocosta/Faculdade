#include <stdlib.h>
#include <stdio.h>

typedef struct no{

    int id;
    struct no *prox;
}NO;

NO* inicio = NULL;
NO* fim = NULL;
int tam = 0;

void adicionar(int id){
    NO *novo = malloc(sizeof(NO));
    novo->id = id;
    novo->prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }else{
        fim->prox = novo;
    }
    fim = novo;
    tam++;
}

int remover(){
    if(tam > 0){
        NO *lixo = inicio;
        inicio = inicio->prox;
        int retorno = lixo->id;
        free(lixo);
        return retorno;
    }else{
        printf("Fila vazia!\n");
    }
}

void imprimir(){
    NO *aux = inicio;
    while(aux != NULL){
        printf("%d", aux);
        aux = aux->prox;
    }
}