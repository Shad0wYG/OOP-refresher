#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class ProdusAlimentar {
#pragma region Attributes
private:
	float pret=0.0;
	int greutate =0;
	char* denumire = NULL;
	char categorie[100];
	int stocuriMagazine[50];
	int nrMagazine =0;
	int* vanzariPeZile = NULL;
	int nrZile = 0;

#pragma endregion

public:

	ProdusAlimentar() {
		char denum[] = "denumire1";
		this->denumire = denum;
	}


#pragma region Getters
	float getPret() {
		return this->pret;
	}

	int getGreutate() {
		return this->greutate;
	}

	char* getDenumire() {
		if (this->denumire) {
			char* denum = new char[strlen(this->denumire) + 1];
			strcpy(denum, this->denumire);
			return denum;
		}

	}

	//??
	char* getCategorie() {
		return this->categorie;
	}

#pragma endregion

};
