#include "ponto.h"

#include <glm/glm.hpp>

//construtor
Ponto::Ponto(){
    pos = glm::vec2(0,0);
    selec = false; //todos os pontos são não selecionados inicialmente
    tamanho = 10;  //o usuário pode clicar até 10 pixels de distância da posição do ponto
}

//método que seleciona o ponto se a coordenada do clique do mouse
void Ponto::seleciona(int x, int y){
    glm::vec2 Q(x,y);
    float distancia = glm::distance(pos,Q);
    //se o clique estiver mais próxima do ponto do que o seu tamanho (margem de erro), então ele é selecionado
    if(distancia < tamanho) selec = true;
    else                    selec = false;
}
