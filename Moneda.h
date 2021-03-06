#pragma once
#include "Elemento.h"
#define RADIO_MONEDA_OUT 0.2f
#define RADIO_MONEDA_IN 0.05f
class Moneda :public Elemento {
protected:
	static float anguloRotacion;
	int puntos;
public:
	Moneda();
	Moneda(float posx, float posy, float posz, float vel = 0);
	void setPos(Vector3D pos);
	virtual void dibuja();//metodo virtual para que MonedaEspecial use el suyo
	static void sumaAnguloRot(float theta);//Metodo para aplicar "velocidad angular" a las monedas
	int getPuntos();
	friend class Interaccion;
};
inline int Moneda::getPuntos() {
	return puntos;
}
inline void Moneda::setPos(Vector3D pos) {
	posicion = pos;
}