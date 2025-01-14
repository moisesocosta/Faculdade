#include <stdlib.h>
#include <stdio.h>

typedef struct no{

    int id;
    struct no *prox;
}NO;

NO* topo = NULL;
int tam = 0;

void adicionar(int id){
    NO *novo = malloc(sizeof(NO));
    novo->id = novo;
    novo-> prox = NULL;
    if(topo == NULL){
        topo = novo;
    }else{
        novo->prox = topo;
        topo = novo;
    }
    tam++;
}

int remover(){
    if(tam > 0){
        NO *lixo = topo;
        topo = topo->prox;
        int retorno = lixo->id;
        free(lixo);
        tam--;
        return retorno;
    }else{
        printf("Lista vazia!\n");
        return -1;
    }
}

void imprimir(){
    NO *aux = topo;
    while(aux != NULL){
        printf("%d", aux->id);
        aux = aux->prox;
    }
}