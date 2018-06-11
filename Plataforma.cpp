#include "Plataforma.h"

float Plataforma::z = 0.0f;

Plataforma::Plataforma()
	:limite1(-1.5f, 0.0f, z),
	limite2(1.5f, 0.5f, z - 10.0f),
	tamañoRect1(limite1.x - 1, limite1.y + 1.4F, limite2.z),
	tamañoRect2(limite2.x + 1, limite1.y + 1.4F, limite2.z),
	limFondo1(-20.0f, 0.0f, z-10),
	limFondo2(20.0f, 0.0f, z ),
	esquinaDer(limite2.x, limite1.y, limite1.z),
	sueloDer(limite1 + 2, limite2),
	sueloCen(limite1 + 1, limite2 - 1),
	sueloIzq(limite1, limite2 - 2),
	MuroDer(esquinaDer, tamañoRect2),
	MuroIzq(limite1, tamañoRect1),
	FondoSuelo(limFondo1, limFondo2)
{
	
	z -= 10;
	

}

void Plataforma::dibuja() {
	sueloDer.dibuja();
	sueloIzq.dibuja();
	sueloCen.dibuja();
	MuroDer.dibuja();
	MuroIzq.dibuja();
//Para dibujar planos ponemos antes la funcion plano.setMaterial para elegir la textura.
	FondoSuelo.setMaterial(0);
	FondoSuelo.dibuja();
	
}
