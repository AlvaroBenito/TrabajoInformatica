#include "Plano.h"

Plano::Plano(){

}

Plano::Plano(Vector3D coor1, Vector3D coor2):impacto(false) {
	limite1 = coor1;
	limite2 = coor2;
	tipoMaterial = 0;
}




void Plano::dibuja() {


	switch (tipoMaterial) {//Texturas a partir de aqui
	case 0:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Mar.png").id);
		break;
	case 10:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/LavaBrillante.png").id);
		break;
	case 20:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Corazon.png").id);
		break;
	}
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(limite1.x, limite1.y, limite1.z);
	glTexCoord2d(1, 1);	glVertex3f(limite1.x, limite2.y, limite2.z);
	glTexCoord2d(1, 0); glVertex3f(limite2.x, limite2.y, limite2.z);
	glTexCoord2d(0, 0); glVertex3f(limite2.x, limite1.y, limite1.z);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	return;
}
