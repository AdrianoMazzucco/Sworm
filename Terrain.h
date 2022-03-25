#pragma once
#include <windows.h> 
#include <math.h> 
#include "app\app.h"

class Terrain
{
	int width = 168;
	int halfWidth = 84;
	int height = 50;
	float xValuesPos[168][50];
	float xValuesNeg[168][50];
	float zValues[168][50];
	float yValues[168][50];
	float tempZ[168][52];
	float heightChange[168][50];
	float size = 25;
	float angle = PI / 3 + 0.3;
	int timer = 0;
	bool left = false, right = false, up = false, down = false, bounce = false;
	float color2r = 0.02;
	float color2g = 1;
	float color2b = 0.7;
	float color1r = 0.73;
	float color1g = 0.4;
	float color1b = 1;

public: void init();
	  void update();
	  void draw(colorScheme *colors);
	  void setLeft(bool setLeft);
	  void setRight(bool setRight);
	  void setUp(bool setUp);
	  void setDown(bool setDown);
	  void setBounce(bool setBounce);
	  void setAngle(float setAngle);
	  void setColor1(float r, float g, float b);
	  void setColor2(float r, float g, float b);

private: void findYValues();
	   void findXValues();
	   void saveZValues();
	   void shiftZValues();
	   void countDown();
};
