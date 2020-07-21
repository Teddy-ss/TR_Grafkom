#include<windows.h>
#include <gl/glut.h>
#include <stdlib.h>

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
int is_depth;


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7, 0.2, 0.4, 0);
//meja kaki kiri belakang
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-15, 27, -18.0);
glVertex3f(-15, 20, -18.0);
glVertex3f(-16, 20, -18.0);
glVertex3f(-16, 27, -18.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-15, 27, -16.0);
glVertex3f(-15, 20, -16.0);
glVertex3f(-16, 20, -16.0);
glVertex3f(-16, 27, -16.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-15, 27, -18.0);
glVertex3f(-15, 20, -18.0);
glVertex3f(-15, 20, -16.0);
glVertex3f(-15, 27, -16.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-16, 27, -16.0);
glVertex3f(-16, 20, -16.0);
glVertex3f(-16, 20, -18.0);
glVertex3f(-16, 27, -18.0);
glEnd();
//meja kaki kanan belakang
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-6, 27, -18.0);
glVertex3f(-6, 20, -18.0);
glVertex3f(-7, 20, -18.0);
glVertex3f(-7, 27, -18.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-6, 27, -16.0);
glVertex3f(-6, 20, -16.0);
glVertex3f(-7, 20, -16.0);
glVertex3f(-7, 27, -16.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-6, 27, -18.0);
glVertex3f(-6, 20, -18.0);
glVertex3f(-6, 20, -16.0);
glVertex3f(-6, 27, -16.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-7, 27, -18.0);
glVertex3f(-7, 20, -18.0);
glVertex3f(-7, 20, -16.0);
glVertex3f(-7, 27, -16.0);
glEnd();
//meja kaki kiri depan
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-15, 27, -9.0);
glVertex3f(-15, 20, -9.0);
glVertex3f(-16, 20, -9.0);
glVertex3f(-16, 27, -9.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-15, 27, -11.0);
glVertex3f(-15, 20, -11.0);
glVertex3f(-16, 20, -11.0);
glVertex3f(-16, 27, -11.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-15, 27, -9.0);
glVertex3f(-15, 20, -9.0);
glVertex3f(-15, 20, -11.0);
glVertex3f(-15, 27, -11.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-16, 27, -11.0);
glVertex3f(-16, 20, -11.0);
glVertex3f(-16, 20, -9.0);
glVertex3f(-16, 27, -9.0);
glEnd();
//meja kaki kanan depan
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-6, 27, -9.0);
glVertex3f(-6, 20, -9.0);
glVertex3f(-7, 20, -9.0);
glVertex3f(-7, 27, -9.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-6, 27, -11.0);
glVertex3f(-6, 20, -11.0);
glVertex3f(-7, 20, -11.0);
glVertex3f(-7, 27, -11.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-6, 27, -9.0);
glVertex3f(-6, 20, -9.0);
glVertex3f(-6, 20, -11.0);
glVertex3f(-6, 27, -11.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-7, 27, -11.0);
glVertex3f(-7, 20, -11.0);
glVertex3f(-7, 20, -9.0);
glVertex3f(-7, 27, -9.0);
glEnd();
//papan meja atas
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-19, 31, -19.0);
glVertex3f(-19, 31, -8.0);
glVertex3f(-3, 31, -8.0);
glVertex3f(-3, 31, -19.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-19, 32, -19.0);
glVertex3f(-19, 31, -19.0);
glVertex3f(-19, 31, -8.0);
glVertex3f(-19, 32, -8.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-3, 32, -8.0);
glVertex3f(-3, 31, -8.0);
glVertex3f(-3, 31, -19.0);
glVertex3f(-3, 32, -19.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-19, 32, -19.0);
glVertex3f(-19, 32, -8.0);
glVertex3f(-3, 32, -8.0);
glVertex3f(-3, 32, -19.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-3, 32, -19.0);
glVertex3f(-3, 31, -19.0);
glVertex3f(-19, 31, -19.0);
glVertex3f(-19, 32, -19.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-19, 32, -8.0);
glVertex3f(-19, 31, -8.0);
glVertex3f(-3, 31, -8.0);
glVertex3f(-3, 32, -8.0);
glEnd();
//papan meja bawah
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-17, 27, -18.0);
glVertex3f(-17, 27, -9.0);
glVertex3f(-5, 27, -9.0);
glVertex3f(-5, 27, -18.0);
glEnd();
//papan meja kanan
glBegin(GL_QUADS);
glColor3f(1, 0, 1);
glVertex3f(-5, 31, -9.0);
glVertex3f(-5, 27, -9.0);
glVertex3f(-5, 27, -18.0);
glVertex3f(-5, 31, -18.0);
glEnd();
//papan meja kiri
glBegin(GL_QUADS);
glColor3f(1, 0, 1);
glVertex3f(-17, 31, -9.0);
glVertex3f(-17, 27, -9.0);
glVertex3f(-17, 27, -18.0);
glVertex3f(-17, 31, -18.0);
glEnd();
//papan meja belakang
glBegin(GL_QUADS);
glColor3f(1, 0, 1);
glVertex3f(-5, 31, -18.0);
glVertex3f(-5, 27, -18.0);
glVertex3f(-17, 27, -18.0);
glVertex3f(-17, 31, -18.0);
glEnd();
//laci
glBegin(GL_QUADS);
glColor3f(1, 0, 0);
glVertex3f(-16, 30.5, -18.0);
glVertex3f(-16, 30.5, -9.0);
glVertex3f(-6, 30.5, -9.0);
glVertex3f(-6, 30.5, -18.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 0);
glVertex3f(-16, 27.5, -18.0);
glVertex3f(-16, 27.5, -9.0);
glVertex3f(-6, 27.5, -9.0);
glVertex3f(-6, 27.5, -18.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 0);
glVertex3f(-6, 30.5, -9.0);
glVertex3f(-6, 27.5, -9.0);
glVertex3f(-6, 27.5, -18.0);
glVertex3f(-6, 30.5, -18.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 0);
glVertex3f(-16, 30.5, -9.0);
glVertex3f(-16, 27.5, -9.0);
glVertex3f(-16, 27.5, -18.0);
glVertex3f(-16, 30.5, -18.0);
glEnd();
//kaki kursi
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 25, -5.0);
glVertex3f(-9, 20, -5.0);
glVertex3f(-10, 20, -5.0);
glVertex3f(-10, 25, -5.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 25, -4.0);
glVertex3f(-9, 20, -4.0);
glVertex3f(-10, 20, -4.0);
glVertex3f(-10, 25, -4.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 25, -5.0);
glVertex3f(-9, 20, -5.0);
glVertex3f(-9, 20, -4.0);
glVertex3f(-9, 25, -4.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-10, 25, -4.0);
glVertex3f(-10, 20, -4.0);
glVertex3f(-10, 20, -5.0);
glVertex3f(-10, 25, -5.0);
glEnd();
//kiri
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 25, -5.0);
glVertex3f(-12, 20, -5.0);
glVertex3f(-13, 20, -5.0);
glVertex3f(-13, 25, -5.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 25, -4.0);
glVertex3f(-12, 20, -4.0);
glVertex3f(-13, 20, -4.0);
glVertex3f(-13, 25, -4.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 25, -5.0);
glVertex3f(-12, 20, -5.0);
glVertex3f(-12, 20, -4.0);
glVertex3f(-12, 25, -4.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-13, 25, -4.0);
glVertex3f(-13, 20, -4.0);
glVertex3f(-13, 20, -5.0);
glVertex3f(-13, 25, -5.0);
glEnd();
//kiri belakang
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 25, -2.0);
glVertex3f(-12, 20, -2.0);
glVertex3f(-13, 20, -2.0);
glVertex3f(-13, 25, -2.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 25, -1.0);
glVertex3f(-12, 20, -1.0);
glVertex3f(-13, 20, -1.0);
glVertex3f(-13, 25, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 25, -2.0);
glVertex3f(-12, 20, -2.0);
glVertex3f(-12, 20, -1.0);
glVertex3f(-12, 25, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-13, 25, -1.0);
glVertex3f(-13, 20, -1.0);
glVertex3f(-13, 20, -2.0);
glVertex3f(-13, 25, -2.0);
glEnd();
//kaki kursi belakang kanan
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 25, -2.0);
glVertex3f(-9, 20, -2.0);
glVertex3f(-10, 20, -2.0);
glVertex3f(-10, 25, -2.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 25, -1.0);
glVertex3f(-9, 20, -1.0);
glVertex3f(-10, 20, -1.0);
glVertex3f(-10, 25, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 25, -2.0);
glVertex3f(-9, 20, -2.0);
glVertex3f(-9, 20, -1.0);
glVertex3f(-9, 25, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-10, 25, -1.0);
glVertex3f(-10, 20, -1.0);
glVertex3f(-10, 20, -2.0);
glVertex3f(-10, 25, -2.0);
glEnd();
//dudukan kursi
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(-13, 25, -5.0);
glVertex3f(-13, 25, -1.0);
glVertex3f(-9, 25, -1.0);
glVertex3f(-9, 25, -5.0);
glEnd();
//atas
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(-13, 26, -5.0);
glVertex3f(-13, 26, -1.0);
glVertex3f(-9, 26, -1.0);
glVertex3f(-9, 26, -5.0);
glEnd();
//kiri
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(-9, 25, -1.0);
glVertex3f(-9, 26, -1.0);
glVertex3f(-9, 26, -5.0);
glVertex3f(-9, 25, -5.0);
glEnd();
//kanan
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(-13, 25, -5.0);
glVertex3f(-13, 26, -5.0);
glVertex3f(-13, 26, -1.0);
glVertex3f(-13, 25, -1.0);
glEnd();
//depan
glBegin(GL_QUADS);
glColor3f(0, 1, 0);
glVertex3f(-13, 25, -5.0);
glVertex3f(-13, 26, -5.0);
glVertex3f(-9, 26, -5.0);
glVertex3f(-9, 25, -5.0);
glEnd();
//belakang
glBegin(GL_QUADS);
glColor3f(0, 1, 0);
glVertex3f(-13, 25, -1.0);
glVertex3f(-13, 26, -1.0);
glVertex3f(-9, 26, -1.0);
glVertex3f(-9, 25, -1.0);
glEnd();
//sandaran kursi kiri
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 30, -2.0);
glVertex3f(-9, 26, -2.0);
glVertex3f(-10, 26, -2.0);
glVertex3f(-10, 30, -2.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 30, -1.0);
glVertex3f(-9, 26, -1.0);
glVertex3f(-10, 26, -1.0);
glVertex3f(-10, 30, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-9, 30, -2.0);
glVertex3f(-9, 26, -2.0);
glVertex3f(-9, 26, -1.0);
glVertex3f(-9, 30, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-10, 30, -1.0);
glVertex3f(-10, 26, -1.0);
glVertex3f(-10, 26, -2.0);
glVertex3f(-10, 30, -2.0);
glEnd();
//kanan
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 30, -2.0);
glVertex3f(-12, 26, -2.0);
glVertex3f(-13, 26, -2.0);
glVertex3f(-13, 30, -2.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 30, -1.0);
glVertex3f(-12, 26, -1.0);
glVertex3f(-13, 26, -1.0);
glVertex3f(-13, 30, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-12, 30, -2.0);
glVertex3f(-12, 26, -2.0);
glVertex3f(-12, 26, -1.0);
glVertex3f(-12, 30, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 0);
glVertex3f(-13, 30, -1.0);
glVertex3f(-13, 26, -1.0);
glVertex3f(-13, 26, -2.0);
glVertex3f(-13, 30, -2.0);
glEnd();
//papan kursi sandaran
glBegin(GL_QUADS);
glColor3f(0, 0, 1);
glVertex3f(-9, 32, -2.0);
glVertex3f(-9, 30, -2.0);
glVertex3f(-13, 30, -2.0);
glVertex3f(-13, 32, -2.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 1);
glVertex3f(-9, 32, -1.0);
glVertex3f(-9, 30, -1.0);
glVertex3f(-13, 30, -1.0);
glVertex3f(-13, 32, -1.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 1);
glVertex3f(-13, 32, -1.0);
glVertex3f(-13, 30, -1.0);
glVertex3f(-13, 30, -2.0);
glVertex3f(-13, 32, -2.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 1);
glVertex3f(-9, 32, -2.0);
glVertex3f(-9, 30, -2.0);
glVertex3f(-9, 30, -1.0);
glVertex3f(-9, 32, -1.0);
glEnd();
//bawah
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(-13, 30, -2.0);
glVertex3f(-13, 30, -1.0);
glVertex3f(-9, 30, -1.0);
glVertex3f(-9, 30, -2.0);
glEnd();
//atas
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(-13, 32, -2.0);
glVertex3f(-13, 32, -1.0);
glVertex3f(-9, 32, -1.0);
glVertex3f(-9, 32, -2.0);
glEnd();
//komputer
glBegin(GL_QUADS);
glColor3f(0.5, 1, 0.5);
glVertex3f(-15, 39, -16);
glVertex3f(-15, 35, -16);
glVertex3f(-8, 35, -16);
glVertex3f(-8, 39, -16);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.5, 0.5, 1);
glVertex3f(-16, 40, -16.05);
glVertex3f(-16, 34, -16.05);
glVertex3f(-7, 34, -16.05);
glVertex3f(-7, 40, -16.05);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.5, 0.5, 1);
glVertex3f(-16, 40, -17.0);
glVertex3f(-16, 34, -17.0);
glVertex3f(-7, 34, -17.0);
glVertex3f(-7, 40, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.5, 0.5, 1);
glVertex3f(-7, 40, -16.0);
glVertex3f(-7, 34, -16.0);
glVertex3f(-7, 34, -17.0);
glVertex3f(-7, 40, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0.5, 0.5, 1);
glVertex3f(-16, 40, -17.0);
glVertex3f(-16, 34, -17.0);
glVertex3f(-16, 34, -16.0);
glVertex3f(-16, 40, -16.0);
glEnd();
//dudukan komputer bawah
glBegin(GL_QUADS);
glColor3f(1, 0.5, 0);
glVertex3f(-14, 32.2, -17.0);
glVertex3f(-14, 32.2, -15.0);
glVertex3f(-9, 32.2, -15.0);
glVertex3f(-9, 32.2, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0.5, 0.5);
glVertex3f(-12, 34, -17.0);
glVertex3f(-12, 32.2, -17.0);
glVertex3f(-11, 32.2, -17.0);
glVertex3f(-11, 34, -17.0);
glEnd();
//kasur
//tiang kasur kiri
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -19.9, -15.0);
glVertex3f(57, -1.9, -15.0);
glVertex3f(60, -1.9, -15.0);
glVertex3f(60, -19.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -19.9, -17.0);
glVertex3f(57, -1.9, -17.0);
glVertex3f(60, -1.9, -17.0);
glVertex3f(60, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -19.9, -15.0);
glVertex3f(57, -1.9, -15.0);
glVertex3f(57, -1.9, -17.0);
glVertex3f(57, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(60, -19.9, -17.0);
glVertex3f(60, -1.9, -17.0);
glVertex3f(60, -1.9, -15.0);
glVertex3f(60, -19.9, -15.0);
glEnd();
//tiang kasur kanan
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(77, -19.9, -15.0);
glVertex3f(77, -1.9, -15.0);
glVertex3f(80, -1.9, -15.0);
glVertex3f(80, -19.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(77, -19.9, -17.0);
glVertex3f(77, -1.9, -17.0);
glVertex3f(80, -1.9, -17.0);
glVertex3f(80, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(77, -19.9, -15.0);
glVertex3f(77, -1.9, -15.0);
glVertex3f(77, -1.9, -17.0);
glVertex3f(77, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(80, -19.9, -17.0);
glVertex3f(80, -1.9, -17.0);
glVertex3f(80, -1.9, -15.0);
glVertex3f(80, -19.9, -15.0);
glEnd();
//tiang kasur kiri depan
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -19.9, 15.0);
glVertex3f(57, -8.9, 15.0);
glVertex3f(60, -8.9, 15.0);
glVertex3f(60, -19.9, 15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -19.9, 17.0);
glVertex3f(57, -8.9, 17.0);
glVertex3f(60, -8.9, 17.0);
glVertex3f(60, -19.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -19.9, 15.0);
glVertex3f(57, -8.9, 15.0);
glVertex3f(57, -8.9, 17.0);
glVertex3f(57, -19.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(60, -19.9, 17.0);
glVertex3f(60, -8.9, 17.0);
glVertex3f(60, -8.9, 15.0);
glVertex3f(60, -19.9, 15.0);
glEnd();
//tiang kasur kanan depan
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(77, -19.9, 15.0);
glVertex3f(77, -8.9, 15.0);
glVertex3f(80, -8.9, 15.0);
glVertex3f(80, -19.9, 15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(77, -19.9, 17.0);
glVertex3f(77, -8.9, 17.0);
glVertex3f(80, -8.9, 17.0);
glVertex3f(80, -19.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(77, -19.9, 15.0);
glVertex3f(77, -8.9, 15.0);
glVertex3f(77, -8.9, 17.0);
glVertex3f(77, -19.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(80, -19.9, 17.0);
glVertex3f(80, -8.9, 17.0);
glVertex3f(80, -8.9, 15.0);
glVertex3f(80, -19.9, 15.0);
glEnd();
//bagian kasur
glBegin(GL_QUADS);
glColor3f(1, 0, 1);
glVertex3f(80, -10.9, -15.0);
glVertex3f(80, -10.9, 15.0);
glVertex3f(80, -14.9, 15.0);
glVertex3f(80, -14.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 1);
glVertex3f(57, -10.9, -15.0);
glVertex3f(57, -10.9, 15.0);
glVertex3f(57, -14.9, 15.0);
glVertex3f(57, -14.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 1);
glVertex3f(58, -9.9, -15.0);
glVertex3f(58, -9.9, 15.0);
glVertex3f(58, -10.9, 15.0);
glVertex3f(58, -10.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 1);
glVertex3f(79, -9.9, -15.0);
glVertex3f(79, -9.9, 15.0);
glVertex3f(79, -10.9, 15.0);
glVertex3f(79, -10.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 1);
glVertex3f(60, -10.9, 15.0);
glVertex3f(60, -10.9, 15.0);
glVertex3f(80, -14.9, 15.0);
glVertex3f(80, -14.9, 15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 0);
glVertex3f(60, -9.9, 17.0);
glVertex3f(60, -14.9, 17.0);
glVertex3f(77, -14.9, 17.0);
glVertex3f(77, -9.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 0, 0);
glVertex3f(60, -19.9, -17);
glVertex3f(60, -5.9, -17);
glVertex3f(77, -5.9, -17);
glVertex3f(77, -19.9, -17);
glEnd();


//papan kasur
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -14.9, 17.0);
glVertex3f(57, -14.9, -17.0);
glVertex3f(80, -14.9, -17.0);
glVertex3f(80, -14.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(57, -10.9, 17.0);
glVertex3f(57, -10.9, -17.0);
glVertex3f(80, -10.9, -17.0);
glVertex3f(80, -10.9, 17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 1, 1);
glVertex3f(58, -9.9, 15.0);
glVertex3f(58, -9.9, -15.0);
glVertex3f(79, -9.9, -15.0);
glVertex3f(79, -9.9, 15.0);
glEnd();



//tiang kiri papan tulis
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-17, -19.9, -15.0);
glVertex3f(-17, 15.9, -15.0);
glVertex3f(-20, 15.9, -15.0);
glVertex3f(-20, -19.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-17, -19.9, -17.0);
glVertex3f(-17, 15.9, -17.0);
glVertex3f(-20, 15.9, -17.0);
glVertex3f(-20, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-17, -19.9, -15.0);
glVertex3f(-17, 15.9, -15.0);
glVertex3f(-17, 15.9, -17.0);
glVertex3f(-17, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-20, -19.9, -17.0);
glVertex3f(-20, 15.9, -17.0);
glVertex3f(-20, 15.9, -15.0);
glVertex3f(-20, -19.9, -15.0);
glEnd();
//tiang kanan papan tulis
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(17, -19.9, -15.0);
glVertex3f(17, 15.9, -15.0);
glVertex3f(20, 15.9, -15.0);
glVertex3f(20, -19.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(17, -19.9, -17.0);
glVertex3f(17, 15.9, -17.0);
glVertex3f(20, 15.9, -17.0);
glVertex3f(20, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(17, -19.9, -15.0);
glVertex3f(17, 15.9, -15.0);
glVertex3f(17, 15.9, -17.0);
glVertex3f(17, -19.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(20, -19.9, -17.0);
glVertex3f(20, 15.9, -17.0);
glVertex3f(20, 15.9, -15.0);
glVertex3f(20, -19.9, -15.0);
glEnd();
// papan tulis
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(17, -5.9, -15.0);
glVertex3f(17, 15.9, -15.0);
glVertex3f(-17, 15.9, -15.0);
glVertex3f(-17, -5.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(0, 0, 0);
glVertex3f(17, -5.9, -17.0);
glVertex3f(17, 15.9, -17.0);
glVertex3f(-17, 15.9, -17.0);
glVertex3f(-17, -5.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(17, -5.9, -15.0);
glVertex3f(17, 15.9, -15.0);
glVertex3f(17, 15.9, -17.0);
glVertex3f(17, -5.9, -17.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(-17, -5.9, -17.0);
glVertex3f(-17, 15.9, -17.0);
glVertex3f(-17, 15.9, -15.0);
glVertex3f(-17, -5.9, -15.0);
glEnd();
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
glVertex3f(15, -4.9, -14);
glVertex3f(15, 14.9, -14);
glVertex3f(-15, 14.9, -14);
glVertex3f(-15, -4.9, -14);
glEnd();




glPushMatrix();
glPopMatrix();

glutSwapBuffers();

}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);//kekiri
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);//kekanan
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, 5.0, 0.0);//kebawah
        break;
    case 'c':
    case 'C':
        glTranslatef(0.0, -5.0, 0.0);//keatas
        break;
    case 'W':
    case 'w':
        glTranslatef(0.0, 0.0, 5.0);//zoom in
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);//zoom out
        break;
    case 'e':
    case 'E':
        glRotatef(3.0, 1.0, 0.0, 0.0);//putar Y keatas
        break;
    case 'r':
    case 'R':
        glRotatef(-3.0, 1.0, 0.0, 0.0);//putar Y kebawah
        break;
    case 'q':
    case 'Q':
        glRotatef(3.0, 0.0, 1.0, 0.0);//putar X kekiri
        break;
    case '1':
        glRotatef(-3.0, 0.0, 1.0, 0.0);//putar X kekanan
        break;
    case '2':
        glRotatef(3.0, 0.0, 0.0, 1.0);//muter lingkaran dari kiri
        break;
    case '3':
        glRotatef(-3.0, 0.0, 0.0, 1.0);//muter lingkaran dari kanan
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
    glLoadIdentity();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -50.0, -400.0); // display ukuran Bangunan
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR_GRAFKOM");
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}