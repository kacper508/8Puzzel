#include <SFML/Graphics.hpp>

#include "Board.h"

int main()
{
    sf::Font MyFont;
    MyFont.loadFromFile("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 800), "8 Puzzels");

    Board Board(MyFont);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case(sf::Keyboard::Up):
                        break;
                case(sf::Keyboard::Down):
                    break;
                case(sf::Keyboard::Right):
                    break;
                case(sf::Keyboard::Left):
                    break;
                }
            }
        }

        window.clear();

        Board.drawBoard(window);

        window.display();
    }

    return 0;
}