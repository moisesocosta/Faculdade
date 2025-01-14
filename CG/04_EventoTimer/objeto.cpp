#include "objeto.h"

#include <GL/gl.h>

//Construtor
Objeto::Objeto(glm::vec2 posicao, int direcao, glm::vec3 cor){
    this->posicao = posicao;
    this->direcao = direcao;
    this->cor = cor;
}

//Método usado para controlar a movimentação do objeto
void Objeto::move(float distancia){
    if(direcao == DIREITA){                    //se o objeto se move pra direita...
        posicao.x += distancia;                //aumente sua coordenada x
        if(posicao.x > 10) direcao = ESQUERDA; //se sua coordenada x ultrapassar o limite máximo, mude sua direção para esquerda
    }
    else{                                      //se o objeto se move pra esquerda...
        posicao.x -= distancia;                //diminua sua coordenada x
        if(posicao.x < -10) direcao = DIREITA; //se sua coordenada x ultrapassar o limite mínimo, mude sua direção para direita
    }
}

//Método usado para desenhar o objeto na tela
void Objeto::desenha(){
    glColor3f(cor.r,cor.g,cor.b);
    glBegin(GL_POINTS);
        glVertex2f(posicao.x, posicao.y);
    glEnd();
}
