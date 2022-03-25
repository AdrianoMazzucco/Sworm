#pragma once
class Boid
{
	float x = 525, y = 400, Vx = 1, Vy = 0, Ax = 0, Ay = 0, angle = 0;
	float colorR = 1, colorG = 1, colorB = 1;
	bool alive = true;
	int level = 1;
	float speed = 1;
	float slowDown = 0;
	float health = 10;

public:	Boid();
	  void update(Boid targets[], int &numBoids, int& score, int& PlayerHealth);
	  float getx();
	  float gety();
	  float getVx();
	  float getYy();
	  void draw();
	  void run(float obstacleX, float obstacleY, float close);
	  void hit(float bulletX, float bulletY, int bulletType);
	  

private: void alignment(Boid mice[]);
			void setColor();
};

