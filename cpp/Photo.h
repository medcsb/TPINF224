#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"
#include <string>
#include <iostream>

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    Photo(std::string objectName, std::string filePath, double latitude, double longitude)
        : Multimedia(objectName, filePath), latitude(latitude), longitude(longitude) {}

    ~Photo() {
        std::cout << "Destructor for Photo called for " << Multimedia::getObjectName() << std::endl;
    }

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    void setLatitude(double latitude) { this->latitude = latitude; }
    void setLongitude(double longitude) { this->longitude = longitude; }

    void display(std::ostream& out) const override {
        Multimedia::display(out);
        out << "Latitude: " << latitude << "\n";
        out << "Longitude: " << longitude << "\n";
    }

    void play() const override {
        std::string command = "imagej " + getFilePath() + " &";
        system(command.data());
    }
};

#endif // PHOTO_H
