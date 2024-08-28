#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm
{
    // ������� ��� ��������� � ��������� ���������� ��������� ������
    PARM getparm(int argc, _TCHAR* argv[])
    {
        // ������������� ��������� PARM ��� �������� ����������
        PARM parm;

        // ���������� ���������� ��� �������� ������� ������������ ����������
        bool hasIn = false;
        bool hasOut = false;
        bool hasLog = false;

        // ���� ��� �������� ������� ���������� -in, -out, -log
        for (int i = 0; i < argc; i++)
        {
            if (wcsstr(argv[i], PARM_IN))
                hasIn = true;

            if (wcsstr(argv[i], PARM_OUT))
                hasOut = true;

            if (wcsstr(argv[i], PARM_LOG))
                hasLog = true;
        }

        // ���� �������� -in �����������, ������������� ������ � ����� 100
        if (!hasIn)
            throw ERROR_THROW(100);

        // ���� ��� ��������� ���� ���������� ��������� ������
        for (int i = 0; i < argc; i++)
        {
            // �������� ����� ���������, ���� ��������� PARM_MAX_SIZE, ������������� ������ � ����� 104
            if (wcslen(argv[i]) > PARM_MAX_SIZE)
                throw ERROR_THROW(104);

            // ���� ������ �������� -in, �������� ��� �������� � parm.in
            if (wcsstr(argv[i], PARM_IN))
                wcscpy_s(parm.in, wcsstr(argv[i], L":") + 1);

            // ���� ������ �������� -out, �������� ��� �������� � parm.out
            if (wcsstr(argv[i], PARM_OUT))
                wcscpy_s(parm.out, wcsstr(argv[i], L":") + 1);

            // ���� ������ �������� -log, �������� ��� �������� � parm.log
            if (wcsstr(argv[i], PARM_LOG))
                wcscpy_s(parm.log, wcsstr(argv[i], L":") + 1);
        }

        // ���� �������� -out �����������, ������������� ��� �������� �� ��������� �� ������ parm.in
        if (!hasOut)
        {
            wcscpy_s(parm.out, parm.in);
            wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
        }

        // ���� �������� -log �����������, ������������� ��� �������� �� ��������� �� ������ parm.in
        if (!hasLog)
        {
            wcscpy_s(parm.log, parm.in);
            wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
        }

        // ���������� ��������� PARM � ������������ ������ � ������
        return parm;
    }
};
