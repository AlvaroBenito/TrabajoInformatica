#include <stdlib.h>
#include "Portal.h"
#include "Plataforma.h"
#include "glut.h"
#include "ETSIDI.h"
Portal::Portal(){
	radio_int = 1;
	radio_ext = 5;
	z = -280;
	rojo = 0;
	azul = 0;
}
Portal::~Portal() {

}
void Portal::dibuja() {
	int mat = PrismaRectangular::getMaterial();
	Vector3D aux1(-6, 0, z + 2);
	Vector3D aux2(-4, 8, z - 2);
	Vector3D aux3(-6, 10, z + 2);
	Vector3D aux4(6, 8, z - 2);
	Vector3D aux5(4, 0, z + 2);
	PrismaRectangular auxiliar;
	PrismaRectangular::setMaterial(3);
	auxiliar.dibuja2(aux1, aux2);
	auxiliar.dibuja2(aux3, aux4);
	auxiliar.dibuja2(aux4, aux5);
	PrismaRectangular::setMaterial(mat);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Portal1.png").id);
	glEnable(GL_BLEND); glBlendFunc(GL_ONE, GL_ONE);//Funcion para la transparencia de la textura del portal
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(4,0,z);
	glTexCoord2d(1, 1); glVertex3f(4,8,z);
	glTexCoord2d(1, 0); glVertex3f(-4,8,z);
	glTexCoord2d(0, 0); glVertex3f(-4,0,z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
}