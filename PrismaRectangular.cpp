#include "PrismaRectangular.h"
#include "glut.h"
#include "Color.h"
PrismaRectangular::PrismaRectangular(Vector3D coor1, Vector3D coor2) {
	p1 = coor1;//Duda para Raquel: ¿Hace falta sobrecargar el operador "=" para igualar objetos Vector3D? La duda es porque Vector3D no tiene punteros dentro
	p2 = coor2;
}
void PrismaRectangular::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(255, 0,0);
	glBegin(GL_POLYGON);//Cara 1, alzado posterior
		glVertex3f(p1.x,p1.y,p1.z);
		glVertex3f(p1.x,p2.y,p1.z);
		glVertex3f(p2.x,p2.y,p1.z);
		glVertex3f(p2.x,p1.y,p1.z);
	glEnd();
	glColor3ub(255, 255, 0);
	glBegin(GL_POLYGON);//Cara 2, alzado anterior
		glVertex3f(p1.x, p1.y, p2.z);
		glVertex3f(p1.x, p2.y, p2.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glVertex3f(p2.x, p1.y, p2.z);
	glEnd();
	glColor3ub(255, 0,255);
	glBegin(GL_POLYGON);//Cara 3, planta alta
		glVertex3f(p1.x, p2.y, p1.z);
		glVertex3f(p1.x, p2.y, p2.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glVertex3f(p2.x, p2.y, p1.z);
	glEnd();
	glColor3ub(0, 100,255);
	glBegin(GL_POLYGON);//Cara 4, planta baja
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p1.x, p1.y, p2.z);
		glVertex3f(p2.x, p1.y, p2.z);
		glVertex3f(p2.x, p1.y, p1.z);
	glEnd();
	glColor3ub(100, 100, 100);
	glBegin(GL_POLYGON);//Cara 5, perfil derecho
		glVertex3f(p1.x, p1.y, p1.z);
		glVertex3f(p1.x, p2.y, p1.z);
		glVertex3f(p1.x, p2.y, p2.z);
		glVertex3f(p1.x, p1.y, p2.z);
	glEnd();
	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);//Cara 6, perfil izquierdo
		glVertex3f(p2.x, p1.y, p1.z);
		glVertex3f(p2.x, p2.y, p1.z);
		glVertex3f(p2.x, p2.y, p2.z);
		glVertex3f(p2.x, p1.y, p2.z);
	glEnd();
	glEnable(GL_LIGHTING);
}
Vector3D PrismaRectangular::getP1() {
	return p1;
}