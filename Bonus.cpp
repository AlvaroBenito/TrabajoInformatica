#include "Bonus.h"

Bonus::~Bonus() {

}
Bonus::Bonus(Vector3D a, Vector3D b, bool tip):PrismaRectangular(a,b),tipo(tip) {

}

void Bonus::dibuja() {
	int a = tipoMaterial;
	tipoMaterial = 10;
	PrismaRectangular::dibuja();
	tipoMaterial = a;
}
bool Bonus::destruye(float z) {
	if (p1.z > z)
		return true;
	return false;
}