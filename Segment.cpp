#include "stdafx.h"
#include <windows.h> 
#include <math.h>  
#include "app\app.h"
#include "Segment.h"


Segment::Segment()
{
}

void Segment::setter(float x, float y, float len)
{
	Ax = x;
	Ay = y;
	length = len;
}

void Segment::update(float targetX, float targetY, float len)
{
	angle = atanf((targetY - Ay) / (targetX - Ax));
	length = len;

	if (targetX > Ax) {
		Bx = Ax + length * cos(angle);
		By = Ay + length * sin(angle);
	}
	else if (targetX < Ax) {
		Bx = Ax - length * cos(angle);
		By = Ay - length * sin(angle);
	}

	float moveX, moveY;
	moveX = targetX - Bx;
	moveY = targetY - By;
	Bx = targetX;
	By = targetY;
	Ax += moveX;
	Ay += moveY;
}

float Segment::getX()
{
	return (Ax);
}

float Segment::getY()
{
	return (Ay);
}

void Segment::draw()
{
	App::DrawLine(Ax, Ay, Bx, By, 1, 1, 1);
}
