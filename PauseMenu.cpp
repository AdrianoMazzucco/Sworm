#include "stdafx.h"
#include "PauseMenu.h"

void PauseMenu::update(colorScheme* colors, int& state, int& score, Game* mainGame)
{
	incrementOption();
	updateAngle();
	updateOffset();
	setMenu();
	setColors(colors);

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
		select(state, score, mainGame);

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
		state = 1;

	
	sprintf(displayPrice, "Cost : %d", price);
}

void PauseMenu::draw()
{
	arrow.shape3D(180 - offset, arrowY, 10, arrowAngle, 0, 0, 3, colorR, colorG, colorB);
	App::Print(200, 600, "Wrecking Ball", color1r, color1g, color1b, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 550, "Swinging Mace", color2r, color2g, color2b, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 500, "Flame Thrower", color3r, color3g, color3b, GLUT_BITMAP_HELVETICA_18);

	if(numSlowTowers ==0)
		App::Print(200, 450, "Slow Tower", color4r, color4g, color4b, GLUT_BITMAP_HELVETICA_18);
	else
		App::Print(200, 450, "SOLD OUT", 0.5, 0.5, 0.5, GLUT_BITMAP_HELVETICA_18);

	if(numWalls < 2 && numBought > 5)
		App::Print(200, 400, "Wall", color5r, color5g, color5b, GLUT_BITMAP_HELVETICA_18);
	else 
		App::Print(200, 400, "SOLD OUT", 0.5, 0.5, 0.5, GLUT_BITMAP_HELVETICA_18);

	App::Print(200, 350, "Resume Game", color6r, color6g, color6b, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 300, "Main Menu", color7r, color7g, color7b, GLUT_BITMAP_HELVETICA_18);
	App::Print(900, 700, displayPrice);
}

void PauseMenu::setMenu()
{
	if (option == 0) {
		arrowY = 605;
		color1r = colorR;
		color1g = colorG;
		color1b = colorB;
		color2r = 1;
		color2g = 1;
		color2b = 1;
		color3r = 1;
		color3g = 1;
		color3b = 1;
		color4r = 1;
		color4g = 1;
		color4b = 1;
		color5r = 1;
		color5g = 1;
		color5b = 1;
		color6r = 1;
		color6g = 1;
		color6b = 1;
		color7r = 1;
		color7g = 1;
		color7b = 1;
	}
	else if (option == 1) {
		arrowY = 555;
		color1r = 1;
		color1g = 1;
		color1b = 1;
		color2r = colorR;
		color2g = colorG;
		color2b = colorB;
		color3r = 1;
		color3g = 1;
		color3b = 1;
		color4r = 1;
		color4g = 1;
		color4b = 1;
		color5r = 1;
		color5g = 1;
		color5b = 1;
		color6r = 1;
		color6g = 1;
		color6b = 1;
		color7r = 1;
		color7g = 1;
		color7b = 1;
	}
	else if (option == 2) {
		arrowY = 505;
		color1r = 1;
		color1g = 1;
		color1b = 1;
		color2r = 1;
		color2g = 1;
		color2b = 1;
		color3r = colorR;
		color3g = colorG;
		color3b = colorB;
		color4r = 1;
		color4g = 1;
		color4b = 1;
		color5r = 1;
		color5g = 1;
		color5b = 1;
		color6r = 1;
		color6g = 1;
		color6b = 1;
		color7r = 1;
		color7g = 1;
		color7b = 1;
	}
	else if (option == 3) {
		arrowY = 455;
		color1r = 1;
		color1g = 1;
		color1b = 1;
		color2r = 1;
		color2g = 1;
		color2b = 1;
		color3r = 1;
		color3g = 1;
		color3b = 1;
		color4r = colorR;
		color4g = colorG;
		color4b = colorB;
		color5r = 1;
		color5g = 1;
		color5b = 1;
		color6r = 1;
		color6g = 1;
		color6b = 1;
		color7r = 1;
		color7g = 1;
		color7b = 1;
	}
	else if (option == 4) {
		arrowY = 405;
		color1r = 1;
		color1g = 1;
		color1b = 1;
		color2r = 1;
		color2g = 1;
		color2b = 1;
		color3r = 1;
		color3g = 1;
		color3b = 1;
		color4r = 1;
		color4g = 1;
		color4b = 1;
		color5r = colorR;
		color5g = colorG;
		color5b = colorB;
		color6r = 1;
		color6g = 1;
		color6b = 1;
		color7r = 1;
		color7g = 1;
		color7b = 1;
	}
	else if (option == 5) {
		arrowY = 355;
		color1r = 1;
		color1g = 1;
		color1b = 1;
		color2r = 1;
		color2g = 1;
		color2b = 1;
		color3r = 1;
		color3g = 1;
		color3b = 1;
		color4r = 1;
		color4g = 1;
		color4b = 1;
		color5r = 1;
		color5g = 1;
		color5b = 1;
		color6r = colorR;
		color6g = colorG;
		color6b = colorB;
		color7r = 1;
		color7g = 1;
		color7b = 1;
	}
	else if (option == 6) {
		arrowY = 305;
		color1r = 1;
		color1g = 1;
		color1b = 1;
		color2r = 1;
		color2g = 1;
		color2b = 1;
		color3r = 1;
		color3g = 1;
		color3b = 1;
		color4r = 1;
		color4g = 1;
		color4b = 1;
		color5r = 1;
		color5g = 1;
		color5b = 1;
		color6r = 1;
		color6g = 1;
		color6b = 1;
		color7r = colorR;
		color7g = colorG;
		color7b = colorB;
	}
}

void PauseMenu::incrementOption()
{
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, true))
	{
		option--;
		if (option == -1)
			option = 6;
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, true))
	{
		option++;
		if (option == 7)
			option = 0;
	}
}

void PauseMenu::select(int& state, int& score, Game* mainGame)
{
	if (option == 0) {
		if (score >= price) {
			numBought++;
			score -= price;
			price += numBought * 5;
			mainGame->createTower(1);
			state = 1;
		}
	}
	else if (option == 1) {
		if (score >= price) {
			numBought++;
			score -= price;
			price += numBought * 5;
			mainGame->createTower(2);
			state = 1;
		}
	}
	else if (option == 2) {
		if (score >= price) {
			numBought++;
			score -= price;
			price += numBought * 5;
			mainGame->createTower(4);
			state = 1;
		}
	}
	else if (option == 3 && numSlowTowers == 0) {
		if (score >= price) {
			numBought++;
			score -= price;
			price += numBought * 5;
			numSlowTowers = 1;
			mainGame->createTower(3);
			state = 1;
		}
	}
	else if (option == 4 && numWalls < 2 && numBought > 5) {
		if (score >= price) {
			numBought++;
			score -= price;
			price += numBought * 5;
			mainGame->createWall();
			numWalls++;
			state = 1;
		}
	}
	else if (option == 5) {
		state = 1;
	}
	else if (option == 6) {
		state = 0;
	}
}
