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
			ETSIDI::setFont("Fuentes/Bitwise.ttf", 50);
			ETSIDI::printxy("INFINITE RUN", -5.5, 15);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("Fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -4.5, 10);
			ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -4.5, 7);
			ETSIDI::printxy("AUTORES-->ALVARO BENITO OLIVA Y MARIO GARCIA TEJERINA", -7, 4);
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
		glTranslatef(0, 0, mundo->getOjo().z - 20);
		ETSIDI::printxy("GAMEOVER: Has perdido", -3, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -3, 5);
		glTranslatef(0, 0, -(mundo->getOjo().z - 20));
	}
	else if (estado == PAUSA)
		 {
		/*gluLookAt(mundo->getOjo().x, mundo->getOjo().y, mundo->getOjo().z,  // posicion del ojo 
			0.0, mundo->getZapunta(), 0.0,      // hacia que punto mira  (0,7.5,0)  
			0.0, 1.0, 0.0);*/
		mundo->dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("Fuentes/Bitwise.ttf", 16);
		glTranslatef(0, 0, mundo->getOjo().z - 20);
		ETSIDI::printxy("PAUSA", -3, 15);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA REANUDAR", -3, 10);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -3, 7);
		ETSIDI::printxy("PULSE LA TECLA -M- PARA VOLVER AL MENU", -3, 4);
		glTranslatef(0, 0, -(mundo->getOjo().z - 20));
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
		if (key == 'e'||key=='E')
		{
			estado = JUEGO;
			PrismaRectangular::setMaterial(0);
		}
		if (key == 's'||key=='S')
			exit(0);
	}
	else    if (estado == JUEGO)
	{
		mundo->tecla(key);
		if (key == 'p'||key=='P')
			estado = PAUSA;
		ETSIDI::playMusica("Sound/Caverna.ogg", true);
	}
	else if (estado == PAUSA)
		{
		if (key == 'e'||key=='E')
			estado = JUEGO;
		if (key == 's'||key=='S')
			exit(0);
		if (key == 'm'||key=='M') {
			delete mundo;
			mundo = new Mundo;
			estado = INICIO;
		}
		}
	else    if (estado == GAMEOVER)
	{
		if (key == 'c'||key=='C') {
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


MaquinaEstados::~MaquinaEstados() {
	delete mundo;
}