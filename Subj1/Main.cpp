#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "WeatherClass.h"

using namespace std;

void main() {
	cout << "\n------Initial testing--------\n";

	WeatherClass w;
	string locations[5] = { "a", "b", "dsfg", "ggggggg", "34"};
	w.setLocations(locations, 5);

	for (int i = 0; i < 5; i++)
		cout <<"\n"<< w.getLocations()[i];

	//w.~WeatherClass();

	cout << "\n------Operator++ testing--------\n";


	WeatherClass Wprm(22, "Sunny");
	cout << "\n" << Wprm++;
	cout << "\n" << Wprm.temperature;

	Wprm.setNoLocs(5);
	Wprm.setLocations(locations);

	cout << "\n---------Testing overloading-----------\n";
	for (int i = 0; i < 5; i++)
		cout << "\n" << Wprm.getLocations()[i];


	cout << "\n Grade 5 achieved.\n";
}