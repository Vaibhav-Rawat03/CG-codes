
 

#include<GL/glut.h>

typedef struct color{GLubyte red; GLubyte green; GLubyte blue;}color;

void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
}
void f_fill(int x,int y,color e,color n)
{
    color o;
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&o);
    if(o.red==e.red && o.green==e.green && o.blue==e.blue)
    {
        glBegin(GL_POINTS);
        glColor3ub(n.red,n.green,n.blue);
        glVertex2f(x,y);
        glEnd();
        glFlush();

        f_fill(x+1,y,e,n);
        f_fill(x-1,y,e,n);
        f_fill(x,y+1,e,n);
        f_fill(x,y-1,e,n);
    }
}

void disp()
{
    color e_color;
    e_color.red=0;
    e_color.green=255;
    e_color.blue=0;
    glBegin(GL_POLYGON);
    glColor3ub(e_color.red,e_color.green,e_color.blue);
    glVertex2f(100,100);
    glVertex2f(100,400);
    glVertex2f(400,400);
    glVertex2f(400,100);
    glEnd();
    color n_color;
    n_color.red=0;
    n_color.green=0;
    n_color.blue=255;

    f_fill(200,200,e_color,n_color);
    glFlush();
}
    

int main(int a,char ** b)
{
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500,500);
    glutCreateWindow("Flood Fill");
    glutDisplayFunc(disp);
    init();
    glutMainLoop();
    return 0;
}