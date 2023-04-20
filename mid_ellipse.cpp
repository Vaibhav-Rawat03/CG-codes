#include<GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,0,255);
    int rx=300,ry=350;
    int y1=ry,x1=0;
    int p=(ry*ry)+((rx*rx)/4)-(ry*rx*rx);
    glBegin(GL_POINTS);
    int dy=2*y1*rx*rx,dx=2*x1*ry*ry;
    while(dx<dy)
    {
        dy=2*y1*rx*rx;
        dx=2*x1*ry*ry;
        glVertex2d(x1,y1);
        glVertex2d(-x1,y1);
        glVertex2d(-x1,-y1);
        glVertex2d(x1,-y1);
        x1++;
        if(p<0)
        {
            p=p+ry*ry*2*(x1)+(ry*ry);
        }
        else 
        {
            y1=y1-1;
            p=p+ry*ry*2*x1+ry*ry-rx*rx*2*y1;
        }
    }
    while(y1>=0)
    {
        glVertex2d(x1,y1);
        glVertex2d(-x1,y1);
        glVertex2d(-x1,-y1);
        glVertex2d(x1,-y1);
        y1--;
        if(p>=0)
        {
            p=p-rx*rx*2*(y1)+rx*rx;
        }
        else 
        {
            x1=x1+1;
            p=p-(rx*rx*2*y1)+(ry*ry*2*x1)+rx*rx;
        }
    }
    glEnd();
    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Mid Ellipse");
    glutDisplayFunc(display);
    gluOrtho2D(-500,500,-500,500);
    glutMainLoop();
    return 0;
}