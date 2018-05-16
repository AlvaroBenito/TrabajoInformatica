#include <stdlib.h>
#include "PrismaRectangular.h"
#include "glut.h"
#include "Color.h"
#include "ETSIDI.h"

int PrismaRectangular::tipoMaterial = 0;
PrismaRectangular::PrismaRectangular(Vector3D coor1, Vector3D coor2) {
	p1 = coor1;//Duda para Raquel: ¿Hace falta sobrecargar el operador "=" para igualar objetos Vector3D? La duda es porque Vector3D no tiene punteros dentro
	p2 = coor2;
}
PrismaRectangular::PrismaRectangular() {//No es necesario ya que por defecto se inicializan vectores3d a 0.
	p1.x = 0;
	p1.y = 0;
	p1.z = 0;
	p2.x = 0;
	p2.y = 0;
	p2.z = 0;

}
void PrismaRectangular::dibuja() {
	switch (tipoMaterial) {//Texturas a partir de aqui
	case 0:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Suelo.png").id);
		break;
	case 1:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Madera.png").id);
		break;
	case 100:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Lava.png").id);
	}
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);//Cara1, alzado posterior
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p1.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p1.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p1.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara2,alzado anterior
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p2.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p2.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p2.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara3,planta superior
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p2.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p2.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p2.y, p1.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara4,planta inferior
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p1.y, p2.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p1.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p1.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara5,perfil drecho
	glColor3f(0.4, 0.4, 0.4);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p1.z);
	glTexCoord2d(1, 0);	glVertex3f(p1.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p1.x, p1.y, p2.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara6,perfil izquierdo
	glColor3f(0.4, 0.4, 0.4);
	glTexCoord2d(0, 1);	glVertex3f(p2.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p2.x, p2.y, p1.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p2.z);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	/*if (p2.z < -300) {
		tipoMaterial = 1;
	}*/
}
void PrismaRectangular::dibuja2(Vector3D a, Vector3D b) {
	PrismaRectangular aux(a, b);
	aux.dibuja();
}
Vector3D PrismaRectangular::getP1() {
	return p1;
}
Vector3D PrismaRectangular::getP2() {
	return p2;
}
void PrismaRectangular::setP1_P2(Vector3D a, Vector3D b) {

}