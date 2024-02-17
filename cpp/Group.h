#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include <iostream>
#include "Multimedia.h"

class Group : public std::list<std::shared_ptr<Multimedia>> {
private:
    std::string groupName;

public:
    // Constructeur
    Group(const std::string& name) : groupName(name) {}

    // Accesseur pour le nom du groupe
    const std::string& getGroupName() const {
        return groupName;
    }

    // Méthode d'affichage
    void display() const {
        std::cout << "Group Name: " << groupName << "\n";

        for (const auto& multimediaPtr : *this) {
            multimediaPtr->display(std::cout);
            std::cout << "\n";
        }
    }

    // Méthode pour ajouter un objet multimédia au groupe
    void add(const std::shared_ptr<Multimedia>& multimedia) {
        push_back(multimedia);
    }
};

#endif // GROUP_H
