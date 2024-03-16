#include <iostream>
#include <locale>

using namespace std;
//проверка на корректность
bool correctness(int day, int mounth, int year) {

    if (year < 0) {
        return false;
    }
    if (mounth < 1 || mounth > 12) {
        return false;
    }

    int Inmonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = Inmonth[mounth - 1];
    if (day < 1 || day > maxDay) {
        return false;
    }
    return true;
}

//является, ли год високосным
bool LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//вычисление порядкового номера дня в веденном году
int Day_that_was_entered(int day, int mounth, int year) {
    int o = 0;
    int Inmonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 1; i < mounth; i++) {
        o += Inmonth[i - 1];
    }

    if (LeapYear(year) && mounth > 2) {
        o++;
    }

    o += day;
    return o;
}

int UBirthday(int cd, int cm, int cy, int bd, int bm) {
    int co = Day_that_was_entered(cd, cm, cy);
    int bo = Day_that_was_entered(bd, bm, cy);

    if (bo > co) {
        bo += LeapYear(cy + 1) ? 366 : 365;
    }

    return co - bo;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int day, mounth, year;
    cout << "Введите дату в формате ДДММГГГГ: ";
    cin >> day >> mounth >> year;

    if (!correctness(day, mounth, year)) {
        cout << "Некорректная дата!" << endl;
        return 1;
    }

    cout << "Введенный год " << (LeapYear(year) ? "високосный" : "не високосный") << endl;

    int o = Day_that_was_entered(day, mounth, year);
    cout << "Порядковый номер введенного дня в году: " << o << endl;

    int cd = 25; // Введите текущий день вашего рождения
    int cm = 5; // Введите текущий месяц вашего рождения
    int cy = 2024; // Введите текущий год вашего рождения
    int du = UBirthday(cd, cm, cy, day, mounth);
    cout << "Дней до ближайшего дня вашего рождения: " << du << endl;

    return 0;
}
