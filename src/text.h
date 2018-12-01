#ifndef TEXT_H
#define TEXT_H
#include "common.h"
#include <SFML/Graphics.hpp>

struct txt {
private:
    sf::Font font;
    sf::Text text;
public:
    void set(string str, int size, sf::Color, sf::Vector2f pos);
    void setStr(string str);
    void draw();
};

struct Texts {
    txt endText, scoreText, resetText;
    Texts();
    void draw();
};
#endif // TEXT_H
