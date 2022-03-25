#include "stdafx.h"
#include "Terrain.h"

void Terrain::init()
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height + 2; y++) {
			tempZ[x][y] = rand() % 50;
		}
	}

	for (int x = 0; x < width - 1; x++) {
		for (int y = 0; y < height; y++) {
			zValues[x][y] = (tempZ[x][y] * 2 + tempZ[x + 1][y] + tempZ[x + 1][y + 1] + tempZ[x + 1][y - 1] + tempZ[x - 1][y] + tempZ[x - 1][y + 1] + tempZ[x - 1][y - 1] + tempZ[x][y + 1] + tempZ[x][y - 1]) / 10;
		}
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width / 2; x++) {
			yValues[x][y] = y * size;
			xValuesPos[x][y] = x * size;
			yValues[halfWidth + x][y] = y * size;
			xValuesNeg[x][y] = -x * size;
		}
	}

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			heightChange[x][y] = -2;
		}
	}
}

void Terrain::update()
{
	findYValues();
	findXValues();
	saveZValues();
	shiftZValues();
	countDown();

}

void Terrain::draw(colorScheme *colors)
{
	color1r = colors->getColor1r();
	color1g = colors->getColor1g();
	color1b = colors->getColor1b();

	color2r = colors->getColor2r();
	color2g = colors->getColor2g();
	color2b = colors->getColor2b();

	for (int y = height; y > 0; y--) {
		for (int x = 0; x < width / 2 - 1; x++) {

			float color1 = (color1r * y + color2r * (height - y)) / height;
			float color2 = (color1g * y + color2g * (height - y)) / height;
			float color3 = (color1b * y + color2b * (height - y)) / height;

			App::DrawLine(xValuesPos[x][y] + 500, yValues[x][y], xValuesPos[x + 1][y] + 500, yValues[x + 1][y], color1, color2, color3);
			App::DrawLine(xValuesNeg[x][y] + 500, yValues[x + halfWidth][y], xValuesNeg[x + 1][y] + 500, yValues[x + 1 + halfWidth][y], color1, color2, color3);
			if (x < width - 1 && y < height - 1) {
				App::DrawLine(xValuesPos[x][y] + 500, yValues[x][y], xValuesPos[x][y + 1] + 500, yValues[x][y + 1], color1, color2, color3);
				App::DrawLine(xValuesNeg[x][y] + 500, yValues[x + halfWidth][y], xValuesNeg[x][y + 1] + 500, yValues[x + halfWidth][y + 1], color1, color2, color3);
				App::DrawLine(xValuesPos[x][y] + 500, yValues[x][y], xValuesPos[x + 1][y + 1] + 500, yValues[x + 1][y + 1], color1, color2, color3);
				App::DrawLine(xValuesNeg[x][y] + 500, yValues[x + halfWidth][y], xValuesNeg[x - 1][y + 1] + 500, yValues[x + halfWidth - 1][y + 1], color1, color2, color3);
			}
		}
	}
}

void Terrain::setLeft(bool setLeft)
{
	left = setLeft;
}

void Terrain::setRight(bool setRight)
{
	right = setRight;
}

void Terrain::setUp(bool setUp)
{
	up = setUp;
}

void Terrain::setDown(bool setDown)
{
	down = setDown;
}

void Terrain::setBounce(bool setBounce)
{
	bounce = setBounce;
}

void Terrain::setAngle(float setAngle)
{
	angle = setAngle;
}

void Terrain::setColor1(float r, float g, float b)
{
	color1r = r;
	color1g = g;
	color1b = b;
}

void Terrain::setColor2(float r, float g, float b)
{
	color2r = r;
	color2g = g;
	color2b = b;
}

void Terrain::findYValues()
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width / 2; x++) {
			yValues[x][y] = y * size * cosf(angle) + zValues[halfWidth + x][y] * sinf(angle) - 50;
			yValues[halfWidth + x][y] = y * size * cosf(angle) + zValues[halfWidth - x][y] * sinf(angle) - 50;
		}
	}
}

void Terrain::findXValues()
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width / 2; x++) {
			xValuesPos[x][y] = x * size * (1 - (y * size - yValues[x][y]) / 1500);
			xValuesNeg[x][y] = -x * size * (1 - (y * size - yValues[halfWidth + x][y]) / 1500);
		}
	}
}

void Terrain::saveZValues()
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			tempZ[x][y] = zValues[x][y];
		}
	}
}

void Terrain::shiftZValues()
{
	if (timer == 0) {
		if (up) {
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					if (y + 1 != height)
						zValues[x][y] = tempZ[x][y + 1];
					if (y + 1 == height)
						zValues[x][y] = zValues[x][0];
				}
			}
		}
		if (down) {
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					if (y - 1 != 0)
						zValues[x][y] = tempZ[x][y - 1];
					if (y - 1 == 0)
						zValues[x][y] = zValues[x][height - 1];
				}
			}
		}
		if (left) {
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					if (x - 1 != 0)
						zValues[x][y] = tempZ[x - 1][y];
					if (x - 1 == 0)
						zValues[x][y] = zValues[width - 2][y];
				}
			}
		}
		if (right) {
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					if (x + 1 != width - 1)
						zValues[x][y] = tempZ[x + 1][y];
					if (x + 1 == width - 1)
						zValues[x][y] = zValues[0][y];
				}
			}
		}
		if (bounce) {
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					if (zValues[x][y]  < 0)
						heightChange[x][y] = 1;

					if (zValues[x][y]  > 10)
						heightChange[x][y] = -1;
					
						
					zValues[x][y] += heightChange[x][y];
				}
			}
		}
	}
}

void Terrain::countDown()
{
	timer++;
	if (timer == 4)
		timer = 0;
}
