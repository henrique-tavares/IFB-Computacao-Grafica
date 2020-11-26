#include <GL/glut.h>
#include <math.h>
#define pi 3.1415926535898

void arco()
{
    GLfloat pontos, angulo, raiox, raioy;
    pontos = 100.0f;
    raiox = 0.5f;
    raioy = 0.5f;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i <= pontos; i++)
    {
        angulo = 1 * pi * i / pontos;
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
    glutCreateWindow("Arco");
    glutDisplayFunc(arco);
    glutMainLoop();

    return 0;
}
