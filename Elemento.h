#pragma once
#include "Vector3D.h"
#include "Color.h"
//Clase base para hacer basicamente todos los elementos moviles, que son: Personaje, Moneda, Bonificacion, Obstaculo,etc
class Elemento {
protected://Protected para que lo use solo las clases heredadas y luego ponemos friend las clases para las interacciones y ese rollo
	Vector3D posicion;
	Vector3D velocidad;
	Color RGB;
public:
	void mueve(float t);//En obstaculos no se usa necesariamente
};