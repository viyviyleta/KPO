using namespace std;


int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool visyear = false;
int yearNumber, dayNumber, monthNumber, dayNumberBirthday, monthNumberBirthday;
int birthdaydays, difference;

int countDay(int day, int monthNumber) {
	int days = 0;
	for (int i = 0; i < monthNumber -1; i++)
	{
		days += months[i];
	}
	days += day;
	if (monthNumber > 2 && visyear) {
		days += 1;
	}

	return days;
}

void visyears() {
	
	if (yearNumber % 4 == 0 && yearNumber % 100 != 0) { 
		cout << "Этот год является високосным\n";
		visyear = true;
	}
	else {
		cout << "Этот год не является високосным\n";
	}
}

void number1() {
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
}
	
	
