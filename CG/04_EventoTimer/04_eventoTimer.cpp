#include <GL/glut.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "objeto.h"

#define FPS 60

using namespace std;

/*
 * Programa básico para realizar animações na GLUT
 * Dois pontos andam para esquerda e direita em velocidades diferentes
 */

//Variáveis globais
//Construtor da classe Objeto(posiçãoInicial, direçãoMovimento, cor)
Objeto A(glm::vec2(0,3) ,DIREITA,glm::vec3(1,0,0)); //Objeto A vermelho acima indo para direita
Objeto B(glm::vec2(0,-3),DIREITA,glm::vec3(0,0,1)); //Objeto B azul abaixo indo para direita

//Função com configurações iniciais da aplicação
void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(30.0); 
    glLineWidth(3.0);  
    glEnable(GL_MULTISAMPLE); //habilitar antialiasing fará o ponto parecer arredondado
}

//Função que será executada periodicamente (serve para realizar as modificações entre um frame e o próximo da animação)
void timer(int v){
    //A função glutTimerFunc define que a função 'timer' irá executar novamente daqui a uma certa quantidade de tempo em milissegundos.
    //Se deseja executar 60 frames por segundo, o tempo entre um frame e o próximo é 1000/60 milissegundos
    //Atenção! Não chame timer dentro de timer. Isso criará uma recursão infinita.
    glutTimerFunc(1000.0/FPS, timer, 0);

    //Realize as modificações entre um frame e o próximo aqui
    //Como o objeto B move-se uma distância maior do que A entre cada frame, ele irá parecer andar mais rápido na tela
    A.move(0.1);
    B.move(0.2);

    //Após as modificações, a tela deve ser atualizada
    glutPostRedisplay();
}

//Função que será executada o tempo todo (sem limitação de tempo)
void idle(){
    //A função glutIdleFunc indica pra GLUT que a função 'idle' será executada o tempo inteiro, sem intervalo de tempo entre uma chamada e a próxima.
    //A velocidade das chamadas depende do poder de processamento do computador (CPU e GPU). Quanto maior o poder de processamento, mais chamadas são feitas à função, resultando em atualizações mais altas.
    //Essa função deve ser evitada, pois assim você não tem certeza de quanto tempo se passou entre um frame e o próximo, causando dificuldades em construir animações precisas.
    
    //Realize as modificações entre um frame e o próximo aqui
    //Como o objeto B move-se uma distância maior do que A entre cada frame, ele irá parecer andar mais rápido na tela
    A.move(0.1);
    B.move(0.2);

    //Após as modificações, a tela deve ser atualizada
    glutPostRedisplay();
}

//Função indicada na 'main' que será usada para redesenhar o conteúdo do frame buffer
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,1); //define o espaço do desenho no intervalo [-10,10] para x e y
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    A.desenha();
    B.desenha();

    //Na 'main' é definido o uso de dois Frame-Buffers usados em paralelo. Essa instrução alterna entre um e outro na tela.
    glutSwapBuffers(); 
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    //GLUT_DOUBLE define que utilizará dois frame-buffers. Isso é útil em animações para evitar o problema de 'flickering' (pisca-pisca)
    //GLUT_MULTISAMPLE habilita uma técnica de antialiasing, suavizando pontos e linhas (aumenta o processamento do programa)
    glutInitDisplayMode(GLUT_MULTISAMPLE | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Evento de timer");

    inicio();

    //Use apenas uma das instruções abaixo para animações (sugiro manter a Timer, mas realize testes com a Idle)
    glutDisplayFunc(desenha);
    glutTimerFunc(1000.0/FPS, timer, 0); //irá executar a função 'timer' após um intervalo de tempo
    //glutIdleFunc(idle);                //irá executar a função 'idle' o tempo todo

    glutMainLoop();

    return 0;
}
