/*
메뉴 구현을 위한 콜백함수를 프로그래밍 한 코드이다.
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

	// 서브 메뉴부터 먼저 구현(나중에 메인 메뉴에 attach할 예정)
	GLint subMenuID = glutCreateMenu(subMenu);
	glutAddMenuEntry("Small one", 1);
	glutAddMenuEntry("Big one", 2);

	// 메인 메뉴 엔트리 구현
	GLint mainMenuID = glutCreateMenu(mainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw torus", 2);
	glutAddSubMenu("Change Size", subMenuID);
	glutAddMenuEntry("Exit", 3);
	// 마우스 오른버튼을 누르면 팝업식으로 뜨는 메뉴
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}