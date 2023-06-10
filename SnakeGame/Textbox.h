//
// Created by Jake on 2/14/2022.
//

#ifndef SNAKEGAME_TEXTBOX_H
#define SNAKEGAME_TEXTBOX_H


#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Textbox {
public:
    Textbox() { Setup(9, 200, sf::Vector2f(0, 0)); }
    Textbox(int charSize, int width, sf::Vector2f screenPos) { Setup(charSize, width, screenPos); }
    ~Textbox() = default;

    void Setup(int charSize, int width, sf::Vector2f screenPos);
    void SetText(const std::string& message);
    void SetTextColor(sf::Color newColor) { displayedText.setFillColor(newColor); }
    void SetBackgroundColor(sf::Color newColor) { background.setFillColor(newColor); }
    void SetPosition(sf::Vector2f newPosition);
    void SetVisible(bool visible) { bVisible = visible; }
    void SetFont(const std::string& filename) { font.loadFromFile(filename); displayedText.setFont(font); }

    void Render(sf::RenderWindow& renderWindow);

private:
    bool bVisible = true;

    sf::RectangleShape background;
    sf::Font font;
    sf::Text displayedText;

    float paddingLeft = 0;
    float paddingTop = 0;
    float paddingRight = 0;
    float paddingBottom = 0;
};


#endif //SNAKEGAME_TEXTBOX_H
