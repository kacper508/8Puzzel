#include <SFML/Graphics.hpp>

#include <iostream>

#include "Board.h"
#include "Score.h"
#include "Button.h"
#include "Shuffle.h"

int main()
{
    srand(time(0));

    sf::Font MyFont;
    MyFont.loadFromFile("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 800), "8 Puzzels");

    Board Board(MyFont);
    Score Score(MyFont);
    Button ButtonShuffel(700,50,50,20,MyFont,"Shuffel", sf::Color(140,140,140), sf::Color(128,128,128), sf::Color(115,115,115));
    Button ButtonNext(600, 500, 50, 20, MyFont, "Next", sf::Color(140, 140, 140), sf::Color(128, 128, 128), sf::Color(115, 115, 115));
    Button ButtonBack(750, 500, 50, 20, MyFont, "Back", sf::Color(140, 140, 140), sf::Color(128, 128, 128), sf::Color(115, 115, 115));

    Shuffle Shuffle;

    while (window.isOpen())
    {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed)
                {
                    if (Board.getPauseValue())
                    {
                        switch (event.key.code)
                        {
                        case(sf::Keyboard::Up):
                            if (Board.moveValue('u'))
                            {
                                Board.updateZeroPosition();
                                Board.updateBoard();
                                Score.update();
                            }
                            break;
                        case(sf::Keyboard::Down):
                            if (Board.moveValue('d'))
                            {
                                Board.updateZeroPosition();
                                Board.updateBoard();
                                Score.update();
                            }
                            break;
                        case(sf::Keyboard::Right):
                            if (Board.moveValue('r'))
                            {
                                Board.updateZeroPosition();
                                Board.updateBoard();
                                Score.update();
                            }
                            break;
                        case(sf::Keyboard::Left):
                            if (Board.moveValue('l'))
                            {
                                Board.updateZeroPosition();
                                Board.updateBoard();
                                Score.update();
                            }
                            break;
                        }
                    }
                        if (event.key.code == sf::Keyboard::Space)
                        {
                            //RESET GAME
                            Board.setPauseValue(true);
                            Shuffle.shuffleArray();
                            Shuffle.copyValuesToBoard(Board);
                            Score.reset();
                            Board.updateZeroPosition();
                            Board.updateBoard();

                            //std::cout << "Spacje\n";
                        }
                }
            }

            window.clear();

            Board.drawBoard(window);
            Score.draw(window);
            ButtonShuffel.drawButton(window);
            ButtonBack.drawButton(window);
            ButtonNext.drawButton(window);

            window.display();

            if (Board.checkIfOver() == true)
            {
                Board.setPauseValue(false);
                //std::cout << "OVER!!!\n";
            }

    }

    return 0;
}