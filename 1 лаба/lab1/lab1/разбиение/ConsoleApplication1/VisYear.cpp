//#include <iostream>
#include "stdafx.h"
#include "countDay.h"
using namespace std;

int yearNumber;

void visyears() {

	if (yearNumber % 4 == 0 && yearNumber % 100 != 0) {
		cout << "���� ��� �������� ����������\n";
		visyear = true;
	}
	else {
		cout << "���� ��� �� �������� ����������\n";
	}
}