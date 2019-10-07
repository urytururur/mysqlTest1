#pragma once

class Light
{
private:

	bool on;
	int id, bri, hue, sat;

public:

	bool getOn();
	void setOn(bool val);

	int getId();
	void setId(int val);

	int getBri();
	void setBri(int val);

	int getHue();
	void setHue(int val);

	int getSat();
	void setSat(int val);
};