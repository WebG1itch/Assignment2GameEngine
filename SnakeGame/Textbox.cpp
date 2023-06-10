//
// Created by Jake on 2/14/2022.
//

#include "Textbox.h"

#include <utility>

void Textbox::Setup(int charSize, int width, sf::Vector2f screenPos) {

    sf::Vector2f offset(2.0f, 2.0f);

    font.loadFromFile("OpenSans-Regular.ttf");
    displayedText.setFont(font);
    displayedText.setString("");
    displayedText.setCharacterSize(charSize);
    displayedText.setFillColor(sf::Color::White);
    displayedText.setPosition(screenPos + offset);
    displayedText.setFillColor(sf::Color(255, 255, 255, 25));

    background.setSize(sf::Vector2f(width, (charSize * 1.2f)));
    background.setFillColor(sf::Color(90, 90, 90, 90));
    background.setPosition(screenPos);
}

void Textbox::SetText(const std::string& message) {
    displayedText.setString(message);
}

void Textbox::Render(sf::RenderWindow& renderWindow) {
    if (bVisible) {
        displayedText.setPosition({75 - (displayedText.getLocalBounds().width / 2) - 3, 25 - (displayedText.getLocalBounds().height / 2) + 3});
        renderWindow.draw(displayedText);
    }
}

void Textbox::SetPosition(sf::Vector2f newPosition) {
    background.setPosition(newPosition);
    displayedText.setPosition(newPosition);
}
