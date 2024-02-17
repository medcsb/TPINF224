#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <iostream>

class Film : public Video {
private:
    int* chapters;  // Tableau dynamique des durées des chapitres
    int numChapters;  // Nombre de chapitres

public:
    // Constructeur
    Film(std::string objectName, std::string filePath, int durationSec, int* chapArray, int numChapters)
        : Video(objectName, filePath, durationSec), chapters(nullptr), numChapters(0) {
        setChapters(chapArray, numChapters);
    }

    // Modifieur pour le tableau de durées des chapitres
    void setChapters(int* chapArray, int numChapters) {
        // Libérer la mémoire du tableau existant s'il y en a un
        delete[] chapters;

        // Allouer de la mémoire pour le nouveau tableau
        chapters = new int[numChapters];

        // Copier les données du tableau donné en argument
        for (int i = 0; i < numChapters; ++i) {
            chapters[i] = chapArray[i];
        }

        // Mettre à jour le nombre de chapitres
        this->numChapters = numChapters;
    }

    // Accesseurs
    const int* getChapters() const {
        return chapters;
    }

    int getNumChapters() const {
        return numChapters;
    }

    // Méthode d'affichage
    void display(std::ostream& out) const override {
        Video::display(out); // Appelle la méthode d'affichage de la classe de base

        out << "Chapters:\n";
        for (int i = 0; i < numChapters; ++i) {
            out << "Chapter " << (i + 1) << ": " << chapters[i] << " seconds\n";
        }
    }

    // Destructeur
    ~Film() {
        delete[] chapters; // Libérer la mémoire du tableau lors de la destruction de l'objet Film
    }
};

#endif // FILM_H
