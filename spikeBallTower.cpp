#include "stdafx.h"
#include "spikeBallTower.h"

void spikeBallTower::update()
{
	if (locationSet) {
		if (delay == 0)
			shoot();
		moveBullet();

		delay++;
		if (delay > 100) {
			delay = 0;
		}
		bulletAngle += 0.5;
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


void spikeBallTower::draw(Shapes* drawTool)
{
	drawTool->shape(x, y, 17, angle, 3, colorR / 2, colorG / 2, colorB / 2);
	drawTool->shape(x, y, 30, PI / 4, 6, colorR, colorG, colorB);

	for (int i = 0; i < 20; i++) {
		drawTool->star(shotsX[i], shotsY[i], 20, 10, bulletAngle, 10, 0.5, 0.5, 0.5);
	}
}

void spikeBallTower::shoot()
{
	shotsAngle[currentShot] = angle;
	shotsX[currentShot] = x;
	shotsY[currentShot] = y;

	currentShot++;
	if (currentShot == 20)
		currentShot = 0;
}

void spikeBallTower::aim(Boid Targets[])
{
	float distance = 0;
	float closest = 1000;
	float currentX = 0;
	float currentY = 0;
	for (int i = 0; i < 200; i++) {
		distance = sqrt((x - Targets[i].getx()) * (x - Targets[i].getx()) + (y - Targets[i].gety()) * (y - Targets[i].gety()));
		if (distance < closest) {
			closest = distance;
			currentX = Targets[i].getx();
			currentY = Targets[i].gety();
		}
	}
	angle = atanf((currentY - y) / (currentX - x));
	if (currentX - x < 0) {
		angle = PI + angle;
	}
}

void spikeBallTower::moveBullet()
{
	for (int i = 0; i < 20; i++) {
		shotsX[i] += cosf(shotsAngle[i]) * 2;
		shotsY[i] += sinf(shotsAngle[i]) * 2;
	}
}

void spikeBallTower::checkHit(Boid Targets[])
{
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 20; j++) {
			Targets[i].hit(shotsX[j], shotsY[j], 1);
		}
	}
}