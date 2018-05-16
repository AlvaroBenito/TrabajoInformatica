#pragma once
#include "Moneda.h"
#include "glut.h"
#include "ETSIDI.h"




void Moneda::dibuja() {

	glColor3ub(255, 255, 0);
	glTranslatef(0, 5, -100);//(posicion.x, posicion.y, posicion.z);
	glutSolidTorus(RADIO_MONEDA_IN, RADIO_MONEDA_OUT, 20, 20);
	glTranslatef(0, -5, 100);// (-posicion.x, -posicion.y, -posicion.z);
	
}


