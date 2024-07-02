#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "ProdusAlimentar.h"

using namespace std;

/*float pret=0.0;
	int greutate =0;
	char* denumire = NULL;
	char categorie[100];
	int stocuriMagazine[50];
	int nrMagazine =0;
	int* vanzariPeZile = NULL;
	int nrZile = 0;*/

int main() {
	ProdusAlimentar prod;
	char cat[10] = "categorie";
	prod.setCategorie(cat);
	//prod.setNrMagazine(4);
	int* stocks = new int[4];
	for (int i = 0; i < 4; i++) stocks[i] = 2 * (i+1);
	int* vanzari = new int[7];
	for (int i = 0; i < 7; i++) vanzari[i] = (int)(i * i * 2 + 23 * i + 13);

	prod.setStocuriMagazine(stocks, 4);
	char denum[] = "Pateu";
	char denum1[] = "Lemn";
	prod.setDenumire(denum);
	prod.setGreutate(13);
	prod.setPret(65.75);
	prod.setVanzariPeZile(vanzari, 7);


	//cout << prod.getCategorie() << "\n";
	prod.printProdus();
	
	cout << "\n---------Setters and Getters tested--------------\n\n";

	ProdusAlimentar produscuparametrii(12.4, 55, denum1, cat, stocks, 4, vanzari, 7);
	produscuparametrii.printProdus();

	cout << "\n---------Constructor with parameters tested--------------\n\n";

	/*ProdusAlimentar empty;
	empty.printProdus();*/

	ProdusAlimentar Empty = produscuparametrii;
	Empty.printProdus();
	cout << "\n\nTesting shallow copy: ";
	produscuparametrii.setGreutate(9999999);
	Empty.printProdus();
	cout << "\n\n";
	produscuparametrii.printProdus();

	cout << "\n---------Copy constructor tested--------------\n\n";

}