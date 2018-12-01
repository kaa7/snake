#include "el.h"
el::el(sf::Vector2f p)
{
    r.setSize(sf::Vector2f(50, 50));
    r.setFillColor(sf::Color(2, 136, 209));
    r.setOutlineThickness(4);
    r.setOutlineColor(sf::Color(48, 63, 159));
    pos = p;
    r.setPosition(pos);
}

el::el(int x, int y)
{
    r.setSize(sf::Vector2f(50, 50));
    r.setFillColor(sf::Color(2, 136, 209));
    r.setOutlineThickness(4);
    r.setOutlineColor(sf::Color(48, 63, 159));
    pos.x = x;
    pos.y = y;
    r.setPosition(pos);
}

int el::x()
{
    return pos.x;
}

int el::y()
{
    return pos.y;
}

sf::Vector2f el::position()
{
    return pos;
}

void el::move(sf::Vector2f dest)
{
    pos = dest;
    r.setPosition(pos);
}

void el::draw()
{
    window.draw(r);
}
