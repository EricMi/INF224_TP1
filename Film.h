#ifndef FILM_H
#define FILM_H

#include "Video.h"
using namespace std;

class Film : public Video {
    friend class MyBase;
    friend class Group;
private:
    int *arrDurations = NULL;
    int numDurations = 0;
protected:
    // Constructor
    Film(string name = "", string fileName = "", int duration = 0, const int *ptrDurations = NULL, int numDurations = 0);
    // function: set durations
    void setDurations(const int *ptrDurations, int numDurations);
    // function: get durations
    const int * getDurations() const;
    // function: get number of durations
    int getNumDurations() const;
    // function: get number of durations
    void print(ostream &os) const;
    // Constructor by copy
    Film(const Film& from);
    // overload operator '='
    Film& operator=(const Film& from);
public:
    // Destructor
    ~Film();
};

#endif // !FILM_H
