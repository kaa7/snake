#include "food.h"
#include "snake.h"
#include "obstacles.h"
#include "common.h"
struct Snake;
struct obstacles;
food::food()
{
    srand(time(NULL));
    r.setSize(sf::Vector2f(50, 50));
    r.setFillColor(sf::Color(255, 193, 7));
    generatePos();
}

void food::generatePos()
{
    int i = 0;
    bool OK = true;
    do {
        if(i > 10) {
            pos.x = snake.tail()->position().x - 50;
            pos.y =  snake.tail()->position().y - 50;
        }
        pos.x = ( rand() % 14 + 1 ) * 50;
        pos.y = ( rand() % 14 + 1 ) * 50;
        if(o.lookFor(sf::Vector2f(pos.x, pos.y))
                || snake.lookFor(sf::Vector2f(pos.x, pos.y))) OK = false;
        i++;
    } while(!OK);
    r.setPosition(pos);
}

sf::Vector2f food::position()
{
    return pos;
}

void food::draw()
{
    window.draw(r);
}
