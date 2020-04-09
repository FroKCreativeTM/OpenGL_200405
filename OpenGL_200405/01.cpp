#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutCreateWindow("OpenGL Tutorial");
	glutInitDisplayMode(GLUT_RGB);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}