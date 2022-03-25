#include "stdafx.h"
#include "CustomizeMenu.h"

void CustomizeMenu::update(colorScheme* colors, int& state)
{
	updateAngle();
	updateOffset();
	chooseColor();
	updateColors(colors);
	setColors(colors);

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
		state = 0;
}

void CustomizeMenu::draw(colorScheme* colors)
{
	char rgb1[64];
	char rgb2[64];
	char rgb3[64];
	char rgb4[64];
	char rgb5[64];
	sprintf(rgb1, "Colour 1      R : %f  G : %f  B : %f", colors->getColor1r(), colors->getColor1g(), colors->getColor1b());
	sprintf(rgb2, "Colour 2      R : %f  G : %f  B : %f", colors->getColor2r(), colors->getColor2g(), colors->getColor2b());
	sprintf(rgb3, "Colour 3      R : %f  G : %f  B : %f", colors->getColor3r(), colors->getColor3g(), colors->getColor3b());
	sprintf(rgb4, "Colour 4      R : %f  G : %f  B : %f", colors->getColor4r(), colors->getColor4g(), colors->getColor4b());
	sprintf(rgb5, "Colour 5      R : %f  G : %f  B : %f", colors->getColor5r(), colors->getColor5g(), colors->getColor5b());
	arrow.shape3D(180 - offset, arrowY, 10, arrowAngle, 0, 0, 3, colorR, colorG, colorB);
	App::Print(200, 600, rgb1, colors->getColor1r(), colors->getColor1g(), colors->getColor1b(), GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 550, rgb2, colors->getColor2r(), colors->getColor2g(), colors->getColor2b(), GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 500, rgb3, colors->getColor3r(), colors->getColor3g(), colors->getColor3b(), GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 450, rgb4, colors->getColor4r(), colors->getColor4g(), colors->getColor4b(), GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 400, rgb5, colors->getColor5r(), colors->getColor5g(), colors->getColor5b(), GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 350, "Left and right on D-Pad to change Red Values.", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 320, "Left Stick for Green Values.", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 290, "Right Stick for Blue values", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);
	App::Print(200, 260, "B button to return to menu", 1, 1, 1, GLUT_BITMAP_HELVETICA_18);

}

void CustomizeMenu::updateColors(colorScheme* colors)
{
	if (colorChoice == 0) {
		arrowY = 605;
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false)) {
			if ((colors->getColor1r() + 0.01) < 1)
				colors->setColor1(colors->getColor1r() + 0.01, colors->getColor1g(), colors->getColor1b());
		}
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false)) {
			if ((colors->getColor1r() - 0.01) > 0)
				colors->setColor1(colors->getColor1r() - 0.01, colors->getColor1g(), colors->getColor1b());
		}
		if ((colors->getColor1g() + App::GetController().GetLeftThumbStickY() / 10) > 0 && (colors->getColor1g() + App::GetController().GetLeftThumbStickY() / 10) < 1)
			colors->setColor1(colors->getColor1r(), colors->getColor1g() + App::GetController().GetLeftThumbStickY() / 10, colors->getColor1b());
		if ((colors->getColor1b() + App::GetController().GetRightThumbStickY() / 10) > 0 && (colors->getColor1b() + App::GetController().GetRightThumbStickY() / 10) < 1)
			colors->setColor1(colors->getColor1r(), colors->getColor1g(), colors->getColor1b() + App::GetController().GetRightThumbStickY() / 10);
	}
	else if (colorChoice == 1) {
		arrowY = 555;
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false)) {
			if ((colors->getColor2r() + 0.01) < 1)
				colors->setColor2(colors->getColor2r() + 0.01, colors->getColor2g(), colors->getColor2b());
		}
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false)) {
			if ((colors->getColor2r() - 0.01) > 0)
				colors->setColor2(colors->getColor2r() - 0.01, colors->getColor2g(), colors->getColor2b());
		}
		if ((colors->getColor2g() + App::GetController().GetLeftThumbStickY() / 10) > 0 && (colors->getColor2g() + App::GetController().GetLeftThumbStickY() / 10) < 1)
			colors->setColor2(colors->getColor2r(), colors->getColor2g() + App::GetController().GetLeftThumbStickY() / 10, colors->getColor2b());
		if ((colors->getColor2b() + App::GetController().GetRightThumbStickY() / 10) > 0 && (colors->getColor2b() + App::GetController().GetRightThumbStickY() / 10) < 1)
			colors->setColor2(colors->getColor2r(), colors->getColor2g(), colors->getColor2b() + App::GetController().GetRightThumbStickY() / 10);
	}
	else if (colorChoice == 2) {
		arrowY = 505;
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false)) {
			if ((colors->getColor3r() + 0.01) < 1)
				colors->setColor3(colors->getColor3r() + 0.01, colors->getColor3g(), colors->getColor3b());
		}
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false)) {
			if ((colors->getColor3r() - 0.01) > -0)
				colors->setColor3(colors->getColor3r() - 0.01, colors->getColor3g(), colors->getColor3b());
		}
		if ((colors->getColor3g() + App::GetController().GetLeftThumbStickY() / 10) > 0 && (colors->getColor3g() + App::GetController().GetLeftThumbStickY() / 10) < 1)
			colors->setColor3(colors->getColor3r(), colors->getColor3g() + App::GetController().GetLeftThumbStickY() / 10, colors->getColor3b());
		if ((colors->getColor3b() + App::GetController().GetRightThumbStickY() / 10) > 0 && (colors->getColor3b() + App::GetController().GetRightThumbStickY() / 10) < 1)
			colors->setColor3(colors->getColor3r(), colors->getColor3g(), colors->getColor3b() + App::GetController().GetRightThumbStickY() / 10);
	}
	else if (colorChoice == 3) {
		arrowY = 455;
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false)) {
			if ((colors->getColor4r() + 0.01) < 1)
				colors->setColor4(colors->getColor4r() + 0.01, colors->getColor4g(), colors->getColor4b());
		}
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false)) {
			if ((colors->getColor4r() - 0.01) > 0)
				colors->setColor4(colors->getColor4r() - 0.01, colors->getColor4g(), colors->getColor4b());
		}
		if ((colors->getColor4g() + App::GetController().GetLeftThumbStickY() / 10) > 0 && (colors->getColor4g() + App::GetController().GetLeftThumbStickY() / 10) < 1)
			colors->setColor4(colors->getColor4r(), colors->getColor4g() + App::GetController().GetLeftThumbStickY() / 10, colors->getColor4b());
		if ((colors->getColor4b() + App::GetController().GetRightThumbStickY() / 10) > 0 && (colors->getColor4b() + App::GetController().GetRightThumbStickY() / 10) < 1)
			colors->setColor4(colors->getColor4r(), colors->getColor4g(), colors->getColor4b() + App::GetController().GetRightThumbStickY() / 10);
	}
	else if (colorChoice == 4) {
		arrowY = 405;
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false)) {
			if ((colors->getColor5r() + 0.01) < 1.1)
				colors->setColor5(colors->getColor5r() + 0.01, colors->getColor5g(), colors->getColor5b());
		}
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false)) {
			if ((colors->getColor5r() - 0.01) > -0.1)
				colors->setColor5(colors->getColor5r() - 0.01, colors->getColor5g(), colors->getColor5b());
		}
		if ((colors->getColor5g() + App::GetController().GetLeftThumbStickY() / 10) > 0 && (colors->getColor5g() + App::GetController().GetLeftThumbStickY() / 10) < 1)
			colors->setColor5(colors->getColor5r(), colors->getColor5g() + App::GetController().GetLeftThumbStickY() / 10, colors->getColor5b());
		if ((colors->getColor5b() + App::GetController().GetRightThumbStickY() / 10) > 0 && (colors->getColor5b() + App::GetController().GetRightThumbStickY() / 10) < 1)
			colors->setColor5(colors->getColor5r(), colors->getColor5g(), colors->getColor5b() + App::GetController().GetRightThumbStickY() / 10);
	}
}

void CustomizeMenu::chooseColor()
{
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, true))
	{
		colorChoice--;
		if (colorChoice == -1)
			colorChoice = 4;
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, true))
	{
		colorChoice++;
		if (colorChoice == 5)
			colorChoice = 0;
	}
}