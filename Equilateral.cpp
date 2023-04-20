#include<GL/glut.h>
void displayMe(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(255,200,100);
glBegin(GL_POLYGON);
    glVertex2f(0.0,0.0);
    glVertex2f(1.0,0.0);
    glVertex2f(0.5,0.866);
glEnd();
glFlush();
}

int main(int argc, char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(400,300);
glutInitWindowPosition(100,100);
glutCreateWindow("Second Triangle");
glutDisplayFunc(displayMe);
glutMainLoop();
return 0;
}
