#include "stdafx.h"
#include "MainMenu.h"

void MainMenu::update(colorScheme* colors, int& state)
{
	selectOption();
	updateAngle();
	updateOffset();
	setMenu();
	setColors(colors);
	

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
		state = option + 1;
}

void MainMenu::draw()
{
	App::Print(200, 650, "THE SWORM", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);
	arrow.shape3D(180 - offset, arrowY, 10, arrowAngle, 0, 0, 3, colorR, colorG, colorB);
	arrow2.shape3D(300 + offset, arrowY, 10, arrowAngle, 0, PI, 3, colorR, colorG, colorB);
	App::Print(200, 600, "Start", startColor1, startColor2, startColor3, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 550, "Controls", controlsColor1, controlsColor2, controlsColor3, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 500, "Customize", custimizeColor1, custimizeColor2, custimizeColor3, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 450, "Exit", exitColor1, exitColor2, exitColor3, GLUT_BITMAP_HELVETICA_18);
}

void MainMenu::setMenu()
{
	if (option == 0) {
		arrowY = 605;
		startColor1 = colorR;
		startColor2 = colorG;
		startColor3 = colorB;
		controlsColor1 = 1;
		controlsColor2 = 1;
		controlsColor3 = 1;
		custimizeColor1 = 1;
		custimizeColor2 = 1;
		custimizeColor3 = 1;
		exitColor1 = 1;
		exitColor2 = 1;
		exitColor3 = 1;
	}
	else if (option == 1) {
		arrowY = 555;
		startColor1 = 1;
		startColor2 = 1;
		startColor3 = 1;
		controlsColor1 = colorR;
		controlsColor2 = colorG;
		controlsColor3 = colorB;
		custimizeColor1 = 1;
		custimizeColor2 = 1;
		custimizeColor3 = 1;
		exitColor1 = 1;
		exitColor2 = 1;
		exitColor3 = 1;
	}
	else if (option == 2) {
		arrowY = 505;
		startColor1 = 1;
		startColor2 = 1;
		startColor3 = 1;
		controlsColor1 = 1;
		controlsColor2 = 1;
		controlsColor3 = 1;
		custimizeColor1 = colorR;
		custimizeColor2 = colorG;
		custimizeColor3 = colorB;
		exitColor1 = 1;
		exitColor2 = 1;
		exitColor3 = 1;
	}
	else if (option == 3) {
		arrowY = 455;
		startColor1 = 1;
		startColor2 = 1;
		startColor3 = 1;
		controlsColor1 = 1;
		controlsColor2 = 1;
		controlsColor3 = 1;
		custimizeColor1 = 1;
		custimizeColor2 = 1;
		custimizeColor3 = 1;
		exitColor1 = colorR;
		exitColor2 = colorG;
		exitColor3 = colorB;
	}
}

void MainMenu::selectOption()
{
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, true))
	{
		option--;
		if (option == -1)
			option = 3;
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, true))
	{
		option++;
		if (option == 4)
			option = 0;
	}
}
