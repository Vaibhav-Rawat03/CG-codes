#include<GL/glut.h>
#include<iostream>
using namespace std;
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,255,0);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}
void draw_square(int x1,int y1,int x2,int y2)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);

    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x2,y2);
    glVertex2f(x2,y1);

    glEnd();
    glFlush();
}


void disp()
{
    int x1=50,y1=50,x2=200,y2=200;
    draw_square(x1,y1,x2,y2);
    int transx,transy;
    cout<<"Enter translate in X-axis -> ";
    cin>>transx;
    cout<<"Enter translate in Y-axis -> ";
    cin>>transy;
    draw_square(x1+transx,y1+transy,x2+transx,y2+transy);
}

int main(int a,char ** b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500,500);
    glutCreateWindow("2d tranform...");
    glutDisplayFunc(disp);
    init();
    glutMainLoop();
    return 0;
}