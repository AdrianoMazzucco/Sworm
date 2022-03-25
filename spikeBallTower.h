#pragma once
#include "tower.h"

class spikeBallTower : public tower
{
public:	void update();
	  void draw(Shapes* drawTool);
	  void shoot();
	  void aim(Boid Targets[]);
	  void moveBullet();
	  void checkHit(Boid Targets[]);
};

