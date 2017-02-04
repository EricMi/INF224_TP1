#ifndef FILM_H
#define FILM_H

#include "Video.h"
using namespace std;

class Film : public Video {
private:
    int *arrDurations = NULL;
    int numDurations = 0;
public:
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
    // Destructor
    ~Film();
    // Constructor by copy
    Film(const Film& from);
    // overload operator '='
    Film& operator=(const Film& from);
};

#endif // !FILM_H
