//***************************************************************************************
//
//! @file Group.h
//! La specification et l'implementation de la class Group dérivant de list<shared_ptr<Multimedia>>.
//!
//! @author    Pengfei Mi
//! @date      2016-12
//
//***************************************************************************************

#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include "Multimedia.h"
using namespace std;

typedef shared_ptr<Multimedia> MultimediaPtr;

//class Group : public list<Multimedia*> {
/**
 * @class Group header-file Group.h
 * @brief
 * La class est une list de smart pointeur de Multimedia.
 * @see Multimedia
 */
class Group : public list<MultimediaPtr> {
    friend class MyBase;
private:
    string name = ""; /**Le nom de groupe.*/
protected:
    /**
     * @brief Le constructeur ayant des paramètres par défaut.
     */
    Group(string n = "") : list() {
        this->name = n;
    };

    // function: get name of group
    string getName() const {
        return this->name;
    };

    /**
     * @brief Méthode pour afficher l'information.
     */
    void print(ostream &os) const {
        os << "Group:" << this->name << endl;
        for(Group::const_iterator it = this->begin(); it != this->end(); it++)
            (*it)->print(os);
    };
};
#endif // !GROUP_H
