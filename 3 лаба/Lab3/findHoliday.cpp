#include "stdafx.h"

using namespace std;

void findHoliday(int dayNumber, int monthNumber) {
    const char* holidayToday[] = { "��� ���� ��������", "���� ��������� ���������", "8 �����", "���� ������� ���������", "���� ������", "���� ������������� ��", "����� ���" };

    if (dayNumber == 25 && monthNumber == 5)
        cout << holidayToday[0];
    else if (dayNumber == 23 && monthNumber == 2)
        cout << "\n������� " << holidayToday[1];
    else if (dayNumber == 8 && monthNumber == 3)
        cout << "\n������ " << holidayToday[2];
    else if (dayNumber == 14 && monthNumber == 2)
        cout << "\n������� " << holidayToday[3];
    else if (dayNumber == 9 && monthNumber == 5)
        cout << "\n�������" << holidayToday[4];
    else if (dayNumber == 3 && monthNumber == 7)
        cout << "\n������� " << holidayToday[5];
    else if (dayNumber == 31 && monthNumber == 12)
        cout << "\n������� " << holidayToday[6];
    else
        cout << "\n������� ����";
}