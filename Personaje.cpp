#include "Personaje.h"
#include "glut.h"
Personaje::Personaje():escudo(false),contMonedas(0),vidas(2),centro(true) {
	posicion.z = -30;
	posicion.y = 3.9;
	posicion.x = 0;
	velocidad.x = 0;
	velocidad.y = -0.1;
	velocidad.z = -0.4;
}
void Personaje::dibuja() {
	glColor3ub(255, 255, 0);
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glutSolidSphere(0.4, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}
void Personaje::gira(bool der){//Der=true->gira derecha, Der=false->gira izquierda
	if (der) {
		velocidad.x = 0.2f;
	}
	else
		velocidad.x = -0.2f;
}
void Personaje::salta() {
	if(salto==true)
		velocidad.y = 0.6f;
	salto = false;
}