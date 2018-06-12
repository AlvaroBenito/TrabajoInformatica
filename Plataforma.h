#pragma once
#include "Vector3D.h"
#include "PrismaRectangular.h"
#include "Plano.h"

class Plataforma
{
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	static float z;
	Vector3D limite1;//esquina inferior izq del frente
	Vector3D limite2;//esquina superior derecha del fondo del suelo
	Vector3D tamañoRect1;//esquina izquierda del fondo
	Vector3D tamañoRect2;//esquina superior derecha del alzado frontal
	Vector3D esquinaDer;//vector auxiliar de la esquina inferior derecha del alzado frontal del suelo
	Vector3D limFondo1;//Estos dos vectores son para hacer el plano que forme el fondo del juego.
	Vector3D limFondo2;
	PrismaRectangular sueloDer;
	PrismaRectangular sueloCen;
	PrismaRectangular sueloIzq;
	PrismaRectangular MuroDer;
	PrismaRectangular MuroIzq;
	Plano FondoSuelo;
public:
	Plataforma();
	void dibuja();
	Vector3D getPos();
	PrismaRectangular getSuelo();
	PrismaRectangular getParedDer();
	PrismaRectangular getParedIzq();
	static void setZ(float zi);
};
inline Vector3D Plataforma::getPos() {
	return sueloDer.getP1();
}
inline PrismaRectangular Plataforma::getSuelo() {
	return sueloCen;
}
inline PrismaRectangular Plataforma::getParedDer() {
	return MuroDer;
}
inline PrismaRectangular Plataforma::getParedIzq() {
	return MuroIzq;
}
inline void Plataforma::setZ(float zi) {
	z = zi;
}