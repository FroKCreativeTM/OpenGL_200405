/*
glutMainLoop() ���α׷��� ���� �̺�Ʈ ������ �������� ���� �Լ��̴�.
*/

#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat g_Delta = 0.0f;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);		// ���� �÷� ���۸� ��� �����!
	glColor3f(0.5, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0 + g_Delta, -0.5, 0.0);
	glVertex3f(0.0 + g_Delta, -0.5, 0.0);
	glVertex3f(0.0 + g_Delta, 0.5, 0.0);
	glVertex3f(-1.0 + g_Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();		
	// glutSwapBuffers �Լ� �տ��ִ� ��� �Լ��� �� ���ۿ� ����ȴ�. �� ������ Delta���� ����Ͽ� ������ �׷��� 
	// �簢���� �� ���ۿ� ��ϵǸ�, �� ���� ���� ȭ�鿡 ���̴� ������ ���� ����Ʈ ���ۿ� �ִ� ���� �簢���̴�.
	// ���ο� �簢���� ����� �Ϸ�Ǵ� ���� glutSwapBuffers �Լ��� ���� ���� �������� ����ϰ� �ȴ�.
	// �� ��� �� ���۰� ����Ʈ ���۰� �����ν� ���� ���� ������ �簢���� �� �� �ְ� �Ǵ� ���̴�.
}

void myIdle()
{
	g_Delta = g_Delta + 0.001;
	glutPostRedisplay();			// g_Delta ���� ���������� �ִ��� ���� �ñ⿡ ���÷��� �ݹ��� �����϶�.
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // ���� ���۸�
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("idle callback");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(display);
	glutIdleFunc(myIdle);

	glutMainLoop();

	return 0;
}