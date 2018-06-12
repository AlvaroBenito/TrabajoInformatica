#pragma once
#include "Personaje.h"
#include <sstream>
#include <iostream>
class Texto {//Clase para manejar el texto en 3D creado con ETSIDI.h
			 //No necesita creacion de objetos y funciona para manejar los contadores que se mueven con el personaje
public:
	static void printxyz(char *txt,float x, float y, float z);
	static void imprimeMonedas(char *txt, float z);
	static void imprimeVidas(char *txt, float z);
	static void imprimeDistancia(char *txt,float vel, float z);
	static char* cadena(int num);
};