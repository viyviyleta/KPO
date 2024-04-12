#include <iostream>
#include <string>
using namespace std;

// Описание структуры Ebook
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

// Операция для вывода информации о книге
ostream& operator<<(ostream& os, const Ebook& ebook) {
    os << "Название: " << ebook.bookTitle << endl;
    os << "Автор: " << ebook.author << endl;
    os << "Формат файла: " << ebook.fileFormat << endl;
    os << "Размер файла: " << ebook.fileSize << " MB" << endl;
    os << "Количество страниц: " << ebook.numPages << endl;
    os << "Для детей: " << (ebook.forChildren ? "Да" : "Нет") << endl;
    os << "Дата загрузки: " << ebook.uploadDate << endl;
    return os;
}

// Операция для сравнения двух книг по размеру файла
bool operator<(const Ebook& ebook1, const Ebook& ebook2) {
    return ebook1.fileSize < ebook2.fileSize;
}

int main() {
    setlocale(0, "");
    // Информация о книгах
    Ebook ebook1 = { "pdf", 3.5, "Алгоритмы. Построение и анализ", "И. В. Красиков", false, 1328, "2024-03-11" };
    Ebook ebook2 = { "txt", 2.1, "Мифический человеко-месяц", "А. В. Логунов", true, 386, "2020-03-10" };

    // Вывод информации о книгах 
    cout << "Информация о книге 1:" << endl;
    cout << ebook1 << endl;
    cout << "Информация о книге 2:" << endl;
    cout << ebook2 << endl;

    // Сравнение книг по размеру
    if (ebook1 < ebook2) {
        cout << "Книга 1 имеет меньший размер файла." << endl;
    }
    else {
        cout << "Книга 2 имеет меньший размер файла." << endl;
    }
    return 0;
}
