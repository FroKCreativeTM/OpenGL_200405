/*
�޴� ������ ���� �ݹ��Լ��� ���α׷��� �� �ڵ��̴�.
*/

#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLboolean g_IsSphere = true;
GLboolean g_IsSmall = true;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);
	if ((g_IsSphere) && (g_IsSmall))
	{
		glutWireSphere(0.2, 15, 15);
	}
	else if ((g_IsSphere) && (!g_IsSmall))
	{
		glutWireSphere(0.4, 15, 15);
	}
	else if ((!g_IsSphere) && (g_IsSmall))
	{
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else 
	{
		glutWireTorus(0.2, 0.5, 40, 20);
	}
	glFlush();
}

void mainMenu(int entryID)
{
	switch (entryID)
	{
	case 1 : 
		g_IsSphere = true;
		break;
	case 2 : 
		g_IsSphere = false;
		break;
	case 3 : 
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void subMenu(int entryID)
{
	switch (entryID)
	{
	case 1 : 
		g_IsSmall = true;
		break;
	case 2 : 
		g_IsSmall = false;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("menu callback");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// ���� �޴����� ���� ����(���߿� ���� �޴��� attach�� ����)
	GLint subMenuID = glutCreateMenu(subMenu);
	glutAddMenuEntry("Small one", 1);
	glutAddMenuEntry("Big one", 2);

	// ���� �޴� ��Ʈ�� ����
	GLint mainMenuID = glutCreateMenu(mainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw torus", 2);
	glutAddSubMenu("Change Size", subMenuID);
	glutAddMenuEntry("Exit", 3);
	// ���콺 ������ư�� ������ �˾������� �ߴ� �޴�
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}