#ifndef FOOD_H
#define FOOD_H
#include <SFML/Graphics.hpp>
struct food {
private:
    sf::Vector2f pos;
    sf::RectangleShape r;
public:
    food();
    void generatePos();
    sf::Vector2f position();
    void draw();
};
#endif // FOOD_H
