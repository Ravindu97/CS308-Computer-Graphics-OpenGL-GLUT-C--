#include "spaceCraftHeader.h"
#include<GL/glut.h>
#include<math.h>

#define pi 3.142857



void drawCircle(float radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2 * pi / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void drawCylinder(float r, float h) {
	glPushMatrix();
	//glColor3f(1, 1, 0);
	glTranslatef(0, 0, -h / 2);
	glPushMatrix();
	GLUquadricObj* qaudratic;
	qaudratic = gluNewQuadric();
	gluCylinder(qaudratic, r, r, h, 100, 100);
	drawCircle(r);
	glTranslatef(0, 0, h);
	drawCircle(r);
	glPopMatrix();
	glPopMatrix();

}

void drawSphere(double r) {
	glPushMatrix();
	//glColor3f(1, 1, 0);
	glutSolidSphere(r, 100, 100);
	glPopMatrix();
}


void draw_cylinder(GLfloat radius,
	GLfloat height)
{
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	/** Draw the tube */
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();


}

void drawEngine() {

	glPushMatrix();

	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0, 0, -0.9);
	draw_cylinder(0.8, 1.8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.0, 0.0);
	glTranslatef(0, 0, -0.9);
	draw_cylinder(0.2, 1.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0.9);
	glColor3f(0.1, 0.0, 0.0);
	glutSolidCone(0.1, 0.6, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1, 1.8, 1.6);
	glColor3f(0.1, 0.0, 0.0);
	glutSolidCube(0.8);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(0.1, 1.8, 1.6);
	glColor3f(0.1, 0.0, 0.0);
	glutSolidCube(0.8);
	glPopMatrix();


	glPopMatrix();
}

void drawMissles() {

	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0, 0, -1.25);
	draw_cylinder(0.3, 2.5);
	
	glColor3f(0.9, 0.9, 0.0);
	glTranslatef(0,0,2.0);
	glScalef(0.29, 0.5, 1.0);
	for (int i = 0; i < 6; i++) {
		glRotatef(360 / 6, 0, 0, 1);
		glutSolidCube(1);
	}

	glColor3f(0.6, 0.0, 1.0);
	glTranslatef(0, 0, 0.6);
	draw_cylinder(0.2, 4.0);

	glPopMatrix();
}



void renderWing() {

	glPushMatrix();
	glTranslatef(-4, 0, 0);
	glScalef(8, 0.25, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8, 0, 0);
	glRotatef(30, 0, 0, 1);
	drawMissles();
	glPopMatrix();

}

void renderShipBody() {
	glPushMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);
	glEnable(GL_CLIP_PLANE3);
	double planeEquation[] = { 0.0, -10.0, -1.0, 25.0 };
	double planeEquation1[] = { -10.0, 0.0, -1.0, 15.0 };
	double planeEquation2[] = { 0.0, 10.0, -1.0, 25.0 };
	double planeEquation3[] = { 10.0, 0.0, -1.0, 15.0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);
	glClipPlane(GL_CLIP_PLANE2, planeEquation2);
	glClipPlane(GL_CLIP_PLANE3, planeEquation3);

	glScalef(4, 6, 20);
	glutSolidCube(1);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glDisable(GL_CLIP_PLANE3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 3, -5);
	glVertex3f(-2, -3, -5);
	glVertex3f(-0.5, -1.5, 10);
	glVertex3f(-0.5, 1.5, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(2, 3, -5);
	glVertex3f(2, -3, -5);
	glVertex3f(0.5, -1.5, 10);
	glVertex3f(0.5, 1.5, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2, 3, -5);
	glVertex3f(2, 3, -5);
	glVertex3f(0.5, 1.5, 10);
	glVertex3f(-0.5, 1.5, 10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-2, -3, -5);
	glVertex3f(2, -3, -5);
	glVertex3f(0.5, -1.5, 10);
	glVertex3f(-0.5, -1.5, 10);
	glEnd();
	glPopMatrix();

	glPopMatrix();

}


void renderSpaceCraft() {

	
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 4);
	glScalef(0.5, 0.5, 0.5);
	renderShipBody();
	glPopMatrix();
	

	glPushMatrix();

	glTranslatef(-2, 0, 0);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	drawEngine();
	glPopMatrix();

	//left bottom
	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	renderWing();
	glPopMatrix();


	//left top
	glPushMatrix();
	glRotatef(-30, 0, 0, 1);
	renderWing();
	glPopMatrix();

	glPopMatrix();


	
	glPushMatrix();

	glTranslatef(2, 0, 0);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	drawEngine();
	glPopMatrix();

	//right top
	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glRotatef(30, 0, 0, 1);
	renderWing();
	glPopMatrix();


	//right bottom
	glPushMatrix();
	glRotatef(150, 0, 0, 1);
	renderWing();
	glPopMatrix();

	glPopMatrix();
	
	glPopMatrix();
}




void renderSpaceCrafts() {

	//leftTop wing
	
	glPushMatrix();
	glScalef(0.15, 0.15, 0.15);
	renderSpaceCraft();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.8, 0, 0);
	glScalef(0.15, 0.15, 0.15);
	renderSpaceCraft();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.8, 0, 0);
	glScalef(0.15, 0.15, 0.15);
	renderSpaceCraft();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 2.8);
	glScalef(0.15, 0.15, 0.15);
	renderSpaceCraft();
	glPopMatrix();

}