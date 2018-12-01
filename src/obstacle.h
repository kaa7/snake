#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
struct obstacle {
private:
    sf::Vector2f pos;
    sf::RectangleShape r;
public:
    obstacle(sf::Vector2f p);
    void draw();
    sf::Vector2f position();
};

#endif
