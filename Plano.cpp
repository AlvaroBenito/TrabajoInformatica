#include <stdlib.h>
#include "Plano.h"
#include "glut.h"
#include "ETSIDI.h"

Plano::Plano(){

}

Plano::Plano(Vector3D coor1, Vector3D coor2) {
	limite1 = coor1;
	limite2 = coor2;
	tipoMaterial = 0;
}

void Plano::setMaterial(int t) {
	tipoMaterial = t;
}



void Plano::dibuja() {


	switch (tipoMaterial) {//Texturas a partir de aqui
	case 0:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Portal1.png").id);
		break;
	case 10:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Lava.png").id);
		break;
	
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(limite1.x, limite1.y, limite1.z);
	glTexCoord2d(1, 1);	glVertex3f(limite1.x, limite1.y, limite2.z);
	glTexCoord2d(1, 0); glVertex3f(limite2.x, limite1.y, limite2.z);
	glTexCoord2d(0, 0); glVertex3f(limite2.x, limite1.y, limite1.z);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	return;
}