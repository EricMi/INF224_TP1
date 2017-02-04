#define VERSION_BASE

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Multimedia.h"
using namespace std;

// Test for base version (Question 3)
#ifdef VERSION_BASE
int main() {
    Multimedia *m1 = new Multimedia();
    Multimedia *m2 = new Multimedia("eiffel", "/home/mi/workspace/INF224_TP1/files/eiffel.jpg");

    cout << "Multimedia object 1:" << endl;
    m1->print(cout);
    cout << "Multimedia object 1:" << endl;
    m2->print(cout);

    cout << "Test for \"getters\" functions:" << endl;
    cout << m2->getName() << endl;
    cout << m2->getFileName() << endl;

    cout << "Test for \"setters\" functions:" << endl;
    m2->setName("newEiffel");
    m2->setFileName("mi/workspace/INF224_TP1/files/eiffel.jpg");
    cout << m2->getName() << endl;
    cout << m2->getFileName() << endl;

    return 0;
}
#endif // VERSION_BASE
