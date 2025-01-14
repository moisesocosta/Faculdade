#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <ctime>

// Dimensões da janela
int windowWidth = 800;
int windowHeight = 600;

// Classe para representar o carro
class Carro {
public:
    float x;
    float y;
    float z;
    float angle;
    float speed;
    float acceleration;
    float maxSpeed;

    Carro(float startX, float startY, float startZ, float startAngle, float startMaxSpeed)
        : x(startX), y(startY), z(startZ), angle(startAngle), speed(0.0f),
          acceleration(0.01f), maxSpeed(startMaxSpeed) {}

    void update() {
        float dx = speed * std::cos(angle * 3.14159f / 180.0f);
        float dy = speed * std::sin(angle * 3.14159f / 180.0f);
        x += dx;
        y += dy;
    }

    void accelerate() {
        speed += acceleration;
        if (speed > maxSpeed)
            speed = maxSpeed;
    }

    void decelerate() {
        speed -= acceleration;
        if (speed < -maxSpeed)
            speed = -maxSpeed;
    }

    void turnLeft() {
        angle += 5.0f;
    }

    void turnRight() {
        angle -= 5.0f;
    }

    void draw() {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        // Desenhe o corpo do carro
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glEnd();

        // Desenhe as rodas do carro
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(-0.8f, -0.8f, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(-0.2f, -0.2f, 0.0f);
        glVertex3f(-0.2f, 0.2f, 0.0f);
        glVertex3f(0.2f, 0.2f, 0.0f);
        glVertex3f(0.2f, -0.2f, 0.0f);
        glEnd();

        glTranslatef(1.6f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(-0.2f, -0.2f, 0.0f);
        glVertex3f(-0.2f, 0.2f, 0.0f);
        glVertex3f(0.2f, 0.2f, 0.0f);
        glVertex3f(0.2f, -0.2f, 0.0f);
        glEnd();

        glPopMatrix();
    }
};

// Classe para representar os obstáculos
class Obstaculo {
public:
    float x;
    float y;
    float z;
    float radius;

    Obstaculo(float startX, float startY, float startZ, float startRadius)
        : x(startX), y(startY), z(startZ), radius(startRadius) {}

    void draw() {
        glPushMatrix();
        glTranslatef(x, y, z);
        glColor3f(1.0f, 0.0f, 0.0f);
        glutSolidSphere(radius, 16, 16);
        glPopMatrix();
    }
};

// Classe para representar o cenário
class Cenario {
public:
    GLuint groundTexture;

    Cenario(const char* groundTexturePath) {
        groundTexture = loadTexture(groundTexturePath);
    }

    GLuint loadTexture(const char* filename) {
        int width, height, channels;
        unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
        if (!image) {
            std::cerr << "Erro ao carregar a textura: " << filename << std::endl;
            return 0;
        }

        GLuint textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Configuração da textura
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

        stbi_image_free(image);

        return textureID;
    }

    void drawGround() {
        glBindTexture(GL_TEXTURE_2D, groundTexture);

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.1f);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-50.0f, -50.0f, 0.0f);
        glTexCoord2f(0.0f, 10.0f);
        glVertex3f(-50.0f, 50.0f, 0.0f);
        glTexCoord2f(10.0f, 10.0f);
        glVertex3f(50.0f, 50.0f, 0.0f);
        glTexCoord2f(10.0f, 0.0f);
        glVertex3f(50.0f, -50.0f, 0.0f);
        glEnd();

        glPopMatrix();
    }
};

// Variáveis globais para o carro, os obstáculos e o cenário
Carro carro(0.0f, 0.0f, 0.0f, 0.0f, 0.5f);
Cenario cenario("ground_texture.jpg");
std::vector<Obstaculo> obstaculos;

// Variáveis globais para controle de câmera
float cameraX = 0.0f;
float cameraY = 0.0f;
float cameraZ = 10.0f;
float cameraLookX = 0.0f;
float cameraLookY = 0.0f;
float cameraLookZ = 0.0f;

// Função para gerar obstáculos aleatórios
void gerarObstaculos() {
    srand(static_cast<unsigned>(time(NULL)));

    for (int i = 0; i < 10; i++) {
        float startX = static_cast<float>(rand() % 100 - 50);
        float startY = static_cast<float>(rand() % 100 - 50);
        float startZ = 0.0f;
        float startRadius = static_cast<float>(rand() % 4 + 1);

        obstaculos.push_back(Obstaculo(startX, startY, startZ, startRadius));
    }
}

// Função de desenho principal
void drawScene() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, cameraY, cameraZ, cameraLookX, cameraLookY, cameraLookZ, 0.0f, 1.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);

    cenario.drawGround();
    carro.draw();

    for (int i = 0; i < obstaculos.size(); i++) {
        obstaculos[i].draw();
    }

    glutSwapBuffers();
}

// Função de atualização de estado
void update(int value) {
    carro.update();

    // Verifica colisões com obstáculos
    for (int i = 0; i < obstaculos.size(); i++) {
        float dx = obstaculos[i].x - carro.x;
        float dy = obstaculos[i].y - carro.y;
        float distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));

        if (distance <= obstaculos[i].radius) {
            // Colisão detectada! Reduza a velocidade do carro
            carro.speed *= 0.5f;

            // Reposicione o carro para evitar sobreposição com o obstáculo
            float collisionAngle = std::atan2(dy, dx);
            float safeDistance = obstaculos[i].radius + 1.0f;
            carro.x = obstaculos[i].x + safeDistance * std::cos(collisionAngle);
            carro.y = obstaculos[i].y + safeDistance * std::sin(collisionAngle);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Função de teclado para controlar o carro e a câmera
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            carro.accelerate();
            break;
        case 's':
            carro.decelerate();
            break;
        case 'a':
            carro.turnLeft();
            break;
        case 'd':
            carro.turnRight();
            break;
        case 'q':
            cameraX -= 1.0f;
            break;
        case 'e':
            cameraX += 1.0f;
            break;
        case 'r':
            cameraY += 1.0f;
            break;
        case 'f':
            cameraY -= 1.0f;
            break;
        case 't':
            cameraZ += 1.0f;
            break;
        case 'g':
            cameraZ -= 1.0f;
            break;
    }
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Rock and Roll Racing");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<float>(windowWidth) / static_cast<float>(windowHeight), 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

    gerarObstaculos();

    glutDisplayFunc(drawScene);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
