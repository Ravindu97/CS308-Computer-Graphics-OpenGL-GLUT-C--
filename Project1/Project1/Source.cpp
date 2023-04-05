#include <GL/glut.h>  
#include <math.h>
#include "spaceCraftHeader.h"
#define pi 3.142857

static int m = 0, M = 0, v = 0, V = 0, E = 0, e = 0, r = 0, R = 0, j = 0, J = 0, s = 0, S = 0, U = 0, u = 0, n = 0, N = 0, X = 0, z = 0, B = 0, b
= 0, c = 0;

// Space Craft path variables
GLfloat craftRotZ = 0;

//space station animation
float stationY = 0;
float rotateY = 0;
float craftMove = 0;

float moveHoverAfter = 0;

//refinery animation
float refineryZ = 0;

//radar rotate
float radarRotateY = 0;

//ISS move
float issTranslate = 0;

float rotateExporerZ = 0;
float translateExplorer = 0;


//frame number
float frameNumber = 0;


//camera variables
GLfloat camX = 0, camY = 0, camZ = 0;


//scene variables
GLfloat sceX = 0, sceY = 0, sceZ = 0;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
}
void drawGrid() {
    GLint line;
    GLfloat step = 1.0f;

    glLineWidth(2);
    glBegin(GL_LINES);

    for (line = -10; line <= 10; line += step) {
        glVertex3f(line, 0, 10);
        glVertex3f(line, 0, -10);

        glVertex3f(10, 0, line);
        glVertex3f(-10, 0, line);
    }
    glEnd();

}

void drawAxes() {
    glBegin(GL_LINES);
    glColor3f(1.0, 0, .0);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 0, -10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 1.0, 0);
    glVertex3f(0, 10, 0);
    glVertex3f(0, -10, -0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 1.0);
    glVertex3f(-10, 0, 0);
    glVertex3f(10, 0, 0);
    glEnd();
}
void renderPlanets() {

    //sun
    GLfloat position[] = { 0.0,0.0,1.5,1.0 };
    glutSolidSphere(0.8, 40, 16);
    glPopMatrix();
    glPushMatrix();
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glDisable(GL_LIGHTING);
    glEnable(GL_LIGHTING);
    glColor3f(1.5, 0.5, 0.0);
    glutSolidTorus(0.2, 0.9, 6, 20);
    glPopMatrix();


    //mercury
    glPushMatrix();
    glRotatef((GLfloat)M, 0.0, 1.0, 0.0);
    glTranslatef(1.5, 0.0, 0.0);
    glRotatef((GLfloat)m, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.2, 20, 8);
    glPopMatrix();

    //venus
    glPushMatrix();
    glRotatef((GLfloat)V, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 1.0);
    glRotatef((GLfloat)v, 0.0, 1.0, 0.0);
    glColor3f(7.5, 9.5, 1.0);
    glutSolidSphere(0.2, 20, 8);
    glPopMatrix();

    //earth
    glPushMatrix();
    glRotatef((GLfloat)E, 0.0, 1.0, 0.0);
    glTranslatef(3.5, 0.0, 0.0);
    glRotatef((GLfloat)e, 0.0, 1.0, 0.0);
    glColor3f(0.1, 6.5, 2.0);
    glutSolidSphere(0.2, 20, 8);
    glRotatef((GLfloat)X, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.2, 0.0);
    glColor3f(4.3, 3.5, 8.0);
    glutSolidSphere(0.1, 20, 14); /*draw moon*/
    glPopMatrix();

    //mars
    glPushMatrix();
    glRotatef((GLfloat)R, 0.0, 1.0, 0.0);
    glTranslatef(5.0, 0.0, 3.0);
    glRotatef((GLfloat)r, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.2, 0.0);
    glutSolidSphere(0.2, 20, 8); /*draw smaller planet mars*/
    glPopMatrix();

    //jupiter
    glPushMatrix();
    glRotatef((GLfloat)J, 0.0, 1.0, 0.0);
    glTranslatef(-2.5, 0.0, 1.0);
    glRotatef((GLfloat)j, 0.0, 1.0, 0.0);
    glColor3f(0.9, 0.7, 0.3);
    glutSolidSphere(0.2, 20, 8);/*draw smaller planet Jupiter*/
    glPopMatrix();

    //Saturn
    glPushMatrix();
    glRotatef((GLfloat)S, 0.0, 1.0, 0.0);
    glTranslatef(-5.0, 0.0, 0.0);
    glRotatef((GLfloat)s, 0.0, 0.0, 5.0);
    glColor3f(4.5, 0.5, 0.0);
    glutSolidSphere(0.5, 20, 16);
    int i = 0;
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= 360; i++)
    {
        glVertex3f(sin(i * 3.1416 / 180) * 0.5, cos(i * 3.1416 / 180) * 0.5, 0);
        glVertex3f(sin(i * 3.1416 / 180) * 0.7, cos(i * 3.1416 / 180) * 0.7, 0);
    }
    glEnd();
    glPopMatrix();

    //Uranus
    glPushMatrix();
    glRotatef((GLfloat)U, 0.0, 1.0, 0.0);
    glTranslatef(-6.5, 0.0, 0.0);
    glColor3f(1.2, 0.6, 0.2);
    glutSolidSphere(0.5, 20, 16);
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= 360; i++)
    {
        glVertex3f(sin(i * 3.1416 / 180) * 0.5, cos(i * 3.1416 / 180) * 0.5, 0);
        glVertex3f(sin(i * 3.1416 / 180) * 0.7, cos(i * 3.1416 / 180) * 0.7, 0);
    }
    glEnd();
    glPopMatrix();

    //Neptune
    glPushMatrix();
    glRotatef((GLfloat)N, 0.0, 1.0, 0.0);
    glTranslatef(-8.0, 0.0, 0.0);
    glRotatef((GLfloat)n, 0.0, 1.0, 0.0);
    glColor3f(1.0, 2.0, 0.0);
    glutSolidSphere(0.4, 20, 8);
    glPopMatrix();

}

void renderComet() {

    glPushMatrix();
    glRotatef((GLfloat)c, 6.0, -14.0, -6.0);
    glTranslatef(20, 3.0, -1.0);
    glScalef(0.60, 0.0, 2.5);
    glColor3f(7.5, 9.5, 2.0);
    glutSolidSphere(0.2, 12, 6);
    glPopMatrix();
    /*draw comet*/


}

void renderTinyStars() {

    GLfloat tiny_star_positions[20][3] = { {0.6, -1.8, 0.6},{0.4, 0.8, 0.3}, {0.8, -0.6, 0.2},{0.1, 0.7, 0.7},{0.4, -0.6, 0.0},{0.7, 0.8, 0.5},{0.6, -0.6, 0.8},{0.0, 0.3, 0.3},{0.7, 0.5, 0.1},{-0.6, -0.27, 0.4},{0.8, 0.7, 0.8},{-0.4, 1.8, 0.4},{1.8, -0.5, 1.8},{-1.8, 0.7, 0.5},{-0.4, 0.6, 0.6},{0.7, -0.7, 0.0},{0.5, -0.6, 0.5},{-0.8, -0.4, 0.7},{0.6, 0.7, 0.6},{1.0, -0.6, 0.3} };

    for (int i = 0; i < 20; i++) {
        glPushMatrix();
        glTranslatef(tiny_star_positions[i][0], tiny_star_positions[i][1], tiny_star_positions[i][2]);
        glRotatef((GLfloat)b, 0.0, 0.0, 0.0);
        glColor3f(4.3, 3.5, 1.0);
        glScalef(0.5, 0.7, 0.9);
        glutSolidSphere(0.025, 20, 8);
        glPopMatrix();
    }

}

void renderMediumStars() {

    GLfloat medium_star_positions[30][3] = { {0.7, -1.0, 0.4}, {-0.6, 0.7, 0.8},{-0.5, 0.3, 0.7},{-1.5, 1.4, 0.7},{-1.9, 3.0, 0.1},{9.0, -1.5, 0.3},{1.3, 1.2, 0.9},{0.5, 1.7, 1.8},{-0.4, 0.6, 1.6},{-1.9, 1.7, 1.4},{-1.3, -0.2, 0.8},{-0.4, 0.3, 1.7},{-0.9, -1.2, 0.4},{-1.7, 0.5, 0.6},{-1.6, -1.5, 0.7},{-0.6, 0.2, 0.2},{-0.6, -0.4, 0.1},{-0.4, -0.9, 0.8},{1.7, -0.9, 0.7},{-0.5, 1.2, 0.7},{1.9, -0.7, 0.6},{0.5, 0.7, -0.2},{1.7, -1.9, -0.4},{0.6, -0.6, -0.7},{-0.6, -0.7, -0.5},{1.9, -0.9, -0.6},{1.5, -0.4, -0.5},{2.6, -2.4, -0.8},{2.4, 2.7, -0.3},{0.6, -0.8, -0.8} };
    for (int i = 0; i < 30; i++) {
        glPushMatrix();
        glTranslatef(medium_star_positions[i][0], medium_star_positions[i][1], medium_star_positions[i][2]);
        glRotatef((GLfloat)b, 0.0, 0.0, 0.0);
        glColor3f(4.3, 3.5, 1.0);
        glutSolidSphere(0.01, 20, 8);
        glPopMatrix();
    }


}

void renderStarBackground() {

    //to put the stars as a background
    glPushMatrix();
    glTranslatef(0, 0, -1.8);
    renderTinyStars();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, -1.8);
    renderMediumStars();
    glPopMatrix();


}



void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //development camera
    //gluLookAt(camX, 10 + camY, 10 + camZ, 0, 0, 0, 0, 1, 0);
    gluLookAt( camX, 5+ camY, 40 + camZ, 0, 0, 0, 0, 1, 0);

    /* set material parameters */
    const GLfloat blue[4] = { 0.3, 0.3, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    const GLfloat matwhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, matwhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

    /* positioned the light source 1 */
    GLfloat position0[] = { 2.0,2.0,2.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position0);

    /* set light intensities for light source 1 */
    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    /* positioned the light source 2 */
    GLfloat position1[] = { -2.0,2.0,-2.0,1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    /* set light intensities for light source 2 */
    glLightfv(GL_LIGHT1, GL_DIFFUSE, paleYellow);
    GLfloat green[] = { 0.0,1.0,0.0,1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, green);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);


    glTranslatef(sceX, sceY, sceZ);
    glPushMatrix();
    //drawAxes();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    //drawGrid();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.01, 0);
    renderPlanets();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.01, 0);
    renderComet();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3, 0.01, -0.3);
    glScalef(5, 5, 5);
    renderStarBackground();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(craftRotZ, 0.0, 1.0, 0.0);
    glTranslatef(-15, 2, 9);
    glRotatef(15, 0, 1, 0);
    renderSpaceCrafts();
    glPopMatrix();

    glPushMatrix();
    glRotatef(craftRotZ, 0.0, 1.0, 0.0);
    glTranslatef(-35, 2, 9);
    glTranslatef(0, 0.01, 0);
    renderComet();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-moveHoverAfter, moveHoverAfter, 0);
    glTranslatef(-8, -6, 6);
    glScalef(0.8, 0.8, 0.8);
    renderSpaceStation(stationY, rotateY, craftMove);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, 6, 5);
    glScalef(0.1, 0.1, 0.1);
    glRotatef(refineryZ, 0, 1, 0);
    renderOilRefinery();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -issTranslate);
    glTranslatef(10,-3,5);
    renderISS(radarRotateY);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, translateExplorer);
    glTranslatef(-20, -10, -20);
    renderExplorer(rotateExporerZ);
    glPopMatrix();


    glutSwapBuffers();
    glFlush();
}

 //animation timer function
void Timer(int v) {
    craftRotZ += 2;
    refineryZ++;
    radarRotateY ++ ;
    issTranslate += 0.05;
    translateExplorer += 0.05;

    rotateExporerZ++;

    frameNumber++;

    if (craftRotZ == 360) {
        craftRotZ = 0;
    }



    if (frameNumber > 100) {
        stationY += 0.3;

        if (stationY >= 10) {
            stationY = 10;
            rotateY++;
        }

        if (rotateY >= 90) {
            rotateY = 90;
        }

        if (rotateY >= 90) {
            craftMove++;
        }

        if (craftMove >= 50) {
            moveHoverAfter += 0.08;
        }
    }
    

    

    //planets animation

    c = (c + 4) % 360;
    b = (b + 10) % 360;

    N = (N + 1) % 360;

    S = (S + 3) % 360;

    U = (U + 2) % 360;

    J = (J + 4) % 360;
    j = (j + 10) % 360;

    R = (R + 6) % 360;

    E = (E + 8) % 360;

    r = (r + 6) % 360;

    e = (e + 5) % 360;

    V = (V + 10) % 360;

    v = (v + 2) % 360;

    m = (m + 3) % 360;
    M = (M + 12) % 360;

    n = (n + 7) % 360;

    glutPostRedisplay();
    glutTimerFunc(60, Timer, 0);
}

// keyboardSpecial
void keyboardSpecial(int key, int x, int y) {
    // camera up and down
    if (key == GLUT_KEY_UP) {
        camY += 1;
    }
    if (key == GLUT_KEY_DOWN) {
        camY -= 1;
    }

    // camera left and right
    if (key == GLUT_KEY_LEFT) {
        camX -= 1;
    }
    if (key == GLUT_KEY_RIGHT) {
        camX += 1;
    }

    glutPostRedisplay();
}

// keyboard move object 
void keyboard(unsigned char key, int x, int y) {

   

    // Move Scene along X axis
    if (key == 'X') {
        sceX -= 1;
    }
    if (key == 'x') {
        sceX += 1;
    }
    // Move Scene along Y axis
    if (key == 'Y') {
        sceY -= 1;
    }
    if (key == 'y') {
        sceY += 1;
    }
    //Move Scene along Z axis
    if (key == 'Z') {
        sceZ -= 1;
    }
    if (key == 'z') {
        sceZ += 1;
    }

   

    // Control light source 1
    if (key == '1') {
        glEnable(GL_LIGHT0);
    }
    if (key == '!') {
        glDisable(GL_LIGHT0);
    }

    // Control light source 2
    if (key == '2') {
        glEnable(GL_LIGHT1);
    }
    if (key == '@') {
        glDisable(GL_LIGHT1);
    }

    if (key == 'a') {

        stationY += 0.5;

        if (stationY >= 10) {
            stationY = 10;
            rotateY++;
        }

        if (rotateY >= 90) {
            rotateY = 90;
        }

        if (rotateY >= 90) {
            craftMove++;
        }

        
    }

    glutPostRedisplay();
}


void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(50.0, aspect_ratio, 1.0, 100.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("2019/20 End Paper Question 2");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // keyboard function activation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    glutTimerFunc(200, Timer, 0);

    glutMainLoop();

    return 0;
}