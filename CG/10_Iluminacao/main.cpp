#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <cmath>
#include <iostream>
#include "fonteluz.h"
#include "surface.h"

using namespace std;

#define FPS 30

int       janelaAltura  = 600;
int       janelaLargura = 600;
glm::vec3 camPos = glm::vec3(20,-10,20);

Surface  surface;
FonteLuz luz;

//função com configurações iniciais
void inicio(){
    glClearColor(0.0, 0.0, 0.0, 1.0); //cor de fundo (preto)
    glEnable(GL_DEPTH_TEST);          //habilitando a remoção de faces que estejam atrás de outras (ocultas)
    glEnable(GL_MULTISAMPLE);         //habilita um tipo de antialiasing (melhora serrilhado)
}

//função para desenhar os eixos cartesianos do sistema de coordenadas global (ou de mundo, ou de cenário)
void eixos(){
    glLineWidth(3); //linhas com largura de 3 pixels
    glBegin(GL_LINES);
        //eixo x em vermelho
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
        //eixo y em verde
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,100,0);
        //eixo z em azul
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,100);
    glEnd();
}

//função que é chamada sempre que o tamanho da janela é modificado
void alteraJanela(int largura, int altura){
    //guardo a atual resolução da janela para manter o aspect ratio da câmera sempre correto
    janelaLargura = largura;
    janelaAltura = altura;

    glutPostRedisplay();
}

//Função indicada pra GLUT que será executada sempre que um evento de teclado que gere um caractere ASCII é criado
void tecladoASCII(unsigned char key, int x, int y){
    switch(key){
        case 'a': surface.setOndaAltura(surface.getOndaAltura()-0.01); break; //altera a altura da onda
        case 'A': surface.setOndaAltura(surface.getOndaAltura()+0.01); break;
        case 'v': surface.setOndaVeloc(surface.getOndaVeloc()-0.1);    break; //altera a velocidade da onda
        case 'V': surface.setOndaVeloc(surface.getOndaVeloc()+0.1);    break;
        case 'c': surface.setOndaComp(surface.getOndaComp()-0.01);     break; //altera o comprimento da onda
        case 'C': surface.setOndaComp(surface.getOndaComp()+0.01);     break;
        case 'd': surface.setDivisoes(surface.getDivisoes()-1);        break; //altera a quantidade de triângulos da superfície
        case 'D': surface.setDivisoes(surface.getDivisoes()+1);        break;
    }

    glutPostRedisplay(); //atualiza o desenho
}

void timer(int v){
    glutTimerFunc(1000.0/FPS, timer, 0);

    glm::mat4 R = glm::rotate(glm::mat4(1.0f), 0.01f, glm::vec3(0,0,1)); //matriz de rotação usada para girar a fonte de luz

    luz.setLuzPos(glm::vec3(R * glm::vec4(luz.getLuzPos(),1.0f))); //girando a fonte de luz em torno do eixo Z
    surface.move(1.0/FPS); //alterando a onda da superfície
    glutPostRedisplay();
}

//Função indicada na 'main' que será usada para redesenhar o conteúdo do frame buffer
void desenha(){
    glViewport(0,0,janelaLargura, janelaAltura);
    //limpando o frame buffer, mas também o depth buffer (buffer usado pra remoção de faces ocultas)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //definindo o tipo de projeção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f),               //ângulo de abertura do frustum
                                                  (float)janelaLargura/janelaAltura, //aspect ratio da tela
                                                  1.0f,                              //distância near
                                                  100.0f);                           //distância far
    glMultMatrixf(glm::value_ptr(projectionMatrix));

    //definindo o posicionamento da câmera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glm::mat4 cameraMatrix = glm::lookAt(camPos,            //posição da câmera
                                         glm::vec3(0,0,0),  //posição para onde a câmera está direcionada
                                         glm::vec3(0,0,1)); //direção para onde o topo da câmera aponta
    glMultMatrixf(glm::value_ptr(cameraMatrix));

    //desenhando itens da cena
    eixos();
    surface.desenha(camPos,luz);
    luz.desenha();

    //atualizando o desenho na tela
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_MULTISAMPLE | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(janelaLargura,janelaAltura);
    glutCreateWindow("Iluminacao");

    inicio();

    glutDisplayFunc(desenha);
    glutReshapeFunc(alteraJanela);
    glutKeyboardFunc(tecladoASCII);
    glutTimerFunc(1000.0/FPS, timer, 0);

    glutMainLoop();

    return 0;
}
