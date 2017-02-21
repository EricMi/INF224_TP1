//***************************************************************************************
//
//! @file Video.h
//! La specification et l'implementation de la class Video dérivant de Multimedia.
//!
//! @author    Pengfei Mi
//! @date      2016-11
//
//***************************************************************************************

#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <string>
using namespace std;

/**
 * @class Video header-file Video.h
 * @brief
 * La class Video dérivant de Multimedia.
 * Ses objets sont des vidéos.
 * @see Multimedia
 */
class Video : public Multimedia {
	friend class MyBase;
	friend class Group;
private:
	int duration = 0; /**La durée de la vidéo.*/
protected:
	/**
     * @brief Le constructeur ayant des paramètres par défaut.
     */
	Video(string n = "", string f = "", int d = 0) : Multimedia(n, f) {
		this->setDuration(d);
	};

	/**
	 * @brief Accesseur de la durée.
	 */
	int getDuration() const {
		return this->duration;
	};

	/**
	 * @brief Modifieur de la durée.
	 */
	void setDuration(int d) {
		this->duration = d;
	};

	/**
     * @brief Méthode override pour afficher l'information.
     */
	void print(ostream &os) const override {
		this->Multimedia::print(os);
		os << "Duration:" << this->getDuration() << endl;
	};

	/**
	 * @brief Méthode override pour jouer la vidéo.
	 */
	void play() const override {
		string command;
		#ifdef __APPLE__
			command = "open ";
		#elif __linux__
			command = "xdg-open ";
		#elif __unix__
			command = "mpv "
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
		os << this->getDuration() << '\n';
	};

	/**
	 * @brief Mérhode override pour relire l'objet de flux entrée.
	 */
	void read(istream &is) override {
		this->Multimedia::read(is);
		string s;
		getline(is, s);
		this->setDuration(stoi(s));
	};

	/**
	 * @brief Méthode override pour retourner le nom de la class.
	 */
	string className() const override {
		return "Video";
	};
};

#endif // !VIDEO_H
