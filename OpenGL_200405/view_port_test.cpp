#include <Windows.h>
#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); 
	//glViewport(0, 0, 300, 300);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

void reshape(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight);

	// 뷰 포트의 폭과 높이의 증가율을 계산
	GLfloat widthFactor = (GLfloat)newWidth / 300.f;
	GLfloat heightFactor = (GLfloat)newHeight / 300.f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 원래 투상 범위에 이 값을 곱하여 투상면의 크기를 조정
	glOrtho(-1.0 * widthFactor, 1.0 * widthFactor, -1.0 * heightFactor, 1.0 * heightFactor, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'Q' : 
	case 'q' : 
	case 27 : 
		exit(0);
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
		exit(0);
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

	glutMainLoop();

	return 0;
}