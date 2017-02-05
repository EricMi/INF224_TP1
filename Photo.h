#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"
using namespace std;

class Photo : public Multimedia {
	friend class MyBase;
	friend class Group;
private:
	int width = 0;
	int height = 0;
protected:
	// constructor
	Photo(string n = "", string f = "", int w = 0, int h = 0) : Multimedia(n, f) {
		this->setWidth(w);
		this->setHeight(h);
	};

	// function: get the width of photo.
	int getWidth() const {
		return this->width;
	};

	// function: set the width of photo.
	void setWidth(int w) {
		this->width = w;
	};

	// function: get the height of photo.
	int getHeight() const {
		return this->height;
	};

	// function: set the height of photo.
	void setHeight(int h) {
		this->height = h;
	};

	// function: print the information of photo.
	void print(ostream &os) const {
		this->Multimedia::print(os);
		os << "Width:" << this->getWidth() << '\n'
			<< "Height:" << this->getHeight() << endl;
	};

	// function: play the photo.
	void play() const {
		string command = "eog " + this->getFileName() + " &";
		system(command.c_str());
	};
};

#endif // !PHOTO_H
