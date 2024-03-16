#include <iostream>
#include <windows.h> 
using namespace std;

char f1(char c) {
    return c;
}
char f2(char c) {
    return c;
}

int main()
{
    setlocale(0, "");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //1-е задание
    int n, x, y, z;
    float s;
    cout << "Введите порядковый номер вашего варианта в списке: ";
    cin >> n;
    x = 9 + n;
    y = 10 + n;
    z = 11 + n;
    s = 1.0 + n;

    //2-е задание
    bool var1 = true; // true в C++ интерпретируется как 1, в шестнадцатеричной системе это 0x1
    bool var2 = false; // false в C++ интерпретируется как 0, в шестнадцатеричной системе это 0x0

    //3-е задание 
    char english_surname = 'a'; // символ 'a' в ASCII кодируется как 0x61
    char rus_surename = 'а'; // символ 'а' в ASCII кодируется как 0xd0

    //4-е задание 
    wchar_t engl_name = L'i'; // символ 'i' в Unicode кодируется как 0x69
    wchar_t rus_name = L'и'; // символ 'и' в Unicode кодируется как 0x438

    //5-e задание
    short X = 0x0001; // 1 в шестнадцатеричной системе это 0x0001
    short negativeShort = -X; // -1 в шестнадцатеричной системе это 0xffff
    short maxShort = SHRT_MAX; // максимальное значение short это 0x7fff
    short minShort = SHRT_MIN; // минимальное значение short это 0x8000
    unsigned short maxUnsignedShort = 0xFFFF; // максимальное беззнаковое short это 0xffff
    unsigned int minUnsignedInt = 0x0000; // минимальное беззнаковое int это 0x0000

    //6-e задание 
    int Y = 0x001; // 1 в шестнадцатеричной системе это 0x0001
    int negativey = -Y; // -1 в шестнадцатеричной системе это 0xffffffff
    int maxint = 0x7fffffff; // максимальное значение int это 0x7fffffff
    int minint = 0x80000000; // минимальное значение int это 0x80000000

    //7-е задание
    unsigned long maxulong = 0xffffffffffffffff; // максимальное беззнаковое long это 0xffffffffffffffff
    unsigned long minulong = 0x0; // минимальное беззнаковое long это 0x0

    //8-е задание
    long int Z = 0x7fffffffffffffff; // максимальное значение long это 0x7fffffffffffffff
    long negativez = -Z; // минимальное значение long это 0x8000000000000000
    long maxlong = 0x7fffffffffffffff; // максимальное значение long это 0x7fffffffffffffff
    long minlong = 0x000000000000000; // минимальное значение long это 0x000000000000000

    //9-е задание
    float S = 10.5f; //0.100.10101010000000000000000 //0x40AA8000
    float negativeS = -S;//1.100.10101010000000000000000
    float positiveInf = S / 0;
    float negativeInf = negativeS / 0;
    float negativeInd = negativeInf + positiveInf;

    //10-е задание 
    char* pointerChar = &english_surname;
    wchar_t* pointerWChar = &engl_name;
    short* pointerShort = &negativeShort;
    int* pointerInt = &n;
    float* pointerFloat = &negativeS;

    // Увеличиваем значения указателей на 3
    pointerChar += 3;
    pointerWChar += 3;
    pointerShort += 3;
    pointerInt += 3;
    pointerFloat += 3;

    char (*f[])(char) = { f1, f2 }; // Объявление массива указателей на функции и их инициализация
     
    char result = (*f[0])('a');
    char result1 = (*f[1])('c');

    return 0;
}
