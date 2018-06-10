#include "Bonus.h"

Bonus::Bonus(Vector3D a, Vector3D b, bool tip):PrismaRectangular(a,b),tipo(tip) {

}

void Bonus::dibuja() {
	int a = tipoMaterial;
	tipoMaterial = 10;
	PrismaRectangular::dibuja();
	tipoMaterial = a;
}