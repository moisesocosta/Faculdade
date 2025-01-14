#include <GL/glut.h>
#include <glm/glm.hpp>
#include <cmath>
#include <vector>

#include "segmento.h"
#include "circulo.h"

using namespace std;

/*
 * Programa de detecção de colisão:
 * -> entre círculos
 * -> entre segmentos
 * -> entre círculo e segmento
 */

//Variáveis globais
int larguraJanela = 500;
int alturaJanela = 500;

Segmento S1(100,100,200,100);
Segmento S2(300,100,400,100);
Circulo C1(150,250,50);
Circulo C2(350,250,50);

//Função com configurações iniciais da aplicação
void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_MULTISAMPLE);
}

//Função que trata o clique do mouse
void mouseClique(int button, int state, int x, int y){
    //pressionar (GLUT_DOWN) o botão esquerdo do mouse (GLUT_LEFT_BUTTON)
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        y = alturaJanela - y; //correção de coordenada de pixel para coordenada de mundo

        //verificando se a coordenada do clique irá selecionar algum ponto de controle do segmento ou dos círculos
        S1.seleciona(x,y);
        S2.seleciona(x,y);
        C1.seleciona(x,y);
        C2.seleciona(x,y);
    }
    glutPostRedisplay();
}

//Função que trata o arrasto do mouse com o botão pressionado
void mouseArrasta(int x, int y){
    y = alturaJanela - y; //correção de coordenada de pixel para coordenada de mundo

    //Os métodos irão modificar os pontos de controle do segmento ou dos círculos apenas se eles foram selecionados durante o clique inicial
    S1.modifica(x,y);
    S2.modifica(x,y);
    C1.modifica(x,y);
    C2.modifica(x,y);

    //verificando e contando quantas colisões acontecem entre os objetos
    int colideS1 = 0, colideS2 = 0, colideC1 = 0, colideC2 = 0;
    if(C1.colisaoSegmento(S1)){  colideS1++;  colideC1++;   } //segmento S1 e círculo  C1
    if(C2.colisaoSegmento(S1)){  colideS1++;  colideC2++;   } //segmento S1 e círculo  C2
    if(C1.colisaoSegmento(S2)){  colideS2++;  colideC1++;   } //segmento S2 e círculo  C1
    if(C2.colisaoSegmento(S2)){  colideS2++;  colideC2++;   } //segmento S2 e círculo  C2
    if(C1.colisaoCirculo(C2) ){  colideC1++;  colideC2++;   } //círculo  C1 e círculo  C2
    if(S1.colisaoSegmento(S2)){  colideS1++;  colideS2++;   } //segmento S1 e segmento S2

    //calculando a cor de cada objeto a partir da quantidade de colisões que cada um obteve
    glm::vec3 PRETO    = glm::vec3(0,0,0); //nenhuma colisão
    glm::vec3 VERMELHO = glm::vec3(1,0,0); //uma colisão
    glm::vec3 VERDE    = glm::vec3(0,1,0); //duas colisões
    glm::vec3 AZUL     = glm::vec3(0,0,1); //três colisões
    glm::vec3 corS1, corS2, corC1, corC2;
    corS1 = (colideS1 == 1) ? VERMELHO : ( (colideS1 == 2) ? VERDE : ( (colideS1 == 3) ? AZUL : PRETO ) );
    corS2 = (colideS2 == 1) ? VERMELHO : ( (colideS2 == 2) ? VERDE : ( (colideS2 == 3) ? AZUL : PRETO ) );
    corC1 = (colideC1 == 1) ? VERMELHO : ( (colideC1 == 2) ? VERDE : ( (colideC1 == 3) ? AZUL : PRETO ) );
    corC2 = (colideC2 == 1) ? VERMELHO : ( (colideC2 == 2) ? VERDE : ( (colideC2 == 3) ? AZUL : PRETO ) );

    //atribuindo as cores calculadas para cada objeto
    S1.setCor(corS1);
    S2.setCor(corS2);
    C1.setCor(corC1);
    C2.setCor(corC2);

    //redesenhar a janela
    glutPostRedisplay();
}

//Função indicada na 'main' que será usada para redesenhar o conteúdo do frame buffer
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,larguraJanela,0,alturaJanela,-1,1); //para facilitar o clique do mouse, o espaço de mundo é do mesmo tamanho da quantidade de pixels da janela

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //desenhando os objetos
    S1.desenha();
    S2.desenha();
    C1.desenha();
    C2.desenha();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_MULTISAMPLE | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(larguraJanela,alturaJanela);
    glutCreateWindow("Deteccao de Colisao");

    inicio();

    glutDisplayFunc(desenha);
    glutMouseFunc(mouseClique);
    glutMotionFunc(mouseArrasta);

    glutMainLoop();
    return 0;
}
