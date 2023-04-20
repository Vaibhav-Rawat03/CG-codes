#include<GL/glut.h>
#include<iostream>
using namespace std;
int height=500,width=500;
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,255,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,float(width)/height,1.0f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,2,-2,
    0,0,0,
    0,1,0);
    //gluOrtho2D(0,500,0,500);
}

void boundary(float x1,float y1,float z1,float x2,float y2,float z2)
{
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    //e1
    glColor3ub(0,0,255);

    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y1,z1);
    //e2
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y2,z1);
    //e3
    glVertex3f(x2,y2,z1);
    glVertex3f(x1,y2,z1);
    //e4
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y1,z1);

    glColor3ub(255,0,0);
   //e5
    glVertex3f(x1,y1,z2);
    glVertex3f(x2,y1,z2);
    //e6
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    //e7
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    //e8
    glVertex3f(x1,y2,z2);
    glVertex3f(x1,y1,z2);

    glColor3ub(255,255,255);
    //e9
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y2,z2);
    //e10
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y2,z2);
    //e11
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    //e12
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y1,z2);
    
    
    glEnd();
}

void draw_square(float x1,float y1,float z1,float x2,float y2,float z2)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3ub(100,100,100);
    //front
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y2,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y1,z1);
    //back
    glVertex3f(x1,y1,z2);
    glVertex3f(x1,y2,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y1,z2);
    //left
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y2,z2);
    glVertex3f(x1,y1,z2);
    //right
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    //top 
    glVertex3f(x1,y2,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    //bottom
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    glVertex3f(x1,y1,z2);

    glEnd();
    boundary(x1,y1,z1,x2,y2,z2);
    glFlush();
}


void disp()
{
    float x1=-500,y1=-500,z1=-500,x2=500,y2=500,z2=500;
    x1/=1000;
    y1/=1000;
    z1/=1000;
    x2/=1000;
    y2/=1000;
    z2/=1000;
    
    draw_square(x1,y1,z1,x2,y2,z2);
    float transx,transy,transz;
    cout<<"Enter translate in X-axis -> ";
    cin>>transx;
    cout<<"Enter translate in Y-axis -> ";
    cin>>transy;
    cout<<"Enter translate in Z-axis -> ";
    cin>>transz;
    transx/=1000;
    transy/=1000;
    transz/=1000;
    draw_square(x1+transx,y1+transy,z1+transz,x2+transx,y2+transy,z2+transz);
}

int main(int a,char ** b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500,500);
    glutCreateWindow("3d tranform...");
    glutDisplayFunc(disp);
    init();
    glutMainLoop();
}