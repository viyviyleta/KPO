#include <iostream>
#include <string>
using namespace std;

// �������� ��������� Ebook
struct Ebook {
    typedef string EbookFormat;
    typedef double EbookSize;
    typedef string EbookTitle;
    typedef string EbookAuthor;
    typedef bool ForChildren;
    typedef int NumPages;
    typedef string UploadDate;

    EbookFormat fileFormat;
    EbookSize fileSize;
    EbookTitle bookTitle;
    EbookAuthor author;
    ForChildren forChildren;
    NumPages numPages;
    UploadDate uploadDate;
};

// �������� ��� ������ ���������� � �����
ostream& operator<<(ostream& os, const Ebook& ebook) {
    os << "��������: " << ebook.bookTitle << endl;
    os << "�����: " << ebook.author << endl;
    os << "������ �����: " << ebook.fileFormat << endl;
    os << "������ �����: " << ebook.fileSize << " MB" << endl;
    os << "���������� �������: " << ebook.numPages << endl;
    os << "��� �����: " << (ebook.forChildren ? "��" : "���") << endl;
    os << "���� ��������: " << ebook.uploadDate << endl;
    return os;
}

// �������� ��� ��������� ���� ���� �� ������� �����
bool operator<(const Ebook& ebook1, const Ebook& ebook2) {
    return ebook1.fileSize < ebook2.fileSize;
}

int main() {
    setlocale(0, "");
    // ���������� � ������
    Ebook ebook1 = { "pdf", 3.5, "���������. ���������� � ������", "�. �. ��������", false, 1328, "2024-03-11" };
    Ebook ebook2 = { "txt", 2.1, "���������� ��������-�����", "�. �. �������", true, 386, "2020-03-10" };

    // ����� ���������� � ������ 
    cout << "���������� � ����� 1:" << endl;
    cout << ebook1 << endl;
    cout << "���������� � ����� 2:" << endl;
    cout << ebook2 << endl;

    // ��������� ���� �� �������
    if (ebook1 < ebook2) {
        cout << "����� 1 ����� ������� ������ �����." << endl;
    }
    else {
        cout << "����� 2 ����� ������� ������ �����." << endl;
    }
    return 0;
}
