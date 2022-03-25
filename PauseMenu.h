#pragma once
#include "Game.h"
class PauseMenu : public Menu
{
	float color1r = 1, color1g = 1, color1b = 1;
	float color2r = 1, color2g = 1, color2b = 1;
	float color3r = 1, color3g = 1, color3b = 1;
	float color4r = 1, color4g = 1, color4b = 1;
	float color5r = 1, color5g = 1, color5b = 1;
	float color6r = 1, color6g = 1, color6b = 1;
	float color7r = 1, color7g = 1, color7b = 1;

	float numSlowTowers = 0;
	float numWalls = 0;
	int price = 10;
	int numBought = 0;
	char displayPrice[10];


public: void update(colorScheme* colors, int& state, int& score, Game* mainGame);
		void draw();
		void setMenu();
		void incrementOption();
		void select(int& state, int& score, Game* mainGame);
};

