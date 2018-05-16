

#include "Hombre.h"
#include "glut.h"


Hombre::Hombre()
{
	altura=1.8f;
}

Hombre::~Hombre()
{

}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);
	glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(altura, 20, 20);
	glPopMatrix();

}

void Hombre::mueve(float t)
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}
void Hombre::setVel(float vx, float vy)
{
	velocidad.x=vx;
	velocidad.y=vy;
}

float Hombre::getAltura() {
	return altura;
}

Vector2D Hombre::getPos() {
	return posicion;
}