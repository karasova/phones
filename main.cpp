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
		cout << "���������� ������� �������� ����" << endl;
		return -1;
	}

	if (!readHumans(filename, humans_map)) {
		cout << "���������� ������� �������� ����" << endl;
		return -1;
	}

	humans_vector.sort();

	string str = "";
	while (str != ".") {
		cout << "������� ��� � ������ �������" << endl;
		cout << "��� ������ �� ��������� ������� '.'" << endl;
		getline(cin, str);
		if (str == ".")
			break;
		string name = convert(str);
		cout << "������� ����� �� �������" << endl;
		cout << findByName(humans_vector, name) << endl;
		cout << "�������� ����� �� �������"  << endl;
		cout << findByNameBin(humans_vector, name) << endl;
		cout << "����� �� map" << endl;
		findByNameMap(humans_map, name);
	}
	

	system("pause");
	return 0;
}