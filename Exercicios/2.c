#include <GL/glut.h>
#include <math.h>

void isometrico2D()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.6, 0.0);
    glVertex2f(0.0, 0.3);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.0, -0.3);
    glEnd();
    glFlush();
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

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(518, 518);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tijolo Isometrico 2D");
    glutDisplayFunc(isometrico2D);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}