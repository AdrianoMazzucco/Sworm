#include "stdafx.h"
#include <windows.h> 
#include <math.h>  
#include "app\app.h"
#include "Boid.h"

Boid::Boid()
{
	angle = (rand() % 360) * PI / 180;
	x = -10;
	y = rand() % 799 + 1;
	Vx = 5;
	Vy = sinf(angle);
}

void Boid::update(Boid targets[], int &numBoids, int& score, int& PlayerHealth)
{

	Vx += Ax * 0.2 + 1;
	Vy += Ay * 0.2;

	Vx = Vx / sqrtf(Vx * Vx + Vy * Vy) + speed;
	Vy = Vy / sqrtf(Vx * Vx + Vy * Vy);

	float speed1 = rand() % 5 + 1;
	float speed2 = rand() % 5 + 1;
	x += speed1 * Vx - slowDown;
	y += speed2 * Vy;

	alignment(targets);

	if (x > 1050) {
		x = 0;
		if (numBoids < 400 && level > 2)
			numBoids++;
		if (level == 5  && PlayerHealth > 0) {
			PlayerHealth--;
		}
		if (level != 5) {
			level++;
			health = numBoids/5;
		}
	}
	else if (x < 0)
		x = rand() % 5;

	if (y > 770) {
		y = 760;
	}
	else if (y < 0) {
		Vy = 10;
	}

	setColor();

	if (health <= 0) {
		x = 5;
		y = rand() % 799 + 1;
		if (level > 3)
			level--;
		health = numBoids / 5;
		score++;
	}
}

float Boid::getx()
{
	return x;
}

float Boid::gety()
{
	return y;
}

float Boid::getVx()
{
	return Vx;
}

float Boid::getYy()
{
	return Vy;
}

void Boid::draw()
{
	if (alive)
		App::DrawLine(x, y, x + 10 * -Vx, y + 10 * -Vy, colorR, colorG, colorB);
}

void Boid::run(float obstacleX, float obstacleY, float close)
{
	float distance = sqrt((obstacleX - x) * (obstacleX - x) + (obstacleY - y) * (obstacleY - y));
	if (distance < close) {
		Ax += (x - obstacleX) * 0.5;
		Ay += (y - obstacleY) * 0.5;
	}
}

void Boid::hit(float bulletX, float bulletY, int bulletType)
{
	float distance = sqrt((x - bulletX) * (x - bulletX) + (y - bulletY) * (y - bulletY));

	if (bulletType == 1 && distance < 25) {
		if (level == 4)
			health -= 0;
		else if (level == 5)
			health -= 7;
		else
			health -= 16;
		
	}
	else if (bulletType == 2 && distance < 25) {
		if (level == 4)
			health -= 0;
		else if (level == 5)
			health -= 15;
		else
			health -= 30;
	}
	else if (bulletType == 3) {
		if (distance < 200)
			slowDown = 1.5;
		else
			slowDown = 0;
	}
	else if (bulletType == 4 && distance < 10) {
		if (level == 4)
			health -= 20;
		else if (level == 5)
			health -= 0;
		else
			health -= 8;
	}
}

void Boid::alignment(Boid mice[])
{
	int total1 = 0;
	int total2 = 0;
	int total3 = 0;
	float totalX = 0;
	float totalY = 0;
	float totalVx = 0;
	float totalVy = 0;
	float totalSx = 0;
	float totalSy = 0;
	for (int i = 0; i < 200; i++) {
		if (abs((mice[i].getx()) - x) < 25 && abs((mice[i].gety()) - y) < 25) {
			total1++;
			totalX += mice[i].getx();
			totalY += mice[i].gety();
		}
		if (abs((mice[i].getx()) - x) < 75 && abs((mice[i].gety()) - y) < 75) {
			total2++;
			totalVx += mice[i].getVx();
			totalVy += mice[i].getYy();
		}
		if (abs((mice[i].getx()) - x) < 25 && abs((mice[i].gety()) - y) < 25) {
			if ((abs((mice[i].getx()) - x)) > 0 && (abs((mice[i].gety()) - y)) > 0) {
				total3++;
				totalSx += (x - mice[i].getx()) / (abs((mice[i].getx()) - x));
				totalSy += (y - mice[i].gety()) / (abs((mice[i].gety()) - y));
			}
		}
	}
	if (total1 > 0) {
		totalX = totalX / total1;
		totalY = totalY / total1;
		totalVx = totalVx / total2;
		totalVy = totalVy / total2;
		Ax = (totalX - x) * 0.2 + (totalVx)+(totalSx) * 1.5;
		Ay = (totalY - y) * 0.2 + (totalVy)+(totalSy) * 1.5;
	}
}

void Boid::setColor()
{
	if (level == 1) {
		colorR = 1;
		colorB = 1;
		colorG = 1;
		speed = 0;
	}
	else if (level == 2) {
		colorR = 0;
		colorB = 1;
		colorG = 1;
		speed = 0.05;
	}
	else if (level == 3) {
		colorR = 0;
		colorB = 0;
		colorG = 0.7;
		speed = 0.1;
	}
	else if (level == 4) {
		colorR = 1;
		colorB = 1;
		colorG = 0;
		speed = 0.15;
	}
	else if (level == 5) {
		colorR = 1;
		colorB = 0;
		colorG = 0;
		speed = 0.2;
	}
}

