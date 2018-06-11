#include "Vector3D.h"
Vector3D::Vector3D(float x1, float y1, float z1) {
	x = x1;
	y = y1;
	z = z1;
}



Vector3D Vector3D::operator + (float x1) {
	Vector3D res;
	res.x = x+x1;
	res.y = y;
	res.z = z;
	return res;
}
Vector3D Vector3D::operator - (float x1) {
	Vector3D res;
	res.x = x-x1;
	res.y = y;
	res.z = z;
	return res;
}