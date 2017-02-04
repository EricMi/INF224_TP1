#define VERSION_DESTRUCTION
/* Version list:
 * VERSION_BASE: base class Multimedia (Question 2&3)
 * VERSION_BASIC: class Photo and Video (Question 4)
 * VERSION_POLYMORPHISM: implement polymorphism (Question 5)
 * VERSION_FILM: class Film (Question 6)
 * VERSION_DESTRUCTION: Deal with the memory leak and copy issues (Question 7)
 */


#include <stdlib.h>
#include <string>
#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
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

    delete m1;
    m1 = NULL;
    delete m2;
    m2 = NULL;

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

    delete p1;
    p1 = NULL;
    delete v1;
    v1 = NULL;

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

    for(int i = 0; i < count; i++) {
        delete myFiles[i];
        myFiles[i] = NULL;
    }
    delete []myFiles;
    myFiles = NULL;

    return 0;
}
#endif // VERSION_POLYMORPHISM

// Test for class Film (Question 6)
#ifdef VERSION_FILM
int main() {
	int *durations = new int[4]{12, 50, 100, 150};
	Film *f1 = new Film("Twilight", "~/workspace/INF224_TP1/files/Twilight-JJLin.mp4", 312, durations, 4);

    cout << "Test for class Film:" << endl;
	f1->print(cout);
    cout << "Test for function setDurations:" << endl;
    durations[0] = 22;
    durations[1] = 40;
    f1->setDurations(durations, 4);
    f1->print(cout);
    cout << "Test for function getDurations and getNumDurations:" << endl;
    int n = f1->getNumDurations();
    const int *ptr = f1->getDurations();
    for(int i = 0; i < n; i++) {
        cout << ptr[i] << ' ';
    }
    cout << endl;
    cout << "Now modify the original duration data:" << endl;
	durations[3] = 25;
    f1->print(cout);
    cout << "Now destroy the original duration data:" << endl;
    delete []durations;
    durations = NULL;
    f1->print(cout);

    delete f1;
    f1 = NULL;

    return 0;
}
#endif // VERSION_FILM

// Test for the memory leak and copy issues (Question 7)
#ifdef VERSION_DESTRUCTION
int main() {
	int *durations = new int[4]{12, 50, 100, 150};
	Film *f1 = new Film("Twilight", "~/workspace/INF224_TP1/files/Twilight-JJLin.mp4", 312, durations, 4);

    Film f2(*f1);
    Film *f3 = new Film();
    *f3 = *f1;

    cout << "Test for the memory leak and copy issues:" << endl;
    cout << "Film1:" << endl;
    f1->print(cout);
    cout << "Film2(created by copy):" << endl;
    f2.print(cout);
    cout << "Film3(assign by operator '='):" << endl;
    f3->print(cout);

    delete f1;
    f1 = NULL;
    delete f3;
    f3 = NULL;
}
#endif // VERSION_DESTRUCTION
