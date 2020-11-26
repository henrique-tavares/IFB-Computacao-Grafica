#include <GL/glut.h>
#include <math.h>
#include <time.h>
#define pi 3.1459

int ambiente, figura, size;
float r1, g1, b1, r2, g2, b2, x, y;

void corpo()
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.9, 0.7, 0.0);
    glVertex2i(-130, 20);
    glVertex2i(-100, 0);
    glVertex2i(-100, 130);
    glVertex2i(100, 0);
    glVertex2i(100, 130);
    glVertex2i(160, 50);
    glVertex2i(160, 80);
    glEnd();
}

void cabeca()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.5, 0.0);
    glVertex2i(-140, 80);
    glVertex2i(-140, -10);
    glVertex2i(-230, 70);
    glVertex2i(-180, 150);
    glVertex2i(-100, 150);
    glVertex2i(-50, 70);
    glVertex2i(-140, -10);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.9, 0.7, 0.0);
    glVertex2i(-140, 85);
    glVertex2i(-160, 130);
    glVertex2i(-120, 130);
    glVertex2i(-80, 85);
    glVertex2i(-120, 40);
    glVertex2i(-160, 40);
    glVertex2i(-200, 85);
    glVertex2i(-160, 130);
    glEnd();
}

void rosto()
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(-160, 110);
    glVertex2i(-160, 100);
    glVertex2i(-152.5, 110);
    glVertex2i(-152.5, 100);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(-152.5, 110);
    glVertex2i(-152.5, 100);
    glVertex2i(-145, 110);
    glVertex2i(-145, 100);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.9, 0.4, 0.4);
    glVertex2i(-200, 85);
    glVertex2i(-195, 90);
    glVertex2i(-195, 80);
    glVertex2i(-190, 85);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.7, 0.3, 0.0);
    glVertex2i(-180, 62.5);
    glVertex2i(-150, 62.5);
    glEnd();
    glLineWidth(1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.9, 0.7, 0.0);
    glVertex2i(-127, 140);
    glVertex2i(-130, 130);
    glVertex2i(-121, 145);
    glVertex2i(-115, 122);
    glVertex2i(-118, 137);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.7, 0.3, 0.0);
    glVertex2i(-123, 130);
    glVertex2i(-122, 140);
    glEnd();
}

void pata(int x, int y)
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.9, 0.7, 0.0);
    glVertex2i(-10 + x, 30 + y);
    glVertex2i(-10 + x, -40 + y);
    glVertex2i(10 + x, 30 + y);
    glVertex2i(10 + x, -40 + y);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(10 + x, -40 + y);
    glVertex2i(0 + x, -50 + y);
    glVertex2i(-5 + x, -30 + y);
    glVertex2i(-30 + x, -50 + y);
    glVertex2i(-30 + x, -30 + y);
    glVertex2i(-40 + x, -40 + y);
    glEnd();
}

void rabo()
{
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.9, 0.7, 0.0);
    glVertex2i(160, 70);
    glVertex2i(160, 80);
    glVertex2i(185, 70);
    glVertex2i(190, 80);
    glVertex2i(203, 45);
    glVertex2i(210, 50);
    glVertex2i(215, 15);
    glVertex2i(220, 22);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.8, 0.5, 0.0);
    glVertex2i(225, 20.5);
    glVertex2i(220, 22);
    glVertex2i(225, 26);
    glVertex2i(235, 22);
    glVertex2i(225, 10);
    glVertex2i(215, 15);
    glVertex2i(220, 22);
    glEnd();
}

void num2()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(-250,250);
    glVertex2i(-250,230);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(-242,250);
    glVertex2i(-242,230);
    glEnd();
}

void quadrado(int x, int y, float r, float g, float b, int size)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2i(x - size, y + size);
    glVertex2i(x + size, y + size);
    glVertex2i(x + size, y - size);
    glVertex2i(x - size, y - size);
    glEnd();
    num2();
    glFlush();
}

void circulo(int x, int y, float r, float g, float b, int size)
{
    GLfloat pontos, raiox, raioy, angulo;
    pontos = 100.0f;
    raiox = size;
    raioy = size;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for (int i = 0; i <= pontos; i++)
    {
        angulo = 2 * pi * i / pontos;
        glVertex2f(cos(angulo) * raiox + x, sin(angulo) * raioy + y);
    }
    glEnd();
    num2();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    switch (ambiente)
    {
    case 1:
        corpo();
        cabeca();
        rosto();
        pata(-80, -30);
        pata(-30, -10);
        pata(80, -10);
        pata(30, -30);
        rabo();
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-250,250);
        glVertex2i(-250,230);
        glEnd();
        break;

    case 2:
        num2();
        break;
    }

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:

        if (ambiente == 2)
        {
            srand(time(NULL));
            figura = rand() % 2;
            size = 10 + (rand() % 141);

            switch (figura)
            {
            case 0:
                r1 = (rand() % 256) / 255.0;
                g1 = (rand() % 256) / 255.0;
                b1 = (rand() % 256) / 255.0;
                x = -(230 - size) + (rand() % (2 * (230 - size)) + 1);
                y = -(230 - size) + (rand() % (2 * (230 - size)) + 1);
                quadrado(x, y, r1, g1, b1, size);
                break;

            case 1:
                r2 = (rand() % 256) / 255.0;
                g2 = (rand() % 256) / 255.0;
                b2 = (rand() % 256) / 255.0;
                x = -(240 - size) + (rand() % (2 * (240 - size)) + 1);
                y = -(240 - size) + (rand() % (2 * (240 - size)) + 1);
                circulo(x, y, r2, g2, b2, size);
                break;
            }
        }
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;

    case '1':
        ambiente = 1;
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glutPostRedisplay();
        break;

    case '2':
        ambiente = 2;
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glutPostRedisplay();
    }
}

void Init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-256, 256, -256, 256);
    ambiente = 1;
    size = 20;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(518, 518);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("1: el leon, 2: cuadrados y circunferencias");
    Init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
