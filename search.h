#pragma once
#undef UNICODE
#include <iostream>
#include "search.h"
#include "human.h"
#include <vector>
#include <string>
#include <windows.h>
#include "sort.h"
#include <map>

using namespace std;

Human findByName(const SortableVector <Human>& humans, const string& name) {
	cout << "����: " << name << endl;
	for (SortableVector<Human>::const_iterator it = humans.begin(); it != humans.end(); it++) {
		if (it->name == name)
			return (*it);
	}
	cout << "������ ����� ��� � ���������� �����";
	Human human_def;
	return human_def;
}

Human findByNameBin(const SortableVector<Human>& humans, string& name, int min, int max)
{
	int index = (min + max) / 2;
	if (min > max)
	{
		cout << "������ ����� ��� � ���������� �����" << endl;
		Human human_def;
		return human_def;
	}
	else if (humans[index].name == name)
		return humans[index];
	else if (humans[index].name > name)
		return findByNameBin(humans, name, min, index - 1);
	else
		return findByNameBin(humans, name, index + 1, max);
}

Human findByNameBin(const SortableVector<Human>& humans, string& name) {
	cout << "����: " << name << endl;
	return findByNameBin(humans, name, 0, (int)humans.size() - 1);
}

void findByNameMap(map<string, HumanData>& humans, string name) {
	map<string, HumanData>::const_iterator it = humans.find(name);
	if (it != humans.end()){
		cout << "������� ������:" << endl;
		cout << it->first << ' ' << it->second << endl;
	}
	else
		cout << "������ ����� ��� � ���������� �����" << endl;
}

string convert(string str) {
	char* buf = new char[strlen(str.c_str()) + 1];
	OemToChar(str.c_str(), buf);
	string res(buf);
	delete[] buf;
	return res;
}
