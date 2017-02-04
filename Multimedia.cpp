#include "Multimedia.h"
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
		<< "File name: " << this->getFileName() << endl;
}
