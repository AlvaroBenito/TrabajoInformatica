#pragma once
#include "Moneda.h"
#include "glut.h"
#include "ETSIDI.h"




void Moneda::dibuja() {

	glColor3ub(255, 255, 0);
	glTranslatef(0, 1.7, -100);//(posicion.x, posicion.y, posicion.z);
	glRotatef(anguloRotacion, 0, 1, 0);
	glutSolidTorus(RADIO_MONEDA_IN, RADIO_MONEDA_OUT, 20, 20);
	glTranslatef(0, -1.7, 100);// (-posicion.x, -posicion.y, -posicion.z);
	
}


void Moneda::rotar(float t){

	anguloRotacion += t;
}