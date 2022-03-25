#pragma once
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
class Shapes
{
		float X = 0, Y = 0, X2 = 0, Y2 = 0, starRadius1, starRadius2, angle1 = 0, angle2 = 0;
public: void shape(float x, float y, float radius, float angle, int numSides, float r, float g, float b);
		void star(float x, float y, float outerRadius, float innerRadius, float angle, int numPoints, float r, float g, float b);
		void shape3D(float x, float y, float radius, float angleX, float angleY, float angleZ, int numSides, float r, float g, float b);
		void wall(float x, float y, float x2,float y2, float r, float g, float b);
private:void findPoints(float angle,float angle2, float radius1, float radius2);
		void starRadius(int i, float radius1, float radius2);
		void findAngles(float angle, float distance, int i);
};

