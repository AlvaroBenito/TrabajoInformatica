#include "Plataforma.h"



Plataforma::Plataforma() 
	:limite1(-10.0,0.0,0.0),
	limite2(10.0,5.0,-50.0),
	tamañoRect1(limite1.x-10,limite1.y+9,limite2.z),
	tamañoRect2(limite2.x+10,limite1.y+9,limite2.z),
	esquinaDer(limite2.x,limite1.y,limite1.z),
	sueloDer(limite1, limite2 / 3),
	sueloCen(limite1*1/3, limite2 * 2 / 3),
	sueloIzq(limite1, limite2),
	MuroDer(esquinaDer,tamañoRect2),
	MuroIzq(limite1,tamañoRect1)
{

}

void Plataforma::dibuja() {
	sueloDer.dibuja();
	sueloIzq.dibuja();
	sueloCen.dibuja();
	MuroDer.dibuja();
	MuroIzq.dibuja();
}