#include "Dictionary.h"
#include "stdafx.h"
#include <iostream>

#if (defined(TEST_CREATE_01)+defined(TEST_CREATE_02)+defined(TEST_ADDENTRY_03)+defined(TEST_ADDENTRY_04)+defined(TEST_GETENTRY_05)+defined(TEST_GETENTRY_06)+defined(TEST_UPDENTRY_07)+defined(TEST_UPDENTRY_08)+defined(TEST_DICTIONARY))>1
#error "Ошибка"
#endif

using namespace dictionary;

int main() {
    setlocale(LC_ALL, "rus");
    try {
#ifdef TEST_CREATE_01
        Instance test1 = Create("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 5);
#endif
#ifdef TEST_CREATE_02
        Instance test2 = Create("test2", 100000000);
#endif
#ifdef TEST_ADDENTRY_03
        Instance test3 = Create("test3", 0);
        Entry en_test3 = { 1, "zzzzzz" };
        AddEntry(test3, en_test3);
#endif
#ifdef TEST_ADDENTRY_04
        Instance test4 = Create("test4", 5);
        Entry en_test4 = { 1, "zzzzzz" };
        AddEntry(test4, en_test4);
        AddEntry(test4, en_test4);
#endif
#ifdef TEST_GETENTRY_05
        Instance test5 = Create("test5", 5);
        Entry en_test5 = { 1, "zzzzzz" };
        AddEntry(test5, en_test5);
        GetEntry(test5, 2);
#endif
#ifdef TEST_GETENTRY_06
        Instance test6 = Create("test6", 5);
        Entry en_test6 = { 1, "zzzzzz" };
        AddEntry(test6, en_test6);
        DelEntry(test6, 2);
#endif
#ifdef TEST_UPDENTRY_07
        Instance test7 = Create("test7", 5);
        Entry test_e7 = { 1, "aaaaaaaaa" }, test_upd_e7 = { 2, "zzzzzzzz" };
        AddEntry(test7, test_e7);
        UpdEntry(test7, 3, test_upd_e7);
#endif
#ifdef TEST_UPDENTRY_08
        Instance test8 = Create("test8", 5);
        Entry test_e8 = { 1, "aaaaaaaaa" }, test_upd_e8 = { 1, "zzzzzzzz" };
        AddEntry(test8, test_e8);
        UpdEntry(test8, 1, test_upd_e8);
#endif
#ifdef TEST_DICTIONARY
        Instance d1 = Create("Студенты", 5);
        Entry e1 = { 10, "Бабич" }, e2 = { 2, "Березовский" }, e3 = { 34, "Угоренко" }, e4 = { 14, "Шутро" }, e5 = { 5, "Яскевич" };
        AddEntry(d1, e1);
        AddEntry(d1, e2);
        AddEntry(d1, e3);
        AddEntry(d1, e4);
        AddEntry(d1, e5);
        Print(d1);

        Instance d2 = Create("Преподаватели", 5);
        Entry s1 = { 1, "Барковский" }, s2 = { 2, "Белодед" }, s3 = { 3, "Наркевич" }, s4 = { 4, "Шиман" }, s5 = { 5, "Ярошевич" };
        AddEntry(d2, s1);
        AddEntry(d2, s2);
        AddEntry(d2, s3);
        AddEntry(d2, s4);
        AddEntry(d2, s5);
        Print(d2);
#endif
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }
    return 0;
}
