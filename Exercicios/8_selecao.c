#include <GL/glut.h>
#include <math.h>
#include <time.h>
#define true 1
#define false 0

float r1 = 1.0;
float g1 = 1.0;
float b1 = 0.0;
float r2 = 1.0;
float g2 = 1.0;
float b2 = 0.0;
float r3 = 1.0;
float g3 = 1.0;
float b3 = 0.0;
float r4 = 1.0;
float g4 = 1.0;
float b4 = 0.0;
float r01 = 0.0;
float g01 = 0.0;
float b01 = 0.0;
float r02 = 0.0;
float g02 = 0.0;
float b02 = 0.0;
float r03 = 0.0;
float g03 = 0.0;
float b03 = 0.0;
float r04 = 0.0;
float g04 = 0.0;
float b04 = 0.0;

int b = false;
int f = false;
int p = true;

void poligono(float x1, float y1, float x2, float y2, float r, float g, float b, float r0, float g0, float b0)
{
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glVertex2i(x2, y1);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(r0, g0, b0);
    glVertex2i(x1, y1);
    glVertex2i(x1, y2);
    glVertex2i(x2, y2);
    glVertex2i(x2, y1);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    poligono(30, 113, 113, 30, r1, g1, b1, r01, g01, b01);
    poligono(143, 113, 226, 30, r2, r2, b2, r02, g02, b02);
    poligono(30, 226, 113, 143, r3, g3, b3, r03, g03, b03);
    poligono(143, 226, 226, 143, r4, g4, b4, r04, g04, b04);
    glFlush();
}

void Init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 256, 0, 256);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'b':
        b = true;
        f = false;
        p = false;
        break;
    case 'f':
        b = false;
        f = true;
        p = false;
        break;
    case 'p':
        b = false;
        f = false;
        p = true;
    }
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        y = -(y - 256);
        srand(time(NULL));

        if ((b == false) && (f == false) && (p == true))
        {
            if ((state == GLUT_DOWN) && (x <= 113) && (x >= 30) && (y <= 113) && (y >= 30))
            {
                r1 = (rand() % 256) / 255.0;
                g1 = (rand() % 256) / 255.0;
                b1 = (rand() % 256) / 255.0;
            }
            else if ((state == GLUT_DOWN) && (x <= 226) && (x >= 143) && (y <= 113) && (y >= 30))
            {
                r2 = (rand() % 256) / 255.0;
                g2 = (rand() % 256) / 255.0;
                b2 = (rand() % 256) / 255.0;
            }
            else if ((state == GLUT_DOWN) && (x <= 113) && (x >= 30) && (y <= 226) && (y >= 143))
            {
                r3 = (rand() % 256) / 255.0;
                g3 = (rand() % 256) / 255.0;
                b3 = (rand() % 256) / 255.0;
            }
            else if ((state == GLUT_DOWN) && (x <= 226) && (x >= 143) && (y <= 226) && (y >= 143))
            {
                r4 = (rand() % 256) / 255.0;
                g4 = (rand() % 256) / 255.0;
                b4 = (rand() % 256) / 255.0;
            }
        }

        else if ((b == true) && (f == false) && (p == false))
        {
            if ((state == GLUT_DOWN) && (x <= 113) && (x >= 30) && (y <= 113) && (y >= 30))
            {
                r01 = (rand() % 256) / 255.0;
                g01 = (rand() % 256) / 255.0;
                b01 = (rand() % 256) / 255.0;
            }
            else if ((state == GLUT_DOWN) && (x <= 226) && (x >= 143) && (y <= 113) && (y >= 30))
            {
                r02 = (rand() % 256) / 255.0;
                g02 = (rand() % 256) / 255.0;
                b02 = (rand() % 256) / 255.0;
            }
            else if ((state == GLUT_DOWN) && (x <= 113) && (x >= 30) && (y <= 226) && (y >= 143))
            {
                r03 = (rand() % 256) / 255.0;
                g03 = (rand() % 256) / 255.0;
                b03 = (rand() % 256) / 255.0;
            }
            else if ((state == GLUT_DOWN) && (x <= 226) && (x >= 143) && (y <= 226) && (y >= 143))
            {
                r04 = (rand() % 256) / 255.0;
                g04 = (rand() % 256) / 255.0;
                b04 = (rand() % 256) / 255.0;
            }
        }

        else if ((b == false) && (f == true) && (p == false))
        {
            glClearColor((rand() % 256) / 255.0, (rand() % 256) / 255.0, (rand() % 256) / 255.0, 1.0);
        }

        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(500, 250);
    glutCreateWindow("*click*");
    Init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}