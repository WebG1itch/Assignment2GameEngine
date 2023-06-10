//
// Created by Jake on 2/5/2022.
//
#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "Textbox.h"

#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

class Game {

public:
    Game();
    ~Game();

    // Checks if the correct keys have been pressed
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow() { return &window; }

    sf::Time getElapsed() { return deltaTime; }
    void RestartClock() { deltaTime += clock.restart(); }

private:
    Window window;

    sf::Clock clock;
    sf::Time deltaTime;

    World world;
    Snake snake;

    Textbox textbox;
};


#endif //MAIN_CPP_GAME_H
