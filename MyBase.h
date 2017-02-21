//***************************************************************************************
//
//! @file MyBase.h
//! La specification la class MyBase.
//!
//! @author    Pengfei Mi
//! @date      2017-1
//
//***************************************************************************************

#ifndef MYBASE_H
#define MYBASE_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <map>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"
using namespace std;
using namespace cppu;

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
    void print(string name, ostream &os = cout) const;
    // function: play a multimedia object by name
    bool play(string name) const;
    // function: delete a multimedia object or group by name
    void remove(string name);
    // function: process the request from cliend
    bool processRequest(TCPConnection& cnx, const string& request, string& response);
    // function: write MyBase into file in text format
    bool save(const string &fileName) const;
    // function: load MyBase from file in text format
    bool load(const string &fileName);
    // function: create multimedia object according to class name
    MultimediaPtr createMultimedia(string className);
    // function: print the information of all objects
    void printAll(ostream &os = cout) const;
};

#endif // !MYBASE_H
