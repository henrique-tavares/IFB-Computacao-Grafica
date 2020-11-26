#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define true 1
#define false 0
#define pi 3.14152635898

// Var globais
int lados = 3;

// Info sobre as transformações
// Translação
int translacao = false;
float passox = 0.1, passoy = 0.1;
// Rotação
int rotacao = false, angulo = 0;
// Escala
int escala = false;
float tamanho = 1;
// Espelhamento
int espelhamento = 1;

float r, g, b;

void init(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	srand(time(NULL));
	r = (rand() % 100 + 156) / 255.0;
	g = (rand() % 100 + 156) / 255.0;
	b = (rand() % 100 + 156) / 255.0;
	glColor3f(r, g, b);
	glClearColor(r * 0.4, g * 0.4, b * 0.4, 1.0);
	gluOrtho2D(-10.0f, 10.0f, -10.0f, 10.0f); //Posição da figura
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void Poligono(void)
{
	float angle, raioX = 4, raioY = 4;

	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
	for (int i = 0; i < lados; i++)
	{
		angle = 2 * pi * i / lados;
		glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
	}
	glEnd();
}

void Sombra(void)
{
	float angle, raioX = 4, raioY = 4;

	glBegin(GL_POLYGON);
	glColor3f(r * 0.3, g * 0.3, b * 0.3);
	for (int i = 0; i < lados; i++)
	{
		angle = 2 * pi * i / lados;
		glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
	}
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(NULL));

	glPushMatrix();
	glScalef(tamanho, tamanho, 0);
	glTranslatef(passox - 0.07, passoy - 0.10, 0);
	glRotatef(angulo, 0.0, 0.0, 1.0);
	glScalef(tamanho * espelhamento, tamanho, 0);
	Sombra();
	glPopMatrix();

	glPushMatrix();
	glScalef(tamanho, tamanho, 0);
	glTranslatef(passox, passoy, 0);
	glRotatef(angulo, 0.0, 0.0, 1.0);
	glScalef(tamanho * espelhamento, tamanho, 0);
	Sombra();
	Poligono();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //Tecla Esc encerra o programa
		exit(0);
		break;

	// Teclas para alterar o a quantidade de lados do polígono //
	case '+':
		if (lados < 15)
			lados++;
		glutPostRedisplay();
		break;

	case '-':
		if (lados > 3)
			lados--;
		glutPostRedisplay();
		break;

	case '*':
		lados = 3;
		glutPostRedisplay();
		break;

	case 't':
		translacao = true;
		rotacao = false;
		escala = false;
		break;

	case 'r':
		translacao = false;
		rotacao = true;
		escala = false;
		break;

	case 's':
		translacao = false;
		rotacao = false;
		escala = true;
		break;

	case 'm':
		espelhamento = -1;
		glutPostRedisplay();
		break;

	case 'i':
		espelhamento = 1;
		glutPostRedisplay();
		break;
	}
	// _______________________________________________________ //
}

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (translacao == true)
			passoy += 0.04;
		if (rotacao == true)
			angulo += 10;
		if (escala == true)
			tamanho += 0.1;
		break;

	case GLUT_KEY_DOWN:
		if (translacao == true)
			passoy -= 0.04;
		if (rotacao == true)
			angulo -= 10;
		if (escala == true)
			tamanho -= 0.1;
		break;

	case GLUT_KEY_RIGHT:
		if (translacao == true)
			passox += 0.04;
		break;

	case GLUT_KEY_LEFT:
		if (translacao == true)
			passox -= 0.04;
		break;
	}
	glutPostRedisplay();
}

void randomcolor(int value)
{
	r = (rand() % 100 + 156) / 255.0;
	g = (rand() % 100 + 156) / 255.0;
	b = (rand() % 100 + 156) / 255.0;
	glColor3f(r, g, b);
	glClearColor(r * 0.4, g * 0.4, b * 0.4, 1.0);
	glutPostRedisplay();

	glutTimerFunc(500, randomcolor, 1);
}

//Função Principal
int main(int argc, char **argv)
{
	glutInit(&argc, argv);						 //Incializa o glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Epecifica o sistema de cores
	glutInitWindowSize(600, 550);				 //Dimeções da janela
	glutInitWindowPosition(200, 100);			 // Posição das Janelas
	glutCreateWindow("Poligonos daoras");
	init();
	glutDisplayFunc(display);   //Redesenha o GLUT
	glutKeyboardFunc(keyboard); //Função do teclado
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(500, randomcolor, 1);
	glutMainLoop(); //Mostra as janelas criadas

	return 0;
}