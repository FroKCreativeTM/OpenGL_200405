#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat g_Delta = 0.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);		
	glColor3f(0.5, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0 + g_Delta, -0.5, 0.0);
	glVertex3f(0.0 + g_Delta, -0.5, 0.0);
	glVertex3f(0.0 + g_Delta, 0.5, 0.0);
	glVertex3f(-1.0 + g_Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void myTimer(int value)
{
	g_Delta += 0.001;
	glutPostRedisplay();
	glutTimerFunc(40, myTimer, 1);
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("timer callback");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(display);
	glutTimerFunc(40, myTimer, 1);	// 40ms 후에 myTimer 콜백함수가 실행, 마지막 1은 의미 없음.

	glutMainLoop();

	return 0;
}