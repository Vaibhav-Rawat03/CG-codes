#include<GL/glut.h>

int inside=0,left=1,right=2,bottom=4,top=8;
int xmax=150,ymax=150,xmin=10,ymin=10;
int regioncode(int x,int y){
    int code = inside;

    if (x < xmin) {
        code |= left;
    } else if (x > xmax) {
        code |= right;
    }

    if (y < ymin) {
        code |= bottom;
    } else if (y > ymax) {
        code |= top;
    }

    return code;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,0,255);
    double x0=20, y0=30, x1=140, y1=180;
    int outcode0 = regioncode(x0, y0);
    int outcode1 = regioncode(x1, y1);

    while (outcode0 | outcode1) {
        if (outcode0 & outcode1) {
            return;
        }

        double x, y;
        int outcodeOut;
        if (outcode0) {
           outcodeOut = outcode0;
        } 
        else {
           outcodeOut = outcode1;
        }

        if (outcodeOut & top) {
            x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
            y = ymax;
        } else if (outcodeOut & bottom) {
            x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
            y = ymin;
        } else if (outcodeOut & right) {
            y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
            x = xmax;
        } else if (outcodeOut & left) {
            y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
            x = xmin;
        }

        if (outcodeOut == outcode0) {
            x0 = x;
            y0 = y;
            outcode0 = regioncode(x0, y0);
        } else {
            x1 = x;
            y1 = y;
            outcode1 = regioncode(x1, y1);
        }
    }

    glBegin(GL_LINES);
    glVertex2d(x0, y0);
    glVertex2d(x1, y1);
    glEnd();
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,400);
    glutInitWindowPosition(400,200);
    glutCreateWindow("Line clip");
    glutDisplayFunc(display);
    gluOrtho2D(-200,200,-200,200);
    glutMainLoop();
    return 0;
}