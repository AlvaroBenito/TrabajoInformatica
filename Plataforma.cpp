#include "Plataforma.h"

float Plataforma::z = 0.0f;

Plataforma::Plataforma() 
	:limite1(-1.5f,0.0f,z),
	limite2(1.5f,0.5f,z-10.0f),
	tamañoRect1(limite1.x-1,limite1.y+1,limite2.z),
	tamañoRect2(limite2.x+1,limite1.y+1,limite2.z),
	esquinaDer(limite2.x,limite1.y,limite1.z),
	sueloDer(limite1+2, limite2),
	sueloCen(limite1+1, limite2 -1),
	sueloIzq(limite1, limite2-2),
	MuroDer(esquinaDer,tamañoRect2),
	MuroIzq(limite1,tamañoRect1)
{
	z -= 10;
}

void Plataforma::dibuja() {
	sueloDer.dibuja();
	sueloIzq.dibuja();
	sueloCen.dibuja();
	MuroDer.dibuja();
	MuroIzq.dibuja();
}
Vector3D Plataforma::getPos() {
	return sueloDer.getP1();
}
