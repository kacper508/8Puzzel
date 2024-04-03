#include <SFML/Graphics.hpp>

#include <iostream>

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
                        Board.moveValue('u');
                        Board.updateZeroPosition();
                        Board.updateBoard();
                        break;
                    case(sf::Keyboard::Down):
                        Board.moveValue('d');
                        Board.updateZeroPosition();
                        Board.updateBoard();
                        break;
                    case(sf::Keyboard::Right):
                        Board.moveValue('r');
                        Board.updateZeroPosition();
                        Board.updateBoard();
                        break;
                    case(sf::Keyboard::Left):
                        Board.moveValue('l');
                        Board.updateZeroPosition();
                        Board.updateBoard();
                        break;
                    }
                }
            }

            window.clear();

            Board.drawBoard(window);

            window.display();

            if (Board.checkIfOver() == true)
            {
                std::cout << "OVER!!!\n";
            }

    }

    return 0;
}