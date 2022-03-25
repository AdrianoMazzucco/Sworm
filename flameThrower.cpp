#include "stdafx.h"
#include "flameThrower.h"

void flameThrower::update()
{
	if (locationSet) {
		if (delay == 0)
			shoot();
		moveBullet();

		delay++;
		if (delay > 0) {
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


void flameThrower::draw(Shapes* drawTool)
{
	drawTool->shape(x, y, 17, angle, 5, colorR / 2, colorG / 2, colorB / 2);
	drawTool->shape(x, y, 30, PI / 4, 3, colorR, colorG, colorB);

	for (int i = 0; i < 20; i++) {
		if (i % 2 != 0) {
			drawTool->shape(shotsX[i], shotsY[i], 10, PI/4 + 0.3, 3, 1, 0.8, 0);
		}
		else if (i % 2 == 0) {
			drawTool->shape(shotsX[i], shotsY[i], 10, PI / 4, 3, 1, 0, 0);
		}
	}
}

void flameThrower::shoot()
{
	shotsAngle[currentShot] = angle;
	shotsX[currentShot] = x;
	shotsY[currentShot] = y;

	currentShot++;
	if (currentShot == 20)
		currentShot = 0;
}

void flameThrower::aim(Boid Targets[])
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

void flameThrower::moveBullet()
{
	for (int i = 0; i < 20; i++) {
		shotsX[i] += cosf(shotsAngle[i]) * 5;
		shotsY[i] += sinf(shotsAngle[i]) * 5;
	}
}

void flameThrower::checkHit(Boid Targets[])
{
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 20; j++) {
			Targets[i].hit(shotsX[j], shotsY[j], 4);
		}
	}
}