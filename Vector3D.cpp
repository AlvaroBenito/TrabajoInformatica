#include "Vector3D.h"
Vector3D::Vector3D(float x1, float y1, float z1) {
	x = x1;
	y = y1;
	z = z1;
}

float Vector3D::modulo()
{
	return (float)sqrt(x*x + y * y + z*z);
}

Vector3D Vector3D::unitario()
{
	Vector3D retorno(x, y, z);
	float mod = modulo();
	if (mod>0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
		retorno.z /= mod;
	}
	return retorno;
}

Vector3D Vector3D::operator - (Vector3D &v)
{
	Vector3D res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}

Vector3D Vector3D::operator + (Vector3D &v)
{
	Vector3D res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

float Vector3D::operator *(Vector3D &v)
{
	return x * v.x + y * v.y + z* v.z;
}

Vector3D Vector3D::operator *(float f)
{
	Vector3D res;
	res.x = x * f;
	res.y = y * f;
	res.z = z * f;
	return res;
}
Vector3D Vector3D::operator /(float f)
{
	Vector3D res;
	res.x = x / f;
	res.y = y / f;
	res.z = z / f;
	return res;
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