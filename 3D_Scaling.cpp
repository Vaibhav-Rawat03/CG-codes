#include<GL/glut.h>
#include<iostream>
using namespace std;
int width=500,height=500;
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

void draw_cube(float x1,float y1,float z1,float x2,float y2,float z2)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);

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

    glEnd();
    glFlush();
}
void mat_mul(float a[4][4],float b[4][1],float r[4][1])
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
    float x1=100,y1=100,z1=100,x2=-100,y2=-100,z2=-100;
    x1/=1000;
    y1/=1000;
    z1/=1000;
    x2/=1000;
    y2/=1000;
    z2/=1000;
    draw_cube(x1,y1,z1,x2,y2,z2);
    int s1,s2,s3;
    cout<<"Enter scaling in X-axis -> ";
    cin>>s1;
    cout<<"Enter scaling in Y-axis -> ";
    cin>>s2;
    cout<<"Enter scaling in Z-axis -> ";
    cin>>s3;
    float mat[4][4];
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
    mat[2][2]=s3;
    float coordinate[4][1];
    coordinate[0][0]=x1;
    coordinate[1][0]=y1;
    coordinate[2][0]=z1;
    coordinate[3][0]=1;
    
    float multiply[4][1];
    mat_mul(mat,coordinate,multiply);
    x1=multiply[0][0];
    y1=multiply[1][0];
    z1=multiply[2][0];
    cout<<x1<<" "<<y1;
    coordinate[0][0]=x2;
    coordinate[1][0]=y2;
    coordinate[2][0]=z2;
    mat_mul(mat,coordinate,multiply);
    x2=multiply[0][0];
    y2=multiply[1][0];
    z2=multiply[2][0];
    draw_cube(x1,y1,z1,x2,y2,z2);
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