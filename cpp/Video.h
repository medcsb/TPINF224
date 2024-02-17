#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <string>
#include <iostream>

class Video : public Multimedia {
private:
    int duration; // Duration in seconds

public:
    Video(std::string objectName, std::string filePath, int durationSec)
        : Multimedia(objectName, filePath), duration(durationSec) {}

    ~Video() {
        std::cout << "Destructor for Video called for " << Multimedia::getObjectName() << std::endl;
    }

    int getDuration() const { return duration; }

    void setDuration(int durationSec) { duration = durationSec; }

    void display(std::ostream& out) const override {
        Multimedia::display(out);
        out << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        std::string command = "mpv " + getFilePath() + " &";
        system(command.data());
    }
};

#endif // VIDEO_H
