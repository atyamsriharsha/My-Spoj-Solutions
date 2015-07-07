#include <iostream>
#include <cmath>
#include <GL/glut.h>
using namespace std ;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)

float box_len = 5.0f ;
float ball_rad1 = 0.1f ;
float ball_rad2 = 0.1f ;
float ball_rad3 = 0.1f ;
float ball_x1 = 1.0f ;
float ball_y1 = 0.0f ;
float ball_x2 = 0.0f ;
float ball_y2 = 0.0f ;
float ball_x3 = 0.06f ;
float ball_y3 = 0.06f ;
float tri_x=0.0f ;
float tri_y = 0.0f ;
float theta= 0.0f ;


void drawbox(float len)
{
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE) ;
	glBegin(GL_QUADS) ;
	glVertex2f(-len/2,len/2) ;
	glVertex2f(len/2,len/2);
	glVertex2f(len/2,-len/2);
	glVertex2f(-len/2,-len/2) ;
	glEnd() ;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL) ;
}

void drawball(float rad)
{
   glBegin(GL_TRIANGLE_FAN);
   for(int i=0 ; i<360 ; i++)
    {
       glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
    }
   glEnd();
}

void drawscene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity() ;
	glPushMatrix();
    glTranslatef(0.0f,0.0f,-0.5f) ;
    glColor3f(1.0f,0.0f,0.0f) ;
    drawbox(box_len) ;

    glPushMatrix();
    glTranslatef(ball_x2,ball_y2,-0.5f) ;
    glColor3f(1.0f,0.0f,0.0f) ;
    drawball(ball_rad2) ;
    glPopMatrix() ;

    glPushMatrix();
    glTranslatef(ball_x3,ball_y3,-0.5f) ;
    glColor3f(1.0f,0.0f,0.0f) ;
    drawball(ball_rad3) ;
    glPopMatrix() ;

    glPushMatrix();
    glTranslatef(ball_x1,ball_y1,-0.5f) ;
    glColor3f(1.0f,0.0f,0.0f) ;
    drawball(ball_rad1) ;
    glPopMatrix() ;

	glPopMatrix();
	glutSwapBuffers() ;
}


void update(int value)
{
	/*
	if(ball_x1 + ball_rad1 > box_len/2 || ball_x1 - ball_rad1 < -box_len/2)
        ball_x1 = ball_x1 - 0.1f ;
    if(ball_y1 + ball_rad1 > box_len/2 || ball_y1 - ball_rad1 < -box_len/2)
        ball_y1 = ball_y1 - 0.1f ;
     if(ball_x2 + ball_rad2 > box_len/2 || ball_x2 - ball_rad2 < -box_len/2)
      ball_x2 = ball_x2 - 0.1f ;
    if(ball_y2 + ball_rad2 > box_len/2 || ball_y2 - ball_rad2 < -box_len/2)
        ball_y1 = ball_y1 - 0.1f ;
     if(ball_x3 + ball_rad3 > box_len/2 || ball_x3 - ball_rad3 < -box_len/2)
        ball_x3 = ball_x3 - 0.1f ;
    if(ball_y3 + ball_rad3 > box_len/2 || ball_y3 - ball_rad3 < -box_len/2)
        ball_y3 = ball_y3 - 0.1f ;
    */
    
	if(ball_x1+ball_x2 == ball_rad2+ball_rad1 && ball_x1 >ball_x2)
	{
		ball_x1 = ball_x1+0.01f;
		ball_x2 = ball_x2-0.01f ;
	}
	else //if(ball_x1+ball_x2 == ball_rad2+ball_rad1 && ball_x1 <ball_x2)
	{
		ball_x2 = ball_x2+0.01f;
		ball_x1 = ball_x1 -0.01f ;
	}
	if(ball_x1+ball_x3 == ball_rad2+ball_rad3 && ball_x1 >ball_x3)
	{
		ball_x1 = ball_x1+0.01f ;
		ball_x3 = ball_x3-0.01f ;
	}
	else //if(ball_x1+ball_x3 == ball_rad2+ball_rad3 && ball_x1 <ball_x3)
	{
		ball_x3 = ball_x3+0.01f;
		ball_x1 = ball_x1 -0.01f ;
	}
	if(ball_x3+ball_x2 == ball_rad2+ball_rad3 && ball_x3 >ball_x2)
	{
		ball_x3 = ball_x3+0.01f ;
		ball_x2 = ball_x2-0.01f ;
	}
	else //if(ball_x3+ball_x2 == ball_rad2+ball_rad3 && ball_x3 <ball_x2)
	{
		ball_x2 = ball_x2+0.01f;
		ball_x3 = ball_x3 -0.01f ;
	}
	glutTimerFunc(10, update, 0);

}

void initRendering()
{
	glEnable(GL_DEPTH_TEST) ;
	glEnable(GL_COLOR_MATERIAL) ;
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void handpresskey1(unsigned char key,int x,int y)
{
	if(key==27)
		exit(0) ;
}

void handpresskey2(int key,int x,int y)
{
	if (key == GLUT_KEY_LEFT)
        ball_x3 -= 0.1;
    if (key == GLUT_KEY_RIGHT)
        ball_x3 += 0.1;
    if (key == GLUT_KEY_UP)
        ball_y3 += 0.1;
    if (key == GLUT_KEY_DOWN)
        ball_y3-= 0.1;
}

void handleMouseclick(int button, int state, int x, int y) {

    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            theta += 15;
        else if (button == GLUT_RIGHT_BUTTON)
            theta -= 15;
    }
}

void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc,char **argv)
{
   glutInit(&argc,argv) ;
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB) ;
   int w = glutGet(GLUT_SCREEN_WIDTH) ;
   int h = glutGet(GLUT_SCREEN_HEIGHT) ;
   int windowwidth =  w/3 ;
   int windowheight = h/3 ;
   glutInitWindowSize(windowwidth,windowheight) ;
   glutInitWindowPosition((w-windowwidth)/2,(h-windowheight)/2);
   glutCreateWindow("atyam gaadi game :p") ;
   initRendering() ;
   glutDisplayFunc(drawscene) ;
   glutIdleFunc(drawscene) ;
   glutKeyboardFunc(handpresskey1);
   glutSpecialFunc(handpresskey2) ;
   glutMouseFunc(handleMouseclick) ;
   glutReshapeFunc(handleResize) ;
   glutTimerFunc(10,update,0) ;
   glutMainLoop() ;
   return 0 ;
}