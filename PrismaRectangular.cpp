#include <stdlib.h>
#include "PrismaRectangular.h"
#include "glut.h"
#include "Color.h"
#include "ETSIDI.h"
PrismaRectangular::PrismaRectangular(Vector3D coor1, Vector3D coor2) {
	p1 = coor1;//Duda para Raquel: ¿Hace falta sobrecargar el operador "=" para igualar objetos Vector3D? La duda es porque Vector3D no tiene punteros dentro
	p2 = coor2;
}
void PrismaRectangular::dibuja() {
											//Texturas a partir de aqui
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Suelo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);//Cara1
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p1.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p1.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p1.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara2
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p2.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p2.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p2.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara3
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p2.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p2.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p2.y, p1.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara4
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p1.y, p2.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p1.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p1.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara5
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p1.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p1.x, p2.y, p1.z);
	glTexCoord2d(1, 0);	glVertex3f(p1.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p1.x, p1.y, p2.z);
	glEnd();
	glBegin(GL_POLYGON);//Cara6
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);	glVertex3f(p2.x, p1.y, p1.z);
	glTexCoord2d(1, 1);	glVertex3f(p2.x, p2.y, p1.z);
	glTexCoord2d(1, 0);	glVertex3f(p2.x, p2.y, p2.z);
	glTexCoord2d(0, 0);	glVertex3f(p2.x, p1.y, p2.z);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}
Vector3D PrismaRectangular::getP1() {
	return p1;
}