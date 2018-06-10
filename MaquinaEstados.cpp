#pragma once
#include "MaquinaEstados.h"

MaquinaEstados::MaquinaEstados() {
	estado = INICIO;
	
}


void MaquinaEstados::dibuja() {
	if (estado == INICIO){ //CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS 
			gluLookAt(0, 7.5, 30,  // posicion del ojo 
				0.0, 7.5, 0.0,      // hacia que punto mira  (0,7.5,0)  
				0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)   
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("Fuentes/Bitwise.ttf", 30);
			ETSIDI::printxy("INFINITE RUN", -3, 15);
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("Fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -3, 10);
			ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -3, 5);
			ETSIDI::printxy("Rock BenitoPolla Stars Games", 2, 1);
	}

	else if (estado == JUEGO) {
		mundo.dibuja();
		
		if (mundo.getVidas() == 0)
			estado = GAMEOVER;

	}

	else    if (estado == GAMEOVER)
	{
	
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}

	else if(estado==PAUSA)
		{
		
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("Fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA", -3, 15);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA REANUDAR", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 5);
		}
}

void MaquinaEstados::teclaEspecial(unsigned char key) {
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}
void MaquinaEstados::mueve()
{
	if (estado == JUEGO)
		mundo.mueve();

}
void MaquinaEstados::tecla(unsigned char key) {
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			mundo.inicializa();
			estado = JUEGO;
		}
		if (key == 's')
			exit(0);
	}
	else    if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}
	else    if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}

	else if (estado == PAUSA)
	{
		if (key == 'e')
			estado = JUEGO;
		else if (key == 's')
			exit(0);
	}
}

void MaquinaEstados::cambia() {
	mundo.cambia();
}
