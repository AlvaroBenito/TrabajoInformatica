#pragma once
#include "Personaje.h"
#include <sstream>
#include <iostream>
class Texto {
	int contMonedas;
	float distancia;
	int vidas;
public:
	static void printxyz(char *txt,float x, float y, float z);
	static void imprimeMonedas(char *txt, float z);
	static void imprimeVidas(char *txt, float z);
	static void imprimeDistancia(char *txt,float vel, float z);
	static char* cadena(int num);
};