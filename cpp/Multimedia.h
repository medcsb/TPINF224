#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>

class Multimedia {
private:
    std::string objectName;
    std::string filePath;

public:
    // Constructeurs
    Multimedia();
    Multimedia(const std::string& name, const std::string& path);

    // Destructeur
    ~Multimedia();

    // Accesseurs
    const std::string& getObjectName() const;
    const std::string& getFilePath() const;

    // Modifieurs
    void setObjectName(const std::string& name);
    void setFilePath(const std::string& path);

    // Méthode d'affichage
    virtual void display(std::ostream& out) const;

    // Méthode de lecture
    virtual void play() const;
};

#endif // MULTIMEDIA_H
