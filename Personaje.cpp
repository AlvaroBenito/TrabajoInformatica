#include <stdlib.h>
#include "Personaje.h"
#include "glut.h"
#include <stdio.h>
int Personaje::contMonedas = 0;
Personaje::Personaje():escudo(false),vidas(2),centro(true) {
	posicion.z = -30;
	posicion.y = 1.4;
	posicion.x = 0;
	velocidad.x = 0;
	velocidad.y = 0;
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
int Personaje::getVidas() {
	return vidas;
}
int Personaje::getContMonedas() {
	return contMonedas;
}
void Personaje::sumaMoneda() {
	contMonedas++;
	printf("%d", contMonedas);
}