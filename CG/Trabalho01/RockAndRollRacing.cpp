#include <iostream>
#include <cmath>
#include <GL/glut.h>

// Dimensões da janela
int windowWidth = 800;
int windowHeight = 600;

// Posição e direção do carro
float carX = 0.0f;
float carY = 0.0f;
float carAngle = 0.0f;

// Velocidade e aceleração do carro
float carSpeed = 0.0f;
float carAcceleration = 0.01f;
float carMaxSpeed = 0.5f;

// Função para desenhar o carro
void drawCar() {
    glPushMatrix();
    glTranslatef(carX, carY, 0.0f);
    glRotatef(carAngle, 0.0f, 0.0f, 1.0f);

    // Desenhe o corpo do carro
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-10.0f, -5.0f);
    glVertex2f(-10.0f, 5.0f);
    glVertex2f(10.0f, 5.0f);
    glVertex2f(10.0f, -5.0f);
    glEnd();

    // Desenhe as rodas do carro
    glTranslatef(-8.0f, -5.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidTorus(1.0f, 2.0f, 10, 10);
    glTranslatef(16.0f, 0.0f, 0.0f);
    glutSolidTorus(1.0f, 2.0f, 10, 10);

    glPopMatrix();
}

// Função de desenho principal
void drawScene() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Define a cor de fundo para preto
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(20.0f);

    glPushMatrix();
    glScalef(5.0f, 5.0f, 1.0f); // Aumenta o tamanho em 5.0 vezes
    // Desenhe o circuito no formato do símbolo do infinito
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);

    const float radius = 40.0f;
    const float centerX = 0.0f;
    const float centerY = 0.0f;
    const float numSegments = 100;
    const float angleIncrement = 2.0f * 3.14159f / numSegments;

    for (int i = 0; i < numSegments; ++i) {
        float angle = i * angleIncrement;
        float x = centerX + radius * std::sin(angle);
        float y = centerY + radius * std::sin(angle * 2.0f);

        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Desenhe o carro
    drawCar();

    glutSwapBuffers();
}


// Função de atualização de estado
void update(int value) {
    // Atualize a posição e a direção do carro com base na velocidade
    carX += carSpeed * std::cos(carAngle * 3.14159f / 180.0f);
    carY += carSpeed * std::sin(carAngle * 3.14159f / 180.0f);

    // Verifique se o carro ultrapassou os limites do circuito
    if (carX < -50.0f)
        carX = -50.0f;
    if (carX > 50.0f)
        carX = 50.0f;
    if (carY < -50.0f)
        carY = -50.0f;
    if (carY > 50.0f)
        carY = 50.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Função de teclado para controlar o carro
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            carSpeed += carAcceleration;
            if (carSpeed > carMaxSpeed)
                carSpeed = carMaxSpeed;
            break;
        case 's':
            carSpeed -= carAcceleration;
            if (carSpeed < -carMaxSpeed)
                carSpeed = -carMaxSpeed;
            break;
        case 'a':
            carAngle += 5.0f;
            break;
        case 'd':
            carAngle -= 5.0f;
            break;
    }
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Rock and Roll Racing");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(drawScene);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
