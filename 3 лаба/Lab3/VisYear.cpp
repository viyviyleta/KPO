#include "stdafx.h"

using namespace std;

int yearNumber;

void visyears() {

	if (yearNumber % 4 == 0 && yearNumber % 100 != 0) {
		cout << "Этот год является високосным\n";
		visyear = true;
	}
	else {
		cout << "Этот год не является високосным\n";
	}
}