#include "stdafx.h"
#include "Shapes.h"



void Shapes::shape(float x, float y, float radius, float angle, int numSides, float r, float g, float b)
{
	float distance = 2 * PI / numSides;
	for (int i = 0; i < numSides; i++) {
		findAngles(angle, distance, i);
		findPoints(angle1, angle2, radius, radius);
		App::DrawLine(x + X, y + Y, x + X2, y + Y2, r, g, b);
	}
}

void Shapes::star(float x, float y, float outerRadius, float innerRadius, float angle, int numPoints, float r, float g, float b)
{
	float distance =  PI / numPoints;
	float radius1 = 0;
	float radius2 = 0;
	for (int i = 0; i < 2*numPoints; i++) {
		findAngles(angle, distance, i);
		starRadius(i, outerRadius, innerRadius);
		findPoints(angle1, angle2, starRadius1, starRadius2);
		App::DrawLine(x + X, y + Y, x + X2, y + Y2, r, g, b);
	}
}

void Shapes::shape3D(float x, float y, float radius, float angleX, float angleY, float angleZ, int numSides, float r, float g, float b)
{
	float pointsX[64];
	float pointsY[64];
	float pointsZ[64];
	float distance = 2 * PI / numSides;
	for (int i = 0; i < 2* numSides + 1; i++) {
		float Z = radius*3/4;
		float Z2 = radius*3/4;
		if (i > numSides) {
			 Z = -Z;
			 Z2 = -Z2;
		}
		findAngles(angleZ, distance, i);
		findPoints(angle1, angle2, radius, radius);

		float tempX = X * cosf(angleY) - Z * sinf(angleY);
		Z = Z * cosf(angleY) + X * sinf(angleY);

		float tempY = Y*cosf(angleX) + Z * sinf(angleX);
		Z = Z * cosf(angleX) - Y * sinf(angleX);

		float tempX2 = X2 * cosf(angleY) - Z2 * sinf(angleY);
		Z2 = Z2 * cosf(angleY) + X2 * sinf(angleY);

		float tempY2 = Y2* cosf(angleX) + Z2 * sinf(angleX);
		Z2 = Z2 * cosf(angleX) - Y * sinf(angleX);

		App::DrawLine(x + tempX, y + tempY, x + tempX2, y + tempY2, r, g, b);
		pointsX[i] = tempX;
		pointsY[i] = tempY;
		pointsZ[i] = Z;
	}
	for (int i = 0; i < numSides+1; i++) {
		App::DrawLine(x + pointsX[i], y + pointsY[i], x + pointsX[i+numSides], y + pointsY[i+numSides], r, g, b);
	}
}

void Shapes::wall(float x, float y, float x2,float y2, float r, float g, float b)
{
	App::DrawLine(x, y, x2, y2, r, g, b);
	App::DrawLine(x, y, x+20, y, r, g, b);
	App::DrawLine(x2, y2, x2+20, y2, r, g, b);
	App::DrawLine(x+20, y, x2+20, y2, r, g, b);
}

void Shapes::findPoints(float angle,float angle2, float radius1, float radius2)
{
	X = cosf( angle) * radius1;
	Y = sinf( angle) * radius1;
	X2 = cosf(angle2) * radius2;
	Y2 = sinf(angle2) * radius2;
}

void Shapes::starRadius(int i,float radius1, float radius2)
{
	if (i % 2 == 0) {
		starRadius1 = radius1;
		starRadius2 = radius2;
	}
	else {
		starRadius1 = radius2;
		starRadius2 = radius1;
	}
}

void Shapes::findAngles(float angle, float distance, int i)
{
	angle1 = distance * i + angle;
	angle2 = distance * (i + 1) + angle;
}
