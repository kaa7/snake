#ifndef COMMON_H
#define COMMON_H
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "obstacles.h"
#include "text.h"
#include "food.h"

struct Snake;
struct direction {
    int x = 1, y = 0;
};
struct obstacles;
struct Texts;
struct food;

extern bool game_over;
extern const int SIZE;
extern sf::RenderWindow window;
extern direction dir;
extern Snake snake;
extern obstacles o;
extern Texts text;
extern food f;
#endif
