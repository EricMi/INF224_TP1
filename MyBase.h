#ifndef MYBASE_H
#define MYBASE_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
using namespace std;

typedef shared_ptr<Group> GroupPtr;
typedef map<string, MultimediaPtr> MultimediaMap;
typedef map<string, GroupPtr> GroupMap;

class MyBase {
private:
    MultimediaMap multimedia;
    GroupMap group;
public:
    // Constructor
    MyBase();
    // Destructor
    ~MyBase();
    // function: create a photo object and add to base
    MultimediaPtr createPhoto(string name, string fileName = "", int width = 0, int height = 0);
    // function: create a Video object and add to base
    MultimediaPtr createVideo(string name, string fileName = "", int duration = 0);
    // function: create a Film object and add to base
    MultimediaPtr createFilm(string name, string fileName = "", int duration = 0, int *ptrDurations = NULL, int numDurations = 0);
    // function: create a Group object and add to base
    GroupPtr createGroup(string name);
    // function: add a mulimedia object to a group
    void addToGroup(string mName, string pName);
    // function: print the information of multimedia object or group in terminal by name
    void print(string name) const;
    // function: play a multimedia object by name
    void play(string name) const;
    // function: delete a multimedia object or group by name
    void remove(string name);
};

#endif // !MYBASE_H
