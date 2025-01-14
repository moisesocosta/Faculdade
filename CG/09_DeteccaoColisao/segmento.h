#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "ponto.h"

class Segmento{
    private:
        Ponto A, B;
        glm::vec3 cor;
    public:
        Segmento(float x1, float y1, float x2, float y2);
        glm::vec2 getExtremidade(int i);
        void      setCor(glm::vec3 cor);

        void seleciona(int x, int y);
        void modifica(int x, int y);

        bool colisaoSegmento(Segmento S2);

        void desenha();
};

#endif // SEGMENTO_H
