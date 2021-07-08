#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);

int is_depth;
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(0.0, 0.80, 2.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);


}
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(5.0, 5.0, 1000.0);//A
    glVertex3f(1500.0, 5.0, 1000.0);//B
    glVertex3f(1500.0, 4000.0, 1000.0);//C
    glVertex3f(5.0, 4000.0, 1000.0);//D
    glEnd();
//---------------------------------------------------------------------------

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(5.0, 5.0, -1000.0);//-A
    glVertex3f(1500.0, 5.0, -1000.0);//-B
    glVertex3f(1500.0, 4000.0, -1000.0);//-C
    glVertex3f(5.0, 4000.0, -1000.0);//-D
    glEnd();

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(5.0, 5.0, 1000.0);//A
    glVertex3f(5.0, 4000.0, 1000.0);//D
    glVertex3f(5.0, 4000.0, -1000.0);//-D
    glVertex3f(5.0, 5.0, -1000.0);//A

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(1500.0, 5.0, 1000.0);//B
    glVertex3f(1500.0, 4000.0, 1000.0);//D
    glVertex3f(1500.0, 4000.0, -1000.0);//B
    glVertex3f(1500.0, 5.0, -1000.0);//A

    glBegin(GL_QUADS);//ATAS
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(5.0, 4000.0, 1000.0);//D
    glVertex3f(1500.0, 4000.0, 1000.0);//D
    glVertex3f(1500.0, 4000.0, -1000.0);//-B
    glVertex3f(5.0, 4000.0, -1000.0);//-A

    //glBegin(GL_QUADS);//BAWAH
    //glColor3f(1.0, 1.0, 1.0);
    //glVertex3f(5.0, 5.0, 1000.0);//D
    //glVertex3f(1500.0, 5.0, 1000.0);//D
    //glVertex3f(1500.0, 5, -1000.0);//B
    //glVertex3f(5.0, 5.0, -1000.0);//A

    //-------------------------------------------------------
    //GEDUNG 2  
    glBegin(GL_QUADS);//DEPAN
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1501.0, 5.0, 1000.0);//A
    glVertex3f(2200.0, 5.0, 1000.0);//B
    glVertex3f(2200.0, 700, 1000.0);//C
    glVertex3f(1501.0, 700.0, 1000.0);//D

    glBegin(GL_QUADS);//BELAKANG
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1501.0, 5.0, -1000.0);//A
    glVertex3f(2200.0, 5.0, -1000.0);//B
    glVertex3f(2200.0, 700, -1000.0);//C
    glVertex3f(1501.0, 700.0, -1000.0);//D

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2200.0, 5.0, 1000.0);//A
    glVertex3f(2200.0, 700.0, 1000.0);//B
    glVertex3f(2200.0, 700, -1000.0);//C
    glVertex3f(2200.0, 5.0, -1000.0);//D

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(0.0, 0., 0.0);
    glVertex3f(1501.0, 5.0, 1000.0);//B
    glVertex3f(1501.0, 700.0, 1000.0);//D
    glVertex3f(1501.0, 700.0, -1000.0);//B
    glVertex3f(1501.0, 5.0, -1000.0);//A

    glBegin(GL_QUADS);//ATAS
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1501.0, 700.0, 1000.0);//B
    glVertex3f(2200.0, 700.0, 1000.0);//D
    glVertex3f(2200.0, 700.0, -1000.0);//-B
    glVertex3f(1501.0, 700.0, -1000.0);//-A




    //-----------------------------------------------------------
    //GEDUNG 3
    glBegin(GL_QUADS);//DEPAN
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 5.0, 900.0);//B
    glVertex3f(3100.0, 5.0, 900.0);//D
    glVertex3f(3100.0, 1200.0, 900.0);//D
    glVertex3f(2201.0, 1200.0, 900.0);//B

    glBegin(GL_QUADS);//BELAKANG
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 5.0, 450.0);//B
    glVertex3f(3100.0, 5.0, 450.0);//D
    glVertex3f(3100.0, 1200.0, 450.0);//D
    glVertex3f(2201.0, 1200.0, 450.0);//B

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 5.0, 900.0);//B
    glVertex3f(2201.0, 1200.0, 900.0);//D
    glVertex3f(2201.0, 1200.0, 450.0);//D
    glVertex3f(2201.0, 5.0, 450.0);//B

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(3100.0, 5.0, 900.0);//B
    glVertex3f(3100.0, 1200.0, 900.0);//D
    glVertex3f(3100.0, 1200.0, 450.0);//D
    glVertex3f(3100.0, 5.0, 450.0);//B

    glBegin(GL_QUADS);//ATAS
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 1200.0, 900.0);//B
    glVertex3f(3100.0, 1200.0, 900.0);//D
    glVertex3f(3100.0, 1200.0, 450.0);//D
    glVertex3f(2201.0, 1200.0, 450.0);//B

 
//------------------------------------------------------------------
    //GEDUNG3
    glBegin(GL_QUADS);//BELAKANG2
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 5.0, 449.0);//B
    glVertex3f(3100.0, 5.0, 449.0);//D
    glVertex3f(3100.0, 700.0, 449.0);//D
    glVertex3f(2201.0, 700.0, 449.0);//B


    glBegin(GL_QUADS);//BELAKANG3
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 5.0, -1000.0);//B
    glVertex3f(3100.0, 5.0, -1000.0);//D
    glVertex3f(3100.0, 700.0, -1000.0);//D
    glVertex3f(2201.0, 700.0, -1000.0);//B


    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 5.0, 449.0);//B
    glVertex3f(2201.0, 700.0, 449.0);//D
    glVertex3f(2201.0, 700.0, -1000);//-D
    glVertex3f(2201.0, 5.0, -1000.0);//-B

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(3100.0, 5.0, 449.0);//B
    glVertex3f(3100.0, 700.0, 449.0);//D
    glVertex3f(3100.0, 700.0, -1000);//-D
    glVertex3f(3100.0, 5.0, -1000.0);//-B


    glBegin(GL_QUADS);//ATAS
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2201.0, 700.0, 449.0);//B
    glVertex3f(3100.0, 700.0, 449.0);//D
    glVertex3f(3100.0, 700.0, -1000);//-D
    glVertex3f(2201.0, 700.0, -1000.0);//-B


//-------------------------------------------------------------------------------------
    glBegin(GL_QUADS);//DEPAN KANAN
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(3100.0, 5.0, 1000.0);//B
    glVertex3f(2900.0, 5.0, 1000.0);//D
    glVertex3f(2900.0, 1200.0, 1000);//-D
    glVertex3f(3100.0, 1200.0, 1000.0);//-B

    glBegin(GL_QUADS);//DEPAN KANAN BG
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(3100.0, 5.0, 901.0);//B
    glVertex3f(2900.0, 5.0, 901.0);//D
    glVertex3f(2900.0, 1200.0, 901);//-D
    glVertex3f(3100.0, 1200.0, 901.0);//-B

    glBegin(GL_QUADS);//DEPAN KANAN SN
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(3100.0, 5.0, 1000.0);//B
    glVertex3f(3100.0, 1200.0, 1000.0);//D
    glVertex3f(3100.0, 1200.0, 901);//-D
    glVertex3f(3100.0, 5.0, 901.0);//-B

    glBegin(GL_QUADS);//DEPAN KANAN SK
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2900.0, 5.0, 1000.0);//B
    glVertex3f(2900.0, 1200.0, 1000.0);//D
    glVertex3f(2900.0, 1200.0, 901);//-D
    glVertex3f(2900.0, 5.0, 901.0);//-B

    glBegin(GL_QUADS);//ATAS
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(2900.0, 1200.0, 1000.0);//B
    glVertex3f(3100.0, 1200.0, 1000.0);//D
    glVertex3f(3100.0, 1200.0, 901);//-D
    glVertex3f(2900.0, 1200.0, 901.0);//-B


//---------------------------------------------------------------------
    //BATAS
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.30, 0.80);
    glVertex3f(3101.0, 5.0, 1000.0);//B
    glVertex3f(3300.0, 5.0, 1000.0);//D
    glVertex3f(3300.0, 400.0, 1000);//D
    glVertex3f(3101.0, 400.0, 1000.0);//B

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3101.0, 5.0, -1000.0);//-B
    glVertex3f(3300.0, 5.0, -1000.0);//-D
    glVertex3f(3300.0, 400.0, -1000);//-D
    glVertex3f(3101.0, 400.0, -1000.0);//-B

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3101.0, 5.0, 1000.0);//B
    glVertex3f(3101.0, 400.0, 1000.0);//D
    glVertex3f(3101.0, 400.0, -1000);//-D
    glVertex3f(3101.0, 5.0, -1000.0);//-B

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(3300.0, 5.0, 1000.0);//B
    glVertex3f(3300.0, 400.0, 1000.0);//D
    glVertex3f(3300.0, 400.0, -1000);//-D
    glVertex3f(3300.0, 5.0, -1000.0);//-B

    glBegin(GL_QUADS);//ATAS
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(3101.0, 400.0, 1000.0);//B
    glVertex3f(3300.0, 400.0, 1000.0);//D
    glVertex3f(3300.0, 400.0, -1000);//-D
    glVertex3f(3101.0, 400.0, -1000.0);//-B


//-------------------------------------------------------------------------
    //GEDUNG4
    glBegin(GL_QUADS);//DEPAN
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(3301.0, 5.0, 1000.0);//B
    glVertex3f(4050.0, 5.0, 1000.0);//D
    glVertex3f(4050.0, 4000.0, 1000);//D
    glVertex3f(3301.0, 4000.0, 1000.0);//B

    glBegin(GL_QUADS);//BELAKANG
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(3301.0, 5.0, -1000.0);//-B
    glVertex3f(4050.0, 5.0, -1000.0);//-D
    glVertex3f(4050.0, 4000.0, -1000);//-D
    glVertex3f(3301.0, 4000.0, -1000.0);//-B

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(3301.0, 5.0, 1000.0);//B
    glVertex3f(3301.0, 4000.0, 1000.0);//D
    glVertex3f(3301.0, 4000.0, -1000);//-D
    glVertex3f(3301.0, 5.0, -1000.0);//-B

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(4050.0, 5.0, 1000.0);//B
    glVertex3f(4050.0, 4000.0, 1000.0);//D
    glVertex3f(4050.0, 4000.0, -1000);//-D
    glVertex3f(4050.0, 5.0, -1000.0);//-B

    glBegin(GL_QUADS);//ATAS
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(3301.0, 4000.0, 1000.0);//B
    glVertex3f(4050.0, 4000.0, 1000.0);//D
    glVertex3f(4050.0, 4000.0, -1000);//-D
    glVertex3f(3301.0, 4000.0, -1000.0);//-B

 
//--------------------------------------------------------------
   //GEDUNG5
    glBegin(GL_QUADS);//DEPAN
    glColor3f(0.0, 0.0, 0.80);
    glVertex3f(4051.0, 5.0, -650.0);//-B
    glVertex3f(5050.0, 5.0, -650.0);//-D
    glVertex3f(5050.0, 4700.0, -650);//-D
    glVertex3f(4051.0, 4700.0, -650.0);//-B

    glBegin(GL_QUADS);//BELAKANG
    glColor3f(0.0, 0.0, 0.80);
    glVertex3f(4051.0, 5.0, -1500.0);//B
    glVertex3f(5050.0, 5.0, -1500.0);//D
    glVertex3f(5050.0, 4700.0, -1500);//D
    glVertex3f(4051.0, 4700.0, -1500.0);//B

    glBegin(GL_QUADS);//SAMPING KIRI
    glColor3f(0.0, 0.0, 0.80);
    glVertex3f(4051.0, 5.0, -650.0);//B
    glVertex3f(4051.0, 4700.0, -650.0);//D
    glVertex3f(4051.0, 4700.0, -1500);//D
    glVertex3f(4051.0, 5.0, -1500.0);//B

    glBegin(GL_QUADS);//SAMPING KANAN
    glColor3f(0.0, 0.0, 0.80);
    glVertex3f(5050.0, 5.0, -650.0);//B
    glVertex3f(5051.0, 4700.0, -650.0);//D
    glVertex3f(5051.0, 4700.0, -1500);//D
    glVertex3f(5051.0, 5.0, -1500.0);//B

    glBegin(GL_QUADS);//ATAS
    glColor3f(0.0, 0.0, 0.80);
    glVertex3f(4051.0, 4700.0, -650.0);//B
    glVertex3f(5051.0, 4700.0, -650.0);//D
    glVertex3f(5051.0, 4700.0, -1500);//D
    glVertex3f(4051.0, 4700.0, -1500.0);//B

    glBegin(GL_QUADS);//BAWAH
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4051.0, 5.0, -650.0);//B
    glVertex3f(5051.0, 5.0, -650.0);//D
    glVertex3f(5051.0, 5.0, -1500);//D
    glVertex3f(4051.0, 5.0, -1500.0);//B
    glEnd();


//-----------------------------------------------------------------
    //DASAR
    glBegin(GL_QUADS); //DEPAN
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(5.0, 5.0, 1000);
    glVertex3f(4051, 5.0, 1000);
    glVertex3f(4051, -600, 1000);
    glVertex3f(5, -600.0, 1000);

   
    glBegin(GL_QUADS);//BELAKANG
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(5.0, 5.0, -1000);
    glVertex3f(4051, 5.0, -1000);
    glVertex3f(4051, -600, -1000);
    glVertex3f(5, -600.0, -1000);

    glBegin(GL_QUADS);//SIKI
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(5.0, 5.0, 1000);
    glVertex3f(5, -600.0, 1000);
    glVertex3f(5, -600, -1000);
    glVertex3f(5, 5.0, -1000);

    glBegin(GL_QUADS);//SIKA
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(4051.0, 5.0, 1000);
    glVertex3f(4051, -600.0, 1000);
    glVertex3f(4051, -600, -1000);
    glVertex3f(4051, 5.0, -1000);
//--------------------------------------------------------------------------------------------------------------------
    //MEJA

    glBegin(GL_QUADS);//ATAS
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2000, -350, 500);
    glVertex3f(2200, -350, 500);
    glVertex3f(2200, -350, 400);
    glVertex3f(2000, -350, 400);

    glBegin(GL_QUADS);//ALAS
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2000, -400, 500);
    glVertex3f(2200, -400, 500);
    glVertex3f(2200, -400, 400);
    glVertex3f(2000, -400, 400);

   
    glBegin(GL_QUADS);//BELAKANG
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2000, -350, 400);
    glVertex3f(2200, -350, 400);
    glVertex3f(2200, -400, 400);
    glVertex3f(2000, -400, 400);

    glBegin(GL_QUADS);//SAKI
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(2200, -350, 400);
    glVertex3f(2200, -400, 400);
    glVertex3f(2200, -400, 500);
    glVertex3f(2200, -350, 500);

    glBegin(GL_QUADS);//SAKA
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(2000, -350, 400);
    glVertex3f(2000, -400, 400);
    glVertex3f(2000, -400, 500);
    glVertex3f(2000, -350, 500);

    glBegin(GL_QUADS);//DEPAN
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(2000, -350, 500);
    glVertex3f(2200, -350, 500);
    glVertex3f(2200, -400, 500);
    glVertex3f(2000, -400, 500);

    glBegin(GL_QUADS);//AKB
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2000, -400, 400);
    glVertex3f(2020, -400, 400);
    glVertex3f(2020, -400, 420);
    glVertex3f(2000, -400, 420);

    glBegin(GL_QUADS);//KBB
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2000, -400, 400);
    glVertex3f(2020, -400, 400);
    glVertex3f(2020, -600, 400);
    glVertex3f(2000, -600, 400);

    glBegin(GL_QUADS);//KBD
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(2000, -400, 420);
    glVertex3f(2020, -400, 420);
    glVertex3f(2020, -600, 420);
    glVertex3f(2000, -600, 420);

    glBegin(GL_QUADS);//KBSK
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(2000, -400, 400);
    glVertex3f(2020, -400, 420);
    glVertex3f(2020, -600, 420);
    glVertex3f(2000, -600, 400);

    glBegin(GL_QUADS);//KBSKN
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(2020, -400, 400);
    glVertex3f(2020, -400, 420);
    glVertex3f(2020, -600, 420);
    glVertex3f(2020, -600, 400);

//----------------------------------------------------------------------------------------------
    glBegin(GL_QUADS);//ALAS
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(5.0, -600.0, 1000);
    glVertex3f(4051, -600.0, 1000);
    glVertex3f(4051, -600, -1000);
    glVertex3f(5, -600.0, -1000);


    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

/*
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"Q" : Melihat interior
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(30.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-30.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 20.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -20.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 20.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -20.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case 'q':
    case 'Q':
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
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(500.0, width / height, 1.0, 7000.0);
    glTranslatef(-200.0, -200.0, -3000.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Tunjungan Plaza, Surabaya");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
//672019174 Gayus sembara
//672019292 Adrianus Dullades Simamora
//672019324 Ardon gilbert bubala
