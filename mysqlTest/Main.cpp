// 
//-------MYSQL----------
//OBS! Det behövdes läggas till bibliotek och dependencies för att detta program skulle funka!

#include "Main.h"

#include "stdafx.h"
#include <mysql.h>
#include <iostream>
#include "Light.h"

#include <string>

Main::Main()
{
	addLights(lights, 10);

	getData();
}

using namespace std;
int qstate;

int main()
{

	Main main = Main();

	return 0;
}

void Main::addLights(vector<Light>& vector, int vectorSize)
{
	for (int i = 0; i < vectorSize; i++)
	{
		Light newLight = Light();
		vector.push_back(newLight);
	}
	
}

void Main::getData()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "155.4.151.137", "remoteuser", "urytururur", "test1", 3306, NULL, 0);
	//conn = mysql_real_connect(conn, "localhost", "root", "urytururur", "smarthome", 3306, NULL, 0);

	if (conn) {
		puts("Successful connection to database!");

		string query = "SELECT * FROM lights";
		const char* q = query.c_str();

		while (true)
		{
			qstate = mysql_query(conn, q);
			if (!qstate)
			{
				res = mysql_store_result(conn);

				int i = 0;
				while (row = mysql_fetch_row(res))
				{
					lights[i].setId(std::stoi(row[0]));
					lights[i].setOn(std::stoi(row[1]));
					lights[i].setBri(std::stoi(row[2]));
					lights[i].setHue(std::stoi(row[3]));
					lights[i].setSat(std::stoi(row[4]));

					cout << "ID: " << lights[i].getId() << endl;
					cout << "ON: " << lights[i].getOn() << endl;
					cout << "BRI: " << lights[i].getBri() << endl;
					cout << "HUE: " << lights[i].getHue() << endl;
					cout << "SAT: " << lights[i].getSat() << endl << endl;

					i++;
				}
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
			}

			system("pause");
		}


	}
	else {
		puts("Connection to database has failed!");
	}
}