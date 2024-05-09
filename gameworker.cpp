// gameworker.cpp
#include "gameworker.h"
#include "game.h"
#include <QApplication>

GameWorker::GameWorker(QObject *parent) : QObject(parent) {}

void GameWorker::startGame()
{
    int argc = 1; // At least one argument
    char arg[] = "game"; // Dummy argument
    char *argv[] = { arg, nullptr }; // Default value for argv
    QApplication a(argc, argv);

    // Initialize the game environment
    game game;
    game.initializeGame();

    a.exec(); // Start the application event loop
}
