#include <GL/glut.h>
#include <glm/glm.hpp>
#include <cmath>

using namespace std;

/*
 * Programa básico para mostrar transformações de translação, rotação e escala feitas usando OpenGL clássico
 * O programa desenha:
 * - um hexágono vermelho sendo transformado por uma rotação
 * - dois retângulos verdes sendo transformados por translações
 * - um quadrado azul sendo transformado por uma escala não-uniforme
 */

//Variáveis globais
int   angRotacao = 0;                                      //ângulo que controlará a rotação do hexágono vermelho
glm::vec2 translacaoRet1(0,0.75), translacaoRet2(0,-0.75); //vetores de translação dos retângulos verdes
glm::vec2 escalaQuad(1,1);                                 //fatores de escala do quadrado azul
float variacaoTranslacao = 0.02;                           //mudança da posição a cada frame
float variacaoEscala = 0.02;                               //mudança da escala a cada frame

//Função que desenha um "círculo" centrado na origem (aqui, irei desenhar um "círculo" com 6 lados, o que vai aparentar um hexágono na tela)
void circulo(float raio, int divisioes){
    glBegin(GL_POLYGON);
        for(int i = 0 ; i < divisioes ; i++){
            float ang = i * (2.0*M_PI/divisioes);
            float x = raio * cos(ang);
            float y = raio * sin(ang);
            glVertex2f(x,y);
        }
    glEnd();
}

//Função com configurações iniciais da aplicação
void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

//Função indicada na 'main' que será usada para redesenhar o conteúdo do frame buffer
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //habilita o uso de matrizes de transformações geométricas
    glLoadIdentity();           //inicializa a matriz de trasnformação com a matriz identidade (não altera as coordenadas dos pontos)

    glPushMatrix();                 //salvando a matriz de transformação atual
    glRotatef(angRotacao, 0,0,1);   //aplicando a matriz de rotação (o vetor (0,0,1) em uma aplicação 2D é o eixo saindo da tela)
    glColor3f(1,0,0);
    circulo(0.5, 8);                //um "círculo" de 6 lados é um hexágono regular
    glPopMatrix();                  //recarregando a matriz de transformação antes da rotação (isso fará com que a rotação aplicada no hexágono não afete os demais objetos)


    glPushMatrix();
    glTranslatef(translacaoRet1.x,translacaoRet1.y,0); //aplicando a matriz de translação (a coordenada z é igual a zero em aplicações 2D)
    glColor3f(0,1,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(translacaoRet2.x,translacaoRet2.y,0); //aplicando a matriz de translação (a coordenada z é igual a zero em aplicações 2D)
    glColor3f(0,0.5,0);
    glPopMatrix();

    glPushMatrix();
    glScalef(escalaQuad.x,escalaQuad.y,1); //aplicando a matriz de escala (a coordenada z é igual a 1, porque escala multiplica os fatores e a multiplicação é o elemento neutro da multiplicação)
    glColor3f(0,0,1);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Q04");

    inicio();

    glutDisplayFunc(desenha);
    glutTimerFunc(1000.0/30, 0, 0);

    glutMainLoop();

    return 0;
}