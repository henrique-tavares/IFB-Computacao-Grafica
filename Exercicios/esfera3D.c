
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float alpha = 0;
float beta = 0;
float delta = 1;
float alpha2 = 0;
float beta2 = 0;
float all = 1;
float alpha3 = 0;
float beta3 = 0;
float angle_alpha3 = 0.2;

void init(void)
{
	glClearColor(0, 0, 0, 0); //define a cor de fundo
	glEnable(GL_DEPTH_TEST); //remoção de superfície oculta
	glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
	glLoadIdentity(); //carrega a matrix de identidade
	glOrtho(-10, 10, -10, 10, -10, 10); //define uma projeção ortográfica
}

void display(void)
{
	//limpa o buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//define que a matrix é a de modelo
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //carrega matrix identidade
	//rotaciona e escala uma esfera ' aramado '
	glPushMatrix();
	glRotatef(beta3, 0, 1, 0);
	glRotatef(alpha3, 1, 0, 0);
	glRotatef(beta, 0, 1, 0);
	glRotatef(alpha, 1, 0, 0);
	glRotatef(beta2, 0, 1, 0);
	glRotatef(alpha2, 0, 0, 1);
	glScalef(delta, delta, delta);
	glColor3f(1,0.5,0);
	glutWireSphere(2.0f,20,20);
	glPopMatrix();
	//desenha um ' piso ' sob a esfera
	glPushMatrix();
	glRotatef(beta3, 0, 1, 0);
	glRotatef(alpha3, 1, 0, 0);
	glRotatef(beta, 0, 1, 0);
	glRotatef(alpha, 1, 0, 0);
	glScalef(delta, delta, delta);
	glTranslatef(0,-4,0);
	glScalef(8, 0.1, 8);
	glColor3f(0.8,0,0);
	glutWireCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glRotatef(beta3, 0, 1, 0);
	glRotatef(alpha3, 1, 0, 0);
	glRotatef(beta, 0, 1, 0);
	glRotatef(alpha, 1, 0, 0);
	glRotatef(beta2, 0, 1, 0);
	//glRotatef(alpha2, 1, 0, 0);
	glScalef(delta, delta, delta);
	glTranslatef(0,-2,-2);
	glScalef(0.2, 4.1, 0.2);
	glColor3f(1.0,1.0,1.0);
	glutWireCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glRotatef(beta3, 0, 1, 0);
	glRotatef(alpha3, 1, 0, 0);
	glRotatef(beta, 0, 1, 0);
	glRotatef(alpha, 1, 0, 0);
	glRotatef(beta2, 0, 1, 0);
	//glRotatef(alpha2, 1, 0, 0);
	glScalef(delta, delta, delta);
	glTranslatef(0,-2,2);
	glScalef(0.2, 4.1, 0.2);
	glColor3f(1.0,1.0,1.0);
	glutWireCube(1.0f);
	glPopMatrix();
	
	//força o desenho das primitivas
	glutSwapBuffers();
}

void special_keyboard(int key, int x, int y)
{
	if (all == 1)
	{
		switch (key)
		{
		case GLUT_KEY_PAGE_UP: //faz zoom − in
			delta = delta * 1.1;
			break;
		case GLUT_KEY_PAGE_DOWN: //faz zoom − out
			delta = delta * 0.809;
			break;
		case GLUT_KEY_UP: //gira sobre o eixo − x
			alpha = alpha - 10;
			break;
		case GLUT_KEY_DOWN: //gira sobre o eixo − x
			alpha = alpha + 10;
			break;
		case GLUT_KEY_LEFT: //gira sobre o eixo − y
			beta = beta + 10;
			break;
		case GLUT_KEY_RIGHT: //gira sobre o eixo − y
			beta = beta - 10;
			break;
		case GLUT_KEY_F1:
			all = 1;
			break;
		case GLUT_KEY_F2:
			all = 0;
			break;
		}
	}

	else if (all == 0)
	{
		switch (key)
		{
		case GLUT_KEY_PAGE_UP: //faz zoom − in
			delta = delta * 1.1;
			break;
		case GLUT_KEY_PAGE_DOWN: //faz zoom − out
			delta = delta * 0.809;
			break;
		case GLUT_KEY_UP: //gira sobre o eixo − x
			alpha2 = alpha2 - 10;
			break;
		case GLUT_KEY_DOWN: //gira sobre o eixo − x
			alpha2 = alpha2 + 10;
			break;
		case GLUT_KEY_LEFT: //gira sobre o eixo − y
			beta2 = beta2 + 10;
			break;
		case GLUT_KEY_RIGHT: //gira sobre o eixo − y
			beta2 = beta2 - 10;
			break;
		case GLUT_KEY_F1:
			all = 1;
			break;
		case GLUT_KEY_F2:
			all = 0;
			break;
		}
	}
	//forçar o redesenho da tela usando double − buffering
	glutPostRedisplay();
}

void temp()
{
	if ((alpha3 < 20) && (alpha3 > -20))
		alpha3 += angle_alpha3;
	else
	{
		angle_alpha3 = -angle_alpha3;
		alpha3 += angle_alpha3;
	}	

	beta3 += 0.8;
	glutPostRedisplay();
	glutTimerFunc(33, temp, 1);
}

void keyboard(unsigned char key, int x, int y)
{
	// ' q ' ou ' Q ' ou ESC para sair do sistema
	if ('q' == key || 'Q' == key || 27 == key)
	{
		exit(0);
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D");
	init();
	//funções de callback
	glutDisplayFunc(display); //registra função de desenho
	glutKeyboardFunc(keyboard); //registra teclado
	glutSpecialFunc(special_keyboard); //registra teclado especial
	glutTimerFunc(33, temp, 1);
	glutMainLoop();
	return 0;
}
//esfera3D.c
//Displaying esfera3D.c.
