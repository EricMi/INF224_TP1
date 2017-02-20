#define VERSION_SERVER
/* Version list:
 * VERSION_BASE: base class Multimedia (Question 2&3)
 * VERSION_BASIC: class Photo and Video (Question 4)
 * VERSION_POLYMORPHISM: implement polymorphism (Question 5)
 * VERSION_FILM: class Film (Question 6)
 * VERSION_DESTRUCTION: Deal with the memory leak and copy issues (Question 7)
 * VERSION_GROUP: class Group (Question 8) (!!!no longer available!!!)
 * VERSION_MEMORY_MGMT: test of memory management by smart pointer (Question 9)
 * VERSION_MEDIABASE: implementation of class MyBase (Question 10)
 * VERSION_SERVER: transform MyBase class as a server (Question 11)
 * VERSION_SERALISATION: save into and read from local file (Question 12)
 */

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MyBase.h"
#include <sstream>
#include "tcpserver.h"
using namespace std;
using namespace cppu;

const int PORT = 3331;

// Test for base class (Question 3)
#ifdef VERSION_BASE
int main() {
    cout << "Test for base class:" << endl;
    Multimedia *m1 = new Multimedia();
    Multimedia *m2 = new Multimedia("eiffel", "files/eiffel.jpg");

    cout << "Multimedia object 1:" << endl;
    m1->print(cout);
    cout << "Multimedia object 1:" << endl;
    m2->print(cout);

    cout << "Test for \"getters\" functions:" << endl;
    cout << m2->getName() << endl;
    cout << m2->getFileName() << endl;

    cout << "Test for \"setters\" functions:" << endl;
    m2->setName("newEiffel");
    m2->setFileName("files/eiffel.jpg");
    cout << m2->getName() << endl;
    cout << m2->getFileName() << endl;

    delete m1;
    m1 = NULL;
    delete m2;
    m2 = NULL;

    return 0;
}
#endif // !VERSION_BASE

// Test for class Photo and Video (Question 4)
#ifdef VERSION_BASIC
int main() {
    cout << "Test for class Photo:" << endl;
    Photo *p1 = new Photo("eiffel", "files/eiffel.jpg", 1920, 1440);
    Video *v1 = new Video("JJ", "files/Twilight-JJLin.mp4", 312);

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
#endif // !VERSION_BASIC

// Test for implementation of polymorphism (Question 5)
#ifdef VERSION_POLYMORPHISM
int main() {
    cout << "Test for implementation of polymorphism:" << endl;
    int count = 0;
    Multimedia ** myFiles = new Multimedia *[4];

	myFiles[count++] = new Photo("eiffel", "files/eiffel.jpg", 1920, 1440);
	myFiles[count++] = new Photo("telecom", "files/logo.png", 113, 113);
	myFiles[count++] = new Video("rose", "files/TheRose-Westlife.mp4", 212);
	myFiles[count++] = new Video("jj", "files/Twilight-JJLin.mp4", 312);

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
#endif // !VERSION_POLYMORPHISM

// Test for class Film (Question 6)
#ifdef VERSION_FILM
int main() {
    cout << "Test for class Film:" << endl;
	int *durations = new int[4]{12, 50, 100, 150};
	Film *f1 = new Film("Twilight", "files/Twilight-JJLin.mp4", 312, durations, 4);

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
#endif // !VERSION_FILM

// Test for the memory leak and copy issues (Question 7)
#ifdef VERSION_DESTRUCTION
int main() {
    cout << "Test for the memory leak and copy issues:" << endl;
	int *durations = new int[4]{12, 50, 100, 150};
	Film *f1 = new Film("Twilight", "files/Twilight-JJLin.mp4", 312, durations, 4);
    delete []durations;
    durations = NULL;

    Film f2(*f1);
    Film *f3 = new Film();
    *f3 = *f1;

    cout << "Film1:" << endl;
    f1->print(cout);
    delete f1;
    f1 = NULL;
    cout << "Film2(created by copy):" << endl;
    f2.print(cout);
    cout << "Film3(assign by operator '='):" << endl;
    f3->print(cout);

    delete f3;
    f3 = NULL;

    return 0;
}
#endif // !VERSION_DESTRUCTION

// Test for class Group (Question 8)
#ifdef VERSION_GROUP
int main() {
    cout << "Test for class Group:" << endl;
    int count = 0;
    Multimedia ** myFiles = new Multimedia *[5];

    myFiles[count++] = new Photo("eiffel", "files/eiffel.jpg", 1920, 1440);
    myFiles[count++] = new Photo("telecom", "files/logo.png", 113, 113);
    myFiles[count++] = new Video("rose", "files/TheRose-Westlife.mp4", 212);
    myFiles[count++] = new Video("jj", "files/Twilight-JJLin.mp4", 312);
	int *durations = new int[4]{12, 50, 100, 150};
	myFiles[count++] = new Film("Twilight", "files/Twilight-JJLin.mp4", 312, durations, 4);
    delete []durations;
    durations = NULL;

	Group *g1 = new Group("myPhoto");
	Group *g2 = new Group("myVideo");
	Group *g3 = new Group("myMedia");

	g1->push_back(myFiles[0]);
	g1->push_back(myFiles[1]);
	g2->push_back(myFiles[2]);
	g2->push_back(myFiles[3]);
	g3->push_back(myFiles[0]);
	g3->push_back(myFiles[1]);
	g3->push_back(myFiles[2]);
	g3->push_back(myFiles[3]);
	g3->push_back(myFiles[4]);

	g1->print(cout);
	g2->print(cout);
	g3->print(cout);

	cout << "Now delete group 'myPhoto':" << endl;
    delete g1;
    g1 = NULL;
	g3->print(cout);

    delete g2;
    g2 = NULL;
    delete g3;
    g3 = NULL;

    for(int i = 0; i < count; i++) {
        delete myFiles[i];
        myFiles[i] = NULL;
    }

    return 0;
}
#endif // !VERSION_GROUP

// Test for memory management (Question 9)
#ifdef VERSION_MEMORY_MGMT
int main() {
    cout << "Test for memory management by using shared_ptr:" << endl;
    int count = 0;
    MultimediaPtr *myFiles = new MultimediaPtr[5];

    myFiles[count++] = MultimediaPtr(new Photo("eiffel", "files/eiffel.jpg", 1920, 1440));
    myFiles[count++] = MultimediaPtr(new Photo("telecom", "files/logo.png", 113, 113));
    myFiles[count++] = MultimediaPtr(new Video("rose", "files/TheRose-Westlife.mp4", 212));
    myFiles[count++] = MultimediaPtr(new Video("jj", "files/Twilight-JJLin.mp4", 312));
	int *durations = new int[4]{12, 50, 100, 150};
	myFiles[count++] = MultimediaPtr(new Film("Twilight", "files/Twilight-JJLin.mp4", 312, durations, 4));
    delete []durations;
    durations = NULL;

	Group *g1 = new Group("myPhoto");
	Group *g2 = new Group("myVideo");
	Group *g3 = new Group("myMedia");

	g1->push_back(myFiles[0]);
	g1->push_back(myFiles[1]);
	g2->push_back(myFiles[2]);
	g2->push_back(myFiles[3]);
	g3->push_back(myFiles[0]);
	g3->push_back(myFiles[1]);
	g3->push_back(myFiles[2]);
	g3->push_back(myFiles[3]);
	g3->push_back(myFiles[4]);

	g1->print(cout);
	g2->print(cout);
	g3->print(cout);

    cout << "Reset all the 'MultimediaPtr' in main program:" << endl;
    for(int i = 0; i < count; i++) {
        myFiles[i].reset();
    }

    cout << "Copy the smart pointer of 'eiffel':" << endl;
    MultimediaPtr m1 = g1->front();

	cout << "Now delete 'eiffel' from group 'myPhoto' and 'myMedia':" << endl;
    g1->remove(m1);
    g3->remove(m1);

    cout << "Now reset the smart pointer of 'eiffel':" << endl;
    m1.reset();

    cout << "Delete the groups:" << endl;
    delete g1;
    g1 = NULL;
    delete g2;
    g2 = NULL;
    delete g3;
    g3 = NULL;

    return 0;
}
#endif // !VERSION_MEMORY_MGMT

// Test for class MyBase
#ifdef VERSION_MEDIABASE
int main() {
    cout << "Test for MyBase:" << endl;
    cout << "Creating test data base..." << endl;
    shared_ptr<MyBase> myBase(new MyBase());
    myBase->createPhoto("eiffel", "files/eiffel.jpg", 1920, 1440);
    myBase->createPhoto("telecom", "files/logo.png", 113, 113);
    myBase->createVideo("rose", "files/TheRose-Westlife.mp4", 212);
    myBase->createVideo("jj", "files/Twilight-JJLin.mp4", 312);
    int *durations = new int[4]{12, 50, 100, 150};
    myBase->createFilm("twilight", "files/Twilight-JJLin.mp4", 312, durations, 4);
    delete []durations;
    durations = NULL;

    myBase->createGroup("myPhoto");
    myBase->createGroup("myVideo");
    myBase->createGroup("myMedia");

    myBase->addToGroup("eiffel", "myPhoto");
    myBase->addToGroup("telecom", "myPhoto");
    myBase->addToGroup("rose", "myVideo");
    myBase->addToGroup("jj", "myVideo");
    myBase->addToGroup("eiffel", "myMedia");
    myBase->addToGroup("telecom", "myMedia");
    myBase->addToGroup("rose", "myMedia");
    myBase->addToGroup("jj", "myMedia");
    myBase->addToGroup("twilight", "myMedia");

    cout << "Test for function 'print'" << endl;
    myBase->print("eiffel");
    myBase->print("myPhoto");

    cout << "Test for function 'play'" << endl;
    myBase->play("rose");

    cout << "Test for function 'remove' (group):" << endl;
    myBase->remove("myPhoto");
    cout << "Test for function 'remove' (multimedia):" << endl;
    myBase->remove("eiffel");

    cout << "Destroy MyBase:" << endl;
    delete myBase;

    return 0;
}
#endif // !VERSION_MEDIABASE

// Test for MyBase server.
#ifdef VERSION_SERVER
int main(int argc, char* argv[]) {
    cout << "Test for MyBase server:" << endl;
    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());
    // cree l'objet qui gère les données
    shared_ptr<MyBase> base(new MyBase());

    cout << "Creating test data base..." << endl;
    base->createPhoto("eiffel", "files/eiffel.jpg", 1920, 1440);
    base->createPhoto("telecom", "files/logo.png", 113, 113);
    base->createVideo("rose", "files/TheRose-Westlife.mp4", 212);
    base->createVideo("jj", "files/Twilight-JJLin.mp4", 312);
    int *durations = new int[4]{12, 50, 100, 150};
    base->createFilm("twilight", "files/Twilight-JJLin.mp4", 312, durations, 4);
    delete []durations;
    durations = NULL;

    base->createGroup("myPhoto");
    base->createGroup("myVideo");
    base->createGroup("myMedia");

    base->addToGroup("eiffel", "myPhoto");
    base->addToGroup("telecom", "myPhoto");
    base->addToGroup("rose", "myVideo");
    base->addToGroup("jj", "myVideo");
    base->addToGroup("eiffel", "myMedia");
    base->addToGroup("telecom", "myMedia");
    base->addToGroup("rose", "myMedia");
    base->addToGroup("jj", "myMedia");
    base->addToGroup("twilight", "myMedia");

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*base, &MyBase::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return 1;
    }

  return 0;
}
#endif // !VERSION_SERVER

// Test for file interaction
#ifdef VERSION_SERALISATION
int main() {
    cout << "Test for file interaction:" << endl;
    cout << "Creating test data base..." << endl;
    shared_ptr<MyBase> myBase(new MyBase());
    myBase->createPhoto("eiffel", "files/eiffel.jpg", 1920, 1440);
    myBase->createPhoto("telecom", "files/logo.png", 113, 113);
    myBase->createVideo("rose", "files/TheRose-Westlife.mp4", 212);
    myBase->createVideo("jj", "files/Twilight-JJLin.mp4", 312);
    int *durations = new int[4]{12, 50, 100, 150};
    myBase->createFilm("twilight", "files/Twilight-JJLin.mp4", 312, durations, 4);
    delete []durations;
    durations = NULL;

    myBase->createGroup("myPhoto");
    myBase->createGroup("myVideo");
    myBase->createGroup("myMedia");

    myBase->addToGroup("eiffel", "myPhoto");
    myBase->addToGroup("telecom", "myPhoto");
    myBase->addToGroup("rose", "myVideo");
    myBase->addToGroup("jj", "myVideo");
    myBase->addToGroup("eiffel", "myMedia");
    myBase->addToGroup("telecom", "myMedia");
    myBase->addToGroup("rose", "myMedia");
    myBase->addToGroup("jj", "myMedia");
    myBase->addToGroup("twilight", "myMedia");

    myBase->save("media.dt");
    cout << "--->Base1:";
    myBase->printAll();

    shared_ptr<MyBase> myBase2(new MyBase());
    if(myBase2->load("media.dt")) {
        cout << "--->Base2:";
        myBase2->printAll();
    };

    return 0;
}
#endif // !VERSION_MEDIABASE
