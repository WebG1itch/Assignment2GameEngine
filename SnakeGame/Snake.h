//
// Created by Jake on 2/8/2022.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include "SFML/System.hpp"
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

struct SnakeSegment {
    SnakeSegment(int x, int y) : position(x,y){}
    sf::Vector2i position;
};

enum class Direction { None, Up, Down, Left, Right };

class Snake {
public:
    Snake(int sizeOfBlocks);
    ~Snake();

    void SetDirection(Direction dir) { direction = dir; }
    Direction GetDirection();
    int GetSpeed() const { return speed; }
    sf::Vector2i GetPosition() { return (!snakeBody.empty() ? snakeBody.front().position : sf::Vector2i(1, 1)); }
    int GetLives() const { return lives; }
    int GetScore() const { return score; }
    void IncreaseScore() { score += 1; }
    bool HasLost() const { return lost; }

    void Lose() { lost = true; }
    void ToggleLost() { lost = !lost; }

    void Extend(); // Grow snake
    void Reset(); // Set snake to starting position

    void Move();
    void Tick();
    void Cut(int cutSegments); // Used to Cut the snake
    void Render(sf::RenderWindow& renderWindow);
private:
    void checkCollision();

    std::vector<SnakeSegment> snakeBody; // Stores the body of snake
    int size; // Size of the blocks
    Direction direction; // Current direction
    int speed;
    int lives;
    int score;
    bool lost;
    sf::RectangleShape bodyRect;
};

#endif //SNAKEGAME_SNAKE_H
