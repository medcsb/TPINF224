#include "MediaManager.h"

std::shared_ptr<Photo> MediaManager::createAndAddPhoto(const std::string& name, const std::string& filePath, double latitude, double longitude) {
    auto photo = std::make_shared<Photo>(name, filePath, latitude, longitude);
    mediaTable[name] = photo;
    return photo;
}

std::shared_ptr<Video> MediaManager::createAndAddVideo(const std::string& name, const std::string& filePath, int duration) {
    auto video = std::make_shared<Video>(name, filePath, duration);
    mediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> MediaManager::createAndAddFilm(const std::string& name, const std::string& filePath, int duration, int* chapters, int numChapters) {
    auto film = std::make_shared<Film>(name, filePath, duration, chapters, numChapters);
    mediaTable[name] = film;
    return film;
}

std::shared_ptr<Group> MediaManager::createAndAddGroup(const std::string& name) {
    auto group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void MediaManager::searchAndDisplayMedia(const std::string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->display(std::cout);
    } else {
        std::cout << "Media not found: " << name << "\n";
    }
}

void MediaManager::searchAndDisplayGroup(const std::string& name) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->display();
    } else {
        std::cout << "Group not found: " << name << "\n";
    }
}

void MediaManager::playMedia(const std::string& name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Media not found: " << name << "\n";
    }
}

void MediaManager::removeMedia(const std::string& name) {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        // Supprimer l'objet multimédia de tous les groupes
        for (auto& group : groupTable) {
            group.second->remove(it->second);
        }

        // Supprimer l'objet multimédia de la table
        mediaTable.erase(it);
    } else {
        std::cout << "Media not found: " << name << "\n";
    }
}

void MediaManager::removeGroup(const std::string& name) {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        groupTable.erase(it);
    } else {
        std::cout << "Group not found: " << name << "\n";
    }
}
