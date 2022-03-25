#include "stdafx.h"
#include "wall.h"

void wall::setLocation()
{
	if (!locationSet) {
		x += App::GetController().GetLeftThumbStickX();
		y += App::GetController().GetLeftThumbStickY();
		angle += App::GetController().GetRightThumbStickY()/10;
		if (x > 1050)
			x = 0;
		if (x < 0)
			x = 1050;
		if (y > 750)
			y = 0;
		if (y < 0)
			y = 750;

		x2 = x + 150 * cosf(angle);
		y2 = y + 150 * sinf(angle);

		if (App::GetController().CheckButton(XINPUT_GAMEPAD_A))
			locationSet = TRUE;
	}
}

void wall::draw(Shapes* drawTool)
{
	drawTool->wall(x,y,x2,y2,1,1,1);
}

bool wall::isSet()
{
	return locationSet;
}

float wall::getX()
{
	return x;
}

float wall::getY()
{
	return y;
}

float wall::getX2()
{
	return x2;
}

float wall::getY2()
{
	return y2;
}
