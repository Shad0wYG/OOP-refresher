#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Conference.h"
using namespace std;

int main() {
	Conference cons1(12, "13/12/1998");
	cout << "\nBasics------------\n";
	printf("\nId conf: %d\nDate: %s\nPrice: %.2f", cons1.getID(), cons1.getDate(), cons1.getPrice());

	cout << "\nOperator+-------------\n";
	5 + cons1;
	printf("\nId conf: %d\nDate: %s\nPrice: %.2f", cons1.getID(), cons1.getDate(), cons1.getPrice());

	cout << "\nCompare operator----------\n";
	Conference cons2(99, "02/02/2024");
	(cons1 < cons2) ? cout<<"First conference is older" : cout<<"Second conference is older";
}