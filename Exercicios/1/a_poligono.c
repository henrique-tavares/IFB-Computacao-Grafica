#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void poligono()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.5, 0.25);
    glVertex2f(0.5, -0.25);
    glVertex2f(-0.5, -0.25);
    glVertex2f(-0.5, 0.25);
    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Poligono");
    init();
    glutDisplayFunc(poligono);
    glutMainLoop();
}