// MediaManager.h
#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <map>
#include <memory>
#include <string>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class MediaManager {
private:
    // Table des objets multimédias
    std::map<std::string, std::shared_ptr<Multimedia>> mediaTable;

    // Table des groupes
    std::map<std::string, std::shared_ptr<Group>> groupTable;

public:
    // Méthode pour créer et ajouter une Photo
    std::shared_ptr<Photo> createAndAddPhoto(const std::string& name, const std::string& filePath, double latitude, double longitude);

    // Méthode pour créer et ajouter une Vidéo
    std::shared_ptr<Video> createAndAddVideo(const std::string& name, const std::string& filePath, int duration);

    // Méthode pour créer et ajouter un Film
    std::shared_ptr<Film> createAndAddFilm(const std::string& name, const std::string& filePath, int duration, int* chapters, int numChapters);

    // Méthode pour créer et ajouter un Groupe
    std::shared_ptr<Group> createAndAddGroup(const std::string& name);

    // Méthode pour rechercher et afficher un objet multimédia à partir de son nom
    void searchAndDisplayMedia(const std::string& name) const;

    // Méthode pour rechercher et afficher un groupe à partir de son nom
    void searchAndDisplayGroup(const std::string& name) const;

    // Méthode pour jouer un objet multimédia à partir de son nom
    void playMedia(const std::string& name) const;

    // Méthode pour supprimer un objet multimédia à partir de son nom
    void removeMedia(const std::string& name);

    // Méthode pour supprimer un groupe à partir de son nom
    void removeGroup(const std::string& name);
};

#endif // MEDIAMANAGER_H
