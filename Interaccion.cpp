#include "Interaccion.h"
bool Interaccion::reboteSuelo(PrismaRectangular suelo, Personaje &p) {
	if (p.posicion.y < suelo.p2.y+0.5) {
		p.velocidad.y /= -2 ;
		return true;
	}
	return false;
}