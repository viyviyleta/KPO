#include "stdafx.h"

namespace Log
{
    // ������� ��� ������������� ����������� � �������� ����� ����
    LOG getlog(wchar_t logfile[])
    {
        LOG log = Log::INITLOG; // ������������� ��������� LOG

        log.stream = new std::ofstream(logfile); // �������� ����� ��� ������ ����

        // �������� ���������� �������� �����
        if (!log.stream)
            throw ERROR_THROW(112); // ���� ���� �� ��������, ����������� ������ � ����� 112

        return log;
    }

    // ������� ��� ������ ������ � ��� (������� � char*)
    void WriteLine(LOG log, char* c, ...)
    {
        char** p = &c;

        // ������ ���� �����, ���������� � �������� ����������
        while (*p != "")
        {
            (*log.stream) << *p;
            p += 1;
        }
    }

    // ������� ��� ������ ������ � ��� (������� � wchar_t*)
    void WriteLine(LOG log, wchar_t* c, ...)
    {
        wchar_t** p = &c;
        char buffer[64];

        // ������ ���� �����, ���������� � �������� ����������, � ��������������� �� wchar_t* � char*
        while (*p != L"")
        {
            wcstombs(buffer, *p, sizeof(buffer));
            (*log.stream) << buffer;
            p += 1;
        }
    }

    // ������� ��� ������ ��������� ���� � ������� ����� � ��������
    void WriteLog(LOG log)
    {
        char buffer[PARM_MAX_SIZE];

        time_t rawtime;
        struct tm* timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // �������������� ������� ���� � �������
        strftime(buffer, PARM_MAX_SIZE, "����: %d.%m.%y %H:%M:%S", timeinfo);
        (*log.stream) << "\n--�- �������� ��--\n" << buffer << "\n";
    }

    // ������� ��� ������ ���������� ��������� � ���
    void WriteParm(LOG log, Parm::PARM parm)
    {
        char inInfo[PARM_MAX_SIZE];
        char outInfo[PARM_MAX_SIZE];
        char logInfo[PARM_MAX_SIZE];

        // �������������� wchar_t* � char* ��� ������ � ���
        wcstombs(inInfo, parm.in, sizeof(inInfo));
        wcstombs(outInfo, parm.out, sizeof(outInfo));
        wcstombs(logInfo, parm.log, sizeof(logInfo));

        // ������ ���������� � ���
        (*log.stream) << "--�- ��������� ��--\n"
            << " -in:   " << inInfo << "\n"
            << " -out:  " << outInfo << "\n"
            << " -log:  " << logInfo << "\n";
    }

    // ������� ��� ������ ���������� � ������� ������ � ���
    void WriteIn(LOG log, In::IN in)
    {
        (*log.stream) << "--�- �������� ������ ��-- \n"
            << "���-�� ��������:   " << in.size << "\n"
            << "���-�� �����:      " << in.lines << "\n"
            << "���������:         " << in.ignor << "\n";
    }

    // ������� ��� ������ ���������� �� ������ � ���
    void WriteError(LOG log, Error::ERROR error)
    {
        // ���� ��� ������ 100, ������� ��������� �� �������
        if (error.id == 100)
        {
            cout << "������ " << error.id << ": " << error.message << "\n";
        }
        else
        {
            // ������ ������ � ��� � ��������� ������ � �������
            (*log.stream) << "������ " << error.id << ": " << error.message << " "
                << "������ " << error.inext.line << ", �������: " << error.inext.col << std::endl;
        }
    }

    // ������� ��� �������� ����� ����
    void Close(LOG log)
    {
        log.stream->close();
    }
};
