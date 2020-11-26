#include <GL/glut.h>
#include <math.h>

void isometrico3D()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.6,0.6);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.6,-0.15);
    glVertex2f(0.0,-0.45);
    glVertex2f(0.0,-0.3);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);
    glVertex2f(0.6,0.0);
    glVertex2f(0.6,-0.15);
    glVertex2f(0.0,-0.45);
    glVertex2f(0.0,-0.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex2f(-0.6,0.0);
    glVertex2f(0.0,0.3);
    glVertex2f(0.6,0.0);
    glVertex2f(0.0,-0.3);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(518,518);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Tijolo Isometrico 2.5D");
    glutDisplayFunc(isometrico3D);
    glutMainLoop();

    return 0;
}