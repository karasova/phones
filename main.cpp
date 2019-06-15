#include <iostream>
#include "human.h"
#include "search.h"
#include <locale.h>
#include <vector>
#include <map>
#include <string>
#include "sort.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const char* filename = "names.txt";
	SortableVector <Human> humans_vector;
	map <string, HumanData> humans_map;

	if (!readHumans(filename, humans_vector)) {
		cout << "Невозможно открыть исходный файл" << endl;
		return -1;
	}

	if (!readHumans(filename, humans_map)) {
		cout << "Невозможно открыть исходный файл" << endl;
		return -1;
	}

	humans_vector.sort();

	string str = "";
	while (str != ".") {
		cout << "Введите ФИО в полном формате" << endl;
		cout << "Для выхода из программы введите '.'" << endl;
		getline(cin, str);
		if (str == ".")
			break;
		string name = convert(str);
		cout << "Простой поиск по вектору" << endl;
		cout << findByName(humans_vector, name) << endl;
		cout << "Бинарный поиск по вектору"  << endl;
		cout << findByNameBin(humans_vector, name) << endl;
		cout << "Поиск по map" << endl;
		findByNameMap(humans_map, name);
	}
	

	system("pause");
	return 0;
}