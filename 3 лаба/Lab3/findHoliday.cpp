#include "stdafx.h"

using namespace std;

void findHoliday(int dayNumber, int monthNumber) {
    const char* holidayToday[] = { "Мой день рождения", "День защитника отечества", "8 Марта", "День Святого Валентина", "День Победы", "День назависимости РБ", "Новый Год" };

    if (dayNumber == 25 && monthNumber == 5)
        cout << holidayToday[0];
    else if (dayNumber == 23 && monthNumber == 2)
        cout << "\nСегодня " << holidayToday[1];
    else if (dayNumber == 8 && monthNumber == 3)
        cout << "\nСегодя " << holidayToday[2];
    else if (dayNumber == 14 && monthNumber == 2)
        cout << "\nСегодня " << holidayToday[3];
    else if (dayNumber == 9 && monthNumber == 5)
        cout << "\nСегодня" << holidayToday[4];
    else if (dayNumber == 3 && monthNumber == 7)
        cout << "\nСегодня " << holidayToday[5];
    else if (dayNumber == 31 && monthNumber == 12)
        cout << "\nСегодня " << holidayToday[6];
    else
        cout << "\nХороший день";
}