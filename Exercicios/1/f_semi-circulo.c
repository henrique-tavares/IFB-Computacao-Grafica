#include <GL/glut.h>
#include <math.h>
#define pi 3.1415926535898

void semi_circulo()
{
    GLfloat pontos, angulo, raiox, raioy;
    pontos = 100.0f;
    raiox = 0.5f;
    raioy = 0.5f;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.0,0.0);
    for (int i = 0; i <= pontos; i++)
    {
        angulo = 1.6 * pi * i / pontos;
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
    glutCreateWindow("Semi circulo");
    glutDisplayFunc(semi_circulo);
    glutMainLoop();

    return 0;
}
