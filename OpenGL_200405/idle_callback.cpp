/*
glutMainLoop() 프로그램을 무한 이벤트 루프로 가져가기 위한 함수이다.
*/

#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLfloat g_Delta = 0.0f;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);		// 기존 컬러 버퍼를 모두 지우라!
	glColor3f(0.5, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0 + g_Delta, -0.5, 0.0);
	glVertex3f(0.0 + g_Delta, -0.5, 0.0);
	glVertex3f(0.0 + g_Delta, 0.5, 0.0);
	glVertex3f(-1.0 + g_Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();		
	// glutSwapBuffers 함수 앞에있는 모든 함수는 백 버퍼에 적용된다. 즉 증가된 Delta값을 사용하여 새로이 그려질 
	// 사각형은 백 버퍼에 기록되며, 그 동안 현재 화면에 보이는 내용은 현재 프런트 버퍼에 있는 이전 사각형이다.
	// 새로운 사각형의 기록이 완료되는 순간 glutSwapBuffers 함수에 의해 버퍼 스와핑을 명령하게 된다.
	// 그 결과 백 버퍼가 프론트 버퍼가 됨으로써 이제 새로 생성된 사각형을 볼 수 있게 되는 것이다.
}

void myIdle()
{
	g_Delta = g_Delta + 0.001;
	glutPostRedisplay();			// g_Delta 값이 증가했으니 최대한 빠른 시기에 디스플레이 콜백을 실행하라.
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // 더블 버퍼링
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