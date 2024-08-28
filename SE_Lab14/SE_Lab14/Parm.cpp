#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm
{
    // ‘ункци€ дл€ получени€ и обработки параметров командной строки
    PARM getparm(int argc, _TCHAR* argv[])
    {
        // »нициализаци€ структуры PARM дл€ хранени€ параметров
        PARM parm;

        // Ћогические переменные дл€ проверки наличи€ об€зательных параметров
        bool hasIn = false;
        bool hasOut = false;
        bool hasLog = false;

        // ÷икл дл€ проверки наличи€ параметров -in, -out, -log
        for (int i = 0; i < argc; i++)
        {
            if (wcsstr(argv[i], PARM_IN))
                hasIn = true;

            if (wcsstr(argv[i], PARM_OUT))
                hasOut = true;

            if (wcsstr(argv[i], PARM_LOG))
                hasLog = true;
        }

        // ≈сли параметр -in отсутствует, выбрасываетс€ ошибка с кодом 100
        if (!hasIn)
            throw ERROR_THROW(100);

        // ÷икл дл€ обработки всех аргументов командной строки
        for (int i = 0; i < argc; i++)
        {
            // ѕроверка длины аргумента, если превышает PARM_MAX_SIZE, выбрасываетс€ ошибка с кодом 104
            if (wcslen(argv[i]) > PARM_MAX_SIZE)
                throw ERROR_THROW(104);

            // ≈сли найден параметр -in, копируем его значение в parm.in
            if (wcsstr(argv[i], PARM_IN))
                wcscpy_s(parm.in, wcsstr(argv[i], L":") + 1);

            // ≈сли найден параметр -out, копируем его значение в parm.out
            if (wcsstr(argv[i], PARM_OUT))
                wcscpy_s(parm.out, wcsstr(argv[i], L":") + 1);

            // ≈сли найден параметр -log, копируем его значение в parm.log
            if (wcsstr(argv[i], PARM_LOG))
                wcscpy_s(parm.log, wcsstr(argv[i], L":") + 1);
        }

        // ≈сли параметр -out отсутствует, устанавливаем его значение по умолчанию на основе parm.in
        if (!hasOut)
        {
            wcscpy_s(parm.out, parm.in);
            wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
        }

        // ≈сли параметр -log отсутствует, устанавливаем его значение по умолчанию на основе parm.in
        if (!hasLog)
        {
            wcscpy_s(parm.log, parm.in);
            wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
        }

        // ¬озвращаем структуру PARM с заполненными пут€ми к файлам
        return parm;
    }
};
