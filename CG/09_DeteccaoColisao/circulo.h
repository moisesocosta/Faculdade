#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"
#include "segmento.h"

class Circulo{
    private:
        Ponto centro;
        Ponto borda;
        float raio;
        glm::vec3 cor;
    public:
        Circulo(float x, float y, float raio);
        glm::vec2 getCentro();
        float     getRaio();
        void      setCor(glm::vec3 cor);

        void seleciona(int x, int y);
        void modifica(int x, int y);

        bool colisaoSegmento(Segmento S);
        bool colisaoCirculo(Circulo C2);

        void desenha();
};

#endif // CIRCULO_H
