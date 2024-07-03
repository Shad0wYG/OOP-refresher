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
	char* denumire = nullptr;
	char categorie[100];
	int stocuriMagazine[50];
	int nrMagazine =0;
	int* vanzariPeZile = nullptr;
	int nrZile = 0;

#pragma endregion

public:
void printProdus() {
		printf("\nDenumire: %s\nCategorie: %s\nPret: %f\nGreutate: %d", this->getDenumire(), this->getCategorie(), this->getPret(), this->getGreutate());
		printf("\nNumar de magazine: %d\nStocuri: ", this->getMagazine());
		for (int i = 0; i < this->getMagazine(); i++)
			cout << this->getStocuri()[i] << " ";

		printf("\nNumar de zile: %d\nVanzari pe zile: ", this->getZile());
		for (int i = 0; i < this->getZile(); i++)
			cout << this->getVanzariPeZile()[i] << " ";
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
		if (this->vanzariPeZile == nullptr) return nullptr;
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
			if (this->denumire != nullptr) delete[] this->denumire;
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
			if (this->vanzariPeZile != nullptr) delete[] this->vanzariPeZile;
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

#pragma region Operators
	//List: operator=, >> , << , + , - , * , / , ++ , -- , += , -= , *= , /= , [] , cast , ! , comma(?) , () , ->

	ProdusAlimentar operator=(const ProdusAlimentar& source) {
		cout << "\n Operator= called.";
		if (this == &source) return *this;

		if (this->denumire) delete[] this->denumire;
		if (this->vanzariPeZile) delete[] this->vanzariPeZile;

		char cat[100]; int stocuri[50];
		strcpy(cat, source.categorie);
		memcpy(stocuri, source.stocuriMagazine, sizeof(int) * source.nrMagazine);

		this->setCategorie(cat);
		this->setDenumire(source.denumire);
		this->setGreutate(source.greutate);
		this->setPret(source.pret);
		this->setStocuriMagazine(stocuri, source.nrMagazine);
		this->setVanzariPeZile(source.vanzariPeZile, source.nrZile);

		return *this;
	}

	//Ik this sucks but i literally dont know if i can do it any other way
	ProdusAlimentar& operator+(const ProdusAlimentar& rightOp) {
		//ProdusAlimentar res = *this;
		int resMag = this->getMagazine() + rightOp.nrMagazine;
		int* resStocks = new int[resMag];
		memcpy(resStocks, this->getStocuri(), sizeof(int) * this->getMagazine());
		memcpy(&(resStocks[this->getMagazine()]), rightOp.stocuriMagazine, sizeof(int)*rightOp.nrMagazine);

		this->setStocuriMagazine(resStocks, resMag);

		return *this;
	}

	int operator[] (int val) {
		return this->getVanzariPeZile()[val];
	}

	 operator float() { //explicit operator float() to use it as (float)obj
		return this->pret;
	}

	 ProdusAlimentar operator++() { //prefix
		 this->setGreutate(this->getGreutate() + 1);
		 return *this;
	 }

	 ProdusAlimentar operator++(int) { //postfix
		 ProdusAlimentar res = *this;
		 this->setGreutate(this->getGreutate() + 1);
		 return res;
	 }

	 bool operator!() {
		 if (this->getVanzariPeZile() == nullptr) return true;
		 return false;
	 }

#pragma endregion
};

void operator<<(ostream& out, ProdusAlimentar& p) {
	out << "\nDenumire: " << p.getDenumire() << "\nCategorie: " << p.getCategorie() << "\nPret: " << p.getPret() << "\nGreutate: " << p.getGreutate();
	out << "\n Numar de magazine: " << p.getMagazine() << "\nStocuri: ";
	for (int i = 0; i < p.getMagazine(); i++)
		out << p.getStocuri()[i] << " ";

	out << "\n Numar de zile: " << p.getZile() << "\nVanzari: ";
	for (int i = 0; i < p.getZile(); i++)
		out << p.getVanzariPeZile()[i] << " ";
}

void operator>>(istream& in, ProdusAlimentar& p) {
	char buffer[255];
	int* arr = nullptr;
	int size = 0;
	cout << "\nDenumire: ";
	in.getline(buffer, 255);
	in.clear();
	p.setDenumire(buffer);

	cout << "Categorie: ";
	in.getline(buffer, 255);
	in.clear();
	p.setCategorie(buffer);

	cout << "Pret: ";
	in.getline(buffer, 255);
	in.clear();
	p.setPret(atof(buffer));

	cout << "Greutate: ";
	in.getline(buffer, 255);
	in.clear();
	p.setGreutate(atoi(buffer));

	cout << "Numar de magazine si stocuri: ";
	in >> size; in.clear();
	arr = new int[size];
	for (int i = 0; i < size; i++) in >> arr[i];
	p.setStocuriMagazine(arr, size);
	delete[]arr;
	
	cout << "Numar de zile si vanzari: ";
	in >> size; in.clear();
	arr = new int[size];
	for (int i = 0; i < size; i++) in >> arr[i];
	p.setVanzariPeZile(arr, size);
	delete[]arr;
}