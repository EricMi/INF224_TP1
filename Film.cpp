#include "Film.h"
using namespace std;

Film::Film(string n, string f, int d, const int *ptrD, int numD) : Video(n, f, d) {
    this->setDurations(ptrD, numD);
}

void Film::setDurations(const int *ptrD, int numD) {
    if(this->arrDurations) {
        delete []this->arrDurations;
        this->arrDurations = NULL;
    }
    if(ptrD) {
        this->arrDurations = new int[numD];
        for(int i = 0; i < numD; i++) {
            this->arrDurations[i] = ptrD[i];
        }
        this->numDurations = numD;
    } else {
        this->arrDurations = NULL;
        this->numDurations = 0;
    }
}

const int * Film::getDurations(void) const{
    return this->arrDurations;
}

int Film::getNumDurations() const {
    return this->numDurations;
}

void Film::print(ostream &os) const {
    this->Video::print(os);
    if(this->arrDurations) {
        os << "Durations: ";
        for(int i = 0; i < this->numDurations; i++) {
            os << this->arrDurations[i] << ' ';
        }
    os << endl;
    } else {
        os << "This film doesn't have duration data!" << endl;
    }
}
