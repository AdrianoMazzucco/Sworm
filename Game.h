#pragma once
#include "tower.h"
#include "Boid.h"
#include "wall.h"
#include "spikeBallTower.h"
#include "maceTower.h"
#include "slowTower.h"
#include "flameThrower.h"
#include "Segment.h"

class Game
{
	Shapes* drawTool = new Shapes;
	spikeBallTower spikeTowers[50];
	maceTower maceTower[50];
	flameThrower flameThrowers[50];
	slowTower slowTowers[1];
	Boid Targets[400];
	wall walls[2];
	Segment snake[20];
	float snakeR = 1, snakeG = 1, snakeB = 1;
	float snakeHeadAngle = 0;
	float snakeX = 400, snakeY = 400;
	bool setting = FALSE;
	int numBoids = 5;
	int& numBoidsReference = numBoids;
	bool settingTower = FALSE;
	int numSpikeTowers = 0, numMaceTowers = 0, numFlameThrowers = 0, numSlowTowers = 0;
	int numWalls = 0;
	bool Start = FALSE;
	char displayNumBoids[10];

public: void init();
		void update(int &state, int &score, int& health, colorScheme* colors);
		void draw();
		void createTower(int type);
		void createWall();
		void endGame();
		void moveSnake();
		void updateTargets(int& score, int& health);
		void updateTowers(colorScheme* colors);
		void updateSnake(colorScheme* colors);
		
};

