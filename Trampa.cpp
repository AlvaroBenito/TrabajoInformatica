#include "Trampa.h"



Trampa::Trampa()
{
}

Trampa::Trampa(float coordx, float coordz) : Plano(Vector3D(coordx-0.5, 0.501 , coordz),Vector3D(coordx+0.5, 0.501, coordz-1)) {

}


Trampa::~Trampa()
{
}

void Trampa::dibuja(){
	Plano::dibuja();
	
	glColor3ub(255, 255, 255);
	glTranslatef(limite1.x+0.5, limite1.y, limite1.z-0.5);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2, 0.7, 10, 10);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-limite1.x - 0.5, -limite1.y, -limite1.z + 0.5);
	
}