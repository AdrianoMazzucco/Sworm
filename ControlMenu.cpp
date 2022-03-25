#include "stdafx.h"
#include "ControlMenu.h"

void ControlMenu::update(colorScheme* colors, int& state)
{
	updateOffset();
	updateAngle();
	setColors(colors);

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true) || App::GetController().CheckButton(XINPUT_GAMEPAD_B))
		state = 0;
}

void ControlMenu::draw()
{
	App::Print(200, 700, "Welcome to the Swarm.", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 680, "Use Left stick to Control the Snake to herd the Aliens. Start button opens the Shop to purchase towers", 1, 1, 1, GLUT_BITMAP_HELVETICA_12);
	App::Print(200, 660, "Use Left stick to move towers and A button to place them. Right Rotates the Wall", 1, 1, 1, GLUT_BITMAP_HELVETICA_12);
	App::Print(200, 640, "Wrecking Ball and Swinging Mace towers deal piercing damage. FlameThrower deals Fire Damage.", 1, 1, 1,GLUT_BITMAP_HELVETICA_12);
	App::Print(200, 620, "Purple Aliens are immune to piercing damage. Red Aliens are immune to Fire damage", 1, 1, 1, GLUT_BITMAP_HELVETICA_12);
	App::Print(200, 600, "Slow towers and Walls can be used to slow down the Swarm. However there are a limited number of both", 1, 1, 1, GLUT_BITMAP_HELVETICA_12);
	App::Print(200, 580, "Outlive the Alien swarm long enough to get $3000 to win the Game. Get too overwhelmed and its GAME OVER", 1, 1, 1, GLUT_BITMAP_HELVETICA_12);
	App::Print(500, 500, "GOOD LUCK", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);
	arrow.shape3D(180 - offset, 405, 10, arrowAngle, 0, 0, 3, colorR, colorG, colorB);
	arrow2.shape3D(300 + offset, 405, 10, arrowAngle, 0, PI, 3, colorR, colorG, colorB);
	App::Print(200, 400, "Return", colorR, colorG, colorB, GLUT_BITMAP_HELVETICA_18);
}
