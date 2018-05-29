#include "Interaccion.h"
#include <math.h>
#include <stdio.h>
bool Interaccion::reboteSuelo(PrismaRectangular suelo, Personaje &p) {
	if (p.posicion.y < suelo.p2.y+0.5f) {
		p.velocidad.y = 0;
		p.posicion.y = suelo.p2.y + 0.5f;
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
bool Interaccion::cogerMoneda(Moneda mon, Personaje &p) {
	if (p.getPos().z <  mon.getPos().z+1 && p.getPos().z >  mon.getPos().z-1) {//-2 para que la interaccion de cogerla sea mas fluida
		if ((int)p.getPos().x == (int)mon.getPos().x) {
			if (fabsf(p.getPos().y-mon.getPos().y)<0.7) {
				p.sumaMoneda();
				return true;
			}
		}
	}
	return false;
}

bool Interaccion::reboteObstaculo(Obstaculo *obstaculo, Personaje &p) {
	if ((obstaculo->getP1().z > p.posicion.z && p.posicion.z > obstaculo->getP2().z) && (p.posicion.y+RADIO_MONEDA_OUT < obstaculo->getP2().y))
		return true;
	return false;
}

bool Interaccion::reboteObstaculo(ListaObstaculos obstaculos, Personaje &p) {
	for (int i = 0; i < obstaculos.numero; i++) {
		if (Interaccion::reboteObstaculo(obstaculos.lista[i], p)) {
			p.restaVida();
			p.posicion.y = 10;//Es Para comprobar que detecta el choque con el obstaculo.
			return true;
		}
	}
	return 0;
}
