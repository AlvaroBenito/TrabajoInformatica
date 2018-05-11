#pragma once
#include "Moneda.h"
#include "glut.h"

Moneda::Moneda(){
	radio=2.0f;

}

Moneda::~Moneda() {

}

void Moneda::dibuja() {

	glColor3ub(100, 255, 0);
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, -posicion.z);
}

