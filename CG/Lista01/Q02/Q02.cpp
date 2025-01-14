#include <GL/glut.h>

void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(5);
    glLineWidth(3);
}

void primitiva(){   
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0, 0);
        glVertex2f(-2, -2);
        glVertex2f(2, -2);
        glVertex2f(2, 2);
        glVertex2f(-2, 2);
        glVertex2f(-2, -2);
    glEnd(); 
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT); 

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -1, 1);  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();
    
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL ); 
    glColor3f(1.0, 0.0, 0.0);                     
    primitiva();                                

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); 
    glColor3f(0.0, 0.0, 0.0);                    
    primitiva();                                

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                         
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition(200,200);              
    glutInitWindowSize(300,300);                  
    glutCreateWindow("Q02");             
 
    inicio(); 
 
    glutDisplayFunc(desenha); 
 
    glutMainLoop();             
    
    return 0;
}