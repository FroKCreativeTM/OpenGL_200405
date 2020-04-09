#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <ctime>

unsigned char PALETTE[16][3] =
{
	{255 ,255,255}, // WHITE
	{0,255,255},	// CYAN
	{255,0,255},	// PURPLE
	{0,0,255},		// BLUE
	{192,192,192},	// LIGHT GRAY
	{128,128,128},	// DARK GRAY
	{0,128,128},	// DARK CYAN
	{128,0,128},	// DARK PURPLE
	{0,0,128},		// DARK BLUE
	{255,255,0},	// YELLOW
	{0,255,0},		// GREEN
	{128,128,0},	// DARK YELLOW
	{0,128,0},		// DARK GREEN
	{255,0,0},		// RED
	{128,0,0},		// DARK RED
	{0,0,0},		// BLACK
};

GLfloat g_Delta = 0.0;
GLint g_Index = 0;

GLfloat red = 0.0;
GLfloat green = 0.0;
GLfloat blue = 0.0;

void display()
{
	red = PALETTE[g_Index][0] / 255.f;
	green = PALETTE[g_Index][1] / 255.f;
	blue = PALETTE[g_Index][2] / 255.f;

	glColor3f(red, green, blue);

	glBegin(GL_LINES);
	glVertex3f(-1.0 + g_Delta, 1.0, 0.0);
	glVertex3f(1.0 - g_Delta, -1.0, 0.0);
	glVertex3f(-1.0, -1.0 + g_Delta, 0.0);
	glVertex3f(1.0, 1.0 - g_Delta, 0.0);
	glEnd();

	glutSwapBuffers();
}

void myTimer(int value)
{
	if (g_Delta < 2.f)
	{
		g_Delta += 0.01;
	}
	else
	{
		g_Delta = 0.0;
		if (++g_Index >= 15)
		{
			g_Index = 0;
		}
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glutPostRedisplay();
	glutTimerFunc(10, myTimer, 1);
}

int main(int argc, char** argv)
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