#include<GL/glut.h>
#include<iostream>

void putpixel(int x,int y){
  glBegin(GL_POINTS);
  glColor3ub(200,255,150);
  glVertex2i(x,y);
  glEnd();
  glFlush();
   }

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
 // glColor3ub(200,150,50);
  int x1=2,x2=150,y1=6,y2=120;
  int dx=x2-x1;
  int dy=y2-y1;
  int P=2*dy-dx;
  while(x1<=x2){
  putpixel(x1,y1);
  x1++;
  if(P<0){
   P=P+2*dy;
  }
  else{
  P=P+2*dy-2*dx;
  y1++;
  }
 }

}

int main(int argc,char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(400,500);
  glutInitWindowPosition(200,300);
  glutCreateWindow("Bresenham Line");
  glutDisplayFunc(display);
  gluOrtho2D(0,200,0,200);
  glutMainLoop();
  return 0;
}
