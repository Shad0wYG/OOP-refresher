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
		if (strlen(name) < 1) this->denumire = nullptr;
		else
		{
			char* ret = new char[strlen(name) + 1];
			strcpy(ret, name);
			this->denumire = ret;
		}
	}
	void setCategorie(char* cat) {
		if (strlen(cat) <= 100 && strlen(cat) > 0) {
			strcpy(this->categorie, cat);
		}
		else strcpy(this->categorie, "-");
	}
	void setStocuriMagazine(int* num, int nrMag) {
		if (nrMag > 0 && nrMag <= 50)
		{
			this->nrMagazine = nrMag;
			memcpy(this->stocuriMagazine, num, sizeof(int) * nrMag);
		}
		else memcpy(this->stocuriMagazine, 0, sizeof(int) * 1);
	}
	void setNrMagazine(int nr) {
		if (nr > 0) this->nrMagazine = nr;
	}
	void setVanzariPeZile(int* vect, int nrDays) {
		if (nrDays > 0) {
			this->nrZile = nrDays;
			this->vanzariPeZile = new int[nrDays];
			memcpy(this->vanzariPeZile, vect, sizeof(int) * nrDays);
		}
		else {
			this->nrZile = 0;
			this->vanzariPeZile = nullptr;
		}
	}
	void setNrZile(int nrD) {
		if (nrD > 1) this->nrZile = nrD;
	}



#pragma endregion


	void printProdus() {
		printf("\nDenumire: %s\nCategorie: %s\nPret: %f\nGreutate: %d", this->getDenumire(),this->getCategorie(), this->getPret(), this->getGreutate());
		printf("\nNumar de magazine: %d\nStocuri: ", this->getMagazine());
		for (int i = 0; i < this->getMagazine(); i++) 
			cout << this->getStocuri()[i] << " ";

		printf("\nNumar de zile: %d\nVanzari pe zile: ", this->getZile());
		for (int i = 0; i < this->getZile(); i++)
			cout << this->getVanzariPeZile()[i] << " ";
	}

#pragma region Constructors/Destructors

	ProdusAlimentar(float Pret, int Greutate, char* Denumire, char* Categorie, int* Stocuri, int NrMag, int* Vanzari, int NrZile):
		pret(Pret), greutate(Greutate) 
	{
		setDenumire(Denumire);
		setCategorie(Categorie);
		setStocuriMagazine(Stocuri, NrMag);
		setVanzariPeZile(Vanzari, NrZile);

	}

	ProdusAlimentar() {}


	~ProdusAlimentar() {
		cout << "\nDestructor on " << this->getDenumire() << ", pret: " << this->getPret();
		delete this->denumire;
		delete this->vanzariPeZile;
	}

	
	ProdusAlimentar(ProdusAlimentar& prod) {
		cout << "\n Copy ctor called with object " << prod.denumire << " , price: " << prod.pret;
		this->setCategorie(prod.categorie);
		this->setDenumire(prod.denumire);
		this->setGreutate(prod.greutate);
		this->setPret(prod.pret);
		this->setStocuriMagazine(prod.stocuriMagazine, prod.nrMagazine);
		this->setVanzariPeZile(prod.vanzariPeZile, prod.nrZile);
	}


#pragma endregion
};
