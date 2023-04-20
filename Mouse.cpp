#include<GL/glut.h>

int c1=0,c2=255;
void triangle(){
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POLYGON);
     glColor3ub(c1,c2,0);
     glVertex2f(0.0,0.0);
     glVertex2f(0.0,0.5);
     glVertex2f(0.5,0.5);
     glEnd();
     glFlush();
}
void click(int button,int state,int x,int y){
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        c1=255;
        triangle();
       }
       else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP){
       c1=0;
       triangle();
      }
       else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
       c1=255;
       c2=150;
       triangle();
       }
        else if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP){ 
       c1=0;
       c2=255;
       triangle();
      }

}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  triangle();
  glFlush();
}

int main(int argc,char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(300,100);
  glutCreateWindow("Mouse Click");
  glutDisplayFunc(display);
  glutMouseFunc(click);
  display();
  glutMainLoop();
  return 0;
}
