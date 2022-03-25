#pragma once
class CustomizeMenu : public Menu
{
	public :
		void update(colorScheme* colors, int& state);
		void draw(colorScheme* colors);
		void updateColors(colorScheme* colors);
		void chooseColor();
};

