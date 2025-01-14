#include "segmento.h"

#include <glm/glm.hpp>
#include <GL/gl.h>

//construtor
Segmento::Segmento(float x1, float y1, float x2, float y2){
    A.pos = glm::vec2(x1,y1);
    B.pos = glm::vec2(x2,y2);
    cor = glm::vec3(0,0,0);
}

//métodos get's e set's
glm::vec2 Segmento::getExtremidade(int i){
    if(i == 0) return A.pos;
    if(i == 1) return B.pos;
    return glm::vec2(0,0);
}

void Segmento::setCor(glm::vec3 cor){
    this->cor = cor;

}

//método que seleciona uma das extremidades do segmento com a coordenada do clique do mouse
void Segmento::seleciona(int x, int y){
    A.seleciona(x,y);
    B.seleciona(x,y);
}

//método que modifica uma das extremidades do segmento caso alguma esteja selecionada
void Segmento::modifica(int x, int y){
    if(A.selec)
        A.pos = glm::vec2(x,y);
    else if(B.selec)
        B.pos = glm::vec2(x,y);
}

//método para detecção de colisão entre dois segmentos de reta
bool Segmento::colisaoSegmento(Segmento S2){
    //dados do segmento de reta (pontos inicial e final e vetor direção)
    glm::vec2 A1 = A.pos;
    glm::vec2 B1 = B.pos;
    glm::vec2 d1 = B1 - A1;

    //dados do segmento de reta recebido como entrada (pontos inicial e final e vetor direção)
    glm::vec2 A2 = S2.A.pos;
    glm::vec2 B2 = S2.B.pos;
    glm::vec2 d2 = B2 - A2;

    //cálculo de interseção entre segmentos de reta
    glm::vec2 E = A2-A1;
    float kross = d1.x*d2.y - d1.y*d2.x;
    float sqrKross = kross*kross;
    float sqrLen1 = glm::dot(d1,d1);
    float sqrLen2 = glm::dot(d2,d2);

    if(sqrKross > 0.001*sqrLen1*sqrLen2){ //se for falso, os dois segmentos são paralelos (logo não se tocam). Isso evita a divisão por zero.
        float s = (E.x*d2.y - E.y*d2.x) / kross;
        float t = (E.x*d1.y - E.y*d1.x) / kross;
        if(s < 0 || s > 1 || t < 0 || t > 1) //
            return false; //as retas se cruzam, mas os segmentos não
        else
            return true; //os segmentos se cruzam
    }

    return false; //os segmentos de reta são paralelos
}

//método que desenha o segmento na tela
void Segmento::desenha(){
    glColor3f(cor.r, cor.g, cor.b);

    //extremidade A
    glPointSize(A.tamanho);
    glBegin(GL_POINTS);
        glVertex2f(A.pos.x, A.pos.y);
    glEnd();

    //extremidade B
    glPointSize(B.tamanho);
    glBegin(GL_POINTS);
        glVertex2f(B.pos.x, B.pos.y);
    glEnd();

    //segmento AB
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(A.pos.x, A.pos.y);
        glVertex2f(B.pos.x, B.pos.y);
    glEnd();
}
