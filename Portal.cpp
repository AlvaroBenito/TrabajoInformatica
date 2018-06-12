#include <stdlib.h>
#include "Portal.h"
#include "Plataforma.h"
#include "glut.h"
#include "ETSIDI.h"
Portal::Portal(){
	radio_int = 1;
	radio_ext = 5;
	z = -280;

}
Portal::~Portal() {

}
void Portal::dibuja() {
	int mat = PrismaRectangular::getMaterial();
	PrismaRectangular::setMaterial(3);
	PrismaRectangular::dibuja2(Vector3D(-6, 0, z + 2), Vector3D(-4, 8, z - 2));
	PrismaRectangular::dibuja2(Vector3D(-6, 10, z + 2), Vector3D(6, 8, z - 2));
	PrismaRectangular::dibuja2(Vector3D(6, 8, z - 2), Vector3D(4, 0, z + 2));
	PrismaRectangular::setMaterial(mat);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Portal1.png").id);
	glEnable(GL_BLEND); glBlendFunc(GL_ONE, GL_ONE);//Funcion para la transparencia de la textura del portal
	glDisable(GL_LIGHTING);
	glColor3f(0.5, 0.5, 0.5);//Cantidad de transparencia de la textura
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
