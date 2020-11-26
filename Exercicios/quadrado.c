// Um programa OpenGL simples que desenha um 
// quadrado em  uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo 
// disponível no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.

//#include <windows.h>
#include <GL/glut.h>

GLint tx, ty, angulo;
GLfloat ex, ey, vel;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B

     
  
     // Desenha um quadrado preenchido com a cor corrente


     glPushMatrix();

     glRotatef(angulo, 0, 0, 1);
     glTranslatef(tx, ty, 0);
     glScalef(ex, ey, 1);

     glLineWidth(3);
     glBegin(GL_LINE_LOOP);
               glColor3f(1.0f, 0.0f, 0.0f);
               glVertex2i(-50,-50);
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(50,-50);
               // Especifica que a cor corrente é azul
               glColor3f(0.0f, 1.0f, 0.0f);
               glVertex2i(50,50);
               glColor3f(1.0f, 1.0f, 0.0f);
               glVertex2i(-50,50);               
     glEnd();

     glBegin(GL_TRIANGLES);
     glColor3f(1.0,1.0,0.0);
     glVertex2i(-50,50);
     glColor3f(1.0,0.0,1.0);
     glVertex2i(0,100);
     glColor3f(0.0,1.0,0.0);
     glVertex2i(50,50);
     glEnd();
     glPopMatrix();

     glPushMatrix();

     glLineWidth(2);
     glBegin(GL_LINES);
     glColor3f(0.0,0.0,0.0);
     glVertex2i(-250,0);
     glVertex2i(250,0);
     glEnd();
     glBegin(GL_LINES);
     glVertex2i(0,250);
     glVertex2i(0,-250);
     glEnd();

     glPopMatrix();


     // Executa os comandos OpenGL
     glFlush();
}

void teclasespeciais(int key, int x, int y)
{
     switch (key)
     {
          case GLUT_KEY_PAGE_UP:
               angulo += 5;
               break;
          case GLUT_KEY_PAGE_DOWN:
               angulo -= 5;
               break;
          case GLUT_KEY_HOME:
               ex += 0.1;
               ey += 0.1;
               break;
          case GLUT_KEY_END:
               ex -= 0.1;
               ey -= 0.1;
               break;
          case GLUT_KEY_UP:
               ty += 1*vel;
               break;
          case GLUT_KEY_DOWN:
               ty -= 1*vel;
               break;
          case GLUT_KEY_RIGHT:
               tx += 1*vel;
               break;
          case GLUT_KEY_LEFT:
               tx -= 1*vel;
               break;
          case GLUT_KEY_F1:
               vel += 0.5;
               break;
          case GLUT_KEY_F2:
               if (vel >= 1)
               {
                    vel -= 0.5;
               }
               break;
     }
     glutPostRedisplay();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250.0f, 250.0f, -250.0, 250.0f);
    tx = 0;
    ty = 0;
    angulo = 0;
    ex = 1;
    ey = 1;
    vel = 1;
}
// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 450.0f, 0.0f, 450.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 450.0f*w/h, 0.0f, 450.0f);
}

// Programa Principal 
int main(int argc, char** argv){
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(60,20);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(Desenha);
     glutSpecialFunc(teclasespeciais);
     Inicializa();
     //glutReshapeFunc(AlteraTamanhoJanela);
     glutMainLoop();
}

