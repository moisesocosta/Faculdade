#include <GL/glut.h>
#include <glm/glm.hpp> //biblioteca GLM permite usar a estrutura vec2 (classe pra armazenar vetor de duas coordenadas)
#include <vector>      //inclui a classe vector, que implementa um vetor de tamanho variável

using namespace std;

/*
 * Programa básico para testar eventos de mouse na GLUT.
 * Clique com o botão direito do mouse, cria um ponto
 * Clique com o botão esquerdo do mouse, cria dois pontos e os conecta por um segmento de reta
 * Se após o clique, o botão permanecer pressionado e o mouse for movido, o último ponto criado será movido
 */

//Variáveis globais
int janelaLargura = 400;   //variável que mantém a largura da janela em pixels
int janelaAltura  = 400;   //variável que mantém a altura da janela em pixels
vector<glm::vec2> pontos;  //array usado para armazenar todos os pontos gerados

//Função com configurações iniciais da aplicação
void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(10.0); //indica para OpenGL que os pontos terão uma largura de aproximadamente 10 pixels
    glLineWidth(3.0);  //indica para OpenGL que os segmentos de reta terão uma largura de aproximadamente 3 pixels
}

//Função indicada pra GLUT que será executada sempre que a janela for redimensionada
void redimensionaJanela(int largura, int altura){
    //as variáveis 'largura' e 'altura' são preenchidas pela GLUT quando a janela é redimensionada
    //salvando esses valores nas variáveis globais 'janelaLargura' e 'alturaJanela'
    janelaLargura = largura;
    janelaAltura = altura;

    glViewport(0,0,largura,altura); //área de desenho deve ser igual a nova área da janela
    glutPostRedisplay();            //redesenha a janela
}

//Função indicada pra GLUT que será executada sempre que um botão do mouse seja pressionado ou liberado
void mouseClique(int button, int state, int x, int y){
    //conversão de coordenada de pixel para coordenada de mundo
    float coord_x = x;
    float coord_y = janelaAltura - y;  //correção da coordenada y, porque na aplicação gráfica, as coordenadas y aumentam para cima e não para baixo.

    //Se o botão esquerdo do mouse (GLUT_LEFT_BUTTON) for sido pressionado (GLUT_DOWN)...
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glm::vec2 novoPonto;         //crie um novo ponto usando as coordenadas de janela 'coord_x' e 'coord_y'
        novoPonto.x = coord_x;
        novoPonto.y = coord_y;
        pontos.push_back(novoPonto); //insere o novo ponto alocado no final do vetor 'pontos'
    }

    glutPostRedisplay(); //redesenha a janela
}

//Função indicada pra GLUT que será usada para redesenhar o conteúdo do frame buffer
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    //espaço de visualização com a mesma resolução da janela para facilitar a conversão de coordenada de pixel com coordenada de mundo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,janelaLargura-1,0,janelaAltura-1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Desenhando todos os pontos (GL_POINTS) na cor azul
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
        for(unsigned int i = 0 ; i < pontos.size() ; i++)
            glVertex2f(pontos[i].x, pontos[i].y);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(janelaLargura,janelaAltura);
    glutCreateWindow("Evento de Mouse");

    inicio();

    glutDisplayFunc(desenha);
    glutReshapeFunc(redimensionaJanela); //função 'redimensionaJanela' será chamada cada vez que tamanho da janela for modificado
    glutMouseFunc(mouseClique);          //função 'mouseClique' será chamada cada vez que botão do mouse é usado

    glutMainLoop();

    return 0;
}
