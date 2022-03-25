#pragma once
class slowTower : public tower
{
public:
	void update();
	void draw(Shapes* drawTool);
	void checkHit(Boid Targets[]);
};

