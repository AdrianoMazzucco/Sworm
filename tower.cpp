#include "stdafx.h"
#include "tower.h"

int tower::getX()
{
	return x;
}

int tower::getY()
{
	return y;
}

bool tower::isSet()
{
	return locationSet;
}

void tower::checkLocation(tower Towers[50],int NumTowers)
{
	if (!locationSet) {
		x += App::GetController().GetLeftThumbStickX() ;
		y += App::GetController().GetLeftThumbStickY() ;
		if (x > 1050)
			x = 0;
		if (x < 0)
			x = 1050;
		if (y > 750)
			y = 0;
		if (y < 0)
			y = 750;

		bladeTipX = x + 75;
		bladeTipY = y;
		for (int i = 0; i < NumTowers; i++) {
			float distance = sqrt((x - Towers[i].getX()) * (x - Towers[i].getX()) + (y - Towers[i].getY()) * (y - Towers[i].getY()));
			if (distance < 70) {
				TooClose = TRUE;
			}
		}
	}
}

void tower::setTooCloseFalse()
{
	TooClose = FALSE;
}

void tower::setColor(float r, float g, float b)
{
	colorR = r;
	colorG = g;
	colorB = b;
}