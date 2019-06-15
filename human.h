#pragma once
#include <iostream>
#include<string>
#include "sort.h"
#include <fstream>
#include <map>

using namespace std;

struct HumanData {
	string address;
	string phone;
	HumanData() {};
	HumanData(string addr, string ph);

	bool operator == (const HumanData& human) const {
		if ((human.address == (*this).address) && (human.phone == (*this).phone))
			return true;
		return false;
	}

	bool operator > (const HumanData& human) const {
		if ((*this).address > human.address)
			return true;
		else if (((*this).address == human.address) && ((*this).phone > human.phone))
			return true;
		return false;
	}

	bool operator < (const HumanData& human) const {
		if ((*this).address < human.address)
			return true;
		else if (((*this).address == human.address) && ((*this).phone < human.phone))
			return true;
		return false;
	}

	void operator = (const HumanData& human) {
		(*this).address = human.address;
		(*this).phone = human.phone;
	}
};

istream& operator >>(istream& in, HumanData& data) {
	getline(in, data.address);
	getline(in, data.phone);
	return in;
}

ostream& operator <<(ostream& out, const HumanData& data){
	out << data.address << ' ' << data.phone << endl;
	return out;
}

ostream& operator <<(char& str, HumanData& data) {
	cout << str;
	cout << data;
	return cout;
}

struct Human {
	string name;
	HumanData data;
	Human() {};
	Human(string aname, string addr, string ph);

	bool operator == (const Human& human) const {
		if (((*this).name == human.name) && ((*this).data == human.data))
			return true;
		return false;
	}

	bool operator < (const Human& human) const {
		if ((*this).name < human.name)
			return true;
		else if (((*this).name == human.name) && ((*this).data < human.data))
			return true;
		return false;
	}

	bool operator > (const Human& human) const {
		if ((*this).name > human.name)
			return true;
		else if (((*this).name == human.name) && ((*this).data > human.data))
			return true;
		return false;
	}

	void operator =(const Human& human) {
		(*this).name = human.name;
		(*this).data = human.data;
	}

	bool operator >=(const Human& human) const{
		if (*this > human || *this == human)
			return true;
		return false;
	}

	bool operator <=(const Human& human) const{
		if (*this < human || *this == human)
			return true;
		return false;
	}

};

istream& operator >>(istream& in, Human& human) {
	getline(in, human.name);
	in >> human.data;
	return in;
}

ostream& operator <<(ostream& out, const Human& human) {
	out << human.name << ' ';
	out << human.data << endl;
	return out;
}

ostream& operator <<(char& str, Human& human) {
	cout << str;
	cout << human;
	return cout;
}

HumanData::HumanData(string addr, string ph) {
	address = addr;
	phone = ph;
}

Human::Human(string aname, string addr, string ph) : name(aname), data(addr, ph) {}

bool readHumans(const char* filename, SortableVector <Human>& humans) {
	ifstream in(filename);
	if (!in.is_open())
		return false;
	Human human;
	in >> human;
	while (!in.fail()) {
		humans.push_back(human);
		in >> human;
	}
	in.close();
	return true;
}

bool readHumans(const char* filename, map<string, HumanData>& humans){
	ifstream in(filename);
	if (!in.is_open())
		return false;
	string name;
	HumanData data;
	getline(in, name) >> data;
	while (!in.fail())
	{
		humans[name] = data;
		getline(in, name) >> data;
	}
	in.close();
	return true;
}