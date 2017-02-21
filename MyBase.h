//***************************************************************************************
//
//! @file MyBase.h
//! La specification la class MyBase.
//!
//! @author    Pengfei Mi
//! @date      2017-1
//
//***************************************************************************************

#ifndef MYBASE_H
#define MYBASE_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <map>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"
using namespace std;
using namespace cppu;

typedef shared_ptr<Group> GroupPtr;
typedef map<string, MultimediaPtr> MultimediaMap;
typedef map<string, GroupPtr> GroupMap;

/**
 * @class MyBase header-file MyBase.h
 * @brief
 * La class réalise un "set-up box", qui répond les requêtes des clients.
 * Ells contient deux map, un des pointeurs d'objets Multimedia, un des pointeurs des groupes.
 * @see Multimedia, Group
 */
class MyBase {
private:
    MultimediaMap multimedia; /**Le map des objets multimédia.*/
    GroupMap group; /**Le map des groupes.*/
public:
    /**
     * @brief Le constructeur.
     */
    MyBase();

    /**
     * @brief Le destructeur.
     */
    ~MyBase();

    /**
     * @brief Méthode pour créer une photo et l'ajouter à la base.
     */
    MultimediaPtr createPhoto(string name, string fileName = "", int width = 0, int height = 0);

    /**
     * @brief Méthode pour créer une vidéo et l'ajouter à la base.
     */
    MultimediaPtr createVideo(string name, string fileName = "", int duration = 0);

    /**
     * @brief Méthode pour créer un film et l'ajouter à la base.
     */
    MultimediaPtr createFilm(string name, string fileName = "", int duration = 0, int *ptrDurations = NULL, int numDurations = 0);

    /**
     * @brief Méthode pour créer un groupe et l'ajouter à la base.
     */
    GroupPtr createGroup(string name);

    /**
     * @brief Méthode pour ajouter un objet à un groupe donnés par leur noms.
     */
    void addToGroup(string mName, string pName);

    /**
     * @brief Méthode pour afficher l'information d'un objet ou groupe donné par son nom.
     */
    void print(string name, ostream &os = cout) const;

    /**
     * @brief Méthode pour jouer un objet multimédia.
     */
    bool play(string name) const;

    /**
     * @brief Méthode pour supprimer un objet ou groupe de la base donné par son nom.
     */
    void remove(string name);

    /**
     * @brief Méthode pour traiter les requêtes.
     */
    bool processRequest(TCPConnection& cnx, const string& request, string& response);

    /**
     * @brief Méthode pour écrire les information des objets dans un ficher.
     */
    bool save(const string &fileName) const;

    /**
     * @brief Méthode pour relire les objets d'un fichier.
     */
    bool load(const string &fileName);

    /**
     * @brief Méthode pour créer un objet par sa class.
     */
    MultimediaPtr createMultimedia(string className);

    /**
     * @brief Méthode pour afficher les information de toute les objets et groupes.
     */
    void printAll(ostream &os = cout) const;
};

#endif // !MYBASE_H
