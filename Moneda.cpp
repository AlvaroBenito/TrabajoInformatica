#pragma once
#include "Moneda.h"
#include "glut.h"
#include "ETSIDI.h"




void Moneda::dibuja() {

	glColor3ub(255, 255, 0);
	glTranslatef(posicion.x, 1.7, posicion.z);
	glRotatef(anguloRotacion, 0, 1, 0);
	glutSolidTorus(RADIO_MONEDA_IN, RADIO_MONEDA_OUT, 20, 20);
	glRotatef(-anguloRotacion, 0, 1, 0);
	glTranslatef(-posicion.x, -1.7, -posicion.z);
	
}

Moneda::Moneda(){

}


void Moneda::rotar(float t){

	anguloRotacion += t;
}

Moneda::Moneda(float posx, float posy, float posz, float vel) {
	posicion.x = posx;
	posicion.y = posy;
	posicion.z = posz;
	velocidad = vel;

}

void Moneda::setPos(Vector3D pos) {

	posicion = pos;
}