#pragma once
#include "Elemento.h"
class Personaje :public Elemento {
	int vidas;
	bool escudo;
	static int contMonedas;
	friend class Interaccion;
	bool centro;//variable para saber si el personaje esta en el carril central
	bool salto;//Variable para comprobar si puede o no saltar
public:
	Personaje();
	void dibuja();
	void gira(bool der);//Metodo para el giro a derecha e izquierda del personaje
	int getVidas();
	int getContMonedas();
	void sumaMoneda(int mult);//Metodo para sumar una cantidad de valor al contador de monedas
	void salta();
	void restaVida();
	void sumaVida();
	void resetMonedas();
	void finEscudo();
	bool getEscudo();
};
inline int Personaje::getVidas() {
	return vidas;
}
inline int Personaje::getContMonedas() {
	return contMonedas;
}
inline bool Personaje::getEscudo() {
	return escudo;
}