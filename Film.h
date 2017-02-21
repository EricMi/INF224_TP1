//***************************************************************************************
//
//! @file Film.h
//! La specification de la class Film dérivant de Vidéo.
//!
//! @author    Pengfei Mi
//! @date      2016-12
//
//***************************************************************************************

#ifndef FILM_H
#define FILM_H

#include "Video.h"
using namespace std;

/**
 * @class Film header-file Film.h
 * @brief
 * La class Film dérivant de Video.
 * Ses objets sont des films.
 * @see Video, Multimedia
 */
class Film : public Video {
    friend class MyBase;
    friend class Group;
private:
    int *arrDurations = NULL; /**Le pointeur pointant sur un tableau des durées.*/
    int numDurations = 0; /**Le nombre de chapitres.*/
protected:
    /**
     * @brief Le constructeur ayant des paramètres par défaut.
     */
    Film(string name = "", string fileName = "", int duration = 0, const int *ptrDurations = NULL, int numDurations = 0);

    /**
     * @brief Modifieur du tableau des durées.
     */
    void setDurations(const int *ptrDurations, int numDurations);

    /**
     * @brief Modifieur du nombre des durées.
     */
    const int * getDurations() const;

    /**
     * @brief Accesseur des durées des chapitres.
     */
    int getNumDurations() const;

    /**
     * @brief Méthode override pour afficher l'information.
     */
    void print(ostream &os) const override;

    /**
     * @brief Constructeur par copie.
     */
    Film(const Film& from);

    /**
     * @brief L'operateur d'égalité.
     */
    Film& operator=(const Film& from);

    /**
     * @brief Méthode override pour écrire l'information ver flux sortée.
     */
    void write(ostream &os) const override;

    /**
	 * @brief Mérhode override pour relire l'objet de flux entrée.
	 */
    void read(istream &is) override;

    /**
	 * @brief Méthode override pour retourner le nom de la class.
	 */
	string className() const override;
public:
    /**
	 * @brief Le destructeur.
	 */
    ~Film();
};

#endif // !FILM_H
