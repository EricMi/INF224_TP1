#define VERSION_POLYMORPHISM

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
using namespace std;

// Test for base class (Question 3)
#ifdef VERSION_BASE
int main() {
    Multimedia *m1 = new Multimedia();
    Multimedia *m2 = new Multimedia("eiffel", "/home/mi/workspace/INF224_TP1/files/eiffel.jpg");

    cout << "Test for base class:" << endl;
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
#endif // VERSION_BASIC

// Test for implementation of polymorphism (Question 5)
#ifdef VERSION_POLYMORPHISM
int main() {
    int count = 0;
    Multimedia ** myFiles = new Multimedia *[4];

	myFiles[count++] = new Photo("eiffel", "~/workspace/INF224_TP1/files/eiffel.jpg", 1920, 1440);
	myFiles[count++] = new Photo("telecom", "~/workspace/INF224_TP1/files/logo.png", 113, 113);
	myFiles[count++] = new Video("rose", "~/workspace/INF224_TP1/files/TheRose-Westlife.mp4", 212);
	myFiles[count++] = new Video("jj", "~/workspace/INF224_TP1/files/Twilight-JJLin.mp4", 312);

    cout << "Test for implementation of polymorphism:" << endl;
    for(int i = 0; i < count; i++) {
        myFiles[i]->print(cout);
        myFiles[i]->play();
    }
}
#endif // VERSION_POLYMORPHISM
