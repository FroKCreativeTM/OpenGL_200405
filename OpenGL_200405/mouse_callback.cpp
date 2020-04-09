#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 300, 300);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(TopLeftX / 300.f, (300 - TopLeftY) / 300.f, 0.0);
	glVertex3f(TopLeftX / 300.f, (300 - BottomRightY) / 300.f, 0.0);
	glVertex3f(BottomRightX/300.f, (300 - BottomRightY) / 300.f, 0.0);
	glVertex3f(BottomRightX/300.f, (300 - TopLeftY) / 300.f, 0.0);
	glEnd();
	glFlush();
}

void reshape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight);

	// 뷰 포트의 폭과 높이의 증가율을 계산
	//GLfloat widthFactor = (GLfloat)newWidth / 300.f;
	//GLfloat heightFactor = (GLfloat)newHeight / 300.f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 원래 투상 범위에 이 값을 곱하여 투상면의 크기를 조정
	// 마우스를 누르고 땐 부분은 뷰 포트 좌표로 입력되기 때문에
	// 이를 투상면 내부의 물체 좌표로 변환해줄 필요가 있다.
	// 이는 화면 좌표를 뷰 포트 크기에 의해 정규화 한 것이다.
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'Q':
	case 'q':
	case 27:
		exit(0);
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		TopLeftX = x;
		TopLeftY = y;
	}
}

void mouseMove(GLint x, GLint y)
{
	BottomRightX = x;
	BottomRightY = y;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("open sample drawing");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);

	glutMainLoop();

	return 0;
}