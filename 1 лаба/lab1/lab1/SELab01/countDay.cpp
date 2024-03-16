#include "stdafx.h"

int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool visyear = false;

int countDay(int day, int monthNumber) {
	int days = 0;
	for (int i = 0; i < monthNumber - 1; i++)
	{
		days += months[i];
	}
	days += day;
	if (monthNumber > 2 && visyear) {
		days += 1;
	}

	return days;
}