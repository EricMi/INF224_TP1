#define VERSION_BASIC

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
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

// Test for class Photo and Video (Question 4)
#ifdef VERSION_BASIC
int main() {
    Photo *p1 = new Photo("eiffel", "/home/mi/workspace/INF224_TP1/files/eiffel.jpg", 1920, 1440);
    Video *v1 = new Video("JJ", "/home/mi/workspace/INF224_TP1/files/Twilight-JJLin.mp4", 312);

    cout << "Test for class Photo:" << endl;
    p1->print(cout);
    p1->play();

    cout << "Test for class Video:" << endl;
    v1->print(cout);
    v1->play();

    return 0;
}
#endif
