#include <stdlib.h>
#include "PrismaRectangular.h"
#include "glut.h"
#include "ETSIDI.h"

int PrismaRectangular::tipoMaterial = 0;
PrismaRectangular::PrismaRectangular(Vector3D coor1, Vector3D coor2):impacto(false) {
	p1 = coor1; 
	p2 = coor2;
}
PrismaRectangular::PrismaRectangular():impacto(false) {//No es necesario ya que por defecto se inicializan vectores3d a 0.
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
	case 2:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/MetalNegro.png").id);
		break;
	case 3:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Lava.png").id);
		break;
	case 4:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Portal1.png").id);
		break;
	case 10:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Corazon.png").id);
		break;
	case 11:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Escudo.png").id);
		break;
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
	
}
void PrismaRectangular::dibuja2(Vector3D a, Vector3D b) {
	PrismaRectangular aux(a, b);
	aux.dibuja();
}

