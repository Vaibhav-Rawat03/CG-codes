#include<GL/glut.h>

void displayName(){
glColor3f(255.0,0.0,0.0);
glRasterPos2f(-0.5,0.0);
char name[]="Vaibhav Rawat";

for(int i=0;name[i]!='\0';i++){
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,name[i]);
}
}
void displayMe(void){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,255);
glBegin(GL_POLYGON);
  glVertex2f(1.0,0.0);
  glVertex2f(0.0,1.0);
  glVertex2f(-1.0,0.0);
glEnd();
displayName();
glFlush();
}

int main(int argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(300,400);
glutInitWindowPosition(100,100);
glutCreateWindow("First_Tringle");
glutDisplayFunc(displayMe);
glutMainLoop();
return 0;
}
