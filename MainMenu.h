#pragma once

class MainMenu : public Menu
{
	float startColor1 = 1, startColor2 = 1, startColor3 = 1;
	float controlsColor1 = 1, controlsColor2 = 1, controlsColor3 = 1;
	float custimizeColor1 = 1, custimizeColor2 = 1, custimizeColor3 = 1;
	float exitColor1 = 1, exitColor2 = 1, exitColor3 = 1;
public : void update(colorScheme* colors, int& state);
		void draw();
		void setMenu();
		void selectOption();
};

