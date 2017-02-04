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
	// Constructors
	Multimedia();
	Multimedia(string name, string fileName);
	// Destructor
	~Multimedia();
	// function: get name of object.
	string getName() const;
	// function: set name of object.
	void setName(string name);
	// function: get file name.
	string getFileName() const;
	// function: set file name.
	void setFileName(string FileName);
	// function: print object informations.
	virtual void print(ostream &os) const;
	// virtural function: play the object.
	virtual void play() const = 0;
};

#endif // !MULTIMEDIA_H
