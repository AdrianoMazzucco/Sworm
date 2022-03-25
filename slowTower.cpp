#include "stdafx.h"
#include "slowTower.h"

void slowTower::update()
{
	bladeAngle += 0.01;

	if (TooClose) {
		colorR = 1;
		colorG = 0;
		colorB = 0;
	}
	else if (!TooClose) {
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_A))
			locationSet = TRUE;
	}
}

void slowTower::draw(Shapes* drawTool)
{
	drawTool->shape(x, y, 30, bladeAngle, 5, colorR, colorG, colorB);
	drawTool->star(x, y, 30, 10, bladeAngle, 5, colorR, colorG, colorB);
	drawTool->shape(x, y, 200, 0, 20, 0, 0.5, 0.5);
}

void slowTower::checkHit(Boid Targets[])
{
	for (int i = 0; i < 200; i++) {
		Targets[i].hit(x, y, 3);
	}
}