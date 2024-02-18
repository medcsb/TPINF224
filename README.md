# TPINF224

#### Multimedia Management System
The Multimedia Management System is a project that allows users to manage and interact with multimedia objects such as films, photos, videos, and groups. It consists of a server implemented in C++ and a Swing-based graphical user interface (GUI) in Java.

## Features
# Multimedia Object Types:

Film
Photo
Video
Group (container for multiple multimedia objects)
# Functionality:

Create, modify, and delete multimedia objects
Search for multimedia objects
Play multimedia objects
Components
C++ Server
The server is responsible for managing multimedia objects and handling requests from the Java Swing interface. Communication between the server and the Swing interface is achieved through a specific protocol.

## Java Swing Interface
The Swing-based GUI serves as a remote control for interacting with the multimedia management system. It provides a user-friendly interface for searching and playing multimedia objects. The communication protocol used for sending requests to the server includes SEARCH:... and PLAY:....

## Communication Protocol
# SEARCH:

Syntax: SEARCH:<query>
Example: SEARCH:Star Wars
Functionality: Searches for multimedia objects based on the provided query.
# PLAY:

Syntax: PLAY:<multimedia_object>
Example: PLAY:Star Wars
Functionality: Plays the specified multimedia object.
# How to Run
Compile C++ Server
Run Java Swing Interface
