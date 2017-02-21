//***************************************************************************************
//
//! @file Photo.h
//! La specification et l'implementation de la class Photo dérivant de Multimedia.
//!
//! @author    Pengfei Mi
//! @date      2016-11
//
//***************************************************************************************

#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"
using namespace std;

/**
 * @class Photo header-file Photo.h
 * @brief
 * La class Photo dérivant de Multimedia.
 * Ses objets sont des photos.
 * @see Multimedia
 */
class Photo : public Multimedia {
	friend class MyBase;
	friend class Group;
private:
	int width = 0; /**La largeur de la photo.*/
	int height = 0; /**La longeur de la photo.*/
protected:
	/**
     * @brief Le constructeur ayant des paramètres par défaut.
     */
	Photo(string n = "", string f = "", int w = 0, int h = 0) : Multimedia(n, f) {
		this->setWidth(w);
		this->setHeight(h);
	};

	/**
	 * @brief Accesseur de la largeur.
	 */
	int getWidth() const {
		return this->width;
	};

	/**
	 * @brief Modifieur de la largeur.
	 */
	void setWidth(int w) {
		this->width = w;
	};

	/**
	 * @brief Accesseur de la longeur.
	 */
	int getHeight() const {
		return this->height;
	};

	/**
	 * @brief Modifieur de la longeur.
	 */
	void setHeight(int h) {
		this->height = h;
	};

	/**
     * @brief Méthode override pour afficher l'information.
     */
	void print(ostream &os) const override {
		this->Multimedia::print(os);
		os << "Width:" << this->getWidth() << '\n'
			<< "Height:" << this->getHeight() << endl;
	};

	/**
	 * @brief Méthode override pour jouer la Photo.
	 */
	void play() const override {
		string command;
		#ifdef __APPLE__
			command = "open ";
		#elif __linux__
			command = "eog ";
		#elif __unix__
			command = "imagej "
		#else
		    cerr << "--->Error: unknown compiler."
		#endif
		command += this->getFileName() + " &";
		system(command.c_str());
	};

	/**
     * @brief Méthode override pour écrire l'information ver flux sortée.
     */
	void write(ostream &os) const override {
		Multimedia::write(os);
		os << this->getWidth() << '\n' << this->getHeight() << '\n';
	};

	/**
	 * @brief Mérhode override pour relire l'objet de flux entrée.
	 */
	void read(istream &is) override {
		this->Multimedia::read(is);
		string s;
		getline(is, s);
		this->setWidth(stoi(s));
		getline(is, s);
		this->setHeight(stoi(s));
	};

	/**
	 * @brief Méthode override pour retourner le nom de la class.
	 */
	string className() const override {
		return "Photo";
	};
};

#endif // !PHOTO_H
