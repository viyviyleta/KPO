#include "stdafx.h"

namespace In
{
    // Функция для чтения входных данных из файла
    IN getin(wchar_t infile[])
    {
        IN in; // Структура для хранения входных данных

        // Инициализация полей структуры IN
        in.lines = 0;
        in.size = 0;
        in.ignor = 0;
        int position = 0;

        // Выделение памяти для хранения входного текста
        unsigned char* inText = new unsigned char[IN_MAX_LEN_TEXT];
        unsigned char inputChar = ' ';

        // Открытие входного файла для чтения
        ifstream fileInput(infile);

        // Проверка успешности открытия файла
        if (fileInput.fail())
            throw ERROR_THROW(110); // Если файл не открылся, выбрасываем ошибку с кодом 110

        // Считывание первого символа из файла
        inputChar = fileInput.get();

        // Основной цикл чтения символов из файла
        while (in.size <= IN_MAX_LEN_TEXT)
        {
            // Проверка на конец файла
            if (fileInput.eof())
            {
                inText[in.size] = '\0'; // Добавляем завершающий нуль-символ
                break;
            }

            // Если текущий символ - новая строка, увеличиваем счетчик строк
            if (inputChar == '\n' && in.code['\n'] != IN::F)
            {
                position = -1;
                in.lines++;
            }

            // Обработка символа в зависимости от его кода
            switch (in.code[(unsigned char)inputChar])
            {
            case IN::S: // S = 8192 (символ S)
            case IN::O: // O = 16384 (символ O)
            case IN::T: // T = 1024 (символ T)
                position++;
                inText[in.size] = inputChar; // Добавляем символ в текст
                in.size++;
                break;

            case IN::F: // F = 2048 (ошибка)
                throw ERROR_THROW_IN(111, in.lines, position); // Выбрасываем ошибку с кодом 111

            case IN::I: // I = 4096 (игнорируемый символ)
                in.ignor++;
                break;

            default: // Замена символа на его код
                inText[in.size] = in.code[(unsigned char)inputChar];
                position++;
                in.size++;
            }

            // Считывание следующего символа из файла
            inputChar = fileInput.get();
        }

        // Удаление повторяющихся пробелов из исходного текста
        unsigned char* textWithoutSpaces = new unsigned char[IN_MAX_LEN_TEXT];
        int j = 0;

        // Цикл для копирования символов, исключая повторяющиеся пробелы
        for (int i = 0; i < in.size; i++)
        {
            if (inText[i] == ' ' && inText[i + 1] == ' ')
                continue; // Пропускаем повторяющиеся пробелы

            else
            {
                textWithoutSpaces[j] = inText[i];
                j++;
            }
        }

        // Запись обработанного текста и обновление размера текста
        in.text = textWithoutSpaces;
        in.text[j] = '\0';
        in.size = j; // Переопределяем длину согласно тексту без повторяющихся пробелов

        // Закрытие входного файла
        fileInput.close();

        // Возвращаем структуру с входными данными
        return in;
    }
};
