#include "stdafx.h"
#include "countDay.h"
#include "VisYear.h"

using namespace std;



int dayNumber, monthNumber, dayNumberBirthday, monthNumberBirthday;
int birthdaydays, difference;

void main() {
	setlocale(0, "");
		
	int date, birthday, dayss;

	cout << "Введите дату в формате ДДММГГГГ: ";
	cin >> date;

	cout << "Введите дату вашего дня рождения в формате ДДММГГГГ: ";
	cin >> birthday;



	dayNumber = date / 1000000;
	monthNumber = (date % 1000000) / 10000;
	yearNumber = date % 10000;

	dayNumberBirthday = birthday / 1000000;
	monthNumberBirthday = (birthday % 1000000) / 10000;

	cout << "День: " << dayNumber << endl;
	cout << "Месяц: " << monthNumber << endl;
	cout << "Год: " << yearNumber << endl;



	if (visyear && monthNumber == 2 && yearNumber > 0) {

	}
	else if (dayNumber <= 0 || monthNumber <= 0 || monthNumber > 12 || yearNumber <= 0 || dayNumber > months[monthNumber - 1]) {
		cout << "Некорректная дата" << endl;
		return;
	}


	visyears();

	cout << "Порядковый номер дня в году: " << countDay(dayNumber, monthNumber);

	dayss = countDay(dayNumber, monthNumber);
	birthdaydays = countDay(dayNumberBirthday, monthNumberBirthday);

	if (birthdaydays == dayss) {
		cout << "\nСегодня твой день рождения!" << endl;
	}
	else if (birthdaydays > dayss) {
		difference = birthdaydays - dayss;
		cout << "\nТвой день рождения через: " << difference << " дней" << endl;
	}
	else if (!visyear) {
		difference = 365 - dayss + birthdaydays;
		cout << "\nТвой день рождения через: " << difference << " дней" << endl;
	}
	else {
		difference = 366 - dayss + birthdaydays;
		cout << "\nТвой день рождения через: " << difference << " дней" << endl;
	}

	/*return 0;*/
}