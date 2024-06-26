#pragma once
#include <iostream>
#include <string>
using namespace std;

//date, temperature, description, location, etc.
class WeatherClass{
private: 
	string date = ""; //pretty sure this is bad but idk how to fix it yet
	float temperature = -1.0;
	char* desc = nullptr;
	string* locations = nullptr;

public:
	WeatherClass() {
		this->desc = (char*)malloc(sizeof(char) * 10);
	}

};

