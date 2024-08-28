#include "stdafx.h"

namespace In
{
    // ������� ��� ������ ������� ������ �� �����
    IN getin(wchar_t infile[])
    {
        IN in; // ��������� ��� �������� ������� ������

        // ������������� ����� ��������� IN
        in.lines = 0;
        in.size = 0;
        in.ignor = 0;
        int position = 0;

        // ��������� ������ ��� �������� �������� ������
        unsigned char* inText = new unsigned char[IN_MAX_LEN_TEXT];
        unsigned char inputChar = ' ';

        // �������� �������� ����� ��� ������
        ifstream fileInput(infile);

        // �������� ���������� �������� �����
        if (fileInput.fail())
            throw ERROR_THROW(110); // ���� ���� �� ��������, ����������� ������ � ����� 110

        // ���������� ������� ������� �� �����
        inputChar = fileInput.get();

        // �������� ���� ������ �������� �� �����
        while (in.size <= IN_MAX_LEN_TEXT)
        {
            // �������� �� ����� �����
            if (fileInput.eof())
            {
                inText[in.size] = '\0'; // ��������� ����������� ����-������
                break;
            }

            // ���� ������� ������ - ����� ������, ����������� ������� �����
            if (inputChar == '\n' && in.code['\n'] != IN::F)
            {
                position = -1;
                in.lines++;
            }

            // ��������� ������� � ����������� �� ��� ����
            switch (in.code[(unsigned char)inputChar])
            {
            case IN::S: // S = 8192 (������ S)
            case IN::O: // O = 16384 (������ O)
            case IN::T: // T = 1024 (������ T)
                position++;
                inText[in.size] = inputChar; // ��������� ������ � �����
                in.size++;
                break;

            case IN::F: // F = 2048 (������)
                throw ERROR_THROW_IN(111, in.lines, position); // ����������� ������ � ����� 111

            case IN::I: // I = 4096 (������������ ������)
                in.ignor++;
                break;

            default: // ������ ������� �� ��� ���
                inText[in.size] = in.code[(unsigned char)inputChar];
                position++;
                in.size++;
            }

            // ���������� ���������� ������� �� �����
            inputChar = fileInput.get();
        }

        // �������� ������������� �������� �� ��������� ������
        unsigned char* textWithoutSpaces = new unsigned char[IN_MAX_LEN_TEXT];
        int j = 0;

        // ���� ��� ����������� ��������, �������� ������������� �������
        for (int i = 0; i < in.size; i++)
        {
            if (inText[i] == ' ' && inText[i + 1] == ' ')
                continue; // ���������� ������������� �������

            else
            {
                textWithoutSpaces[j] = inText[i];
                j++;
            }
        }

        // ������ ������������� ������ � ���������� ������� ������
        in.text = textWithoutSpaces;
        in.text[j] = '\0';
        in.size = j; // �������������� ����� �������� ������ ��� ������������� ��������

        // �������� �������� �����
        fileInput.close();

        // ���������� ��������� � �������� �������
        return in;
    }
};
