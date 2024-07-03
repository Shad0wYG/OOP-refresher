#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//date, temperature, description, location, etc.
class WeatherClass{
private: 
	const int id;
	string date = ""; 
public: float temperature = -273.0;
private:
	char* desc = nullptr;
	string* locations = nullptr;
	int noLocs = 0;

public:
	static int idCount;

#pragma region Accessors
	string* getLocations() {
		if (this->locations == nullptr) return nullptr;
		string* res = new string[this->noLocs];
		for (int i = 0; i < this->noLocs; i++) res[i] = this->locations[i];
		return res;
	}


	void setNoLocs(int val) {
		this->noLocs = val;
	}

	void setLocations(string* locs, int locnr) {
		if (locnr < 1) {
			this->noLocs = 0;
			this->locations = nullptr;
		}
		if (this->locations != nullptr) delete[] this->locations;

		this->noLocs = locnr;
		this->locations = new string[locnr];
		for (int i = 0; i < this->noLocs; i++) {
			this->locations[i] = locs[i];
		}

	}

	void setLocations(string* locs) {
		if (this->noLocs > 1) {
			if (this->locations != nullptr) delete[] this->locations;
			this->locations = new string[this->noLocs];
			for (int i = 0; i < this->noLocs; i++) {
				this->locations[i] = locs[i];
			}
		}
	}

#pragma endregion

	WeatherClass(float temp, const char Desc[]) : id(++idCount) {
		this->desc = new char[strlen(Desc) + 1];
		strcpy(this->desc, Desc);
		this->temperature = temp;
	}

	WeatherClass() : id(++idCount) {
		this->desc = (char*)malloc(sizeof(char) * 10);
	}


	~WeatherClass() {
		cout << "\nDestr";
		if (this->desc != nullptr) {
			delete[] this->desc; 
			this->desc = nullptr;
		}
		if (this->locations != nullptr) {
			delete[] this->locations;
			this->locations = nullptr;
		}

		idCount--;
	}


	int operator++(int) {
		int res = this->temperature;
		this->temperature = (this->temperature + 100);
		return res;
	}

};


int WeatherClass::idCount = 0;
