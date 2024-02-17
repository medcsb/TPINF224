#include "Multimedia.h"

// Constructeurs
Multimedia::Multimedia() : objectName(""), filePath("") {}

Multimedia::Multimedia(const std::string& name, const std::string& path)
    : objectName(name), filePath(path) {}

// Destructeur
Multimedia::~Multimedia() {

}

// Accesseurs
const std::string& Multimedia::getObjectName() const {
    return objectName;
}

const std::string& Multimedia::getFilePath() const {
    return filePath;
}

// Modifieurs
void Multimedia::setObjectName(const std::string& name) {
    objectName = name;
}

void Multimedia::setFilePath(const std::string& path) {
    filePath = path;
}

// Méthode d'affichage
void Multimedia::display(std::ostream& out) const {
    out << "Object Name: " << objectName << "\n";
    out << "File Path: " << filePath << "\n";
}

// Méthode de lecture
void Multimedia::play() const {
    std::string command = "open " + filePath + " &";
    system(command.data());
}
