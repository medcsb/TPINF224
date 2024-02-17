#include <iostream>
#include "MediaManager.h"
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
using namespace std;

int main(int argc, const char* argv[])
{
    // Create a MediaManager instance
    MediaManager mediaManager;

    // Create and add some multimedia objects
    auto photo1 = mediaManager.createAndAddPhoto("Photo1", "/path/to/photo1.jpg", 40.7128, -74.0060);
    auto video1 = mediaManager.createAndAddVideo("Video1", "/path/to/video1.mp4", 120);
    int filmChapters[] = {10, 20, 30};  // Example chapters for the film
    auto film1 = mediaManager.createAndAddFilm("Film1", "/path/to/film1.mp4", 180, filmChapters, 3);

    // Create and add a group
    auto group1 = mediaManager.createAndAddGroup("Group1");

    // Add multimedia objects to the group
    group1->add(photo1);
    group1->add(video1);

    // Display the multimedia objects and the group
    mediaManager.searchAndDisplayMedia("Photo1");
    mediaManager.searchAndDisplayMedia("Video1");
    mediaManager.searchAndDisplayMedia("Film1");

    mediaManager.searchAndDisplayGroup("Group1");

    // Play a multimedia object
    mediaManager.playMedia("Video1");

    // Remove a multimedia object and display the group again
    mediaManager.removeMedia("Photo1");
    mediaManager.searchAndDisplayGroup("Group1");
    // a way to pause the program until the user presses enter
    std::cin.get();
    return 0;
}
