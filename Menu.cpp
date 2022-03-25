#include "stdafx.h"
#include "Menu.h"


void Menu::background(float colorR, float colorG, float colorB)
{
	for (int i = 800; i > 0; i--) {
		App::DrawLine(0,i,1050,i, colorR*i/800 - 0.3, colorG*i/800 - 0.3, colorB*i/800 - 0.3);
	}
}

void Menu::updateAngle()
{
	arrowAngle += 0.05f;
	if (arrowAngle > 2 * PI)
		arrowAngle = 0;
}

void Menu::updateOffset()
{
	
	if (offset > 20)
		add = -0.4;
	if(offset < 0)
		add = 0.4;

	offset = offset + add;
}

void Menu::setColors(colorScheme* colors)
{
	colorR = colors->getColor3r();
	colorG = colors->getColor3g();
	colorB = colors->getColor3b();
}



