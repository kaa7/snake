#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include "common.h"
#include "snake.h"
#include "obstacles.h"
#include "food.h"
#include <SFML/Graphics.hpp>
using namespace std;
sf::Time delta_i = sf::seconds(0.3f);
sf::Time delta = delta_i;
bool game_over = false;
const int SIZE = 800;
sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "Snake");
direction dir;
Snake snake;
obstacles o;
food f;
Texts text;

void input(direction &d)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        d.x = 1;
        d.y = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        d.x = -1;
        d.y = 0;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        d.x = 0;
        d.y = -1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        d.x = 0;
        d.y = 1;
    }
}

void reset()
{
    game_over = false;
    snake.reset();
    f.generatePos();
}

int main()
{
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(244, 67, 54));
        if(game_over) {
            ostringstream s;
            s << "Your score was : " << snake.length();
            text.scoreText.setStr(s.str());
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) reset();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;
            text.draw();
        } else {

            input(dir);
            sf::Time elapsed = clock.getElapsedTime();
            if(elapsed >= delta) {
                if(snake.head()->position() ==  f.position()) {
                    snake.add();
                    f.generatePos();
                    delta = sf::seconds(delta_i.asSeconds() - 
                            (float)snake.length() / 100);
                }
                snake.move(dir);
                clock.restart();

            }
            o.draw();
            f.draw();
            snake.draw();
        }
        window.display();
    }
    return 0;
}
