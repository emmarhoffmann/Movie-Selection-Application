# Movie Selection Application

## About
This is a Qt-based movie selection application that features a responsive QML interface coupled with a C++ backend for enhanced performance and functionality. The app allows users to select movies with randomization options and efficient file reading capabilities.

## Features
- **QML Frontend**: Provides a modern and responsive interface for seamless user interaction.
- **C++ Backend**: Handles logic, movie selection, randomization, and file processing, ensuring smooth operation.
- **Randomized Movie Selection**: The app includes a randomization feature to help users discover movies based on randomized choices.
- **File Input Support**: Movie data can be imported via text files, offering flexibility for adding movie lists.

## Project Structure
- `main.cpp`: Initializes the application and sets up the QML environment.
- `main.qml`: The QML file responsible for rendering the UI.
- `CFantasyMovies.cpp/h`: Handles the logic related to movies, including fantasy movie selection.
- `CRandom.cpp/h`: Implements randomization logic for movie selection.
- `CReadFile.cpp/h`: Manages file reading and importing movie data from external files.
- `input.txt`: Contains movie data for the application to process.
