#pragma once
#include "Boid.h"


class tower
{
public:
	float colorR = 1, colorG = 1, colorB = 1;
	float x = 500, y = 400;
	bool locationSet = FALSE;
	bool TooClose = FALSE;
	float angle = 0;
	float bulletAngle = 0;
	Shapes towerShape;
	int currentShot = 0;
	float shotsX[20];
	float shotsY[20];
	float shotsAngle[20];
	int delay = 0;
	int towerType = 1;
	float bladeAngle;
	float bladeTipX = 0, bladeTipY = 0, PbladeTipX = 0, PbladeTipY = 0;

		
		int getX();
		int getY();
		bool isSet();
		void checkLocation(tower towers[50], int numTowers);
		void setTooCloseFalse();
		void setColor(float r, float g, float b);
};

