#include <stdio.h>
#include <math.h>

class	Pt4f
{
public:
	Pt4f(float _x, float _y, float _z, float _w)
			: x(_x), y(_y), z(_z), w(_w)
	{}

	float	x;
	float	y;
	float	z;

	/*
	** Must stay the last attribute of the point.
	*/
	float	w;
};

class	Pt3f
{

	float	x;
	float	y;
	float	z;
};

void FromAxis(float angle, float vx, float vy, float vz)
{
	float sinAngle;
	angle *= 0.5f;

	sinAngle = sin(angle);
	printf("sin %f\n", sinAngle);
	printf("direction x %f y %f z %f\n", vx, vy, vz);

	// x = (vn.x * sinAngle);
	float x = (vx * sinAngle);
	printf("pt_direction->x %f * sinAngle %f = x %f\n",
			vx, sinAngle, x);
	// y = (vn.y * sinAngle);
	float y = (vy * sinAngle);
	// z = (vn.z * sinAngle);
	float z = (vz * sinAngle);
	float w = cos(angle);
	printf("x %f y %f z %f w %f \n", x, y, z, w);
}

void multi_quat (Pt4f pt1, Pt4f pt2)
{
	// the constructor takes its arguments as (x, y, z, w)
	printf("multi_quat :");
	printf("%f ", pt1.w * pt2.x + pt1.x * pt2.w + pt1.y * pt2.z - pt1.z * pt2.y);
	printf("%f ", pt1.w * pt2.y + pt1.y * pt2.w + pt1.z * pt2.x - pt1.x * pt2.z);
	printf("%f ", pt1.w * pt2.z + pt1.z * pt2.w + pt1.x * pt2.y - pt1.y * pt2.x);
	printf("%f\n", pt1.w * pt2.w - pt1.x * pt2.x - pt1.y * pt2.y - pt1.z * pt2.z);
}

void getMatrix(Pt4f pt)
{
	float x2 = pt.x * pt.x;
	float y2 = pt.y * pt.y;
	float z2 = pt.z * pt.z;
	float xy = pt.x * pt.y;
	float xz = pt.x * pt.z;
	float yz = pt.y * pt.z;
	float wx = pt.w * pt.x;
	float wy = pt.w * pt.y;
	float wz = pt.w * pt.z;

	// This calculation would be a lot more complicated for non-unit length quaternions
	// Note: The constructor of Matrix4 expects the Matrix in column-major format like expected by
	//   OpenGL
printf("%f ", 1.0f - 2.0f * (y2 + z2));
printf("%f ", 2.0f * (xy - wz));
printf("%f ", 2.0f * (xz + wy));
printf("%f\n", 0.0f);
printf("%f ", 2.0f * (xy + wz));
printf("%f ", 1.0f - 2.0f * (x2 + z2));
printf("%f ", 2.0f * (yz - wx));
printf("%f\n", 0.0f);
printf("%f ", 2.0f * (xz - wy));
printf("%f ", 2.0f * (yz + wx));
printf("%f ", 1.0f - 2.0f * (x2 + y2));
printf("%f\n", 0.0f);
printf("%f ", 0.0f);
printf("%f ", 0.0f);
printf("%f ", 0.0f);
printf("%f\n", 1.0f);
}

int main(int argc, char const *argv[])
{
	FromAxis(0.5, 0.298142, -0.745356, 0.596285);
	multi_quat(Pt4f(1, 2, 3, 4), Pt4f(5, 6, 7, 8));
	multi_quat(Pt4f(0, 0, 0, 0), Pt4f(5, 6, 7, 8));
	getMatrix(Pt4f(1, 2, 3, 4));
	return 0;
}
