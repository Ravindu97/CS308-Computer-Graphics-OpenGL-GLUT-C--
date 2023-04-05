#include "spaceCraftHeader.h"
#include<GL/glut.h>
#include<math.h>

#define pi 3.142857



void renderSimpleSpaceStation() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();

	glRotatef(-90, 1, 0, 0);


	//render engines

	glPushMatrix();
	glTranslatef(2, -2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, 2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, -2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	drawCylinder(0.1, 3.5);
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	drawCylinder(0.1, 3.5);
	glPopMatrix();


	glPushMatrix();
	glScalef(8, 8, 8);
	glColor4f(0.9, 0.7, 0.0, 0.5);
	glutSolidTorus(0.08, 0.3, 25, 25);
	glPopMatrix();

	glPopMatrix();
}


void renderSpaceStation(float stationY , float rotateY , float craftMove) {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();

	glRotatef(-90, 1, 0, 0);


	//render spaceCrafts
	glPushMatrix();
	glTranslatef(craftMove, 0, 0);
	glRotatef(rotateY, 0, 1, 0);
	glTranslatef(0, 0, stationY);
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(8, 0, -10);
	glRotatef(90, 0, 0, 1);
	renderSpaceCraft();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-craftMove, 0, 0);
	glRotatef(-rotateY, 0, 1, 0);
	glTranslatef(0, 0, stationY);
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(-8, 0, -10);
	glRotatef(90, 0, 0, 1);
	renderSpaceCraft();
	glPopMatrix();


	//render engines

	glPushMatrix();
	glTranslatef(2, -2,0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, 2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, -2, 0);
	glScalef(0.7, 0.7, 0.7);
	drawEngine();
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	drawCylinder(0.1, 3.5);
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	drawCylinder(0.1, 3.5);
	glPopMatrix();


	glPushMatrix();
	glScalef(8, 8, 8);
	glColor4f(0.9, 0.7, 0.0, 0.5);
	glutSolidTorus(0.08, 0.3, 25, 25);
	glPopMatrix();

	glPopMatrix();

}


void renderOilRefinery() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 3.5, 0);
	drawCylinder(0.15, 25);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glColor4f(1.0, 1.0, 1.0, 0.5);
	glTranslatef(0,3.5,0);
	drawCylinder(0.15, 25);
	glPopMatrix();


	glPushMatrix();
	glColor4f(0.6, 0.1, 1.0, 0.8);
	glScalef(3, 0.9, 2);
	glTranslatef(0, 3.8, 0);
	glutSolidSphere(2, 60, 60);
	glPopMatrix();


	glPushMatrix();
	glColor4f(0.6, 0.7, 0.9, 0.8);
	glRotatef(90, 1, 0, 0);
	drawCylinder(2, 4.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.9, 0.8, 0.0, 0.8);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, 3);
	drawCylinder(1, 3.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.9, 0.8, 0.0, 0.8);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -7);
	drawCylinder(0.5, 3.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.6, 0.1, 1.0, 0.8);
	glScalef(1.5, 0.7, 1.5);
	glTranslatef(0, 7, 0);
	glutSolidSphere(2, 60, 60);
	glPopMatrix();

}

// draw cylinder
void cylinder(float br, float tr, float h, int slices) {
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, br, tr, h, slices, 1);

}

// draw cylinder with caps
void cylinderWithCap(float br, float tr, float h, int slices) {
	cylinder(br, tr, h, slices);
	float x = 0.0;
	float y = 0.0;
	float angle = 0.0;
	float angle_stepsize = 0.1;

	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = tr * cos(angle);
		y = tr * sin(angle);
		glVertex3f(x, y, h);
		angle = angle + angle_stepsize;
	}
	glVertex3f(tr, 0.0, h);
	glEnd();

	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = br * cos(angle);
		y = br * sin(angle);
		glVertex3f(x, y, 0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(br, 0.0, 0);
	glEnd();
}

//create antena bars
void anternaBars() {

	glPushMatrix();
	glTranslatef(0, 1.8, 0);
	glScalef(0.2, 3, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}

//create antena sphere
void antenaSphere() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//left bar
	glColor4f(0.2, 0.1, 0.5, 0.8);

	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	glRotatef(-30, 0, 0, 1);
	anternaBars();
	glPopMatrix();

	//right bar
	glPushMatrix();
	glTranslatef(1.5, 0, 0);
	glRotatef(30, 0, 0, 1);
	anternaBars();
	glPopMatrix();

	//top square
	glPushMatrix();
	glTranslatef(0, 2.8, 0);
	glutSolidSphere(0.4, 10, 10);
	glPopMatrix();


	//create clipped sphere
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glScalef(3, 1, 3);
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);

	double planeEquation[] = { 0.0, -1.0, 0.0, -0.6 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glutSolidSphere(1, 20, 20);

	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();


}


void antenaHandle() {

	//angle bar
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 2, 0);
	glRotatef(-30, 0, 0, 1);
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.2, 0.2, 1, 20);
	glPopMatrix();

	//joint
	glPushMatrix();
	glTranslatef(0, 2, -0.2);
	cylinderWithCap(0.2, 0.2, 0.4, 20);
	glPopMatrix();


	//bottom bar
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	cylinderWithCap(0.2, 0.2, 2, 20);
	glPopMatrix();

}

//create radar antena
void radarAntena() {

	antenaHandle();

	glPushMatrix();
	glTranslatef(0.5, 2.5, 0);
	glRotatef(-30, 0, 0, 1);
	antenaSphere();
	glPopMatrix();

}




void renderSolarArray() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();

	glPushMatrix();
	glColor4f(0.2, 0.1, 0.5, 0.8);
	glTranslatef(3.0, 0, -1.2);
	glScalef(1, 0.2, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.2, 0.1, 0.5, 0.8);
	glTranslatef(1.5, 0, -1.2);
	glScalef(1, 0.2, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.2, 0.1, 0.5, 0.8);
	glTranslatef(-1.5, 0, -1.2);
	glScalef(1, 0.2, 2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glColor4f(0.2, 0.1, 0.5, 0.8);
	glTranslatef(0, 0, -1.2);
	glScalef(1, 0.2, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}




void renderCapsule() {

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();


	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.0, 0, 5.5);
	drawCylinder(2.0, 4.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.2, 0.1, 0.5, 0.8);
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.0, 0, 2.8);
	drawCylinder(2.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glRotatef(90, 0, 1, 0);
	drawCylinder(2.0, 4.0);
	glPopMatrix();

	glPopMatrix();


}

void renderSolarPanel() {

	
	glPushMatrix();
	renderSolarArray();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 2.5);
	renderSolarArray();
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0, 1.0, 1.0, 0.8);
	glRotatef(90, 0, 1, 0);
	glScalef(0.1, 0.1, 2);
	drawCylinder(1, 3.0);
	glPopMatrix();

	

}

void renderISS(float radarRotateY) {

	
	glPushMatrix();
	glRotatef(radarRotateY, 0, 1, 0);
	glScalef(0.5, 0.5, 0.5);
	radarAntena();
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(-4, 0, 0);
	glScalef(0.4, 0.4, 0.4);
	renderCapsule();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(1, 0, 0);

	glPushMatrix();
	glTranslatef(4.5, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(-45, 1, 0, 0);
	renderSolarPanel();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);
	renderCapsule();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glScalef(0.4, 0.4, 0.4);
	renderCapsule();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);

	glPushMatrix();
	glTranslatef(4.5, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(45, 1, 0, 0);
	renderSolarPanel();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);
	renderCapsule();
	glPopMatrix();

	glPopMatrix();
}

void renderExplorer(float rotateExporerZ) {

	glPushMatrix();
	glRotatef(90, 1, 0, 0);

	glPushMatrix();
	glRotatef(rotateExporerZ, 0, 1, 0);
	renderSimpleSpaceStation();
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glScalef(0.4, 0.4, 0.4);
	renderCapsule();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(3.5, 2.7, 0);
	renderSolarPanel();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, 2.7, 0);
	glRotatef(180, 0, 1, 0);
	renderSolarPanel();
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glTranslatef(-3, 0, 0);
	glScalef(0.4, 0.4, 0.4);
	renderCapsule();
	glPopMatrix();

	glPopMatrix();

}