#pragma once
#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <string>
using namespace std;

class Team
{
private:
	char teamName[20] = "";
	float* memberHeights = nullptr;
	string* memberNames = nullptr;
	int noMembers = 0;
	double attributeThatDoesntMatter = 1;

public:

	void setNoMem(int n) {
		if (n > 0) this->noMembers = n;
	}

	void setHeights(float* hs) {
		if (hs == nullptr) return;
		if (this->memberHeights != nullptr) delete[] this->memberHeights;
		this->memberHeights = new float[this->noMembers];
		memcpy(this->memberHeights, hs, sizeof(float) * this->noMembers);

	}

	void setNames(string* names) {
		if (names == nullptr) return;
		if (this->memberNames != nullptr) delete[] this->memberNames;
		this->memberNames = new string[this->noMembers];

		for (int i = 0; i < this->noMembers; i++) {
			this->memberNames[i] = names[i];
		}

	}

	int getNoMem() {
		return this->noMembers;
	}

	float* getHeights() {
		float* res = new float[this->noMembers];
		memcpy(res, this->memberHeights, sizeof(float) * this->noMembers);
		return res;
	}

	string* getNames() {
		string* res = new string[this->noMembers];
		for (int i = 0; i < this->noMembers; i++) {
			res[i] = this->memberNames[i];
		}
		return res;
	}

	double getUseless() {
		return this->attributeThatDoesntMatter;
	}

	//----------------End of accessors--------------


	Team(const char name[], int nrMembr) {
		this->setNoMem(nrMembr);
		strcpy(this->teamName, name);
	}



	~Team() {
		cout << "\nDestructor on " << this->teamName;
		//if (this->memberNames != nullptr) 
			delete[] this->memberNames;
		//if (this->memberHeights != nullptr) 
			delete[] this->memberHeights;
	}

	//Wtf is that below me Scoob
	Team(Team& t): attributeThatDoesntMatter(t.attributeThatDoesntMatter), noMembers(t.noMembers) {
		cout << "\nCopy Ctor";
		strcpy(this->teamName, t.teamName);
		this->setHeights(t.getHeights());
		this->setNames(t.getNames());
	}

	void operator *=(int x) {
		this->attributeThatDoesntMatter *= x;
	}

	void operator() (string name, int pos) {
		pos -= 1;
		//if (strcmp(name.c_str(), this->getNames()[pos].c_str()) == 0) {
		if(name._Equal(this->getNames()[pos])){
			printf("\nYes, %s is indeed the member on position %d", this->getNames()[pos].c_str(), pos + 1);
		}
		else printf("\nNo, the name on position %d is %s", pos + 1, this->getNames()[pos].c_str());
	}

	void operator=(Team& rightOp) {
		//strcpy(this->teamName, rightOp.teamName);
		this->noMembers = rightOp.noMembers;
		this->attributeThatDoesntMatter = rightOp.attributeThatDoesntMatter;
		if (this->memberHeights) delete[] this->memberHeights;
		if (this->memberNames) delete[] this->memberNames;
		this->memberHeights = new float[this->noMembers];
		this->memberNames = new string[this->noMembers];
		for (int i = 0; i < this->noMembers; i++) {
			this->memberHeights[i] = rightOp.memberHeights[i];
			this->memberNames[i] = rightOp.memberNames[i];
		}

	}

};

