#include <GL/glut.h>


void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glPointSize(5); 
    glLineWidth(3); 
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT); 
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glColor3f(0.0, 0.0, 0.0);    
    glBegin(GL_QUADS);       
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(1.0, -1.0);  
        glVertex2f(1.0, 1.0); 
        glVertex2f(-1.0, 1.0);
        glVertex2f(-1.0, -1.0);
    glEnd();
    
    glFlush();  
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                         
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition(200,200);              
    glutInitWindowSize(300,300);                  
    glutCreateWindow("Q01");             
 
    inicio(); 
 
    glutDisplayFunc(desenha);   
 
    glutMainLoop();             
    
    return 0;
}