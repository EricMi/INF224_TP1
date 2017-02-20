#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <string>
using namespace std;

class Video : public Multimedia {
	friend class MyBase;
	friend class Group;
private:
	int duration = 0;
protected:
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
	void print(ostream &os) const override {
		this->Multimedia::print(os);
		os << "Duration:" << this->getDuration() << endl;
	};

	// function: play the video.
	void play() const override {
		string command;
		#ifdef __APPLE__
			command = "open ";
		#elif __linux__
			command = "xdg-open ";
		#elif __unix__
			command = "mpv "
		#else
		    cerr << "--->Error: unknown compiler."
		#endif
		command += this->getFileName() + " &";
		system(command.c_str());
	};

	// virtual function: write object to ostream.
	void write(ostream &os) const override {
		Multimedia::write(os);
		os << this->getDuration() << '\n';
	};

	// virtual function: read object from istream.
	void read(istream &is) override {
		this->Multimedia::read(is);
		string s;
		getline(is, s);
		this->setDuration(stoi(s));
	};

	// virtual function: return class name.
	string className() const override {
		return "Video";
	};
};

#endif // !VIDEO_H
