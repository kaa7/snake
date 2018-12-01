#include "obstacle.h"
#include "common.h"
#include <vector>
#include <SFML/Graphics.hpp>
obstacle::obstacle(sf::Vector2f p)
{
    pos = p;
    r.setPosition(p);
    r.setSize(sf::Vector2f(50, 50));
    r.setFillColor(sf::Color(255, 205, 210));
}
void obstacle::draw()
{
    window.draw(r);
}
sf::Vector2f obstacle::position()
{
    return pos;
}
