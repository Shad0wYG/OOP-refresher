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

	/*ProdusAlimentar() {
		char denum[] = "denumire1";
		this->denumire = denum;
	}*/


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

	char* getCategorie() {
		char* ret = new char[101];
		strcpy(ret, this->categorie);
		return ret;
	}

	int* getStocuri() {
		int* ret = new int[50];
		memcpy(ret, this->stocuriMagazine, sizeof(int) * 50);
		return ret;
	}

	int getMagazine() {
		return this->nrMagazine;
	}

	int* getVanzariPeZile() {
		int* ret = new int[this->nrZile];
		for (int i = 0; i < this->nrZile; i++) {
			ret[i] = this->vanzariPeZile[i];
		}
		return ret;
	}

	int getZile() {
		return this->nrZile;
	}

#pragma endregion


#pragma region Setters
	void setPret(float num) {
		if (num > 0) this->pret = num;
	}
	void setGreutate(int weight) {
		if (weight > 0) this->greutate = weight;
	}
	void setDenumire(char* name) {

	}
	void setCategorie(char* cat) {

	}
	void setStocuriMagazine(int num) {

	}
	void setNrMagazine(int nr) {
		if (nr > 0) this->nrMagazine = nr;
	}
	void setVanzariPeZile(int nrDays, int* vect) {

	}
	void setNrZile(int nrD) {
		if (nrD > 1) this->nrZile = nrD;
	}



#pragma endregion


};
