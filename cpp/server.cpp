#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "MediaManager.h"  // Include your MediaManager or equivalent

const int PORT = 3331;

int main(int argc, char* argv[]) {
    // Create the MediaManager instance
    MediaManager mediaManager;

    // Create the TCPServer
    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        std::cout << "Request: " << request << std::endl;

        // Parse the request and perform the corresponding action
        if (request.compare(0, 5, "PLAY:") == 0) {
            // Extract the object name from the request
            std::string objectName = request.substr(5);

            // Implement the logic to play the media
            mediaManager.playMedia(objectName);
            response = "OK";

        } else if (request.compare(0, 7, "SEARCH:") == 0) {
            // Extract the object name from the request
            std::string objectName = request.substr(7);

            response = "OK";

            // Implement the logic to search and display media
            mediaManager.searchAndDisplayMedia(objectName);

        } else {
            // Unknown command
            response = "ERROR: Unknown command";
        }

        // Return true to keep the connection open, false to close it
        return true;
    });

    // Run the server loop
    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server->run(PORT);

    // Handle any errors
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
