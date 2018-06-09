#include "SueloMalo.h"
SueloMalo::SueloMalo()
{
}

SueloMalo::SueloMalo(float coordx, float coordz) : Plano(Vector3D(coordx - 0.5, 0.501, coordz), Vector3D(coordx + 0.5, 0.501, coordz - 1)) {

}


SueloMalo::~SueloMalo()
{
}

void SueloMalo::dibuja() {
	tipoMaterial = 10; 
	Plano::dibuja();
	tipoMaterial = 0;
}