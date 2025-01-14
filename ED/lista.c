#include <stdlib.h>
#include <stdio.h>

typedef struct no{

    int valor;
    struct no *prox;
}NO;

NO* inicio = NULL;
int cont = 0;

void add(int valor, int pos){
    if(pos >= 0 && pos <= tam){ 
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;
        if(inicio == NULL){ //inicio
            inicio = novo;
            tam++;
        }else if(pos == 0){ //fim
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else{ //meio
            NO* aux = inicio;
            for(int i = 0; i< pos -1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
        } // FIM!!!!!
    }
}

void remover(int pos){
    if(pos >= 0 && pos < tam){
        if(pos == 0){
            NO* lixo = inicio;
            inicio = inicio->prox;
            int retorno = lixo->valor;
            free(lixo);
            tam--;
        }else{
            NO* aux = inicio;
            for(int i = 0; i < pos - 1; i++){
                aux = aux->prox;
            }
            aux->prox = aux->prox->prox;
            int retorno = lixo->valor;
            free(lixo);
            tam--;
            return retorno;
        }
    }else{
        return -1;
    }
}

void imprimir(){
    NO* aux = inicio;
    int i;
    while(aux != NULL){
        printf("%d", aux->valor);
        aux = aux->prox;
    }
}


int main(){
    
    add(10,0);
    add(20,0);
    add(30,2);
    imprimir();
    return 0;
}






