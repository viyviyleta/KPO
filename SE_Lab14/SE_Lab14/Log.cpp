#include "stdafx.h"

namespace Log
{
    // Функция для инициализации логирования и открытия файла лога
    LOG getlog(wchar_t logfile[])
    {
        LOG log = Log::INITLOG; // Инициализация структуры LOG

        log.stream = new std::ofstream(logfile); // Открытие файла для записи лога

        // Проверка успешности открытия файла
        if (!log.stream)
            throw ERROR_THROW(112); // Если файл не открылся, выбрасываем ошибку с кодом 112

        return log;
    }

    // Функция для записи строки в лог (вариант с char*)
    void WriteLine(LOG log, char* c, ...)
    {
        char** p = &c;

        // Запись всех строк, переданных в качестве аргументов
        while (*p != "")
        {
            (*log.stream) << *p;
            p += 1;
        }
    }

    // Функция для записи строки в лог (вариант с wchar_t*)
    void WriteLine(LOG log, wchar_t* c, ...)
    {
        wchar_t** p = &c;
        char buffer[64];

        // Запись всех строк, переданных в качестве аргументов, с преобразованием из wchar_t* в char*
        while (*p != L"")
        {
            wcstombs(buffer, *p, sizeof(buffer));
            (*log.stream) << buffer;
            p += 1;
        }
    }

    // Функция для записи заголовка лога с текущей датой и временем
    void WriteLog(LOG log)
    {
        char buffer[PARM_MAX_SIZE];

        time_t rawtime;
        struct tm* timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // Форматирование текущей даты и времени
        strftime(buffer, PARM_MAX_SIZE, "Дата: %d.%m.%y %H:%M:%S", timeinfo);
        (*log.stream) << "\n--—- Протокол ——--\n" << buffer << "\n";
    }

    // Функция для записи параметров программы в лог
    void WriteParm(LOG log, Parm::PARM parm)
    {
        char inInfo[PARM_MAX_SIZE];
        char outInfo[PARM_MAX_SIZE];
        char logInfo[PARM_MAX_SIZE];

        // Преобразование wchar_t* в char* для записи в лог
        wcstombs(inInfo, parm.in, sizeof(inInfo));
        wcstombs(outInfo, parm.out, sizeof(outInfo));
        wcstombs(logInfo, parm.log, sizeof(logInfo));

        // Запись параметров в лог
        (*log.stream) << "--—- Параметры ——--\n"
            << " -in:   " << inInfo << "\n"
            << " -out:  " << outInfo << "\n"
            << " -log:  " << logInfo << "\n";
    }

    // Функция для записи информации о входных данных в лог
    void WriteIn(LOG log, In::IN in)
    {
        (*log.stream) << "--—- Исходные данные ——-- \n"
            << "Кол-во символов:   " << in.size << "\n"
            << "Кол-во строк:      " << in.lines << "\n"
            << "Пропущено:         " << in.ignor << "\n";
    }

    // Функция для записи информации об ошибке в лог
    void WriteError(LOG log, Error::ERROR error)
    {
        // Если код ошибки 100, выводим сообщение на консоль
        if (error.id == 100)
        {
            cout << "Ошибка " << error.id << ": " << error.message << "\n";
        }
        else
        {
            // Запись ошибки в лог с указанием строки и позиции
            (*log.stream) << "Ошибка " << error.id << ": " << error.message << " "
                << "строка " << error.inext.line << ", позиция: " << error.inext.col << std::endl;
        }
    }

    // Функция для закрытия файла лога
    void Close(LOG log)
    {
        log.stream->close();
    }
};
