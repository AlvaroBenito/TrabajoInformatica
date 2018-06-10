#include <stdlib.h>
#include "Personaje.h"
#include "glut.h"
#include <stdio.h>
int Personaje::contMonedas = 0;
Personaje::Personaje():escudo(false),vidas(2),centro(true),salto(true) {
	posicion.z = -30;
	posicion.y = 1.4;
	posicion.x = 0;
	velocidad.x = 0;
	velocidad.y = 0;
	velocidad.z = -0.4;
}
void Personaje::dibuja() {
	switch (vidas) {
	case 0:
		glColor3ub(255, 0, 0);
		break;
	case 1:
		glColor3ub(255, 255, 0);
		break;
	default:
		glColor3ub(0, 255, 0);
	}
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
		velocidad.y = 0.45f;
	salto = false;
}
int Personaje::getVidas() {
	return vidas;
}
int Personaje::getContMonedas() {
	return contMonedas;
}
void Personaje::sumaMoneda(int mult) {
	contMonedas+=mult;
	printf("%d", contMonedas);
}
void Personaje::restaVida(){
	if(vidas!=0)
		vidas--;
}
void Personaje::sumaVida() {
	if (vidas < 6)
		vidas++;
}
bool Personaje::getEscudo() {
	return escudo;
}