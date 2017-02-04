#ifndef GROUP_H
#define GROUP_H

#include <list>
#include "Multimedia.h"
using namespace std;

class Group : public list<Multimedia*> {
private:
    string name = "";
public:
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
