#include <GL/glut.h>
#include <math.h>
#define pi 3.1415926535898

void elipse()
{
    GLfloat pontos, angulo, raiox, raioy;
    pontos = 100.0f;
    raiox = 0.7f;
    raioy = 0.3f;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i <= pontos; i++)
    {
        angulo = 2 * pi * i / pontos;
        glVertex2f(cos(angulo) * raiox, sin(angulo) * raioy);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(518, 518);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Elipse");
    glutDisplayFunc(elipse);
    glutMainLoop();

    return 0;
}
