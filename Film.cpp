//***************************************************************************************
//
//! @file Film.h
//! L'implementation de la class Film dérivant de Vidéo.
//!
//! @author    Pengfei Mi
//! @date      2016-12
//
//***************************************************************************************

#include "Film.h"
using namespace std;

Film::Film(string n, string f, int d, const int *ptrD, int numD) : Video(n, f, d) {
    this->setDurations(ptrD, numD);
}

void Film::setDurations(const int *ptrD, int numD) {
    if(numD > 0 && ptrD) {
        if(this->arrDurations) {
            delete []this->arrDurations;
        }
        this->arrDurations = new int[numD];
        for(int i = 0; i < numD; i++) {
            this->arrDurations[i] = ptrD[i];
        }
        this->numDurations = numD;
    } else if(numD <= 0) {
        cerr << "--->Error: the number of chapters must be positive!" << endl;
    	throw std::invalid_argument("--->Error: the number of chapters must be positive!");
    } else {
        cerr << "--->Error: the pointer is null!" << endl;
        throw std::invalid_argument("--->Error: the pointer is null!");
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
        os << "Durations:";
        for(int i = 0; i < this->numDurations-1; i++) {
            os << this->arrDurations[i] << '-';
        }
        os << this->arrDurations[this->numDurations-1] << endl;
    } else {
        os << "Durations:NULL" << endl;
    }
}

Film::~Film() {
    delete []this->arrDurations;
    this->arrDurations = NULL;
}

Film::Film(const Film& from) : Video(from) {
    const int *ptr = from.getDurations();
    numDurations = from.getNumDurations();

    if(ptr) {
        arrDurations = new int[numDurations];
        for(int i = 0; i < numDurations; i++) {
            arrDurations[i] = ptr[i];
        }
    } else {
        arrDurations = NULL;
        numDurations = 0;
    }
}

Film& Film::operator=(const Film& from) {
    Video::operator=(from);

    const int *ptr = from.getDurations();
    numDurations = from.getNumDurations();

    if(arrDurations) {
        delete []arrDurations;
        arrDurations = NULL;
    }
    if(ptr) {
        arrDurations = new int[numDurations];
        for(int i = 0; i < numDurations; i++) {
            arrDurations[i] = ptr[i];
        }
    } else {
        arrDurations = NULL;
        numDurations = 0;
    }
    return *this;
}

void Film::write(ostream &os) const {
    Video::write(os);
    os << this->getNumDurations() << '\n';
    for(int i = 0; i < this->numDurations; i++) {
        os << this->arrDurations[i] << '\n';
    }
}

void Film::read(istream &is) {
    this->Video::read(is);
    string s;
    getline(is, s);
    cout << "read numD: " << s << endl;
    int numD = stoi(s);
    int *arrD = new int[numD];
    for(int i = 0; i < numD; i++) {
        getline(is, s);
        arrD[i] = stoi(s);
    };
    this->setDurations(arrD, numD);
    delete []arrD;
}

// virtual function: return class name.
string Film::className() const {
    return "Film";
}
