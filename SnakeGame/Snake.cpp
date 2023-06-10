//
// Created by Jake on 2/8/2022.
//

#include "Snake.h"

Snake::Snake(int sizeOfBlocks) {
    size = sizeOfBlocks;
    bodyRect.setSize(sf::Vector2f(size - 1, size - 1));
    Reset();
}

Snake::~Snake() {}

void Snake::Reset() {
    snakeBody.clear();

    // Add 3 body segments to start
    snakeBody.emplace_back(5, 7);
    snakeBody.emplace_back(5, 6);
    snakeBody.emplace_back(5, 5);

    SetDirection(Direction::None);
    speed = 15;
    lives = 3;
    score = 0;
    lost = false;
}

void Snake::Extend() {
    if (snakeBody.empty()) { return; }
    SnakeSegment& head = snakeBody[snakeBody.size() - 1];
    SnakeSegment& tail = snakeBody[snakeBody.size() - 1];

    if (snakeBody.size() > 1) {
        tail = snakeBody[snakeBody.size() - 2];

        if (head.position.x == tail.position.x) {
            if (head.position.y > tail.position.y) {
                snakeBody.emplace_back(head.position.x, head.position.y + 1);
            } else {
                snakeBody.emplace_back(head.position.x, head.position.y - 1);
            }
        } else if (head.position.y == tail.position.y) {
            if (head.position.x > tail.position.x) {
                snakeBody.emplace_back(head.position.x + 1, head.position.y);
            } else {
                snakeBody.emplace_back(head.position.x - 1, head.position.y);
            }
        }
    } else {
        if (direction == Direction::Up) {
            snakeBody.emplace_back(head.position.x, head.position.y + 1);
        } else if (direction == Direction::Down) {
            snakeBody.emplace_back(head.position.x, head.position.y - 1);
        } else if (direction == Direction::Left) {
            snakeBody.emplace_back(head.position.x + 1, head.position.y);
        } else if (direction == Direction::Right) {
            snakeBody.emplace_back(head.position.x - 1, head.position.y);
        }
    }
}

void Snake::Tick() {
    if (snakeBody.empty()) { return; }
    if (direction == Direction::None) { return; }
    Move();
    checkCollision();
}

void Snake::Move() {
    for (int i = snakeBody.size() - 1; i > 0; --i) {
        snakeBody[i].position = snakeBody[i - 1].position;
    }
    if (direction == Direction::Left) {
        --snakeBody[0].position.x;
    } else if (direction == Direction::Right) {
        ++snakeBody[0].position.x;
    } else if (direction == Direction::Up) {
        --snakeBody[0].position.y;
    } else if (direction == Direction::Down) {
        ++snakeBody[0].position.y;
    }

}

void Snake::checkCollision() {
    if (snakeBody.size() <= 5) { return; }
    SnakeSegment& head = snakeBody.front();
    for (auto itr = snakeBody.begin() + 1; itr != snakeBody.end(); ++itr) {
        if (itr->position == head.position) {
            int segments = snakeBody.end() - itr;
            Cut(segments);
            return;
        }
    }
}

void Snake::Cut(int cutSegments) {
    for (int i = 0; i < cutSegments; ++i) {
        snakeBody.pop_back();
    }

    score -= cutSegments;

    --lives;
    if (!lives) {
        Lose();
        return;
    }
}

void Snake::Render(sf::RenderWindow &renderWindow) {
    if (snakeBody.empty()) { return; }

    auto head = snakeBody.begin();
    bodyRect.setFillColor(sf::Color::Yellow);
    bodyRect.setPosition(head->position.x * size, head->position.y * size);
    renderWindow.draw(bodyRect);

    bodyRect.setFillColor(sf::Color::Green);
    for (auto itr = snakeBody.begin() + 1; itr != snakeBody.end(); ++itr) {
        bodyRect.setPosition(itr->position.x * size, itr->position.y * size);
        renderWindow.draw(bodyRect);
    }
}

Direction Snake::GetDirection() {
    if (snakeBody.size() <= 1) {
        return Direction::None;
    }

    SnakeSegment& head = snakeBody[0];
    SnakeSegment& neck = snakeBody[1];

    if (head.position.x == neck.position.x) {
        return (head.position.y > neck.position.y ? Direction::Down : Direction::Up);
    } else if (head.position.y == neck.position.y) {
        return (head.position.x > neck.position.x ? Direction::Right : Direction::Left);
    }

    return Direction::None;
}

