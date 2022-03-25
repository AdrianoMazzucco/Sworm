#pragma once
class Segment
{
	float Ax = 0, Ay = 0, Bx = 0, By = 0, length = 0, angle = 0;
public: Segment();
	  void setter(float x, float y, float length);
	  void update(float targetX, float targetY, float len);
	  float getX();
	  float getY();
	  void draw();

};


