//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

MainMenu *menu;
ControlMenu *menu2;
CustomizeMenu *menu3;
PauseMenu *menu4;
Terrain terrain;
colorScheme *colors;
Game *mainGame;
int state = 0;
int& stateRefernce = state;
int score = 90;
int& scoreReference = score;
int health = 200;
int& healthReference = health;
char displayHealth[10];
char displayScore[10];

void Init()
{
	menu = new MainMenu;
	menu2 = new ControlMenu;
	menu3 = new CustomizeMenu;
	menu4 = new PauseMenu;
	mainGame = new Game;
	colors = new colorScheme;
	mainGame->init();
	terrain.init();
}
	
void Update(float deltaTime)
{
	if (state == 0) {
		menu->update(colors, stateRefernce);
		terrain.setUp(true);
		terrain.setRight(false);
		terrain.setBounce(false);
		terrain.update();
	}
	else if (state == 1) {
		mainGame->update(stateRefernce, scoreReference, healthReference,colors);

		if (health == 0) {
			state = 6;
		}

		if (score >= 3000) {
			state = 7;
		}
	}
	else if (state == 2) {
		menu2->update(colors, stateRefernce);
		terrain.setBounce(true);
		terrain.setUp(false);
		terrain.setRight(false);
		terrain.update();
	}
	else if (state == 3) {
		menu3->update(colors, stateRefernce);
		terrain.setUp(false);
		terrain.setRight(true);
		terrain.setBounce(false);
		terrain.update();
	}
	else if (state == 5){
		menu4 -> update(colors, stateRefernce, scoreReference, mainGame);
		terrain.update();
	}
	else if (state == 4)
		exit(1);
	else if (state == 6 || state == 7) {
		terrain.setUp(false);
		terrain.setRight(true);
		terrain.setBounce(false);
		terrain.update();
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
			state = 4;
	}
	
	sprintf(displayScore, "Money $ %d", score);
	sprintf(displayHealth, "Health : %d", health);
}

void Render()
{

	if (state == 0) {
		menu->background(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		menu->draw();
		terrain.draw(colors);
	}
	else if (state == 1) {
		mainGame->draw();
	}
	else if (state == 2) {
		menu->background(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		menu2->draw();
		terrain.draw(colors);
	}
	else if (state == 3) {
		menu->background(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		menu3->draw(colors);
		terrain.draw(colors);
	}
	else if (state == 5) {
		menu->background(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		menu4->draw();
		terrain.draw(colors);
	}
	else if (state == 6) {
		menu->background(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		App::Print(200, 600, "You Loose", 1, 0, 0, GLUT_BITMAP_HELVETICA_18);
		terrain.draw(colors);
	}
	else if (state == 7) {
		menu->background(colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
		App::Print(200, 600, "You Win", 0, 1, 0, GLUT_BITMAP_HELVETICA_18);
		terrain.draw(colors);
	}

	App::Print(900, 725, displayScore);
	App::Print(900, 675, displayHealth);
}

void Shutdown()
{	
	delete colors;
	delete menu;
	delete menu2;
	delete menu3;
	delete menu4;
	mainGame->endGame();
	delete mainGame;
}