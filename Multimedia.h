//***************************************************************************************
//
//! @file Multimedia.h
//! La specification de la class de base Multimedia.
//!
//! @author    Pengfei Mi
//! @date      2016-11
//
//***************************************************************************************

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

/**
 * @class Multimedia header-file Multimedia.h
 * @brief
 * La class de base qui est une class abstraite.
 */
class Multimedia {
	friend class MyBase;
	friend class Group;
private:
	string name = "";  /**Le nom d'objet.*/
	string fileName = ""; /**Le chemin du fichier.*/
protected:
	/**
	 * @brief Constructeur sans arguments.
	 */
	Multimedia();

	/**
	 * @brief Constructeur avec arguments.
	 */
	Multimedia(string name, string fileName);

	/**
	 * @brief Accesseur du nom.
	 */
	string getName() const;

	/**
	 * @brief Modifieur du nom.
	 */
	void setName(string name);

	/**
	 * @brief Accesseur du chemin de fichier.
	 */
	string getFileName() const;

	 /**
	  * @brief Modifieur du chemin de fichier.
	  */
	void setFileName(string FileName);

	/**
	 * @brief Méthode virtuelle pour afficher l'information.
	 */
	virtual void print(ostream &os) const;

	/**
	 * @brief Méthode abstraite pour jouer l'objet multimédia.
	 */
	#ifndef VERSION_BASE
	virtual void play() const = 0;
	#endif

	/**
	 * @brief Méthode virtuelle pour écrire l'information ver flux sortée.
	 */
	virtual void write(ostream &os) const;

	/**
	 * @brief Mérhode virtuelle pour relire l'objet de flux entrée.
	 */
	virtual void read(istream &is);

	/**
	 * @brief Méthode virtuelle pour retourner le nom de la class.
	 */
	virtual string className() const;
public:
	/**
	 * @brief Le destructeur.
	 */
	virtual ~Multimedia();
};

#endif // !MULTIMEDIA_H
