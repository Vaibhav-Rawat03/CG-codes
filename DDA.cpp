#include<GL/glut.h>
#include<iostream>
using namespace std;
#include<cmath>

void putpixel(int x, int y){
glBegin(GL_POINTS);
glColor3f(0,255,0);
glVertex2i(x,y);
glEnd();
glFlush();
}

void display(){
glClear(GL_COLOR_BUFFER_BIT);
int x1=1,x2=150,y1=5,y2=200;
int dx=x2-x1;
int dy=y2-y1;
int step;
if(abs(dx)>abs(dy)){
step=dx;
}
else{
step=dy;
}
float x=x1, y=y1;
float xinc=float(dx)/step,yinc=float(dy)/step;
for(int i=1; i<=step;i++){
   putpixel(round(x),round(y));
   x=x+xinc;
   y=y+yinc;
}
}

int main(int argc, char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(200,200);
glutInitWindowPosition(200,200);
glutCreateWindow("DDA");
glutDisplayFunc(display);
gluOrtho2D(0,200,0,200);
glutMainLoop();
return 0;
}
