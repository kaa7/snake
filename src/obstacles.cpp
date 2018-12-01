#include "obstacles.h"
#include "common.h"

void obstacles::add(obstacle obj)
{
    v.push_back(obj);
}

void obstacles::draw()
{
    for(auto i : v) i.draw();
}

void obstacles::generate()
{
    for(int i = 0; i < SIZE / 50; i++) {
        obstacle obj1(sf::Vector2f(i * 50, 0));
        this->add(obj1);
        obstacle obj2(sf::Vector2f(i * 50, SIZE - 50));
        this->add(obj2);
        obstacle obj3(sf::Vector2f(0, i * 50));
        this->add(obj3);
        obstacle obj4(sf::Vector2f(SIZE - 50, i * 50));
        this->add(obj4);
    }
}

obstacles::obstacles()
{
    obstacles::generate();
}

bool obstacles::lookFor(sf::Vector2f p)
{
    for(auto i : v) {
        if(i.position() == p) return true;
    }
    return false;
}
