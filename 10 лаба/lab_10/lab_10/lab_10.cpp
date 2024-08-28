#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target1 = 3;

	int num_items1 = std::count(v.begin(), v.end(), target1);
	cout << "число: " << target1 << " кол-во: " << num_items1 << '\n';
	int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	cout << "кол-во элементов кратных 3: " << num_items3 << '\n';

	cout << endl << " Лямбда, захват переменных" << endl;
	for (auto i : v) [i]() {if (i % 3 == 0) cout << i << ' '; }();
	cout << endl << " Лямбда с параметрами" << endl;
	for (auto i : v) [](auto i) {if (i % 3 == 0) cout << i << ' '; }(i);
	cout << endl << " Лямюда без параметров" << endl;
	for (auto i : v) [i] {if (i % 3 == 0) cout << i << ' '; }();

	cout << endl << endl;

	auto concatenateStrings = [](const std::string& str1, const std::string& str2) {
		return str1 + str2;
		};
	
	string firstString = "Hello, ";
	string secondString = "world!";
	string result = concatenateStrings(firstString, secondString);
	cout << "Совмещённые строки: " << result << endl;
}