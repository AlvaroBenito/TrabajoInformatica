#pragma once
#include "Vector3D.h"
//Clase base para hacer basicamente todos los elementos moviles, que son: Personaje, Moneda, Bonificacion, Obstaculo,etc
class Elemento {
protected://Protected para que lo use solo las clases heredadas y luego ponemos friend las clases para las interacciones y ese rollo
	Vector3D posicion;
	float velocidad;

public:
	Elemento();
	Elemento(Vector3D pos, float vel=0);
	void mueve();//En obstaculos no se usa necesariamente
	void rotar();//
};