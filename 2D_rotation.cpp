#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
float pi=3.14;
void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,255,0);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
}
void draw_square(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);

    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);

    glEnd();
    glFlush();
}
void mat_mul(float a[3][3],float b[3][1],float r[3][1])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            r[i][j]=0;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<1;j++)
        {
            for(int k=0;k<3;k++)
            {
                r[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
}
void disp()
{
    float x1=100,y1=100,x2=-100,y2=-100;
    draw_square(x1,y1, x1,y2, x2,x2, x2,y1);
    float theta;
    cout<<"Enter angle of rotation -> ";
    cin>>theta;
    theta=theta*(pi/180);
    float mat[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mat[i][j]=0;
        }
    }
    mat[0][0]=cos(theta);
    mat[1][1]=cos(theta);
    mat[0][1]=sin(theta);
    mat[1][0]=(-1)*sin(theta);
    mat[2][2]=1;

    float coordinate[3][1];
    coordinate[0][0]=x1;
    coordinate[1][0]=y1;
    coordinate[2][0]=1;
    float multiply[3][1];
    mat_mul(mat,coordinate,multiply);
    float x1f=multiply[0][0];
    float y1f=multiply[1][0];

    //cout<<x1<<" "<<y1;
    coordinate[0][0]=x1;
    coordinate[1][0]=y2;
    mat_mul(mat,coordinate,multiply);
    float x2f=multiply[0][0];
    float y2f=multiply[1][0];

    coordinate[0][0]=x2;
    coordinate[1][0]=y2;
    mat_mul(mat,coordinate,multiply);
    float x3f=multiply[0][0];
    float y3f=multiply[1][0];

    coordinate[0][0]=x2;
    coordinate[1][0]=y1;
    mat_mul(mat,coordinate,multiply);
    float x4f=multiply[0][0];
    float y4f=multiply[1][0];
    


    draw_square(x1f,y1f,x2f,y2f,x3f,y3f,x4f,y4f);
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
}