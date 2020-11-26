#include <GL/glut.h>          // Header File For The GLut Library
#include <stdlib.h>
#include <time.h>
// Initial square position and size
GLfloat x = 13.0;
GLfloat y = 0.0;
GLfloat x2 = 17.0;
GLfloat y2 = 0.0;
GLfloat size = 2.5;
GLfloat angle = 0;
GLfloat angle2 = 0;

// Step values for coordinates 
GLfloat xstep = 1;
GLfloat ystep = 1;
GLfloat xstep2 = 1;
GLfloat ystep2 = 1;

void quad()
{
	glBegin(GL_QUADS);
	glVertex2f( 0.0, 0.0);
	glVertex2f( 2.5, 0.0);
	glVertex2f( 2.5, 2.5);
	glVertex2f( 0.0, 2.5);
	glEnd();
}

void quad2()
{
	glBegin(GL_QUADS);
	glVertex2f( 0.0, 0.0);
	glVertex2f( 2.5, 0.0);
	glVertex2f( 2.5, 2.5);
	glVertex2f( 0.0, 2.5);
	glEnd();
}

GLvoid DESENHAR(GLvoid)
{
	srand(time(NULL));
	glClearColor(0.7f,0.7f,0.7f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,40.0,0.0,40.0);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	// BEGIN collision detection for a square 
	if (x + size > 40.0  || x < 0.0)
		//glRotatef(45,0.0,0.0,1.0);
		xstep = -xstep; // reverse direction on left or right edge
	if (y + size > 40 || y < 0)
		//glRotatef(45,0.0,0.0,1.0);
		ystep = -ystep; // reverse direction on top or bottom edge

	x += xstep*(rand()%100 + 1)/100; // update x-coordinate for square origin 
	y += ystep*(rand()%100 + 1)/100; // update y-coordinate for square origin
	// END collision detection for a square
	angle += 5*size;

	if (x2 + size > 40.0  || x2 < 0.0)
		//glRotatef(45,0.0,0.0,1.0);
		xstep2 = -xstep2; // reverse direction on left or right edge
	if (y2 + size > 40 || y2 < 0)
		//glRotatef(45,0.0,0.0,1.0);
		ystep2 = -ystep2; // reverse direction on top or bottom edge

	x2 += xstep2*(rand()%100 + 1)/100; // update x-coordinate for square origin 
	y2 += ystep2*(rand()%100 + 1)/100; // update y-coordinate for square origin
	// END collision detection for a square
	angle2 += 10*size;
	// set current drawing color to red
	//quad();
	glPushMatrix();
	glColor3f(1.0f,0.0f,0.0f);
	glTranslatef(x,y,0);
	glPushMatrix();
	glRotatef(angle,0.0,0.0,1.0);
	quad();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f,1.0f,0.0f);
	glTranslatef(x2,y2,0);
	glPushMatrix();
	glRotatef(angle2,0.0,0.0,1.0);
	quad2();
	glPopMatrix();
	glPopMatrix();

	// flush drawing commands and swap
	glutSwapBuffers();
}

GLvoid TEMPORIZADOR()
{
	// Redraw the scene by calling the display function DESENHAR
	glutPostRedisplay();
	glutTimerFunc(33,TEMPORIZADOR, 1);
}

void ESCAPE(unsigned char key, int a, int b)
{
	if(key==27) exit(0);
}

int main (int argc, char** argv) 
{
	// initialization for GLUT/OpenGL
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// create window with resolution 500x500
	glutInitWindowSize( 500,500 );
	glutCreateWindow("Bounce");
	// register callbacks
	glutDisplayFunc(DESENHAR);
	glutKeyboardFunc(ESCAPE);
	glutTimerFunc(33,TEMPORIZADOR,1);
	// process events
	glutMainLoop();
	return 0;
}
