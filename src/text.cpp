#include "text.h"

Texts::Texts()
{
    endText.set("Game Over", 50, sf::Color(255, 193, 7),
                sf::Vector2f(SIZE / 2 - 200, SIZE / 2 - 100));
    scoreText.set("Your score was : ", 50, sf::Color(255, 255, 255),
                  sf::Vector2f(SIZE / 2 - 200, SIZE / 2));
    resetText.set("Press R to restart", 50, sf::Color(156, 39, 176),
                  sf::Vector2f(SIZE / 2 - 200, SIZE / 2 + 100));
}

void Texts::draw()
{
    endText.draw();
    scoreText.draw();
    resetText.draw();
}

void txt::set(string str, int size, sf::Color color, sf::Vector2f pos)
{
    if (!font.loadFromFile("./res/arial.ttf"))throw "Exception";
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setColor(color);
    text.setPosition(pos.x, pos.y);
}

void txt::setStr(string str)
{
    text.setString(str);
}

void txt::draw()
{
    window.draw(text);
}
