#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include "Multimedia.h"
using namespace std;

typedef shared_ptr<Multimedia> MultimediaPtr;

//class Group : public list<Multimedia*> {
class Group : public list<MultimediaPtr> {
    friend class MyBase;
private:
    string name = "";
protected:
    // Constructor
    Group(string n = "") : list() {
        this->name = n;
    };

    // function: get name of group
    string getName() const {
        return this->name;
    };

    // function: print information of every member of the group
    void print(ostream &os) const {
        os << "Group name: " << this->name << endl;
        for(Group::const_iterator it = this->begin(); it != this->end(); it++)
            (*it)->print(os);
    };
};
#endif // !GROUP_H
