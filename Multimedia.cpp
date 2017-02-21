//***************************************************************************************
//
//! @file Multimedia.cpp
//! L'implementation de la class de base Multimedia.
//!
//! @author    Pengfei Mi
//! @date      2016-11
//
//***************************************************************************************

#include "Multimedia.h"
#include <ctype.h>
#include <stdexcept>
using namespace std;

Multimedia::Multimedia() {
	this->setName("");
	this->setFileName("");
}

Multimedia::Multimedia(string n, string f) {
	this->setName(n);
	this->setFileName(f);
}

Multimedia::~Multimedia() {
	cout << "Object destructed: " << this->name << '\n';
	this->setName("");
	this->setFileName("");
}

string Multimedia::getName() const {
	return this->name;
}

void Multimedia::setName(string n) {

	for(char& c : n) {
		if(!isalnum(c)) {
			throw invalid_argument( "--->Error: the name contain illegal character.");
		}
	}
	this->name = n;
}

string Multimedia::getFileName() const {
	return this->fileName;
}

void Multimedia::setFileName(string f) {
	this->fileName = f;
}

void Multimedia::print(ostream &os) const {
	os << "Name:" << this->getName() << '\n'
		<< "File:" << this->getFileName() << endl;
}

void Multimedia::write(ostream &os) const {
	os << this->getName() << '\n' << this->getFileName() << '\n';
}

void Multimedia::read(istream &is) {
	string s;
	getline(is, s);
	this->setName(s);
	getline(is, s);
	this->setFileName(s);
}

string Multimedia::className() const {
	return "Multimedia";
}
