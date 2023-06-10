//
// Created by Jake on 2/10/2022.
//

#ifndef SNAKEGAME_WORLD_H
#define SNAKEGAME_WORLD_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Snake;

class World {
public:
    World(sf::Vector2u defaultWindowSize);
    ~World();

    int GetBlockSize() const { return blockSize; }

    void RespawnApple();

    void Update(Snake& player);
    void Render(sf::RenderWindow& window);

private:
    sf::Vector2u windowSize;
    sf::Vector2i item;
    int blockSize;

    sf::CircleShape appleShape;
    sf::RectangleShape bounds[4];

};


#endif //SNAKEGAME_WORLD_H
