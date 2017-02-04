#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <string>
using namespace std;

class Video : public Multimedia {
private:
	int duration = 0;
public:
	// constructor
	Video(string n = "", string f = "", int d = 0) : Multimedia(n, f) {
		this->setDuration(d);
	};

	// function: get the duration of video.
	int getDuration() const {
		return this->duration;
	};

	// function: set the duration of video.
	void setDuration(int d) {
		this->duration = d;
	};

	// function: print the information of video.
	void print(ostream &os) const {
		os << "Name:" << this->getName() << '\n'
			<< "File name: " << this->getFileName() << '\n'
			<< "Duration: " << this->getDuration() << endl;
	};

	// function: play the video.
	void play() const {
		string command = "xdg-open " + this->getFileName() + " &";
		system(command.c_str());
	};
};

#endif // !VIDEO_H
