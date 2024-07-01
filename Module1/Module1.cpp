#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void ex1PrintSomething() {
	cout << "\n----Ex1----\n";
	printf("\nThis is a message printed with printf :D");
	cout << endl << "This is a message printed with cout";
}

void ex2ConsoleInput() {
	cout << "\n----Ex2----\n";
	cout << "Input a number: ";
	double a;
	scanf("%lf", &a);
	cout << "Inputted value: " << a;
	cout << "\nInput a char: ";
	char b;
	cin >> b;
	printf("\nInputted value: %c with ascii code %d", b, (int)b);

}

void exs3to5() {
	cout << "\n\n----Exercises 3,4,5----\nGimme 2 nrs: ";
	int a, b;
	if (cin >> a >> b)
	{
		if (a > b) {
			printf("\nMinimum is %d, maximum is %d", b, a);
		}
		else if (a != b) {
			printf("\nMinimum is %d, maximum is %d", a, b);
		}
		else printf("\nNumbers are equal.");

		cout << "\nSum is: " << a + b;
	}
	else cout << "Those ain't numbers";
}

int main() {
	ex1PrintSomething();
	ex2ConsoleInput(); 
	exs3to5();


}