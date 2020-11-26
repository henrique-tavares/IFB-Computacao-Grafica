#include <stdlib.h>
#include <unistd.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>

float r, g, b;

void quadradorainbow()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    glVertex2f(0.9, -0.9);
    glVertex2f(-0.9, -0.9);
    glEnd();
    glFlush();
}

void Init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}

void timer(int value)
{
    srand(time(NULL));
    r = (rand() % 256) / 255.0;
    g = (rand() % 256) / 255.0;
    b = (rand() % 256) / 255.0;
    glColor3f(r, g, b);
    glutPostRedisplay();
    glutTimerFunc(100, timer, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(500, 250);
    glutCreateWindow("Quadrado Arcoiro");
    Init();
    glutDisplayFunc(quadradorainbow);
    glutTimerFunc(100, timer, 1);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}