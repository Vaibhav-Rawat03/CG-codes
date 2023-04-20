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
    gluOrtho2D(-500,500,-500,500);
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
void mat_mul(int a[3][3],int b[3][1],int r[3][1])
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
    int x1=100,y1=100,x2=-100,y2=-100;
    draw_square(x1,y1,x2,y2);
    int s1,s2;
    cout<<"Enter scaling in X-axis -> ";
    cin>>s1;
    cout<<"Enter scaling in Y-axis -> ";
    cin>>s2;
    int mat[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            {
                mat[i][j]=1;
            }
            else
            {
                mat[i][j]=0;
            }
        }
    }
    mat[0][0]=s1;
    mat[1][1]=s2;
    int coordinate[3][1];
    coordinate[0][0]=x1;
    coordinate[1][0]=y1;
    coordinate[2][0]=1;
    int multiply[3][1];
    mat_mul(mat,coordinate,multiply);
    x1=multiply[0][0];
    y1=multiply[1][0];
    cout<<x1<<" "<<y1;
    coordinate[0][0]=x2;
    coordinate[1][0]=y2;
    mat_mul(mat,coordinate,multiply);
    x2=multiply[0][0];
    y2=multiply[1][0];
    draw_square(x1,y1,x2,y2);
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