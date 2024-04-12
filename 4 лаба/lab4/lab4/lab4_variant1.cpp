//#include <iostream>
//#include <string>
//using namespace std;
//
////описание структуры
//struct Ebook {
//	string fileFormat;
//	double fileSize;
//	string bookTitle;
//	string author;
//	bool forChildren;
//	int numPages;
//	string uploadDate;
//};
//
////псевдонимы типов данных
//using EbookFormat = string;
//using EbookSize = double;
//using EbookTitle = string;
//using EbookAuthor = string;
//using ForChildren = bool;
//using NumPages = int;
//using UploadDate = string;
//
//// Операция для вывода информации о книге
//ostream& operator<<(ostream& os, const Ebook& ebook) {
//	os << "Название: " << ebook.bookTitle << endl;
//	os << "Автор: " << ebook.author << endl;
//	os << "Формат файла: " << ebook.fileFormat << endl;
//	os << "Размер файла: " << ebook.fileSize << " MB" << endl;
//	os << "Количество страниц: " << ebook.numPages << endl;
//	os << "Для детей: " << (ebook.forChildren ? "Да" : "Нет") << endl;
//	os << "Дата загрузки: " << ebook.uploadDate << endl;
//	return os;
//}
//
//// Операция для сравнения двух книг по размеру файла
//bool operator<(const Ebook& ebook1, const Ebook& ebook2) {
//	return ebook1.fileSize < ebook2.fileSize;
//}
//
//int main() {
//	setlocale(0, "");
//	//игформация о книгах
//	Ebook ebook1 = { "pdf", 3.5, "Алгоритмы. Построение и анализ", "И. В. Красиков", false, 1328, "2024-03-11" };
//	Ebook ebook2 = { "txt", 2.1, "Мифический человеко-месяц", "А. В. Логунов", true, 386, "2020-03-10" };
//
//	//Вывод информации о книгах 
//	cout << "Информация о книге 1:" << endl;
//	cout << ebook1 << endl;
//	cout << "Информация о книге 2:" << endl;
//	cout << ebook2 << endl;
//	 
//	//сравнение книг по размеру
//	if (ebook1 < ebook2) {
//		cout << "Книга 1 имеет меньший размер файла." << endl;
//	}
//	else {
//		cout << "Книга 2 имеет меньший размер файла." << endl;
//	}
//	return 0;
//}
