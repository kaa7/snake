#ifndef EL_H
#define EL_H

#include "common.h"
#include <vector>
#include <SFML/Graphics.hpp>
struct el {
private:
    sf::Vector2f pos;
    sf::RectangleShape r;
public:
    el(sf::Vector2f p);
    el(int x, int y);
    int x();
    int y();
    sf::Vector2f position();
    void move(sf::Vector2f dest);
    void draw();
};
#endif // EL_H
