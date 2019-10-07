#include "Light.h"

bool Light::getOn()
{
	return on;
}
void Light::setOn(bool val)
{
	on = val;
}

int Light::getId()
{
	return id;
}
void Light::setId(int val)
{
	id = val;
}

int Light::getBri()
{
	return bri;
}
void Light::setBri(int val)
{
	bri = val;
}

int Light::getHue()
{
	return hue;
}
void Light::setHue(int val)
{
	hue = val;
}

int Light::getSat()
{
	return sat;
}
void Light::setSat(int val)
{
	sat = val;
}