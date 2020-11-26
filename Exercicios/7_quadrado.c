#include <GL/glut.h>
#include <math.h>

GLfloat r, g, b;

void Init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0,256,0,256);
    r = 1;
    g = 0;
    b = 0;
}

void quadrado()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2i(30, 226);
    glVertex2i(226, 226);
    glVertex2i(226, 30);
    glVertex2i(30, 30);
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        r = 0;
        b = 1;
        glutPostRedisplay();
        break;
    case 'v':
        r = 1;
        b = 0;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(500, 250);
    glutCreateWindow("Daltonismo");
    Init();
    glutDisplayFunc(quadrado);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}