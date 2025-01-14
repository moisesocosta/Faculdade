#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Enum para as cores:Rubro e Negro
enum cors{R, N};

//Estruturas para a árvore
typedef struct no{
    int chave, cor;
    struct no* esq;
    struct no* dir;
    struct no* p;
}No;

typedef struct rn{
    No* raiz;
    No* externo;
}Rn;

//Função para fazer o cálculo das alturas negras das subárvores
int altura(No* x){
    if(x == NULL || (x->esq == NULL && x->dir == NULL)){
        return 0;
    }else{
        if(altura(x->esq) > altura(x->dir)){
            return 1 + altura(x->esq);
        }else{
            return 1 + altura(x->dir);
        }
    }
}

//Função para contar os nós
int contar(No* x){
    if(x == NULL){
        return 0;
    }else{
        int cont_esq = contar(x->esq);
        int cont_dir = contar(x->dir);
        return cont_esq + cont_dir + 1;
    }
}

//Função para criar a árvore
void RB_Create(Rn* t){
    if(t->externo == NULL){
        t->externo = (No*)malloc(sizeof(No));
        t->externo->cor = N;
        t->externo->p = t->externo;
        t->externo->esq = t->externo;
        t->externo->dir = t->externo;
    }
    Rn* arvore = (Rn*)calloc(1, sizeof(Rn));
    arvore->raiz = t->externo;
}

//Função para criar um nó
No* No_Create(Rn* t, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = valor;
    novo->cor = R;
    novo->dir = t->externo;
    novo->esq = t->externo;
    novo->p = t->externo;
    return novo;
}

//Função para procurar o valor minimo na subárvore
No* Tree_Minimum(Rn* t, No* x){
    while(x->esq != t->externo){
        x = x->esq;
    }
    return x;
}

//Função para mostrar o sucessor
No* Tree_Successor(Rn* t, No* x){
    if(x->dir != t->externo){
        return Tree_Minimum(t, x->dir);
    }
    No* y = x->p;
    while(y != t->externo && y->esq != x){
        x = y;
        y = y->p;
    }
    return y;
}

//Função para fazer as rotações para esquerda
void Left_Rotate(Rn* t, No* x){
    No* y = x->dir;
    x->dir = y->esq;
    if(y->esq != t->externo){
        y->esq->p = x;
    }
    y->p = x->p;
    if(x->p == t->externo){
        t->raiz = y;
    }else{
        if(x == x->p->esq){
            x->p->esq = y;
        }else{
            x->p->dir = y;
        }
    }
    y->esq = x;
    x->p = y;
}

//Função para fazer as rotações para direita
void Right_Rotate(Rn* t, No* x){
    No* y = x->esq;
    x->esq = y->dir;
    if(y->dir != t->externo){
        y->dir->p = x;
    }
    y->p = x->p;
    if(x->p == t->externo){
        t->raiz = y;
    }else{
        if(x == x->p->dir){
            x->p->dir = y;
        }else{
            x->p->esq = y;
        }
    }
    y->dir = x;
    x->p = y;
}

//Função para corrigir a árvore após inserir um nó
void RB_Insert_Fixup(Rn* t, No* z){
    No* y;
    while(z->p->cor == R){
        if(z->p == z->p->p->esq){ //Se o pai do nó inserido tiver na esquerda
            y = z->p->p->dir; 
            if(y->cor == R){ //Se o tio tiver a cor Rubro
                z->p->cor = N;
                y->cor = N;
                z->p->p->cor = R;
                z = z->p->p;
            }else{ //Se o tio tiver a cor Negra
                if(z == z->p->dir){ //Se o z for o filho direito
                    z = z->p;
                    Left_Rotate(t, z);
                }
                z->p->cor = N;
                z->p->p->cor = R;
                Right_Rotate(t, z->p->p);
            }
        }else{ //Análogo
            y = z->p->p->esq;
            if(y->cor == R){
                z->p->cor = N;
                y->cor = N;
                z->p->p->cor = R;
                z = z->p->p;
            }else{
                if(z == z->p->esq){
                    z = z->p;
                    Right_Rotate(t, z);
                }
                z->p->cor = N;
                z->p->p->cor = R;
                Left_Rotate(t, z->p->p);
            }
        }
    }
    t->raiz->cor = N;
}

//Função para inserir um nó
int RB_Insert(Rn* t, int valor){
    No* y = t->externo;
    No* x = t->raiz;
    No* z = No_Create(t,valor);
    while(x != t->externo){
        y = x; //Modifica o x
        if(z->chave == x->chave){ //Se for igual
            //printf("chave existente")
            y = NULL;
            x = t->externo;
        }else{
            if(z->chave < x->chave){ //Se for menor(Filho da esquerda)
                x = x->esq;
            }else{ //Se for maior(Filho da direita)
                x = x->dir;
            }
        }
    }
    if(y != NULL){
        z->p = y;
        if(y == t->externo){ //Se estiver vazia
            t->raiz = z;
        }else{
            if(z->chave < y->chave){ //Se for menor(Filho da esquerda)
                y->esq = z;
            }else{ //Se for maior(Filho da direita)
                y->dir = z;
            }
        }
        z->esq = t->externo;
        z->dir = t->externo;
        z->cor = R;
        RB_Insert_Fixup(t, z);
    }
    return 0;
}

//Função para trocar um nó de lugar com outro
void RB_Transplant(Rn* t, No* u, No* v){
    if(u->p == t->externo){ //Se não tiver pai
        t->raiz = v;
    }else{ //Se tiver um pai
        if(u == u->p->esq){ //Se for o filho da esquerda
                u->p->esq = v;
        }else{ //Se for o filho da direita
            u->p->dir = v;
        }
    }
    v->p = u->p;
}

//Função para corrigir a árvore após remover um nó
void RB_Delete_Fixup(Rn* t, No* x){
    No* w;
    while(x != t->raiz && x->cor != R){
        if(x == x->p->esq){ //Se x for filho da esquerda
            w = x->p->dir;
            if(w->cor == R){ //Caso 1
                w->cor = N;
                x->p->cor = R;
                Left_Rotate(t, x->p);
                w = x->p->dir;
            }
            if(w->esq->cor == N && w->dir->cor == N){ //Caso 2
                w->cor = R;
                x = x->p;
            }else{
                if(w->dir->cor == N){ //O irmão de w de x é negro, o filho a esquerda de w é rubro e o filho a direita de w é negro
                    w->esq->cor = N;
                    w->cor = R;
                    Right_Rotate(t, w);
                    w = x->p->dir;
                }
                w->cor = x->p->cor; //O irmão de w de x é preto e o filho a direita de w é rubro
                x->p->cor = N;
                w->p->cor = N;
                Left_Rotate(t, x->p);
                x = t->raiz;
            }
        }else{ //Análogo
            w = x->p->esq;
            if(w->cor == R){
                w->cor = N;
                x->p->cor = R;
                Left_Rotate(t, x->p);
                w = x->p->esq;
            }
            if(w->dir->cor == N && w->esq->cor == N){
                w->cor = R;
                x = x->p;
            }else{
                if(w->esq->cor == N){
                    w->dir->cor = N;
                    w->cor = R;
                    Left_Rotate(t, w);
                    w = x->p->esq;
                }
                w->cor = x->p->cor;
                x->p->cor = N;
                w->p->cor = N;
                Right_Rotate(t, x->p);
                x = t->raiz;
            }
        }
    }
    x->cor = N;
}

//Função para remover um nó
void RB_Delete(Rn* t, No* z){
    No* x;
    No* y = z;
    int corOriginal = y->cor;
    if(z->esq == t->externo){ //Caso 1
        x = z->dir;
        RB_Transplant(t, z, x);
    }else{
        if(z->dir == t->externo){ //Caso 2
            x = z->esq;
            RB_Transplant(t, z, x);
        }else{
            y = Tree_Successor(t, z);
            corOriginal = y->cor;
            x = y->dir;
            if(y->p != z){ //Se o pai do sucessor não for o z
                RB_Transplant(t, y, x);
                y->dir = z->dir;
                y->dir->p = y;
            }else{
                x->p = y;
            }
            RB_Transplant(t, z, y);
            y->esq = z->esq;
            y->esq->p = y;
            y->cor = z->cor;
        }
    }
    if(corOriginal == N){ //Verificar se a cor do nó é Negro
        RB_Delete_Fixup(t, x);
    }
    t->raiz->cor = N;
}

//Função pros testes
int main(){
    Rn* t;
    int nosInserir = 10, nosRemover = 10, valor; 
    printf("\n\nAntes de criar a arvore\n\n");
    RB_Create(t);
    printf("\n\nDepois de criar a arvore\n\n");
    srand(time(NULL));

    printf("\n\nAntes de inserir\n\n");

    for(int i = 0; i < nosInserir; i++){
        valor = rand() % 100000;
        RB_Insert(t, valor);
    }
    
    printf("\n\nDepois de inserir\n\n");

    return 0;
}