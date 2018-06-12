#include "Interaccion.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
bool Interaccion::reboteSuelo(PrismaRectangular suelo, Personaje &p) {
	if (p.posicion.y < suelo.p2.y+0.5f) {//Cuando se detecta impacto con el suelo
		p.velocidad.y = 0;
		p.posicion.y = suelo.p2.y + 0.5f;
		p.salto = true;//Se permite solo saltar cuando el personaje está en el suelo (No hay dobles saltos)
		return true;
	}
	
	return false;
}
bool Interaccion::mueveCentro(PrismaRectangular suelo, Personaje &p) {//De esta forma cuando se pulsa una tecla para moverse a un lado
																      //Solo se mueve la distancia de un carril
	if (p.posicion.x < suelo.p1.x+0.6f &&p.posicion.x>suelo.p1.x+0.4f&& p.centro == false) {//se coloca la bola entre un espacio de 0.2 en el carril central
		p.velocidad.x = 0;
		p.centro = true;//Variable que permite el control de si el personaje está en el carril central o no
		return true;
	}
	return false;
}
bool Interaccion::choqueParedes(PrismaRectangular paredDer,PrismaRectangular paredIzq, Personaje &p) {
	if (p.posicion.x > paredDer.p1.x - 0.5f) {
		p.posicion.x = paredDer.p1.x - 0.5f;
		p.velocidad.x = 0.0f;
		p.centro = false;//Cuando p.centro=False, la proxima vez que se cambie de carril, se quedará el personaje en el carril central
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
	if (p.getPos().z <  mon.getPos().z+1 && p.getPos().z >  mon.getPos().z-1) {//Consideramos una hitbox de 2 de profundidad para
		if ((int)p.getPos().x == (int)mon.getPos().x) {						   //coger la moneda
			if (fabsf(p.getPos().y-mon.getPos().y)<0.7) {
				p.sumaMoneda(mon.getPuntos());//se suman los puntos que valga la moneda al contador de monedas
				return true;
			}
		}
	}
	return false;
}

bool Interaccion::reboteObstaculo(PrismaRectangular *obstaculo, Personaje &p) {
	if ((obstaculo->getP1().z+1 > p.posicion.z && p.posicion.z > obstaculo->getP2().z-1) && (p.posicion.y < obstaculo->getP2().y))
		return true;//Al igual que con las monedas, la hitbox es de 2 de profundidad
	return false;
}

bool Interaccion::reboteObstaculo(ListaObstaculos obstaculos, Personaje &p) {
	for (int i = 0; i < obstaculos.numero; i++) {
		if (Interaccion::reboteObstaculo(obstaculos.lista[i], p)) {
			if (obstaculos.lista[i]->impacto == false) {
				if (p.escudo == false) {
					ETSIDI::play("Sound/Hurt.mp3");
					p.restaVida();
				}
				obstaculos.lista[i]->impacto = true;//Una vez es true, ya no hay mas colisiones con dicho obstaculo
				obstaculos.lista[i]->p1.z += 50;//Mueve el obstaculo hacia atrás para que destructorObstaculos lo destruya
				obstaculos.lista[i]->p2.z += 50;
			}
			return true;
		}
	}
	return 0;
}
bool Interaccion::condicionDibujo(Plano *p, PrismaRectangular *o) {//Funcion para evitar que se creen trampas en el mismo sitio que los
	if (abs(o->p1.z - p->limite1.z) < 10) {						   //Obstaculos, eliminando dichas trampas si se crearan
		p->limite1.z = 0;
		p->limite2.z = 0;
		return true;
	}
	return false;
}
bool Interaccion::condicionDibujo(ListaTrampas &t, ListaObstaculos o) {//Ejecuta la funcion anterior para todas las trampas y todos los
	for (int i = 0; i < t.numero; i++) {							   //Obstaculos
		for (int j = 0; j < o.numero; j++) {
			condicionDibujo(t.lista[i], o.lista[j]);
		}
	}
	return true;
}
bool Interaccion::colisionTrampas(Plano *plano, Personaje &p) {//Metodo para calcular la colision con las trampas
	if (plano->limite1.z > p.posicion.z && plano->limite2.z < p.posicion.z) {
		if (abs(p.posicion.y - plano->limite1.y) < 1.0f) {
			if (p.posicion.x > plano->limite1.x && p.posicion.x < plano->limite2.x) {
				if (plano->impacto == false) {
					if (p.escudo == false) {
						ETSIDI::play("Sound/Hurt.mp3");
						p.restaVida();
					}
				}
				plano->impacto = true;//Variable para evitar varios impactos con la misma trampa
			}
		}
	}
	return true;
}
bool Interaccion::colisionTrampas(ListaTrampas t, Personaje &p) {//Metodo para comprobar todas las posibles colisiones con las trampas
	for (int i = 0; i < t.numero; i++)
		colisionTrampas(t.lista[i], p);
	return true;
}
bool Interaccion::cogeBonus(Bonus *bon, Personaje &p) {//Metodo para coger los bonus
	if (bon->p1.z > p.posicion.z && bon->p2.z < p.posicion.z) {//Condicion eje z
		if (bon->p1.y < p.posicion.y && bon->p2.y > p.posicion.y) {//Condicion eje y
			if (bon->p1.x < p.posicion.x&& bon->p2.x > p.posicion.x) {//Condicion eje x
				if (bon->tipo) {
					p.sumaVida();
					ETSIDI::play("Sound/Vida.wav");
					return true;
				}
				else {
					ETSIDI::play("Sound/Escudo.mp3");
					p.escudo = true;
					return true;
				}
			}
		}
	}
	if (bon->p1.z-20 > p.getPos().z)
		return true;
	return false;
}
bool Interaccion::redibujaMon(Moneda *mon, PrismaRectangular *o) {//Metodo para que las monedas no se dibujen dentro de los obstaculos
	if (abs(mon->posicion.z - o->p1.z) < 10.0f) {				  //Y se dibujen encima de ellos con una forma parecida a una parabola
		mon->posicion.y = 3.0f- abs(mon->posicion.z - o->p1.z)/10;
		return true;
	}
	return false;
}
bool Interaccion::redibujaMon(ListaMonedas mon, ListaObstaculos obs) {//Comprobacion del metodo anterior con todas las monedas y obstaculos
	for (int i = 0; i < mon.numero; i++) {
		for (int j = 0; j < obs.numero; j++) {
			redibujaMon(mon.lista[i], obs.lista[j]);
		}
	}
	return true;
}