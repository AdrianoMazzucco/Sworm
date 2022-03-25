#pragma once
class wall
{
	float x = 400, y = 400, x2 = 400, y2 = 450;
	float angle = 0;
	bool locationSet = FALSE;
	
public: void setLocation();
	  void draw(Shapes *drawTool);
	  bool isSet();
	  float getX();
	  float getY();
	  float getX2();
	  float getY2();
};

