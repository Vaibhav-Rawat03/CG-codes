#include<GL/glut.h>

void displayMe(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3ub(255,0,0);
glBegin(GL_POLYGON);
  glVertex2f(0.0,0.0);
  glVertex2f(0.0,1.0);
  glVertex2f(1.0,0.0);
glEnd();
glFlush();
}

int main(int argc, char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500,400);
glutInitWindowPosition(300,200);
glutCreateWindow("Right Triangle");
glutDisplayFunc(displayMe);
glutMainLoop();
return 0;
}
