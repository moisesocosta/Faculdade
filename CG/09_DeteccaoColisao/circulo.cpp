#include "circulo.h"

#include <GL/gl.h>
#include <glm/glm.hpp>

//construtor
Circulo::Circulo(float x, float y, float raio){
    centro.pos = glm::vec2(x,y);
    borda.pos = glm::vec2(x+raio,y);
    this->raio = raio;
    cor = glm::vec3(0,0,0);
}

//métodos get's e set's
glm::vec2 Circulo::getCentro(){
    return centro.pos;
}

float Circulo::getRaio(){
    return raio;
}

void Circulo::setCor(glm::vec3 cor){
    this->cor = cor;
}

//método que seleciona um dos pontos de controle do círculo com a coordenada do clique do mouse
void Circulo::seleciona(int x, int y){
    centro.seleciona(x,y);
    borda.seleciona(x,y);
}

//método que modifica um dos pontos de controle do círculo caso algum esteja selecionado
void Circulo::modifica(int x, int y){
    if(centro.selec)
        centro.pos = glm::vec2(x,y);
    else if(borda.selec)
        borda.pos = glm::vec2(x,y);

    //após alterar o centro ou o ponto que controla a borda, o raio do círculo deve ser recalculado
    raio = glm::distance(centro.pos, borda.pos);
}

// detecção de colisão entre um círculo e um segmento de reta
bool Circulo::colisaoSegmento(Segmento S){
    //dados do segmento de reta (pontos inicial e final)
    glm::vec2 A = S.getExtremidade(0);
    glm::vec2 B = S.getExtremidade(1);

    float distancia;

    //cálculo da distância entre o centro do círculo e o segmento de reta
    glm::vec2 v = centro.pos - A;
    glm::vec2 w = B - A;
    float proj = glm::dot(v,w);
    if(proj < 0){
        distancia = sqrt( glm::dot(v,v) );
    }
    else{
        float size = glm::dot(w,w);
        float dist = glm::dot(v,v);
        if(proj > size){
            distancia = sqrt( dist - 2.0f*proj + size );
        }
        else
            distancia = sqrt( dist - proj*proj/size );
    }

    //se a distância for menor que o raio do círculo, eles se tocam
    if(distancia < raio)
        return true;
    else
        return false;
}

//detecção de colisão entre dois círculos
bool Circulo::colisaoCirculo(Circulo C2){
    //se a distância entre os centros dos círculos for menor do que a soma dos seus raios, os círculos se tocam
    float distanciaCentros = glm::distance(centro.pos, C2.getCentro());
    if(distanciaCentros < raio + C2.getRaio())
        return true;
    else
        return false;
}

//método que desenha o círculo na tela
void Circulo::desenha(){
    glColor3f(cor.r, cor.g, cor.b);

    //centro
    glPointSize(centro.tamanho);
    glBegin(GL_POINTS);
        glVertex2f(centro.pos.x, centro.pos.y);
    glEnd();

    //ponto na borda
    glPointSize(borda.tamanho);
    glBegin(GL_POINTS);
        glVertex2f(borda.pos.x, borda.pos.y);
    glEnd();

    //circulo (círculo de raio 1 transladado para o centro e escalonado através do raio)
    glPushMatrix();
    glTranslatef(centro.pos.x, centro.pos.y, 0);
    glScalef(raio,raio,1);
    glBegin(GL_LINE_LOOP);
    for(int i = 0 ; i < 36 ; i++){
        float ang = i*2.0*M_PI/36;
        float x = cos(ang);
        float y = sin(ang);
        glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}


