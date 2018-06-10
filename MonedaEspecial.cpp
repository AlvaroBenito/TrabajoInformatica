#include <stdlib.h>
#include "MonedaEspecial.h"
#include "glut.h"
#include "ETSIDI.h"
MonedaEspecial::MonedaEspecial(float posx, float posy, float posz, float vel):Moneda(posx,posy,posz,vel) {
	puntos = 5;
}
void MonedaEspecial::dibuja() {
	int rojo=ETSIDI::lanzaDado(255);
	int verde=ETSIDI::lanzaDado(255);
	int azul=ETSIDI::lanzaDado(255);
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glRotatef(3*anguloRotacion, 1, 1, 1);
	glutSolidTorus(1.5*RADIO_MONEDA_IN, 1.5*RADIO_MONEDA_OUT, 20, 20);
	glRotatef(3*-anguloRotacion, 1, 1, 1);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}