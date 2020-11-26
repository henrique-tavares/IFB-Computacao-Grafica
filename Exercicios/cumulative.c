// Cumulative 2D transformations	
#include <GL/glut.h> 
#include <stdlib.h>	

void draw()	
{	
	// Make background colour yellow
	glClearColor( 80, 80, 80, 0 );
	glClear ( GL_COLOR_BUFFER_BIT );	
	// modelview matrix	
	glMatrixMode(GL_MODELVIEW);	
	// x-axis
	glLineWidth(2);
	glColor3f(0,0,0);	
	glBegin(GL_LINES);	
	glVertex2f(-0.5,0.0);	
	glVertex2f(0.5,0.0);	
	glEnd();	
	// y-axis	
	glColor3f(0,0,0);	
	glBegin(GL_LINES);	
	glVertex2f(0.0,-0.5);	
	glVertex2f(0.0,0.5);	
	glEnd();

	//RED rectangle
	glPushMatrix();
	glRotatef(45,0.0,0.0,1.0);
	glScalef(1.0,3.0,1.0);
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(0.05,-0.15,0.0);
	glRectf(0.1,0.2,0.4,0.3);
	glPopMatrix();
	//Translate GREEN / all next rectangle
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-0.05, 0.15, 0.0);
	glRectf(-0.1,-0.2,-0.4,-0.3);
	glPopMatrix();
	//Rotate + Translate BLUE rectangle
	glColor3f(0,0, 1);
	glPushMatrix();
	glTranslatef(-0.05,-0.15,0.0);
	//glRotatef(90, 0.0, 0.0, 1.0);
	glRectf(-0.1,0.2,-0.4,0.3);
	glPopMatrix();
	//Scale + Rotate + Translate MAGENTA rect
	glColor3f(1,0,1);
	glPushMatrix();
	//glScalef(-0.5, 1.0, 1.0);
	glTranslatef(0.05,0.15,0.0);
	glRectf(0.1,-0.2,0.4,-0.3);
	glPopMatrix();
	glPopMatrix();
	// display
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}
int main (int argc, char** argv) 
{
	// initialization for GLUT/OpenGL
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// create window with resolution 500x500
	glutInitWindowSize( 500,500 );
	glutCreateWindow("Retangulos ...");
	// register callbacks
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	// process events
	glutMainLoop();
	return 0;
}
	
