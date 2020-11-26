#include <GL/glut.h>
#include <math.h>

int quadrado(float x, float y, float size, float r, float g, float b)
{
    size = size / 2;
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-size + x, size + y);
    glVertex2f(size + x, size + y);
    glVertex2f(size + x, -size + y);
    glVertex2f(-size + x, -size + y);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-size + x, size + y);
    glVertex2f(size + x, size + y);
    glVertex2f(size + x, -size + y);
    glVertex2f(-size + x, -size + y);
    glEnd();
}

void IVquadrados()
{
    glClear(GL_COLOR_BUFFER_BIT);
    quadrado(-0.5, 0.5, 0.5, 0.8, 0.1, 0.1);
    quadrado(0.5, 0.5, 0.5, 0.1, 0.1, 0.8);
    quadrado(0.5, -0.5, 0.5, 0.1, 0.8, 0.1);
    quadrado(-0.5, -0.5, 0.5, 0.0, 0.7, 0.7);
    glFlush();
}

void Init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(500, 250);
    glutCreateWindow("4 Queijos");
    Init();
    glutDisplayFunc(IVquadrados);
    glutMainLoop();

    return 0;
}