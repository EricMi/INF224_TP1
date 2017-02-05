#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Multimedia {
	friend class MyBase;
	friend class Group;
private:
	string name = "";
	string fileName = "";
protected:
	// Constructors
	Multimedia();
	Multimedia(string name, string fileName);
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
	#ifndef VERSION_BASE
	virtual void play() const = 0;
	#endif
public:
	// Destructor
	virtual ~Multimedia();
};

#endif // !MULTIMEDIA_H
