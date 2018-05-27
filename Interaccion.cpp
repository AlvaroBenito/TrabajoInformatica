#include "Interaccion.h"
#include <stdio.h>
bool Interaccion::reboteSuelo(PrismaRectangular suelo, Personaje &p) {
	if (p.posicion.y < suelo.p2.y+0.5f) {
		p.posicion.y = suelo.p2.y+0.5f ;
		p.salto = true;
		return true;
	}
	
	return false;
}
bool Interaccion::mueveCentro(PrismaRectangular suelo, Personaje &p) {
	if (p.posicion.x < suelo.p1.x+0.6f &&p.posicion.x>suelo.p1.x+0.4f&& p.centro == false) {//se coloca la bola entre un espacio de 0.2 en el carril central
		p.velocidad.x = 0;
		p.centro = true;
		return true;
	}
	return false;
}
bool Interaccion::choqueParedes(PrismaRectangular paredDer,PrismaRectangular paredIzq, Personaje &p) {
	if (p.posicion.x > paredDer.p1.x - 0.5f) {
		p.posicion.x = paredDer.p1.x - 0.5f;
		p.velocidad.x = 0.0f;
		p.centro = false;
		return true;
	}
	if (p.posicion.x < paredIzq.p1.x + 0.5f) {
		p.posicion.x = paredIzq.p1.x + 0.5f;
		p.velocidad.x = 0.0f;//Se resetea la velocidad para que no entre constantemente en el bucle y tenga que rectificar la posicion
		p.centro = false;
		return true;
	}
	
	return false;
}