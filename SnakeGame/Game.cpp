//
// Created by Jake on 2/5/2022.
//

#include "Game.h"

Game::Game(): window("Micro Snake :)", sf::Vector2u(150, 100)), snake(world.GetBlockSize()), world(sf::Vector2u(150, 100)) {
    // Set up members
    textbox.Setup(70, 150, sf::Vector2f(0, 0));
    textbox.SetText("0");
}

Game::~Game() {}

void Game::Update() {
    float timeStep = 1.0f / snake.GetSpeed();

    if (deltaTime.asSeconds() >= timeStep) {
        snake.Tick();
        world.Update(snake);
        deltaTime -= sf::seconds(timeStep);
        if(snake.HasLost()) {
            snake.Reset();
        }
        textbox.SetText(std::to_string(snake.GetScore()));
    }
    window.update(); // Update the window
}

void Game::Render() {
    window.beginDraw(); // To clear the screen
    world.Render(*window.getRenderWindow());
    snake.Render(*window.getRenderWindow());
    textbox.Render(*window.getRenderWindow());
    window.endDraw(); // Send to display
}

void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.GetDirection() != Direction::Down) {
        snake.SetDirection(Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.GetDirection() != Direction::Up) {
        snake.SetDirection(Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.GetDirection() != Direction::Left) {
        snake.SetDirection(Direction::Right);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.GetDirection() != Direction::Right) {
        snake.SetDirection(Direction::Left);
    }
}
