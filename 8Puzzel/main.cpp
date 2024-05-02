#include <SFML/Graphics.hpp>

#include <iostream>

#include "Board.h"
#include "Score.h"
#include "Button.h"
#include "Shuffle.h"
#include "Solver.h"



int main()
{
    srand(time(0));

    // Loading the Texture
    sf::Texture texture;
    texture.loadFromFile("BoardTexture.jpg");  
    if (!texture.loadFromFile("BoardTexture.jpg", sf::IntRect(0, 0, 450, 450)))
    {
        return EXIT_FAILURE;
    }
    
    // Loading the Font
    sf::Font MyFont;
    MyFont.loadFromFile("Arial.ttf");
    if (!MyFont.loadFromFile("Arial.ttf"))
    {
        return EXIT_FAILURE;
    }

    // Render Window
    sf::RenderWindow window(sf::VideoMode(800, 800), "8 Puzzels");

    // 
    Board Board(MyFont, texture);
    Score Score(MyFont);
    Shuffle Shuffle;
    Solver PuzzelSolver(MyFont);

    // Buttons
    Button ButtonShuffel(670,50,100,40,MyFont,"Shuffel", sf::Color(140,140,140), sf::Color(128,128,128), sf::Color(115,115,115));
    Button ButtonNext(300, 500, 80, 40, MyFont, "Next", sf::Color(140, 140, 140), sf::Color(128, 128, 128), sf::Color(115, 115, 115));
    Button ButtonBack(450, 500, 80, 40, MyFont, "Back", sf::Color(140, 140, 140), sf::Color(128, 128, 128), sf::Color(115, 115, 115));
    Button ButtonSolve(650, 650, 80, 40, MyFont, "Solve", sf::Color(140, 140, 140), sf::Color(128, 128, 128), sf::Color(115, 115, 115));

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
                            // RESET GAME
                            Board.setPauseValue(true);
                            Shuffle.shuffleArray(Board);
                            PuzzelSolver.getValues(Board);
                            PuzzelSolver.updateSolverBoard();
                            Score.reset();
                            Board.updateZeroPosition();
                            Board.updateBoard();

                        }
                        if (event.key.code == sf::Keyboard::S)
                        {
                            // Solve Puzzel
                            // PuzzelSolver.solve();
                        }
                        if (event.key.code == sf::Keyboard::A)
                        {
                            // Back
                        }
                        if (event.key.code == sf::Keyboard::D)
                        {
                            // Next
                        }
                }
            }

            if (ButtonShuffel.update(sf::Vector2f(sf::Mouse::getPosition(window))))
            {
                //RESET GAME
                Board.setPauseValue(true);
                Shuffle.shuffleArray(Board);
                PuzzelSolver.getValues(Board);
                PuzzelSolver.updateSolverBoard();
                Score.reset();
                Board.updateZeroPosition();
                Board.updateBoard();
            }
            // Clear the window
            window.clear();

            // Draw
            Board.drawBoard(window);
            //Board.drawText(window);
            Score.draw(window);
            PuzzelSolver.drawSolverBoard(window);

            ButtonShuffel.drawButton(window);
            ButtonBack.drawButton(window);
            ButtonNext.drawButton(window);
            ButtonSolve.drawButton(window);


            // Check if it is over
            if (Board.checkIfOver() == true)
            {
                Board.setPauseValue(false);
            }

            // Display
            window.display();
    }

    return 0;
}