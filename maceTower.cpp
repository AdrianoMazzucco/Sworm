#include "stdafx.h"
#include "maceTower.h"


void maceTower::update()
{
	if (locationSet) {
		bladeAngle += 0.05;
		bladeTipX = x + cosf(bladeAngle) * 75;
		bladeTipY = y + sinf(bladeAngle) * 75;
	}

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


void maceTower::draw(Shapes* drawTool)
{
	drawTool->shape(x, y, 30, PI / 4, 20, colorR, colorG, colorB);
	drawTool->star(bladeTipX, bladeTipY, 20, 10, -bladeAngle + PI / 3, 4, 0.5, 0.5, 0.5);
	App::DrawLine(x, y, bladeTipX, bladeTipY, colorR / 2, colorG / 2, colorB / 2);
}

void maceTower::checkHit(Boid Targets[])
{
	for (int i = 0; i < 200; i++) {
		Targets[i].hit(bladeTipX, bladeTipY, 2);
	}
}