#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Multimedia {
private:
	string name;
	string fileName;

public:
	Multimedia();
	Multimedia(string name, string fileName);
	~Multimedia();
	string getName() const;
	void setName(string name);
	string getFileName() const;
	void setFileName(string FileName);
	virtual void print(ostream &os) const;
};

#endif // !MULTIMEDIA_H
