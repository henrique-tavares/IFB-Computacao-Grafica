#include <GL/glut.h>
#include <math.h>

int losango25D(float x, float y, float width, float height, float r, float g, float b)
{
    glColor3f(r * 0.6, g * 0.6, b * 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(-width + x, 0.0 + y + height);
    glVertex2f(-width + x, 0.0 + y);
    glVertex2f(0.0 + x, (-width / 2) + y);
    glVertex2f(0.0 + x, (-width / 2) + y + height);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-width + x, 0.0 + y + height);
    glVertex2f(-width + x, 0.0 + y);
    glVertex2f(0.0 + x, (-width / 2) + y);
    glVertex2f(0.0 + x, (-width / 2) + y + height);
    glEnd();
    glColor3f(r * 0.4, g * 0.4, b * 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(0.0 + x, (-width / 2) + y + height);
    glVertex2f(width + x, 0.0 + y + height);
    glVertex2f(width + x, 0.0 + y);
    glVertex2f(0.0 + x, (-width / 2) + y);    
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0 + x, (-width / 2) + y + height);
    glVertex2f(width + x, 0.0 + y + height);
    glVertex2f(width + x, 0.0 + y);
    glVertex2f(0.0 + x, (-width / 2) + y);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(r * 0.9, g * 0.9, b * 0.9);
    glVertex2f(-width + x, 0.0 + y + height);
    glVertex2f(0.0 + x, (width / 2) + y + height);
    glVertex2f(width + x, 0.0 + y + height);
    glVertex2f(0.0 + x, (-width / 2) + y + height);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-width + x, 0.0 + y + height);
    glVertex2f(0.0 + x, (width / 2) + y + height);
    glVertex2f(width + x, 0.0 + y + height);
    glVertex2f(0.0 + x, (-width / 2) + y + height);
    glEnd();
}

void tijolo1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    losango25D(0.0, 0.1, 0.2, 0.0, 0.3, 0.3, 0.3);
    losango25D(0.0, -0.1, 0.2, 0.0, 0.3, 0.3, 0.3);
    losango25D(-0.2, 0.0, 0.2, 0.0, 0.3, 0.3, 0.3);
    losango25D(0.0, 0.3, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.2, 0.2, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.4, 0.1, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.2, 0.0, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.6, 0.0, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.4, -0.1, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.2, -0.2, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(-0.2, 0.2, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(-0.4, 0.1, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(-0.6, 0.0, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(-0.4, -0.1, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(-0.2, -0.2, 0.2, 0.05, 0.9, 0.9, 0.9);
    losango25D(0.0, -0.3, 0.2, 0.05, 0.9, 0.9, 0.9);
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
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(400, 50);
    glutCreateWindow("Tijolo Isometrico 2.5D");
    Init();
    glutDisplayFunc(tijolo1);
    glutMainLoop();

    return 0;
}