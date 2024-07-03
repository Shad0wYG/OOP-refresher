#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Conference
{
private:
	static int idCounter;

	const int id;
	float entryPrice = 0.0;
	char* date = nullptr;

public: 
#pragma region Accessors
	int getID() {
		return this->id;
	}
	float getPrice() {
		return this->entryPrice;
	}

	char* getDate(){
		char* res = new char[strlen(this->date) + 1];
		strcpy(res, this->date);
		return res;
	}

	void setPrice(float p) {
		if (p > 0) this->entryPrice = p;
	}

	void setDate(const char* buff) {
		if (strlen(buff) <= 0) return;
		this->date = new char[strlen(buff) + 1];
		strcpy(this->date, buff);

	}
#pragma endregion

	Conference(float p, const char* date): id(++idCounter) {
		this->setDate(date);
		this->setPrice(p);

	}

	/*Conference(Conference& c) {

	}*/

	Conference(): id(++idCounter) {

	}

	~Conference() {
		cout << "\nDestructor on " << this->id;
		delete[] this->date;
	}

	bool operator<(const Conference& other) {
		int y1, y2;
		y1 = atoi(&(this->date[6]));
		y2 = atoi(&(other.date[6]));
		if (y1 < y2) return true;
		return false;
	}


	friend void operator+ (float price, Conference& c);
};

int Conference::idCounter = 0;


void operator+ (float price, Conference& c) {
	c.entryPrice += price;
}