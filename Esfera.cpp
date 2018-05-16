

#include "Esfera.h"
#include "glut.h"


Esfera::Esfera()
{
	radio = 1.0f;
	aceleracion.y = -9.8f;
	velocidad.x = 4;
	velocidad.y = 4;
}

Esfera::~Esfera()
{

}

void Esfera::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Esfera::mueve(float t)
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}
void Esfera::setColor(int r, int v, int a) {

	rojo = r;
	verde = v;
	azul = a;

}
void Esfera::setRadio(float r)
{
	if(r<0.1F)
		r=0.1F;
	radio=r;
}	

void Esfera::setPos(float ix,float iy)
{
	posicion.x=ix;
	posicion.y=iy;
}

void Esfera::setVel(float vx, float vy)
{
	velocidad.x=vx;
	velocidad.y=vy;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	rojo = verde = 255;
	azul = 100; //color distinto 
	aceleracion.y = -9.8;
}