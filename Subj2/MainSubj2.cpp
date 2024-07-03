#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <string>
#include "Team.h"
using namespace std;


int main() {
	cout << "\n------------Default tests-------------\n";
	float inaltimidefault[4] = { 1.67, 1.88, 1.68, 1.94 };
	string numedefault[4] = { "Marcel", "Ionel", "Name3", "George" };
	Team testone("NumeEchipa", 4);

	testone.setHeights(inaltimidefault);
	testone.setNames(numedefault);

	for (int i = 0; i < testone.getNoMem(); i++) {
		cout << "\n" << i + 1 << ". Nume: " << testone.getNames()[i] << ", Inaltime: " << testone.getHeights()[i];
	}

	//testone.~Team(); //breaks program confirming destructor works

	cout << "\n------------Operator *=-------------\n";

	cout << "Before: " << testone.getUseless();
	testone *= 5;
	cout << "\nAfter: " << testone.getUseless();

	cout << "\n------------Function Operator-------------\n";

	testone("George", 4);
	testone("dsajgh", 3);

	cout << "\n Grade 5 achieved.\n";
	cout << "\n------------Copy ctor-------------\n";

	Team t = testone;
	testone.setNoMem(3);


	for (int i = 0; i < testone.getNoMem(); i++) {
		cout << "\n" << i + 1 << ". Nume: " << testone.getNames()[i] << ", Inaltime: " << testone.getHeights()[i];
	}
	cout << "\nVS\n";
	for (int i = 0; i < t.getNoMem(); i++) {
		cout << "\n" << i + 1 << ". Nume: " << t.getNames()[i] << ", Inaltime: " << t.getHeights()[i];
	}


	cout << "\n------------Operator=-------------\n";

	Team t2("AltaEchipa", 5);
	string n[5] = { "a", "b", "c", "d", "e" };
	float h[5] = { 2, 1.54, 1.76, 1.98, 1.80 };
	t2.setHeights(h);
	t2.setNames(n);

	for (int i = 0; i < t2.getNoMem(); i++) {
		cout << "\n" << i + 1 << ". Nume: " << t2.getNames()[i] << ", Inaltime: " << t2.getHeights()[i];
	}

	t2 = testone;
	cout << "\nVS\n";
	for (int i = 0; i < t2.getNoMem(); i++) {
		cout << "\n" << i + 1 << ". Nume: " << t2.getNames()[i] << ", Inaltime: " << t2.getHeights()[i];
	}
}