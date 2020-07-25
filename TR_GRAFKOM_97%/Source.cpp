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
    glPointSize(3.0);
    glLineWidth(3.0f);

}

void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    //depan
    glBegin(GL_QUADS);
    //glEnable(GL_LIGHTING);
    glColor3f(0.65, 0.50, 0.39);    // WARNA COKLAT
    glVertex3f(-10.0, -20.0, 50); // Z aku buat 50 buat tengah depan 
    glVertex3f(-10.0, 50.0, 50);
    glVertex3f(10.0, 50.0, 50);
    glVertex3f(10.0, -20.0, 50);
    glEnd();

    //GARIS TENGAH
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-10.0, 15.0, 50.5);
    glVertex3f(10.0, 15.0, 50.5);
    glEnd();

    // JENDELA LANTAI 2
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA jendela
    glVertex3f(-8.0, 25.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-8.0, 45.0, 50.5);
    glVertex3f(8.0, 45.0, 50.5);
    glVertex3f(8.0, 25.0, 50.5);
    glEnd();

    // JENDELA LANTAI 2 PUTIH
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);    // WARNA jendela
    glVertex3f(-8.0, 40.0, 50.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(-8.0, 45.0, 50.55);
    glVertex3f(8.0, 45.0, 50.55);
    glVertex3f(8.0, 40.0, 50.55);
    glEnd();

    // GARIS JENDELA LANTAI 2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-8.0, 25.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-8.0, 45.0, 50.5);
    glVertex3f(8.0, 45.0, 50.5);
    glVertex3f(8.0, 25.0, 50.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(0, 25.0, 50.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(0, 45.0, 50.6);

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-4, 25.0, 50.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-4, 45.0, 50.6);

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(4, 25.0, 50.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(4, 45.0, 50.6);

    glEnd();

    // JENDELA LANTAI 1
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA jendela
    glVertex3f(-8.0, -10.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-8.0, 10.0, 50.5);
    glVertex3f(8.0, 10.0, 50.5);
    glVertex3f(8.0, -10.0, 50.5);
    glEnd();

    // JENDELA LANTAI 1 PUTIH
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);    // WARNA jendela
    glVertex3f(-8.0, 10.0, 50.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(-8.0, 5.0, 50.55);
    glVertex3f(8.0, 5.0, 50.55);
    glVertex3f(8.0, 10.0, 50.55);
    glEnd();

    // GARIS JENDELA LANTAI 1
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-8.0, -10.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-8.0, 10.0, 50.5);
    glVertex3f(8.0, 10.0, 50.5);
    glVertex3f(8.0, -10.0, 50.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(0, 10.0, 50.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(0, -10.0, 50.6);

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-4, -10.0, 50.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-4, 10.0, 50.6);

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(4, -10.0, 50.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(4, 10.0, 50.6);

    glEnd();

    //samping serong kiri bagian depan
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.50, 0.39);
    glVertex3f(-15.0, -20.0, 40.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-15.0, 50.0, 40.0);
    glVertex3f(-10.0, 50.0, 50.0);
    glVertex3f(-10.0, -20.0, 50.0);
    glEnd();

    //GARIS TENGAH SERONG KIRI
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-15.0, 15.0, 40.5);
    glVertex3f(-10.0, 15.0, 50.5);
    glEnd();

    // JENDELA LANTAI 1 (SERONG KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA jendela
    glVertex3f(-14.0, -10.0, 40.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-14.0, 10.0, 40.5);
    glVertex3f(-11.0, 10.0, 50.5);
    glVertex3f(-11.0, -10.0, 50.5);
    glEnd();

    // JENDELA LANTAI 1 PUTIH (SERONG KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);    // WARNA jendela
    glVertex3f(-14.0, 10.0, 40.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(-14.0, 5.0, 40.55);
    glVertex3f(-11.0, 5.0, 50.55);
    glVertex3f(-11.0, 10.0, 50.55);
    glEnd();

    // GARIS JENDELA LANTAI 1( SERONG KIRI)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-14.0, -10.0, 40.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-14.0, 10.0, 40.5);
    glVertex3f(-11.0, 10.0, 50.5);
    glVertex3f(-11.0, -10.0, 50.5);
    glEnd();

    // JENDELA LANTAI 2 (SERONG KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA jendela
    glVertex3f(-14.0, 25.0, 40.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-14.0, 45.0, 40.5);
    glVertex3f(-11.0, 45.0, 50.5);
    glVertex3f(-11.0, 25.0, 50.5);
    glEnd();

    // JENDELA LANTAI 2 PUTIH   (SERONG KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);    // WARNA jendela
    glVertex3f(-14.0, 40.0, 40.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(-14.0, 45.0, 40.55);
    glVertex3f(-11.0, 45.0, 50.55);
    glVertex3f(-11.0, 40.0, 50.55);
    glEnd();

    // GARIS JENDELA LANTAI 2   (SERONG KIRI)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-14.0, 25.0, 40.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-14.0, 45.0, 40.5);
    glVertex3f(-11.0, 45.0, 50.5);
    glVertex3f(-11.0, 25.0, 50.5);
    glEnd();


    //samping serong kanan bagian depan
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.50, 0.39);
    glVertex3f(10.0, -20.0, 50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(10.0, 50.0, 50.0);
    glVertex3f(15.0, 50.0, 40.0);
    glVertex3f(15.0, -20.0, 40.0);
    glEnd();

    //GARIS TENGAH
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(10.0, 15.0, 50.5);
    glVertex3f(15.0, 15.0, 40.5);
    glEnd();

    // JENDELA LANTAI 1 (SERONG KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA jendela
    glVertex3f(11.0, -10.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(11.0, 10.0, 50.5);
    glVertex3f(14.0, 10.0, 40.5);
    glVertex3f(14.0, -10.0, 40.5);
    glEnd();

    // JENDELA LANTAI 1 PUTIH (SERONG KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);    // WARNA jendela
    glVertex3f(11.0, 10.0, 50.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(11.0, 5.0, 50.55);
    glVertex3f(14.0, 5.0, 40.55);
    glVertex3f(14.0, 10.0, 40.55);
    glEnd();

    // GARIS JENDELA LANTAI 1( SERONG KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(11.0, -10.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(11.0, 10.0, 50.5);
    glVertex3f(14.0, 10.0, 40.5);
    glVertex3f(14.0, -10.0, 40.5);
    glEnd();

    // JENDELA LANTAI 2 (SERONG KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA jendela
    glVertex3f(11.0, 25.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(11.0, 45.0, 50.5);
    glVertex3f(14.0, 45.0, 40.5);
    glVertex3f(14.0, 25.0, 40.5);
    glEnd();

    // JENDELA LANTAI 2 PUTIH   (SERONG KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);    // WARNA jendela
    glVertex3f(11.0, 40.0, 50.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(11.0, 45.0, 50.55);
    glVertex3f(14.0, 45.0, 40.55);
    glVertex3f(14.0, 40.0, 40.55);
    glEnd();

    // GARIS JENDELA LANTAI 2   (SERONG KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(11.0, 25.0, 50.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(11.0, 45.0, 50.5);
    glVertex3f(14.0, 45.0, 40.5);
    glVertex3f(14.0, 25.0, 40.5);
    glEnd();

    //Atas Depan
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.45, 0.39);    // WARNA COKLAT
    glVertex3f(-10.0, 50.0, 50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-10.0, 60.0, 40.0);
    glVertex3f(10.0, 60.0, 40.0);
    glVertex3f(10.0, 50.0, 50.0);
    glEnd();

    // samping serong kiri bagian depan atas
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.45, 0.39);
    glVertex3f(-15.0, 50.0, 40.0);
    glVertex3f(-10.0, 60.0, 40.0);      // TINGGI BANGUN 50
    glVertex3f(-10.0, 50.0, 50.0);
    glEnd();


    // samping serong kanan bagian depan atas
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.45, 0.39);
    glVertex3f(15.0, 50.0, 40.0);
    glVertex3f(10.0, 60.0, 40.0);      // TINGGI BANGUN 50
    glVertex3f(10.0, 50.0, 50.0);
    glEnd();




    // BAGIAN DEPAN SBLUM DI ATAS + BAGIAN ATAS SEGITIGA
    // Depan tengah
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.43, 0.39);    // WARNA COKLAT
    glVertex3f(-20.0, -20.0, 40.0);
    glVertex3f(-20.0, 50.0, 40.0);
    glVertex3f(20.0, 50.0, 40.0);
    glVertex3f(20.0, -20.0, 40.0);
    glEnd();

    //GARIS TENGAH
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-20.0, 15.0, 40.5);
    glVertex3f(20.0, 15.0, 40.5);
    glEnd();

    // Segitiga TENGAH DEPAN
    glBegin(GL_POLYGON);
    glColor3f(0.75, 0.43, 0.39);    // WARNA COKLAT
    glVertex3f(-20.0, 50.0, 40.0);
    glVertex3f(0.0, 85.0, 40.0);
    glVertex3f(20.0, 50.0, 40.0);
    glEnd();

    // GENTENG SEGITIGA TENGAH DEPAN
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-20.0, 50.0, 40.0);       // y di kanan berbeda 
    glVertex3f(-0.0, 85.0, 40.0);
    glVertex3f(-0.0, 85.0, 0.0);
    glVertex3f(-20.0, 50.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(20.0, 50.0, 40.0);       // y di kanan berbeda 
    glVertex3f(0.0, 85.0, 40.0);
    glVertex3f(0.0, 85.0, 0.0);
    glVertex3f(20.0, 50.0, 0.0);
    glEnd();

    // tutup belakang GENTENG SEGITIGA TENGAH DEPAN
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(20.0, 50.0, 0.0);
    glVertex3f(0.0, 85.0, 0.0);
    glVertex3f(-20.0, 50.0, 0.0);
    glEnd();
    //JENDELA SEGITIGA //
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);    // WARNA JENDELA
    glVertex3f(-6.0, 60.0, 40.5);
    glVertex3f(-6.0, 72.5, 40.5);
    glVertex3f(6.0, 72.5, 40.5);
    glVertex3f(6.0, 60.0, 40.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA GARIS 
    glVertex3f(-6.0, 60.0, 40.5);
    glVertex3f(-6.0, 72.5, 40.5);
    glVertex3f(6.0, 72.5, 40.5);
    glVertex3f(6.0, 60.0, 40.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA JENDELA
    glVertex3f(0, 60.0, 40.6);
    glVertex3f(0, 72.5, 40.6);
    glEnd();
    // Samping kiri tengah
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.43, 0.39);    // WARNA COKLAT
    glVertex3f(-20.0, -20.0, 20.0);
    glVertex3f(-20.0, 50.0, 20.0);
    glVertex3f(-20.0, 50.0, 40.0);
    glVertex3f(-20.0, -20.0, 40.0);
    glEnd();

    // Samping kanan  tengah
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.43, 0.39);    // WARNA COKLAT
    glVertex3f(20.0, -20.0, 20.0);
    glVertex3f(20.0, 50.0, 20.0);
    glVertex3f(20.0, 50.0, 40.0);
    glVertex3f(20.0, -20.0, 40.0);
    glEnd();

    //BAGIAN DEPAN SBLAH BELAKANG
    // Depan Sebelah belakang  X = 20
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.43, 0.39);    // WARNA COKLAT
    glVertex3f(-60.0, -20.0, 20.0);
    glVertex3f(-60.0, 50.0, 20.0);
    glVertex3f(60.0, 50.0, 20.0);
    glVertex3f(60.0, -20.0, 20.0);
    glEnd();

    // GARIS TENGAH BAGIAN SAMPING KIRI
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-20.5, 15.0, 20);
    glVertex3f(-20.5, 15.0, 40.5);
    glEnd();

    // GARIS TENGAH POJOK KIRI
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-60, 15.0, 20.5);
    glVertex3f(-130, 15.0, 20.5);
    glEnd();

    // GARIS TENGAH POJOK KANAN 
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(60, 15.0, 20.5);
    glVertex3f(130, 15.0, 20.5);
    glEnd();



    // GARIS TENGAH BAGIAN SAMPING KANAN
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(20.5, 15.0, 20);
    glVertex3f(20.5, 15.0, 40.5);
    glEnd();

    // GARIS TENGAH
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-60.0, 15.0, 20.5);
    glVertex3f(60.0, 15.0, 20.5);
    glEnd();

    // JENDELA LANTAI 1 Y -10 10
    // JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-28.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-28.0, 10.0, 20.5);
    glVertex3f(-22.0, 10.0, 20.5);
    glVertex3f(-22.0, -10.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-28.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-28.0, 10.0, 20.5);
    glVertex3f(-22.0, 10.0, 20.5);
    glVertex3f(-22.0, -10.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-25.0, -10.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-25.0, 10.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-28.0, -0.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-22.0, 0.0, 20.6);
    glEnd();

    // JENDELA LANTAI 2 Y 20 40

    // JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-28.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-28.0, 40.0, 20.5);
    glVertex3f(-22.0, 40.0, 20.5);
    glVertex3f(-22.0, 20.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-28.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-28.0, 40.0, 20.5);
    glVertex3f(-22.0, 40.0, 20.5);
    glVertex3f(-22.0, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-25.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-25.0, 40.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-28.0, 35.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-22.0, 35.0, 20.6);
    glEnd();


    //

    // JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (3)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-58.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-58.0, 10.0, 20.5);
    glVertex3f(-52.0, 10.0, 20.5);
    glVertex3f(-52.0, -10.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (3)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-58.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-58.0, 10.0, 20.5);
    glVertex3f(-52.0, 10.0, 20.5);
    glVertex3f(-52.0, -10.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH VERTIKAL) (3)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-55.0, -10.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-55.0, 10.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH HORIZONTAL) (3)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-58.0, -0.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-52.0, 0.0, 20.6);
    glEnd();
    //
    // JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (3)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-58.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-58.0, 40.0, 20.5);
    glVertex3f(-52.0, 40.0, 20.5);
    glVertex3f(-52.0, 20.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (3)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-58.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-58.0, 40.0, 20.5);
    glVertex3f(-52.0, 40.0, 20.5);
    glVertex3f(-52.0, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH VERTIKAL) (3)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-55.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-55.0, 40.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH HORIZONTAL)(3)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-58.0, 35.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-52.0, 35.0, 20.6);
    glEnd();

    //


    // JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (2)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(28.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(28.0, 10.0, 20.5);
    glVertex3f(22.0, 10.0, 20.5);
    glVertex3f(22.0, -10.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (2)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(28.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(28.0, 10.0, 20.5);
    glVertex3f(22.0, 10.0, 20.5);
    glVertex3f(22.0, -10.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (TENGAH VERTIKAL) (2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(25.0, -10.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(25.0, 10.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (TENGAH HORIZONTAL) (2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(28.0, -0.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(22.0, 0.0, 20.6);
    glEnd();
    //
    // JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (2)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(28.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(28.0, 40.0, 20.5);
    glVertex3f(22.0, 40.0, 20.5);
    glVertex3f(22.0, 20.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (2)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(28.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(28.0, 40.0, 20.5);
    glVertex3f(22.0, 40.0, 20.5);
    glVertex3f(22.0, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH VERTIKAL) (2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(25.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(25.0, 40.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH HORIZONTAL) (2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(28.0, 35.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(22.0, 35.0, 20.6);
    glEnd();

    //

    // JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (4)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(58.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(58.0, 10.0, 20.5);
    glVertex3f(52.0, 10.0, 20.5);
    glVertex3f(52.0, -10.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (4)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(58.0, -10.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(58.0, 10.0, 20.5);
    glVertex3f(52.0, 10.0, 20.5);
    glVertex3f(52.0, -10.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (TENGAH VERTIKAL) (4)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(55.0, -10.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(55.0, 10.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BAGIAN BELAKANG DARI TENGAH DEPAN KANAN (TENGAH HORIZONTAL) (4)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(58.0, -0.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(52.0, 0.0, 20.6);
    glEnd();

    //
    // JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (4)
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(58.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(58.0, 40.0, 20.5);
    glVertex3f(52.0, 40.0, 20.5);
    glVertex3f(52.0, 20.0, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (4)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(58.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(58.0, 40.0, 20.5);
    glVertex3f(52.0, 40.0, 20.5);
    glVertex3f(52.0, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH VERTIKAL) (4)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(55.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(55.0, 40.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BAGIAN BELAKANG DARI TENGAH DEPAN KIRI (TENGAH HORIZONTAL) (4)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(58.0, 35.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(52.0, 35.0, 20.6);
    glEnd();

    //

    // bangun sblah kiri dari bangun tengah persiS
    glBegin(GL_QUADS);
    glColor3f(0.66, 0.40, 0.43);
    glVertex3f(-50.0, -20.0, 30.0);
    glVertex3f(-50.0, 50.0, 30.0);
    glVertex3f(-30.0, 50.0, 30.0);
    glVertex3f(-30.0, -20.0, 30.0);
    glEnd();

    // GARIIS TENGAH SEBELAH KANAN DAN KIRI DARI BANGUN TENGAH Z = 30
    // GARIS KANAN
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-50.0, 15.0, 30.5);
    glVertex3f(-30.0, 15.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-50.1, 15.0, 20);
    glVertex3f(-50.1, 15.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-29.9, 15.0, 20);
    glVertex3f(-29.9, 15.0, 30);
    glEnd();

    // GARIS KIRI
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(50.0, 15.0, 30.5);
    glVertex3f(30.0, 15.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(50.1, 15.0, 20);
    glVertex3f(50.1, 15.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(29.9, 15.0, 20);
    glVertex3f(29.9, 15.0, 30);
    glEnd();

    // JENDELA BANGUN SEBELAH KIRI DARI BANGUN TENGAH PERSIS //
    // JENDELA LANTAI 2 bangun sblah kiri dari bangun tengah persiS (KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-47.0, 20.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-47.0, 35.0, 30.5);
    glVertex3f(-41.0, 35.0, 30.5);
    glVertex3f(-41.0, 20.0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-47.0, 35.0, 30.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(-47.0, 40.0, 30.55);
    glVertex3f(-41.0, 40.0, 30.55);
    glVertex3f(-41.0, 35.0, 30.55);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah kiri dari bangun tengah persiS (KIRI)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-47.0, 40.0, 30.6);
    glVertex3f(-41.0, 40.0, 30.6);
    glVertex3f(-41.0, 20.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah kiri dari bangun tengah persiS (TENGAH VERTIKAL) (KIRI) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 35.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-41.0, 35.0, 30.6);
    glEnd();

    // JENDELA LANTAI 2 bangun sblah kiri dari bangun tengah persiS (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-39.0, 20.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-39.0, 35.0, 30.5);
    glVertex3f(-33.0, 35.0, 30.5);
    glVertex3f(-33.0, 20.0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-39.0, 35.0, 30.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(-39.0, 40.0, 30.55);
    glVertex3f(-33.0, 40.0, 30.55);
    glVertex3f(-33.0, 35.0, 30.55);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah kiri dari bangun tengah persiS (KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-39.0, 40.0, 30.6);
    glVertex3f(-33.0, 40.0, 30.6);
    glVertex3f(-33.0, 20.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah kiri dari bangun tengah persiS (TENGAH VERTIKAL) (KANAN) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 35.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-33.0, 35.0, 30.6);
    glEnd();

    //
    // JENDELA LANTAI 1 bangun sblah kiri dari bangun tengah persiS (KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-47.0, -10.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-47.0, 10.0, 30.5);
    glVertex3f(-41.0, 10.0, 30.5);
    glVertex3f(-41.0, -10.0, 30.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 bangun sblah kiri dari bangun tengah persiS (KIRI)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 10.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-47.0, -10.0, 30.6);
    glVertex3f(-41.0, -10.0, 30.6);
    glVertex3f(-41.0, 10.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 bangun sblah kiri dari bangun tengah persiS (TENGAH VERTIKAL) (KIRI) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 0.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-41.0, 0.0, 30.6);
    glEnd();

    // JENDELA LANTAI 1 bangun sblah kiri dari bangun tengah persiS (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-39.0, -10.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-39.0, 10.0, 30.5);
    glVertex3f(-33.0, 10.0, 30.5);
    glVertex3f(-33.0, -10.0, 30.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 bangun sblah kiri dari bangun tengah persiS (KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 10.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-39.0, -10.0, 30.6);
    glVertex3f(-33.0, -10.0, 30.6);
    glVertex3f(-33.0, 10.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 bangun sblah kiri dari bangun tengah persiS (TENGAH VERTIKAL) (KANAN) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 0.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-33.0, 0.0, 30.6);
    glEnd();




    //

    //BAGIAN TUTUP ATAS sblah kiri dari bangun tengah persis
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(-50.0, 50.0, 30.0);       // y di kanan berbeda 
    glVertex3f(-50.0, 50.0, 20.0);
    glVertex3f(-30.0, 50.0, 20.0);
    glVertex3f(-30.0, 50.0, 30.0);
    glEnd();

    // Tambahan atas 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-30.0, 50.0, 20.0);
    glVertex3f(-30.0, 55.0, 20.0);
    glVertex3f(-50.0, 55.0, 20.0);
    glVertex3f(-50.0, 50.0, 20.0);
    glEnd();



    // SEGITIGA bangun sblah KIri dari bangun tengah persis
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-30.0, 55.0, 20.0);
    glVertex3f(-40.0, 70.0, 20.0);
    glVertex3f(-50.0, 55.0, 20.0);
    glEnd();

    // GENTENG bangun sblah KIri dari bangun tengah persis
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-30.0, 55.0, 20.0);       // y di kanan berbeda 
    glVertex3f(-40.0, 70.0, 20.0);
    glVertex3f(-40.0, 70.0, 0.0);
    glVertex3f(-30.0, 55.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-50.0, 55.0, 20.0);       // y di kanan berbeda 
    glVertex3f(-40.0, 70.0, 20.0);
    glVertex3f(-40.0, 70.0, 0.0);
    glVertex3f(-50.0, 55.0, 0.0);
    glEnd();

    // tutup belakang GENTENG bangun sblah KIri dari bangun tengah persis
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-30.0, 55.0, 0.0);
    glVertex3f(-40.0, 70.0, 0.0);
    glVertex3f(-50.0, 55.0, 0.0);
    glEnd();

    // samping kaNAN
    glBegin(GL_QUADS);
    glColor3f(0.66, 0.40, 0.43);
    glVertex3f(-50.0, -20.0, 20.0);
    glVertex3f(-50.0, 50.0, 20.0);
    glVertex3f(-50.0, 50.0, 30.0);
    glVertex3f(-50.0, -20.0, 30.0);
    glEnd();

    // samping kiRI
    glBegin(GL_QUADS);
    glColor3f(0.66, 0.40, 0.43);
    glVertex3f(-30.0, -20.0, 20.0);
    glVertex3f(-30.0, 50.0, 20.0);
    glVertex3f(-30.0, 50.0, 30.0);
    glVertex3f(-30.0, -20.0, 30.0);
    glEnd();

    // bangun sblah KAnan dari bangun tengah persis
    glBegin(GL_QUADS);
    glColor3f(0.66, 0.40, 0.43);
    glVertex3f(30.0, -20.0, 30.0);
    glVertex3f(30.0, 50.0, 30.0);
    glVertex3f(50.0, 50.0, 30.0);
    glVertex3f(50.0, -20.0, 30.0);
    glEnd();
    //
    // JENDELA BANGUN SEBELAH KANAN DARI BANGUN TENGAH PERSIS //
    // JENDELA LANTAI 2 bangun sblah KANAN dari bangun tengah persiS (KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(47.0, 20.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(47.0, 35.0, 30.5);
    glVertex3f(41.0, 35.0, 30.5);
    glVertex3f(41.0, 20.0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(47.0, 35.0, 30.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(47.0, 40.0, 30.55);
    glVertex3f(41.0, 40.0, 30.55);
    glVertex3f(41.0, 35.0, 30.55);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah KANAN dari bangun tengah persiS (KIRI)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(47.0, 40.0, 30.6);
    glVertex3f(41.0, 40.0, 30.6);
    glVertex3f(41.0, 20.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah KANAN dari bangun tengah persiS (TENGAH VERTIKAL) (KIRI) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 35.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(41.0, 35.0, 30.6);
    glEnd();

    // JENDELA LANTAI 2 bangun sblah KANAN dari bangun tengah persiS (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(39.0, 20.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(39.0, 35.0, 30.5);
    glVertex3f(33.0, 35.0, 30.5);
    glVertex3f(33.0, 20.0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(39.0, 35.0, 30.55); // Z aku buat 50 buat tengah depan 
    glVertex3f(39.0, 40.0, 30.55);
    glVertex3f(33.0, 40.0, 30.55);
    glVertex3f(33.0, 35.0, 30.55);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah KANAN dari bangun tengah persiS (KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(39.0, 40.0, 30.6);
    glVertex3f(33.0, 40.0, 30.6);
    glVertex3f(33.0, 20.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 bangun sblah KANAN dari bangun tengah persiS (TENGAH VERTIKAL) (KANAN) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 35.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(33.0, 35.0, 30.6);
    glEnd();
    //
    // JENDELA LANTAI 1 bangun sblah KANAN dari bangun tengah persiS (KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(47.0, -10.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(47.0, 10.0, 30.5);
    glVertex3f(41.0, 10.0, 30.5);
    glVertex3f(41.0, -10.0, 30.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 bangun sblah KANAN dari bangun tengah persiS (KIRI)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 10.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(47.0, -10.0, 30.6);
    glVertex3f(41.0, -10.0, 30.6);
    glVertex3f(41.0, 10.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 bangun sblah KANAN dari bangun tengah persiS (TENGAH VERTIKAL) (KIRI) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 0.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(41.0, 0.0, 30.6);
    glEnd();

    // JENDELA LANTAI 1 bangun sblah KANAN dari bangun tengah persiS (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(39.0, -10.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(39.0, 10.0, 30.5);
    glVertex3f(33.0, 10.0, 30.5);
    glVertex3f(33.0, -10.0, 30.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 bangun sblah KANAN dari bangun tengah persiS (KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 10.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(39.0, -10.0, 30.6);
    glVertex3f(33.0, -10.0, 30.6);
    glVertex3f(33.0, 10.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 bangun sblah KANAN dari bangun tengah persiS (TENGAH VERTIKAL) (KANAN) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 0.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(33.0, 0.0, 30.6);
    glEnd();



    //

    //BAGIAN TUTUP ATAS sblah kiri dari bangun tengah persis
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(50.0, 50.0, 30.0);       // y di kanan berbeda 
    glVertex3f(50.0, 50.0, 20.0);
    glVertex3f(30.0, 50.0, 20.0);
    glVertex3f(30.0, 50.0, 30.0);
    glEnd();


    // Tambahan atas 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(30.0, 50.0, 20.0);
    glVertex3f(30.0, 55.0, 20.0);
    glVertex3f(50.0, 55.0, 20.0);
    glVertex3f(50.0, 50.0, 20.0);
    glEnd();

    // SEGITIGA bangun sblah KAnan dari bangun tengah persis
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(30.0, 55.0, 20.0);
    glVertex3f(40.0, 70.0, 20.0);
    glVertex3f(50.0, 55.0, 20.0);
    glEnd();

    // JENDELA SEGITIGA KANAN DARI BANGUN TENGAH PERSIS //
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);
    glVertex3f(35.0, 52.0, 20.5);
    glVertex3f(35.0, 62.0, 20.5);
    glVertex3f(45.0, 62.0, 20.5);
    glVertex3f(45.0, 52.0, 20.5);
    glEnd();

    // GARIS JENDELA SEGITIGA KANAN DARI BANGUN TENGAH PERSIS
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(35.0, 52.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(35.0, 62.0, 20.6);
    glVertex3f(45.0, 62.0, 20.6);
    glVertex3f(45.0, 52.0, 20.6);
    glEnd();

    // GARIS JENDELA SEGITIGA KANAN DARI BANGUN TENGAH PERSIS (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(40.0, 52.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(40.0, 62.0, 20.6);
    glEnd();

    //
    // JENDELA SEGITIGA KIRI DARI BANGUN TENGAH PERSIS //
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);
    glVertex3f(-35.0, 52.0, 20.5);
    glVertex3f(-35.0, 62.0, 20.5);
    glVertex3f(-45.0, 62.0, 20.5);
    glVertex3f(-45.0, 52.0, 20.5);
    glEnd();

    // GARIS JENDELA SEGITIGA KIRI DARI BANGUN TENGAH PERSIS
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-35.0, 52.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-35.0, 62.0, 20.6);
    glVertex3f(-45.0, 62.0, 20.6);
    glVertex3f(-45.0, 52.0, 20.6);
    glEnd();

    // GARIS JENDELA SEGITIGA KIRI DARI BANGUN TENGAH PERSIS (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-40.0, 52.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-40.0, 62.0, 20.6);
    glEnd();

    // GENTENG bangun sblah KAnan dari bangun tengah persis
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(30.0, 55.0, 20.0);       // y di kanan berbeda 
    glVertex3f(40.0, 70.0, 20.0);
    glVertex3f(40.0, 70.0, 0.0);
    glVertex3f(30.0, 55.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(50.0, 55.0, 20.0);       // y di kanan berbeda 
    glVertex3f(40.0, 70.0, 20.0);
    glVertex3f(40.0, 70.0, 0.0);
    glVertex3f(50.0, 55.0, 0.0);
    glEnd();

    // tutup belakang GENTENG bangun sblah KAnan dari bangun tengah persis
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(30.0, 55.0, 0.0);
    glVertex3f(40.0, 70.0, 0.0);
    glVertex3f(50.0, 55.0, 0.0);
    glEnd();

    // samping KAnan
    glBegin(GL_QUADS);
    glColor3f(0.66, 0.40, 0.43);
    glVertex3f(50.0, -20.0, 20.0);
    glVertex3f(50.0, 50.0, 20.0);
    glVertex3f(50.0, 50.0, 30.0);
    glVertex3f(50.0, -20.0, 30.0);
    glEnd();

    // samping KIri
    glBegin(GL_QUADS);
    glColor3f(0.66, 0.40, 0.43);
    glVertex3f(30.0, -20.0, 20.0);
    glVertex3f(30.0, 50.0, 20.0);
    glVertex3f(30.0, 50.0, 30.0);
    glVertex3f(30.0, -20.0, 30.0);
    glEnd();




    //BANGUN TIGA LANTAI KANAN DAN KIRI

    // BANGUN TIGA LANTAI KIRI 1

    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-90.0, -20.0, 30.0);
    glVertex3f(-90.0, 85.0, 30.0);      // TINGGI BANGUN 70
    glVertex3f(-60.0, 85.0, 30.0);
    glVertex3f(-60.0, -20.0, 30.0);
    glEnd();

    // JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI
    // JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-84.0, 12.5, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 0, 30.5);
    glVertex3f(-66.0, 0, 30.5);
    glVertex3f(-66.0, 12.5, 30.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 12.5, 30.6);
    glVertex3f(-66.0, 12.5, 30.6);
    glVertex3f(-66.0, 0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-78.0, 0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-78.0, 12.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-72.0, 0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-72.0, 12.5, 30.6);
    glEnd();
    //
    // JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI
    // JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-84.0, 57.5, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 65, 30.5);
    glVertex3f(-66.0, 65, 30.5);
    glVertex3f(-66.0, 57.5, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-84.0, 65, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 67.5, 30.5);
    glVertex3f(-66.0, 67.5, 30.5);
    glVertex3f(-66.0, 65, 30.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 57.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 67.5, 30.6);
    glVertex3f(-66.0, 67.5, 30.6);
    glVertex3f(-66.0, 57.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-78.0, 57.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-78.0, 67.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-72.0, 57.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-72.0, 67.5, 30.6);
    glEnd();
    //
    // JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI
    // JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-84.0, 20.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 45.0, 30.5);
    glVertex3f(-66.0, 45.0, 30.5);
    glVertex3f(-66.0, 20.0, 30.5);
    glEnd();

    // GARIS JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 45.0, 30.6);
    glVertex3f(-66.0, 45.0, 30.6);
    glVertex3f(-66.0, 20.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI (VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 32.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-66.0, 32.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-78.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-78.0, 45.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 3 BANGUN 3 LANTAI KIRI (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-72.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-72.0, 45.0, 30.6);
    glEnd();
    //

    //GARIS TENGAH BANGUN TIGA LANTAI KIRI 1
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-90.0, 15.0, 30.5);
    glVertex3f(-60.0, 15.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-59.9, 15.0, 20);
    glVertex3f(-59.9, 15.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-90.1, 15.0, 20);
    glVertex3f(-90.1, 15.0, 30);
    glEnd();


    //GARIS LANTAI 3 BANGUN TIGA LANTAI KIRI 1
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-90.0, 50.0, 30.5);
    glVertex3f(-60.0, 50.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-59.9, 50.0, 20);
    glVertex3f(-59.9, 50.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(-90.1, 50.0, 20);
    glVertex3f(-90.1, 50.0, 30);
    glEnd();

    // GARIS ATAS BANGUN TIGA LANTAI KIRI 1

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-90.0, 75.0, 30.5);
    glVertex3f(-60.0, 75.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-59.9, 75.0, 10);
    glVertex3f(-59.9, 75.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-90.1, 75.0, 10);
    glVertex3f(-90.1, 75.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-90.0, 75.0, 9.5);
    glVertex3f(-60.0, 75.0, 9.5);
    glEnd();

    // samping KAnan  1
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-90.0, -20.0, 20.0);
    glVertex3f(-90.0, 85.0, 20.0);
    glVertex3f(-90.0, 85.0, 30.0);
    glVertex3f(-90.0, -20.0, 30.0);
    glEnd();
    // tambahan sampink KAnan 1
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-90.0, 50.0, 20.0);
    glVertex3f(-90.0, 85.0, 20.0);
    glVertex3f(-90.0, 85.0, 10.0);
    glVertex3f(-90.0, 50.0, 10.0);
    glEnd();
    // samping KIri 1
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-60.0, -20.0, 20.0);
    glVertex3f(-60.0, 85.0, 20.0);
    glVertex3f(-60.0, 85.0, 30.0);
    glVertex3f(-60.0, -20.0, 30.0);
    glEnd();

    // tambahan samping KIri 1
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-60.0, 50.0, 20.0);
    glVertex3f(-60.0, 85.0, 20.0);
    glVertex3f(-60.0, 85.0, 10.0);
    glVertex3f(-60.0, 50.0, 10.0);
    glEnd();

    // tutup atas lantai 3 Kanan  1'
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-60.0, 85.0, 30.0);
    glVertex3f(-90.0, 85.0, 30.0);
    glVertex3f(-90.0, 85.0, 10.0);
    glVertex3f(-60.0, 85.0, 10.0);
    glEnd();

    // Bagian belakang bangun 3 lantai Kiri
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-90.0, 50.0, 10.0);
    glVertex3f(-90.0, 85.0, 10.0);      // TINGGI BANGUN 70
    glVertex3f(-60.0, 85.0, 10.0);
    glVertex3f(-60.0, 50.0, 10.0);
    glEnd();

    // BANGUN TIGA LANTAI KANAN 2

    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(90.0, -20.0, 30.0);
    glVertex3f(90.0, 85.0, 30.0);      // TINGGI BANGUN 70
    glVertex3f(60.0, 85.0, 30.0);
    glVertex3f(60.0, -20.0, 30.0);
    glEnd();

    // JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN
    // JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(84.0, 12.5, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 0, 30.5);
    glVertex3f(66.0, 0, 30.5);
    glVertex3f(66.0, 12.5, 30.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 12.5, 30.6);
    glVertex3f(66.0, 12.5, 30.6);
    glVertex3f(66.0, 0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(78.0, 0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(78.0, 12.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(72.0, 0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(72.0, 12.5, 30.6);
    glEnd();
    //

    // JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN
    // JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(84.0, 20.0, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 45.0, 30.5);
    glVertex3f(66.0, 45.0, 30.5);
    glVertex3f(66.0, 20.0, 30.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 45.0, 30.6);
    glVertex3f(66.0, 45.0, 30.6);
    glVertex3f(66.0, 20.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN (VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 32.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(66.0, 32.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(78.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(78.0, 45.0, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(72.0, 20.0, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(72.0, 45.0, 30.6);
    glEnd();

    // JENDELA LANTAI 3 BANGUN 3 LANTAI KANAN
    // JENDELA LANTAI 3 BANGUN 3 LANTAI KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(84.0, 57.5, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 65, 30.5);
    glVertex3f(66.0, 65, 30.5);
    glVertex3f(66.0, 57.5, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(84.0, 65, 30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 67.5, 30.5);
    glVertex3f(66.0, 67.5, 30.5);
    glVertex3f(66.0, 65, 30.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 57.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 67.5, 30.6);
    glVertex3f(66.0, 67.5, 30.6);
    glVertex3f(66.0, 57.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 3 BANGUN 3 LANTAI KANAN (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(78.0, 57.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(78.0, 67.5, 30.6);
    glEnd();

    // GARIS JENDELA LANTAI 3 BANGUN 3 LANTAI KANAN (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(72.0, 57.5, 30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(72.0, 67.5, 30.6);
    glEnd();
    //
    //GARIS TENGAH
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(90.0, 15.0, 30.5);
    glVertex3f(60.0, 15.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(59.9, 15.0, 20);
    glVertex3f(59.9, 15.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(90.1, 15.0, 20);
    glVertex3f(90.1, 15.0, 30);
    glEnd();

    //GARIS LANTAI 3 BANGUN TIGA LANTAI KANAN 1
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(90.0, 50.0, 30.5);
    glVertex3f(60.0, 50.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(59.9, 50.0, 20);
    glVertex3f(59.9, 50.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA COKLAT
    glVertex3f(90.1, 50.0, 20);
    glVertex3f(90.1, 50.0, 30);
    glEnd();

    // GARIS ATAS BANGUN TIGA LANTAI KANAN 1

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(90.0, 75.0, 30.5);
    glVertex3f(60.0, 75.0, 30.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(59.9, 75.0, 10);
    glVertex3f(59.9, 75.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(90.1, 75.0, 10);
    glVertex3f(90.1, 75.0, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(90.0, 75.0, 9.5);
    glVertex3f(60.0, 75.0, 9.5);
    glEnd();


    // samping KAnan  2
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(90.0, -20.0, 20.0);
    glVertex3f(90.0, 85.0, 20.0);
    glVertex3f(90.0, 85.0, 30.0);
    glVertex3f(90.0, -20.0, 30.0);
    glEnd();
    // tambahan sampink KAnan 2
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(90.0, 50.0, 20.0);
    glVertex3f(90.0, 85.0, 20.0);
    glVertex3f(90.0, 85.0, 10.0);
    glVertex3f(90.0, 50.0, 10.0);
    glEnd();

    // samping KIri 2
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(60.0, -20.0, 20.0);
    glVertex3f(60.0, 85.0, 20.0);
    glVertex3f(60.0, 85.0, 30.0);
    glVertex3f(60.0, -20.0, 30.0);
    glEnd();

    // tambahan samping KIri 2
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(60.0, 50.0, 20.0);
    glVertex3f(60.0, 85.0, 20.0);
    glVertex3f(60.0, 85.0, 10.0);
    glVertex3f(60.0, 50.0, 10.0);
    glEnd();


    // tutup atas lantai 3 Kanan  2'
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(60.0, 85.0, 30.0);
    glVertex3f(90.0, 85.0, 30.0);
    glVertex3f(90.0, 85.0, 10.0);
    glVertex3f(60.0, 85.0, 10.0);
    glEnd();

    // Bagian belakang bangun 3 lantai Kiri
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(90.0, 50.0, 10.0);
    glVertex3f(90.0, 85.0, 10.0);      // TINGGI BANGUN 70
    glVertex3f(60.0, 85.0, 10.0);
    glVertex3f(60.0, 50.0, 10.0);
    glEnd();

    // GENTENG LUAR Bangun sblah kiri dari tengah  (1)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-90.0, 50.0, 20.0);
    glVertex3f(-90.0, 65.0, 0.0);      // TINGGI BANGUN 50
    glVertex3f(90.0, 65.0, 0.0);
    glVertex3f(90.0, 50.0, 20.0);
    glEnd();

    // GENTENG DALAM Bangun sblah kiri dari tengah (1)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-90.0, 50.0, -20.0);
    glVertex3f(-90.0, 65.0, 0.0);      // TINGGI BANGUN 50
    glVertex3f(90.0, 65.0, 0.0);
    glVertex3f(90.0, 50.0, -20.0);
    glEnd();

    // BANGUN SEBELAH  BANGUN 3 LANTAI

    // Bangun sblah Kiri bangun 3 lantai (1)
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(-130.0, -20.0, 20.0);
    glVertex3f(-130.0, 50.0, 20.0);      // TINGGI BANGUN 50
    glVertex3f(-90.0, 50.0, 20.0);
    glVertex3f(-90.0, -20.0, 20.0);
    glEnd();

    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI
    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KIRI KE KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-92.5, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-92.5, 45.0, 20.5);
    glVertex3f(-97.5, 45.0, 20.5);
    glVertex3f(-97.5, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-92.5, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-92.5, 45.0, 20.6);
    glVertex3f(-97.5, 45.0, 20.6);
    glVertex3f(-97.5, 20.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-92.5, 32.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-97.5, 32.5, 20.6);
    glEnd();
    //---

    // BAGIAN TENGAH JENDELA LANTAI 2 BANGUN SEBELAH LANTAI 3
    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KIRI KE KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-100.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, 45.0, 20.5);
    glVertex3f(-115.0, 45.0, 20.5);
    glVertex3f(-115.0, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-100.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, 45.0, 20.6);
    glVertex3f(-115.0, 45.0, 20.6);
    glVertex3f(-115.0, 20.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-100.0, 32.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-115.0, 32.5, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-105.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-105.0, 45.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL 2) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-110.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-110.0, 45.0, 20.6);
    glEnd();

    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 KIRI POJOK KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-117.5, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-117.5, 45.0, 20.5);
    glVertex3f(-122.5, 45.0, 20.5);
    glVertex3f(-122.5, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI POJOK KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-117.5, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-117.5, 45.0, 20.6);
    glVertex3f(-122.5, 45.0, 20.6);
    glVertex3f(-122.5, 20.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI POJOK KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-117.5, 32.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-122.5, 32.5, 20.6);
    glEnd();
    //---


    // JENDELA LANTAI 1 BANGUN SEBELAH KIRI BANGUN LANTAI 3 

    // JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KIRI KE KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-92.5, -15.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-92.5, 7.5, 20.5);
    glVertex3f(-97.5, 7.5, 20.5);
    glVertex3f(-97.5, -15.0, 20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-92.5, 7.5, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-92.5, 10.0, 20.5);
    glVertex3f(-97.5, 10.0, 20.5);
    glVertex3f(-97.5, 7.5, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-92.5, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-92.5, 10.0, 20.6);
    glVertex3f(-97.5, 10.0, 20.6);
    glVertex3f(-97.5, -15.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-92.5, -2.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-97.5, -2.5, 20.6);
    glEnd();
    //---

    // BAGIAN TENGAH JENDELA LANTAI 1 BANGUN SEBELAH LANTAI 3
    // JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KIRI KE KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-100.0, -15.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, 7.5, 20.5);
    glVertex3f(-115.0, 7.5, 20.5);
    glVertex3f(-115.0, -15.0, 20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-100.0, 7.5, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, 10.0, 20.5);
    glVertex3f(-115.0, 10.0, 20.5);
    glVertex3f(-115.0, 7.5, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-100.0, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, 10.0, 20.6);
    glVertex3f(-115.0, 10.0, 20.6);
    glVertex3f(-115.0, -15.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-100.0, -2.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-115.0, -2.5, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-105.0, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-105.0, 10.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL 2) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-110.0, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-110.0, 10.0, 20.6);
    glEnd();

    // JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 KIRI POJOK KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-117.5, -15.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-117.5, 7.5, 20.5);
    glVertex3f(-122.5, 7.5, 20.5);
    glVertex3f(-122.5, -15.0, 20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-117.5, 7.5, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-117.5, 10.0, 20.5);
    glVertex3f(-122.5, 10.0, 20.5);
    glVertex3f(-122.5, 7.5, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI POJOK KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-117.5, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-117.5, 10.0, 20.6);
    glVertex3f(-122.5, 10.0, 20.6);
    glVertex3f(-122.5, -15.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI POJOK KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-117.5, -2.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-122.5, -2.5, 20.6);
    glEnd();
    //---


    //

    // GENTENG LUAR Bangun sblah kiri bangun 3 lantai (1)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-130.0, 50.0, 20.0);
    glVertex3f(-130.0, 65.0, 0.0);      // TINGGI BANGUN 50
    glVertex3f(-90.0, 65.0, 0.0);
    glVertex3f(-90.0, 50.0, 20.0);
    glEnd();

    // GENTENG DALAM Bangun sblah kiri bangun 3 lantai (1)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-130.0, 50.0, -20.0);
    glVertex3f(-130.0, 65.0, 0.0);      // TINGGI BANGUN 50
    glVertex3f(-90.0, 65.0, 0.0);
    glVertex3f(-90.0, 50.0, -20.0);
    glEnd();

    // Bangun sblah Kanan bangun 3 lantai (2)
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(90.0, -20.0, 20.0);
    glVertex3f(90.0, 50.0, 20.0);      // TINGGI BANGUN 50
    glVertex3f(130.0, 50.0, 20.0);
    glVertex3f(130.0, -20.0, 20.0);
    glEnd();

    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KANAN
    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KANAN KE KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(92.5, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(92.5, 45.0, 20.5);
    glVertex3f(97.5, 45.0, 20.5);
    glVertex3f(97.5, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KANNA
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(92.5, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(92.5, 45.0, 20.6);
    glVertex3f(97.5, 45.0, 20.6);
    glVertex3f(97.5, 20.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(92.5, 32.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(97.5, 32.5, 20.6);
    glEnd();
    //---

        // JENDELA LANTAI 1 BANGUN SEBELAH KANAN BANGUN LANTAI 3 

    // JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KANAN KE KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(92.5, -15.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(92.5, 7.5, 20.5);
    glVertex3f(97.5, 7.5, 20.5);
    glVertex3f(97.5, -15.0, 20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(92.5, 7.5, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(92.5, 10.0, 20.5);
    glVertex3f(97.5, 10.0, 20.5);
    glVertex3f(97.5, 7.5, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(92.5, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(92.5, 10.0, 20.6);
    glVertex3f(97.5, 10.0, 20.6);
    glVertex3f(97.5, -15.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(92.5, -2.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(97.5, -2.5, 20.6);
    glEnd();
    //---

    // BAGIAN TENGAH JENDELA LANTAI 1 BANGUN SEBELAH LANTAI 3
    // JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KIRI KE KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(100.0, -15.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, 7.5, 20.5);
    glVertex3f(115.0, 7.5, 20.5);
    glVertex3f(115.0, -15.0, 20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(100.0, 7.5, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, 10.0, 20.5);
    glVertex3f(115.0, 10.0, 20.5);
    glVertex3f(115.0, 7.5, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(100.0, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, 10.0, 20.6);
    glVertex3f(115.0, 10.0, 20.6);
    glVertex3f(115.0, -15.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(100.0, -2.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(115.0, -2.5, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(105.0, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(105.0, 10.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL 2) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(110.0, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(110.0, 10.0, 20.6);
    glEnd();

    // JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 KIRI POJOK KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(117.5, -15.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(117.5, 7.5, 20.5);
    glVertex3f(122.5, 7.5, 20.5);
    glVertex3f(122.5, -15.0, 20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(117.5, 7.5, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(117.5, 10.0, 20.5);
    glVertex3f(122.5, 10.0, 20.5);
    glVertex3f(122.5, 7.5, 20.5);
    glEnd();


    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI KIRI POJOK KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(117.5, -15.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(117.5, 10.0, 20.6);
    glVertex3f(122.5, 10.0, 20.6);
    glVertex3f(122.5, -15.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 1 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KIRI POJOK KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(117.5, -2.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(122.5, -2.5, 20.6);
    glEnd();
    //---
    //

    // BAGIAN TENGAH JENDELA LANTAI 2 BANGUN SEBELAH LANTAI 3
    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI DARI KANAN KE KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(100.0, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, 45.0, 20.5);
    glVertex3f(115.0, 45.0, 20.5);
    glVertex3f(115.0, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(100.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, 45.0, 20.6);
    glVertex3f(115.0, 45.0, 20.6);
    glVertex3f(115.0, 20.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(100.0, 32.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(115.0, 32.5, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL) KANNA
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(105.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(105.0, 45.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (HORIZONTAL 2) KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(110.0, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(110.0, 45.0, 20.6);
    glEnd();

    // JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 KANAN POJOK KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(117.5, 20.0, 20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(117.5, 45.0, 20.5);
    glVertex3f(122.5, 45.0, 20.5);
    glVertex3f(122.5, 20.0, 20.5);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI KANAN POJOK KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(117.5, 20.0, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(117.5, 45.0, 20.6);
    glVertex3f(122.5, 45.0, 20.6);
    glVertex3f(122.5, 20.0, 20.6);
    glEnd();

    // GARIS JENDELA LANTAI 2 BANGUN SEBELAH  BANGUN 3 LANTAI (VERTIKAL) KANAN POJOK KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(117.5, 32.5, 20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(122.5, 32.5, 20.6);
    glEnd();
    //---


    // GENTENG LUAR Bangun sblah KANAN bangun 3 lantai (1)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(130.0, 50.0, 20.0);
    glVertex3f(130.0, 65.0, 0.0);      // TINGGI BANGUN 50
    glVertex3f(90.0, 65.0, 0.0);
    glVertex3f(90.0, 50.0, 20.0);
    glEnd();

    // GENTENG DALAM Bangun sblah KANAN bangun 3 lantai (1)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(130.0, 50.0, -20.0);
    glVertex3f(130.0, 65.0, 0.0);      // TINGGI BANGUN 50
    glVertex3f(90.0, 65.0, 0.0);
    glVertex3f(90.0, 50.0, -20.0);
    glEnd();




    // BAGIAN KIRI GEDUNG SERONG
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.44, 0.48);
    glVertex3f(130.0, -20.0, 20.0);
    glVertex3f(130.0, 50.0, 20.0);
    glVertex3f(140.0, 50.0, 15.0);
    glVertex3f(140.0, -20.0, 15.0);
    glEnd();

    // BAGIAN KANAN GEDUNG SERONG
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.44, 0.48);
    glVertex3f(-140.0, -20.0, 15.0);
    glVertex3f(-140.0, 50.0, 15.0);
    glVertex3f(-130.0, 50.0, 20.0);
    glVertex3f(-130.0, -20.0, 20.0);
    glEnd();




    //BAGIAN KANAN GEDUNG
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(140.0, 50.0, 15.0);       // y di kanan berbeda 
    glVertex3f(140.0, -20.0, 15.0);
    glVertex3f(140.0, -20.0, -15.0);
    glVertex3f(140.0, 50.0, -15.0);
    glEnd();

    //BAGIAN TUTUP GEDUNG ATAS KANAN
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(140.0, 50.0, 15.0);       // y di kanan berbeda 
    glVertex3f(140.0, 50.0, -20.0);
    glVertex3f(130.0, 50.0, -20.0);
    glVertex3f(130.0, 50.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(130.0, 50.0, 15.0);       // y di kanan berbeda 
    glVertex3f(130.0, 50.0, 20.0);
    glVertex3f(140.0, 50.0, 15.0);
    glEnd();

    //BAGIAN KANAN GEDUNG SEGITIGA
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(130.0, 50.0, 20.0);       // y di kanan berbeda 
    glVertex3f(130.0, 75.0, 0.0);
    glVertex3f(130.0, 50.0, -20.0);
    glEnd();


    //BAGIAN KIRI GEDUNG
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(-140.0, 50.0, 15.0);       // y di kanan berbeda 
    glVertex3f(-140.0, -20.0, 15.0);
    glVertex3f(-140.0, -20.0, -15.0);
    glVertex3f(-140.0, 50.0, -15.0);
    glEnd();

    //BAGIAN TUTUP GEDUNG ATAS KIRI
    glBegin(GL_QUADS);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(-140.0, 50.0, 15.0);       // y di kanan berbeda 
    glVertex3f(-140.0, 50.0, -20.0);
    glVertex3f(-130.0, 50.0, -20.0);
    glVertex3f(-130.0, 50.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.43, 0.40);
    glVertex3f(-130.0, 50.0, 15.0);       // y di kanan berbeda 
    glVertex3f(-130.0, 50.0, 20.0);
    glVertex3f(-140.0, 50.0, 15.0);
    glEnd();
    //BAGIAN KANAN GEDUNG SEGITIGA
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-130.0, 50.0, 20.0);       // y di kanan berbeda 
    glVertex3f(-130.0, 75.0, 0.0);
    glVertex3f(-130.0, 50.0, -20.0);

    glEnd();


    //BELAKANG
    // BAGIAN BELAKANG GEDUNG
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(-110.0, -20.0, -20.0);   // lebar gedung belakang dari -110 sampe 110
    glVertex3f(-110.0, 50.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(110.0, 50.0, -20.0);
    glVertex3f(110.0, -20.0, -20.0);
    glEnd();

    // 3 SEGITIGA BAGIAN BELAKANG
    // SEGITIGA KIRI
    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(60.0, 60.0, -20.0);
    glVertex3f(75.0, 85.0, -20.0);
    glVertex3f(90.0, 60.0, -20.0);
    glEnd();

    // GENTENG SEGITIGA KIRI
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(60.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(75.0, 85.0, -20.0);
    glVertex3f(75.0, 85.0, 0.0);
    glVertex3f(60.0, 60.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(90.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(75.0, 85.0, -20.0);
    glVertex3f(75.0, 85.0, 0.0);
    glVertex3f(90.0, 60.0, 0.0);
    glEnd();

    // tutup belakang GENTENG SEGITIGA KIRI
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(60.0, 60.0, 0.0);
    glVertex3f(75.0, 85.0, 0.0);
    glVertex3f(90.0, 60.0, 0.0);
    glEnd();


    // SEGITIGA TENGAH
    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(-15.0, 60.0, -20.0);
    glVertex3f(0.0, 85.0, -20.0);
    glVertex3f(15.0, 60.0, -20.0);
    glEnd();

    // GENTENG SEGITIGA TENGAH
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-15.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(0.0, 85.0, -20.0);
    glVertex3f(0.0, 85.0, 0.0);
    glVertex3f(-15.0, 60.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(15.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(0.0, 85.0, -20.0);
    glVertex3f(0.0, 85.0, 0.0);
    glVertex3f(15.0, 60.0, 0.0);
    glEnd();

    // tutup belakang GENTENG SEGITIGA TENGAH
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(15.0, 60.0, 0.0);
    glVertex3f(0.0, 85.0, 0.0);
    glVertex3f(-15.0, 60.0, 0.0);
    glEnd();

    // SEGITIGA KANAN
    glBegin(GL_POLYGON);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(-60.0, 60.0, -20.0);
    glVertex3f(-75.0, 85.0, -20.0);
    glVertex3f(-90.0, 60.0, -20.0);
    glEnd();

    // GENTENG SEGITIGA KANAN
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-60.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-75.0, 85.0, -20.0);
    glVertex3f(-75.0, 85.0, 0.0);
    glVertex3f(-60.0, 60.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-90.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-75.0, 85.0, -20.0);
    glVertex3f(-75.0, 85.0, 0.0);
    glVertex3f(-90.0, 60.0, 0.0);
    glEnd();

    // tutup belakang GENTENG SEGITIGA KANAN
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-60.0, 60.0, 0.0);
    glVertex3f(-75.0, 85.0, 0.0);
    glVertex3f(-90.0, 60.0, 0.0);
    glEnd();

    // TAMBAHAN TEMBOK DIBAWAH SEGITIGA
    // TAMBAHAN KANAN
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(-90.0, 50.0, -20.0);
    glVertex3f(-90.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(-60.0, 60.0, -20.0);
    glVertex3f(-60.0, 50.0, -20.0);
    glEnd();

    // TAMBAHAN TENGAH
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(-15.0, 50.0, -20.0);
    glVertex3f(-15.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(15.0, 60.0, -20.0);
    glVertex3f(15.0, 50.0, -20.0);
    glEnd();

    // TAMBAHAN KIRI
    glBegin(GL_QUADS);
    glColor3f(0.68, 0.50, 0.45);
    glVertex3f(90.0, 50.0, -20.0);
    glVertex3f(90.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(60.0, 60.0, -20.0);
    glVertex3f(60.0, 50.0, -20.0);
    glEnd();

    // PINTU BELAKANG 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(-15.0, -20.0, -40.0);
    glVertex3f(-15.0, 15.0, -40.0);      // TINGGI BANGUN 50
    glVertex3f(15.0, 15.0, -40.0);
    glVertex3f(15.0, -20.0, -40.0);
    glEnd();

    // PINTU BELAKANG TUTUP ATAS
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(-15.0, 15.0, -40.0);
    glVertex3f(-15.0, 15.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(15.0, 15.0, -20.0);
    glVertex3f(15.0, 15.0, -40.0);
    glEnd();

    // bagian KANAN PINTU BELAKANG
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(15.0, 15.0, -20.0);       // y di kanan berbeda 
    glVertex3f(15.0, -20.0, -20.0);
    glVertex3f(15.0, -20.0, -40.0);
    glVertex3f(15.0, 15.0, -40.0);
    glEnd();

    // bagian KIRI PINTU BELAKANG
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(-15.0, 15.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-15.0, -20.0, -20.0);
    glVertex3f(-15.0, -20.0, -40.0);
    glVertex3f(-15.0, 15.0, -40.0);
    glEnd();

    // BAGIAN GEDUNG KACA

    // BANGUN KACA KANAN (1)    // BELUM DI UBAH KACA
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-85.0, -20.0, -30.0);
    glVertex3f(-85.0, 50.0, -30.0);      // TINGGI BANGUN 50
    glVertex3f(-65.0, 50.0, -30.0);
    glVertex3f(-65.0, -20.0, -30.0);
    glEnd();

    // BANGUN KACA KANAN (1)    GENTENG DEPAN
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-85.0, 50.0, -30.0);
    glVertex3f(-85.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(-65.0, 60.0, -20.0);
    glVertex3f(-65.0, 50.0, -30.0);
    glEnd();

    // BANGUN KACA KANAN (1)    GENTENG KANAN
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-90.0, 50.0, -20.0);
    glVertex3f(-85.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(-85.0, 50.0, -30.0);
    glEnd();

    // BANGUN KACA KANAN (1)    GENTENG KIRI
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-60.0, 50.0, -20.0);
    glVertex3f(-65.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(-65.0, 50.0, -30.0);
    glEnd();

    // samping KIRI  (1)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-90.0, -20.0, -20.0);
    glVertex3f(-90.0, 50.0, -20.0);
    glVertex3f(-85.0, 50.0, -30.0);
    glVertex3f(-85.0, -20.0, -30.0);
    glEnd();

    // samping KANAN (1)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-60.0, -20.0, -20.0);
    glVertex3f(-60.0, 50.0, -20.0);
    glVertex3f(-65.0, 50.0, -30.0);
    glVertex3f(-65.0, -20.0, -30.0);
    glEnd();


    // BANGUN KACA KIRI (2)   // BELUM DIUBAH KACA
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(65.0, -20.0, -30.0);
    glVertex3f(65.0, 50.0, -30.0);      // TINGGI BANGUN 50
    glVertex3f(85.0, 50.0, -30.0);
    glVertex3f(85.0, -20.0, -30.0);
    glEnd();

    // BANGUN KACA KIRI (2)    GENTENG DEPAN
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(85.0, 50.0, -30.0);
    glVertex3f(85.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(65.0, 60.0, -20.0);
    glVertex3f(65.0, 50.0, -30.0);
    glEnd();

    // BANGUN KACA KIRI (2)   GENTENG KANAN
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(90.0, 50.0, -20.0);
    glVertex3f(85.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(85.0, 50.0, -30.0);
    glEnd();

    // BANGUN KACA KIRI (2)    GENTENG KIRI
    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(60.0, 50.0, -20.0);
    glVertex3f(65.0, 60.0, -20.0);      // TINGGI BANGUN 50
    glVertex3f(65.0, 50.0, -30.0);
    glEnd();

    // samping KIRI  (2)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(90.0, -20.0, -20.0);
    glVertex3f(90.0, 50.0, -20.0);
    glVertex3f(85.0, 50.0, -30.0);
    glVertex3f(85.0, -20.0, -30.0);
    glEnd();

    // samping KANAN (2)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(60.0, -20.0, -20.0);
    glVertex3f(60.0, 50.0, -20.0);
    glVertex3f(65.0, 50.0, -30.0);
    glVertex3f(65.0, -20.0, -30.0);
    glEnd();












    //BAWAH LANTAI GEDUNG
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.8, 0.7);
    glVertex3f(-140, -20.0, 30.0);
    glVertex3f(140, -20.0, 30.0);
    glVertex3f(140, -20.0, -20.0);
    glVertex3f(-140, -20.0, -20.0);
    glEnd();

    // LAPANGAN
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.55, 0.55);
    glVertex3f(-140, -20.0, -120.0);
    glVertex3f(140, -20.0, -120.0);
    glVertex3f(140, -20.0, -20.0);
    glVertex3f(-140, -20.0, -20.0);
    glEnd();



    //LANTAI 2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.7, 0.5);
    glVertex3f(-130, 20.0, 20.0);
    glVertex3f(130, 20.0, 20.0);
    glVertex3f(130, 20.0, -20.0);
    glVertex3f(-130, 20.0, -20.0);
    glEnd();

    // GEDUNG Kanan BELAKANG( DALEM)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-110.0, 30.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-110.0, -20.0, -20.0);
    glVertex3f(-110.0, -20.0, -120.0);
    glVertex3f(-110.0, 30.0, -120.0);
    glEnd();
    // GEDUNG Kanan BELAKANG( DALEM) yang 2 lantai
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-110.0, 50.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 30.0, -20.0);
    glVertex3f(-110.0, 30.0, -60.0);
    glVertex3f(-110.0, 50.0, -60.0);
    glEnd();

    // SEGITIGA KANAN BELAKANG (DALEM) 2 LANTAI
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-110.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 90.0, -40.0);
    glVertex3f(-110.0, 60.0, -60.0);
    glEnd();

    // GENTENG KANAN BELAKANG (DALEM) 2 LANTAI
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-110.0, 60.0, -20.0);       // y di kanan berbeda
    glVertex3f(-110.0, 90.0, -40.0);
    glVertex3f(-140.0, 90.0, -40.0);
    glVertex3f(-140.0, 60.0, -20.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-110.0, 60.0, -60.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 90.0, -40.0);
    glVertex3f(-140.0, 90.0, -40.0);
    glVertex3f(-140.0, 60.0, -60.0);
    glEnd();

    // tambahan
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-110.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 50.0, -20.0);
    glVertex3f(-110.0, 50.0, -60.0);
    glVertex3f(-110.0, 60.0, -60.0);
    glEnd();
    // GEDUNG Kanan BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-140.0, 30.0, -15.0);       // y di kanan berbeda 
    glVertex3f(-140.0, -20.0, -15.0);
    glVertex3f(-140.0, -20.0, -120.0);
    glVertex3f(-140.0, 30.0, -120.0);
    glEnd();
    // GEDUNG Kanan BELAKANG(LUAR) yang 2 lantai
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-140.0, 50.0, -15.0);       // y di kanan berbeda 
    glVertex3f(-140.0, 30.0, -15.0);
    glVertex3f(-140.0, 30.0, -60.0);
    glVertex3f(-140.0, 50.0, -60.0);
    glEnd();

    // SEGITIGA KIRI BELAKANG (DALEM) 2 LANTAI
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-140.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-140.0, 90.0, -40.0);
    glVertex3f(-140.0, 60.0, -60.0);
    glEnd();


    // GENTENG KANAN BELAKANG (DALEM) 2 LANTAI
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(110.0, 60.0, -20.0);       // y di kanan berbeda
    glVertex3f(110.0, 90.0, -40.0);
    glVertex3f(140.0, 90.0, -40.0);
    glVertex3f(140.0, 60.0, -20.0);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(110.0, 60.0, -60.0);       // y di kanan berbeda 
    glVertex3f(110.0, 90.0, -40.0);
    glVertex3f(140.0, 90.0, -40.0);
    glVertex3f(140.0, 60.0, -60.0);
    glEnd();

    // tambahan
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-140.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-140.0, 50.0, -20.0);
    glVertex3f(-140.0, 50.0, -60.0);
    glVertex3f(-140.0, 60.0, -60.0);
    glEnd();

    // PENUTUP BAGIAN DEPAN 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-110.0, 40.0, -20.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 60.0, -20.0);
    glVertex3f(-140.0, 60.0, -20.0);
    glVertex3f(-140.0, 40.0, -20.0);
    glEnd();

    // PENUTUP BAGIAN BELAKANG
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-110.0, 30.0, -60.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 60.0, -60.0);
    glVertex3f(-140.0, 60.0, -60.0);
    glVertex3f(-140.0, 30.0, -60.0);
    glEnd();

    // PENUTUP BAGIAN BELAKANG KANAN 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(110.0, 30.0, -60.0);       // y di kanan berbeda 
    glVertex3f(110.0, 60.0, -60.0);
    glVertex3f(140.0, 60.0, -60.0);
    glVertex3f(140.0, 30.0, -60.0);
    glEnd();

    // GEDUNG Kanan BELAKANG(TUTUP) 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.50, 0.42);
    glVertex3f(-140.0, 30.0, -120.0);       // y di kanan berbeda 
    glVertex3f(-140.0, -20.0, -120.0);
    glVertex3f(-110.0, -20.0, -120.0);
    glVertex3f(-110.0, 30.0, -120.0);
    glEnd();

    // GEDUNG Kiri BELAKANG(SEGITIGA) 
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.50, 0.42);
    glVertex3f(-110.0, 30.0, -120.0);       // y di kanan berbeda 
    glVertex3f(-125.0, 50.0, -120.0);
    glVertex3f(-140.0, 30.0, -120.0);
    glEnd();

    // GENTENG Gedung Kanan BELAKANG (GENTENG KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-140.0, 30.0, -60.0);       // y di kanan berbeda 
    glVertex3f(-140.0, 30.0, -120.0);
    glVertex3f(-125.0, 50.0, -120.0);
    glVertex3f(-125.0, 50.0, -60.0);
    glEnd();

    // GENTENG Gedung Kanan BELAKANG (GENTENG KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(-110.0, 30.0, -60.0);       // y di kanan berbeda 
    glVertex3f(-110.0, 30.0, -120.0);
    glVertex3f(-125.0, 50.0, -120.0);
    glVertex3f(-125.0, 50.0, -60.0);
    glEnd();


    // GEDUNG Kiri BELAKANG( DALEM)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(110.0, 30.0, -20.0);       // y di kanan berbeda 
    glVertex3f(110.0, -20.0, -20.0);
    glVertex3f(110.0, -20.0, -120.0);
    glVertex3f(110.0, 30.0, -120.0);
    glEnd();
    // GEDUNG Kiri BELAKANG( DALEM) yang 2 lantai
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(110.0, 50.0, -20.0);       // y di kanan berbeda 
    glVertex3f(110.0, 30.0, -20.0);
    glVertex3f(110.0, 30.0, -60.0);
    glVertex3f(110.0, 50.0, -60.0);
    glEnd();

    // tambahan
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(110.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(110.0, 50.0, -20.0);
    glVertex3f(110.0, 50.0, -60.0);
    glVertex3f(110.0, 60.0, -60.0);
    glEnd();

    // SEGITIGA KIRI BELAKANG (DALEM) 2 LANTAI
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(110.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(110.0, 90.0, -40.0);
    glVertex3f(110.0, 60.0, -60.0);

    glEnd();


    // GEDUNG Kiri BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(140.0, 30.0, -15.0);       // y di kanan berbeda 
    glVertex3f(140.0, -20.0, -15.0);
    glVertex3f(140.0, -20.0, -120.0);
    glVertex3f(140.0, 30.0, -120.0);
    glEnd();


    // GARIS TENGAH BANGUN KANAN & KIRI
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA jendela
    glVertex3f(140.5, 30.0, 15); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 30.0, -60.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA jendela
    glVertex3f(-140.5, 30.0, 15); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 30.0, -60.0);
    glEnd();
    //
    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA jendela
    glVertex3f(109.5, 30.0, -20); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 30.0, -60.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.4, 0.4, 0.4);    // WARNA jendela
    glVertex3f(-109.5, 30.0, -20); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 30.0, -60.0);
    glEnd();
    // // //

    //JENDELA LANTAI 2
    // JENDELA LUAR KIRI
     // JENDELA LANTAI 2 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 60.0, -49.0);
    glVertex3f(-140.5, 60.0, -31.0);
    glVertex3f(-140.5, 40.0, -31.0);
    glEnd();


    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 60.0, -49.0);
    glVertex3f(-140.5, 60.0, -31);
    glVertex3f(-140.5, 40.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 50.0, -49); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 50.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 40.0, -43); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 60.0, -43);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 40.0, -37); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 60.0, -37);
    glEnd();

    // JENDELA DALAM
    // JENDELA LANTAI 2 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-109.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 60.0, -49.0);
    glVertex3f(-109.5, 60.0, -31.0);
    glVertex3f(-109.5, 40.0, -31.0);
    glEnd();


    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 60.0, -49.0);
    glVertex3f(-109.5, 60.0, -31);
    glVertex3f(-109.5, 40.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 50.0, -49); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 50.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 40.0, -43); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 60.0, -43);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 40.0, -37); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 60.0, -37);
    glEnd();


    // // //
    // JENDELA LANTAI 2
    // JENDELA LUAR
     // JENDELA LANTAI 2 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 60.0, -49.0);
    glVertex3f(140.5, 60.0, -31.0);
    glVertex3f(140.5, 40.0, -31.0);
    glEnd();


    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 60.0, -49.0);
    glVertex3f(140.5, 60.0, -31);
    glVertex3f(140.5, 40.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 50.0, -49); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 50.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 40.0, -43); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 60.0, -43);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 40.0, -37); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 60.0, -37);
    glEnd();

    // JENDELA DALAM
    // JENDELA LANTAI 2 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(109.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 60.0, -49.0);
    glVertex3f(109.5, 60.0, -31.0);
    glVertex3f(109.5, 40.0, -31.0);
    glEnd();


    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.5, 40.0, -49.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 60.0, -49.0);
    glVertex3f(109.5, 60.0, -31);
    glVertex3f(109.5, 40.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 50.0, -49); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 50.0, -31);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 40.0, -43); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 60.0, -43);
    glEnd();

    // GARIS JENDELA LANTAI 2 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTA;) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 40.0, -37); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 60.0, -37);
    glEnd();

    // // 
    // JENDELA GEDUNG KIRI 2 LANTAI (1)
    // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 17.5, -50.0);
    glVertex3f(140.5, 17.5, -42.5);
    glVertex3f(140.5, -10.0, -42.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(140.5, 17.5, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -50.0);
    glVertex3f(140.5, 20.0, -42.5);
    glVertex3f(140.5, 17.5, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -50.0);
    glVertex3f(140.5, 20.0, -42.5);
    glVertex3f(140.5, -10.0, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 5.0, -50); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 5.0, -42.5);
    glEnd();

    // JENDELA KIRI 
     // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 17.5, -30.0);
    glVertex3f(140.5, 17.5, -37.5);
    glVertex3f(140.5, -10.0, -37.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(140.5, 17.5, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -30.0);
    glVertex3f(140.5, 20.0, -37.5);
    glVertex3f(140.5, 17.5, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -30.0);
    glVertex3f(140.5, 20.0, -37.5);
    glVertex3f(140.5, -10.0, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 5.0, -30); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 5.0, -37.5);
    glEnd();


    // JENDELA DALAM BANGUN 2 LANTAI //
    // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(109.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 17.5, -50.0);
    glVertex3f(109.5, 17.5, -42.5);
    glVertex3f(109.5, -10.0, -42.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(109.5, 17.5, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -50.0);
    glVertex3f(109.5, 20.0, -42.5);
    glVertex3f(109.5, 17.5, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -50.0);
    glVertex3f(109.5, 20.0, -42.5);
    glVertex3f(109.5, -10.0, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 5.0, -50); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 5.0, -42.5);
    glEnd();

    // JENDELA KIRI 
     // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(109.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 17.5, -30.0);
    glVertex3f(109.5, 17.5, -37.5);
    glVertex3f(109.5, -10.0, -37.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(109.5, 17.5, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -30.0);
    glVertex3f(109.5, 20.0, -37.5);
    glVertex3f(109.5, 17.5, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -30.0);
    glVertex3f(109.5, 20.0, -37.5);
    glVertex3f(109.5, -10.0, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 5.0, -30); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 5.0, -37.5);
    glEnd();

    // JENDELA GEDUNG KANAN DARI BELAKANG 
    // JENDELA LANTAI 1 GEDUNG 2 LANTAI (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 17.5, -50.0);
    glVertex3f(-140.5, 17.5, -42.5);
    glVertex3f(-140.5, -10.0, -42.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-140.5, 17.5, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -50.0);
    glVertex3f(-140.5, 20.0, -42.5);
    glVertex3f(-140.5, 17.5, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -50.0);
    glVertex3f(-140.5, 20.0, -42.5);
    glVertex3f(-140.5, -10.0, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 5.0, -50); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 5.0, -42.5);
    glEnd();

    // JENDELA KIRI /////////////////////////////////////////
     // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 17.5, -30.0);
    glVertex3f(-140.5, 17.5, -37.5);
    glVertex3f(-140.5, -10.0, -37.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-140.5, 17.5, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -30.0);
    glVertex3f(-140.5, 20.0, -37.5);
    glVertex3f(-140.5, 17.5, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -30.0);
    glVertex3f(-140.5, 20.0, -37.5);
    glVertex3f(-140.5, -10.0, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 5.0, -30); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 5.0, -37.5);
    glEnd();


    // PINTU GEDUNG BAGIAN KANAN DAN KIRI 
    // PINTU KANAN
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);   // WARNA jendela
    glVertex3f(140.5, -20.0, 5); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 5, 5);
    glVertex3f(140.5, 5, -5.0);
    glVertex3f(140.5, -20.0, -5.0);
    glEnd();


    // GARIS PINTU KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, -20.0, 5.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 5.0, 5.0);
    glVertex3f(140.6, 5.0, -5.0);
    glVertex3f(140.6, -20.0, -5.0);
    glVertex3f(140.6, 5.0, 5.0);
    glVertex3f(140.6, 5.0, -5.0);
    glEnd();

    // GAGANG PINTU
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(140.6, -7.5, 2.5);
    glEnd();
    //  ..  //
    // PINTU KIRI

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);   // WARNA jendela
    glVertex3f(-140.5, -20.0, 5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 5, 5);
    glVertex3f(-140.5, 5, -5.0);
    glVertex3f(-140.5, -20.0, -5.0);
    glEnd();


    // GARIS PINTU KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, -20.0, 5.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 5.0, 5.0);
    glVertex3f(-140.6, 5.0, -5.0);
    glVertex3f(-140.6, -20.0, -5.0);
    glVertex3f(-140.6, 5.0, 5.0);
    glVertex3f(-140.6, 5.0, -5.0);
    glEnd();

    // GAGANG PINTU
    glBegin(GL_POINTS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-140.6, -7.5, 2.5);
    glEnd();
    //  ..  //

    // JENDELA ATAS PINTU (KANAN)
    // JENDELA ATAS PINTU (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);  // WARNA jendela
    glVertex3f(140.5, 12.5, -15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 22.5, -15.0);
    glVertex3f(140.5, 22.5, -5);
    glVertex3f(140.5, 12.5, -5);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);   // WARNA jendela
    glVertex3f(140.6, 12.5, -15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 22.5, -15.0);
    glVertex3f(140.6, 22.5, -5);
    glVertex3f(140.6, 12.5, -5);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 17.5, -15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 17.5, -5.0);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 22.5, -10.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 12.5, -10.0);
    glEnd();


    // // 
    // JENDELA ATAS PINTU (KANAN) KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, 12.5, 15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 22.5, 15.0);
    glVertex3f(140.5, 22.5, 5);
    glVertex3f(140.5, 12.5, 5);
    glEnd();

    // GARIS JENDELA ATAS PINTU (KANAN) KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);   // WARNA jendela
    glVertex3f(140.6, 12.5, 15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 22.5, 15.0);
    glVertex3f(140.6, 22.5, 5);
    glVertex3f(140.6, 12.5, 5);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 17.5, 15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 17.5, 5.0);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (HORIZONTAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 22.5, 10.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 12.5, 10.0);
    glEnd();
    // //

    // JENDELA ATAS PINTU KANAN 
    // SETELAH GARIS TENGAH
    // JENDELA ATAS GARIS TENGAH (KANAN) 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, 35.0, 10.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 42.5, 10.0);
    glVertex3f(140.5, 42.5, -10);
    glVertex3f(140.5, 35.0, -10);
    glEnd();

    // JENDELA WARNA PUTIH
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(140.5, 42.5, 10.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 45.0, 10.0);
    glVertex3f(140.5, 45.0, -10);
    glVertex3f(140.5, 42.5, -10);
    glEnd();

    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);   // WARNA jendela
    glVertex3f(140.6, 35.0, 10.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 45.0, 10.0);
    glVertex3f(140.6, 45.0, -10);
    glVertex3f(140.6, 35.0, -10);
    glEnd();


    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) (HORIZONTAL) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 35.0, 5.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 45.0, 5.0);
    glEnd();

    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) (HORIZONTAL) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 35.0, 0.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 45.0, 0.0);
    glEnd();

    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) (HORIZONTAL) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 35.0, -5.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 45.0, -5.0);
    glEnd();

    //..// //..//
    // JENDELA SEBELAH KIRI 
    // SEBELAH GEDUNG KIRI LUAR
    // JENDELA ATAS PINTU (KANAN)
    // JENDELA ATAS PINTU (KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);  // WARNA jendela
    glVertex3f(-140.5, 12.5, -15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 22.5, -15.0);
    glVertex3f(-140.5, 22.5, -5);
    glVertex3f(-140.5, 12.5, -5);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);   // WARNA jendela
    glVertex3f(-140.6, 12.5, -15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 22.5, -15.0);
    glVertex3f(-140.6, 22.5, -5);
    glVertex3f(-140.6, 12.5, -5);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 17.5, -15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 17.5, -5.0);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 22.5, -10.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 12.5, -10.0);
    glEnd();


    // // 
    // JENDELA ATAS PINTU (KANAN) KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, 12.5, 15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 22.5, 15.0);
    glVertex3f(-140.5, 22.5, 5);
    glVertex3f(-140.5, 12.5, 5);
    glEnd();

    // GARIS JENDELA ATAS PINTU (KANAN) KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);   // WARNA jendela
    glVertex3f(-140.6, 12.5, 15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 22.5, 15.0);
    glVertex3f(-140.6, 22.5, 5);
    glVertex3f(-140.6, 12.5, 5);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 17.5, 15.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 17.5, 5.0);
    glEnd();


    // GARIS JENDELA ATAS PINTU (KANAN) (HORIZONTAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 22.5, 10.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 12.5, 10.0);
    glEnd();
    // //

    // JENDELA ATAS PINTU KANAN 
    // SETELAH GARIS TENGAH
    // JENDELA ATAS GARIS TENGAH (KANAN) 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, 35.0, 10.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 42.5, 10.0);
    glVertex3f(-140.5, 42.5, -10);
    glVertex3f(-140.5, 35.0, -10);
    glEnd();

    // JENDELA WARNA PUTIH
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-140.5, 42.5, 10.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 45.0, 10.0);
    glVertex3f(-140.5, 45.0, -10);
    glVertex3f(-140.5, 42.5, -10);
    glEnd();

    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);   // WARNA jendela
    glVertex3f(-140.6, 35.0, 10.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 45.0, 10.0);
    glVertex3f(-140.6, 45.0, -10);
    glVertex3f(-140.6, 35.0, -10);
    glEnd();


    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) (HORIZONTAL) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 35.0, 5.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 45.0, 5.0);
    glEnd();

    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) (HORIZONTAL) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 35.0, 0.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 45.0, 0.0);
    glEnd();

    // GARIS JENDELA ATAS GARIS TENGAH (KANAN) (HORIZONTAL) 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 35.0, -5.0);  //Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 45.0, -5.0);
    glEnd();

    //..// // .. //

    // JENDELA DALAM BANGUN 2 LANTAI //
    // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-109.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 17.5, -50.0);
    glVertex3f(-109.5, 17.5, -42.5);
    glVertex3f(-109.5, -10.0, -42.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-109.5, 17.5, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -50.0);
    glVertex3f(-109.5, 20.0, -42.5);
    glVertex3f(-109.5, 17.5, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.5, -10.0, -50.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -50.0);
    glVertex3f(-109.5, 20.0, -42.5);
    glVertex3f(-109.5, -10.0, -42.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 5.0, -50); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 5.0, -42.5);
    glEnd();

    // JENDELA KIRI 
     // JENDELA LANTAI 1 GEDUNG 2 LANTAI BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-109.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 17.5, -30.0);
    glVertex3f(-109.5, 17.5, -37.5);
    glVertex3f(-109.5, -10.0, -37.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-109.5, 17.5, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -30.0);
    glVertex3f(-109.5, 20.0, -37.5);
    glVertex3f(-109.5, 17.5, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) 2 LANTAI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.5, -10.0, -30.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -30.0);
    glVertex3f(-109.5, 20.0, -37.5);
    glVertex3f(-109.5, -10.0, -37.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI 2 LANTAI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 5.0, -30); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 5.0, -37.5);
    glEnd();


    // //

    // //


    // GEDUNG KANAN & KIRI
    // JENDELA GEDUNG KIRI BELAKANG (DALAM) (1)
    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(109.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 17.5, -107.5);
    glVertex3f(109.5, 17.5, -115.0);
    glVertex3f(109.5, -10.0, -115.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(109.5, 17.5, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -107.5);
    glVertex3f(109.5, 20.0, -115.0);
    glVertex3f(109.5, 17.5, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -107.5);
    glVertex3f(109.5, 20.0, -115.0);
    glVertex3f(109.5, -10.0, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 5.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 5.0, -115.0);
    glEnd();

    //

    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) TENGAH
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(109.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 17.5, -80.0);
    glVertex3f(109.5, 17.5, -102.5);
    glVertex3f(109.5, -10.0, -102.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(109.5, 17.5, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -80.0);
    glVertex3f(109.5, 20.0, -102.5);
    glVertex3f(109.5, 17.5, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) TENGAH //
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -80.0);
    glVertex3f(109.5, 20.0, -102.5);
    glVertex3f(109.5, -10.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) (VERTIKAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 5.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 5.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) (HORIZONTAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, -10.0, -95.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 20.0, -95.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) (HORIZONTAL 2)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, -10.0, -87.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 20.0, -87.5);
    glEnd();

    //
    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) BAGIAN KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(109.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 17.5, -75);
    glVertex3f(109.5, 17.5, -67.5);
    glVertex3f(109.5, -10.0, -67.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(109.5, 17.5, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -75);
    glVertex3f(109.5, 20.0, -67.5);
    glVertex3f(109.5, 17.5, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) BAGIAN KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.5, 20.0, -75);
    glVertex3f(109.5, 20.0, -67.5);
    glVertex3f(109.5, -10.0, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) (VERTIKAL) BAGIAN KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(109.4, 5.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(109.4, 5.0, -67.5);
    glEnd();

    // //  
    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-109.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 17.5, -107.5);
    glVertex3f(-109.5, 17.5, -115.0);
    glVertex3f(-109.5, -10.0, -115.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-109.5, 17.5, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -107.5);
    glVertex3f(-109.5, 20.0, -115.0);
    glVertex3f(-109.5, 17.5, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -107.5);
    glVertex3f(-109.5, 20.0, -115.0);
    glVertex3f(-109.5, -10.0, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(DALAM) (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 5.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 5.0, -115.0);
    glEnd();

    //

    // JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) TENGAH
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-109.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 17.5, -80.0);
    glVertex3f(-109.5, 17.5, -102.5);
    glVertex3f(-109.5, -10.0, -102.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-109.5, 17.5, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -80.0);
    glVertex3f(-109.5, 20.0, -102.5);
    glVertex3f(-109.5, 17.5, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) TENGAH //
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -80.0);
    glVertex3f(-109.5, 20.0, -102.5);
    glVertex3f(-109.5, -10.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) (VERTIKAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 5.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 5.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) (HORIZONTAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, -10.0, -95.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 20.0, -95.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) (HORIZONTAL 2)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, -10.0, -87.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 20.0, -87.5);
    glEnd();

    //
    // JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) BAGIAN KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-109.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 17.5, -75);
    glVertex3f(-109.5, 17.5, -67.5);
    glVertex3f(-109.5, -10.0, -67.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-109.5, 17.5, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -75);
    glVertex3f(-109.5, 20.0, -67.5);
    glVertex3f(-109.5, 17.5, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) BAGIAN KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.5, 20.0, -75);
    glVertex3f(-109.5, 20.0, -67.5);
    glVertex3f(-109.5, -10.0, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(DALAM) (VERTIKAL) BAGIAN KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-109.4, 5.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-109.4, 5.0, -67.5);
    glEnd();
    //

        // JENDELA GEDUNG KANAN BELAKANG (LUAR) (2)
    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR)
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 17.5, -107.5);
    glVertex3f(-140.5, 17.5, -115.0);
    glVertex3f(-140.5, -10.0, -115.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-140.5, 17.5, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -107.5);
    glVertex3f(-140.5, 20.0, -115.0);
    glVertex3f(-140.5, 17.5, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -107.5);
    glVertex3f(-140.5, 20.0, -115.0);
    glVertex3f(-140.5, -10.0, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 5.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 5.0, -115.0);
    glEnd();

    //

    // JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) TENGAH
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 17.5, -80.0);
    glVertex3f(-140.5, 17.5, -102.5);
    glVertex3f(-140.5, -10.0, -102.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-140.5, 17.5, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -80.0);
    glVertex3f(-140.5, 20.0, -102.5);
    glVertex3f(-140.5, 17.5, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) TENGAH //
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -80.0);
    glVertex3f(-140.5, 20.0, -102.5);
    glVertex3f(-140.5, -10.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 5.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 5.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, -10.0, -95.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 20.0, -95.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (HORIZONTAL 2)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, -10.0, -87.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 20.0, -87.5);
    glEnd();

    //
    // JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) BAGIAN KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-140.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 17.5, -75);
    glVertex3f(-140.5, 17.5, -67.5);
    glVertex3f(-140.5, -10.0, -67.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-140.5, 17.5, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -75);
    glVertex3f(-140.5, 20.0, -67.5);
    glVertex3f(-140.5, 17.5, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) BAGIAN KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.5, 20.0, -75);
    glVertex3f(-140.5, 20.0, -67.5);
    glVertex3f(-140.5, -10.0, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG KANAN BELAKANG(LUAR) (VERTIKAL) BAGIAN KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-140.6, 5.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(-140.6, 5.0, -67.5);
    glEnd();

    //JENDELA DALAM KANAN & KIRI
    // JENDELA DALEM BANGUN KIRI DARI BELAKANG
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 17.5, -107.5);
    glVertex3f(140.5, 17.5, -115.0);
    glVertex3f(140.5, -10.0, -115.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(140.5, 17.5, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -107.5);
    glVertex3f(140.5, 20.0, -115.0);
    glVertex3f(140.5, 17.5, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR)
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.5, -10.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -107.5);
    glVertex3f(140.5, 20.0, -115.0);
    glVertex3f(140.5, -10.0, -115.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) (VERTIKAL) KIRI
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 5.0, -107.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 5.0, -115.0);
    glEnd();

    //

    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) TENGAH
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 17.5, -80.0);
    glVertex3f(140.5, 17.5, -102.5);
    glVertex3f(140.5, -10.0, -102.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(140.5, 17.5, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -80.0);
    glVertex3f(140.5, 20.0, -102.5);
    glVertex3f(140.5, 17.5, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) TENGAH //
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.5, -10.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -80.0);
    glVertex3f(140.5, 20.0, -102.5);
    glVertex3f(140.5, -10.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) (VERTIKAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 5.0, -80.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 5.0, -102.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) (HORIZONTAL)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, -10.0, -95.0); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 20.0, -95.0);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) (HORIZONTAL 2)  TENGAH
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, -10.0, -87.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 20.0, -87.5);
    glEnd();

    //
    // JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) BAGIAN KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(140.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 17.5, -75);
    glVertex3f(140.5, 17.5, -67.5);
    glVertex3f(140.5, -10.0, -67.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(140.5, 17.5, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -75);
    glVertex3f(140.5, 20.0, -67.5);
    glVertex3f(140.5, 17.5, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) BAGIAN KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.5, -10.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.5, 20.0, -75);
    glVertex3f(140.5, 20.0, -67.5);
    glVertex3f(140.5, -10.0, -67.5);
    glEnd();

    // GARIS JENDELA LANTAI 1 GEDUNG Kiri BELAKANG(LUAR) (VERTIKAL) BAGIAN KANAN
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(140.6, 5.0, -75); // Z aku buat 50 buat tengah depan 
    glVertex3f(140.6, 5.0, -67.5);
    glEnd();
    //

    //


    // GEDUNG Kiri BELAKANG(LUAR) yang 2 lantai
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(140.0, 50.0, -15.0);       // y di kanan berbeda 
    glVertex3f(140.0, 30.0, -15.0);
    glVertex3f(140.0, 30.0, -60.0);
    glVertex3f(140.0, 50.0, -60.0);
    glEnd();

    // tambahan
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(140.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(140.0, 50.0, -20.0);
    glVertex3f(140.0, 50.0, -60.0);
    glVertex3f(140.0, 60.0, -60.0);
    glEnd();

    // PENUTUP BAGIAN DEPAN 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(110.0, 40.0, -20.0);       // y di kanan berbeda 
    glVertex3f(110.0, 60.0, -20.0);
    glVertex3f(140.0, 60.0, -20.0);
    glVertex3f(140.0, 40.0, -20.0);
    glEnd();


    // SEGITIGA KIRI BELAKANG (LUAR) 2 LANTAI
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(140.0, 60.0, -20.0);       // y di kanan berbeda 
    glVertex3f(140.0, 90.0, -40.0);
    glVertex3f(140.0, 60.0, -60.0);

    glEnd();


    // GEDUNG Kiri BELAKANG(TUTUP) 
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.50, 0.42);
    glVertex3f(140.0, 30.0, -120.0);       // y di kanan berbeda 
    glVertex3f(140.0, -20.0, -120.0);
    glVertex3f(110.0, -20.0, -120.0);
    glVertex3f(110.0, 30.0, -120.0);
    glEnd();

    // GEDUNG Kiri BELAKANG(SEGITIGA) 
    glBegin(GL_POLYGON);
    glColor3f(0.70, 0.50, 0.42);
    glVertex3f(110.0, 30.0, -120.0);       // y di kanan berbeda 
    glVertex3f(125.0, 50.0, -120.0);
    glVertex3f(140.0, 30.0, -120.0);
    glEnd();

    // GENTENG Gedung KIri BELAKANG (GENTENG KIRI)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(140.0, 30.0, -60.0);       // y di kanan berbeda 
    glVertex3f(140.0, 30.0, -120.0);
    glVertex3f(125.0, 50.0, -120.0);
    glVertex3f(125.0, 50.0, -60.0);
    glEnd();

    // GENTENG Gedung KIri BELAKANG (GENTENG KANAN)
    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(110.0, 30.0, -60.0);       // y di kanan berbeda 
    glVertex3f(110.0, 30.0, -120.0);
    glVertex3f(125.0, 50.0, -120.0);
    glVertex3f(125.0, 50.0, -60.0);
    glEnd();


    // JENDELA BAGIAN BELAKANG
// JENDELA BAGIAN BELAKANG TENGAH 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-12.0, 25.0, -20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-12.0, 45.0, -20.5);
    glVertex3f(12.0, 45.0, -20.5);
    glVertex3f(12.0, 25.0, -20.5);
    glEnd();
    // 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-12.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-12.0, 45.0, -20.6);
    glVertex3f(12.0, 45.0, -20.6);
    glVertex3f(12.0, 25.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-12.0, 35, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(12.0, 35, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-6.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-6.0, 45.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(0.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(0.0, 45.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(6.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(6.0, 45.0, -20.6);
    glEnd();
    //

    //
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(47.0, 20.0, -20.5);
    glVertex3f(47.0, 35.0, -20.5);
    glVertex3f(41.0, 35.0, -20.5);
    glVertex3f(41.0, 20.0, -20.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(47.0, 35.0, -20.55);
    glVertex3f(47.0, 40.0, -20.55);
    glVertex3f(41.0, 40.0, -20.55);
    glVertex3f(41.0, 35.0, -20.55);
    glEnd();
    // GARIS JENDELA 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 20.0, -20.6);
    glVertex3f(47.0, 40.0, -20.6);
    glVertex3f(41.0, 40.0, -20.6);
    glVertex3f(41.0, 20.0, -20.6);
    glEnd();
    // GARIS JENDELA  
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 35.0, -20.6);
    glVertex3f(41.0, 35.0, -20.6);
    glEnd();
    // JENDELA 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(39.0, 20.0, -20.5);
    glVertex3f(39.0, 35.0, -20.5);
    glVertex3f(33.0, 35.0, -20.5);
    glVertex3f(33.0, 20.0, -20.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(39.0, 35.0, -20.55);
    glVertex3f(39.0, 40.0, -20.55);
    glVertex3f(33.0, 40.0, -20.55);
    glVertex3f(33.0, 35.0, -20.55);
    glEnd();
    // GARIS JENDELA 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 20.0, -20.6);
    glVertex3f(39.0, 40.0, -20.6);
    glVertex3f(33.0, 40.0, -20.6);
    glVertex3f(33.0, 20.0, -20.6);
    glEnd();
    // GARIS JENDELA 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 35.0, -20.6);
    glVertex3f(33.0, 35.0, -20.6);
    glEnd();
    // JENDELA LANTAI 1 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(47.0, -10.0, -20.5);
    glVertex3f(47.0, 10.0, -20.5);
    glVertex3f(41.0, 10.0, -20.5);
    glVertex3f(41.0, -10.0, -20.5);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 10.0, -20.6);
    glVertex3f(47.0, -10.0, -20.6);
    glVertex3f(41.0, -10.0, -20.6);
    glVertex3f(41.0, 10.0, -20.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(47.0, 0.0, -20.6);
    glVertex3f(41.0, 0.0, -20.6);
    glEnd();
    // JENDELA LANTAI 1 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(39.0, -10.0, -20.5);
    glVertex3f(39.0, 10.0, -20.5);
    glVertex3f(33.0, 10.0, -20.5);
    glVertex3f(33.0, -10.0, -20.5);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 10.0, -20.6);
    glVertex3f(39.0, -10.0, -20.6);
    glVertex3f(33.0, -10.0, -20.6);
    glVertex3f(33.0, 10.0, -20.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(39.0, 0.0, -20.6);
    glVertex3f(33.0, 0.0, -20.6);
    glEnd();



    //KANAN
    // JENDELA BANGUN SEBELAH KANAN DARI BANGUN TENGAH PERSIS //
    // JENDELA LANTAI 2 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-47.0, 20.0, -20.5);
    glVertex3f(-47.0, 35.0, -20.5);
    glVertex3f(-41.0, 35.0, -20.5);
    glVertex3f(-41.0, 20.0, -20.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-47.0, 35.0, -20.55);
    glVertex3f(-47.0, 40.0, -20.55);
    glVertex3f(-41.0, 40.0, -20.55);
    glVertex3f(-41.0, 35.0, -20.55);
    glEnd();
    // GARIS JENDELA LANTAI 2 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 20.0, -20.6);
    glVertex3f(-47.0, 40.0, -20.6);
    glVertex3f(-41.0, 40.0, -20.6);
    glVertex3f(-41.0, 20.0, -20.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 35.0, -20.6);
    glVertex3f(-41.0, 35.0, -20.6);
    glEnd();
    // JENDELA LANTAI 2 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-39.0, 20.0, -20.5);
    glVertex3f(-39.0, 35.0, -20.5);
    glVertex3f(-33.0, 35.0, -20.5);
    glVertex3f(-33.0, 20.0, -20.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);   // WARNA jendela
    glVertex3f(-39.0, 35.0, -20.55);
    glVertex3f(-39.0, 40.0, -20.55);
    glVertex3f(-33.0, 40.0, -20.55);
    glVertex3f(-33.0, 35.0, -20.55);
    glEnd();
    // GARIS JENDELA LANTAI 2
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 20.0, -20.6);
    glVertex3f(-39.0, 40.0, -20.6);
    glVertex3f(-33.0, 40.0, -20.6);
    glVertex3f(-33.0, 20.0, -20.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 35.0, -20.6);
    glVertex3f(-33.0, 35.0, -20.6);
    glEnd();
    //
    // JENDELA LANTAI 1 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-47.0, -10.0, -20.5);
    glVertex3f(-47.0, 10.0, -20.5);
    glVertex3f(-41.0, 10.0, -20.5);
    glVertex3f(-41.0, -10.0, -20.5);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 10.0, -20.6);
    glVertex3f(-47.0, -10.0, -20.6);
    glVertex3f(-41.0, -10.0, -20.6);
    glVertex3f(-41.0, 10.0, -20.6);
    glEnd();
    // GARIS JENDELA LANTAI 1  
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-47.0, 0.0, -20.6);
    glVertex3f(-41.0, 0.0, -20.6);
    glEnd();
    // JENDELA LANTAI 1 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-39.0, -10.0, -20.5);
    glVertex3f(-39.0, 10.0, -20.5);
    glVertex3f(-33.0, 10.0, -20.5);
    glVertex3f(-33.0, -10.0, -20.5);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 10.0, -20.6);
    glVertex3f(-39.0, -10.0, -20.6);
    glVertex3f(-33.0, -10.0, -20.6);
    glVertex3f(-33.0, 10.0, -20.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-39.0, 0.0, -20.6);
    glVertex3f(-33.0, 0.0, -20.6);
    glEnd();


    // BANGUN TIGA LANTAI KIRI 1
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.42, 0.39);
    glVertex3f(-90.0, -20.0, 30.0);
    glVertex3f(-90.0, 85.0, 30.0);      // TINGGI BANGUN 70
    glVertex3f(-60.0, 85.0, 30.0);
    glVertex3f(-60.0, -20.0, 30.0);
    glEnd();
    // JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-84.0, 12.5, -30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 0, -30.5);
    glVertex3f(-66.0, 0, -30.5);
    glVertex3f(-66.0, 12.5, -30.5);
    glEnd();
    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 12.5, -30.6);
    glVertex3f(-66.0, 12.5, -30.6);
    glVertex3f(-66.0, 0, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-78.0, 0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-78.0, 12.5, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KIRI (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-72.0, 0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-72.0, 12.5, -30.6);
    glEnd();
    // JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-84.0, 20.0, -30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 45.0, -30.5);
    glVertex3f(-66.0, 45.0, -30.5);
    glVertex3f(-66.0, 20.0, -30.5);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 20.0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-84.0, 45.0, -30.6);
    glVertex3f(-66.0, 45.0, -30.6);
    glVertex3f(-66.0, 20.0, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI (VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-84.0, 32.5, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-66.0, 32.5, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-78.0, 20.0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-78.0, 45.0, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KIRI (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-72.0, 20.0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-72.0, 45.0, -30.6);
    glEnd();
    //




    // JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(84.0, 12.5, -30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 0, -30.5);
    glVertex3f(66.0, 0, -30.5);
    glVertex3f(66.0, 12.5, -30.5);
    glEnd();
    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 12.5, -30.6);
    glVertex3f(66.0, 12.5, -30.6);
    glVertex3f(66.0, 0, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(78.0, 0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(78.0, 12.5, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 1 BANGUN 3 LANTAI KANAN (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(72.0, 0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(72.0, 12.5, -30.6);
    glEnd();
    // JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(84.0, 20.0, -30.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 45.0, -30.5);
    glVertex3f(66.0, 45.0, -30.5);
    glVertex3f(66.0, 20.0, -30.5);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 20.0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(84.0, 45.0, -30.6);
    glVertex3f(66.0, 45.0, -30.6);
    glVertex3f(66.0, 20.0, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN (VERTIKAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(84.0, 32.5, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(66.0, 32.5, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN (HORIZONTAL)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(78.0, 20.0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(78.0, 45.0, -30.6);
    glEnd();
    // GARIS JENDELA LANTAI 2 BANGUN 3 LANTAI KANAN (HORIZONTAL 2)
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(72.0, 20.0, -30.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(72.0, 45.0, -30.6);
    glEnd();


    // JENDELA BAGIAN BELAKANG SEBELAH KIRI BANGUN 3 LANTAI 2
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(106.0, 25.0, -20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(106.0, 45.0, -20.5);
    glVertex3f(94.0, 45.0, -20.5);
    glVertex3f(94.0, 25.0, -20.5);
    glEnd();
    // 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(106.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(106.0, 45.0, -20.6);
    glVertex3f(94.0, 45.0, -20.6);
    glVertex3f(94.0, 25.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(106.0, 35, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(94.0, 35, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(100.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, 45.0, -20.6);
    glEnd();
    // 

    // JENDELA BELAKANG SEBELAH KIRI BANGUN 3 BAGIAN LANTAI 1
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(106.0, 15.0, -20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(106.0, -5.0, -20.5);
    glVertex3f(94.0, -5.0, -20.5);
    glVertex3f(94.0, 15.0, -20.5);
    glEnd();
    // 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(106.0, 15.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(106.0, -5.0, -20.6);
    glVertex3f(94.0, -5.0, -20.6);
    glVertex3f(94.0, 15.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(106.0, 5, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(94.0, 5, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(100.0, 15.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(100.0, -5.0, -20.6);
    glEnd();
    // 

    // JENDELA BELAKANG SEBELAH KANAN BANGUN 3 KANAN BAGIAN LANTAI 1 
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-106.0, 15.0, -20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-106.0, -5.0, -20.5);
    glVertex3f(-94.0, -5.0, -20.5);
    glVertex3f(-94.0, 15.0, -20.5);
    glEnd();
    // 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-106.0, 15.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-106.0, -5.0, -20.6);
    glVertex3f(-94.0, -5.0, -20.6);
    glVertex3f(-94.0, 15.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-106.0, 5, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-94.0, 5, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-100.0, 15.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, -5.0, -20.6);
    glEnd();
    // 
    // JENDELA BELAKANG SEBELAH KANAN BANGUN 3 BAGIAN LANTAI 2
    glBegin(GL_QUADS);
    glColor3f(0.2843, 0.309, 0.309);   // WARNA jendela
    glVertex3f(-106.0, 25.0, -20.5); // Z aku buat 50 buat tengah depan 
    glVertex3f(-106.0, 45.0, -20.5);
    glVertex3f(-94.0, 45.0, -20.5);
    glVertex3f(-94.0, 25.0, -20.5);
    glEnd();
    // 
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-106.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-106.0, 45.0, -20.6);
    glVertex3f(-94.0, 45.0, -20.6);
    glVertex3f(-94.0, 25.0, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-106.0, 35, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-94.0, 35, -20.6);
    glEnd();
    // 
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.6);    // WARNA jendela
    glVertex3f(-100.0, 25.0, -20.6); // Z aku buat 50 buat tengah depan 
    glVertex3f(-100.0, 45.0, -20.6);
    glEnd();
    // 


    // FURNITURE            5
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