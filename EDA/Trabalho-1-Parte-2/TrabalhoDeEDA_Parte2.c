#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 1
#define F 0

//Estrutura para a AVL
typedef struct no{
    int chave, bal;
    struct no* esq;
    struct no* dir;
}No;

//Função para inicializar um nó na AVL
No* iniciarNo(No** pt, int x){
    No *novo = (No*)malloc(sizeof(No));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = x;
    novo->bal = 0;
    (*pt) = novo;
}

//Função para fazer o cálculo das alturas das subárvores
int altura(No* h){
    if(h == NULL){
        return 0;
    }else{
        int he = altura(h->esq);
        int hd = altura(h->dir);
        if(he < hd){
            return hd + 1;
        }else{
            return he + 1;
        }
    }
}

//Função para verificar se é uma AVL ou não
int verifica(No* h){
    if(h == NULL){
        return 1;
    }
    if(altura(h->dir) - altura(h->esq) >= -1 && altura(h->dir) - altura(h->esq) <= 1){
        printf("\nEh AVL\n\n");
    }else{
        printf("\nNao eh AVL\n\n");
    }
}

//Função para contar os nós da AVL
int contar(No* c){
    if(c == NULL){
        return 0;
    }else{
        int cont_esq = contar(c->esq);
        int cont_dir = contar(c->dir);
        return cont_esq + cont_dir + 1;
    }
}

//Função para trocar os nós de posição
void trocar(No** A, No** B){
    No* aux = (*A);
    (*A) = (*B);
    (*B) = aux;
}

//Função para fazer as rotações simples e duplas para direita no Inserir
// pt -> ponteiro para o nó para fazer a rotação
// h = V -> altura modificada após a rotação
// h = F -> altura não modificada após a rotação
void Caso1(No** pt, int* h){
    No* ptu = (*pt)->esq;
    if(ptu->bal == -1){ //Rotação Simples
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        (*pt)->bal = 0;
        (*pt) = ptu;
    }else{ //Rotação Dupla
        No* ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = (*pt);
        if(ptv->bal == -1){ 
            (*pt)->bal = 1;
        }else{
            (*pt)->bal = 0;
        }
        if(ptv->bal == 1){
            ptu->bal = -1;
        }else{
            ptu->bal = 0;
        }
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    (*h) = F;
}

//Função para fazer as rotações simples e duplas para esquerda no Inserir
// pt -> ponteiro para o nó para fazer a rotação
// h = V -> altura modificada após a rotação
// h = F -> altura não modificada após a rotação
void Caso2(No** pt, int* h){
    No* ptu = (*pt)->dir;
    if(ptu->bal == 1){ //Rotação Simples
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);
        (*pt)->bal = 0;
        (*pt) = ptu;
    }else{ //Rotação Dupla
        No* ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = (*pt);
        if(ptv->bal == 1){
            (*pt)->bal = -1;
        }else{
            (*pt)->bal = 0;
        }
        if(ptv->bal == -1){
            ptu->bal = 1;
        }else{
            ptu->bal = 0;
        }
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    (*h) = F;
}

//Função para inserir os Nós na árvore
// x -> chave para inserir
// pt -> ponteiro para o nó raiz da AVL
// h = V -> altura modificada após a inserção
// h = F -> altura não modificada após a inserção
void InserirAVL(int x, No** pt, int* h){
    if((*pt) == NULL){ //Árvore vazia
        iniciarNo(&(*pt), x);
        (*h) = V;
    }else{
        if(x == (*pt)->chave){ //O elemento já existe
            //printf("elem. encontrado\n");
            (*h) = F;
            return;
        }
        if(x < (*pt)->chave){ //Inserir para a esquerda
            InserirAVL(x, &(*pt)->esq, h);
            if((*h) == V){ //Verifica se a altura foi modificada
                switch ((*pt)->bal){
                    case 1: //Sub-árvore direita maior que a da esquerda
                        (*pt)->bal = 0;
                        (*h) = F;
                        break;
                    case 0: //Sub-árvore direita do mesmo tamanho da esquerda
                        (*pt)->bal = -1;
                        break;
                    case -1: //Sub-árvore direita menor que a da esquerda
                        Caso1(pt, h);
                        break;
                }
            }
        }else{ //Inserir para a direita
            InserirAVL(x, &(*pt)->dir, h);
            if((*h) == V){ //Verifica se a altura foi modificada
                switch((*pt)->bal){
                    case -1: //Sub-árvore esquerda menor que a da direita
                        (*pt)->bal = 0;
                        (*h) = F;
                        break;
                    case 0: //Sub-árvore esquerda do mesmo tamanho da direita
                        (*pt)->bal = 1;
                        break;
                    case 1: //Sub-árvore esquerda maior que a da direita
                        Caso2(pt, h);
                        break;
                }
            }
        }
    }
}

//Função para fazer as rotações simples e duplas para direita no Remover
// pt -> ponteiro para o nó para fazer a rotação
// h = V -> altura modificada após a rotação
// h = F -> altura não modificada após a rotação
void Caso1R(No** pt, int* h){
    No* ptu = (*pt)->esq;
    if(ptu->bal <= 0){ //Rotação Simples
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        (*pt) = ptu;
        if(ptu->bal == -1){
            ptu->bal = (*pt)->dir->bal = 0;
            (*h) = V;
        }else{
            ptu->bal = 1;
            (*pt)->dir->bal = -1;
            (*h) = F;
        }
    }else{ //Rotação Dupla
        No* ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = (*pt);
        (*pt) = ptv;
        switch(ptv->bal){
            case -1:
                ptu->bal = 0;
                (*pt)->dir->bal = 1;
                break;
            case 0:
                ptu->bal = 0;
                (*pt)->dir->bal = 0;
                break;
            case 1:
                ptu->bal = -1;
                (*pt)->dir->bal = 0;
                break;
        }
        (*pt)->bal = 0;
        (*h) = V;
    }
}

//Função para fazer as rotações simples e duplas para esquerda no Remover
// pt -> ponteiro para o nó para fazer a rotação
// h = V -> altura modificada após a rotação
// h = F -> altura não modificada após a rotação
void Caso2R(No** pt, int* h){
    No* ptu = (*pt)->dir;
    if(ptu->bal <= 0){ //Rotação Simples
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);
        (*pt) = ptu;
        if(ptu->bal == 1){
            ptu->bal = (*pt)->esq->bal = 0;
            (*h) = V;
        }else{
            ptu->bal = -1;
            (*pt)->esq->bal = 1;
            (*h) = F;
        }
    }else{ //Rotação Dupla
        No* ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = (*pt);
        (*pt) = ptv;
        switch(ptv->bal){
            case -1:
                ptu->bal = 1;
                (*pt)->esq->bal = 0;
                break;
            case 0:
                ptu->bal = 0;
                (*pt)->esq->bal = 0;
                break;
            case 1:
                ptu->bal = 0;
                (*pt)->esq->bal = -1;
                break;
        }
        (*pt)->bal = 0;
        (*h) = V;
    }
}

//Função para balancear a AVL
// pt -> ponteiro para o nó 
// R -> direção da árvore
// h = V -> altura modificada após a rotação
// h = F -> altura não modificada após a rotação
void balancear(No** pt, char R, int* h){
    if((*h) == V){ //Verifica se a altura foi modificada
        if(R == 'D'){ //Verifica as modificações na direita
            switch((*pt)->bal){
                case 1:
                    (*pt)->bal = 0;
                    break;
                case 0:
                    (*pt)->bal = -1;
                    (*h) = F;
                    break;
                case -1:
                    Caso1R(&(*pt), h);
                    break;
            }
        }else{ //Verifica as modificações na direita
            switch((*pt)->bal){
                case -1:
                    (*pt)->bal = 0;
                    break;
                case 0:
                    (*pt)->bal = 1;
                    (*h) = F;
                    break;
                case 1:
                    Caso2R(&(*pt), h);
                    break;
            }
        }
    }
}

//Função para remover os Nós na árvore
void RemoverAVL(int x, No** pt, int* h){
    if((*pt) == NULL){ //Não encontrou o nó
        //printf("elem. nao existe\n");
        (*h) = F;
        return;
    }else{
        if(x < (*pt)->chave){ //Busca/Remoção pro lado esquerdo
            RemoverAVL(x, &(*pt)->esq, h);
            balancear(&(*pt), 'E', h);
        }else{
            if(x > (*pt)->chave){ //Busca/Remoção pro lado direito
                RemoverAVL(x, &(*pt)->dir, h);
                balancear(&(*pt), 'D', h);
            }else{
                No* aux = (*pt);
                if((*pt)->esq == NULL){ //O nó da esquerda for nulo
                    (*pt) = (*pt)->dir;
                    (*h) = V;
                }else{
                    if((*pt)->dir == NULL){ //O nó da direita for nulo
                        (*pt) = (*pt)->esq;
                        (*h) = V;
                    }else{
                        No* s = (*pt)->dir;
                        if(s->esq == NULL){ //Caso do sucessor
                            s->esq = (*pt)->esq;
                            s->bal = (*pt)->bal;
                            (*pt) = s;
                            (*h) = V;
                        }else{ //Pegar o sucessor na parte de baixo da árvore
                            No* PaiS = s;
                            while(s->esq != NULL){
                                PaiS = s;
                                s = s->esq;
                            }
                            trocar(&(*pt), &PaiS->esq); //Trocar os nós de posição
                            RemoverAVL(x, &(*pt)->dir, h);
                        }
                        balancear(&(*pt), 'D', h);
                    }
                }
                free(aux); //Liberar o nó
            }
        }
    }
}

//Função para imprimir a AVL
void pre_ordem(No* pt){
    printf("%d ", pt->chave);
    if(pt->esq != NULL){
        pre_ordem(pt->esq);
    }
    if(pt->dir != NULL){
        pre_ordem(pt->dir);
    }
}

//Função para imprimir a AVL
void in_ordem(No* pt){
    if(pt->esq != NULL){
        pre_ordem(pt->esq);
    }
    printf("%d ", pt->chave);
    if(pt->dir != NULL){
        pre_ordem(pt->dir);
    }
}

//Função para imprimir a AVL
void pos_ordem(No* pt){
    if(pt->esq != NULL){
        pre_ordem(pt->esq);
    }
    if(pt->dir != NULL){
        pre_ordem(pt->dir);
    }
    printf("%d ", pt->chave);
}

//Função pros testes
int main(){
    srand(time(NULL));
    int avls = 100, nosInserir = 1000, nosRemover = 100, valor, cont, h;
    No* ptraiz[1000];

    for(int i = 0; i < avls; i++){
        ptraiz[i] = NULL;
        cont = 0;
        while(cont < nosInserir){
            h = F;
            valor = rand() % 100000;
            InserirAVL(valor, &ptraiz[i], &h);
            cont = contar(ptraiz[i]);
        }
        printf("\nA arvore %d tem %d nos\n\n", i, cont);
        verifica(ptraiz[i]);

        cont = 0;

        while(cont < nosRemover){
            valor = rand() % 100000;
            h = F;
            RemoverAVL(valor, &ptraiz[i], &h);
            cont++;
        }
        
        cont = contar(ptraiz[i]);
        printf("\nA arvore %d tem %d nos\n\n", i, cont);
        verifica(ptraiz[i]);    
    }

    return 0;
}