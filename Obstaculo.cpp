#include "Obstaculo.h"
#include "glut.h"
#include "ETSIDI.h"

//Estos son los dos vectores que de definen la creacion de un obstaculo: despues con setPosZ lo fijaremos donde queramos
//Vector3D lim1(Elemento::posicion.x-1, 0, 0);
//Vector3D lim2(1, 1, lim1.z-1);

Obstaculo::Obstaculo()
{
}

Obstaculo::Obstaculo(float coordz) :PrismaRectangular(Vector3D(posicion.x-4,posicion.y,coordz), Vector3D(posicion.x+4,posicion.y+2,coordz-1)) {
	//setPosZ(coordz);
}


	/*void Obstaculo::dibuja() {
		switch (tipoMaterial) {//Texturas a partir de aqui
		case 0:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Suelo.png").id);
			break;
		case 1:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Madera.png").id);
			break;
		case 10:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/MetalNegro.png").id);
			break;
		case 100:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Lava.png").id);
			break;
		case 1000:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imag/Portal1.png").id);
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
}*/

Obstaculo::~Obstaculo()
{
}

