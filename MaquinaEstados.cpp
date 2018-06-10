#pragma once
#include <stdlib.h>
#include "MaquinaEstados.h"
#include "ETSIDI.h"
MaquinaEstados::MaquinaEstados() {
	estado = INICIO;
	mundo = new Mundo;
	ETSIDI::playMusica("Sound/Caverna.ogg", true);
}


void MaquinaEstados::dibuja() {
	if (estado == INICIO){//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
			gluLookAt(0, 7.5,30,  // posicion del ojo 
				0.0, 7.5, 0.0,      // hacia que punto mira  (0,7.5,0)  
				0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

			
			mundo->inicializa();
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("Fuentes/Bitwise.ttf", 30);
			ETSIDI::printxy("INFINITE RUN", -3, 15);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("Fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -3, 10);
			ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -3, 5);
			ETSIDI::printxy("Rock BenitoPolla Stars Games", 2, 1);
	}

	else if (estado == JUEGO){
		ETSIDI::stopMusica();
		mundo->dibuja();
		if (mundo->getPers().getVidas() == 0) {
			estado = GAMEOVER;
			ETSIDI::playMusica("Sound/Caverna.ogg", true);
		}
		}

	else    if (estado == GAMEOVER)
	{
		/*gluLookAt(mundo->getOjo().x, mundo->getOjo().y, mundo->getOjo().z,  // posicion del ojo 
			0.0, mundo->getZapunta(), 0.0,      // hacia que punto mira  (0,7.5,0)  
			0.0, 1.0, 0.0);*/
		mundo->dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("Fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -3, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -3, 5);
	}
	else if (estado == PAUSA)
		 {
		/*gluLookAt(mundo->getOjo().x, mundo->getOjo().y, mundo->getOjo().z,  // posicion del ojo 
			0.0, mundo->getZapunta(), 0.0,      // hacia que punto mira  (0,7.5,0)  
			0.0, 1.0, 0.0);*/
		
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("Fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -3, 15);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA REANUDAR", -3, 10);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -3, 5);
		}
}

void MaquinaEstados::teclaEspecial(unsigned char key) {
	if (estado == JUEGO)
		mundo->teclaEspecial(key);
}
void MaquinaEstados::mueve()
{
	if (estado == JUEGO)
		mundo->mueve();

}
void MaquinaEstados::tecla(unsigned char key) {
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			//delete mundo;
			
			//mundo->inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else    if (estado == JUEGO)
	{
		mundo->tecla(key);
		if (key == 'p')
			estado = PAUSA;
		ETSIDI::playMusica("Sound/Caverna.ogg", true);
	}
	else if (estado == PAUSA)
		{
		if (key == 'e')
			estado = JUEGO;
		else if (key == 's')
			exit(0);
		}
	else    if (estado == GAMEOVER)
	{
		if (key == 'c') {
			delete mundo;
			mundo = new Mundo;
			estado = INICIO;
		}
	}
}

void MaquinaEstados::cambia() {
	if (estado == JUEGO) {
		mundo->cambia();
	}
}
Vector3D MaquinaEstados::getOjo() {
	return mundo->getOjo();
}
float MaquinaEstados::getZapunta() {
	return mundo->getZapunta();
}

MaquinaEstados::~MaquinaEstados() {
	delete mundo;
}