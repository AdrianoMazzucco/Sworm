#pragma once
#include "colorScheme.h"
class Menu
{
public:
	Shapes arrow, arrow2;
	float arrowAngle = 0, arrowY = 0;
	int option = 0;
	float colorR = 1, colorG = 0.44, colorB = 0.8;
	float offset = 0;
	float add = 0.4;
	int colorChoice = 0;

		void background(float colorR, float colorG, float colorB);
		void updateAngle();
		void updateOffset();
		void setColors(colorScheme* colors);
};

