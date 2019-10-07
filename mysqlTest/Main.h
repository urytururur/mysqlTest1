#pragma once

#include <vector>
#include "stdafx.h"
#include <mysql.h>
#include <iostream>
#include "Light.h"

using namespace std;

class Main
{
private:

	vector<Light> lights;

public:

	Main();

	void addLights(vector<Light>& vector, int vectorSize);

	void getData();


};