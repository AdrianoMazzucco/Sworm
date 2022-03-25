#pragma once
class colorScheme
{
	//purple
	float color1r = 0.73;
	float color1g = 0.4;
	float color1b = 1;

	//teal
	float color2r = 0.02;
	float color2g = 1;
	float color2b = 0.7;
	
	//pink
	float color3r = 1;
	float color3g = 0.44;
	float color3b = 0.8;

	//blue
	float color4r = 0;
	float color4g = 0.5;
	float color4b = 0.6;

	//yellow
	float color5r = 1;
	float color5g = 0.98;
	float color5b = 0.59;

public: void setColor1(float r, float g, float b);
		void setColor2(float r, float g, float b);
		void setColor3(float r, float g, float b);
		void setColor4(float r, float g, float b);
		void setColor5(float r, float g, float b);

		float getColor1r();
		float getColor1g();
		float getColor1b();

		float getColor2r();
		float getColor2g();
		float getColor2b();

		float getColor3r();
		float getColor3g();
		float getColor3b();

		float getColor4r();
		float getColor4g();
		float getColor4b();

		float getColor5r();
		float getColor5g();
		float getColor5b();
};

