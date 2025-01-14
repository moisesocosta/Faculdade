#ifndef PONTO_H
#define PONTO_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class Ponto{
    public:
        glm::vec2 pos;     //coordenada do ponto
        bool      selec;   //indica se foi selecionado por um clique ou não
        float     tamanho; //raio do ponto (permite o clique não ser perfeitamente na coordenada, é uma margem de erro)

        Ponto();
        void seleciona(int x, int y);
};

#endif // PONTO_H
